
#include "KeyFrame.h"
#include "Converter.h"
#include <mutex>


namespace ORB_SLAM3
{


KeyFrame::KeyFrame()
{

}


Sophus::SE3f KeyFrame::GetPose()
{
    unique_lock<mutex> lock(mMutexPose);
    return mTcw;
}

} //namespace ORB_SLAM
