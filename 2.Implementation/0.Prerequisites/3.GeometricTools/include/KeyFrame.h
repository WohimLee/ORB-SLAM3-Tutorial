

#ifndef KEYFRAME_H
#define KEYFRAME_H



#include "GeometricCamera.h"
#include "SerializationUtils.h"

#include <mutex>
using namespace std;

namespace ORB_SLAM3
{
class KeyFrame
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    KeyFrame();

    // Pose functions
    Sophus::SE3f GetPose();

public:
    GeometricCamera* mpCamera, *mpCamera2;

    // The following variables need to be accessed trough a mutex to be thread safe.
protected:
    // sophus poses
    Sophus::SE3<float> mTcw;
    // Mutex
    std::mutex mMutexPose; // for pose, velocity and biases

};

} //namespace ORB_SLAM

#endif // KEYFRAME_H
