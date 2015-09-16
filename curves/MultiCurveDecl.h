#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API MultiCurveImpl;

typedef MultiCurveImpl<float> MultiCurveF;
typedef MultiCurveImpl<double> MultiCurveD;

} // namespace curve
