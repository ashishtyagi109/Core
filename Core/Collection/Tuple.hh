// Tuple.hh
#ifndef INCLUDED_CORE_COLLECTION_TUPLE
#define INCLUDED_CORE_COLLECTION_TUPLE

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

#ifndef INCLUDED_CORE_MEMORY_MOVE
#include <Core/Memory/Move.hh>
#endif /* INCLUDED_CORE_MEMORY_MOVE */

#ifndef INCLUDED_CORE_METAFUNCTION_TYPELIST
#include <Core/MetaFunction/TypeList.hh>
#endif /* INCLUDED_CORE_METAFUNCTION_TYPELIST */

// =======================================================================<DC>=
// @PURPOSE:
// @CLASSES:
// @MACROS:
// @SEE_ALSO:
// @DESCRIPTION:
// ============================================================================

namespace
{
  template <typename ElementType>
  struct TupleImp;
  
  
  template <typename TypeList>
  struct TupleImp
  {

  };
  
  template <>
  struct TupleImp<Void>
  {
  };
}

namespace Core
{
  namespace Collection
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    using namespace Core::Literal;
    namespace MF = Core::MetaFunction;

    // ===================================================================<CL>=
    // CLASS Tuple
    // ========================================================================

    template <typename TypeList>
    struct TupleImpl final
    {
    public:
      // TYPES -----------------------------------------------------------<TY>-
      struct Type
      {
        using List = TypeList;
      };

    private:
      using HeadType = MF::Head<TypeList>;
      using TailType = MF::Tail<TypeList>;

      // DATA ------------------------------------------------------------<DT>-
      HeadType Head;
      Tuple<TailType> Tail;

    public:
      // CREATORS --------------------------------------------------------<CR>-
      constexpr TupleImpl ();

      constexpr TupleImpl (HeadType Head, TupleImpl<TailType> Tail);

      constexpr TupleImpl (const TupleImpl &Source);

      TupleImpl (TupleImpl &&Source);

      // DESTRUCTORS -----------------------------------------------------<DS>-
      ~TupleImpl () = default;

      // FRIEND ACCESSORS ------------------------------------------------<FA>-

      // FRIEND MANIPULATORS ---------------------------------------------<FM>-

      // TRAITS ----------------------------------------------------------<TR>-

    private:
      // NOT IMPLEMENTED -------------------------------------------------<NI>-
    };

    // FREE CREATORS -----------------------------------------------------<FC>-
    template <typename... ElementTypes>
    auto constexpr MakeTuple (ElementTypes... Elements)
      -> Tuple<ElementTypes...>;

    // ACCESSORS ---------------------------------------------------------<AC>-
    template <Size ElementIndex, typename... ElementTypes>
    auto constexpr inline Index (const Tuple<ElementTypes...> &Self)
      -> const MF::Index<MF::TypeList<ElementTypes...>, ElementIndex> &;

    // MANIPULATORS ------------------------------------------------------<MA>-
    template <Size ElementIndex, typename... ElementTypes>
    auto inline Index (Tuple<ElementTypes...> &Self)
      -> MF::Index<MF::TypeList<ElementTypes...>, ElementIndex> &;

    // FREE OPERATORS ----------------------------------------------------<FO>-
    template <typename... ElementTypes>
    auto constexpr inline
    operator==(const Tuple<ElementTypes...> &TupleOne,
               const Tuple<ElementTypes...> &TupleTwo) -> Boolean;

    template <typename... ElementTypes>
    auto constexpr inline
    operator!=(const Tuple<ElementTypes...> &TupleOne,
               const Tuple<ElementTypes...> &TupleTwo) -> Boolean;
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
    using namespace Core::Literal;
    using namespace Core::Memory;
    namespace MF = Core::MetaFunction;
    // USING TYPES -------------------------------------------------------<UT>-
    // CREATORS ----------------------------------------------------------<CR>-
    template <typename... ElementTypes>
    constexpr Tuple<ElementTypes...>::Tuple ()
      : Head (), Tail ()
    {
    }

    template <typename FirstElementType, typename... ElementTypes>
    constexpr Tuple<FirstElementType, ElementTypes...>::Tuple (
      FirstElementType FirstElement,
      ElementTypes... Elements)
      : Head (FirstElement), Tail (Elements...)
    {
    }

    template <typename FirstElementType, typename... ElementTypes>
    constexpr Tuple<FirstElementType, ElementTypes...>::Tuple (
      const Tuple &Source)
      : Head (Head (Source)), Tail (Tail (Source))
    {
    }

    Tuple (Tuple &&Source);

    // DESTRUCTORS -----------------------------------------------------<DS>-
    ~Tuple () = default;

    // FRIEND ACCESSORS ------------------------------------------------<FA>-
    auto constexpr friend inline Head (const Tuple &Self)
      -> const FirstElementType &;

    auto constexpr friend inline Tail (const Tuple &Self)
      -> const Tuple<ElementTypes...> &;

    // FRIEND MANIPULATORS ---------------------------------------------<FM>-
    auto friend inline Head (Tuple &Self) -> FirstElementType &;

    auto friend inline Tail (Tuple &Self) -> Tuple<ElementTypes...> &;
    // DESTRUCTORS -------------------------------------------------------<DS>-
    // ACCESSORS ---------------------------------------------------------<AC>-
    // MANIPULATORS ------------------------------------------------------<MA>-
    // OPERATORS ---------------------------------------------------------<OP>-
  }
}

#endif /* INCLUDED_CORE_COLLECTION_TUPLE */

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
