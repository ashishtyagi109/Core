// UniquePtr.t.cc
#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

#ifndef INCLUDED_CORE_MEMORY_UNIQUEPTR
#include <Core/Memory/UniquePtr.hh>
#endif /* INCLUDED_CORE_MEMORY_UNIQUEPTR */

#ifndef INCLUDED_CORE_TYPETRAIT_BASETYPE
#include <Core/TypeTrait/BaseType.hh>
#endif /* INCLUDED_CORE_TYPETRAIT_BASETYPE */

#ifndef INCLUDED_IOSTREAM
#include <iostream>
#endif /* INCLUDED_IOSTREAM */

using namespace Core::Literal;
using namespace Core::Memory;
using namespace Core::TypeTrait;

int
main ()
{
  auto Foo = MakeUnique<Integer>(3);
  std::cout << "some integer: " << *Foo << std::endl;
  return 0;
}
