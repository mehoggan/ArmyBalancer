#include "curve/offset/CurveRoll.h"
#include <NavCore/Math/Vector/Matrix34.h>
#include "curve/core/CurveSample.h"


namespace curve
{

template<typename RealT>
CurveRollImpl<RealT>::CurveRollImpl()
    : m_upDirection(NavCore::Math::Vector3Impl<RealType>::cZAxis)
{
}

template<typename RealT>
NavCore::Math::InterpolationSequenceImpl<RealT>& CurveRollImpl<RealT>::getInterpolations()
{
    return m_interpolations;
}

template<typename RealT>
const NavCore::Math::Vector3Impl<RealT>& CurveRollImpl<RealT>::getUpDirection() const
{
    return m_upDirection;
}

template<typename RealT>
void CurveRollImpl<RealT>::setUpDirection(const NavCore::Math::Vector3Impl<RealType>& upDirection)
{
    m_upDirection = upDirection;
    m_upDirection.SafeNormalize(NavCore::Math::Vector3Impl<RealType>::cZAxis);
}

template<typename RealT>
RealT CurveRollImpl<RealT>::solve(RealType t) const
{
    return m_interpolations.Solve(t);
}

template<typename RealT>
RealT CurveRollImpl<RealT>::solveDerivative(RealType t) const
{
    return m_interpolations.SolveDerivative(t);
}

template<typename RealT>
void CurveRollImpl<RealT>::applyRoll(NavCore::Math::Matrix34Impl<RealType>& matrix, RealType t) const
{
    if (m_interpolations.GetInterpolations().empty())
        return;

    RealType roll = m_interpolations.Solve(t);
    NavCore::Math::Vector3Impl<RealType> b0(matrix.a);
    NavCore::Math::Vector3Impl<RealType> b1(matrix.b);

    RealType sinTh = std::sin(roll);
    RealType cosTh = std::cos(roll);

    matrix.a.Scale(b0, cosTh);
    matrix.a.AddScaled(b1, sinTh);

    matrix.b.Scale(b0, -sinTh);
    matrix.b.AddScaled(b1, cosTh);
}

template<typename RealT>
NavCore::Math::Matrix34Impl<RealT> CurveRollImpl<RealT>::createFrame(
    const CurveSampleImpl<RealType>& sample) const
{
    NavCore::Math::Matrix34Impl<RealType> outMatrix = sample.createFrame(m_upDirection);
    applyRoll(outMatrix, sample.m_parameter);
    return outMatrix;
}

template class CurveRollImpl<float>;
template class CurveRollImpl<double>;

} // namespace curve
