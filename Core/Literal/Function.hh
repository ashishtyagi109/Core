// Function.hh
#ifndef INCLUDED_CORE_LITERAL_FUNCTION
#define INCLUDED_CORE_LITERAL_FUNCTION

#ifndef INCLUDED_CORE_MEMORY_UNIQUEPTR
#include <Core/Memory/UniquePtr.hh>
#endif /* INCLUDED_CORE_MEMORY_UNIQUEPTR */

// =======================================================================<DC>=
// @PURPOSE:
// @CLASSES:
// @MACROS:
// @SEE_ALSO:
// @DESCRIPTION:
// ============================================================================

namespace Core
{
  namespace Literal
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    using namespace Core::Memory;
    // USING TYPES -------------------------------------------------------<UT>-

    // ===================================================================<CL>=
    // CLASS Function Protocol
    // ========================================================================

    template <typename ResultType, typename... ArgumentTypes>
    struct FunctionProtocol;

    template <typename ResultType, typename... ArgumentTypes>
    struct FunctionProtocol<ResultType (ArgumentTypes...)>
    {
    public:
      virtual ~FunctionProtocol ()
      {
      }

      virtual ResultType operator()(ArgumentTypes... Arguments) = 0;
    };

    // ===================================================================<CL>=
    // CLASS Lambda Function
    // ========================================================================

    template <typename LambdaType, typename ResultType, typename... ArgumentTypes>
    struct LambdaFunction;

    template <typename LambdaType, typename ResultType, typename... ArgumentTypes>
    struct LambdaFunction<LambdaType, ResultType (ArgumentTypes...)> final
      : FunctionProtocol<ResultType (ArgumentTypes...)>
    {
    private:
      LambdaType Lambda;

    public:
      LambdaFunction (LambdaType Lambda) : Lambda (Lambda)
      {
      }

      inline virtual ResultType operator()(ArgumentTypes... Arguments)
      {
        return Lambda (Arguments...);
      }
    };

    // ===================================================================<CL>=
    // CLASS Function
    // ========================================================================

    template <typename ResultType, typename... ArgumentTypes>
    struct Function;

    template <typename ResultType, typename... ArgumentTypes>
    struct Function<ResultType (ArgumentTypes...)> final
    {
    public:
      // TYPES -----------------------------------------------------------<TY>-
      struct Type
      {
        using Result = ResultType;
      };

    private:
      // PRIVATE TYPES ---------------------------------------------------<PT>-
      // CLASS DATA ------------------------------------------------------<CD>-
      // DATA ------------------------------------------------------------<DT>-
      UniquePtr<FunctionProtocol<ResultType (ArgumentTypes...)>> Implementation;
      // FRIENDS ---------------------------------------------------------<FR>-
      // PRIVATE CREATORS ------------------------------------------------<PC>-
      // PRIVATE MANIPULATORS --------------------------------------------<PM>-
      // PRIVATE ACCESSORS -----------------------------------------------<PA>-

    public:
      // CREATORS --------------------------------------------------------<CR>-
      Function () : Implementation ()
      {
      }

      template <typename LambdaType>
      Function (LambdaType Source)
        : Implementation (
            UniquePtr<FunctionProtocol<ResultType (ArgumentTypes...)>> (
              new LambdaFunction<LambdaType, ResultType (ArgumentTypes...)> (
                Source)))
      {
      }

      Function (const Function &Source);

      Function (Function &&Source);

      inline ResultType operator()(ArgumentTypes... Arguments)
      {
        return (*Implementation)(Arguments...);
      }
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

// IMPLEMENTATION --------------------------------------------------------<IM>-

#endif /* INCLUDED_CORE_LITERAL_FUNCTION */

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
