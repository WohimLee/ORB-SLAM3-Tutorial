#ifndef MAPDRAWER_H
#define MAPDRAWER_H

#include "Atlas.h"
#include <Eigen/Core>
#include <string>

using namespace std;

namespace ORB_SLAM3
{

class Settings;

class MapDrawer
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    MapDrawer(Atlas* pAtlas, const string &strSettingPath, Settings* settings);
};
}


#endif // MAPDRAWER_H


