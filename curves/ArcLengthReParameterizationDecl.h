#pragma once

#include "curve/CurveApi.h"

namespace curve
{

template<typename RealT>
class CURVE_API ArcLengthReParameterizationQualityImpl;

typedef ArcLengthReParameterizationQualityImpl<float> ArcLengthReParameterizationQualityF;
typedef ArcLengthReParameterizationQualityImpl<double> ArcLengthReParameterizationQualityD;

template<typename RealT>
class CURVE_API ArcLengthReParameterizationImpl;

typedef ArcLengthReParameterizationImpl<float> ArcLengthReParameterizationF;
typedef ArcLengthReParameterizationImpl<double> ArcLengthReParameterizationD;

} // namespace curve