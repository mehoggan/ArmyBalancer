#include <curve/partial/PartialCurve.h>
#include <curve/core/CurveNumeric.h>

#include <NavCore/Math/Geometry/AlignedBox3.h>

namespace curve
{

template<typename RealT>
PartialCurveImpl<RealT>::PartialCurveImpl(ConstCurvePtr curve, RealType startT, RealType endT)
    : m_curve(curve)
    , m_startT(startT)
    , m_endT(endT)
{
}

template<typename RealT>
NavCore::Math::Vector3Impl<RealT> PartialCurveImpl<RealT>::evaluatePosition(RealType t) const
{
    return m_curve->evaluatePosition(computeParameter(t));
}

template<typename RealT>
NavCore::Math::Vector3Impl<RealT> PartialCurveImpl<RealT>::evaluateTangent(RealType t) const
{
    return m_curve->evaluateTangent(computeParameter(t));
}

template<typename RealT>
CurveSampleImpl<RealT> PartialCurveImpl<RealT>::evaluate(RealType t) const
{
    CurveSampleImpl<RealT> sample = m_curve->evaluate(computeParameter(t));

    sample.m_parameter = t;

    return sample;
}

template<typename RealT>
NavCore::Math::AlignedBox3Impl<RealT> PartialCurveImpl<RealT>::computeBoundingBox() const
{
    return CurveNumericImpl<RealT>::computeBoundingBox(*this);
}

template<typename RealT>
std::vector<RealT> PartialCurveImpl<RealT>::computeSampleValues(size_t sampleCount) const
{
    return m_curve->computeSampleValues(sampleCount);
}

template<typename RealT>
std::vector<CurveSampleImpl<RealT>> PartialCurveImpl<RealT>::computeSamplesAdaptive(
    const TessellationQualityImpl<RealType>& quality) const
{
    return m_curve->computeSamplesAdaptive(quality);
}

template class PartialCurveImpl<float>;
template class PartialCurveImpl<double>;

} // namespace curve
