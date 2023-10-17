
#ifndef TRACKING_H
#define TRACKING_H

#include "Viewer.h"
#include "FrameDrawer.h"
#include "Atlas.h"
#include "LocalMapping.h"
#include "LoopClosing.h"
#include "ORBVocabulary.h"
#include "KeyFrameDatabase.h"
#include "MapDrawer.h"
#include "System.h"
#include "ImuTypes.h"
#include "Settings.h"

namespace ORB_SLAM3
{

class System;

class Tracking
{  

public:
    Tracking(System* pSys, ORBVocabulary* pVoc, 
        FrameDrawer* pFrameDrawer, MapDrawer* pMapDrawer, 
        Atlas* pAtlas, KeyFrameDatabase* pKFDB, 
        const string &strSettingPath, const int sensor, Settings* settings, const string &_nameSeq=std::string());
    void SetLocalMapper(LocalMapping* pLocalMapper);
    void SetLoopClosing(LoopClosing* pLoopClosing);
    void SetViewer(Viewer* pViewer);

};
}

#endif // TRACKING_H