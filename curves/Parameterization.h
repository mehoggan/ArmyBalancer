#pragma once

#include <utility>
#include <vector>
#include <algorithm>
#include "curve/reparameterized/ParameterizationDecl.h"

namespace curve
{

/**
* @brief Remaps a single parametric value 't' to 's', s(t), ie given an input 't', it returns 's',
* thus making t the new effective parameterization.
*   -Both 't' and 's' span [0,1]
*   -Enforces that first mapping is (0,0) and samples are monotonically-increasing in t and s
*   -Last mapping must be (1,1)
*/
template<typename RealT>
class CURVE_API ParameterizationImpl
{
public:
    using RealType = RealT;

    ParameterizationImpl() { clear(); }

    /**
    * @brief Empties the current parameterization.
    */
    void clear()
    {
        m_parameters.clear();
    }

    /**
    * @brief Adds another mapping point.
    *   -Rejects parameter and displays error if t and s are not monotonically increasing
    *   or either lies outside the range [0,1]
    *   -Ensures initial parameter is (0,0)@param outLength Length of the curve (m).
    * @param t The value seen outside.
    * @param s The mapped value seen inside.
    */
    void addMapping(RealType t, RealType s);

    /**
    * @brief Outputs the mapping points.
    * @param outMappingParameters a vector of (t, s) pairs
    *        t The value seen outside.
    *        s The mapped value seen inside.
    */
    void getMappingParameters(std::vector< std::pair<RealType, RealType> >& outMappingParameters) const;

    /**
    * @brief Evaluate the parameterization (Given t, compute s).
    *   Returns the inside, ie original, parameter, s.
    * @param t The value seen outside.
    */
    RealType evaluate(RealType t) const;

    /**
    * @brief Evaluate the inverse of the parameterization (Given s, compute t).
    *   Returns the outside, ie re-parameterized, parameter, t.
    * @param s The inside parameter.
    */
    RealType evaluateInverse(RealType s) const;

    /**
    * @brief Evaluate the "stretch" dS/dt at the outside value.
    * @param t The unparameterized value.
    */
    RealType evaluateStretch(RealType t) const;

    /**
    * @brief Returns the number of explicitly mapped points.
    */
    size_t size() const { return m_parameters.size(); }

    /**
    * @brief Ensures that the Parameters span [0,1].
    * Remark: Displays errors before fixing
    */
    void makeValid();

private:

    RealType evaluateParams(RealType paramVal, bool isT) const;

    struct Parameter
    {
        Parameter() {}
        Parameter(RealType t, RealType s)
            : m_t(t)
            , m_s(s)
        {}

        void set(RealType t, RealType s)
        {
            m_t = t;
            m_s = s;
        }

        bool operator<(const Parameter& other) const
        {
            return (m_t < other.m_t);
        }

        RealType m_t;   //Input parameter
        RealType m_s;   //Output parameter

        // Functors for comparison in evaluate() and evaluateInverse()
        struct TLessThan
        {
            bool operator()(const Parameter& leftP, const Parameter& rightP) const
            {
                return (leftP.m_t < rightP.m_t);
            }
        };

        struct SLessThan
        {
            bool operator()(const Parameter& leftP, const Parameter& rightP) const
            {
                return (leftP.m_s < rightP.m_s);
            }
        };
    };

    std::vector<Parameter> m_parameters;
};

} // namespace curve