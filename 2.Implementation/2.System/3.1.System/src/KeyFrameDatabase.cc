
#include "KeyFrameDatabase.h"
#include "ORBVocabulary.h"

namespace ORB_SLAM3
{

KeyFrameDatabase::KeyFrameDatabase (const ORBVocabulary &voc):
    mpVoc(&voc)
{
    mvInvertedFile.resize(voc.size());
}
} // ORB_SLAM3