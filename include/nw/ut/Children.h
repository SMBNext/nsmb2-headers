#pragma once

#include "nw/ut/MoveArray.h"

namespace nw { namespace ut {

template<typename TChild>
class ChildDeleter
{
public:
    ChildDeleter() :
        m_Allocator(0) {}

    // TODO: More...

    os::IAllocator* m_Allocator;
};

template<typename TChild>
class ChildDetacher
{
public:
    ChildDetacher() {}

    // TODO: More...
};

template<typename TChild, typename TParent, typename TDeleter = ChildDeleter<TChild>, typename TChildList = MoveArray<TChild*> >
class Children
{
public:
    typedef TDeleter deleter_type;
    typedef TDeleter& deleter_reference;
    typedef const TDeleter& deleter_const_reference;

public:
    Children() :
        m_Children(),
        m_Deleter() {}

    ~Children() {}

    deleter_reference GetDeleter() { return m_Deleter; }
    deleter_const_reference GetDeleter() const { return m_Deleter; }

    // TODO: More...

private:
    TParent* m_Parent;
    TChildList m_Children;
    deleter_type m_Deleter;
};

} // namespace ut
} // namespace nw


