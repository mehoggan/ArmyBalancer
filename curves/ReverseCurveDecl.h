#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API ReverseCurveImpl;

typedef ReverseCurveImpl<float> ReverseCurveF;
typedef ReverseCurveImpl<double> ReverseCurveD;

} // namespace curve
