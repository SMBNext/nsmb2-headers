#pragma once

#include "fnd.h"

namespace nn { namespace os {

class HandleObject
{
public:

    Handle GetHandle() const { return m_Handle; }
    bool IsValid() const { return m_Handle.IsValid(); }

protected:
    HandleObject() {}
    ~HandleObject() {};

    void SetHandle(nn::Handle handle);
    void Close();
    void Finalize();
    void ClearHandle();

private:
    HandleObject (const HandleObject &);
    HandleObject & operator = (const HandleObject &);

    nn::Handle m_Handle;
};


class MemoryBlockBase : public fnd::IntrusiveLinkedList<MemoryBlockBase>::Item
{
public:
    uptr GetAddress() const { return m_Addr; }
    size_t GetSize() const { return m_Size; }
    bool IsReadOnly() const { return m_ReadOnly; }

protected:
    MemoryBlockBase() : m_Addr(0), m_Size(0), m_ReadOnly(false) {}
    ~MemoryBlockBase() {}

    void SetAddressAndSize(uptr addr, size_t size)
    {
        this->m_Addr = addr;
        this->m_Size = size;
    }
    void SetReadOnly(bool readOnly) { this->m_ReadOnly = readOnly; }

private:
    uptr m_Addr;
    size_t m_Size;
    bool m_ReadOnly;
    u8 m_Padding[3];
};
size_assert(MemoryBlockBase, 0x14);


class SharedMemoryBlock : public MemoryBlockBase, public HandleObject
{
public:
    SharedMemoryBlock() : m_SpaceAllocated(false) {}
    ~SharedMemoryBlock();
    
    Result AttachAndMap(Handle handle, size_t size, bool readOnly);
    void Finalize();

private:
    bool m_SpaceAllocated;
    u8 m_Padding[7];
};

size_assert(SharedMemoryBlock, 0x20);


class Thread
{
public:
    inline static void Sleep(nn::fnd::TimeSpan time)
    {
        SleepImpl(time);
    }

private:
    static void SleepImpl(nn::fnd::TimeSpan time);
};

} }
