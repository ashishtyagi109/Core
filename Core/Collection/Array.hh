// Array.hh
#ifndef INCLUDED_CORE_COLLECTION_ARRAY
#define INCLUDED_CORE_COLLECTION_ARRAY

#ifndef INCLUDED_CORE_LITERAL
#include <Core/Literal.hh>
#endif /* INCLUDED_CORE_LITERAL */

#ifndef INCLUDED_CORE_METAFUNCTION_ARGUMENTTYPES
#include <Core/MetaFunction/ArgumentTypes.hh>
#endif /* INCLUDED_CORE_METAFUNCTION_ARGUMENTTYPES */

#ifndef INCLUDED_CORE_METAFUNCTION_RETURNTYPE
#include <Core/MetaFunction/ReturnType.hh>
#endif /* INCLUDED_CORE_METAFUNCTION_RETURNTYPE */

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
    using namespace Core::MetaFunction;
    // USING TYPES -------------------------------------------------------<UT>-
    // ===================================================================<CL>=
    // CLASS Array
    // ========================================================================

    template <Size Count, typename ElementType>
    struct Array final
    {
    public:
      // TYPES -----------------------------------------------------------<TY>-
      struct Type
      {
        using Element = ElementType;
      };

    public:
      // PRIVATE TYPES ---------------------------------------------------<PT>-
      // CLASS DATA ------------------------------------------------------<CD>-
      ElementType Elements[Count];
      // DATA ------------------------------------------------------------<DT>-
      // FRIENDS ---------------------------------------------------------<FR>-
      // PRIVATE CREATORS ------------------------------------------------<PC>-
      // PRIVATE MANIPULATORS --------------------------------------------<PM>-
      // PRIVATE ACCESSORS -----------------------------------------------<PA>-

    public:
      // CREATORS --------------------------------------------------------<CR>-
      // DESTRUCTORS -----------------------------------------------------<DS>-
      // FRIEND ACCESSORS ------------------------------------------------<FA>-
      friend constexpr auto Index (const Array &Self,
                                   Size Index) -> const ElementType &;
      // FRIEND MANIPULATORS ---------------------------------------------<FM>-
      friend auto Index (Array &Self, Size Index) -> ElementType &;
      friend auto Update (Array &Self,
                          Size Index,
                          const ElementType &Element) -> Void;
      friend auto Update (Array &Self,
                          Size Index,
                          ElementType &&Element) -> Void;
      // OPERATORS -------------------------------------------------------<OP>-
      auto operator[](Size Index) -> ElementType &;
      constexpr auto operator[](Size Index) const -> const ElementType &;
      // TRAITS ----------------------------------------------------------<TR>-

    private:
      // NOT IMPLEMENTED -------------------------------------------------<NI>-
    };

    // FREE CREATORS -----------------------------------------------------<FC>-
    template <typename ElementType, typename... ElementTypes>
    auto MakeArray (ElementType Element, ElementTypes... Elements)
      -> Array<1 + sizeof...(ElementTypes), ElementType>;
    // FREE DESTRUCTORS --------------------------------------------------<FD>-
    // ACCESSORS ---------------------------------------------------------<AC>-
    // MANIPULATORS ------------------------------------------------------<MA>-
    template <Size Count, typename FunctionType>
    inline auto ForEach (Array<Count, ArgumentType<FunctionType, 0>> &Self,
                         FunctionType Function) -> Void;

    template <Size Count, typename FunctionType>
    inline auto ForEach (const Array<Count, ArgumentType<FunctionType, 0>> &Self,
                         FunctionType Function) -> Void;

    template <Size Count, typename FunctionType>
    inline auto Map (const Array<Count, ArgumentType<FunctionType, 0>> &Self,
                     FunctionType Function)
      -> Array<Count, ReturnType<FunctionType>>;

    template <Size Count, typename FunctionType>
    inline auto FoldLeft (
      const Array<Count, ArgumentType<FunctionType, 1>> &Self,
      ArgumentType<FunctionType, 0> Initial,
      FunctionType Function) -> ReturnType<FunctionType>;

    template <Size Count, typename FunctionType>
    inline auto FoldRight (
      const Array<Count, ArgumentType<FunctionType, 1>> &Self,
      ArgumentType<FunctionType, 0> Initial,
      FunctionType Function) -> ReturnType<FunctionType>;

    template <Size Count, typename FunctionType>
    inline auto Concatenate (
      const Array<Count, ArgumentType<FunctionType, 0>> &Self,
      FunctionType) -> ReturnType<FunctionType>;

    // FREE OPERATORS ----------------------------------------------------<FO>-
  }
}

