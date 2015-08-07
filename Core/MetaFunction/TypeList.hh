// TypeList.hh
#ifndef INCLUDED_CORE_METAFUNCTION_TYPELIST
#define INCLUDED_CORE_METAFUNCTION_TYPELIST

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

namespace
{
  using namespace Core::Literal;

  template <typename TypeList, Size Index>
  struct IndexImp;
}

namespace Core
{
  namespace MetaFunction
  {
    using namespace Core::Literal;

    template <typename... ElementTypes>
    struct TypeList;

    template <>
    struct TypeList<>
    {
    };
    
    template <typename HeadType, typename... TailTypes>
    struct TypeList<HeadType, TailTypes...>
    {
      using Head = HeadType;
      using Tail = TypeList<TailTypes...>;
    };

    template <typename TypeList>
    using Head = typename TypeList::Head;

    template <typename TypeList>
    using Tail = typename TypeList::Tail;

    template <typename TypeList, Size Index>
    using Index = typename IndexImp<TypeList, Index>::Type;
  }
}

// ============================================================================
// IMPLEMENTATION
// ============================================================================

namespace
{
  using namespace Core::Literal;
  using namespace Core::MetaFunction;

  template <typename TypeList>
  struct IndexImp<TypeList, 0>
  {
    using Type = Head<TypeList>;
  };

  template <typename TypeList, Size Index>
  struct IndexImp
  {
    using Type = typename IndexImp<Tail<TypeList>, Index - 1>::Type;
  };
}

#endif /* INCLUDED_CORE_METAFUNCTION_TYPELIST */
