// ArgumentTypes.hh
#ifndef INCLUDED_CORE_METAFUNCTION_ARGUMENTTYPES
#define INCLUDED_CORE_METAFUNCTION_ARGUMENTTYPES

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

#ifndef INCLUDED_CORE_METAFUNCTION_TYPELIST
#include <Core/MetaFunction/TypeList.hh>
#endif /* INCLUDED_CORE_METAFUNCTION_TYPELIST */

namespace
{
  template <typename CallableType>
  struct ArgumentTypesImp;
}

namespace Core
{
  namespace MetaFunction
  {
    using namespace Core::Literal;

    template <typename CallableType>
    using ArgumentTypes =
      typename ArgumentTypesImp<decltype (&CallableType::operator())>::Types;

    template <typename CallableType, Size TypeIndex>
    using ArgumentType = Index<ArgumentTypes<CallableType>, TypeIndex>;
  }
}

// ============================================================================
// IMPLEMENTATION
// ============================================================================

namespace
{
  using namespace Core::MetaFunction;

  template <typename ElementType, typename ReturnType, typename... ArgumentTypes>
  struct ArgumentTypesImp<ReturnType (ElementType::*)(ArgumentTypes...) const>
  {
    using Types = TypeList<ArgumentTypes...>;
  };
}

#endif /* INCLUDED_CORE_METAFUNCTION_ARGUMENTTYPES */
