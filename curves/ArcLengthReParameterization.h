#pragma once

#include <NavCore/Math/Vector/Vector3Decl.h>
#include "curve/core/Curve.h"
#include "curve/core/CurveSample.h"
#include "curve/core/CurveSampleRefinerBase.h"
#include "curve/reparameterized/Parameterization.h"
#include "curve/reparameterized/ArcLengthReParameterizationDecl.h"

namespace curve
{

/**
 * @brief Quality settings for the ArcLengthReParameterizationImpl.
 */
template<typename RealT>
class CURVE_API ArcLengthReParameterizationQualityImpl
{
public:
    using RealType = RealT;

    ArcLengthReParameterizationQualityImpl()
        : m_distanceError(0.01f)
    {}

    /**
    * @brief Maximum allowable error between estimated and actual midpoint values.
    */
    void setDistanceError(RealType val) { m_distanceError = val; }
    RealType getDistanceError() const { return m_distanceError; }

private:
    RealType m_distanceError;
};

/**
* @brief Creates an arc-length parameterization from a CurveType or vector of curve samples.
*   -Both 't' and 's' span [0,1]
*   -Enforces that first mapping is (0,0) and samples are monotonically-increasing in t and s
*   -Last mapping must be (1,1)
*/
template<typename RealT>
class CURVE_API ArcLengthReParameterizationImpl : private CurveSampleRefinerBaseImpl<RealT>
{
public:
    using RealType = RealT;

    /**
    * @brief Creates a new empty arc length parameterization (parameter value is proportional to the distance
    * along the curve.
    */
    explicit ArcLengthReParameterizationImpl(const ArcLengthReParameterizationQualityImpl<RealType>& quality =
        TessellationQualityImpl<RealType>::cDefault);

    struct MappingPoint
    {
        MappingPoint()
            : m_t(-1)
            , m_s(-1)
        {}

        MappingPoint(RealType t, RealType s, const NavCore::Math::Vector3Impl<RealType>& pos)
            : m_t(t)
            , m_s(s)
            , m_pos(pos)
        {}

        RealType m_t;
        RealType m_s;
        NavCore::Math::Vector3Impl<RealType> m_pos;
    };

    using MappingPointList = std::list<MappingPoint>;
    using MappingPointIter = typename MappingPointList::iterator;
    using MappingPointConstIter = typename MappingPointList::const_iterator;

    using SampleNode = typename CurveSampleRefinerBaseImpl<RealType>::SampleNode;
    using NodeList = typename CurveSampleRefinerBaseImpl<RealType>::NodeList;
    using NodeIter =  typename NodeList::iterator;
    using NodeConstIter = typename NodeList::const_iterator;

    /**
    * @brief Computes arc-length parameterization of curve, treating the adaptive tessellation of
    * curve as the 'ground truth' curve.
    * Returns he length of the curve.
    */
    RealType run(ParameterizationImpl<RealType>& outParam, const CurveImpl<RealType>& curve);

    /**
    * @brief Computes arc-length parameterization of the given curve samples, treating the samples
    * as the 'ground truth' curve.
    * Returns he length of the curve.
    */
    RealType run(ParameterizationImpl<RealType>& outParam, const std::vector<CurveSampleImpl<RealType>>& curveSamples);

    using CurveSampleRefinerBaseImpl<RealT>::getMaxError;
    using CurveSampleRefinerBaseImpl<RealT>::getCurve;
    using CurveSampleRefinerBaseImpl<RealT>::getNodeList;

private:
    void createParameterization(
        ParameterizationImpl<RealType>& outParam,
        const NodeList& nodes);

    RealType getTotalLength(const typename CurveSampleRefinerBaseImpl<RealType>::NodeList& nodes) const;

    virtual void computeValues() override;
    virtual bool needRefinementAtMidPoint(
        const SampleNode& node0, const SampleNode& node1) const override;

    ArcLengthReParameterizationQualityImpl<RealType> m_quality;
};

} // namespace curve
