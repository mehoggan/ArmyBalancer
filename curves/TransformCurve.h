#pragma once

#include <vector>
#include "curve/core/Curve.h"
#include "curve/transform/TransformCurveDecl.h"
#include "NavCore/Math/Vector/Matrix34.h"

namespace curve
{

/**
 * @brief Wrapper curve that applies a matrix transform to the curve.
 */
template <typename RealT>
class CURVE_API TransformCurveImpl : public CurveImpl<RealT>
{
public:
    using RealType = RealT;
    using CurvePtr = std::shared_ptr<const CurveImpl<RealType>>;
    using Matrix34 = NavCore::Math::Matrix34Impl<RealType>;

    TransformCurveImpl() = default;
    TransformCurveImpl(const CurvePtr& curve, const Matrix34& transform);

    const CurvePtr& getCurve() const;
    void setCurve(const CurvePtr& curve);

    const Matrix34& getTransform() const;
    void setTransform(const Matrix34& transform);

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
    Matrix34 m_transform;
    Matrix34 m_transformInverseTranspose;
};

template <typename RealT>
inline TransformCurveImpl<RealT>::TransformCurveImpl(const CurvePtr& curve, const Matrix34& transform)
    : m_curve(curve)
    , m_transform(transform)
{
    m_transformInverseTranspose.Inverse(m_transform);
    m_transformInverseTranspose.Transpose();
}

template <typename RealT>
inline const typename TransformCurveImpl<RealT>::CurvePtr& TransformCurveImpl<RealT>::getCurve() const
{
    return m_curve;
}

template <typename RealT>
inline void TransformCurveImpl<RealT>::setCurve(const CurvePtr& curve)
{
    m_curve = curve;
}

template <typename RealT>
inline const typename TransformCurveImpl<RealT>::Matrix34& TransformCurveImpl<RealT>::getTransform() const
{
    return m_transform;
}

template <typename RealT>
inline void TransformCurveImpl<RealT>::setTransform(const Matrix34& transform)
{
    m_transform = transform;
    m_transformInverseTranspose.Inverse(m_transform);
    m_transformInverseTranspose.Transpose();
}

} // namespace curve
