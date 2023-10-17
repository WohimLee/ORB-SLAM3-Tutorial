&emsp;
# std::thread

## 1 Basics of std::thread
### 1.1 Initialization
You can create a thread by passing a function (or callable object) to the std::thread constructor. This function will be executed in the new thread.

>Example
```c++
void myFunction() {
    // Code to run in the thread
}
std::thread myThread(myFunction);
```
### 1.2 Joining
When you're done with a thread, you have two primary options: join or detach. Joining with a thread means waiting for its completion.

>Example
```c++
myThread.join();
```

### 1.3 Detaching
If you don't need to wait for a thread to finish (and don't care about its completion status), you can detach it. This allows the thread to run independently in the background.

>Example
```c++
myThread.detach();
```

### 1.4 Thread ID
Every thread has a unique ID associated with it which can be retrieved using the get_id() function.

>Example
```c++
std::thread::id id = myThread.get_id();
```

### 1.5 Hardware Concurrency
You can check the number of threads that can run concurrently for the given system.

>Example
```c++
unsigned int n = std::thread::hardware_concurrency();
```

&emsp;
## 2 Some Important Notes
Always ensure you either join() or detach() a thread before its destructor is called, otherwise the program will terminate (std::terminate will be called). If you don't decide between joining or detaching a thread, you can face undefined behavior.

Using global variables or shared data among threads can lead to race conditions. It's crucial to use synchronization techniques, like std::mutex, to ensure safe access to shared data.

It's often a good idea to limit the number of threads to the number of cores on the machine or slightly more, depending on the nature of the task (IO-bound vs. CPU-bound). Creating a very large number of threads can lead to excessive context switching, reducing the overall performance.

&emsp;
## 3 Simple Example
```c++
#include <iostream>
#include <thread>

void printHello(int id) {
    std::cout << "Hello from thread " << id << "!\n";
}

int main() {
    std::thread t1(printHello, 1);
    std::thread t2(printHello, 2);

    t1.join();
    t2.join();

    return 0;
}
```

In this simple example, two threads are created. Each thread prints a greeting to the console. The main() function waits for both threads to finish using join() before terminating.