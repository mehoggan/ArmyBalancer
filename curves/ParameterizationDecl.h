#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API ParameterizationImpl;

typedef ParameterizationImpl<float> ParameterizationF;
typedef ParameterizationImpl<double> ParameterizationD;

} // namespace curve