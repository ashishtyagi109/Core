// ReturnType.hh
#ifndef INCLUDED_CORE_METAFUNCTION_RETURNTYPE
#define INCLUDED_CORE_METAFUNCTION_RETURNTYPE

namespace
{
  template <typename CallableType>
  struct ReturnTypeImp;
}

namespace Core
{
  namespace MetaFunction
  {
    template <typename CallableType>
    using ReturnType =
      typename ReturnTypeImp<decltype (&CallableType::operator())>::Type;
  }
}

// ============================================================================
// IMPLEMENTATION
// ============================================================================

namespace
{
  template <typename ElementType, typename ReturnType, typename... ArgumentTypes>
  struct ReturnTypeImp<ReturnType (ElementType::*)(ArgumentTypes...) const>
  {
    using Type = ReturnType;
  };
}

#endif /* INCLUDED_CORE_METAFUNCTION_RETURNTYPE */
