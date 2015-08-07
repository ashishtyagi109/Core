// Buffer.hh
#ifndef INCLUDED_CORE_PERSISTENCE_BUFFER
#define INCLUDED_CORE_PERSISTENCE_BUFFER

#ifndef INCLUDED_CORE_COLLECTION_ARRAY
#include <Core/Collection/Array.hh>
#endif /* INCLUDED_CORE_COLLECTION_ARRAY */

#ifndef INCLUDED_CORE_LITERAL_PRIMITIVE
#include <Core/Literal/Primitive.hh>
#endif /* INCLUDED_CORE_LITERAL_PRIMITIVE */

#ifndef INCLUDED_CORE_MEMORY_MOVE
#include <Core/Memory/Move.hh>
#endif /* INCLUDED_CORE_MEMORY_MOVE */

// =======================================================================<DC>=
// @PURPOSE:
// @CLASSES:
// @MACROS:
// @SEE_ALSO:
// @DESCRIPTION:
// ============================================================================

namespace Core
{
  namespace Persistence
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    namespace C = Core::Collection;
    namespace L = Core::Literal;

    // ===================================================================<CL>=
    // CLASS Buffer
    // ========================================================================

    template <typename ValueType>
    union Buffer final
    {
    public:
      struct Constant
      {
        auto const constexpr static Size = sizeof (ValueType);
      };

      // TYPES -----------------------------------------------------------<TY>-
      struct Type
      {
        using Value = ValueType;
        using ByteArray = C::Array<sizeof (ValueType), L::Byte>;
      };

    private:
      // TYPES -----------------------------------------------------------<PT>-
      using ByteArray = typename Type::ByteArray;

      // DATA ------------------------------------------------------------<DT>-
      union
      {
        ByteArray Bytes;
        ValueType Value;
      } Data;

    public:
      // CREATORS --------------------------------------------------------<CR>-
      constexpr Buffer (const ValueType &Value);

      constexpr Buffer (const ByteArray &Bytes);

      constexpr Buffer (const Buffer &Source);

      Buffer (ValueType &&Value);

      Buffer (ByteArray &&Bytes);

      Buffer (Buffer &&Source);

      // DESTRUCTORS -----------------------------------------------------<DS>-
      ~Buffer () = default;

      // FRIEND ACCESSORS ------------------------------------------------<FA>-
      auto constexpr friend inline Bytes (const Buffer &Self)
        -> const ByteArray &;

      auto constexpr friend inline Value (const Buffer &Self)
        -> const ValueType &;

      // FRIEND MANIPULATORS ---------------------------------------------<FM>-
      auto friend inline Bytes (Buffer &Self) -> ByteArray &;

      auto friend inline Value (Buffer &Self) -> ValueType &;

      // OPERATORS -------------------------------------------------------<OP>-
      auto constexpr inline operator[](Size Index) const -> const L::Byte &;

      auto inline operator[](Size Index) -> L::Byte &;

      // TRAITS ----------------------------------------------------------<TR>-

    private:
      // NOT IMPLEMENTED -------------------------------------------------<NI>-
    };

    // ACCESSORS ---------------------------------------------------------<AC>-
    template <typename ValueType>
    auto constexpr inline Size (const Buffer<ValueType> &Self) -> L::Size;

    // FREE OPERATORS ----------------------------------------------------<FO>-
    template <typename ValueType>
    auto inline operator==(const Buffer<ValueType> &BufferOne,
                           const Buffer<ValueType> &BufferTwo) -> L::Boolean;

    template <typename ValueType>
    auto inline operator!=(const Buffer<ValueType> &BufferOne,
                           const Buffer<ValueType> &BufferTwo) -> L::Boolean;
  }
}

// ============================================================================
// IMPLEMENTATION
// ============================================================================

namespace Core
{
  namespace Persistence
  {
    // USING NAMESPACES --------------------------------------------------<UN>-
    namespace C = Core::Collection;
    namespace L = Core::Literal;
    namespace M = Core::Memory;

    template <typename ElementType>
    using ByteArray = typename Buffer<ElementType>::Type::ByteArray;

    // CREATORS ----------------------------------------------------------<CR>-
    template <typename ValueType>
    constexpr Buffer<ValueType>::Buffer (const ValueType &Value)
      : Data (Value)
    {
    }

    template <typename ValueType>
    constexpr Buffer<ValueType>::Buffer (const ByteArray &Bytes)
      : Data (Bytes)
    {
    }

    template <typename ValueType>
    constexpr Buffer<ValueType>::Buffer (const Buffer &Source)
      : Data (Source.Data)
    {
    }

    template <typename ValueType>
    Buffer<ValueType>::Buffer (ValueType &&Value)
      : Data (M::Move (Value))
    {
      Value = {0};
    }

    template <typename ValueType>
    Buffer<ValueType>::Buffer (ByteArray &&Bytes)
      : Data (M::Move (Bytes))
    {
      Bytes = {0};
    }

    template <typename ValueType>
    Buffer<ValueType>::Buffer (Buffer &&Source)
      : Data (M::Move (Source.Data))
    {
      Source.Data = {0};
    }

    // ACCESSORS ---------------------------------------------------------<AC>-
    template <typename ValueType>
    auto constexpr inline Bytes (const Buffer<ValueType> &Self)
      -> const ByteArray<ValueType> &
    {
      return Self.Bytes;
    }

    template <typename ValueType>
    auto constexpr inline Value (const Buffer<ValueType> &Self)
      -> const ValueType &
    {
      return Self.Value;
    }

    template <typename ValueType>
    auto constexpr inline Size (const Buffer<ValueType> &Self
                                __attribute__ ((unused))) -> L::Size
    {
      return Buffer<ValueType>::Constant::Size;
    }

    // MANIPULATORS ------------------------------------------------------<MA>-
    template <typename ValueType>
    auto inline Bytes (Buffer<ValueType> &Self) -> ByteArray<ValueType> &
    {
      return Self.Bytes;
    }

    template <typename ValueType>
    auto inline Value (Buffer<ValueType> &Self) -> ValueType &
    {
      return Self.Value;
    }

    // OPERATORS ---------------------------------------------------------<OP>-
    template <typename ValueType>
    auto constexpr inline Buffer<ValueType>::
    operator[](L::Size Index) const -> const L::Byte &
    {
      return Data.Bytes[Index];
    }

    template <typename ValueType>
    auto inline Buffer<ValueType>::operator[](L::Size Index) -> L::Byte &
    {
      return Data.Bytes[Index];
    }

    template <typename ValueType>
    auto inline operator==(const Buffer<ValueType> &BufferOne,
                           const Buffer<ValueType> &BufferTwo) -> L::Boolean
    {
      for (L::Size Index = 0; Index < Size (BufferOne); Index++)
        {
          if (BufferOne[Index] != BufferTwo[Index])
            {
              return L::False;
            }
        }
      return L::True;
    }

    template <typename ValueType>
    auto inline operator!=(const Buffer<ValueType> &BufferOne,
                           const Buffer<ValueType> &BufferTwo) -> L::Boolean
    {
      return !(BufferOne == BufferTwo);
    }
  }
}

#endif /* INCLUDED_CORE_PERSISTENCE_BUFFER */

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
