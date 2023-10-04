&emsp;
# Intro
- GitHub: https://github.com/UZ-SLAMLab/ORB_SLAM3
- Paper: 



要可视化运行，先改可执行文件源码重新编译
- false 改为 true
```c++
// ORB_SLAM3::System SLAM(argv[1],argv[2],ORB_SLAM3::System::IMU_STEREO, false);
ORB_SLAM3::System SLAM(argv[1],argv[2],ORB_SLAM3::System::IMU_STEREO, true);
```