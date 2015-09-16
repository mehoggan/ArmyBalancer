#pragma once

#include "curve/core/Curve.h"
#include <curve/partial/PartialCurveDecl.h>

namespace curve
{

/**
 * @brief Specifies a curve that represents a bounded parameter range along another curve.
 */

template<typename RealT>
class CURVE_API PartialCurveImpl : public CurveImpl<RealT>
{
public:
    using RealType = RealT;
    using ConstCurvePtr = std::shared_ptr<const CurveImpl<RealType>>;

    PartialCurveImpl(ConstCurvePtr curve, RealType startT, RealType endT);

    virtual NavCore::Math::Vector3Impl<RealType> evaluatePosition(RealType t) const override;
    virtual NavCore::Math::Vector3Impl<RealType> evaluateTangent(RealType t) const override;
    virtual CurveSampleImpl<RealType> evaluate(RealType t) const override;

    virtual NavCore::Math::AlignedBox3Impl<RealType> computeBoundingBox() const override;

    virtual std::vector<RealType> computeSampleValues(size_t sampleCount = 2) const override;
    virtual std::vector<CurveSampleImpl<RealType>> computeSamplesAdaptive(
        const TessellationQualityImpl<RealType>& quality =
            TessellationQualityImpl<RealType>::cDefault) const override;

private:
    RealType computeParameter(RealType t) const { return NavCore::Math::Lerp(t, m_startT, m_endT); }

private:
    ConstCurvePtr m_curve;
    RealType m_startT;
    RealType m_endT;
};

} // namespace curve
