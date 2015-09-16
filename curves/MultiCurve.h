#pragma once

#include <vector>
#include "curve/core/Curve.h"
#include "curve/multi/MultiCurveDecl.h"

namespace curve
{

/**
 * @brief Wraps a sequence of curves.
 * Each value in the parameter space maps to specific curves. The parameter space is evenly
 * distributed among the curves, regardless of length. It is generally expected, but not required,
 * that there are no geometric discontinuities between curves. There is no special handling of
 * tangents between curves. Where curves meet, there can be a C1 or C2 discontinuity.
 */
template<typename RealT>
class CURVE_API MultiCurveImpl : public CurveImpl<RealT>
{
public:
    using RealType = RealT;
    using ConstCurvePtr = std::shared_ptr<const CurveImpl<RealType>>;

    MultiCurveImpl();

    /**
     * @brief Removes all curves from the contained curves
     */
    void clear();

    /**
     * @brief Appends a curve to the list of contained curves.
     */
    void addCurve(ConstCurvePtr curve);

    /**
     * @brief Gets the number of contained curves in this multi-curve.
     */
    size_t getCurveCount() const;

    /**
     * @brief Gets the contained curve with the specified index.
     * @param index The index of the contained curve.
     * @return The contained curve.
     */
    ConstCurvePtr getCurve(size_t index) const;

    /**
     * @brief Gets the contained curve corresponding to the specified multi-curve parameter.
     * @param t The multi-curve parameter.
     * @return The corresponding contained curve.
     */
    ConstCurvePtr getCurveFromParameter(RealType t) const;

    /**
     * @brief Gets the index of the contained curve corresponding the the specified multi-curve
     * parameter.
     * @param t The multi-curve parameter.
     * @return The corresponding parameter along the contained curve.
     */
    size_t getCurveIndexFromParameter(RealType t) const;

    /**
     * @brief Gets the multi-curve parameter given a parameter and curve index of a contained curve.
     * @param t The contained curve parameter.
     * @param curveIndex The contained curve index.
     * @return The multi-curve parameter.
     */
    RealType getMultiCurveParameter(RealType t, size_t curveIndex) const;

    /**
     * @brief Gets a contained curve parameter given the multi-curve parameter.
     * @param t The multi-curve parameter.
     * @return The contained curve parameter.
     */
    RealType getCurveParameter(RealType t) const;

    virtual NavCore::Math::Vector3Impl<RealType> evaluatePosition(RealType t) const override;
    virtual NavCore::Math::Vector3Impl<RealType> evaluateTangent(RealType t) const override;
    virtual CurveSampleImpl<RealType> evaluate(RealType t) const override;

    virtual NavCore::Math::AlignedBox3Impl<RealType> computeBoundingBox() const override;

    virtual std::vector<RealType> computeSampleValues(size_t sampleCount = 2) const override;
    virtual std::vector<CurveSampleImpl<RealType>> computeSamplesAdaptive(
        const TessellationQualityImpl<RealType>& quality =
            TessellationQualityImpl<RealType>::cDefault) const override;

private:
    std::vector<ConstCurvePtr> m_curves;
};


} // namespace curve
