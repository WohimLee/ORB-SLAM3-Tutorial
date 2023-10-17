#ifndef LOCALMAPPING_H
#define LOCALMAPPING_H

#include <string>

using namespace std;

namespace ORB_SLAM3
{

class System;
class Tracking;
class LoopClosing;
class Atlas;

class LocalMapping
{
public:
    LocalMapping(System* pSys, Atlas* pAtlas, const float bMonocular, bool bInertial, const string &_strSeqName=std::string());

    void SetLoopCloser(LoopClosing* pLoopCloser);

    void SetTracker(Tracking* pTracker);

    // Main function
    void Run();

    // For debugging (erase in normal mode)
    int mInitFr;

    // not consider far points (clouds)
    bool mbFarPoints;
    float mThFarPoints;
};
}

#endif // LOCALMAPPING_H