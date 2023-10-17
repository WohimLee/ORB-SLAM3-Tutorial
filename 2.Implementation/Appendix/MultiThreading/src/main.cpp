#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> data_queue;
bool finished = false;

void producer(int n) {
    for (int i = 0; i < n; ++i) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            data_queue.push(i);
        } // lock is released here
        
        cv.notify_one(); // Notify the consumer
    }

    {
        std::unique_lock<std::mutex> lock(mtx);
        finished = true;
    }
    cv.notify_one();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !data_queue.empty() || finished; }); // Wait until there's data to process or producer is finished

        while (!data_queue.empty()) {
            int data = data_queue.front();
            data_queue.pop();
            lock.unlock();  // Manually unlock to allow other operations while we're processing data

            std::cout << "Processed: " << data << std::endl;

            lock.lock();  // Manually relock for the next iteration
        }

        if (finished) {
            break;
        }
    }
}

int main(int argc, char** argv) {
    std::thread prod(producer, 10);
    std::thread cons(consumer);

    prod.join();
    cons.join();

    return 0;
}


