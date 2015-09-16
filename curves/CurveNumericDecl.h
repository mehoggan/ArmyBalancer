#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API CurveNumericImpl;

typedef CurveNumericImpl<float> CurveNumericF;
typedef CurveNumericImpl<double> CurveNumericD;

} // namespace curve
