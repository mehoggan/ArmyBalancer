#pragma once

#include <stdlib.h>
#include <vector>
#include "curve/core/CurveOpsDecl.h"

namespace curve
{

template<typename RealT>
class CURVE_API CurveOpsImpl
{
public:
    using RealType = RealT;

    /**
     * @brief Adds sampling points to the samples vector until it reaches sampleCount. It does this
     * by iteratively adding points to the largest gap in the samples vector.
     */
    static void enforceMinimumSampleCount(std::vector<RealType>& outSamples, size_t sampleCount);
};

} // namespace curve
