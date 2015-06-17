// UniquePtr.hh
#ifndef INCLUDED_CORE_MEMORY_UNIQUEPTR
#define INCLUDED_CORE_MEMORY_UNIQUEPTR

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

#ifndef INCLUDED_CORE_MEMORY_ALLOCATORPROTOCOL
#include <Core/Memory/AllocatorProtocol.hh>
#endif /* INCLUDED_CORE_MEMORY_ALLOCATORPROTOCOL */

// =======================================================================<DC>=
// @PURPOSE:
// @CLASSES:
// @MACROS:
// @SEE_ALSO:
// @DESCRIPTION:
// ============================================================================

namespace Core
{
  namespace Memory
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    using namespace Core::Literal;
    // USING TYPES -------------------------------------------------------<UT>-
    // ===================================================================<CL>=
    // CLASS UniquePtr
    // ========================================================================
    template <typename ElementType>
    struct UniquePtr final
    {
    public:
      // TYPES -----------------------------------------------------------<TY>-
      struct Type
      {
        using Element = ElementType;
      };

    private:
      // DATA ------------------------------------------------------------<DT>-
      ElementType *Element;

    public:
      // CREATORS --------------------------------------------------------<CR>-
      constexpr UniquePtr ();
      constexpr UniquePtr (ElementType *Element);
      UniquePtr (UniquePtr &&Source);
      // DESTRUCTORS -----------------------------------------------------<DS>-
      ~UniquePtr ();
      // FRIEND ACCESSORS ------------------------------------------------<FA>-
      friend inline constexpr ElementType &Reference (const UniquePtr &Self);
      friend inline ElementType *Get (const UniquePtr &Self);
      // FRIEND MANIPULATORS ---------------------------------------------<FM>-
      friend inline ElementType &Reference (UniquePtr &Self);
      friend inline ElementType *Release (UniquePtr &Self);
      friend inline Void Reset (UniquePtr &Self);
      friend inline Void
      Swap (UniquePtr &UniquePtrOne, UniquePtr &UniquePtrTwo);
      // OPERATORS -------------------------------------------------------<OP>-
      UniquePtr &operator=(UniquePtr &&Source);
      inline ElementType &operator*();
      inline constexpr ElementType &operator*() const;
      inline ElementType *operator->();
      inline constexpr ElementType *operator->() const;
      // TRAITS ----------------------------------------------------------<TR>-

    private:
      // NOT IMPLEMENTED -------------------------------------------------<NI>-
      UniquePtr (const UniquePtr &Source) = delete;
      UniquePtr &operator=(const UniquePtr &Source) = delete;
    };

    // FREE CREATORS -----------------------------------------------------<FC>-
    template <typename ElementType, typename... ArgumentTypes>
    UniquePtr<ElementType>
    MakeUnique (AllocatorProtocol &Allocator, ArgumentTypes... Arguments);

    template <typename ElementType, typename... ArgumentTypes>
    UniquePtr<ElementType> MakeUnique (ArgumentTypes... Arguments);
    // FREE DESTRUCTORS --------------------------------------------------<FD>-
    // ACCESSORS ---------------------------------------------------------<AC>-
    // MANIPULATORS ------------------------------------------------------<MA>-
    // FREE OPERATORS ----------------------------------------------------<FO>-
    template <typename ElementType>
    inline constexpr Boolean
    operator==(const UniquePtr<ElementType> &UniquePtrOne,
               const UniquePtr<ElementType> &UniquePtrTwo);

    template <typename ElementType>
    inline constexpr Boolean
    operator!=(const UniquePtr<ElementType> &UniquePtrOne,
               const UniquePtr<ElementType> &UniquePtrTwo);
  }
}

// IMPLEMENTATION --------------------------------------------------------<IM>-
#include <Core/Memory/UniquePtr.mm>

#endif /* INCLUDED_CORE_MEMORY_UNIQUEPTR */

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
