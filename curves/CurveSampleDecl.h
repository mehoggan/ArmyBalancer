#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API CurveSampleImpl;

typedef CurveSampleImpl<float> CurveSampleF;
typedef CurveSampleImpl<double> CurveSampleD;

} // namespace curve
