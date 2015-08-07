// UniquePtr.t.cc
#ifndef INCLUDED_CORE_LITERAL
#include <Core/Literal.hh>
#endif /* INCLUDED_CORE_LITERAL */

#ifndef INCLUDED_CORE_MATH
#include <Core/Math.hh>
#endif /* INCLUDED_CORE_MATH */

#ifndef INCLUDED_CORE_COLLECTION_ARRAY
#include <Core/Collection/Array.hh>
#endif /* INCLUDED_CORE_COLLECTION_ARRAY */

#ifndef INCLUDED_CORE_TEST_ASSERT
#include <Core/Test/Assert.hh>
#endif /* INCLUDED_CORE_TEST_ASSERT */

#ifndef INCLUDED_IOSTREAM
#include <iostream>
#define INCLUDED_IOSTREAM
#endif /* INCLUDED_IOSTREAM */

using namespace Core::Collection;
using namespace Core::Literal;
using namespace Core::Math;

auto main () -> Integer32
{
  CoreAssert(3 == 3);
  auto Foo = MakeMatrix (MakeVector (1.0, 1.0), MakeVector (1.0, 1.0));
  auto Bar = MakeMatrix (MakeVector (2.0, 2.0), MakeVector (2.0, 2.0));
  auto Baz = Foo * Bar;
  std::cout << Baz[0][0] << std::endl;
  return 0;
}
