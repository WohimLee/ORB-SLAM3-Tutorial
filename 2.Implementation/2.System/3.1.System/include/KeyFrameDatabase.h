#ifndef KEYFRAMEDATABASE_H
#define KEYFRAMEDATABASE_H


namespace ORB_SLAM3
{

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