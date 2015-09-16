#pragma once

#include <vector>
#include <NavCore/Math/Geometry/AlignedBox3Decl.h>
#include <NavCore/Math/Vector/Vector3Decl.h>
#include "curve/CurveApi.h"
#include "curve/core/CurveDecl.h"
#include "curve/core/CurveNumericDecl.h"

namespace curve
{

template<typename RealT>
class CURVE_API CurveNumericImpl
{
public:
    using RealType = RealT;

    static NavCore::Math::Vector3Impl<RealType> evaluateTangent(const CurveImpl<RealType>& curve,
        RealType t);

    static std::vector<RealType> computeSampleValues(const CurveImpl<RealType>& curve,
        size_t sampleCount = 2);

    static NavCore::Math::AlignedBox3Impl<RealType> computeBoundingBox(const CurveImpl<RealType>& curve);
};

} // namespace curve
