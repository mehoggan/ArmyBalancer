#pragma once

#include <list>
#include <NavCore/Math/Vector/Vector3Decl.h>
#include "curve/core/Curve.h"
#include "curve/core/CurveSample.h"
#include "curve/core/CurveSampleRefinerBaseDecl.h"

namespace curve
{

/**
 * @brief Base class to compute or take a list of initial samples, refine the samples
 * by recursively inserting middle point samples, and reduce unneeded samples.
 */
template<typename RealT>
class CURVE_API CurveSampleRefinerBaseImpl
{
protected:
    using RealType = RealT;

    explicit CurveSampleRefinerBaseImpl(RealType maxError) : m_maxError(maxError)
    {}

    /**
    * @brief No deletion of any derived class via this base class handle. Do no expect use of this class
    * in a polymorphic way.
    */
    ~CurveSampleRefinerBaseImpl()
    {}

    struct SampleNode
    {
        SampleNode()
            : m_t(-1)
            , m_value(-1)
        {}

        RealType m_t;
        RealType m_value; // Currently float and double only, more refactoring needed if other types are needed.
        NavCore::Math::Vector3Impl<RealType> m_pos;
    };

    using NodeList = std::list<SampleNode>;
    using NodeIter =  typename NodeList::iterator;
    using NodeConstIter = typename NodeList::const_iterator;

    const NodeList run(const CurveImpl<RealType>& curve);
    const NodeList run(const std::vector<CurveSampleImpl<RealType>>& curveSamples);

    RealType getMaxError() const {return m_maxError;}
    const CurveImpl<RealType>* getCurve() const { return m_curve; }
    NodeList& getNodeList() {return m_nodes;}

private:
    struct Stats
    {
        Stats()
            : m_numInitialSamples(0)
            , m_numRefinedSamples(0)
            , m_numReducedSamples(0)
        {}

        size_t m_numInitialSamples;
        size_t m_numRefinedSamples;
        size_t m_numReducedSamples;
    };

    void reset();
    void sampleCurveInitial(std::vector<CurveSampleImpl<RealType>>& outSamples);
    void setInitialSamples(const std::vector<CurveSampleImpl<RealType>>& samples);
    void refineCurveSamples();
    void reduceSamples();
    void refineBeforeNode(const NodeIter& nodeIter, const size_t depth = 0);

    void subDivReduceSamples(
        NodeList& outNewNodeList, const NodeConstIter nodeFront, const NodeConstIter nodeBack) const;
    bool findSampleWithLargestExceedingError(
        NodeConstIter& outMaxErrorNode,
        const NodeConstIter nodeFront, const NodeConstIter nodeBack) const;

    /**
    * @brief Methods to override by derived classes.
    * Compute the m_value field in each node, called after sample refinement and before sample reduction.
    */
    virtual void computeValues() = 0;

    /**
    * @brief Given two nodes and determine whether a middle point needs to be inserted.
    */
    virtual bool needRefinementAtMidPoint(
        const SampleNode& node0, const SampleNode& node1) const = 0;

private:
    RealType m_maxError;
    NodeList m_nodes;
    const CurveImpl<RealType>* m_curve;
    Stats m_theStats;
};

} // namespace curve