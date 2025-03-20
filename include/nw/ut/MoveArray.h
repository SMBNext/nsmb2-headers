#pragma once

namespace nw { namespace ut {

enum ArrayKind
{
    ARRAY_WRAPPER,
    ARRAY_FIXED,
};

template<typename TElement>
class MoveArray
{
public:
    typedef TElement* iterator; 
    typedef const TElement* const_iterator; 

public:
    MoveArray() :
        m_Allocator(nullptr),
        m_Elements(nullptr),
        m_End(nullptr) {}

    ~MoveArray()
    {
        clear();
        if (m_Allocator && m_Elements)
        {
            m_Allocator->Free(m_Elements);
        }
    }

public:

    MoveArray& operator=(MoveArray rhs)
    {
        rhs.swap(*this);
        return *this;
    }

    const TElement* Elements() const { return m_Elements; }

    TElement& operator[](int index) { return m_Elements[index]; }
    const TElement& operator[](int index) const { return m_Elements[index]; }

    int size() const { return m_End - m_Elements; }

    iterator begin() { return m_Elements; }
    const_iterator begin() const { return m_Elements; }

    iterator end() { return m_End; }
    const_iterator end() const { return m_End; }

    TElement& front() { return *m_Elements; }
    const TElement& front() const { return *m_Elements; }

    TElement& back() { return *(m_End - 1); }
    const TElement& back() const { return *(m_End - 1); }

    bool empty() const { return m_Elements == m_End; }

    os::IAllocator& GetAllocator() { return *m_Allocator; }

    template <typename TIterator>
    TIterator erase(TIterator first);
    
    template <typename TIterator>
    TIterator erase(TIterator first, TIterator last);
    
    void clear() { erase(begin()); }

    // TODO: More

protected:
    os::IAllocator* m_Allocator;
    TElement* m_Elements;
    TElement* m_End;

private:
    size_t m_Capacity;
};

} // namespace ut
} // namespace nw


