
#ifndef LOOPCLOSING_H
#define LOOPCLOSING_H

#include "Atlas.h"
#include "LoopClosing.h"
#include "Tracking.h"
#include "KeyFrameDatabase.h"
#include "Settings.h"

namespace ORB_SLAM3
{

class Tracking;
class LocalMapping;
class KeyFrameDatabase;
class Map;


class LoopClosing
{
public:
    LoopClosing(Atlas* pAtlas, KeyFrameDatabase* pDB, ORBVocabulary* pVoc,const bool bFixScale, const bool bActiveLC);
    void SetTracker(Tracking* pTracker);

    void SetLocalMapper(LocalMapping* pLocalMapper);
    // Main function
    void Run();

    Viewer* mpViewer;

};

}

#endif // LOOPCLOSING_H