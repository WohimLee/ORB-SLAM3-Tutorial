&emsp;
# Installation

## 1 Dependencies
- opencv-4.5.1：记住 ORB-SLAM3 里面 Thirdparty 的所有 opencv 也要指定路径
- eigen-3.1.0
- Pangolin-0.6
- realsense-2.54.2

>Others
```sh
sudo apt install libboost-dev libboost-serialization-dev
```

&emsp;
## 2 编译 Thirdparty
因为需要指定 OpenCV 版本, 所以要先单独编译 Thirdparty 里面的库, DBoW2, g2o, Sophus 都用下面这个脚本编译, 不需要 make install
>build_thirdparty.sh
```sh
mkdir -p build
cd build
cmake .. -DOpenCV_DIR=/home/nerf/datav/SourceCode/opencv-4.5.1/build/
make -j8
```

&emsp;
## 3 编译 ORB-SLAM3
需要指定包含 OpenCVConfig.cmake 的路径