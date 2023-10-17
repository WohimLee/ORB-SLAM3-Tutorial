
#ifndef ATLAS_H
#define ATLAS_H


namespace ORB_SLAM3
{
class Viewer;
class Map;
class MapPoint;
class KeyFrame;
class KeyFrameDatabase;
class Frame;
class KannalaBrandt8;
class Pinhole;

class Atlas
{

public:
    Atlas();
    Atlas(int initKFid); // When its initialization the first map is created
    ~Atlas();
    void CreateNewMap();
    void SetInertialSensor();

}; // Atlas
} // ORB_SLAM3

#endif // ATLAS_H