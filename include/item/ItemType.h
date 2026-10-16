#pragma once

#include "types.h"

enum class ItemType : s32
{
    cNone               = -1,   // 
    cKinoko             =  0,   // Mushroom
    cFlower             =  1,   // Fire Flower
    cStar               =  2,   // Star
    c1UpKinoko          =  3,   // 1UP-Mushroom
    cMameKinoko         =  4,   // Mini Mushroom
    cBigKinoko          =  5,   // Mega Mushroom
    cLeaf               =  6,   // Raccoon Leaf
    cGoldFlower         =  7,   // Gold Flower
    cLeafWhite          =  8,   // White Racoon Leaf
    cPanelStar          =  9,   // Star Panel
    cPanelGoldFlower    = 10,   // Gold Flower Panel
    
    cItemCount                  //
};

static constexpr u32 cNumItemTypes = static_cast<u32>(ItemType::cItemCount);
