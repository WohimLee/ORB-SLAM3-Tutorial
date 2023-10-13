&emsp;
# Appendix - C++

## stringstream
通常用来做数据转换, 用于 string 与其他变量类型的转换，相比c库的转换，它更加安全，自动和直接
>头文件
```c++
#include <fstream>
```


## .eof()
- C++ eof() 函数可以帮助我们用来判断文件是否为空, 或者是判断其是否读到文件结尾
>头文件
```c++
#include 
```


## string.find()
- 返回值是字符在母串中的位置（下标记录）, 如果没有找到, 那么会返回一个特别的标记 npos（返回值可以看成是一个int型的数）
>头文件
```c++
#include 
```

## string::npos
```c++
static const size_type npos = -1;
```
- 该值表示 "直到字符串结尾", 作为返回值它通常被用作表明没有匹配
>头文件
```c++
#include 
```

## stod
- 将数字字符串转化为 double 型
- 在截取过程中遇到非法字符（包括空格）停止截数
>头文件
```c++
#include 
```

