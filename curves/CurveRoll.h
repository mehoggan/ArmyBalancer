#pragma once

#include <NavCore/Math/Vector/Matrix34Decl.h>
#include <NavCore/Math/Vector/Vector3.h>
#include <NavCore/Math/Interpolate/InterpolationSequence.h>
#include "curve/core/CurveSampleDecl.h"
#include "curve/offset/CurveRollDecl.h"

namespace curve
{

template<typename RealT>
class CURVE_API CurveRollImpl
{
public:
    using RealType = RealT;

    CurveRollImpl();

    NavCore::Math::InterpolationSequenceImpl<RealType>& getInterpolations();

    const NavCore::Math::Vector3Impl<RealType>& getUpDirection() const;
    void setUpDirection(const NavCore::Math::Vector3Impl<RealType>& upDirection);

    /**
     * @brief Returns the roll angle, in radians, at the given parameter.
     */
    RealType solve(RealType t) const;

    /**
     * @brief Returns the roll angle derivative at the given parameter.
     */
    RealType solveDerivative(RealType t) const;

    /**
     * @brief Computes rotation at t and rolls matrix about its c vector.
     * This assumes the matrix is orthogonal.
     */
    void applyRoll(NavCore::Math::Matrix34Impl<RealType>& matrix, RealType t) const;

    /**
     * @brief Creates a rolled matrix from a curve sample.
     */
    NavCore::Math::Matrix34Impl<RealType> createFrame(const CurveSampleImpl<RealType>& sample) const;

private:
    NavCore::Math::Vector3Impl<RealType> m_upDirection;
    NavCore::Math::InterpolationSequenceImpl<RealType> m_interpolations;
};

} // namespace curve
