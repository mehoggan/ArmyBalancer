#pragma once

#include "curve/core/CurveDecl.h"
#include "curve/cubic/CubicCurveConnectDecl.h"
#include "curve/cubic/CubicCurveDecl.h"

namespace curve
{

/**
 * @brief Generates a cubic curve between 2 given curves.
 */
template<typename RealT>
class CURVE_API CubicCurveConnectImpl
{
public:
    using RealType = RealT;

    static void connect(CubicCurveImpl<RealType>& outCurve,
        const CurveImpl<RealType>& curve1, const CurveImpl<RealType>& curve2,
        RealType tangentScale1 = 1, RealType tangentScale2 = 1);

    static void connect(CubicCurveImpl<RealType>& outCurve,
        const CurveImpl<RealType>& curve1, RealType curve1T,
        const CurveImpl<RealType>& curve2, RealType curve2T,
        RealType tangentScale1 = 1, RealType tangentScale2 = 1);
};

} // namespace curve
