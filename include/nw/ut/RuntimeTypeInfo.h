#pragma once

namespace nw {
namespace ut {
namespace internal {

struct RuntimeTypeInfo
{
    const RuntimeTypeInfo* mParentTypeInfo;
    
    explicit RuntimeTypeInfo( const RuntimeTypeInfo* parent ) :
        mParentTypeInfo(parent) {}
    
    bool IsDerivedFrom( const RuntimeTypeInfo* s_TypeInfo ) const
    {
        const RuntimeTypeInfo *self = this;
        
        while (self != nullptr)
        {
            if (self == s_TypeInfo)
            {
                return true;
            }
            self = self->mParentTypeInfo;
        }
        return false;
    }
};

} // namespace internal
} // namespace ut
} // namespace nw


