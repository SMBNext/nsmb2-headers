#pragma once

#include "nw/ut/ResTypes.h"

// TODO: fully implement iterators etc

namespace nw { namespace ut { namespace internal {

template <typename T, template <typename> class TTraits>
class ResArray
{
public:
    typedef typename TTraits<T>::pointer pointer;
    typedef typename TTraits<T>::reference reference;
    typedef typename TTraits<T>::const_reference const_reference;

    ResArray(void* pBegin, void* pEnd) :
        m_pBegin(static_cast<pointer>(pBegin)),
        m_pEnd(static_cast<pointer>(pEnd)) {}

    ResArray(void* pBegin, s32 num) :
        m_pBegin(static_cast<pointer>(pBegin)),
        m_pEnd(m_pBegin + num) {}

    operator pointer() { return m_pBegin; }
    operator const pointer() const { return m_pBegin; }
    
    reference operator[](int index) { return TTraits<T>::GetValue(m_pBegin + index); }

    const_reference operator[](int index) const { return TTraits<T>::GetValue(m_pBegin + index); }

    class const_iterator;
    class iterator
    {
    public:
        typedef typename TTraits<T>::pointer pointer;
        typedef typename TTraits<T>::reference reference;

        iterator() :
            m_pCurrent(nullptr) {}

        operator const_iterator() { return const_iterator(m_pCurrent); }

        reference operator*() const { return TTraits<T>::GetValue(m_pCurrent); }

        iterator &operator++() { ++m_pCurrent; return *this; }
        iterator operator++(int) { iterator it(*this); (void)++*this; return it; }
        iterator &operator--() { --m_pCurrent; return *this; }
        iterator operator--(int) { iterator it(*this); (void)--*this; return it; }

        friend bool operator==(iterator it1, iterator it2) { return it1.m_pCurrent == it2.m_pCurrent; }
        friend bool operator!=(iterator it1, iterator it2) { return !(it1 == it2); }

    private:
        explicit iterator(pointer p) :
            m_pCurrent(p) {}

        pointer m_pCurrent;

        friend class const_iterator;
        friend class ResArray<T, TTraits>;
    };

    class const_iterator
    {
    public:
        typedef typename TTraits<T>::const_pointer const_pointer;
        typedef typename TTraits<T>::const_reference const_reference;

        const_iterator() :
            m_pCurrent(nullptr) {}

        const_reference operator*() const { return TTraits<T>::GetValue(m_pCurrent); }

        const_iterator &operator++() { ++m_pCurrent; return *this; }
        const_iterator operator++(int) { const_iterator it(*this); (void)++*this; return it; }
        const_iterator &operator--() { --m_pCurrent; return *this; }
        const_iterator operator--(int) { const_iterator it(*this); (void)--*this; return it; }

        friend bool operator==(const_iterator it1, const_iterator it2) { return it1.m_pCurrent == it2.m_pCurrent; }
        friend bool operator!=(const_iterator it1, const_iterator it2) { return !(it1 == it2); }

    private:
        explicit const_iterator(const_pointer p) :
            m_pCurrent(p) {}

        const_pointer m_pCurrent;

        friend class ResArray<T, TTraits>;
    };

    s32 size() const { return (size_t(m_pEnd) - size_t(m_pBegin)) / TTraits<T>::ValueSize(); }
    bool empty() const { return (m_pBegin == m_pEnd); }

private:
    pointer m_pBegin;
    pointer m_pEnd;

    friend class ResArray<const T, TTraits>;
};

template <typename T, template <typename> class TTraits>
class ResArray<const T, TTraits>
{
public:
    typedef typename TTraits<T>::pointer pointer;
    typedef typename TTraits<T>::const_pointer const_pointer;
    typedef typename TTraits<T>::const_reference const_reference;

    ResArray(const void* pBegin, const void* pEnd) :
        m_pBegin(static_cast<const_pointer>(pBegin)),
        m_pEnd(static_cast<const_pointer>(pEnd)) {}

    ResArray(const void* pBegin, s32 num) :
        m_pBegin(static_cast<const_pointer>(pBegin)),
        m_pEnd(m_pBegin + num) {}

    ResArray(const ResArray<T, TTraits>& rhs) :
        m_pBegin(rhs.m_pBegin),
        m_pEnd(rhs.m_pEnd) {}

    operator const pointer() const { return m_pBegin; }

    const_reference operator[](int index) const { return TTraits<T>::GetValue(m_pBegin + index); }

    class const_iterator
    {
    public:
        typedef typename TTraits<T>::const_pointer const_pointer;
        typedef typename TTraits<T>::const_reference const_reference;

        const_iterator() :
            m_pCurrent(nullptr) {}

        const_reference operator*() const { return TTraits<T>::GetValue(m_pCurrent); }

        const_iterator &operator++() { ++m_pCurrent; return *this; }
        const_iterator operator++(int) { const_iterator it(*this); (void)++*this; return it; }
        const_iterator &operator--() { --m_pCurrent; return *this; }
        const_iterator operator--(int) { const_iterator it(*this); (void)--*this; return it; }

        friend bool operator==(const_iterator it1, const_iterator it2) { return it1.m_pCurrent == it2.m_pCurrent; }
        friend bool operator!=(const_iterator it1, const_iterator it2) { return !(it1 == it2); }

    private:
        explicit const_iterator(const_pointer p) :
            m_pCurrent(p) {}

        const_pointer m_pCurrent;

        friend class ResArray<const T, TTraits>;
    };

    s32 size() const { return (size_t(m_pEnd) - size_t(m_pBegin)) / TTraits<T>::ValueSize(); }
    bool empty() const { return (m_pBegin == m_pEnd); }

private:
    const_pointer m_pBegin;
    const_pointer m_pEnd;

    friend class ResArray<T, TTraits>;
};

} // namespace internal
} // namespace ut
} // namespace nw


