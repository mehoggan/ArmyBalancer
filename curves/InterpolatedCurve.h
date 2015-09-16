#pragma once

#include "curve/core/Curve.h"
#include "curve/interpolated/InterpolatedCurveDecl.h"

namespace curve
{

/**
 * @brief Curve that interpolates between two input curves.
 *
 */
template <typename RealT>
class CURVE_API InterpolatedCurveImpl : public CurveImpl<RealT>
{
public:
    using RealType = RealT;
    using CurvePtr = std::shared_ptr<const CurveImpl<RealType>>;

    InterpolatedCurveImpl() = default;
    InterpolatedCurveImpl(const CurvePtr& curve0, const CurvePtr& curve1,
        RealType t0, RealType t1);

    const CurvePtr& getCurve0() const;
    void setCurve0(const CurvePtr& curve0);
    const CurvePtr& getCurve1() const;
    void setCurve1(const CurvePtr& curve1);

    const RealType& getT0() const;
    void setT0(const RealType& t0);
    const RealType& getT1() const;
    void setT1(const RealType& t1);

    virtual NavCore::Math::Vector3Impl<RealType> evaluatePosition(RealType t) const override;
    virtual NavCore::Math::Vector3Impl<RealType> evaluateTangent(RealType t) const override;
    virtual CurveSampleImpl<RealType> evaluate(RealType t) const override;

    virtual NavCore::Math::AlignedBox3Impl<RealType> computeBoundingBox() const override;

    virtual std::vector<RealType> computeSampleValues(size_t sampleCount) const override;
    virtual std::vector<CurveSampleImpl<RealType>> computeSamplesAdaptive(
        const TessellationQualityImpl<RealType>& quality =
            TessellationQualityImpl<RealType>::cDefault) const override;

private:
    void interpolateTs(RealType& outTInterpolate, RealType& outTEvaluate, const RealType& t) const;

private:
    CurvePtr m_curve0;
    CurvePtr m_curve1;
    RealT m_T0;
    RealT m_T1;
};

template <typename RealT>
inline InterpolatedCurveImpl<RealT>::InterpolatedCurveImpl(const CurvePtr& curve0, const CurvePtr& curve1,
    RealType t0, RealType t1)
    : m_curve0(curve0)
    , m_curve1(curve1)
    , m_T0(t0)
    , m_T1(t1)
{}

template <typename RealT>
inline const typename InterpolatedCurveImpl<RealT>::CurvePtr& InterpolatedCurveImpl<RealT>::getCurve0() const
{
    return m_curve0;
}

template <typename RealT>
inline void InterpolatedCurveImpl<RealT>::setCurve0(const CurvePtr& curve0)
{
    m_curve0 = curve0;
}

template <typename RealT>
inline const typename InterpolatedCurveImpl<RealT>::CurvePtr& InterpolatedCurveImpl<RealT>::getCurve1() const
{
    return m_curve1;
}

template <typename RealT>
inline void InterpolatedCurveImpl<RealT>::setCurve1(const CurvePtr& curve1)
{
    m_curve1 = curve1;
}

template <typename RealT>
inline const RealT& InterpolatedCurveImpl<RealT>::getT0() const
{
    return m_T0;
}

template <typename RealT>
inline void InterpolatedCurveImpl<RealT>::setT0(const RealType& t0)
{
    m_T0 = t0;
}

template <typename RealT>
inline const RealT& InterpolatedCurveImpl<RealT>::getT1() const
{
    return m_T1;
}

template <typename RealT>
inline void InterpolatedCurveImpl<RealT>::setT1(const RealType& t1)
{
    m_T1 = t1;
}

} // namespace curve
