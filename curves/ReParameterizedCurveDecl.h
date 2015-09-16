#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API ReParameterizedCurveImpl;

typedef ReParameterizedCurveImpl<float> ReParameterizedCurveF;
typedef ReParameterizedCurveImpl<double> ReParameterizedCurveD;

} // namespace curve