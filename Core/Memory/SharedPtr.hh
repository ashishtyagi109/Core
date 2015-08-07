// SharedPtr.hh
#ifndef INCLUDED_CORE_MEMORY_SHAREDPTR
#define INCLUDED_CORE_MEMORY_SHAREDPTR

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

#ifndef INCLUDED_CORE_MEMORY_STANDARDALLOCATOR
#include <Core/Memory/StandardAllocator.hh>
#endif /* INCLUDED_CORE_MEMORY_STANDARDALLOCATOR */

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
  namespace Memory
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    using namespace Core::Literal;

    // ===================================================================<CL>=
    // CLASS SharedPtr
    // ========================================================================

    template <typename ElementType>
    struct SharedPtr final
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
      Size *ReferenceCount;

    public:
      // CREATORS --------------------------------------------------------<CR>-
      SharedPtr ();
      SharedPtr (ElementType *Element);
      SharedPtr (ElementType *Element, Size *ReferenceCount);
      SharedPtr (const SharedPtr &Source);
      SharedPtr (SharedPtr &&Source);
      SharedPtr (UniquePtr<ElementType> &&Source);

      // DESTRUCTORS -----------------------------------------------------<DS>-
      ~SharedPtr ();

      // FRIEND ACCESSORS ------------------------------------------------<FA>-
      friend inline constexpr ElementType &Reference (const SharedPtr &Self);
      friend inline ElementType *Get (const SharedPtr &Self);

      // FRIEND MANIPULATORS ---------------------------------------------<FM>-
      friend inline ElementType &Reference (SharedPtr &Self);
      friend inline ElementType *Release (SharedPtr &Self);
      friend inline Void Reset (SharedPtr &Self);
      friend inline Void
      Swap (SharedPtr &SharedPtrOne, SharedPtr &SharedPtrTwo);

      // OPERATORS -------------------------------------------------------<OP>-
      SharedPtr &operator=(SharedPtr &&Source);
      inline ElementType &operator*();
      inline constexpr const ElementType &operator*() const;
      inline ElementType *operator->();
      inline constexpr const ElementType *operator->() const;

      // TRAITS ----------------------------------------------------------<TR>-

    private:
      // NOT IMPLEMENTED -------------------------------------------------<NI>-
    };

    // FREE CREATORS -----------------------------------------------------<FC>-
    template <typename ElementType, typename... ArgumentTypes>
    SharedPtr<ElementType>
    MakeShared (AllocatorProtocol &Allocator, ArgumentTypes... Arguments);

    template <typename ElementType, typename... ArgumentTypes>
    SharedPtr<ElementType> MakeShared (ArgumentTypes... Arguments);

    // FREE OPERATORS ----------------------------------------------------<FO>-
    template <typename ElementType>
    inline constexpr Boolean
    operator==(const SharedPtr<ElementType> &SharedPtrOne,
               const SharedPtr<ElementType> &SharedPtrTwo);

    template <typename ElementType>
    inline constexpr Boolean
    operator!=(const SharedPtr<ElementType> &SharedPtrOne,
               const SharedPtr<ElementType> &SharedPtrTwo);
  }
}


namespace Core
{
  namespace Memory
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    using namespace Core::Literal;
    using namespace Core::MetaFunction;

    // CREATORS ----------------------------------------------------------<CR>-
    template <typename ElementType>
    SharedPtr<ElementType>::SharedPtr ()
      : Element (nullptr), ReferenceCount (new Size (0))
    {
    }

    template <typename ElementType>
    SharedPtr<ElementType>::SharedPtr (ElementType *Element)
      : Element (Element), ReferenceCount (new Size (0))
    {
    }

    template <typename ElementType>
    SharedPtr<ElementType>::SharedPtr (ElementType *Element,
                                       Size *ReferenceCount)
      : Element (Element), ReferenceCount (ReferenceCount)
    {
    }

    template <typename ElementType>
    SharedPtr<ElementType>::SharedPtr (const SharedPtr<ElementType> &Source)
      : Element (Source.Element), ReferenceCount (Source.ReferenceCount)
    {
      (*Source.ReferenceCount)++;
    }

    template <typename ElementType>
    SharedPtr<ElementType>::SharedPtr (SharedPtr<ElementType> &&Source)
      : Element (Source.Element), ReferenceCount (Source.ReferenceCount)
    {
      Source.Element = nullptr;
      Source.ReferenceCount = new Size (0);
    }

    template <typename ElementType>
    SharedPtr<ElementType>::SharedPtr (UniquePtr<ElementType> &&Source)
      : Element (Release (Source)), ReferenceCount (new Size(0))
    {
    }

