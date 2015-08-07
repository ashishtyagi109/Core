// Point.hh
#ifndef INCLUDED_CORE_MATH_POINT
#define INCLUDED_CORE_MATH_POINT

#ifndef INCLUDED_CORE_LITERAL
#include <Core/Literal.hh>
#endif /* INCLUDED_CORE_LITERAL */

#ifndef INCLUDED_CMATH
#include <cmath>
#define INCLUDED_CMATH
#endif /* INCLUDED_CMATH */

// =======================================================================<DC>=
// @PURPOSE:
// @CLASSES:
// @MACROS:
// @SEE_ALSO:
// @DESCRIPTION:
// ============================================================================

namespace Core
{
  namespace Math
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    using namespace Core::Literal;
    // USING TYPES -------------------------------------------------------<UT>-

    // ===================================================================<CL>=
    // CLASS Point
    // ========================================================================

    template <Size Dimensions, typename ScalarType = Real>
    struct Point final
    {
    public:
      // TYPES -----------------------------------------------------------<TY>-
      struct Type
      {
        using Scalar = ScalarType;
      };

    private:
      // PRIVATE TYPES ---------------------------------------------------<PT>-
      // CLASS DATA ------------------------------------------------------<CD>-
      // DATA ------------------------------------------------------------<DT>-
      ScalarType Scalars[Dimensions];
      // FRIENDS ---------------------------------------------------------<FR>-
      // PRIVATE CREATORS ------------------------------------------------<PC>-
      // PRIVATE MANIPULATORS --------------------------------------------<PM>-
      // PRIVATE ACCESSORS -----------------------------------------------<PA>-

    public:
      // CREATORS --------------------------------------------------------<CR>-
      constexpr Point ();

      template <typename... ScalarTypes>
      constexpr Point (ScalarTypes... Scalars)
	: Scalars{static_cast<ScalarType>(Scalars)...}
      {
      }

      template <typename FirstScalarType, typename... ScalarTypes>
      auto friend MakePoint (FirstScalarType Scalar, ScalarTypes... Scalars)
        -> Point<1 + sizeof...(ScalarTypes), FirstScalarType>;
      // DESTRUCTORS -----------------------------------------------------<DS>-
      // FRIEND ACCESSORS ------------------------------------------------<FA>-
      // FRIEND MANIPULATORS ---------------------------------------------<FM>-
      // OPERATORS -------------------------------------------------------<OP>-
      auto operator[](Size Index) -> ScalarType &;
      auto constexpr operator[](Size Index) const -> const ScalarType &;
      // TRAITS ----------------------------------------------------------<TR>-

    private:
      // NOT IMPLEMENTED -------------------------------------------------<NI>-
    };

    // FREE CREATORS -----------------------------------------------------<FC>-
    // FREE DESTRUCTORS --------------------------------------------------<FD>-
    // ACCESSORS ---------------------------------------------------------<AC>-
    template <Size Dimensions, typename ScalarType = Real>
    auto Distance (const Point<Dimensions, ScalarType> &PointOne,
                   const Point<Dimensions, ScalarType> &PointTwo) -> ScalarType;
    // MANIPULATORS ------------------------------------------------------<MA>-
    // FREE OPERATORS ----------------------------------------------------<FO>-
  }
}

// ============================================================================
// IMPLEMENTATION
// ============================================================================

namespace Core
{
  namespace Math
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    using namespace Core::Literal;
    // USING TYPES -------------------------------------------------------<UT>-
    // CREATORS ----------------------------------------------------------<CR>-
    template <typename FirstScalarType, typename... ScalarTypes>
    auto MakePoint (FirstScalarType Scalar, ScalarTypes... Scalars)
      -> Point<1 + sizeof...(ScalarTypes), FirstScalarType>
    {
      return Point<1 + sizeof...(ScalarTypes), FirstScalarType> (
        Scalar, static_cast<FirstScalarType> (Scalars)...);
    }

    // DESTRUCTORS -------------------------------------------------------<DS>-
    // ACCESSORS ---------------------------------------------------------<AC>-
    template <Size Dimensions, typename ScalarType>
    auto Point<Dimensions, ScalarType>::operator[](Size Index) -> ScalarType &
    {
      return Scalars[Index];
    }

    template <Size Dimensions, typename ScalarType>
    auto constexpr Point<Dimensions, ScalarType>::
    operator[](Size Index) const -> const ScalarType &
    {
      return Scalars[Index];
    }

    template <Size Dimensions, typename ScalarType>
    auto Distance (const Point<Dimensions, ScalarType> &PointOne,
                   const Point<Dimensions, ScalarType> &PointTwo) -> ScalarType
    {
      ScalarType Sum = 0;
      for (Size Index = 0; Index < Dimensions; Index++)
        {
          ScalarType Difference = PointTwo[Index] - PointOne[Index];
          Sum += Difference * Difference;
        }
      return sqrt (Sum);
    }
    // MANIPULATORS ------------------------------------------------------<MA>-
    // OPERATORS ---------------------------------------------------------<OP>-
  }
}

#endif /* INCLUDED_CORE_MATH_POINT */

// =======================================================================<CP>=
// COPYRIGHT NOTICE:
// Copyright (c) 2015. Nathan Burgers.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
// ============================================================================
