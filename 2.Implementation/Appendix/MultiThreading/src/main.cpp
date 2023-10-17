#include <iostream>
#include <thread>

void func(int &a, int b){
    b = a;
    printf("Runing thread: 1\n");
}


int main(int argc, char** argv)
{
    printf("Running Main Thread...\n");
    int a = 888;
    int b = 999;
    std::thread t(func, std::ref(a), b);

    t.join();

    return  0;
}