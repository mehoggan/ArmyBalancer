#include "curve/core/CurveOps.h"
#include <NavCore/Core/Core/Assert.h>

namespace curve
{

template<typename RealT>
void CurveOpsImpl<RealT>::enforceMinimumSampleCount(std::vector<RealType>& outSamples,
    size_t sampleCount)
{
    NT_ASSERT(outSamples.size() >= 2);

    // If too few samples, insert into the largest gap
    while (outSamples.size() < sampleCount)
    {
        RealType maxGap = 0;
        size_t maxGapIndex = 0;
        for (size_t i = 0; i < outSamples.size() - 1; ++i)
        {
            RealType gap = std::abs(outSamples[i + 1] - outSamples[i]);
            if (gap > maxGap)
            {
                maxGap = gap;
                maxGapIndex = i;
            }
        }

        RealType newVal = (outSamples[maxGapIndex] + outSamples[maxGapIndex + 1]) / 2.0f;
        outSamples.insert(outSamples.begin() + maxGapIndex + 1, newVal);
    }
}


template class CurveOpsImpl<float>;
template class CurveOpsImpl<double>;

} // namespace curve
