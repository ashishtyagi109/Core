// Sequence.hh
#ifndef INCLUDED_CORE_COLLECTION_SEQUENCE
#define INCLUDED_CORE_COLLECTION_SEQUENCE

#ifndef INCLUDED_CORE_COLLECTION_ARRAY
#include <Core/Collection/Array.hh>
#endif /* INCLUDED_CORE_COLLECTION_ARRAY */

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

#ifndef INCLUDED_CORE_MEMORY_SHAREDPTR
#include <Core/Memory/SharedPtr.hh>
#endif /* INCLUDED_CORE_MEMORY_SHAREDPTR */

// =======================================================================<DC>=
// @PURPOSE:
// @CLASSES:
// @MACROS:
// @SEE_ALSO:
// @DESCRIPTION:
// ============================================================================

namespace Core
{
  namespace Collection
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    using namespace Core::Literal;
    using namespace Core::Memory;

    // ===================================================================<CL>=
    // CLASS Sequence
    // ========================================================================

    template <typename ElementType>
    struct Sequence final
    {
    public:
      struct Constant
      {
        constexpr const static Real GrowthFactor = 1.5;
      };

      // TYPES -----------------------------------------------------------<TY>-
      struct Type
      {
        using Element = ElementType;
      };

    private:
      // DATA ------------------------------------------------------------<DT>-
      ElementType *Buffer;
      Size Count;
      Size Capacity;

    public:
      // CREATORS --------------------------------------------------------<CR>-
      Sequence (const SharedPtr<AllocatorProtocol> &Allocator);

      Sequence (Size DynamicBufferSize,
                const SharedPtr<AllocatorProtocol> &Allocator);

      template <typename... ElementTypes>
      constexpr Sequence (ElementTypes... Elements);

      // DESTRUCTORS -----------------------------------------------------<DS>-
      ~Sequence ();

      // FRIEND ACCESSORS ------------------------------------------------<FA>-
      auto constexpr friend inline Count (const Sequence &) -> Size;

      auto constexpr friend inline Capacity (const Sequence &) -> Size;

      // FRIEND MANIPULATORS ---------------------------------------------<FM>-
      auto friend Resize (Sequence &Self, Size NewSize) -> Void;

      auto friend Resize (const Sequence &Self, Size NewSize) -> Sequence;

      template <Size BatchSize>
      auto friend Insert (Sequence &Self,
                          Size Index,
                          const Array<BatchSize, ElementType> &Elements) -> Void;

      template <Size BatchSize>
      auto friend Insert (Sequence &Self,
                          Size Index,
                          Array<BatchSize, ElementType> &&Elements) -> Void;

      template <Size BatchSize>
      auto friend Splice (Array<BatchSize, ElementType> &Destination,
                          const Sequence &Self,
                          Size Inex) -> Void;

      template <Size BatchSize>
      auto friend Splice (Array<BatchSize, ElementType> &Destination,
                          Sequence &Self,
                          Size Index) -> Void;

      // OPERATORS -------------------------------------------------------<OP>-
      auto constexpr inline operator[](Size Index) const -> const ElementType &;

      auto inline operator[](Size Index) -> ElementType &;

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
  namespace Collection
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    // USING TYPES -------------------------------------------------------<UT>-
    // CREATORS ----------------------------------------------------------<CR>-
    template <typename FirstElementType, typename... ElementTypes>
    auto constexpr inline MakeSequence (FirstElementType Element,
                                        ElementTypes... Elements)
      -> Sequence<FirstElementType>;

    template <typename FirstElementType, typename... ElementTypes>
    auto constexpr inline MakeSequence (
      const SharedPtr<AllocatorProtocol> &Allocator,
      FirstElementType Element,
      ElementTypes... Elements)
      -> Sequence<FirstElementType>;

    // DESTRUCTORS -------------------------------------------------------<DS>-
    // ACCESSORS ---------------------------------------------------------<AC>-
    // MANIPULATORS ------------------------------------------------------<MA>-
    // OPERATORS ---------------------------------------------------------<OP>-
  }
}

#endif /* INCLUDED_CORE_COLLECTION_SEQUENCE */

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
