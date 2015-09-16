#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API PartialCurveImpl;

typedef PartialCurveImpl<float> PartialCurveF;
typedef PartialCurveImpl<double> PartialCurveD;

} // namespace curve
