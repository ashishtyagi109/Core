// Expression.hh
#ifndef INCLUDED__EXPRESSION_
#define INCLUDED__EXPRESSION_

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

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

namespace Artel {

namespace LT = Core::Literal;
namespace MY = Core::Memory;

struct Value {
public:
  enum class Variant { Natural, Integer, Real };

  using Natural = LT::Natural64;
  using Integer = LT::Integer64;
  using Real    = LT::Real64;

private:
  Variant Variant;
  union {
    Natural Natural;
    Integer Integer;
    Real Real;
  } Data;

public:
  template<enum Variant Variant>
  Value();
};

struct Expression {
public:
  enum class Variant { Value, Application, Abstraction, Let };

  struct Value {};

  struct Application {
  private:
    MY::UniquePtr<Expression> Function;
    MY::UniquePtr<Expression> Argument;

  public:
    Application(MY::UniquePtr<Expression> &&Function,
                MY::UniquePtr<Expression> &&Argument);

    ~Application() = default;

    auto constexpr friend Function(const Application &Self)
        -> const Expression &;

    auto constexpr friend Argument(const Application &Self)
        -> const Expression &;
  };

  struct Abstraction {};

  struct Let {};
};
}

namespace {
namespace Expression {
// USING NAMESPACES --------------------------------------------------<UN>-
// USING TYPES -------------------------------------------------------<UT>-
// ===================================================================<CL>=
// CLASS
// ========================================================================

struct final {
public:
  // TYPES -----------------------------------------------------------<TY>-
  struct Type {};

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

namespace Core {
namespace Expression {
// USING NAMESPACES --------------------------------------------------<UN>-
// USING TYPES -------------------------------------------------------<UT>-
// CREATORS ----------------------------------------------------------<CR>-
// DESTRUCTORS -------------------------------------------------------<DS>-
// ACCESSORS ---------------------------------------------------------<AC>-
// MANIPULATORS ------------------------------------------------------<MA>-
// OPERATORS ---------------------------------------------------------<OP>-
}
}

#endif /* INCLUDED_CORE_EXPRESSION_ */

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
