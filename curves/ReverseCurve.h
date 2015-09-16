#pragma once

#include <vector>
#include "curve/core/Curve.h"
#include "curve/reverse/ReverseCurveDecl.h"

namespace curve
{

/**
 * @brief Wrapper curve that reverses a curve's direction.
 */
template <typename RealT>
class CURVE_API ReverseCurveImpl : public CurveImpl<RealT>
{
public:
    using RealType = RealT;
    using CurvePtr = std::shared_ptr<const CurveImpl<RealType>>;

    ReverseCurveImpl() = default;
    explicit ReverseCurveImpl(const CurvePtr& curve);

    const CurvePtr& getCurve() const;
    void setCurve(const CurvePtr& curve);

    virtual NavCore::Math::Vector3Impl<RealType> evaluatePosition(RealType t) const override;
    virtual NavCore::Math::Vector3Impl<RealType> evaluateTangent(RealType t) const override;
    virtual CurveSampleImpl<RealType> evaluate(RealType t) const override;

    virtual NavCore::Math::AlignedBox3Impl<RealType> computeBoundingBox() const override;

    virtual std::vector<RealType> computeSampleValues(size_t sampleCount) const override;
    virtual std::vector<CurveSampleImpl<RealType>> computeSamplesAdaptive(
        const TessellationQualityImpl<RealType>& quality =
            TessellationQualityImpl<RealType>::cDefault) const override;

private:
    CurvePtr m_curve;
};

template<typename RealT>
inline ReverseCurveImpl<RealT>::ReverseCurveImpl(const CurvePtr& curve)
    : m_curve(curve)
{}

template<typename RealT>
inline const typename ReverseCurveImpl<RealT>::CurvePtr& ReverseCurveImpl<RealT>::getCurve() const
{
    return m_curve;
}

template<typename RealT>
inline void ReverseCurveImpl<RealT>::setCurve(const CurvePtr& curve)
{
    m_curve = curve;
}

} // namespace curve
