#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API TransformCurveImpl;

typedef TransformCurveImpl<float> TransformCurveF;
typedef TransformCurveImpl<double> TransformCurveD;

} // namespace curve
