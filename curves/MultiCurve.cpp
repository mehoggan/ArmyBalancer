#include "curve/multi/MultiCurve.h"

#include <NavCore/Math/Geometry/AlignedBox3.h>
#include "curve/core/CurveOps.h"

#include <iterator>

namespace curve
{

template <typename RealT>
static bool pointsEqual(const NavCore::Math::Vector3Impl<RealT>& p0,
    const NavCore::Math::Vector3Impl<RealT>& p1)
{
    RealT maxValue = std::abs(p0.x);
    maxValue = std::max(maxValue, std::abs(p0.y));
    maxValue = std::max(maxValue, std::abs(p0.z));
    maxValue = std::max(maxValue, std::abs(p1.x));
    maxValue = std::max(maxValue, std::abs(p1.y));
    maxValue = std::max(maxValue, std::abs(p1.z));
    RealT epsilon = NavCore::Math::ComputeDynamicEpsilon(maxValue);
    return NavCore::Math::FloatEquals(p0, p1, epsilon);
}

template<typename RealT>
MultiCurveImpl<RealT>::MultiCurveImpl()
{
}

template<typename RealT>
void MultiCurveImpl<RealT>::clear()
{
    m_curves.clear();
}


template<typename RealT>
void MultiCurveImpl<RealT>::addCurve(ConstCurvePtr curve)
{
    m_curves.push_back(curve);
}


template<typename RealT>
size_t MultiCurveImpl<RealT>::getCurveCount() const
{
    return m_curves.size();
}


template<typename RealT>
typename MultiCurveImpl<RealT>::ConstCurvePtr MultiCurveImpl<RealT>::getCurve(size_t index) const
{
    NT_ASSERT(index < m_curves.size());
    return m_curves[index];
}


template<typename RealT>
typename MultiCurveImpl<RealT>::ConstCurvePtr
MultiCurveImpl<RealT>::getCurveFromParameter(RealType t) const
{
    size_t index = getCurveIndexFromParameter(t);
    return m_curves[index];
}


template<typename RealT>
size_t MultiCurveImpl<RealT>::getCurveIndexFromParameter(RealType t) const
{
    NT_ASSERT(t >= 0.0f && t <= 1.0f);
    size_t index = NavCore::Math::Clamp(
        static_cast<size_t>(std::floor(t * m_curves.size())),
        static_cast<size_t>(0),
        static_cast<size_t>(m_curves.size() - 1));

    return index;
}


template<typename RealT>
RealT MultiCurveImpl<RealT>::getMultiCurveParameter(RealType t, size_t curveIndex) const
{
    NT_ASSERT(!m_curves.empty());
    RealType deltaT = 1.0f / static_cast<RealType>(m_curves.size());
    RealType multiT = NavCore::Math::Lerp(t, curveIndex * deltaT, (curveIndex + 1) * deltaT);
    return NavCore::Math::Clamp(multiT, static_cast<RealType>(0.0), static_cast<RealType>(1.0));
}


template<typename RealT>
RealT MultiCurveImpl<RealT>::getCurveParameter(RealType t) const
{
    NT_ASSERT(!m_curves.empty());
    NT_ASSERT(t >= 0.0f && t <= 1.0f);
    size_t index = getCurveIndexFromParameter(t);
    RealType curveT = t * m_curves.size() - index;
    return NavCore::Math::Clamp(curveT, static_cast<RealType>(0.0), static_cast<RealType>(1.0));
}

template<typename RealT>
NavCore::Math::Vector3Impl<RealT> MultiCurveImpl<RealT>::evaluatePosition(RealType t) const
{
    ConstCurvePtr curve = getCurveFromParameter(t);
    RealType curveT = getCurveParameter(t);
    return curve->evaluatePosition(curveT);
}

template<typename RealT>
NavCore::Math::Vector3Impl<RealT> MultiCurveImpl<RealT>::evaluateTangent(RealType t) const
{
    ConstCurvePtr curve = getCurveFromParameter(t);
    RealType curveT = getCurveParameter(t);
    return curve->evaluateTangent(curveT);
}

template<typename RealT>
CurveSampleImpl<RealT> MultiCurveImpl<RealT>::evaluate(RealType t) const
{
    CurveSampleImpl<RealType> outSample;

    ConstCurvePtr curve = getCurveFromParameter(t);
    RealType curveT = getCurveParameter(t);
    outSample.m_position = curve->evaluatePosition(curveT);
    outSample.m_tangent = curve->evaluateTangent(curveT);
    outSample.m_parameter = t;

    return outSample;
}

template<typename RealT>
NavCore::Math::AlignedBox3Impl<RealT> MultiCurveImpl<RealT>::computeBoundingBox() const
{
    NavCore::Math::AlignedBox3Impl<RealType> outBox;
    outBox.Invalidate();
    for (ConstCurvePtr curve : m_curves)
        outBox.GrowToContain(curve->computeBoundingBox());

    return outBox;
}

template<typename RealT>
std::vector<RealT> MultiCurveImpl<RealT>::computeSampleValues(size_t sampleCount) const
{
    std::vector<RealType> outSamples;
    for (size_t iCurve = 0; iCurve < m_curves.size(); ++iCurve)
    {
        ConstCurvePtr curve = m_curves[iCurve];
        std::vector<RealType> curveSamples = curve->computeSampleValues(sampleCount);
        CurveOpsImpl<RealType>::enforceMinimumSampleCount(curveSamples, sampleCount);

        for (size_t iSample = 0; iSample < curveSamples.size(); ++iSample)
        {
            RealType t = getMultiCurveParameter(curveSamples[iSample], iCurve);

            // Remove last sample if it's the same as the first sample of the next curve.
            // Otherwise, subtract epsilon from the T value so evalueate() picks the correct curve.
            if (iCurve != 0 && iSample == 0 && outSamples.size() > 0)
            {
                auto p0 = m_curves[iCurve - 1]->evaluatePosition(getCurveParameter(outSamples.back()));
                auto p1 = curve->evaluatePosition(curveSamples[iSample]);

                if (pointsEqual(p0, p1))
                    outSamples.pop_back();
                else
                    outSamples.back() -= NavCore::Math::FConstsImpl<RealType>::cEpsilon;
            }

            outSamples.push_back(t);
        }
    }
    return outSamples;
}

template<typename RealT>
std::vector<CurveSampleImpl<RealT>> MultiCurveImpl<RealT>::computeSamplesAdaptive(
    const TessellationQualityImpl<RealType>& quality) const
{
    std::vector<CurveSampleImpl<RealType>> outSamples;

    // We need to do two things here to produce an actual "multi" curve:
    // 1. We need to adjust the parameters down based on the number of curves present in the multi-
    //    curve.
    // 2. We also need to make sure that we do not have any duplicate begin and end point within
    //    some epsilon
    RealType ratio = 1.0f / m_curves.size();
    for (size_t iCurve = 0; iCurve < m_curves.size(); ++iCurve)
    {
        // Scale down curve[i]'s scale value.
        ConstCurvePtr curvei = m_curves[iCurve];
        std::vector<CurveSampleImpl<RealType>> curveSamplesi =
            curvei->computeSamplesAdaptive(quality);
        for (size_t iSample = 0; iSample < curveSamplesi.size(); ++iSample)
        {
            curveSamplesi[iSample].m_parameter = NavCore::Math::Clamp(iCurve * ratio +
                ratio * curveSamplesi[iSample].m_parameter, RealType(0), RealType(1));
        }

        // If the last out position is the same as the new samples begin position remove the
        // the last position. If we don't need to remove the last sample, then subtract epsilon
        // from the T value so evaluate() chooses the correct curve.
        if (!outSamples.empty())
        {
            if (pointsEqual(outSamples.back().m_position, curveSamplesi.front().m_position))
                outSamples.pop_back();
            else
                outSamples.back().m_parameter -= NavCore::Math::FConstsImpl<RealType>::cEpsilon;
        }

        std::copy(curveSamplesi.begin(), curveSamplesi.end(), std::back_inserter(outSamples));
    }


    return outSamples;
}


template class MultiCurveImpl<float>;
template class MultiCurveImpl<double>;

} // namespace curve
