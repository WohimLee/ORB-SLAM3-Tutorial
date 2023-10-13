#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <Eigen/Core> // EIGEN_MAKE_ALIGNED_OPERATOR_NEW
#include<opencv2/core/core.hpp> // cv::FileStorage, cv::FileNode

using namespace std;

namespace ORB_SLAM3
{
class Viewer;
class Settings;
class System
{
public:
    // Input sensor
    enum eSensor{
        MONOCULAR=0,
        STEREO=1,
        RGBD=2,
        IMU_MONOCULAR=3,
        IMU_STEREO=4,
        IMU_RGBD=5,
    };

public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    // Initialize the SLAM system. It launches the Local Mapping, Loop Closing and Viewer threads.
    System(const string &strVocFile, const string &strSettingsFile, const eSensor sensor, const bool bUseViewer = true, const int initFr = 0, const string &strSequence = std::string());

private:
    // Input sensor
    eSensor mSensor;

    // The viewer draws the map and the current camera pose. It uses Pangolin.
    Viewer* mpViewer;

    // Reset flag
    bool mbReset;
    bool mbResetActiveMap;

    // Change mode flags
    bool mbActivateLocalizationMode;
    bool mbDeactivateLocalizationMode;

    // Shutdown flag
    bool mbShutDown;
    Settings* settings_;

};
}

#endif // SYSTEM_H