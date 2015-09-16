#include "curve/offset/OffsetCurve.h"
#include <NavCore/Math/Geometry/AlignedBox3.h>
#include <NavCore/Math/Vector/Matrix34.h>

namespace curve
{

template<typename RealT>
OffsetCurveImpl<RealT>::OffsetCurveImpl(ConstCurvePtr curve)
    : m_curve(curve)
{
}

template<typename RealT>
void OffsetCurveImpl<RealT>::setUpDirection(const NavCore::Math::Vector3Impl<RealType>& upDirection)
{
    m_curveRoll.setUpDirection(upDirection);
}

template<typename RealT>
void OffsetCurveImpl<RealT>::addRollInterpolation(NavCore::Math::InterpolateImpl<RealType>& interpolate, RealType startT)
{
    m_curveRoll.getInterpolations().AddInterpolation(interpolate, startT);
}

template<typename RealT>
void OffsetCurveImpl<RealT>::addHorizontalInterpolation(NavCore::Math::InterpolateImpl<RealType>& interpolate, RealType startT)
{
    m_horizontalInterpolation.AddInterpolation(interpolate, startT);
}

template<typename RealT>
void OffsetCurveImpl<RealT>::addVerticalInterpolation(NavCore::Math::InterpolateImpl<RealType>& interpolate, RealType startT)
{
    m_verticalInterpolation.AddInterpolation(interpolate, startT);
}

template<typename RealT>
void OffsetCurveImpl<RealT>::addYawInterpolation(NavCore::Math::InterpolateImpl<RealType>& interpolate, RealType startT)
{
    m_yawInterpolation.AddInterpolation(interpolate, startT);
}

template<typename RealT>
NavCore::Math::Vector3Impl<RealT> OffsetCurveImpl<RealT>::evaluatePosition(RealType t) const
{
    NavCore::Math::Matrix34Impl<RealType> matrix = createFrame(t);

    RealType horizOffset = m_horizontalInterpolation.Solve(t);
    RealType vertOffset = m_verticalInterpolation.Solve(t);

    NavCore::Math::Vector3Impl<RealType> curveSpacePos(horizOffset, vertOffset, 0.0f);
    NavCore::Math::Vector3Impl<RealType> finalPos = matrix.Transform(curveSpacePos);
    return finalPos;
}

template<typename RealT>
NavCore::Math::Vector3Impl<RealT> OffsetCurveImpl<RealT>::evaluateTangent(RealType t) const
{
    return m_curve->evaluateTangent(t);
}

template<typename RealT>
CurveSampleImpl<RealT> OffsetCurveImpl<RealT>::evaluate(RealType t) const
{
    return CurveImpl<RealType>::evaluate(t);
}

template<typename RealT>
NavCore::Math::AlignedBox3Impl<RealT> OffsetCurveImpl<RealT>::computeBoundingBox() const
{
    return CurveImpl<RealType>::computeBoundingBox();
}

template<typename RealT>
std::vector<RealT> OffsetCurveImpl<RealT>::computeSampleValues(size_t sampleCount) const
{
    return CurveImpl<RealType>::computeSampleValues(sampleCount);
}

template<typename RealT>
std::vector<CurveSampleImpl<RealT>> OffsetCurveImpl<RealT>::computeSamplesAdaptive(
    const TessellationQualityImpl<RealType>& quality) const
{
    return CurveImpl<RealType>::computeSamplesAdaptive(quality);
}

template<typename RealT>
static NavCore::Math::Matrix34Impl<RealT> createFrameMatrix(const CurveSampleImpl<RealT>& sample,
    RealT roll,
    RealT yaw,
    const NavCore::Math::Vector3Impl<RealT>& upDirection)
{
    using RealType = RealT;

    NavCore::Math::Matrix34Impl<RealType> frameMatrix = sample.createFrame(upDirection);

    NavCore::Math::Matrix34Impl<RealType> rotZ;
    rotZ.MakeRotateZ(roll);
    rotZ.d.Zero();

    NavCore::Math::Matrix34Impl<RealType> rotY;
    rotY.MakeRotateY(yaw);
    rotY.d.Zero();

    NavCore::Math::Matrix34Impl<RealType> rotMatrix;
    rotMatrix.Dot(rotY, rotZ);

    NavCore::Math::Matrix34Impl<RealType> outMatrix;
    outMatrix.Dot(rotMatrix, frameMatrix);

    return outMatrix;
}

template<typename RealT>
NavCore::Math::Matrix34Impl<RealT> OffsetCurveImpl<RealT>::createFrame(RealType t) const
{
    CurveSampleImpl<RealType> sample = m_curve->evaluate(t);
    sample.normalizeTangent();
    return createFrame(sample);
}

template<typename RealT>
NavCore::Math::Matrix34Impl<RealT> OffsetCurveImpl<RealT>::createFrame(
    const CurveSampleImpl<RealType>& sample) const
{
    RealType roll = m_curveRoll.solve(sample.m_parameter);
    RealType yaw = m_yawInterpolation.Solve(sample.m_parameter);
    return createFrameMatrix(sample, roll, yaw, m_curveRoll.getUpDirection());
}

template class OffsetCurveImpl<float>;
template class OffsetCurveImpl<double>;

} // namespace curve
