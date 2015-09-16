#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API CurveOpsImpl;

typedef CurveOpsImpl<float> CurveOpsF;
typedef CurveOpsImpl<double> CurveOpsD;

} // namespace curve
