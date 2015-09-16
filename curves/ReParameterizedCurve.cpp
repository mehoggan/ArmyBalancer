#include "curve/reparameterized/ReParameterizedCurve.h"

#include <NavCore/Math/Geometry/AlignedBox3.h>
#include "curve/core/CurveSample.h"
#include "curve/core/CurveNumeric.h"

namespace curve
{

template<typename RealT>
ReParameterizedCurveImpl<RealT>::ReParameterizedCurveImpl()
    : m_curve(nullptr)
    , m_parameterization(nullptr)
{
}

template<typename RealT>
typename ReParameterizedCurveImpl<RealT>::ConstCurvePtr ReParameterizedCurveImpl<RealT>::getCurve() const
{
    return m_curve;
}

template<typename RealT>
void ReParameterizedCurveImpl<RealT>::setCurve(ConstCurvePtr curve)
{
    m_curve = curve;
}

template<typename RealT>
typename ReParameterizedCurveImpl<RealT>::ParameterizationPtr ReParameterizedCurveImpl<RealT>::getParameterization() const
{
    return m_parameterization;
}

template<typename RealT>
void ReParameterizedCurveImpl<RealT>::setParameterization(ParameterizationPtr param)
{
    m_parameterization = param;
}

template<typename RealT>
typename ReParameterizedCurveImpl<RealT>::ReParameterizedCurvePtr ReParameterizedCurveImpl<RealT>::createArcLengthCurve(
    RealT& outLength,
    ConstCurvePtr curve,
    const ArcLengthReParameterizationQualityImpl<RealT>& quality)
{
    ReParameterizedCurvePtr repCurve = std::make_shared< ReParameterizedCurveImpl<RealT> >();
    std::shared_ptr<ParameterizationImpl<RealType>> param = std::make_shared< ParameterizationImpl<RealT> >();

    ArcLengthReParameterizationImpl<RealT> acRep(quality);
    outLength = acRep.run(*param, *curve);

    repCurve->setCurve(curve);
    repCurve->setParameterization(param);

    return repCurve;
}

template<typename RealT>
NavCore::Math::Vector3Impl<RealT> ReParameterizedCurveImpl<RealT>::evaluatePosition(RealType t) const
{
    RealType s = m_parameterization->evaluate(t);
    return m_curve->evaluatePosition(s);
}

template<typename RealT>
NavCore::Math::Vector3Impl<RealT> ReParameterizedCurveImpl<RealT>::evaluateTangent(RealType t) const
{
    RealType s = m_parameterization->evaluate(t);
    return m_curve->evaluateTangent(s);
}

template<typename RealT>
CurveSampleImpl<RealT> ReParameterizedCurveImpl<RealT>::evaluate(RealType t) const
{
    CurveSampleImpl<RealType> outSample;

    RealType s = m_parameterization->evaluate(t);
    outSample.m_position = m_curve->evaluatePosition(s);
    outSample.m_tangent = m_curve->evaluateTangent(s);
    outSample.m_parameter = t;

    return outSample;
}

template<typename RealT>
NavCore::Math::AlignedBox3Impl<RealT> ReParameterizedCurveImpl<RealT>::computeBoundingBox() const
{
    return m_curve->computeBoundingBox();
}

template<typename RealT>
std::vector<RealT> ReParameterizedCurveImpl<RealT>::computeSampleValues(size_t sampleCount) const
{
    std::vector<RealT> sampleValues;
    if (m_curve)
    {
        sampleValues = m_curve->computeSampleValues(sampleCount);
        for (auto& sample : sampleValues)
            sample = m_parameterization->evaluate(sample);
    }

    return sampleValues;
}

template<typename RealT>
std::vector<CurveSampleImpl<RealT>> ReParameterizedCurveImpl<RealT>::computeSamplesAdaptive(
    const TessellationQualityImpl<RealType>& quality) const
{
    std::vector<CurveSampleImpl<RealT>> sampleValues;
    if (m_curve)
    {
        sampleValues = m_curve->computeSamplesAdaptive(quality);
        for (auto& sample : sampleValues)
            sample.m_parameter = m_parameterization->evaluate(sample.m_parameter);
    }

    return sampleValues;
}

template class ReParameterizedCurveImpl<float>;
template class ReParameterizedCurveImpl<double>;

}  //namespace curve