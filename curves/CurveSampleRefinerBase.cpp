#include "curve/core/CurveSampleRefinerBase.h"

#include "curve/multi/MultiCurve.h"
#include "curve/core/Tessellator.h"
#include <iterator>

namespace curve
{

template<typename RealT>
void CurveSampleRefinerBaseImpl<RealT>::sampleCurveInitial(
    std::vector<CurveSampleImpl<RealT>>& outSamples)
{
    TessellationQualityImpl<RealT> quality;
    quality.m_chordalTolerance = 0.0005f;

    outSamples = m_curve->computeSamplesAdaptive(quality);
}

template<typename RealT>
void CurveSampleRefinerBaseImpl<RealT>::setInitialSamples(const std::vector<CurveSampleImpl<RealT>>& samples)
{
    for (size_t i = 0; i < samples.size(); ++i)
    {
        SampleNode node;
        node.m_t = samples[i].m_parameter;
        node.m_pos = samples[i].m_position;
        m_nodes.push_back(node);
    }

    m_theStats.m_numInitialSamples = samples.size();
}

template<typename RealT>
void CurveSampleRefinerBaseImpl<RealT>::refineCurveSamples()
{
    NT_ASSERT(m_nodes.size() >= 2);

    for (NodeIter iter = std::next(m_nodes.begin()); iter != m_nodes.end(); ++iter)
    {
        refineBeforeNode(iter);
    }
}

template<typename RealT>
void CurveSampleRefinerBaseImpl<RealT>::refineBeforeNode(
    const NodeIter& nodeIter,
    const size_t depth)
{
    const size_t cMaximumDepth = 6; // The maximum recursion depth
    if (depth > cMaximumDepth)
        return;

    NT_ASSERT(nodeIter != m_nodes.begin());
    NodeIter prevIter(std::prev(nodeIter));

    SampleNode& node0 = *prevIter;
    SampleNode& node1 = *nodeIter;

    NT_ASSERT(node0.m_t < node1.m_t);

    const CurveImpl<RealType>* curve = m_curve;

    // TODO: refinement at mid point is sometimes similar to reduction given 3 points (with
    // the middle point pre-calculated).  Look into combining these two methods into one.
    if (needRefinementAtMidPoint(node0, node1))
    {
        SampleNode newNode;
        m_theStats.m_numRefinedSamples++;

        newNode.m_t = (node1.m_t + node0.m_t) * 0.5f;
        newNode.m_pos = curve->evaluatePosition(newNode.m_t);

        NodeIter newIter = m_nodes.insert(nodeIter, newNode);

        refineBeforeNode(newIter, depth + 1);
        refineBeforeNode(nodeIter, depth + 1);
    }
}

template<typename RealT>
const typename CurveSampleRefinerBaseImpl<RealT>::NodeList CurveSampleRefinerBaseImpl<RealT>::run(const CurveImpl<RealT>& curve)
{
    reset();

    m_curve = &curve;
    NodeList nodes;

    std::vector<CurveSampleImpl<RealT>> curveSamples;
    sampleCurveInitial(curveSamples);
    setInitialSamples(curveSamples);
    refineCurveSamples();
    computeValues();
    reduceSamples();
    nodes = m_nodes;

    reset();
    return nodes;
}

template<typename RealT>
const typename CurveSampleRefinerBaseImpl<RealT>::NodeList CurveSampleRefinerBaseImpl<RealT>::run(
    const std::vector<CurveSampleImpl<RealT>>& curveSamples)
{
    setInitialSamples(curveSamples);
    computeValues();
    reduceSamples();

    NodeList nodes = m_nodes;
    reset();
    return nodes;
}

template<typename RealT>
void CurveSampleRefinerBaseImpl<RealT>::reduceSamples()
{
    NT_ASSERT(m_nodes.size() >= 2);

    NodeList reducedNodeList;
    subDivReduceSamples(reducedNodeList, m_nodes.begin(), std::prev(m_nodes.end()));

    // We are always keeping the start and end points.
    reducedNodeList.push_front(m_nodes.front());
    reducedNodeList.push_back(m_nodes.back());

    m_nodes = reducedNodeList;
}

template<typename RealT>
void CurveSampleRefinerBaseImpl<RealT>::reset()
{
    m_nodes.clear();
    m_theStats = Stats();
    m_curve = nullptr;
}

template<typename RealT>
void CurveSampleRefinerBaseImpl<RealT>::subDivReduceSamples(
    NodeList& outNewNodeList, const NodeConstIter nodeFront, const NodeConstIter nodeBack) const
{
    // Find the sample with the largest error exceeding the max error.
    // If such sample is found, insert it into the final list to keep it, and divide the list into
    // two pieces using that sample.
    // If no such sample is found, then we can safely remove all points within that subdivision.
    NodeConstIter maxErrorNode;
    const bool foundSampleExceedingMaxError =
        findSampleWithLargestExceedingError(maxErrorNode, nodeFront, nodeBack);
    if (foundSampleExceedingMaxError)
    {
        // Further subdividing needed since one or more node exceeding the max interpolation error
        subDivReduceSamples(outNewNodeList, nodeFront, maxErrorNode);
        outNewNodeList.push_back(*maxErrorNode); // Retain the sample with max error
        subDivReduceSamples(outNewNodeList, maxErrorNode, nodeBack);
    }

    // Else, we can safely remove all nodes. Done.
}

template<typename RealT>
bool CurveSampleRefinerBaseImpl<RealT>::findSampleWithLargestExceedingError(
    NodeConstIter& outMaxErrorNode,
    const NodeConstIter nodeFront,
    const NodeConstIter nodeBack) const
{
    if (nodeFront == nodeBack || std::next(nodeFront) == nodeBack)
        return false;

    const SampleNode& node0 = *nodeFront;
    NodeConstIter node1 = std::next(nodeFront);
    const SampleNode& node2 = *nodeBack;
    bool foundSampleExceedngError = false;

    const RealType denom = node2.m_t - node0.m_t;
    const bool denomIsZero = NavCore::Math::FloatEqualsZero(denom);
    RealType maxSampleError = 0.0;

    while (node1 != nodeBack)
    {
        const RealType lerp = denomIsZero ? 0.0f : ((*node1).m_t - node0.m_t) / denom;

        const RealType valueInterpolated = NavCore::Math::Lerp(lerp, node0.m_value, node2.m_value);
        const RealType valueActual = (*node1).m_value;

        // Reduce the error by a bit to make reduction a bit harder than refinement
        const RealType reductionError = m_maxError * 0.9f;
        const RealType sampleError = fabs(valueInterpolated - valueActual);
        if (sampleError > reductionError && sampleError > maxSampleError)
        {
            // Found a sample that cannot be reduced, and it is so far the largest error.
            maxSampleError = sampleError;
            outMaxErrorNode = node1;
            foundSampleExceedngError = true;
        }

        node1++;
    }

    return foundSampleExceedngError;
}

template class CurveSampleRefinerBaseImpl<float>;
template class CurveSampleRefinerBaseImpl<double>;

}  // namespace curve