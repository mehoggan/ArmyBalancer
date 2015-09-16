#include "curve/reverse/ReverseCurve.h"

#include <algorithm>
#include <NavCore/Math/Geometry/AlignedBox3.h>
#include <NavCore/Math/Vector/Vector3.h>

namespace curve
{

template <typename RealT>
NavCore::Math::Vector3Impl<RealT> ReverseCurveImpl<RealT>::evaluatePosition(RealType t) const
{
    NavCore::Math::Vector3Impl<RealT> position;
    if (m_curve)
        position = m_curve->evaluatePosition(1 - t);

    return position;
}

template <typename RealT>
NavCore::Math::Vector3Impl<RealT> ReverseCurveImpl<RealT>::evaluateTangent(RealType t) const
{
    NavCore::Math::Vector3Impl<RealT> tangent;
    if (m_curve)
        tangent = -m_curve->evaluateTangent(1 - t);

    return tangent;
}

template <typename RealT>
CurveSampleImpl<RealT> ReverseCurveImpl<RealT>::evaluate(RealType t) const
{
    CurveSampleImpl<RealT> curveSample;
    if (m_curve)
    {
        curveSample = m_curve->evaluate(1 - t);
        curveSample.m_tangent.Negate();
    }

    return curveSample;
}

template <typename RealT>
NavCore::Math::AlignedBox3Impl<RealT> ReverseCurveImpl<RealT>::computeBoundingBox() const
{
    NavCore::Math::AlignedBox3Impl<RealT> bounds;
    if (m_curve)
        bounds = m_curve->computeBoundingBox();

    return bounds;
}

template <typename RealT>
std::vector<RealT> ReverseCurveImpl<RealT>::computeSampleValues(size_t sampleCount) const
{
    std::vector<RealType> sampleValues;
    if (m_curve)
    {
        sampleValues = m_curve->computeSampleValues(sampleCount);
        std::reverse(sampleValues.begin(), sampleValues.end());
        for (RealT& sample : sampleValues)
            sample = 1 - sample;
    }

    return sampleValues;
}

template <typename RealT>
std::vector<CurveSampleImpl<RealT>> ReverseCurveImpl<RealT>::computeSamplesAdaptive(
    const TessellationQualityImpl<RealType>& quality) const
{
    std::vector<CurveSampleImpl<RealType>> samples;
    if (m_curve)
    {
        samples = m_curve->computeSamplesAdaptive(quality);
        std::reverse(samples.begin(), samples.end());
        for (CurveSampleImpl<RealType>& sample : samples)
        {
            sample.m_parameter = 1 - sample.m_parameter;
            sample.m_tangent.Negate();
        }
    }

    return samples;
}

template class ReverseCurveImpl<float>;
template class ReverseCurveImpl<double>;

} // namespace curve
