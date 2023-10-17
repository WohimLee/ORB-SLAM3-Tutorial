
#include "Tracking.h"


namespace ORB_SLAM3
{
Tracking::Tracking(
    System *pSys, ORBVocabulary* pVoc, 
    FrameDrawer *pFrameDrawer, MapDrawer *pMapDrawer, 
    Atlas *pAtlas, KeyFrameDatabase* pKFDB, 
    const string &strSettingPath, const int sensor, Settings* settings, const string &_nameSeq)
{
}

void Tracking::SetLocalMapper(LocalMapping* pLocalMapper)
{}

void Tracking::SetLoopClosing(LoopClosing* pLoopClosing)
{}

void Tracking::SetViewer(Viewer* pViewer)
{}


}

