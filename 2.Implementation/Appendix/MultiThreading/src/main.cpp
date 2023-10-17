#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx; // Mutex for critical section

void printHello(int id) {
    mtx.lock();
    std::cout << "Hello from thread " << id << "!\n";
    mtx.unlock();
}

int main() {
    std::vector<std::thread> threads;

    // Launch multiple threads
    for (int i = 0; i < 5; ++i) {
        threads.push_back(std::thread(printHello, i));
    }

    // Join the threads to the main thread
    for (auto& th : threads) {
        th.join();
    }

    return 0;
}
