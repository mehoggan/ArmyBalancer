#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API TessellatorImpl;

typedef TessellatorImpl<float> TessellatorF;
typedef TessellatorImpl<double> TessellatorD;

} // namespace curve
