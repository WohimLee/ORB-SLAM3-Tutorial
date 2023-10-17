
#ifndef FRAMEDRAWER_H
#define FRAMEDRAWER_H

#include <Eigen/Core>
#include "Atlas.h"

namespace ORB_SLAM3
{

class FrameDrawer
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    FrameDrawer(Atlas* pAtlas);
    bool both;
};
}

#endif // FRAMEDRAWER_H