&emsp;
# sleep & usleep
## 时钟换算
```py
微秒 us(英语：microsecond)
1us = 1e6s (百万分之一秒)
0.000 001 微秒 = 1皮秒
0.001 微秒 = 1纳秒
1,000 微秒 = 1毫秒
1,000,000 微秒 = 1秒
1s = 1000ms
1ms = 1000μs
1μs = 1000ns
1ns = 1000ps
1s  = 1e3 毫秒(ms) 
    = 1e6 微秒(μs) 
    = 1e9 纳秒(ns) 
    = 1e12 皮秒(ps)
```

## sleep
- 功能: 执行挂起指定的秒数
- 语法: `unsigned sleep(unsigned seconds);`
>头文件

```c++
#include <unistd.h>  // 在gcc编译器中，使用的头文件因gcc版本的不同而不同
```


>Example
```c++
#include<stdio.h>
int main()
{
  int a;
  a=1;
  printf("hello");
  sleep(a);        
  printf("world"); 
  return 0;
}
```


&emsp;
## usleep
- 功能: usleep 功能把进程挂起一段时间， 单位是微秒（百万分之一秒）；
- 语法: `void usleep(int micro_seconds)`;
- 返回值: 无
>头文件
```c++
#include <unistd.h>
```

本函数可暂时使程序停止执行。参数 micro_seconds 为要暂停的微秒数(us)。
>注意
- 这个函数不能工作在windows 操作系统中。用在Linux的测试环境下面

&emsp;
## 区别
usleep() 与sleep()类似，用于延迟挂起进程。进程被挂起放到reday queue

是一般情况下，延迟时间数量级是秒的时候，尽可能使用sleep()函数

如果延迟时间为几十毫秒（1ms = 1000us），或者更小，尽可能使用usleep()函数。这样才能最佳的利用CPU时间

