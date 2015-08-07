// SparseMatrix.hh
#ifndef INCLUDED_CORE_MATH_SPARSEMATRIX
#define INCLUDED_CORE_MATH_SPARSEMATRIX

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

#ifndef INCLUDED_CORE_MATH_VECTOR
#include <Core/Math/Vector.hh>
#endif /* INCLUDED_CORE_MATH_VECTOR */

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
    // CLASS SparseMatrix
    // ========================================================================

    template<Size ColumnCount, Size RowCount, typename ScalarType> 
    struct SparseMatrix final
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
      // CLASS DATA ------------------------------------------------------<CD>-
      // DATA ------------------------------------------------------------<DT>-
      // FRIENDS ---------------------------------------------------------<FR>-
      // PRIVATE CREATORS ------------------------------------------------<PC>-
      // PRIVATE MANIPULATORS --------------------------------------------<PM>-
      // PRIVATE ACCESSORS -----------------------------------------------<PA>-
      
    public:
      // CREATORS --------------------------------------------------------<CR>-
      // DESTRUCTORS -----------------------------------------------------<DS>-
      // FRIEND ACCESSORS ------------------------------------------------<FA>-
      // FRIEND MANIPULATORS ---------------------------------------------<FM>-
      // OPERATORS -------------------------------------------------------<OP>-
      // TRAITS ----------------------------------------------------------<TR>-
      
    private:
      // NOT IMPLEMENTED -------------------------------------------------<NI>-
    };
    
    // FREE CREATORS -----------------------------------------------------<FC>-
    // FREE DESTRUCTORS --------------------------------------------------<FD>-
    // ACCESSORS ---------------------------------------------------------<AC>-
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
    // USING TYPES -------------------------------------------------------<UT>-
    // CREATORS ----------------------------------------------------------<CR>-
    // DESTRUCTORS -------------------------------------------------------<DS>-
    // ACCESSORS ---------------------------------------------------------<AC>-
    // MANIPULATORS ------------------------------------------------------<MA>-
    // OPERATORS ---------------------------------------------------------<OP>-
  }
}


#endif /* INCLUDED_CORE_MATH_SPARSEMATRIX */

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
