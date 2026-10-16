#pragma once

#include "item/ItemBase.h"

// Size: 0x11D8
class ItemActorBase : public ItemBase
{
    SEAD_RTTI_OVERRIDE(ItemActorBase, ItemBase);
public:
    ItemActorBase();

    // Unknown. Null.
    virtual void vf184();

    // Unknown. Null.
    virtual void vf188();

    // Sets the value of `this->speed.x`.
    virtual void setHorizontalSpeed();

    DECLARE_STATE_ID(ItemActorBase, Moving);
    DECLARE_STATE_ID(ItemActorBase, Stationary);
    DECLARE_STATE_ID(ItemActorBase, Jumping);

};

size_assert(ItemActorBase, 0x11D8);
