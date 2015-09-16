#include "curve/reparameterized/Parameterization.h"

#include "NavCore/Math/Core/MathCore.h"

namespace curve
{

template<typename RealT>
void ParameterizationImpl<RealT>::addMapping(RealType t, RealType s)
{
    if (m_parameters.empty())
    {
        // Parameterization must start with (0,0).
        NT_ASSERT(!(t != 0.0 || s != 0.0));
        m_parameters.push_back(Parameter(0, 0));
    }
    else
    {
        // Parameterization must be monotonically increasing.
        NT_ASSERT(!(t <= m_parameters.back().m_t || s <= m_parameters.back().m_s));
        m_parameters.push_back(Parameter(t, s));
    }
}

template<typename RealT>
void ParameterizationImpl<RealT>::getMappingParameters(std::vector< std::pair<RealType, RealType> >& outMappingParameters) const
{
    for (const auto& parameter : m_parameters)
    {
        outMappingParameters.push_back(std::make_pair(parameter.m_t, parameter.m_s));
    }
}

template<typename RealT>
RealT ParameterizationImpl<RealT>::evaluate(RealType t) const
{
    return evaluateParams(t, true);
}

template<typename RealT>
RealT ParameterizationImpl<RealT>::evaluateInverse(RealType paramInput) const
{
    return evaluateParams(paramInput, false);
}

template<typename RealT>
RealT ParameterizationImpl<RealT>::evaluateParams(RealType paramInput, bool isT) const
{
    NT_ASSERT(m_parameters.size() >= 2);

    if (isT)
    {
        typename std::vector<Parameter>::const_iterator iter =
            std::lower_bound(m_parameters.begin(), m_parameters.end(), Parameter(paramInput, 0.0),
            typename Parameter::TLessThan());
        //NOTE: iter points to next HIGHER parameter

        if (iter == m_parameters.begin())
        {
            return m_parameters.front().m_s;
        }
        else if (iter == m_parameters.end())
        {
            //Shouldn't happen if input is in [0,1]!
            NT_ASSERT(false && "Parameter out of range");
            return m_parameters.back().m_s;
        }
        else
        {
            const Parameter& prev = *(iter - 1);
            const Parameter& next = *iter;

            const RealType lerp = (paramInput - prev.m_t) / (next.m_t - prev.m_t);
            const RealType s = NavCore::Math::Lerp(lerp, prev.m_s, next.m_s);
            return s;
        }
    }

    typename std::vector<Parameter>::const_iterator iter =
        std::lower_bound(m_parameters.begin(), m_parameters.end(),
        Parameter(0.0, paramInput), typename Parameter::SLessThan());
    //NOTE: iter points to next HIGHER parameter

    if (iter == m_parameters.begin())
    {
        return m_parameters.front().m_t;
    }
    else if (iter == m_parameters.end())
    {
        //Shouldn't happen if input is in [0,1].
        NT_ASSERT(false && "Parameter out of range");
        return m_parameters.back().m_t;
    }
    else
    {
        const Parameter& prev = *(iter - 1);
        const Parameter& next = *iter;

        const RealType lerp = (paramInput - prev.m_s) / (next.m_s - prev.m_s);
        const RealType t = NavCore::Math::Lerp(lerp, prev.m_t, next.m_t);
        return t;
    }
}

template<typename RealT>
RealT ParameterizationImpl<RealT>::evaluateStretch(RealType t) const
{
    const RealType cDeltaParam = RealType(0.001);
    RealType tPlusDelta = NavCore::Math::Min<RealType>(t + cDeltaParam, 1);
    RealType tMinusDelta = NavCore::Math::Max<RealType>(t - cDeltaParam, 0);

    const RealType dS = evaluate(tPlusDelta) - evaluate(tMinusDelta);
    const RealType dT = RealType(2.0)*cDeltaParam;

    return (dS / dT);
}

template<typename RealT>
void ParameterizationImpl<RealT>::makeValid()
{
    // Note: AddMapping enforces that samples start at (0,0) and are monotonically-increasing,
    // so we don't need to do that here.

    if (m_parameters.size() < 2)
    {
        // Parameterization must have at least two parameters.
        m_parameters.resize(2);
        m_parameters.front().set(0, 0);
        m_parameters.back().set(1, 1);
    }
    else if (m_parameters.back().m_t != 1.0 || m_parameters.back().m_s != 1.0)
    {
        // Parameterization must end with (1,1)
        m_parameters.back().set(1, 1);
    }
}

template class ParameterizationImpl<float>;
template class ParameterizationImpl<double>;

}  // namespace curve