// =======================================================================<IM>=
// IMPLEMENTATION
// ============================================================================
namespace Core
{
  namespace Collection
  {
    using namespace Core::Literal;

    template <Size Count, typename FunctionType>
    inline auto ForEach (Array<Count, ArgumentType<FunctionType, 0>> &Self,
                         FunctionType Function) -> Void
    {
      for (Size Index = 0; Index < Count; Index++)
        {
          Function (Self[Index]);
        }
    }

    template <Size Count, typename FunctionType>
    inline auto ForEach (const Array<Count, ArgumentType<FunctionType, 0>> &Self,
                         FunctionType Function) -> Void
    {
      for (Size Index = 0; Index < Count; Index++)
        {
          Function (Self[Index]);
        }
    }

    template <Size Count, typename FunctionType>
    inline auto Map (const Array<Count, ArgumentType<FunctionType, 0>> &Self,
                     FunctionType Function)
      -> Array<Count, ReturnType<FunctionType>>
    {
      Array<Count, ReturnType<FunctionType>> Result;
      for (Size Index = 0; Index < Count; Index++)
        {
          Result[Index] = Function (Self[Index]);
        }
      return Result;
    }

    template <Size Count, typename FunctionType>
    inline auto FoldLeft (
      const Array<Count, ArgumentType<FunctionType, 1>> &Self,
      ArgumentType<FunctionType, 0> Initial,
      FunctionType Function) -> ReturnType<FunctionType>
    {
      for (Size Index = 0; Index < Count; Index++)
        {
          Initial = Function (Initial, Self[Index]);
        }
      return Initial;
    }

    template <Size Count, typename FunctionType>
    inline auto FoldRight (
      const Array<Count, ArgumentType<FunctionType, 1>> &Self,
      ArgumentType<FunctionType, 0> Initial,
      FunctionType Function) -> ReturnType<FunctionType>
    {
      for (Size Index = 0; Index < Count; Index++)
        {
          Initial = Function (Initial, Self[Count - Index]);
        }
      return Initial;
    }

    template <Size Count, typename FunctionType>
    inline auto Concatenate (
      const Array<Count, ArgumentType<FunctionType, 0>> &Self,
      FunctionType Function) -> ReturnType<FunctionType>
    {
      auto Result = Self[0];
      for (Size Index = 1; Index < Count; Index ++)
	{
	  Result = Function(Result, Self[Index]);
	}
      return Result;
    }

    template <Size Count, typename ElementType>
    constexpr const ElementType &
    Index (const Array<Count, ElementType> &Self, Size Index)
    {
      return Self.Elements[Index];
    }

    template <Size Count, typename ElementType>
    ElementType &
    Index (Array<Count, ElementType> &Self, Size Index)
    {
      return Self.Elements[Index];
    }

    template <Size Count, typename ElementType>
    Void
    Update (Array<Count, ElementType> &Self,
            Size Index,
            const ElementType &Element)
    {
      Self.Elements[Index] = Element;
    }

    template <Size Count, typename ElementType>
    Void
    Update (Array<Count, ElementType> &Self, Size Index, ElementType &&Element)
    {
      Self.Elements[Index] = Move (Element);
    }

    template <Size Count, typename ElementType>
    ElementType &Array<Count, ElementType>::operator[](Size Index)
    {
      return Elements[Index];
    }

    template <Size Count, typename ElementType>
    constexpr const ElementType &Array<Count, ElementType>::
    operator[](Size Index) const
    {
      return Elements[Index];
    }

    template <typename ElementType, typename... ElementTypes>
    Array<1 + sizeof...(ElementTypes), ElementType>
    MakeArray (ElementType Element, ElementTypes... Elements)
    {
      return Array<1 + sizeof...(ElementTypes), ElementType>{
        {Element, static_cast<ElementType> (Elements)...}};
    }
  }
}
#endif /* INCLUDED_CORE_COLLECTION_ARRAY */

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
