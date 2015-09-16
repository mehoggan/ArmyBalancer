#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API LinearCurveImpl;

typedef LinearCurveImpl<float> LinearCurveF;
typedef LinearCurveImpl<double> LinearCurveD;

} // namespace curve
