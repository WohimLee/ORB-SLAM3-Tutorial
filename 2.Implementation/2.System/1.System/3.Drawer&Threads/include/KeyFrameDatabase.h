

#ifndef KEYFRAMEDATABASE_H
#define KEYFRAMEDATABASE_H

#include "ORBVocabulary.h"


namespace ORB_SLAM3
{

class KeyFrame;
class Frame;
class Map;


class KeyFrameDatabase
{

public:

    KeyFrameDatabase(){}
    KeyFrameDatabase(const ORBVocabulary &voc);
}; // KeyFrameDatabase
} // ORB_SLAM3


#endif // KEYFRAMEDATABASE_H