#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API CurveImpl;

typedef CurveImpl<float> CurveF;
typedef CurveImpl<double> CurveD;

} // namespace curve
