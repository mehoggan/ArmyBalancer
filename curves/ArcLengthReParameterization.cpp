#include "curve/reparameterized/ArcLengthReParameterization.h"

#include "curve/core/Tessellator.h"

namespace curve
{

template<typename RealT>
ArcLengthReParameterizationImpl<RealT>::ArcLengthReParameterizationImpl(const ArcLengthReParameterizationQualityImpl<RealT>& quality)
    : m_quality(quality)
    , CurveSampleRefinerBaseImpl<RealT>(quality.getDistanceError())
{
}

template<typename RealT>
RealT ArcLengthReParameterizationImpl<RealT>::run(ParameterizationImpl<RealT>& outParam,
    const CurveImpl<RealT>& curve)
{
    NodeList nodes;

    nodes = CurveSampleRefinerBaseImpl<RealT>::run(curve);
    createParameterization(outParam, nodes);
    return getTotalLength(nodes);
}

template<typename RealT>
RealT ArcLengthReParameterizationImpl<RealT>::run(ParameterizationImpl<RealT>& outParam,
    const std::vector<CurveSampleImpl<RealT>>& curveSamples)
{
    const NodeList& nodes = CurveSampleRefinerBaseImpl<RealT>::run(curveSamples);
    createParameterization(outParam, nodes);
    return getTotalLength(nodes);
}

template<typename RealT>
void ArcLengthReParameterizationImpl<RealT>::computeValues()
{
    NodeList& nodes = getNodeList();
    NT_ASSERT(nodes.size() >= 2);

    SampleNode* prevNode = &nodes.front();
    prevNode->m_value = 0.0;

    RealType lengthAccum = 0;

    for (NodeIter iter(++nodes.begin()); iter != nodes.end(); ++iter)
    {
        SampleNode* node = &*iter;

        lengthAccum += node->m_pos.Distance(prevNode->m_pos);
        node->m_value = lengthAccum;

        prevNode = node;
    }
}

template<typename RealT>
bool ArcLengthReParameterizationImpl<RealT>::needRefinementAtMidPoint(
    const SampleNode& node0, const SampleNode& node1) const
{
    // Handle the case where two consecutive pieces of a multicurve have disjoint end points.
    if (NavCore::Math::FloatEquals(node0.m_t, node1.m_t))
        return false;

    const CurveImpl<RealType>* curve = getCurve();

    NavCore::Math::Vector3Impl<RealType> node0Pos = curve->evaluatePosition(node0.m_t);
    NavCore::Math::Vector3Impl<RealType> node1Pos = curve->evaluatePosition(node1.m_t);

    const RealType guessTotalLength = node1Pos.Distance(node0Pos);
    const RealType guessedMidPointLength = 0.5f * guessTotalLength;

    const RealType tVal = 0.5f*(node0.m_t + node1.m_t);
    NavCore::Math::Vector3Impl<RealType> midpointActualPos = curve->evaluatePosition(tVal);

    const RealType actualMidPointLengthFromNode0 = node0Pos.Distance(midpointActualPos);
    const RealType halfLengthError = fabs(actualMidPointLengthFromNode0 - guessedMidPointLength);

    // The half length error inserts node in case of the mid point length is not well estimated
    // by lerping the length of node0 and node1.
    return halfLengthError > getMaxError();
}

template<typename RealT>
void ArcLengthReParameterizationImpl<RealT>::createParameterization(
    ParameterizationImpl<RealT>& outParam,
    const NodeList& nodes)
{
    NT_ASSERT(nodes.size() >= 2);

    outParam.clear();

    const RealType totalLength = nodes.back().m_value;

    NodeConstIter node(++nodes.begin());
    NodeConstIter last(--nodes.end());

    outParam.addMapping(0, 0);
    while (node != last)
    {
        const RealType t = node->m_t;
        const RealType s = node->m_value / totalLength; // normalize the arc length parameter with the curve's total length
        outParam.addMapping(s, t);
        ++node;
    }
    outParam.addMapping(1, 1);

    outParam.makeValid();
}

template<typename RealT>
RealT ArcLengthReParameterizationImpl<RealT>::getTotalLength(const NodeList& nodes) const
{
    if (nodes.empty())
        return 0.0;

    return nodes.back().m_value;
}

template class ArcLengthReParameterizationImpl<float>;
template class ArcLengthReParameterizationImpl<double>;

}  // namespace curve