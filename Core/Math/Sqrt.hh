// Sqrt.hh
#ifndef INCLUDED_CORE_MATH_SQRT
#define INCLUDED_CORE_MATH_SQRT

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

// =======================================================================<DC>=
// @PURPOSE: Provide an implementation of `Sqrt`
// @DESCRIPTION: Implements the square root function
// ============================================================================

namespace Core
{
  namespace Math
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    using namespace Core::Literal;

    // FUNCTIONS ---------------------------------------------------------<FN>- 
    /** Compute the square root of `Number`
     *
     * \param[out] Root      The computed square root
     *
     * \param Number         The number to compute the square root for
     *
     * \param IterationCount The number of iterations of the approximation
     *                       algorithm to perform.
     *
     */
    template <typename NumericType>
    auto inline Sqrt (NumericType &Root,
                      const NumericType &Number,
		      Size IterationCount = 5) -> Void;

    /** Compute the square root of `Number`
     *
     * \param Number         The number to compute the square root for
     *
     * \param IterationCount The number of iterations of the approximation
     *                       algorithm to perform.
     *
     * \return               The approximate square root of `Number`
     */
    template <typename NumericType>
    auto inline Sqrt (const NumericType &Number,
                      Size IterationCount = 5) -> NumericType;
  }
}

// =======================================================================<IM>=
// IMPLEMENTATION
// ============================================================================

namespace Core
{
  namespace Math
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    using namespace Core::Literal;

    // FUNCTIONS ---------------------------------------------------------<FN>- 
    template <typename NumericType>
    auto inline Sqrt (NumericType &Root,
                      const NumericType &Number,
		      Size IterationCount) -> Void
    {
      Root = Number;
      for (Size Iteration = 0; Iteration < IterationCount; Iteration++)
        {
	  Root = (Root + Number / Root) / 2;
        }
    }

    template <typename NumericType>
    auto inline Sqrt (const NumericType &Number,
		      Size IterationCount) -> NumericType
    {
      NumericType Root;
      Sqrt (Root, Number, IterationCount);
      return Root;
    }
  }
}

#endif /* INCLUDED_CORE_MATH_SQRT */
