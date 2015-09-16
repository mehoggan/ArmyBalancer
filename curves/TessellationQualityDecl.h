#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API TessellationQualityImpl;

typedef TessellationQualityImpl<float> TessellationQualityf;
typedef TessellationQualityImpl<double> TessellationQualityd;

} // namespace curve