    // DESTRUCTORS -------------------------------------------------------<DS>-
    template <typename ElementType>
    SharedPtr<ElementType>::~SharedPtr ()
    {
      if (ReferenceCount == 0)
        {
          delete ReferenceCount;
          delete Element;
          ReferenceCount = nullptr;
          Element = nullptr;
        }
    }

    // FRIEND ACCESSORS --------------------------------------------------<FA>-
    template <typename ElementType>
    constexpr ElementType &
    Reference (const SharedPtr<ElementType> &Self)
    {
      return *Self.Element;
    }

    template <typename ElementType>
    ElementType *
    Get (const SharedPtr<ElementType> &Self)
    {
      return Self.Element;
    }

    // FRIEND MANIPULATORS -----------------------------------------------<FM>-
    template <typename ElementType>
    ElementType &
    Reference (SharedPtr<ElementType> &Self)
    {
      return *Self.Element;
    }

    // template <typename ElementType>
    // ElementType *
    // Release (SharedPtr<ElementType> &Self)
    // {
    //   auto Result = Self.Element;
    //   Self.Element = CoreNull;
    //   return Result;
    // }

    // template <typename ElementType>
    // Void
    // Reset (SharedPtr<ElementType> &Self)
    // {
    //   Self.Element = CoreNull;
    // }

    template <typename ElementType>
    Void
    Swap (SharedPtr<ElementType> &SharedPtrOne,
          SharedPtr<ElementType> &SharedPtrTwo)
    {
      auto TemporaryElement = SharedPtrOne.Element;
      SharedPtrOne.Element = SharedPtrTwo.Element;
      SharedPtrTwo.Element = TemporaryElement;
      auto TemporaryReferenceCount = SharedPtrOne.ReferenceCount;
      SharedPtrOne.ReferenceCount = SharedPtrTwo.ReferenceCount;
      SharedPtrTwo.ReferenceCount = TemporaryReferenceCount;
    }

    // OPERATORS ---------------------------------------------------------<OP>-
    template <typename ElementType>
    ElementType &SharedPtr<ElementType>::operator*()
    {
      return *Element;
    }

    template <typename ElementType>
    constexpr const ElementType &SharedPtr<ElementType>::operator*() const
    {
      return *Element;
    }

    template <typename ElementType>
    ElementType *SharedPtr<ElementType>::operator->()
    {
      return Element;
    }

    template <typename ElementType>
    constexpr const ElementType *SharedPtr<ElementType>::operator->() const
    {
      return Element;
    }

    // FREE CREATORS -----------------------------------------------------<FC>-
    template <typename ElementType, typename... ArgumentTypes>
    SharedPtr<ElementType>
    MakeShared (AllocatorProtocol &Allocator, ArgumentTypes... Arguments)
    {
      Byte *Buffer
        = (Byte *) Allocate (Allocator, sizeof (Size) + sizeof (ElementType));
      Size *ReferenceCount = (Size *) (Buffer);
      Void *ElementBuffer = (Void *) (Buffer + sizeof (Size));
      (*ReferenceCount) = 0;
      auto Pointer = new (ElementBuffer)
        ElementType (Forward<ArgumentTypes...> (Arguments)...);
      return SharedPtr<ElementType> (Pointer, ReferenceCount);
    }

    template <typename ElementType, typename... ArgumentTypes>
    SharedPtr<ElementType> MakeShared (ArgumentTypes... Arguments)
    {
      Byte *Buffer
        = (Byte *) Allocate (StandardAllocator, sizeof (Size) + sizeof (ElementType));
      Size *ReferenceCount = (Size *) (Buffer);
      Void *ElementBuffer = (Void *) (Buffer + sizeof (Size));
      (*ReferenceCount) = 0;
      auto Pointer = new (ElementBuffer)
        ElementType (Forward<ArgumentTypes...> (Arguments)...);
      return SharedPtr<ElementType> (Pointer, ReferenceCount);
    }

    // FREE OPERATORS ----------------------------------------------------<FO>-
    template <typename ElementType>
    constexpr Boolean operator==(const SharedPtr<ElementType> &SharedPtrOne,
                                 const SharedPtr<ElementType> &SharedPtrTwo)
    {
      return Get (SharedPtrOne) == Get (SharedPtrTwo);
    }

    template <typename ElementType>
    constexpr Boolean operator!=(const SharedPtr<ElementType> &SharedPtrOne,
                                 const SharedPtr<ElementType> &SharedPtrTwo)
    {
      return Get (SharedPtrOne) != Get (SharedPtrTwo);
    }
  }
}

#endif /* INCLUDED_CORE_MEMORY_SHAREDPTR */

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
