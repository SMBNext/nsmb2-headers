#pragma once

#include "sead/seadListImpl.h"

namespace sead {

class Heap;

// Size: 0x10
// Vtable: 0x005D3354
class IDisposer
{
public:

    // Address: 0x0010E5F0
    IDisposer();

    // Address: 0x0010A028
    virtual ~IDisposer();

private:
    Heap* mDispoerHeap;     // 0x0
    ListNode mListNode;     // 0x4

    friend class Heap;
};


#define SEAD_SINGLETON_DISPOSER(CLASS)                                          \
    public:                                                                     \
        static CLASS* instance() { return sInstance; }                          \
        static CLASS* createInstance(sead::Heap* heap);                         \
        static void deleteInstance();                                           \
                                                                                \
    protected:                                                                  \
        class SingletonDisposer_ : public sead::IDisposer                       \
        {                                                                       \
        public:                                                                 \
            SingletonDisposer_() : sead::IDisposer() { }                        \
            virtual ~SingletonDisposer_();                                      \
                                                                                \
            static SingletonDisposer_* sStaticDisposer;                         \
        };                                                                      \
                                                                                \
    private:                                                                    \
        CLASS(const CLASS&);                                                    \
        const CLASS& operator=(const CLASS&);                                   \
                                                                                \
    protected:                                                                  \
        u32 mSingletonDisposerBuf_[sizeof(SingletonDisposer_) / sizeof(u32)];   \
                                                                                \
        static CLASS* sInstance;                                                \
                                                                                \
        friend class SingletonDisposer_;


#define SEAD_CREATE_SINGLETON_INSTANCE(CLASS)                                                                   \
    CLASS* CLASS::createInstance(sead::Heap* heap)                                                              \
    {                                                                                                           \
        CLASS::SingletonDisposer_* staticDisposer = CLASS::SingletonDisposer_::sStaticDisposer;                 \
        CLASS* instance = CLASS::sInstance;                                                                     \
                                                                                                                \
        if (CLASS::sInstance == nullptr)                                                                        \
        {                                                                                                       \
            instance = reinterpret_cast<CLASS*>(new(heap, 4) u8[sizeof(CLASS)]);                                \
                                                                                                                \
            staticDisposer = reinterpret_cast<CLASS::SingletonDisposer_*>(instance->mSingletonDisposerBuf_);    \
                                                                                                                \
            CLASS::SingletonDisposer_::sStaticDisposer = new (staticDisposer) SingletonDisposer_();             \
            CLASS::sInstance = new (instance) CLASS;                                                            \
        }                                                                                                       \
                                                                                                                \
        return CLASS::sInstance;                                                                                \
    }


#define SEAD_DELETE_SINGLETON_INSTANCE(CLASS)                                                       \
    void CLASS::deleteInstance()                                                                    \
    {                                                                                               \
        CLASS::SingletonDisposer_* staticDisposer = CLASS::SingletonDisposer_::sStaticDisposer;     \
        if (CLASS::SingletonDisposer_::sStaticDisposer != nullptr)                                  \
        {                                                                                           \
            CLASS::SingletonDisposer_::sStaticDisposer = nullptr;                                   \
            staticDisposer->~SingletonDisposer_();                                                  \
                                                                                                    \
            if (CLASS::sInstance != nullptr)                                                        \
                delete CLASS::sInstance;                                                            \
                                                                                                    \
            CLASS::sInstance = nullptr;                                                             \
        }                                                                                           \
    }


#define SEAD_SINGLETON_DISPOSER_IMPL(CLASS)                                             \
    CLASS* CLASS::sInstance = nullptr;                                                  \
    CLASS::SingletonDisposer_* CLASS::SingletonDisposer_::sStaticDisposer = nullptr;    \
                                                                                        \
    SEAD_CREATE_SINGLETON_INSTANCE(CLASS)                                               \
    SEAD_DELETE_SINGLETON_INSTANCE(CLASS)                                               \
                                                                                        \
    CLASS::SingletonDisposer_::~SingletonDisposer_()                                    \
    {                                                                                   \
        if (this == sStaticDisposer)                                                    \
        {                                                                               \
            sStaticDisposer = nullptr;                                                  \
            CLASS::sInstance->~CLASS();                                                 \
            CLASS::sInstance = nullptr;                                                 \
        }                                                                               \
    }

}
