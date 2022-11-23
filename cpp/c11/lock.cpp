#include <thread>
#include <mutex>
#include <iostream>
 
int g_i = 0;
std::mutex g_i_mutex;  // protects g_i
 
void safe_increment()
{
    const std::lock_guard<std::mutex> lock(g_i_mutex);
    ++g_i;
 
    std::cout << "g_i: " << g_i << "; in thread #"
              << std::this_thread::get_id() << '\n';
 
    // g_i_mutex is automatically released when lock
    // goes out of scope
}
 
int lock_lock_guard()
{
    std::cout << "g_i: " << g_i << "; in main()\n";
 
    std::thread t1(safe_increment);
    std::thread t2(safe_increment);
 
    t1.join();
    t2.join();
 
    std::cout << "g_i: " << g_i << "; in main()\n";
}

struct Box{
    explicit Box(int num) : num_things{num} {}
 
    int num_things;
    std::mutex m;
};
 

void work1(int& s) {
	for (int i = 1; i <= 5000; i++) {
		std::unique_lock<std::mutex> munique(g_i_mutex, std::defer_lock);
		munique.lock();
		s += i;
		munique.unlock(); // can delete 
	}
}

void work2(int& s) {
	for (int i = 5001; i <= 10000; i++) {
		std::unique_lock<std::mutex> munique(g_i_mutex, std::defer_lock);
		munique.lock();
		s += i;
		munique.unlock();
	}
}

int lock_unigue_lock(){
	int ans = 0;
	std::thread t1(work1, std::ref(ans));
	std::thread t2(work2, std::ref(ans));
	t1.join();
	t2.join();
	std::cout << ans << std::endl;
	return 0;
}

int main(void) {
    // lock_lock_guard();

    lock_unigue_lock();

    return 0;
}