&emsp;
# std::mutex

std::mutex 是 C++11 中最基本的互斥量

## 成员函数

>构造函数
- std::mutex 不允许拷贝构造，也不允许 move 拷贝，最初产生的 mutex 对象是处于 unlocked 状态的

>lock()
- 调用线程将锁住该互斥量。线程调用该函数会发生下面 3 种情况
    1. 如果该互斥量当前没有被锁住，则调用线程将该互斥量锁住，直到调用 unlock 之前，该线程一直拥有该锁
    2. 如果当前互斥量被其他线程锁住，则当前的调用线程被阻塞住
    3. 如果当前互斥量被当前调用线程锁住，则会产生死锁(deadlock)。

>unlock()
- 解锁，释放对互斥量的所有权

>try_lock()
- 尝试锁住互斥量，如果互斥量被其他线程占有，则当前线程也不会被阻塞。线程调用该函数也会出现下面 3 种情况
    1. 如果当前互斥量没有被其他线程占有，则该线程锁住互斥量，直到该线程调用 unlock 释放互斥量
    2. 如果当前互斥量被其他线程锁住，则当前调用线程返回 false，而并不会被阻塞掉
    3. 如果当前互斥量被当前调用线程锁住，则会产生死锁(deadlock)


>Example
```c++
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
```