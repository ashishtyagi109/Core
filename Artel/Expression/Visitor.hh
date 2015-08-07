// Visitor.hh
#ifndef INCLUDED_ARTEL_EXPRESSION_VISITOR
#define INCLUDED_ARTEL_EXPRESSION_VISITOR

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

// =======================================================================<DC>=
// @PURPOSE:
// @CLASSES:
// @MACROS:
// @SEE_ALSO:
// @DESCRIPTION:
// ============================================================================

namespace Artel
{
  namespace Expression
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    namespace LT = Core::Literal;

    // ===================================================================<CL>=
    // CLASS Visitor
    // ========================================================================

    struct Visitor 
    {
    public:
      // TYPES -----------------------------------------------------------<TY>-
      struct Type
      {
      };
      
    public:
      // DESTRUCTORS -----------------------------------------------------<DS>-
      virtual ~Visitor() = default;

      // FRIEND ACCESSORS ------------------------------------------------<FA>-
      auto virtual VisitValue(const LT::Natural &Value) -> Visitor = 0;

      auto virtual VisitAbstraction(const LT::Character *Argument,
				    const Visitor &Body) -> Visitor = 0;

      auto virtual VisitApplication(const ResultType &Function,
				    const ResultType &Body) -> ResultType = 0;

      auto virtual VisitLet(const LT::Character *Name,
			    const ResultType &Value,
			    const ResultType &Continuation) -> ResultType = 0;
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
  namespace Expression
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


#endif /* INCLUDED_CORE_EXPRESSION_VISITOR */

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
