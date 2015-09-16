#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API InterpolatedCurveImpl;

typedef InterpolatedCurveImpl<float> InterpolatedCurveF;
typedef InterpolatedCurveImpl<double> InterpolatedCurveD;

} // namespace curve
