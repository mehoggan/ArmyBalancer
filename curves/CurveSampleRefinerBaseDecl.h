#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API CurveSampleRefinerBaseImpl;

typedef CurveSampleRefinerBaseImpl<float> CurveSampleRefinerBaseF;
typedef CurveSampleRefinerBaseImpl<double> CurveSampleRefinerBaseD;

} // namespace curve