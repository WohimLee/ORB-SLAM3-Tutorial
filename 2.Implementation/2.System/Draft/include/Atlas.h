#ifndef ATLAS_H
#define ATLAS_H


namespace ORB_SLAM3
{
class Atlas
{


public:
    Atlas();
    Atlas(int initKFid); // When its initialization the first map is created
    ~Atlas();

    void CreateNewMap();
    void SetInertialSensor();
};
}

#endif // ATLAS_H