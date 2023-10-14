&emsp;
# steady&monotonic_clock

在C++11版里已经没有momotonic_clock了，有steady_clock作为替代。

所以orb-slam的作者在代码中使用了ifdef来判断用户的C++版本（大概是这个意思）