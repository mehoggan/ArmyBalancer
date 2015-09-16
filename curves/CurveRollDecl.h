#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API CurveRollImpl;

typedef CurveRollImpl<float> CurveRollF;
typedef CurveRollImpl<double> CurveRollD;

} // namespace curve
