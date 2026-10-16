#pragma once

#include "types.h"


namespace nn { namespace fnd {

template <typename T>
class IntrusiveLinkedList 
{
public:
    class Item;
    
    IntrusiveLinkedList() : m_Head(0) {}
    bool IsEmpty() const { return !m_Head; }

private:
    Item* m_Head;
};

template <typename T>
class IntrusiveLinkedList<T>::Item
{
    friend class IntrusiveLinkedList;
protected:
    Item() : m_PreviousLink(0), m_NextLink(0) {}
    ~Item() { }
    T* GetPrevious() const { return static_cast<T*>(m_PreviousLink); }
    T* GetNext() const { return static_cast<T*>(m_NextLink); }
    bool IsChained() const { return m_PreviousLink != nullptr; }

private:
    Item* m_PreviousLink;
    Item* m_NextLink;
};

class DateTime
{
public:
    DateTime() : milliseconds(0) { }
    DateTime(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second, s32 millisecond);

    s32 GetYear() const;
    s32 GetMonth() const;
    s32 GetWeek() const;
    s32 GetDay() const;
    s32 GetHour() const;
    s32 GetMinute() const;
    s32 GetSecond() const;
    s32 GetMilliSecond() const;

    static DateTime GetNow();

    s64 milliseconds;
};

class TimeSpan
{
public:
    TimeSpan() : nanoseconds(0) { }
    TimeSpan(s64 nanoseconds) : nanoseconds(nanoseconds) { }

    s64 nanoseconds;
};

} }
