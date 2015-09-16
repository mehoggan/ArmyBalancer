#include "curve/interpolated/InterpolatedCurve.h"

#include <algorithm>
#include <NavCore/Math/Geometry/AlignedBox3.h>
#include <NavCore/Math/Vector/Vector3.h>
#include <NavCore/Math/Core/MathCore.h>

namespace curve
{

template <typename RealT>
void InterpolatedCurveImpl<RealT>::interpolateTs(RealType& outTInterpolate, RealType& outTEvaluate,
    const RealType& t) const
{
    outTInterpolate = NavCore::Math::SmoothStep(t);
    outTEvaluate = NavCore::Math::Lerp(t, m_T0, m_T1);
}

template <typename RealT>
NavCore::Math::Vector3Impl<RealT> InterpolatedCurveImpl<RealT>::evaluatePosition(RealType t) const
{
    NavCore::Math::Vector3Impl<RealT> outPosition;

    if (m_curve0 != nullptr && m_curve1 != nullptr)
    {
        RealType tInterpolate = 0;
        RealType tEvaluate = 0;
        interpolateTs(tInterpolate, tEvaluate, t);
        NavCore::Math::Vector3Impl<RealT> position0 = m_curve0->evaluatePosition(tEvaluate);
        NavCore::Math::Vector3Impl<RealT> position1 = m_curve1->evaluatePosition(tEvaluate);
        outPosition = NavCore::Math::Lerp(tInterpolate, position0, position1);
    }

    return outPosition;
}

template <typename RealT>
NavCore::Math::Vector3Impl<RealT> InterpolatedCurveImpl<RealT>::evaluateTangent(RealType t) const
{
    NavCore::Math::Vector3Impl<RealT> outTangent;

    if (m_curve0 != nullptr && m_curve1 != nullptr)
    {
        outTangent = CurveImpl<RealType>::evaluateTangent(t);
    }

    return outTangent;
}

template <typename RealT>
CurveSampleImpl<RealT> InterpolatedCurveImpl<RealT>::evaluate(RealType t) const
{
    CurveSampleImpl<RealT> outCurveSample;

    if (m_curve0 != nullptr && m_curve1 != nullptr)
    {
        outCurveSample = CurveImpl<RealType>::evaluate(t);
    }

    return outCurveSample;
}

template <typename RealT>
NavCore::Math::AlignedBox3Impl<RealT> InterpolatedCurveImpl<RealT>::computeBoundingBox() const
{
    NavCore::Math::AlignedBox3Impl<RealT> bounds;

    if (m_curve0 != nullptr && m_curve1 != nullptr)
    {
        bounds.GrowToContain(m_curve0->computeBoundingBox());
        bounds.GrowToContain(m_curve1->computeBoundingBox());
    }

    return bounds;
}

template <typename RealT>
std::vector<RealT> InterpolatedCurveImpl<RealT>::computeSampleValues(size_t sampleCount) const
{
    return CurveImpl<RealType>::computeSampleValues(sampleCount);
}

template <typename RealT>
std::vector<CurveSampleImpl<RealT>> InterpolatedCurveImpl<RealT>::computeSamplesAdaptive(
    const TessellationQualityImpl<RealType>& quality) const
{
    return CurveImpl<RealType>::computeSamplesAdaptive(quality);
}

template class InterpolatedCurveImpl<float>;
template class InterpolatedCurveImpl<double>;

} // namespace curve
