#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <opencv2/core/core.hpp> // cv::Mat
#include "sophus/se3.hpp" // Sophus::SE3f
#include "ImuTypes.h"

using namespace std;

namespace ORB_SLAM3
{

class System
{
public:
    enum eSensor{
        MONOCULAR=0,
        STEREO=1,
        RGBD=2,
        IMU_MONOCULAR=3,
        IMU_STEREO=4,
        IMU_RGBD=5,
    };
public:
    // Initialize the SLAM system. It launches the Local Mapping, Loop Closing and Viewer threads.
    System(const string &strVocFile, const string &strSettingsFile, const eSensor sensor, const bool bUseViewer = true, const int initFr = 0, const string &strSequence = std::string());
    Sophus::SE3f TrackMonocular(const cv::Mat &im, const double &timestamp, const vector<IMU::Point>& vImuMeas = vector<IMU::Point>(), string filename="");
    
    void Shutdown();

    void SaveTrajectoryEuRoC(const string &filename);
    void SaveKeyFrameTrajectoryEuRoC(const string &filename);

    void ChangeDataset();
    
    float GetImageScale();

};

}



#endif // SYSTEM_H