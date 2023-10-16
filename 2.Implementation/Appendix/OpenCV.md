&emsp;
# OpenCV

## cv::FileStorage
OpenCV 提供了一种序列化和反序列化的机制，用于将不同数据类型的数据以 YAML 或 XML 格式写入磁盘或者从磁盘读取。这种方法可以用来加载或者保存任何 OpenCV 的数值变量（包括基本数据变量，像 int 和 float 等）到一个文件中

上述文件读写的基本机制是建立在 cv::FileStorage 对象基础上的，cv::FileStorage 实际代表磁盘中的一个文件，但与普通方式不同的是，它让人们以一种简单而自然的方式访问文件中的数据
>头文件
```c++
#include <opencv2/opencv.hpp>
```

&emsp;
## cv::FileNode
cv::FileNode 通常在 cv::FileStorage 对象读取文件时使用，cv::FileStorage::operator>> 操作符的返回值是一个 cv::FileNode 对象

成功构建 cv::FileNode 对象之后，便可以利用它来完成许多工作。如果直接表示一个实际的对象（或者一个数字或者字符串），可以直接使用重载操作符cv::FileStorage::operator>>()，将它的值加载到对应类型的变量之中


可以使用迭代器完成对 cv::FileNode 的遍历。给定一个 cv::FileNode 对象，使用成员函数 cv::FileNode::begin() 和 cv::FileNode::end() 可以分别返回首元素的迭代器和末尾元素的迭代器





