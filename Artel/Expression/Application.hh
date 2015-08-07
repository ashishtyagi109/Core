// Application.ah
#ifndef INCLUDED_ARTEL_EXPRESSION_APPLICATION
#define INCLUDED_ARTEL_EXPRESSION_APPLICATION

#ifndef INCLUDED_ARTEL_EXPRESSION_PROTOCOL
#include <Artel/Expression/Protocol.hh>
#endif /* INCLUDED_ARTEL_EXPRESSION_PROTOCOL */

#ifndef INCLUDED_CORE_MEMORY_FORWARD
#include <Core/Memory/Forward.hh>
#endif /* INCLUDED_CORE_MEMORY_FORWARD */

#ifndef INCLUDED_CORE_MEMORY_MOVE
#include <Core/Memory/Move.hh>
#endif /* INCLUDED_CORE_MEMORY_MOVE */

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

namespace Artel
{
  namespace Expression
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    namespace EX = Artel::Expression;
    namespace MY = Core::Memory;

    // ===================================================================<CL>=
    // CLASS Application
    // ========================================================================
    
    struct Application final
    {
    public:
      // TYPES -----------------------------------------------------------<TY>-
      struct Type
      {
      };
      
    private:
      // DATA ------------------------------------------------------------<DT>-
      MY::UniquePtr<EX::Protocol> Function;
      MY::UniquePtr<EX::Protocol> Argument;
      
    public:
      // CREATORS --------------------------------------------------------<CR>-
      Application (MY::UniquePtr<EX::Protocol> &&Function,
		   MY::UniquePtr<EX::Protocol> &&Argument);

      // DESTRUCTORS -----------------------------------------------------<DS>-
      ~Application() = default;

      // FRIEND ACCESSORS ------------------------------------------------<FA>-
      auto constexpr inline friend Function (const Application &) -> const EX::Protocol &;

      auto constexpr inline friend Argument (const Application &) -> const EX::Protocol &;

      // FRIEND MANIPULATORS ---------------------------------------------<FM>-
      auto inline friend Function (Application &) -> EX::Protocol &;

      auto inline friend Argument (Application &) -> EX::Protocol &;

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

namespace Artel
{
  namespace Expression
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    namespace EX = Artel::Expression;
    namespace MY = Core::Memory;
    using namespace Core::Memory;

    // CREATORS ----------------------------------------------------------<CR>-
    Application::Application(MY::UniquePtr<EX::Protocol> &&Function,
			     MY::UniquePtr<EX::Protocol> &&Argument)
      : Function(Forward<MY::UniquePtr<EX::Protocol> &>(Function)),
	Argument(Forward<MY::UniquePtr<EX::Protocol> &>(Argument))
    {
    }

    // DESTRUCTORS -------------------------------------------------------<DS>-
    // ACCESSORS ---------------------------------------------------------<AC>-
    auto constexpr inline Function (const Application &Self) -> const EX::Protocol &
    {
      return Reference (Self.Function);
    }

    auto constexpr inline Argument (const Application &Self) -> const EX::Protocol &
    {
      return Reference (Self.Argument);
    }

    // MANIPULATORS ------------------------------------------------------<MA>-
    auto inline Function (Application &Self) -> EX::Protocol &
    {
      return Reference (Self.Function);
    }

    auto inline Argument (Application &Self) -> EX::Protocol &
    {
      return Reference (Self.Argument);
    }

    // OPERATORS ---------------------------------------------------------<OP>-
  }
}


#endif /* INCLUDED_CORE_EXPRESSION_APPLICATION */

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
