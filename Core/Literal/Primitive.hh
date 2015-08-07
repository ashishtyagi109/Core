// Primitive.hh
#ifndef INCLUDED_LITERAL_PRIMITIVE
#define INCLUDED_LITERAL_PRIMITIVE

#ifndef INCLUDED_CSTDBOOL
#include <cstdbool>
#define INCLUDED_CSTDBOOL
#endif /* INCLUDED_CSTDBOOL */

#ifndef INCLUDED_CSTDDEF
#include <cstddef>
#define INCLUDED_CSTDDEF
#endif /* INCLUDED_CSTDDEF */

#ifndef INCLUDED_CSTDINT
#include <cstdint>
#define INCLUDED_CSTDINT
#endif /* INCLUDED_CSTDINT */

// =======================================================================<DC>=
// @PURPOSE:
// @CLASSES:
// @MACROS: CoreNull
// @SEE_ALSO:
// @DESCRIPTION:
// ============================================================================

#define CoreNull nullptr

namespace Core
{
  namespace Literal
  {
    using Void = void;
    using NullPointer = void *;

    using Byte = uint8_t;
    using Short = uint16_t;
    using HalfWord = uint32_t;
    using Word = uint64_t;

    using Boolean = bool;
    const constexpr extern Boolean False = false;
    const constexpr extern Boolean True = true;

    using Character = char;

    using Size = size_t;

    using Natural8 = uint8_t;
    using Natural16 = uint16_t;
    using Natural32 = uint32_t;
    using Natural64 = uint64_t;
    using Natural = uint64_t;

    using Integer8 = int8_t;
    using Integer16 = int16_t;
    using Integer32 = int32_t;
    using Integer64 = int64_t;
    using Integer = int64_t;

    using Real32 = float;
    using Real64 = double;
    using Real = double;
  }
}

#endif /* INCLUDED_LITERAL_PRIMITIVE */

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
