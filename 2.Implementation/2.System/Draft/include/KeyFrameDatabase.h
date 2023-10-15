#ifndef KEYFRAMEDATABASE_H
#define KEYFRAMEDATABASE_H

#include "ORBVocabulary.h"

#include <list>
#include <vector>

using namespace std;

namespace ORB_SLAM3
{
class KeyFrame;
class KeyFrameDatabase
{

public:
    KeyFrameDatabase(){}
    KeyFrameDatabase(const ORBVocabulary &voc);

protected:
    // Associated vocabulary
    const ORBVocabulary* mpVoc;
    // Inverted file
    std::vector<list<KeyFrame*> > mvInvertedFile;
    
}; // KeyFrameDatabase
} // ORB_SLAM3


#endif // KEYFRAMEDATABASE_H