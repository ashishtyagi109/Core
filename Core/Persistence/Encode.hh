// Encode.hh
#ifndef INCLUDED_CORE_PERSISTENCE_ENCODE
#define INCLUDED_CORE_PERSISTENCE_ENCODE

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

#ifndef INCLUDED_CORE_PERSISTENCE_BUFFER
#include <Core/Persistence/Buffer.hh>
#endif /* INCLUDED_CORE_PERSISTENCE_BUFFER */

namespace Core
{
  namespace Persistence
  {
    using namespace Core::Literal;

    template <typename Value>
    auto inline Encode(Buffer &Destination,
		       const Value &Source) -> Size;
  }
}

namespace Core
{
  namespace Persistence
  {
    using namespace Core::Literal;

    template<>
    auto inline Encode<Natural8>(Buffer &Destination,
				 const Natural8 &Source) -> Size
    {
      return Write (Destination, Source);
    }

    template<>
    auto inline Encode<Natural16>(Buffer &Destination,
				  const Natural16 &Source) -> Size
    {
      return Write (Destination, Source >> 8 & 0xFF) +
	Write (Destination, Source & 0xFF);
    }
  }
}

#endif /* INCLUDED_CORE_PERSISTENCE_ENCODE */
