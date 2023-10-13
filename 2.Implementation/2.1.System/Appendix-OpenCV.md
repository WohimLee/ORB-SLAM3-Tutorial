&emsp;
# Appendix - OpenCV

## cv::FileStorage
OpenCV 提供了一种序列化和反序列化的机制，用于将不同数据类型的数据以 YAML 或 XML 格式写入磁盘或者从磁盘读取。这种方法可以用来加载或者保存任何 OpenCV 的数值变量（包括基本数据变量，像 int 和 float 等）到一个文件中

上述文件读写的基本机制是建立在 cv::FileStorage 对象基础上的，cv::FileStorage 实际代表磁盘中的一个文件，但与普通方式不同的是，它让人们以一种简单而自然的方式访问文件中的数据
>头文件
```c++
#include <opencv2/opencv.hpp>
```