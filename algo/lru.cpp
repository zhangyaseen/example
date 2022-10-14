#include <chrono>
#include <iostream>
#include <list>
#include <map>
#include <thread>
#include <unistd.h>
#include <unordered_map>
#include <utility>

struct Node {
  int m_key;
  int m_value;
  time_t m_expiry_time;

  Node(int key, int val, time_t expiry_time) {
    m_key = key;
    m_value = val;
    m_expiry_time = expiry_time;
  }
};

struct Iterators {
  std::list<Node>::iterator cache_iter;
  std::list<int>::iterator key_iter;
};

class LRUCache {
public:
  LRUCache(int capacity, int timeout_sec) {
    m_capacity = capacity;
    m_time = timeout_sec;

    clean_thread = std::thread(&LRUCache::expired, this);
  }

  ~LRUCache() {
    if (clean_thread.joinable()) {
      clean_thread.join();
    }
  }

  void expired() {
    while (true) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));

      std::lock_guard<std::mutex> lock(mtx);

      auto iter = time_buckets.begin();

      while (iter != time_buckets.end()) {
        auto current_time = time(nullptr);
        if (iter->first > current_time) {
          break;
        }

        for (int key : iter->second) {
          Iterators temp = hashmap[key];
          int val = temp.cache_iter->m_value;
          cache.erase(temp.cache_iter);
        }

        auto current = iter;
        iter++;
        time_buckets.erase(current);
      }
    }
  }

  void update_cache(int key, int value) {
    Iterators temp = hashmap[key];

    int current_value = temp.cache_iter->m_value;
    auto current_expiry_time = temp.cache_iter->m_expiry_time;
    auto new_expiry_time = time(nullptr) + m_time;

    cache.erase(temp.cache_iter);
    cache.push_front(Node(key, value, new_expiry_time));

    time_buckets[current_expiry_time].erase(temp.key_iter);
    if (time_buckets[current_expiry_time].empty()) {
      time_buckets.erase(current_expiry_time);
    }
    time_buckets[new_expiry_time].push_front(key);

    hashmap[key] = {cache.begin(), time_buckets[new_expiry_time].begin()};
  }

  int get(int key) {
    if (hashmap.find(key) == hashmap.end()) {
      return -1;
    }

    Iterators temp = hashmap[key];
    auto current_time = time(nullptr);
    auto expiry_time = temp.cache_iter->m_expiry_time;
    int value = temp.cache_iter->m_value;

    if (expiry_time < current_time) {
      return -1;
    }

    std::lock_guard<std::mutex> lock(mtx);
    update_cache(key, value);

    return value;
  }

  void pop_lru() {
    Node pop_node = cache.back();
    Iterators temp = hashmap[pop_node.m_key];
    time_buckets[pop_node.m_expiry_time].erase(temp.key_iter);
    if (time_buckets[pop_node.m_expiry_time].empty()) {
      time_buckets.erase(pop_node.m_expiry_time);
    }

    cache.pop_back();
    hashmap.erase(pop_node.m_key);

    std::cout << "Capacity reached. Key " << pop_node.m_key << std::endl;
  }

  void put(int key, int value) {
    std::lock_guard<std::mutex> lock(mtx);
    if (hashmap.find(key) != hashmap.end()) {
      std::cout << "key exist, update cache" << std::endl;
      update_cache(key, value);
      return;
    }

    if ((int)hashmap.size() == m_capacity) {
      pop_lru();
    }

    auto exiry_time = time(nullptr) + m_time;
    cache.push_front(Node{key, value, exiry_time});
    time_buckets[exiry_time].push_front(key);
    hashmap[key] = {cache.begin(), time_buckets[exiry_time].begin()};

    std::cout << "Key " << key << " inserted. Value = " << value
              << " . Expiry = " << exiry_time << std::endl;
  }

private:
  int m_capacity;
  int m_time;

  // LRU list
  std::list<Node> cache;

  // map, value is keys that expire expiry_time
  std::map<time_t, std::list<int>> time_buckets;

  //  hashmap, value is iterator
  std::unordered_map<int, Iterators> hashmap;

  std::mutex mtx;

  //  remove expire node
  std::thread clean_thread;
};