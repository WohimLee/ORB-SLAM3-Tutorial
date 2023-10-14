

#include "System.h"

#include <string>

using namespace std;


namespace ORB_SLAM3
{
System::System(const string &strVocFile, const string &strSettingsFile, const eSensor sensor,
               const bool bUseViewer, const int initFr, const string &strSequence)
{
    printf("Call constructor: System::System\n");
}

Sophus::SE3f System::TrackMonocular(const cv::Mat &im, const double &timestamp, const vector<IMU::Point>& vImuMeas, string filename)
{
    printf("Tracking Monocular: ");
}

void System::Shutdown(){
    printf("Shut down ORB-SLAM3.\n");
}

void System::SaveTrajectoryEuRoC(const string& filename){
    printf("Saving trajectory EuRoc...\n");
}

void System::SaveKeyFrameTrajectoryEuRoC(const string& filename){
    printf("Saving key frame trajectory EuRoc...\n");
}


void System::ChangeDataset(){
    printf("Changing dataset...\n");
}

float System::GetImageScale(){
    printf("Return image scale\n");
    return 0.5;
}
}