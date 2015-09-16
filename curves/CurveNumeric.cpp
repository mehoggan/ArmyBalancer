#include "curve/core/CurveNumeric.h"
#include <NavCore/Math/Geometry/AlignedBox3.h>
#include <NavCore/Math/Vector/Vector3.h>
#include "curve/core/Curve.h"
#include "curve/core/CurveOps.h"

namespace curve
{

template<typename RealT>
NavCore::Math::Vector3Impl<RealT> CurveNumericImpl<RealT>::evaluateTangent(
    const CurveImpl<RealType>& curve, RealType t)
{
    RealType delta = 0.001f;

    RealType backwardT = NavCore::Math::Max<RealType>(t - delta, 0.0f);
    RealType forwardT = NavCore::Math::Min<RealType>(t + delta, 1.0f);

    NavCore::Math::Vector3Impl<RealType> p0 = curve.evaluatePosition(backwardT);
    NavCore::Math::Vector3Impl<RealType> p1 = curve.evaluatePosition(forwardT);

    NavCore::Math::Vector3Impl<RealType> tan;
    tan.Subtract(p1, p0);
    tan.Scale(1.0f / (forwardT - backwardT));
    return tan;
}

template<typename RealT>
std::vector<RealT> CurveNumericImpl<RealT>::computeSampleValues(const CurveImpl<RealType>& curve,
    size_t sampleCount)
{
    NT_ASSERT(sampleCount >= 2);
    sampleCount = NavCore::Math::Max(sampleCount, static_cast<size_t>(2));

    std::vector<RealType> outSamples;
    outSamples.reserve(sampleCount);
    outSamples.push_back(0.0f);
    for (size_t i = 1; i < sampleCount - 1; i++)
    {
        outSamples.push_back(static_cast<RealType>(i) / static_cast<RealType>(sampleCount - 1));
    }
    outSamples.push_back(1.0f);

    return outSamples;
}

template<typename RealT>
NavCore::Math::AlignedBox3Impl<RealT> CurveNumericImpl<RealT>::computeBoundingBox(
    const CurveImpl<RealType>& curve)
{
    NavCore::Math::AlignedBox3Impl<RealType> outBox;
    outBox.Invalidate();
    std::vector<RealType> samples = curve.computeSampleValues(5);
    CurveOpsImpl<RealType>::enforceMinimumSampleCount(samples, 5);

    for (size_t i = 0; i < samples.size(); ++i)
    {
        NavCore::Math::Vector3Impl<RealType> pos = curve.evaluatePosition(samples[i]);
        outBox.GrowToContain(pos);
    }

    return outBox;
}


template class CurveNumericImpl<float>;
template class CurveNumericImpl<double>;

} // namespace curve
