#pragma once


namespace sead { namespace RuntimeTypeInfo {

class Interface
{
public:
    virtual bool isDerived(const Interface* other) const = 0;
};

class Root : public Interface
{
public:
    Root() { }

    __attribute__((noinline))
    bool isDerived(const Interface* other) const override
    {
        return other == this;
    }
};

template <typename TBase>
class Derive : public Interface
{
public:
    Derive() { }

    __attribute__((noinline))
    bool isDerived(const Interface* other) const override
    {
        if (this == other)
            return true;

        const Interface* baseTypeInfo = TBase::getRuntimeTypeInfoStatic();
        return baseTypeInfo->isDerived(other);
    }
};

}

template <typename TCheck, typename TInstance>
inline bool IsDerivedFrom(const TInstance* instance)
{
    const RuntimeTypeInfo::Interface* instanceTypeInfo = instance->getRuntimeTypeInfo();
    const RuntimeTypeInfo::Interface* checkTypeInfo = TCheck::getRuntimeTypeInfoStatic();
    return instance && instanceTypeInfo->isDerived(checkTypeInfo);
}

template <typename TCast, typename TInstance>
inline TCast* DynamicCast(TInstance* instance)
{
    if (IsDerivedFrom<TCast, TInstance>(instance))
        return static_cast<TCast*>(instance);
    return nullptr;
}

}


#define SEAD_RTTI_BASE(CLASS)                                                       \
    public:                                                                         \
        static const sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfoStatic()   \
        {                                                                           \
            static const sead::RuntimeTypeInfo::Root typeInfo;                      \
            return &typeInfo;                                                       \
        }                                                                           \
                                                                                    \
        virtual const sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const  \
        {                                                                           \
            return getRuntimeTypeInfoStatic();                                      \
        }

#define SEAD_RTTI_OVERRIDE(CLASS, BASE)                                             \
    public:                                                                         \
        static const sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfoStatic()   \
        {                                                                           \
            static const sead::RuntimeTypeInfo::Derive<BASE> typeInfo;              \
            return &typeInfo;                                                       \
        }                                                                           \
                                                                                    \
        virtual const sead::RuntimeTypeInfo::Interface* getRuntimeTypeInfo() const  \
        {                                                                           \
            return getRuntimeTypeInfoStatic();                                      \
        }
