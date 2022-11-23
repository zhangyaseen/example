#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <pthread.h>
#include <cstring>
#include <mutex>

std::mutex iomutex;

void f1(int n){
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread " << n << " executing\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void f2(int& n){
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 2 executing\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void thread_task(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "hello thread "
        << std::this_thread::get_id()
        << " paused " << n << " seconds" << std::endl;
} 

void thread_constructor(void) {
    int n = 0;
    std::thread t1; // t1 is not a thread
    std::thread::id t1_id = t1.get_id();
    std::cout << "t1 thead id: " << t1_id << " joinable: " << t1.joinable() << std::endl;;

    std::thread t2(f1, n + 1); // pass by value
    std::thread::id t2_id = t2.get_id();
    std::cout << "t2 thead id: " << t2_id << " joinable: " << t2.joinable() << std::endl;;

    std::thread t3(f2, std::ref(n)); // pass by reference
    std::thread::id t3_id = t3.get_id();
    std::cout << "t3 thead id: " << t3_id << " joinable: " << t3.joinable() << std::endl;;

    std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
    std::thread::id t4_id = t4.get_id();
    std::cout << "t4 thead id: " << t4_id << " joinable: " << t4.joinable() << std::endl;;

    t2.join();
    t4.join();

    std::cout << "Final value of n is " << n << '\n';
}

void thread_assigment(void) {
    std::thread threads[5];
    std::cout << "Spawning 5 threads...\n";
    for (int i = 0; i < 5; i++) {
        threads[i] = std::thread(thread_task, i + 1);
    }
    std::cout << "Done spawning threads! Now wait for them to join\n";
    for (auto& t: threads) {
        t.join();
    }
    std::cout << "All threads joined.\n";
}

void independentThread() {
    std::cout << "Starting concurrent thread.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Exiting concurrent thread.\n";
}

void thread_detach(void) {
    std::cout << "Starting thread caller.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Exiting thread caller.\n";

    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void thread_swap() {
    std::thread t1(independentThread);
    std::thread t2(independentThread);

    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    std::swap(t1, t2);

    std::cout << "after std::swap(t1, t2):" << std::endl;
    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    t1.swap(t2);

    std::cout << "after t1.swap(t2):" << std::endl;
    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;

    t1.join();
    t2.join();
}

void get_sched_param(int num) {
    std::this_thread::sleep_for(std::chrono::seconds(1));

    sched_param sch;
    int policy; 
    pthread_getschedparam(pthread_self(), &policy, &sch);
    std::lock_guard<std::mutex> lk(iomutex);
    std::cout << "Thread " << num << " is executing at priority "
           << sch.sched_priority << '\n';
}

void thread_native_handle(void) {
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";

    std::thread t1(get_sched_param, 1);
    std::thread t2(get_sched_param, 2);

    sched_param sch;
    int policy; 
    pthread_getschedparam(t1.native_handle(), &policy, &sch);
    sch.sched_priority = 20;
    // root privilege
    if(pthread_setschedparam(t1.native_handle(), SCHED_FIFO, &sch)) {
        std::cout << "Failed to setschedparam: " << std::strerror(errno) << '\n';
    }

    t1.join();
    t2.join();
}


void foo(){
  std::thread::id this_id = std::this_thread::get_id();

  iomutex.lock();
  std::cout << "thread " << this_id << " sleeping...\n";
  iomutex.unlock();

  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void thread_this(void) {
    std::thread t1(foo);
    std::thread t2(foo);

    t1.join();
    t2.join();
}

void little_sleep(std::chrono::microseconds us){
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start + us;
    do {
        std::this_thread::yield();
    } while (std::chrono::high_resolution_clock::now() < end);
}


void sleep_time(std::chrono::microseconds us) {
    std::this_thread::sleep_for(us);
}

void thread_yield(void) {
    auto start = std::chrono::high_resolution_clock::now();

    little_sleep(std::chrono::microseconds(100));

    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "waited for "
            << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
            << " microseconds\n";

    start = std::chrono::high_resolution_clock::now();
    sleep_time(std::chrono::microseconds(100));
    elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "waited for "
            << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
            << " microseconds\n";
}

int main(){
    // thread_constructor();

    // thread_assigment();

    // thread_detach();

    // thread_swap();

    // thread_native_handle();

    // thread_this();

    // thread_yield();

    return 0;
}