#pragma once

#include <vector>
#include "curve/core/Curve.h"
#include "curve/reparameterized/Parameterization.h"
#include "curve/reparameterized/ArcLengthReParameterization.h"
#include "curve/reparameterized/ReParameterizedCurveDecl.h"

namespace curve
{

/**
* @brief Allows reparameterization of a curve by wrapping a curve and using a parameterization map
* to serve as an intermediary. See Parameterization.h for constraints on parameterization.
* To use, create an empty class, a curve (to be reparameterized), and a Parameterization.
* Use the set accessors to assign the curve and the parameterization.
*/
template<typename RealT>
class CURVE_API ReParameterizedCurveImpl : public CurveImpl<RealT>
{
public:
    using RealType = RealT;
    using ConstCurvePtr = std::shared_ptr<const CurveImpl<RealType>>;
    using ParameterizationPtr = std::shared_ptr<ParameterizationImpl<RealType>>;
    using ReParameterizedCurvePtr = std::shared_ptr<ReParameterizedCurveImpl<RealType>>;

    ReParameterizedCurveImpl();

    /**
    * @brief Gets the curve to be reparameterized.
    */
    ConstCurvePtr getCurve() const;

    /**
    * @brief Sets the curve to be reparameterized.
    */
    void setCurve(ConstCurvePtr curve);

    /**
    * @brief Gets the current parameterization.
    */
    ParameterizationPtr getParameterization() const;

    /**
    * @brief Sets the curve to be reparameterized.
    */
    void setParameterization(ParameterizationPtr param);

    /**
    * @brief Creates arc length curve from input curve.
    * @param outLength Length of the curve (m).
    * @param curve The curve to reparameterize.
    * @param quality Input quality.
    */
    static ReParameterizedCurvePtr createArcLengthCurve(
        RealType& outLength,
        ConstCurvePtr curve,
        const ArcLengthReParameterizationQualityImpl<RealT>& quality = ArcLengthReParameterizationQualityImpl<RealT>());

    virtual NavCore::Math::Vector3Impl<RealType> evaluatePosition(RealType t) const override;
    virtual NavCore::Math::Vector3Impl<RealType> evaluateTangent(RealType t) const override;
    virtual CurveSampleImpl<RealType> evaluate(RealType t) const override;

    virtual NavCore::Math::AlignedBox3Impl<RealType> computeBoundingBox() const override;

    virtual std::vector<RealType> computeSampleValues(size_t sampleCount = 2) const override;
    virtual std::vector<CurveSampleImpl<RealType>> computeSamplesAdaptive(
        const TessellationQualityImpl<RealType>& quality =
        TessellationQualityImpl<RealType>::cDefault) const override;

private:
    ConstCurvePtr m_curve;
    ParameterizationPtr m_parameterization;
};

} // namespace curve