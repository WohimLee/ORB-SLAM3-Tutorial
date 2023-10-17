
#ifndef IMUTYPES_H
#define IMUTYPES_H

#include <opencv2/core/core.hpp>

namespace ORB_SLAM3
{

namespace IMU
{

const float GRAVITY_VALUE=9.81;

//IMU measurement (gyro, accelerometer and timestamp)
class Point
{
public:
    Point(const float &acc_x, const float &acc_y, const float &acc_z,
             const float &ang_vel_x, const float &ang_vel_y, const float &ang_vel_z,
             const double &timestamp){}
    Point(const cv::Point3f Acc, const cv::Point3f Gyro, const double &timestamp){}

};
} // IMU
} // ORB_SLAM3


#endif // IMUTYPES_H