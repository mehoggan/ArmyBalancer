#pragma once

#include <vector>
#include <NavCore/Math/Interpolate/InterpolationSequence.h>
#include "curve/core/Curve.h"
#include "curve/offset/CurveRoll.h"
#include "curve/offset/OffsetCurveDecl.h"

namespace curve
{

/**
 * @brief The offset curve evaluates an underlying curve and then applies several transformations
 * to the resulting sample so it is offset from the original curve.
 *
 * After the underlying curve is evaluated, a local frame is created using the sample's tangent
 * and the curve roll's 'up' vector. The following transforms are then applied, in order:
 * 1) A horizontal offset is applied along the frame's a vector
 * 2) A vertical offset is applied along the frame's b vector
 * 3) A roll rotation is applied about the frame's c vector
 * 4) A yaw rotation is applied about the frame's (rotated) b vector
 */
template<typename RealT>
class CURVE_API OffsetCurveImpl : public CurveImpl<RealT>
{
public:
    using RealType = RealT;
    using ConstCurvePtr = std::shared_ptr<const CurveImpl<RealType>>;

    explicit OffsetCurveImpl(ConstCurvePtr curve);

    void setUpDirection(const NavCore::Math::Vector3Impl<RealType>& upDirection);

    void addRollInterpolation(NavCore::Math::InterpolateImpl<RealType>& interpolate, RealType startT);

    void addHorizontalInterpolation(NavCore::Math::InterpolateImpl<RealType>& interpolate, RealType startT);

    void addVerticalInterpolation(NavCore::Math::InterpolateImpl<RealType>& interpolate, RealType startT);

    void addYawInterpolation(NavCore::Math::InterpolateImpl<RealType>& interpolate, RealType startT);

    virtual NavCore::Math::Vector3Impl<RealType> evaluatePosition(RealType t) const override;
    virtual NavCore::Math::Vector3Impl<RealType> evaluateTangent(RealType t) const override;
    virtual CurveSampleImpl<RealType> evaluate(RealType t) const override;

    virtual NavCore::Math::AlignedBox3Impl<RealType> computeBoundingBox() const override;

    virtual std::vector<RealType> computeSampleValues(size_t sampleCount = 2) const override;
    virtual std::vector<CurveSampleImpl<RealType>> computeSamplesAdaptive(
        const TessellationQualityImpl<RealType>& quality =
            TessellationQualityImpl<RealType>::cDefault) const override;

private:
    NavCore::Math::Matrix34Impl<RealType> createFrame(RealType t) const;
    NavCore::Math::Matrix34Impl<RealType> createFrame(const CurveSampleImpl<RealType>& sample) const;

    ConstCurvePtr m_curve;

    CurveRollImpl<RealType> m_curveRoll;

    NavCore::Math::InterpolationSequenceImpl<RealType> m_horizontalInterpolation;
    NavCore::Math::InterpolationSequenceImpl<RealType> m_verticalInterpolation;
    NavCore::Math::InterpolationSequenceImpl<RealType> m_yawInterpolation;
};


} // namespace curve
