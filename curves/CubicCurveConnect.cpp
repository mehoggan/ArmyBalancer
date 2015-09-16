#include "curve/cubic/CubicCurveConnect.h"
#include "curve/core/Curve.h"
#include "curve/cubic/CubicCurve.h"

namespace curve
{

template<typename RealT>
void CubicCurveConnectImpl<RealT>::connect(CubicCurveImpl<RealType>& outCurve,
    const CurveImpl<RealType>& curve1, const CurveImpl<RealType>& curve2,
    RealType tangentScale1, RealType tangentScale2)
{
    connect(outCurve, curve1, 1, curve2, 0, tangentScale1, tangentScale2);
}

template<typename RealT>
void CubicCurveConnectImpl<RealT>::connect(CubicCurveImpl<RealType>& outCurve,
    const CurveImpl<RealType>& curve1, RealType curve1T,
    const CurveImpl<RealType>& curve2, RealType curve2T,
    RealType tangentScale1, RealType tangentScale2)
{
    NavCore::Math::Vector3Impl<RealType> startPosition = curve1.evaluatePosition(curve1T);
    NavCore::Math::Vector3Impl<RealType> endPosition = curve2.evaluatePosition(curve2T);
    NavCore::Math::Vector3Impl<RealType> startTangent = curve1.evaluateTangent(curve1T);
    NavCore::Math::Vector3Impl<RealType> endTangent = curve2.evaluateTangent(curve2T);
    startTangent.Scale(tangentScale1);
    endTangent.Scale(tangentScale2);

    outCurve.setHermite(startPosition, endPosition, startTangent, endTangent);
}

template class CubicCurveConnectImpl<float>;
template class CubicCurveConnectImpl<double>;

} // namespace curve
