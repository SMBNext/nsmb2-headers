#pragma once

#include "nw/ut/ResTypes.h"
#include "nw/ut/ResArray.h"
#include "nw/ut/ResDictionary.h"

namespace nw { namespace ut { namespace internal {

template <typename TDic>
class ResArrayDicTraits
{
public:

template <typename T>
class Traits
{
public:
    typedef typename TDic::ResDicNodeData* pointer;
    typedef const typename TDic::ResDicNodeData* const_pointer;
    typedef T reference;
    typedef const T const_reference;
    
    static reference GetValue(void* ptr) { return GetValue( reinterpret_cast<pointer>(ptr) ); }
    static reference GetValue(pointer ptr) { return T( ptr->ofsData.to_ptr() ); }
    static const_reference GetValue(const void* ptr) { return GetValue( reinterpret_cast<const_pointer>(ptr) ); }
    static const_reference GetValue(const_pointer ptr) { return T(ptr->ofsData.to_ptr()); }
    
    static pointer GetNext(pointer ptr) { return ptr + 1; }
    static const_pointer GetNext(const_pointer ptr) { return ptr + 1; }
    static size_t ValueSize() { return sizeof(TDic::ResDicNodeData); }
};
};

template<typename T>
class ResArrayClassTraits
{
public:
    typedef Offset* pointer;
    typedef const Offset* const_pointer;
    typedef T reference;
    typedef const T const_reference;

    static reference GetValue(void* ptr) { return GetValue( reinterpret_cast<pointer>(ptr) ); }
    static reference GetValue(pointer ptr) { return T(ptr->to_ptr()); }
    static const_reference GetValue(const void* ptr) { return GetValue( reinterpret_cast<const_pointer>(ptr) ); }
    static const_reference GetValue(const_pointer ptr) { return T(ptr->to_ptr()); }

    static pointer GetNext(pointer ptr){ return ptr + 1; }
    static const_pointer GetNext(const_pointer ptr) { return ptr + 1; }
    static size_t ValueSize() { return sizeof(Offset); }
};

} // namespace internal

template <typename T>
class ResArrayClass
{
public:
    typedef internal::ResArray<T, internal::ResArrayClassTraits> type;
};

template <typename T>
class ResArrayPatricia
{
public:
    typedef internal::ResArray<T, internal::ResArrayDicTraits<ResDicPatriciaData>::Traits> type;
};

} // namespace ut
} // namespace nw


