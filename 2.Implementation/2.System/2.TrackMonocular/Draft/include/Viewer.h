#ifndef VIEWER_H
#define VIEWER_H

#include <string>

using namespace std;

namespace ORB_SLAM3
{

class Tracking;
class FrameDrawer;
class MapDrawer;
class System;
class Settings;

class Viewer
{
public:
    Viewer(
        System* pSystem, 
        FrameDrawer* pFrameDrawer, MapDrawer* pMapDrawer, 
        Tracking *pTracking, 
        const string &strSettingPath, Settings* settings);

    // Main thread function. Draw points, keyframes, the current camera pose and the last processed
    // frame. Drawing is refreshed according to the camera fps. We use Pangolin.
    void Run();

    bool both;

};
}

#endif // VIEWER_H