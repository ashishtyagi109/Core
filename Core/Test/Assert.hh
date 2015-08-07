// Assert.hh
#ifndef INCLUDED_CORE_TEST_ASSERT
#define INCLUDED_CORE_TEST_ASSERT

//@PURPOSE: Provide macros and functions for testing program correctness
//
//@MACROS:
// CoreAssertCritical: perform fast assertion in all build modes
// CoreAssert:         perform assertion in development build mode
// CoreAssertSanity:   perform assertion in debug build mode
// CoreAssertTest:     perform assertion only in testing build modes
//                     does not abort the program on failure
//
//@DESCRIPTION:
// Assertions abort the program if a boolean test fails

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

#ifndef INCLUDED_IOSTREAM
#include <iostream>
#define INCLUDED_IOSTREAM
#endif /* INCLUDED_IOSTREAM */

#ifndef INCLUDED_CSTDLIB
#include <cstdlib>
#define INCLUDED_CSTDLIB
#endif /* INCLUDED_CSTDLIB */

#ifndef CORE_ASSERT_CRITICAL
#define CORE_ASSERT_CRITICAL 1
#endif

#ifndef CORE_ASSERT_STANDARD
#define CORE_ASSERT_STANDARD 1
#endif

#ifndef CORE_ASSERT_SANITY
#define CORE_ASSERT_SANITY 1
#endif

#ifndef CORE_ASSERT_TEST
#define CORE_ASSERT_TEST 0
#endif

#if CORE_ASSERT_CRITICAL
#define CoreAssertCritical(Expression) \
  Core::Test::Assert ((Expression), __FILE__, __LINE__, #Expression)
#else
#define CoreAssertCritical(Expression)
#endif

#if CORE_ASSERT_STANDARD
#define CoreAssert(Expression) \
  Core::Test::Assert ((Expression), __FILE__, __LINE__, #Expression)
#else
#define CoreAssert(Expression)
#endif

#if CORE_ASSERT_SANITY
#define CoreAssertSanity(Expression) \
  Core::Test::Assert ((Expression), __FILE__, __LINE__, #Expression)
#else
#define CoreAssertSanity(Expression)
#endif

#if CORE_ASSERT_TEST
#define CoreAssertTest(Expression) \
  Core::Test::AssertTest ((Expression), __FILE__, __LINE__, #Expression)
#else
#define CoreAssertTest(Expression)
#endif

namespace Core
{
  namespace Test
  {
    namespace L = Core::Literal;

    auto inline Assert (L::Boolean Test,
                        const char *FileName,
                        L::Size LineNumber,
                        const char *Expression) -> L::Void;

    auto inline AssertTest (L::Boolean Test,
                            const char *FileName,
                            L::Size LineNumber,
                            const char *Expression) -> L::Void;
  }
}

namespace Core
{
  namespace Test
  {
    namespace L = Core::Literal;

    auto inline Assert (L::Boolean Test,
                        const char *FileName,
                        L::Size LineNumber,
                        const char *Expression) -> L::Void
    {
      if (!Test)
        {
          std::cerr << "Assertion Failed [" << FileName << ":" << LineNumber
                    << "] " << Expression << std::endl;
          std::abort ();
        }
    }

    auto inline AssertTest (L::Boolean Test,
                            const char *FileName,
                            L::Size LineNumber,
                            const char *Expression) -> L::Void
    {
      if (!Test)
        {
          std::cerr << "Test Assertion Failed [" << FileName << ":"
                    << LineNumber << "] " << Expression << std::endl;
        }
    }
  }
}

#endif /* INCLUDED_CORE_TEST_ASSERT */
