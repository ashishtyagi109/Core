// UniquePtr.hh
#ifndef INCLUDED_CORE_MEMORY_UNIQUEPTR
#define INCLUDED_CORE_MEMORY_UNIQUEPTR

#ifndef INCLUDED_CORE_MEMORY_FORWARD
#include <Core/Memory/Forward.hh>
#endif /* INCLUDED_CORE_MEMORY_FORWARD */

#ifndef INCLUDED_CORE_MEMORY_STANDARDALLOCATOR
#include <Core/Memory/StandardAllocator.hh>
#endif /* INCLUDED_CORE_MEMORY_STANDARDALLOCATOR */

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
      auto constexpr friend inline Reference (const UniquePtr &Self)
        -> ElementType &;
      auto friend inline Get (const UniquePtr &Self) -> ElementType *;

      // FRIEND MANIPULATORS ---------------------------------------------<FM>-
      auto friend inline Reference (UniquePtr &Self) -> ElementType &;
      auto friend inline Release (UniquePtr &Self) -> ElementType *;
      auto friend inline Reset (UniquePtr &Self) -> Void;
      auto friend inline Swap (UniquePtr &UniquePtrOne,
                               UniquePtr &UniquePtrTwo) -> Void;

      // OPERATORS -------------------------------------------------------<OP>-
      auto inline operator=(UniquePtr &&Source) -> UniquePtr &;
      auto inline operator*() -> ElementType &;
      auto inline operator -> () -> ElementType *;
      auto constexpr inline operator*() const -> const ElementType &;
      auto constexpr inline operator -> () const -> const ElementType *;

      // TRAITS ----------------------------------------------------------<TR>-

    private:
      // NOT IMPLEMENTED -------------------------------------------------<NI>-
      UniquePtr (const UniquePtr &Source) = delete;
      auto operator=(const UniquePtr &Source) -> UniquePtr & = delete;
    };

    // FREE CREATORS -----------------------------------------------------<FC>-
    template <typename ElementType, typename... ArgumentTypes>
    auto MakeUnique (AllocatorProtocol &Allocator,
                     ArgumentTypes... Arguments) -> UniquePtr<ElementType>;

    template <typename ElementType, typename... ArgumentTypes>
    auto MakeUnique (ArgumentTypes... Arguments) -> UniquePtr<ElementType>;

    // FREE OPERATORS ----------------------------------------------------<FO>-
    template <typename ElementType>
    inline constexpr auto
    operator==(const UniquePtr<ElementType> &UniquePtrOne,
               const UniquePtr<ElementType> &UniquePtrTwo) -> Boolean;

    template <typename ElementType>
    inline constexpr auto
    operator!=(const UniquePtr<ElementType> &UniquePtrOne,
               const UniquePtr<ElementType> &UniquePtrTwo) -> Boolean;
  }
}

// =======================================================================<IM>=
// IMPLEMENTATION
// ============================================================================

namespace Core
{
  namespace Memory
  {
    // CREATORS ----------------------------------------------------------<CR>-
    template <typename ElementType>
    constexpr UniquePtr<ElementType>::UniquePtr ()
      : Element (nullptr)
    {
    }

    template <typename ElementType>
    constexpr UniquePtr<ElementType>::UniquePtr (ElementType *Element)
      : Element (Element)
    {
    }

    template <typename ElementType>
    UniquePtr<ElementType>::UniquePtr (UniquePtr<ElementType> &&Source)
      : Element (Source.Element)
    {
      Source.Element = nullptr;
    }

    // DESTRUCTORS -------------------------------------------------------<DS>-
    template <typename ElementType>
    UniquePtr<ElementType>::~UniquePtr ()
    {
      delete Element;
    }

    // FRIEND ACCESSORS --------------------------------------------------<FA>-
    template <typename ElementType>
    constexpr ElementType &
    Reference (const UniquePtr<ElementType> &Self)
    {
      return *Self.Element;
    }

    template <typename ElementType>
    ElementType *
    Get (const UniquePtr<ElementType> &Self)
    {
      return Self.Element;
    }

    // FRIEND MANIPULATORS -----------------------------------------------<FM>-
    template <typename ElementType>
    ElementType &
    Reference (UniquePtr<ElementType> &Self)
    {
      return *Self.Element;
    }

    template <typename ElementType>
    ElementType *
    Release (UniquePtr<ElementType> &Self)
    {
      auto Result = Self.Element;
      Self.Element = CoreNull;
      return Result;
    }

    template <typename ElementType>
    Void
    Reset (UniquePtr<ElementType> &Self)
    {
      Self.Element = CoreNull;
    }

    template <typename ElementType>
    Void
    Swap (UniquePtr<ElementType> &UniquePtrOne,
          UniquePtr<ElementType> &UniquePtrTwo)
    {
      auto TemporaryElement = UniquePtrOne.Element;
      UniquePtrOne.Element = UniquePtrTwo.Element;
      UniquePtrTwo.Element = TemporaryElement;
    }

    // OPERATORS ---------------------------------------------------------<OP>-
    template <typename ElementType>
    ElementType &UniquePtr<ElementType>::operator*()
    {
      return *Element;
    }

    template <typename ElementType>
    auto constexpr UniquePtr<ElementType>::
    operator*() const -> const ElementType &
    {
      return *Element;
    }

    template <typename ElementType>
    ElementType *UniquePtr<ElementType>::operator->()
    {
      return Element;
    }

    template <typename ElementType>
    auto constexpr UniquePtr<ElementType>::
    operator -> () const -> const ElementType *
    {
      return Element;
    }

    // FREE CREATORS -----------------------------------------------------<FC>-
    template <typename ElementType, typename... ArgumentTypes>
    UniquePtr<ElementType>
    MakeUnique (AllocatorProtocol &Allocator, ArgumentTypes... Arguments)
    {
      auto Pointer = new (Allocator)
        ElementType (Forward<ArgumentTypes...> (Arguments)...);
      return UniquePtr<ElementType> (Pointer);
    }

    template <typename ElementType, typename... ArgumentTypes>
    UniquePtr<ElementType> MakeUnique (ArgumentTypes... Arguments)
    {
      auto Pointer = new (StandardAllocator)
        ElementType (Forward<ArgumentTypes...> (Arguments)...);
      return UniquePtr<ElementType> (Pointer);
    }

    // FREE OPERATORS ----------------------------------------------------<FO>-
    template <typename ElementType>
    constexpr Boolean operator==(const UniquePtr<ElementType> &UniquePtrOne,
                                 const UniquePtr<ElementType> &UniquePtrTwo)
    {
      return Get (UniquePtrOne) == Get (UniquePtrTwo);
    }

    template <typename ElementType>
    constexpr Boolean operator!=(const UniquePtr<ElementType> &UniquePtrOne,
                                 const UniquePtr<ElementType> &UniquePtrTwo)
    {
      return Get (UniquePtrOne) != Get (UniquePtrTwo);
    }
  }
}

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
