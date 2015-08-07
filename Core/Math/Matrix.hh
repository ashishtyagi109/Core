// Matrix.hh
#ifndef INCLUDED_CORE_MATH_MATRIX
#define INCLUDED_CORE_MATH_MATRIX

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

#ifndef INCLUDED_CORE_MATH_VECTOR
#include <Core/Math/Vector.hh>
#endif /* INCLUDED_CORE_MATH_VECTOR */

#ifndef INCLUDED_CORE_MATH_QUATERNION
#include <Core/Math/Quaternion.hh>
#endif /* INCLUDED_CORE_MATH_QUATERNION */

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

    // ===================================================================<CL>=
    // CLASS Matrix
    // ========================================================================

    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    struct Matrix final
    {
    public:
      // CONSTANTS -------------------------------------------------------<CN>-
      struct Constant
      {
        constexpr const static Size Columns = ColumnCount;
        constexpr const static Size Rows = RowCount;
      };

      // TYPES -----------------------------------------------------------<TY>-
      struct Type
      {
        using Scalar = ScalarType;
        using Column = Vector<RowCount, ScalarType>;
        using Row = Vector<ColumnCount, ScalarType>;
      };

    private:
      // PRIVATE TYPES ---------------------------------------------------<PT>-
      using ColumnType = typename Type::Column;
      using RowType = typename Type::Row;

      // DATA ------------------------------------------------------------<DT>-
      Vector<ColumnCount, ColumnType> Columns;

    public:
      // CREATORS --------------------------------------------------------<CR>-

      /** Construct the Zero Matrix
       * Construct the Zero Matrix of the specified `ColumnCount` and
       * `RowCount`, with elements of `ScalarType`
       */
      constexpr Matrix () = default;

      /** Construct a Matrix
       * Construct a Matrix with the specified columns. It is a compile-time
       * error to construct a matrix with column vectors of different
       * numbers or types of scalar elements.
       */
      template <typename... ColumnTypes>
      constexpr Matrix (ColumnTypes... Columns)
        : Columns (Columns...)
      {
      }

      /** Copy the `Source` Matrix into `this` Matrix
       * Copy each column vector of `Source` by value into `this` Matrix
       *
       * \param Source The original Matrix
       */
      Matrix (const Matrix &Source) = default;

      /** Move the `Source` Matrix into `this` Matrix
       * Move each column vector of `Source` by value into `this` Matrix
       *
       * \param Source The original Matrix
       */
      Matrix (Matrix &&Source) = default;

      // DESTRUCTORS -----------------------------------------------------<DS>-

      /** Delete `this` Matrix
       * Delete `this` Matrix and each column vector of `this` Matrix
       */
      ~Matrix () = default;

      // OPERATORS -------------------------------------------------------<OP>-

      /** Obtain the mutable column vector at index `ColumnIndex`
       *
       * \param ColumnIndex The index of the column vector
       *
       * \return The mutable reference to the column vector at `ColumnIndex`
       */
      auto inline
      operator[](Size ColumnIndex) -> Vector<RowCount, ScalarType> &;

      /** Obtain the column vector at index `ColumnIndex`
       *
       * \param ColumnIndex The index of the column vector
       *
       * \return The reference to the column vector at `ColumnIndex`
       */
      auto constexpr inline
      operator[](Size ColumnIndex) const -> const Vector<RowCount, ScalarType> &;

      // TRAITS ----------------------------------------------------------<TR>-

    private:
      // NOT IMPLEMENTED -------------------------------------------------<NI>-
    };

    // FREE CREATORS -----------------------------------------------------<FC>-

    /** Construct an inline Matrix
     * Construct an inline Matrix with the supplied column vectors. It is a
     * compile-time error to construct a Matrix with column vectors of
     * different numbers or types of elements. The number of columns and rows,
     * and the scalar element types of the Matrix can be inferred at compile
     * time and need not be specified.
     *
     * Example:
     *   auto RealIdentityMatrix2x2 = MakeMatrix (MakeVector (1.0, 0.0),
     *                                            MakeVector (0.0, 1.0));
     *
     * \param Column The first column vector of the Matrix. Each subsequent
     *               column vector must have the same type as this column
     *               vector.
     *
     * \param Columns The remaining column vectors of the Matrix. The number of
     *                column vectors in the resulting Matrix is equal to
     *                the size of the `Columns` parameter pack plus one.
     *
     * \return The inline Matrix with column vectors defined by `Column` and
     *         `Columns`
     */
    template <typename ScalarType, Size RowCount, typename... ColumnTypes>
    auto constexpr inline MakeMatrix (const Vector<RowCount, ScalarType> &Column,
                                      ColumnTypes... Columns)
      -> Matrix<1 + sizeof...(ColumnTypes), RowCount, ScalarType>;

    template <typename ScalarType>
    auto constexpr inline MakeRotationMatrix (const ScalarType &XAngle,
                                              const ScalarType &YAngle,
                                              const ScalarType &ZAngle)
      -> Matrix<4, 4, ScalarType>;

    template <typename ScalarType>
    auto inline MakeRotationMatrix (const Quaternion<ScalarType> &Source)
      -> Matrix<4, 4, ScalarType>;

    template <typename ScalarType>
    auto inline MakeScaleMatrix (const ScalarType &X,
                                 const ScalarType &Y,
                                 const ScalarType &Z)
      -> Matrix<4, 4, ScalarType>;

    template <typename ScalarType>
    auto inline MakeTranslationMatrix (const ScalarType &X,
                                       const ScalarType &Y,
                                       const ScalarType &Z)
      -> Matrix<4, 4, ScalarType>;

    // FREE ACCESSORS ----------------------------------------------------<FA>-
    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline Column (const Matrix<ColumnCount, RowCount, ScalarType> &Self,
                        Size ColumnIndex) -> Vector<RowCount, ScalarType>;

    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline Row (const Matrix<ColumnCount, RowCount, ScalarType> &Self,
                     Size RowIndex) -> Vector<ColumnCount, ScalarType>;

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline Add (Matrix<ColumnCount, RowCount, ScalarType> &Sum,
                     const Matrix<ColumnCount, RowCount, ScalarType> &Augend,
                     const Matrix<ColumnCount, RowCount, ScalarType> &Addend)
      -> Void;

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline Subtract (
      Matrix<ColumnCount, RowCount, ScalarType> &Difference,
      const Matrix<ColumnCount, RowCount, ScalarType> &Minuend,
      const Matrix<ColumnCount, RowCount, ScalarType> &Subtrahend) -> Void;

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline Multiply (
      Matrix<ColumnCount, RowCount, ScalarType> &Product,
      const Matrix<ColumnCount, RowCount, ScalarType> &Multiplicand,
      const ScalarType &Multiplier) -> Void;

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline Multiply (
      Vector<ColumnCount, ScalarType> &Product,
      const Matrix<ColumnCount, RowCount, ScalarType> &Multiplicand,
      const Vector<ColumnCount, ScalarType> &Multiplier) -> Void;

    template <Size ColumnCountOne,
              Size RowCountOne,
              Size ColumnCountTwo,
              Size RowCountTwo,
              typename ScalarType>
    auto inline Multiply (
      Matrix<ColumnCountOne, RowCountTwo, ScalarType> &Product,
      const Matrix<ColumnCountOne, RowCountOne, ScalarType> &Multiplicand,
      const Matrix<ColumnCountTwo, RowCountTwo, ScalarType> &Multiplier) -> Void;

    // FREE OPERATORS ----------------------------------------------------<FO>-
    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline
    operator-(const Matrix<ColumnCount, RowCount, ScalarType> &Minuend,
              const Matrix<ColumnCount, RowCount, ScalarType> &Subtrahend)
      -> Matrix<ColumnCount, RowCount>;

    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline
    operator-=(Matrix<ColumnCount, RowCount, ScalarType> &Minuend,
               const Matrix<ColumnCount, RowCount, ScalarType> &Subtrahend)
      -> Void;

    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline
    operator+(const Matrix<ColumnCount, RowCount, ScalarType> &Augend,
              const Matrix<ColumnCount, RowCount, ScalarType> &Addend)
      -> Matrix<ColumnCount, RowCount, ScalarType>;

    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline
    operator+=(Matrix<ColumnCount, RowCount, ScalarType> &Augend,
               const Matrix<ColumnCount, RowCount, ScalarType> &Addend) -> Void;

    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline
    operator*(const Matrix<ColumnCount, RowCount, ScalarType> &Multiplicand,
              const ScalarType &Multiplier)
      -> Matrix<ColumnCount, RowCount, ScalarType>;

    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline
    operator*(const ScalarType &Multiplicand,
              const Matrix<ColumnCount, RowCount, ScalarType> &Multiplier)
      -> Matrix<ColumnCount, RowCount, ScalarType>;

    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline
    operator*(const Matrix<ColumnCount, RowCount, ScalarType> &Multiplicand,
              const Vector<ColumnCount, ScalarType> &Multiplier)
      -> Vector<RowCount, ScalarType>;

    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline
    operator*(const Vector<ColumnCount, ScalarType> &Multiplicand,
              const Matrix<ColumnCount, RowCount, ScalarType> &Multiplier)
      -> Vector<RowCount, ScalarType>;

    template <Size ColumnCountOne,
              Size RowCountOne,
              Size ColumnCountTwo,
              Size RowCountTwo,
              typename ScalarType = Real>
    auto inline
    operator*(const Matrix<ColumnCountOne, RowCountOne, ScalarType> &MatrixOne,
              const Matrix<ColumnCountTwo, RowCountTwo, ScalarType> &MatrixTwo)
      -> Matrix<ColumnCountOne, RowCountTwo, ScalarType>;

    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline
    operator*=(Matrix<ColumnCount, RowCount, ScalarType> &Multiplicand,
               const ScalarType &Multiplier) -> Void;

    template <Size ColumnCountOne,
              Size RowCountOne,
              Size ColumnCountTwo,
              Size RowCountTwo,
              typename ScalarType = Real>
    auto inline
    operator*=(Matrix<ColumnCountOne, RowCountOne, ScalarType> &MatrixOne,
               const Matrix<ColumnCountTwo, RowCountTwo, ScalarType> &MatrixTwo)
      -> Void;

    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline
    operator==(const Matrix<ColumnCount, RowCount> &MatrixOne,
               const Matrix<ColumnCount, RowCount> &MatrixTwo) -> Boolean;

    template <Size ColumnCount, Size RowCount, typename ScalarType = Real>
    auto inline
    operator!=(const Matrix<ColumnCount, RowCount> &MatrixOne,
               const Matrix<ColumnCount, RowCount> &MatrixTwo) -> Boolean;
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

    // CREATORS ----------------------------------------------------------<CR>-
    template <typename ScalarType, Size RowCount, typename... ColumnTypes>
    auto constexpr inline MakeMatrix (const Vector<RowCount, ScalarType> &Column,
                                      ColumnTypes... Columns)
      -> Matrix<1 + sizeof...(ColumnTypes), RowCount, ScalarType>
    {
      return Matrix<1 + sizeof...(ColumnTypes), RowCount, ScalarType> (
        Column, static_cast<Vector<RowCount, ScalarType>> (Columns)...);
    }

    template <typename ScalarType>
    auto constexpr inline MakeRotationMatrix (const ScalarType &XAngle,
                                              const ScalarType &YAngle,
                                              const ScalarType &ZAngle)
      -> Matrix<4, 4, ScalarType>
    {
      return MakeMatrix (
        MakeVector (1 + cos (YAngle) + cos (ZAngle), sin (ZAngle),
                    -sin (YAngle), 0),
        MakeVector (-sin (ZAngle), cos (XAngle) + 1 + cos (ZAngle),
                    sin (XAngle), 0),
        MakeVector (sin (YAngle), -sin (XAngle),
                    cos (XAngle) + cos (YAngle) + 1, 0),
        MakeVector (0, 0, 0, 1));
    }

    template <typename ScalarType>
    auto inline MakeRotationMatrix (const Quaternion<ScalarType> &Source)
      -> Matrix<4, 4, ScalarType>
    {
      auto QA = A (Source);
      auto QI = I (Source);
      auto QJ = J (Source);
      auto QK = K (Source);
      return MakeMatrix (
        MakeVector (1 - 2 * QJ * QJ - 2 * QK * QK, 2 * (QI * QJ + QK * QA),
                    2 * (QI * QK - QJ * QA), 0),
        MakeVector (2 * (QI * QJ - QK * QA), 1 - 2 * QI * QI - 2 * QK * QK,
                    2 * (QJ * QK + QI * QA), 0),
        MakeVector (QI * QK + QJ * QA, QJ * QK - QI * QA,
                    1 - 2 * QI * QI - 2 * QJ * QJ, 0),
        MakeVector (0, 0, 0, 1));
    }

    template <typename ScalarType>
    auto inline MakeScaleMatrix (const ScalarType &X,
                                 const ScalarType &Y,
                                 const ScalarType &Z) -> Matrix<4, 4, ScalarType>
    {
      return MakeMatrix (MakeVector (X, 0, 0, 0), MakeVector (0, Y, 0, 0),
                         MakeVector (0, 0, Z, 0), MakeVector (0, 0, 0, 1));
    }

    template <typename ScalarType>
    auto inline MakeTranslationMatrix (const ScalarType &X,
                                       const ScalarType &Y,
                                       const ScalarType &Z)
      -> Matrix<4, 4, ScalarType>
    {
      return MakeMatrix (MakeVector (1, 0, 0, 0), MakeVector (0, 1, 0, 0),
                         MakeVector (0, 0, 1, 0), MakeVector (X, Y, Z, 1));
    }

    // ACCESSORS ---------------------------------------------------------<AC>-
    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline Column (const Matrix<ColumnCount, RowCount, ScalarType> &Self,
                        Size Index) -> Vector<RowCount, ScalarType>
    {
      return Self[Index];
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline Row (const Matrix<ColumnCount, RowCount, ScalarType> &Self,
                     Size RowIndex) -> Vector<ColumnCount, ScalarType>
    {
      Vector<ColumnCount, ScalarType> Result;
      for (Size ColumnIndex = 0; ColumnIndex < ColumnCount; ColumnIndex++)
        {
          Result[ColumnIndex] = Self[ColumnIndex][RowIndex];
        }
      return Result;
    }

    // MANIPULATORS ------------------------------------------------------<MA>-
    // OPERATORS ---------------------------------------------------------<OP>-
    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline Matrix<ColumnCount, RowCount, ScalarType>::
    operator[](Size ColumnIndex) -> Vector<RowCount, ScalarType> &
    {
      return Columns[ColumnIndex];
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto constexpr inline Matrix<ColumnCount, RowCount, ScalarType>::
    operator[](Size ColumnIndex) const -> const Vector<RowCount, ScalarType> &
    {
      return Columns[ColumnIndex];
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline Add (Matrix<ColumnCount, RowCount, ScalarType> &Sum,
                     const Matrix<ColumnCount, RowCount, ScalarType> &Augend,
                     const Matrix<ColumnCount, RowCount, ScalarType> &Addend)
      -> Void
    {
      for (Size ColumnIndex = 0; ColumnIndex < ColumnCount; ColumnIndex++)
        {
          for (Size RowIndex = 0; RowIndex < RowCount; RowIndex++)
            {
              Sum[ColumnIndex][RowIndex] = Augend[ColumnIndex][RowIndex]
                                           + Addend[ColumnIndex][RowIndex];
            }
        }
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline Subtract (
      Matrix<ColumnCount, RowCount, ScalarType> &Difference,
      const Matrix<ColumnCount, RowCount, ScalarType> &Minuend,
      const Matrix<ColumnCount, RowCount, ScalarType> &Subtrahend) -> Void
    {
      for (Size ColumnIndex = 0; ColumnIndex < ColumnCount; ColumnIndex++)
        {
          for (Size RowIndex = 0; RowIndex < RowCount; RowIndex++)
            {
              Difference[ColumnIndex][RowIndex]
                = Minuend[ColumnIndex][RowIndex]
                  - Subtrahend[ColumnIndex][RowIndex];
            }
        }
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline Multiply (
      Matrix<ColumnCount, RowCount, ScalarType> &Product,
      const Matrix<ColumnCount, RowCount, ScalarType> &Multiplicand,
      const ScalarType &Multiplier) -> Void
    {
      for (Size ColumnIndex = 0; ColumnIndex < ColumnCount; ColumnIndex++)
        {
          for (Size RowIndex = 0; RowIndex < RowCount; RowIndex++)
            {
              Product[ColumnIndex][RowIndex]
                = Multiplicand[ColumnIndex][RowIndex] * Multiplier;
            }
        }
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline Multiply (
      Vector<ColumnCount, ScalarType> &Product,
      const Matrix<ColumnCount, RowCount, ScalarType> &Multiplicand,
      const Vector<ColumnCount, ScalarType> &Multiplier) -> Void
    {
      for (Size ColumnIndex = 0; ColumnIndex < ColumnCount; ColumnIndex++)
        {
          Product[ColumnIndex]
            = DotProduct (Multiplicand[ColumnIndex], Multiplier);
        }
    }

    template <Size ColumnCountOne,
              Size RowCountOne,
              Size ColumnCountTwo,
              Size RowCountTwo,
              typename ScalarType>
    auto inline Multiply (
      Matrix<ColumnCountOne, RowCountTwo, ScalarType> &Product,
      const Matrix<ColumnCountOne, RowCountOne, ScalarType> &Multiplicand,
      const Matrix<ColumnCountTwo, RowCountTwo, ScalarType> &Multiplier) -> Void
    {
      static_assert (RowCountOne == ColumnCountTwo,
                     "Matrix multiplication is undefined unless the number of "
                     "rows of the left hand side match the number of columns "
                     "of the right hand side.");
      for (Size ColumnIndex = 0; ColumnIndex < ColumnCountOne; ColumnIndex++)
        {
          for (Size RowIndex = 0; RowIndex < RowCountTwo; RowIndex++)
            {
              for (Size ElementIndex = 0; ElementIndex < RowCountOne;
                   ElementIndex++)
                {
                  Product[ColumnIndex][RowIndex]
                    += Multiplicand[ColumnIndex][ElementIndex]
                       * Multiplier[ElementIndex][RowIndex];
                }
            }
        }
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline
    operator-(const Matrix<ColumnCount, RowCount, ScalarType> &Minuend,
              const Matrix<ColumnCount, RowCount, ScalarType> &Subtrahend)
      -> Matrix<ColumnCount, RowCount, ScalarType>
    {
      Matrix<ColumnCount, RowCount, ScalarType> Difference;
      Subtract (Difference, Minuend, Subtrahend);
      return Difference;
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline
    operator-=(Matrix<ColumnCount, RowCount, ScalarType> &Minuend,
               const Matrix<ColumnCount, RowCount, ScalarType> &Subtrahend)
      -> Void
    {
      Subtract (Minuend, Minuend, Subtrahend);
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline
    operator+(const Matrix<ColumnCount, RowCount, ScalarType> &Augend,
              const Matrix<ColumnCount, RowCount, ScalarType> &Addend)
      -> Matrix<ColumnCount, RowCount, ScalarType>
    {
      Matrix<ColumnCount, RowCount, ScalarType> Sum;
      Add (Sum, Augend, Addend);
      return Sum;
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline
    operator+=(Matrix<ColumnCount, RowCount, ScalarType> &Augend,
               const Matrix<ColumnCount, RowCount, ScalarType> &Addend) -> Void
    {
      Add (Augend, Augend, Addend);
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline
    operator*(const Matrix<ColumnCount, RowCount, ScalarType> &Multiplicand,
              const ScalarType &Multiplier)
      -> Matrix<ColumnCount, RowCount, ScalarType>
    {
      Matrix<ColumnCount, RowCount, ScalarType> Product;
      Multiply (Product, Multiplicand, Multiplier);
      return Product;
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline
    operator*(const ScalarType &Multiplicand,
              const Matrix<ColumnCount, RowCount, ScalarType> &Multiplier)
      -> Matrix<ColumnCount, RowCount, ScalarType>
    {
      return Multiplier * Multiplicand;
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline
    operator*(const Matrix<ColumnCount, RowCount, ScalarType> &Multiplicand,
              const Vector<ColumnCount, ScalarType> &Multiplier)
      -> Vector<ColumnCount, ScalarType>
    {
      Vector<ColumnCount, ScalarType> Product;
      Multiply (Product, Multiplicand, Multiplier);
      return Product;
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline
    operator*(const Vector<ColumnCount, ScalarType> &Multiplicand,
              const Matrix<ColumnCount, RowCount, ScalarType> &Multiplier)
      -> Vector<RowCount, ScalarType>
    {
      return Multiplier * Multiplicand;
    }

    template <Size ColumnCountOne,
              Size RowCountOne,
              Size ColumnCountTwo,
              Size RowCountTwo,
              typename ScalarType>
    auto inline operator*(
      const Matrix<ColumnCountOne, RowCountOne, ScalarType> &Multiplicand,
      const Matrix<ColumnCountTwo, RowCountTwo, ScalarType> &Multiplier)
      -> Matrix<ColumnCountOne, RowCountTwo, ScalarType>
    {
      Matrix<ColumnCountOne, RowCountTwo, ScalarType> Product;
      Multiply (Product, Multiplicand, Multiplier);
      return Product;
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline
    operator*=(Matrix<ColumnCount, RowCount, ScalarType> &Multiplicand,
               const ScalarType &Multiplier) -> Void
    {
      Multiply (Multiplicand, Multiplicand, Multiplier);
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline
    operator==(const Matrix<ColumnCount, RowCount> &MatrixOne,
               const Matrix<ColumnCount, RowCount> &MatrixTwo) -> Boolean
    {
      for (Size ColumnIndex = 0; ColumnIndex < ColumnCount; ColumnIndex++)
        {
          for (Size RowIndex = 0; RowIndex < RowCount; RowIndex++)
            {
              if (MatrixOne[ColumnIndex][RowIndex]
                  != MatrixTwo[ColumnIndex][RowIndex])
                {
                  return False;
                }
            }
        }
      return True;
    }

    template <Size ColumnCount, Size RowCount, typename ScalarType>
    auto inline
    operator!=(const Matrix<ColumnCount, RowCount> &MatrixOne,
               const Matrix<ColumnCount, RowCount> &MatrixTwo) -> Boolean
    {
      for (Size ColumnIndex = 0; ColumnIndex < ColumnCount; ColumnIndex++)
        {
          for (Size RowIndex = 0; RowIndex < RowCount; RowIndex++)
            {
              if (MatrixOne[ColumnIndex][RowIndex]
                  != MatrixTwo[ColumnIndex][RowIndex])
                {
                  return True;
                }
            }
        }
      return False;
    }
  }
}

#endif /* INCLUDED_CORE_MATH_MATRIX */

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
