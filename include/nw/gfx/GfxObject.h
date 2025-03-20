#pragma once

#include "nw/os/Memory.h"

#include "nw/ut/MovePtr.h"

namespace nw { namespace gfx {

// This entire class got optimized away...
class GfxObject
{
public:
    GfxObject(nw::os::IAllocator* allocator) :
        m_Allocator(*allocator) {}

    // Inlined
    inline void Destroy()
    { 
        this->~GfxObject(); 
        m_Allocator.Free(this); 
    }

    inline nw::os::IAllocator& getAllocator() { return m_Allocator; }

protected:
    virtual ~GfxObject() {}

private:
    nw::os::IAllocator& m_Allocator;
};


class GfxDeleter
{
public:
    GfxDeleter() :
        m_HasOwnership(true) {}

    GfxDeleter(bool hasOwnership) :
        m_HasOwnership(hasOwnership) {}

private:    
    bool m_HasOwnership;
};


template<typename TObject>
class GfxPtr
{
public:
    typedef ut::MovePtr<TObject, GfxDeleter> GfxMovePtr;
    typedef typename GfxMovePtr::element_type element_type;

    GfxPtr() :
        m_MovePtr() {}

    GfxPtr(const GfxPtr& pointer) :
        m_MovePtr(const_cast<GfxPtr*>(&pointer)->m_MovePtr) {}

    ~GfxPtr() {}

    inline element_type* Get() const { return m_MovePtr.Get(); }
    inline element_type* Release() { return m_MovePtr.Release(); }

    inline element_type& operator*() const { return *m_MovePtr; }
    inline element_type* operator->() const { return m_MovePtr.operator->(); }

    inline GfxPtr& operator=(GfxPtr<TObject> rhs)
    {
        m_MovePtr.operator=(rhs.m_MovePtr);
        return *this;
    }

    inline void Reset() { m_MovePtr.Reset(); }

    inline void Swap(GfxPtr& pointer) { m_MovePtr.Swap(pointer.m_MovePtr); }

private:
    GfxMovePtr m_MovePtr;
};


} // namespace gfx
} // namespace nw


