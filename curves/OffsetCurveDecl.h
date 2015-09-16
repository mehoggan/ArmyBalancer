#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API OffsetCurveImpl;

typedef OffsetCurveImpl<float> OffsetCurveF;
typedef OffsetCurveImpl<double> OffsetCurveD;

} // namespace curve
