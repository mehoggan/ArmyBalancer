#include "curve/transform/TransformCurve.h"

#include <algorithm>
#include <NavCore/Math/Geometry/AlignedBox3.h>
#include <NavCore/Math/Vector/Vector3.h>

namespace curve
{

template <typename RealT>
NavCore::Math::Vector3Impl<RealT> TransformCurveImpl<RealT>::evaluatePosition(RealType t) const
{
    NavCore::Math::Vector3Impl<RealT> position;
    if (m_curve)
        position = m_transform.Transform(m_curve->evaluatePosition(t));

    return position;
}

template <typename RealT>
NavCore::Math::Vector3Impl<RealT> TransformCurveImpl<RealT>::evaluateTangent(RealType t) const
{
    NavCore::Math::Vector3Impl<RealT> tangent;
    if (m_curve)
        tangent = m_transformInverseTranspose.Transform3x3(m_curve->evaluateTangent(t));

    return tangent;
}

template <typename RealT>
CurveSampleImpl<RealT> TransformCurveImpl<RealT>::evaluate(RealType t) const
{
    CurveSampleImpl<RealT> curveSample;
    if (m_curve)
    {
        curveSample = m_curve->evaluate(t);
        curveSample.m_position = m_transform.Transform(curveSample.m_position);
        curveSample.m_tangent = m_transformInverseTranspose.Transform3x3(curveSample.m_tangent);
    }

    return curveSample;
}

template <typename RealT>
NavCore::Math::AlignedBox3Impl<RealT> TransformCurveImpl<RealT>::computeBoundingBox() const
{
    NavCore::Math::AlignedBox3Impl<RealT> bounds;
    if (m_curve)
    {
        bounds = m_curve->computeBoundingBox();
        bounds.Transform(m_transform);
    }

    return bounds;
}

template <typename RealT>
std::vector<RealT> TransformCurveImpl<RealT>::computeSampleValues(size_t sampleCount) const
{
    std::vector<RealType> sampleValues;
    if (m_curve)
        sampleValues = m_curve->computeSampleValues(sampleCount);

    return sampleValues;
}

template <typename RealT>
std::vector<CurveSampleImpl<RealT>> TransformCurveImpl<RealT>::computeSamplesAdaptive(
    const TessellationQualityImpl<RealType>& quality) const
{
    std::vector<CurveSampleImpl<RealType>> samples;
    if (m_curve)
    {
        samples = m_curve->computeSamplesAdaptive(quality);
        for (CurveSampleImpl<RealType>& sample : samples)
        {
            sample.m_position = m_transform.Transform(sample.m_position);
            sample.m_tangent = m_transformInverseTranspose.Transform3x3(sample.m_tangent);
        }
    }

    return samples;
}

template class TransformCurveImpl<float>;
template class TransformCurveImpl<double>;

} // namespace curve
