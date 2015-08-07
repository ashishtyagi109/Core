// Vector.hh
#ifndef INCLUDED_CORE_MATH_VECTOR
#define INCLUDED_CORE_MATH_VECTOR

#ifndef INCLUDED_CORE_LITERAL
#include <Core/Literal.hh>
#endif /* INCLUDED_CORE_LITERAL */

#ifndef INCLUDED_CORE_MATH_SQRT
#include <Core/Math/Sqrt.hh>
#endif /* INCLUDED_CORE_MATH_SQRT */

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

    // ===================================================================<CL>=
    // CLASS Vector
    // ========================================================================

    template <Size Rank, typename ScalarType>
    struct Vector final
    {
    public:
      // CONSTANTS -------------------------------------------------------<CN>-
      struct Constant
      {
	constexpr const static Size ScalarCount = Rank;
      };

      // TYPES -----------------------------------------------------------<TY>-
      struct Type
      {
        using Scalar = ScalarType;
      };

    private:
      // DATA ------------------------------------------------------------<DT>-
      ScalarType Scalars[Rank];

    public:
      // CREATORS --------------------------------------------------------<CR>-
      Vector ();

      template <typename... ScalarTypes>
      constexpr Vector (ScalarTypes... Scalars)
        : Scalars{static_cast<ScalarType> (Scalars)...}
      {
      }

      Vector (const Vector &Source) = default;

      Vector (Vector &&Source) = default;

      // DESTRUCTORS -----------------------------------------------------<DS>-
      ~Vector () = default;

      // OPERATORS -------------------------------------------------------<OP>-
      auto constexpr operator[](Size Index) const -> const ScalarType &;

      auto operator[](Size Index) -> ScalarType &;

      auto operator-() -> Vector;

      auto operator=(const Vector &) -> Vector & = default;

      auto operator=(Vector && ) -> Vector & = default;
    };

    // FREE CREATORS -----------------------------------------------------<FC>-
    template <typename FirstScalarType, typename... ScalarTypes>
    auto constexpr MakeVector (FirstScalarType Scalar, ScalarTypes... Scalars)
      -> Vector<1 + sizeof...(ScalarTypes), FirstScalarType>;

    // template <typename ScalarType>
    // auto constexpr I = MakeVector<ScalarType> (1, 0, 0);

    // template <typename ScalarType>
    // auto constexpr J = MakeVector<ScalarType> (0, 1, 0);

    // template <typename ScalarType>
    // auto constexpr K = MakeVector<ScalarType> (0, 0, 1);

    // ACCESSORS ---------------------------------------------------------<AC>-
    template <Size Rank, typename ScalarType = Real>
    auto constexpr X (const Vector<Rank, ScalarType> &Self)
      -> const ScalarType &;

    template <Size Rank, typename ScalarType = Real>
    auto constexpr Y (const Vector<Rank, ScalarType> &Self)
      -> const ScalarType &;

    template <Size Rank, typename ScalarType = Real>
    auto constexpr Z (const Vector<Rank, ScalarType> &Self)
      -> const ScalarType &;

    template <typename ScalarType = Real>
    auto CrossProduct (const Vector<3, ScalarType> &VectorOne,
                       const Vector<3, ScalarType> &VectorTwo)
      -> Vector<3, ScalarType>;

    template <Size Rank, typename ScalarType = Real>
    auto DotProduct (const Vector<Rank, ScalarType> &VectorOne,
                     const Vector<Rank, ScalarType> &VectorTwo) -> ScalarType;

    template <Size Rank, typename ScalarType = Real>
    auto Magnitude (const Vector<Rank, ScalarType> &Self) -> ScalarType;

    template <Size Rank, typename ScalarType = Real>
    auto Normalize (const Vector<Rank, ScalarType> &Self)
      -> Vector<Rank, ScalarType>;

    template <Size Rank, typename ScalarType = Real>
    auto Project (const Vector<Rank, ScalarType> &Source,
                  const Vector<Rank, ScalarType> &Destination) -> ScalarType;

    template <Size Rank, typename ScalarType = Real>
    auto X (Vector<Rank, ScalarType> &Self) -> ScalarType &;

    template <Size Rank, typename ScalarType = Real>
    auto Y (Vector<Rank, ScalarType> &Self) -> ScalarType &;

    template <Size Rank, typename ScalarType = Real>
    auto Z (Vector<Rank, ScalarType> &Self) -> ScalarType &;

    // FREE OPERATORS ----------------------------------------------------<FO>-
    template <Size Rank, typename ScalarType = Real>
    auto operator+(const Vector<Rank, ScalarType> &VectorOne,
                   const Vector<Rank, ScalarType> &VectorTwo)
      -> Vector<Rank, ScalarType>;

    template <Size Rank, typename ScalarType = Real>
    auto operator+=(Vector<Rank, ScalarType> &VectorOne,
                    const Vector<Rank, ScalarType> &VectorTwo) -> Void;

    template <Size Rank, typename ScalarType = Real>
    auto operator-(const Vector<Rank, ScalarType> &VectorOne,
                   const Vector<Rank, ScalarType> &VectorTwo)
      -> Vector<Rank, ScalarType>;

    template <Size Rank, typename ScalarType = Real>
    auto operator-=(Vector<Rank, ScalarType> &VectorOne,
                    const Vector<Rank, ScalarType> &VectorTwo) -> Void;

    template <Size Rank, typename ScalarType = Real>
    auto operator*(const Vector<Rank, ScalarType> &Self,
                   const ScalarType &Scalar) -> Vector<Rank, ScalarType>;

    template <Size Rank, typename ScalarType = Real>
    auto
    operator*(const ScalarType &Scalar,
              const Vector<Rank, ScalarType> &Self) -> Vector<Rank, ScalarType>;

    template <Size Rank, typename ScalarType = Real>
    auto operator*=(Vector<Rank, ScalarType> &Self,
                    const ScalarType &Scalar) -> Void;

    template <Size Rank, typename ScalarType = Real>
    auto operator/(const Vector<Rank, ScalarType> &Self,
                   const ScalarType &Scalar) -> Vector<Rank, ScalarType>;

    template <Size Rank, typename ScalarType = Real>
    auto
    operator/(const ScalarType &Scalar,
              const Vector<Rank, ScalarType> &Self) -> Vector<Rank, ScalarType>;

    template <Size Rank, typename ScalarType = Real>
    auto operator/=(Vector<Rank, ScalarType> &Self,
                    const ScalarType &Scalar) -> Void;

    template <Size Rank, typename ScalarType = Real>
    auto operator==(const Vector<Rank, ScalarType> &VectorOne,
                    const Vector<Rank, ScalarType> &VectorTwo) -> Boolean;

    template <Size Rank, typename ScalarType = Real>
    auto operator!=(const Vector<Rank, ScalarType> &VectorOne,
                    const Vector<Rank, ScalarType> &VectorTwo) -> Boolean;

    template <Size Rank, typename ScalarType = Real>
    auto operator<(const Vector<Rank, ScalarType> &VectorOne,
                   const Vector<Rank, ScalarType> &VectorTwo) -> Boolean;

    template <Size Rank, typename ScalarType = Real>
    auto operator<=(const Vector<Rank, ScalarType> &VectorOne,
                    const Vector<Rank, ScalarType> &VectorTwo) -> Boolean;

    template <Size Rank, typename ScalarType = Real>
    auto operator>(const Vector<Rank, ScalarType> &VectorOne,
                   const Vector<Rank, ScalarType> &VectorTwo) -> Boolean;

    template <Size Rank, typename ScalarType = Real>
    auto operator>=(const Vector<Rank, ScalarType> &VectorOne,
                    const Vector<Rank, ScalarType> &VectorTwo) -> Boolean;
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

    // CREATORS ----------------------------------------------------------<CR>-
    template <Size Rank, typename ScalarType>
    Vector<Rank, ScalarType>::Vector () = default;

    template <typename FirstScalarType, typename... ScalarTypes>
    auto constexpr MakeVector (FirstScalarType Scalar, ScalarTypes... Scalars)
      -> Vector<1 + sizeof...(ScalarTypes), FirstScalarType>
    {
      return Vector<1 + sizeof...(ScalarTypes), FirstScalarType> (
        Scalar, static_cast<FirstScalarType> (Scalars)...);
    }

    // ACCESSORS ---------------------------------------------------------<AC>-
    template <Size Rank, typename ScalarType>
    auto constexpr X (const Vector<Rank, ScalarType> &Self) -> const ScalarType
      &
    {
      static_assert (Rank >= 1,
                     "Accessing the X Element of a Vector is undefined for "
                     "Vectors of fewer than 1 Scalars");
      return Self[0];
    }

    template <Size Rank, typename ScalarType>
    auto constexpr Y (const Vector<Rank, ScalarType> &Self) -> const ScalarType
      &
    {
      static_assert (Rank >= 2,
                     "Accessing the Y Element of a Vector is undefined for "
                     "Vectors of fewer than 2 Scalars");
      return Self[1];
    }

    template <Size Rank, typename ScalarType>
    auto constexpr Z (const Vector<Rank, ScalarType> &Self) -> const ScalarType
      &
    {
      static_assert (Rank >= 3,
                     "Accessing the Z Element of a Vector is undefined for "
                     "Vectors of fewer than 3 Scalars");
      return Self[2];
    }

    template <typename ScalarType>
    auto CrossProduct (const Vector<3, ScalarType> &VectorOne,
                       const Vector<3, ScalarType> &VectorTwo)
      -> Vector<3, ScalarType>
    {
      auto X = VectorOne[1] * VectorTwo[2] - VectorOne[2] * VectorTwo[1];
      auto Y = VectorOne[2] * VectorTwo[0] - VectorOne[0] * VectorTwo[2];
      auto Z = VectorOne[0] * VectorTwo[1] - VectorOne[1] * VectorTwo[0];
      return MakeVector<ScalarType> (X, Y, Z);
    }

    template <Size Rank, typename ScalarType>
    auto DotProduct (const Vector<Rank, ScalarType> &VectorOne,
                     const Vector<Rank, ScalarType> &VectorTwo) -> ScalarType
    {
      ScalarType Product = 0;
      for (Size Index = 0; Index < Rank; Index++)
        {
          Product += VectorOne[Index] * VectorTwo[Index];
        }
      return Product;
    }

    template <Size Rank, typename ScalarType>
    auto Magnitude (const Vector<Rank, ScalarType> &Self) -> ScalarType
    {
      return Sqrt (DotProduct (Self, Self));
    }

    template <Size Rank, typename ScalarType>
    auto Normalize (const Vector<Rank, ScalarType> &Self)
      -> Vector<Rank, ScalarType>
    {
      return Self / Magnitude (Self);
    }

    template <Size Rank, typename ScalarType>
    auto Project (const Vector<Rank, ScalarType> &Source,
                  const Vector<Rank, ScalarType> &Destination) -> ScalarType
    {
      return DotProduct (Source, Normalize (Destination));
    }

    template <Size Rank, typename ScalarType>
    auto X (Vector<Rank, ScalarType> &Self) -> ScalarType &
    {
      static_assert (Rank >= 1,
                     "Accessing the X Element of a Vector is undefined for "
                     "Vectors of fewer than 1 Scalars");
      return Self[0];
    }

    template <Size Rank, typename ScalarType>
    auto Y (Vector<Rank, ScalarType> &Self) -> ScalarType &
    {
      static_assert (Rank >= 2,
                     "Accessing the Y Element of a Vector is undefined for "
                     "Vectors of fewer than 2 Scalars");
      return Self[1];
    }

    template <Size Rank, typename ScalarType>
    auto Z (Vector<Rank, ScalarType> &Self) -> ScalarType &
    {
      static_assert (Rank >= 3,
                     "Accessing the Y Element of a Vector is undefined for "
                     "Vectors of fewer than 3 Scalars");
      return Self[2];
    }

    // OPERATORS ---------------------------------------------------------<OP>-
    template <Size Rank, typename ScalarType>
    auto constexpr Vector<Rank, ScalarType>::
    operator[](Size Index) const -> const ScalarType &
    {
      return Scalars[Index];
    }

    template <Size Rank, typename ScalarType>
    auto Vector<Rank, ScalarType>::operator[](Size Index) -> ScalarType &
    {
      return Scalars[Index];
    }

    template <Size Rank, typename ScalarType>
    auto Vector<Rank, ScalarType>::operator-() -> Vector<Rank, ScalarType>
    {
      Vector<Rank, ScalarType> Result;
      for (Size Index = 0; Index < Rank; Index++)
        {
          Result[Index] = -Scalars[Index];
        }
      return Result;
    }

    template <Size Rank, typename ScalarType>
    auto operator+(const Vector<Rank, ScalarType> &VectorOne,
                   const Vector<Rank, ScalarType> &VectorTwo)
      -> Vector<Rank, ScalarType>
    {
      Vector<Rank, ScalarType> Result;
      for (Size Index = 0; Index < Rank; Index++)
        {
          Result[Index] = VectorOne[Index] + VectorTwo[Index];
        }
      return Result;
    }

    template <Size Rank, typename ScalarType>
    auto operator+=(Vector<Rank, ScalarType> &VectorOne,
                    const Vector<Rank, ScalarType> &VectorTwo) -> Void
    {
      for (Size Index = 0; Index < Rank; Index++)
        {
          VectorOne[Index] += VectorTwo[Index];
        }
    }

    template <Size Rank, typename ScalarType>
    auto operator-(const Vector<Rank, ScalarType> &VectorOne,
                   const Vector<Rank, ScalarType> &VectorTwo)
      -> Vector<Rank, ScalarType>
    {
      Vector<Rank, ScalarType> Result;
      for (Size Index = 0; Index < Rank; Index++)
        {
          Result[Index] = VectorOne[Index] - VectorTwo[Index];
        }
      return Result;
    }

    template <Size Rank, typename ScalarType>
    auto operator-=(Vector<Rank, ScalarType> &VectorOne,
                    const Vector<Rank, ScalarType> &VectorTwo) -> Void
    {
      for (Size Index = 0; Index < Rank; Index++)
        {
          VectorOne[Index] -= VectorTwo[Index];
        }
    }

    template <Size Rank, typename ScalarType>
    auto operator*(const Vector<Rank, ScalarType> &Self,
                   const ScalarType &Scalar) -> Vector<Rank, ScalarType>
    {
      Vector<Rank, ScalarType> Result;
      for (Size Index = 0; Index < Rank; Index++)
        {
          Result[Index] = Self[Index] * Scalar;
        }
      return Result;
    }

    template <Size Rank, typename ScalarType>
    auto
    operator*(const ScalarType &Scalar,
              const Vector<Rank, ScalarType> &Self) -> Vector<Rank, ScalarType>
    {
      return Self * Scalar;
    }

    template <Size Rank, typename ScalarType>
    auto
    operator*=(Vector<Rank, ScalarType> &Self, const ScalarType &Scalar) -> Void
    {
      for (Size Index = 0; Index < Rank; Index++)
        {
          Self[Index] *= Scalar;
        }
    }

    template <Size Rank, typename ScalarType>
    auto operator/(const Vector<Rank, ScalarType> &Self,
                   const ScalarType &Scalar) -> Vector<Rank, ScalarType>
    {
      Vector<Rank, ScalarType> Result;
      for (Size Index = 0; Index < Rank; Index++)
        {
          Result[Index] = Self[Index] / Scalar;
        }
      return Result;
    }

    template <Size Rank, typename ScalarType>
    auto
    operator/(const ScalarType &Scalar,
              const Vector<Rank, ScalarType> &Self) -> Vector<Rank, ScalarType>
    {
      Vector<Rank, ScalarType> Result;
      for (Size Index = 0; Index < Rank; Index++)
        {
          Result[Index] = Scalar / Self[Index];
        }
      return Result;
    }

    template <Size Rank, typename ScalarType>
    auto
    operator/=(Vector<Rank, ScalarType> &Self, const ScalarType &Scalar) -> Void
    {
      for (Size Index = 0; Index < Rank; Index++)
        {
          Self[Index] /= Scalar;
        }
    }

    template <Size Rank, typename ScalarType>
    auto operator==(const Vector<Rank, ScalarType> &VectorOne,
                    const Vector<Rank, ScalarType> &VectorTwo) -> Boolean
    {
      for (Size Index = 0; Index < Rank; Index++)
        {
          if (!(VectorOne[Index] == VectorTwo[Index]))
            {
              return False;
            }
        }
      return True;
    }

    template <Size Rank, typename ScalarType>
    auto operator!=(const Vector<Rank, ScalarType> &VectorOne,
                    const Vector<Rank, ScalarType> &VectorTwo) -> Boolean
    {
      return !(VectorOne == VectorTwo);
    }

    template <Size Rank, typename ScalarType>
    auto operator<(const Vector<Rank, ScalarType> &VectorOne,
                   const Vector<Rank, ScalarType> &VectorTwo) -> Boolean
    {
      for (Size Index = 0; Index < Rank; Index++)
        {
          if (!(VectorOne[Index] < VectorTwo[Index]))
            {
              return False;
            }
        }
      return True;
    }

    template <Size Rank, typename ScalarType>
    auto operator<=(const Vector<Rank, ScalarType> &VectorOne,
                    const Vector<Rank, ScalarType> &VectorTwo) -> Boolean
    {
      for (Size Index = 0; Index < Rank; Index++)
        {
          if (!(VectorOne[Index] <= VectorTwo[Index]))
            {
              return False;
            }
        }
      return True;
    }

    template <Size Rank, typename ScalarType>
    auto operator>(const Vector<Rank, ScalarType> &VectorOne,
                   const Vector<Rank, ScalarType> &VectorTwo) -> Boolean
    {
      for (Size Index = 0; Index < Rank; Index++)
        {
          if (!(VectorOne[Index] > VectorTwo[Index]))
            {
              return False;
            }
        }
      return True;
    }

    template <Size Rank, typename ScalarType>
    auto operator>=(const Vector<Rank, ScalarType> &VectorOne,
                    const Vector<Rank, ScalarType> &VectorTwo) -> Boolean
    {
      for (Size Index = 0; Index < Rank; Index++)
        {
          if (!(VectorOne[Index] >= VectorTwo[Index]))
            {
              return False;
            }
        }
      return True;
    }
  }
}

#endif /* INCLUDED_CORE_MATH_VECTOR */

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
