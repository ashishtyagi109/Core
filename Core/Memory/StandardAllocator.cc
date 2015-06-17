// StandardAllocator.cc
#ifndef INCLUDED_CORE_MEMORY_STANDARDALLOCATOR
#include <Core/Memory/StandardAllocator.hh>
#endif /* INCLUDED_CORE_MEMORY_STANDARDALLOCATOR */

#ifndef INCLUDED_CSTDLIB
#include <cstdlib>
#endif /* INCLUDED_CSTDLIB */

namespace Core
{
  namespace Memory
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    using namespace Core::Literal;

    // CREATORS ----------------------------------------------------------<CR>-
    StandardAllocator::StandardAllocator ()
    {
    }

    // DESTRUCTORS -------------------------------------------------------<DS>-
    StandardAllocator::~StandardAllocator ()
    {
    }

    // MANIPULATORS ------------------------------------------------------<MA>-
    Void *StandardAllocator::Allocate (Size NumberOfBytesToAllocate)
    {
      return malloc (NumberOfBytesToAllocate);
    }

    Void StandardAllocator::Deallocate (Void *Object)
    {
      free (Object);
    }

    // STATE -------------------------------------------------------------<ST>-
    struct StandardAllocator StandardAllocator;
  }
}

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
