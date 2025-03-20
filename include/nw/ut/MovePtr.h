#pragma once

#include "nw/ut/MoveArray.h"

namespace nw { namespace ut {

// Not accurate....
template<typename TObject>
class GfxDeleter 
{ 
bool m_HasOwnership;
};


template<typename TObject, typename TDeleter = GfxDeleter<TObject>>
class MovePtr
{    
public:
    typedef TObject element_type;
    typedef TDeleter deleter_type;

    element_type* Get() const { return Ptr(); }

private:
    element_type*& Ptr() { return m_Object; }
    element_type* Ptr() const { return m_Object; }
    
    element_type* m_Object;
    deleter_type m_Deleter;
};

} // namespace ut
} // namespace nw
