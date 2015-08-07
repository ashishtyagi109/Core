// Quaternion.hh
#ifndef INCLUDED_CORE_MATH_QUATERNION
#define INCLUDED_CORE_MATH_QUATERNION

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

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
    // CLASS Quaternion
    // ========================================================================

    template <typename ScalarType>
    struct Quaternion final
    {
    public:
      // TYPES -----------------------------------------------------------<TY>-
      struct Type
      {
      };

    private:
      // DATA ------------------------------------------------------------<DT>-
      ScalarType A;
      ScalarType I;
      ScalarType J;
      ScalarType K;

    public:
      // CREATORS --------------------------------------------------------<CR>-
      constexpr Quaternion ();

      constexpr Quaternion (const ScalarType &RealComponent);

      constexpr Quaternion (const ScalarType &A,
                            const ScalarType &I,
                            const ScalarType &J,
                            const ScalarType &K);

      constexpr Quaternion (const Quaternion &Source);

      Quaternion (Quaternion &&Source);

      // DESTRUCTORS -----------------------------------------------------<DS>-
      ~Quaternion () = default;

      // FRIEND ACCESSORS ------------------------------------------------<FA>-
      auto constexpr inline friend A (const Quaternion &Self)
        -> const ScalarType &;

      auto constexpr inline friend I (const Quaternion &Self)
        -> const ScalarType &;

      auto constexpr inline friend J (const Quaternion &Self)
        -> const ScalarType &;

      auto constexpr inline friend K (const Quaternion &Self)
        -> const ScalarType &;

      // FRIEND MANIPULATORS ---------------------------------------------<FM>-
      auto inline friend A (Quaternion &Self) -> ScalarType &;

      auto inline friend I (Quaternion &Self) -> ScalarType &;

      auto inline friend J (Quaternion &Self) -> ScalarType &;

      auto inline friend K (Quaternion &Self) -> ScalarType &;

      // OPERATORS -------------------------------------------------------<OP>-
      auto operator=(const Quaternion &Source) -> Quaternion & = default;

      auto operator=(Quaternion &&Source) -> Quaternion & = default;

      // TRAITS ----------------------------------------------------------<TR>-

    private:
      // NOT IMPLEMENTED -------------------------------------------------<NI>-
    };

    // FREE CREATORS -----------------------------------------------------<FC>-
    template <typename ScalarType>
    auto constexpr inline MakeQuaternion (const ScalarType &RealComponent)
      -> Quaternion<ScalarType>;

    template <typename ScalarType>
    auto constexpr inline MakeQuaternion (const ScalarType &A,
                                          const ScalarType &I,
                                          const ScalarType &J,
                                          const ScalarType &K)
      -> Quaternion<ScalarType>;

    // ACCESSORS ---------------------------------------------------------<AC>-
    template <typename ScalarType>
    auto inline Invert (Quaternion<ScalarType> &Inverse,
                        const Quaternion<ScalarType> &Self) -> Void;

    template <typename ScalarType>
    auto inline Invert (const Quaternion<ScalarType> &Self)
      -> Quaternion<ScalarType>;

    template <typename ScalarType>
    auto inline Magnitude (const Quaternion<ScalarType> &Self) -> ScalarType;

    template <typename ScalarType>
    auto inline Normalize (Quaternion<ScalarType> &UnitQuaternion,
                           const Quaternion<ScalarType> &Self) -> Void;

    template <typename ScalarType>
    auto inline Normalize (const Quaternion<ScalarType> &Self)
      -> Quaternion<ScalarType>;

    template <typename ScalarType>
    auto inline Add (Quaternion<ScalarType> &Sum,
                     const Quaternion<ScalarType> &Augend,
                     const Quaternion<ScalarType> &Addend) -> Void;

    template <typename ScalarType>
    auto inline Subtract (Quaternion<ScalarType> &Difference,
                          const Quaternion<ScalarType> &Minuend,
                          const Quaternion<ScalarType> &Subtrahend) -> Void;

    template <typename ScalarType>
    auto inline Multiply (Quaternion<ScalarType> &Product,
                          const Quaternion<ScalarType> &Multiplicand,
                          const ScalarType &Multiplier) -> Void;

    template <typename ScalarType>
    auto inline Multiply (Quaternion<ScalarType> &Product,
                          const Quaternion<ScalarType> &Multiplicand,
                          const Quaternion<ScalarType> &Multiplier) -> Void;

    template <typename ScalarType>
    auto inline Divide (Quaternion<ScalarType> &Quotient,
                        const Quaternion<ScalarType> &Dividend,
                        const ScalarType &Divider) -> Void;

    template <typename ScalarType>
    auto inline Divide (Quaternion<ScalarType> &Quotient,
                        const Quaternion<ScalarType> &Dividend,
                        const Quaternion<ScalarType> &Divider) -> Void;

    // FREE OPERATORS ----------------------------------------------------<FO>-
    template <typename ScalarType>
    auto inline
    operator+(const Quaternion<ScalarType> &Augend,
              const Quaternion<ScalarType> &Addend) -> Quaternion<ScalarType>;

    template <typename ScalarType>
    auto inline operator+=(Quaternion<ScalarType> &Augend,
                           const Quaternion<ScalarType> &Addend) -> Void;

    template <typename ScalarType>
    auto inline
    operator-(const Quaternion<ScalarType> &Self) -> Quaternion<ScalarType>;

    template <typename ScalarType>
    auto inline operator-(const Quaternion<ScalarType> &Minuend,
                          const Quaternion<ScalarType> &Subtrahend)
      -> Quaternion<ScalarType>;

    template <typename ScalarType>
    auto inline operator-=(Quaternion<ScalarType> &Minuend,
                           const Quaternion<ScalarType> &Subtrahend) -> Void;

    template <typename ScalarType>
    auto inline operator*(const Quaternion<ScalarType> &Multiplicand,
                          const Quaternion<ScalarType> &Multiplier)
      -> Quaternion<ScalarType>;

    template <typename ScalarType>
    auto inline operator*=(Quaternion<ScalarType> &Multiplicand,
                           const Quaternion<ScalarType> &Multiplier) -> Void;

    template <typename ScalarType>
    auto inline
    operator*(const Quaternion<ScalarType> &Multiplicand,
              const ScalarType &Multiplier) -> Quaternion<ScalarType>;

    template <typename ScalarType>
    auto inline operator*=(Quaternion<ScalarType> &Multiplicand,
                           const ScalarType &Multiplier) -> Void;

    template <typename ScalarType>
    auto inline operator*(const ScalarType &Multiplicand,
                          const Quaternion<ScalarType> &Multiplier)
      -> Quaternion<ScalarType>;

    template <typename ScalarType>
    auto inline
    operator/(const Quaternion<ScalarType> &Dividend,
              const Quaternion<ScalarType> &Divisor) -> Quaternion<ScalarType>;

    template <typename ScalarType>
    auto inline operator/=(Quaternion<ScalarType> &Dividend,
                           const Quaternion<ScalarType> &Divisor) -> Void;

    template <typename ScalarType>
    auto inline operator/(const Quaternion<ScalarType> &Dividend,
                          const ScalarType &Divisor) -> Quaternion<ScalarType>;

    template <typename ScalarType>
    auto inline operator/=(Quaternion<ScalarType> &Dividend,
                           const ScalarType &Divisor) -> Void;

    template <typename ScalarType>
    auto inline
    operator==(const Quaternion<ScalarType> &QuaternionOne,
               const Quaternion<ScalarType> &QuaternionTwo) -> Boolean;

    template <typename ScalarType>
    auto inline
    operator!=(const Quaternion<ScalarType> &QuaternionOne,
               const Quaternion<ScalarType> &QuaternionTwo) -> Boolean;
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
    template <typename ScalarType>
    constexpr Quaternion<ScalarType>::Quaternion ()
      : A (), I (), J (), K ()
    {
    }

    template <typename ScalarType>
    constexpr Quaternion<ScalarType>::Quaternion (
      const ScalarType &RealComponent)
      : A (RealComponent), I (), J (), K ()
    {
    }

    template <typename ScalarType>
    constexpr Quaternion<ScalarType>::Quaternion (const ScalarType &A,
                                                  const ScalarType &I,
                                                  const ScalarType &J,
                                                  const ScalarType &K)
      : A (A), I (I), J (J), K (K)
    {
    }

    template <typename ScalarType>
    constexpr Quaternion<ScalarType>::Quaternion (
      const Quaternion<ScalarType> &Source)
      : A (A (Source)), I (I (Source)), J (J (Source)), K (K (Source))
    {
    }

    template <typename ScalarType>
    Quaternion<ScalarType>::Quaternion (Quaternion<ScalarType> &&Source)
      : A (A (Source)), I (I (Source)), J (J (Source)), K (K (Source))
    {
      A (Source) = 0;
      I (Source) = 0;
      J (Source) = 0;
      K (Source) = 0;
    }

    template <typename ScalarType>
    auto constexpr inline MakeQuaternion (const ScalarType &RealComponent)
      -> Quaternion<ScalarType>
    {
      return Quaternion<ScalarType> (RealComponent);
    }

    template <typename ScalarType>
    auto constexpr inline MakeQuaternion (const ScalarType &A,
                                          const ScalarType &I,
                                          const ScalarType &J,
                                          const ScalarType &K)
      -> Quaternion<ScalarType>
    {
      return Quaternion<ScalarType> (A, I, J, K);
    }

    // ACCESSORS ---------------------------------------------------------<AC>-
    template <typename ScalarType>
    auto constexpr inline A (const Quaternion<ScalarType> &Self)
      -> const ScalarType &
    {
      return Self.A;
    }

    template <typename ScalarType>
    auto constexpr inline I (const Quaternion<ScalarType> &Self)
      -> const ScalarType &
    {
      return Self.I;
    }

    template <typename ScalarType>
    auto constexpr inline J (const Quaternion<ScalarType> &Self)
      -> const ScalarType &
    {
      return Self.J;
    }

    template <typename ScalarType>
    auto constexpr inline K (const Quaternion<ScalarType> &Self)
      -> const ScalarType &
    {
      return Self.K;
    }

    template <typename ScalarType>
    auto inline Invert (Quaternion<ScalarType> &Inverse,
                        const Quaternion<ScalarType> &Self) -> Void
    {
      auto ASquared = A (Self) * A (Self);
      auto ISquared = I (Self) * I (Self);
      auto JSquared = J (Self) * J (Self);
      auto KSquared = K (Self) * K (Self);
      auto Denominator = ASquared + ISquared + JSquared + KSquared;
      A (Inverse) = A (Self) / Denominator;
      I (Inverse) = -I (Self) / Denominator;
      J (Inverse) = -J (Self) / Denominator;
      K (Inverse) = -K (Self) / Denominator;
    }

    template <typename ScalarType>
    auto inline Invert (const Quaternion<ScalarType> &Self)
      -> Quaternion<ScalarType>
    {
      Quaternion<ScalarType> Inverse;
      Invert (Inverse, Self);
      return Inverse;
    }

    template <typename ScalarType>
    auto inline Magnitude (const Quaternion<ScalarType> &Self) -> ScalarType
    {
      auto ASquared = A (Self) * A (Self);
      auto ISquared = I (Self) * I (Self);
      auto JSquared = J (Self) * J (Self);
      auto KSquared = K (Self) * K (Self);
      return Sqrt (ASquared + ISquared + JSquared + KSquared);
    }

    template <typename ScalarType>
    auto inline Normalize (Quaternion<ScalarType> &UnitQuaternion,
                           const Quaternion<ScalarType> &Self) -> Void
    {
      Divide (UnitQuaternion, Self, Magnitude (Self));
    }

    template <typename ScalarType>
    auto inline Normalize (const Quaternion<ScalarType> &Self)
      -> Quaternion<ScalarType>
    {
      Quaternion<ScalarType> UnitQuaternion;
      Normalize (UnitQuaternion, Self);
      return UnitQuaternion;
    }

    template <typename ScalarType>
    auto inline Add (Quaternion<ScalarType> &Sum,
                     const Quaternion<ScalarType> &Augend,
                     const Quaternion<ScalarType> &Addend) -> Void
    {
      A (Sum) = A (Augend) + A (Addend);
      I (Sum) = I (Augend) + I (Addend);
      J (Sum) = J (Augend) + J (Addend);
      K (Sum) = K (Augend) + K (Addend);
    }

    template <typename ScalarType>
    auto inline Subtract (Quaternion<ScalarType> &Difference,
                          const Quaternion<ScalarType> &Minuend,
                          const Quaternion<ScalarType> &Subtrahend) -> Void
    {
      A (Difference) = A (Minuend) - A (Subtrahend);
      I (Difference) = I (Minuend) - I (Subtrahend);
      J (Difference) = J (Minuend) - J (Subtrahend);
      K (Difference) = K (Minuend) - K (Subtrahend);
    }

    template <typename ScalarType>
    auto inline Multiply (Quaternion<ScalarType> &Product,
                          const Quaternion<ScalarType> &Multiplicand,
                          const ScalarType &Multiplier) -> Void
    {
      A (Product) = A (Multiplicand) * Multiplier;
      I (Product) = I (Multiplicand) * Multiplier;
      J (Product) = J (Multiplicand) * Multiplier;
      K (Product) = K (Multiplicand) * Multiplier;
    }

    template <typename ScalarType>
    auto inline Multiply (Quaternion<ScalarType> &Product,
                          const Quaternion<ScalarType> &Multiplicand,
                          const Quaternion<ScalarType> &Multiplier) -> Void
    {
      ScalarType ACache = A (Multiplicand);
      ScalarType ICache = I (Multiplicand);
      ScalarType JCache = J (Multiplicand);
      ScalarType KCache = K (Multiplicand);
      A (Product) = ACache * A (Multiplier) - ICache * I (Multiplier)
                    - JCache * J (Multiplier) - KCache * K (Multiplier);
      I (Product) = ACache * I (Multiplier) + ICache * A (Multiplier)
                    + JCache * K (Multiplier) - KCache * J (Multiplier);
      J (Product) = ACache * J (Multiplier) - ICache * K (Multiplier)
                    + JCache * A (Multiplier) + KCache * J (Multiplier);
      K (Product) = ACache * K (Multiplier) + ICache * J (Multiplier)
                    - JCache * I (Multiplier) + KCache * A (Multiplier);
    }

    template <typename ScalarType>
    auto inline Divide (Quaternion<ScalarType> &Quotient,
                        const Quaternion<ScalarType> &Dividend,
                        const ScalarType &Divisor) -> Void
    {
      A (Quotient) = A (Dividend) / Divisor;
      I (Quotient) = I (Dividend) / Divisor;
      J (Quotient) = J (Dividend) / Divisor;
      K (Quotient) = K (Dividend) / Divisor;
    }

    template <typename ScalarType>
    auto inline Divide (Quaternion<ScalarType> &Quotient,
                        const Quaternion<ScalarType> &Dividend,
                        const Quaternion<ScalarType> &Divisor) -> Void
    {
      Multiply (Quotient, Dividend, Invert (Divisor));
    }

    // MANIPULATORS ------------------------------------------------------<MA>-
    template <typename ScalarType>
    auto inline A (Quaternion<ScalarType> &Self) -> ScalarType &
    {
      return Self.A;
    }

    template <typename ScalarType>
    auto inline I (Quaternion<ScalarType> &Self) -> ScalarType &
    {
      return Self.I;
    }

    template <typename ScalarType>
    auto inline J (Quaternion<ScalarType> &Self) -> ScalarType &
    {
      return Self.J;
    }

    template <typename ScalarType>
    auto inline K (Quaternion<ScalarType> &Self) -> ScalarType &
    {
      return Self.K;
    }

    // OPERATORS ---------------------------------------------------------<OP>-
    template <typename ScalarType>
    auto inline
    operator+(const Quaternion<ScalarType> &Augend,
              const Quaternion<ScalarType> &Addend) -> Quaternion<ScalarType>
    {
      Quaternion<ScalarType> Sum;
      Add (Sum, Augend, Addend);
      return Sum;
    }

    template <typename ScalarType>
    auto inline operator+=(Quaternion<ScalarType> &Augend,
                           const Quaternion<ScalarType> &Addend) -> Void
    {
      Add (Augend, Augend, Addend);
    }

    template <typename ScalarType>
    auto inline
    operator-(const Quaternion<ScalarType> &Self) -> Quaternion<ScalarType>
    {
      return MakeQuaternion (-A (Self), -I (Self), -J (Self), -K (Self));
    }

    template <typename ScalarType>
    auto inline
    operator-(const Quaternion<ScalarType> &Minuend,
              const Quaternion<ScalarType> &Subtrahend) -> Quaternion<ScalarType>
    {
      Quaternion<ScalarType> Difference;
      Subtract (Difference, Minuend, Subtrahend);
      return Difference;
    }

    template <typename ScalarType>
    auto inline operator-=(Quaternion<ScalarType> &Minuend,
                           const Quaternion<ScalarType> &Subtrahend) -> Void
    {
      Subtract (Minuend, Minuend, Subtrahend);
    }

    template <typename ScalarType>
    auto inline
    operator*(const Quaternion<ScalarType> &Multiplicand,
              const Quaternion<ScalarType> &Multiplier) -> Quaternion<ScalarType>
    {
      Quaternion<ScalarType> Product;
      Multiply (Product, Multiplicand, Multiplier);
      return Product;
    }

    template <typename ScalarType>
    auto inline operator*=(Quaternion<ScalarType> &Multiplicand,
                           const Quaternion<ScalarType> &Multiplier) -> Void
    {
      Multiply (Multiplicand, Multiplicand, Multiplier);
    }

    template <typename ScalarType>
    auto inline
    operator*(const Quaternion<ScalarType> &Multiplicand,
              const ScalarType &Multiplier) -> Quaternion<ScalarType>
    {
      Quaternion<ScalarType> Product;
      Mutliply (Product, Multiplicand, Multiplier);
      return Product;
    }

    template <typename ScalarType>
    auto inline operator*=(Quaternion<ScalarType> &Multiplicand,
                           const ScalarType &Multiplier) -> Void
    {
      Multiply (Multiplicand, Multiplicand, Multiplier);
    }

    template <typename ScalarType>
    auto inline
    operator*(const ScalarType &Multiplicand,
              const Quaternion<ScalarType> &Multiplier) -> Quaternion<ScalarType>
    {
      return Multiplier * Multiplicand;
    }

    template <typename ScalarType>
    auto inline
    operator/(const Quaternion<ScalarType> &Dividend,
              const Quaternion<ScalarType> &Divisor) -> Quaternion<ScalarType>
    {
      Quaternion<ScalarType> Quotient;
      Divide (Quotient, Dividend, Divisor);
      return Quotient;
    }

    template <typename ScalarType>
    auto inline operator/=(Quaternion<ScalarType> &Dividend,
                           const Quaternion<ScalarType> &Divisor) -> Void
    {
      Divide (Dividend, Dividend, Divisor);
    }

    template <typename ScalarType>
    auto inline operator/(const Quaternion<ScalarType> &Dividend,
                          const ScalarType &Divisor) -> Quaternion<ScalarType>
    {
      Quaternion<ScalarType> Quotient;
      Divide (Quotient, Dividend, Divisor);
      return Quotient;
    }

    template <typename ScalarType>
    auto inline operator/=(Quaternion<ScalarType> &Dividend,
                           const ScalarType &Divisor) -> Void
    {
      Divide (Dividend, Dividend, Divisor);
    }

    template <typename ScalarType>
    auto inline
    operator==(const Quaternion<ScalarType> &QuaternionOne,
               const Quaternion<ScalarType> &QuaternionTwo) -> Boolean
    {
      return A (QuaternionOne) == A (QuaternionTwo)
             && I (QuaternionOne) == I (QuaternionTwo)
             && J (QuaternionOne) == J (QuaternionTwo)
             && K (QuaternionOne) == K (QuaternionTwo);
    }

    template <typename ScalarType>
    auto inline
    operator!=(const Quaternion<ScalarType> &QuaternionOne,
               const Quaternion<ScalarType> &QuaternionTwo) -> Boolean
    {
      return A (QuaternionOne) != A (QuaternionTwo)
             || I (QuaternionOne) != I (QuaternionTwo)
             || J (QuaternionOne) != J (QuaternionTwo)
             || K (QuaternionOne) != k (QuaternionTwo);
    }
  }
}

#endif /* INCLUDED_CORE_MATH_QUATERNION */

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
