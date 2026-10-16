#pragma once

#include "types.h"

class BgUnitCode
{
public:
    enum Type
    {
        cNone               = 0,    // No type.
        cLine               = 1,    // Rail line.
        cCoinOutline        = 2,    // Coin outline.
        cCoin               = 3,    // Regular coin (Yellow, Red).
        cCoinBlue           = 4,    // Blue coin.
        cBlock              = 5,    // Regular block (Stone, Wood etc).
        cBlockRenga         = 6,    // Brick block.
        cBlockHatena        = 7,    // A ? block.
        cBlockTensen        = 8,    // Dotted-outline block outline.
        cBlockQuarter       = 9,    // Quarter block (Mini-Mario tunnels).
        cBlockClear         = 10,   // Invisible block.
        cSaka               = 11,   // Slope tile.
        cTenjou             = 12,   // Ceiling slope tile.
        cLiquid             = 13,   // Liquid (Quicksand etc).
        cClimb              = 14,   // Climbable surfaces (Vine, Fence etc).
        cDamage             = 15,   // Damage tiles (Spikes, Icicle etc).
        cDokan              = 16,   // Pipe tiles.
        cBeltConveyor       = 17,   // Conveyor platforms.
        cChikuwa            = 18,   // Donut platforms.
        cCaveEnter          = 19,   // [Unused].
        cKanai              = 20,   // Climbable ledge [Unused].
        cHold               = 21,   // Hanging rope.
        cPole               = 22,   // Climbable pole.

        cUnk17              = 23,   //
        cUnk18              = 24,   //
        cUnk19              = 25,   //
        cUnk1A              = 26,   //
        cUnk1B              = 27,   //
        cUnk1C              = 28,   //
        cUnk1D              = 29,   //
        cUnk1E              = 30,   //
        cUnk1F              = 31,   //
        
        cGateOneway         = 32,   // Flipper gate.
        cClownAttackSafe    = 33,   // Koopa Clown Car safe area.
        cNoBonk             = 34,   // Unknown - prevents head-bonk.
        cBlockJump          = 35,   // Note block.
        cYukaBane           = 36,   // Ghost house floor spring.
        cBlockShock         = 37,   // Pow block.
        cUnk38              = 38,   //
        cUnk39              = 39,   //
    };

    enum TypeInfo
    {
        TypeInfo_cNone          = 0,    // No type.
        TypeInfo_cVineStop      = 1,    // Stop vines from growing.

        TypeInfo_cNum
    };

    enum TypeOpt
    {
        TypeOpt_cNone   = 0,
        TypeOpt_cNum
    };

    enum HitType
    {
        HitType_cNone           = 0,    // Collision is non-solid.
        HitType_cFull           = 1,    // Collision is solid.
        HitType_cHalf           = 2,    // Collision is solid on the outer surface (Solid on top).
        HitType_cHalfCeiling    = 3,    // Collision is solid on the inner surface (Solid on bottom).
        HitType_cNum
    };    

    enum SlipAttr
    {
        SlipAttr_cNormal        = 0,    // Player can slide while colliding when crouching
        SlipAttr_cSlip          = 1,    // Player instantly enters sliding state when colliding
        SlipAttr_cNoSuberu      = 2,    // Player cannot slide while colliding
        SlipAttr_cIceLowSlip    = 3,    //
        SlipAttr_cSakaLowPow    = 4,    //
        SlipAttr_cSlipFlatAngle = 5,    //
        SlipAttr_cSlideSlope    = 6,    //
        SlipAttr_cNum
    };

    enum Attr
    {
        Attr_cNone          = 0,   //
        Attr_cIce           = 1,   //
        Attr_cSnow          = 2,   //
        Attr_cQuicksand     = 3,   //
        Attr_cSand          = 4,   //
        Attr_cGrass         = 5,   //
        Attr_cCloud         = 6,   //
        Attr_cBeachSand     = 7,   //
        Attr_cCarpet        = 8,   //
        Attr_cLeaves        = 9,   //
        Attr_cWood          = 10,  //
        Attr_cWater         = 11,  //
        Attr_cNum
    };
    
    
    static constexpr u32 cPanelTypeMask       = 0x0000FFFF;
    static constexpr u32 cPanelTypeInfoMask   = 0x00FF0000;
    static constexpr u32 cPanelTypeOptionMask = 0xFF000000;
    
    static constexpr u32 cPanelHitTypeMask    = 0x0000000F;
    static constexpr u32 cPanelSlipAttrMask   = 0x000000F0;
    static constexpr u32 cPanelAttrMask       = 0x0000FF00;

    enum Shift
    {
        cShift_Type       = 0,
        cShift_TypeInfo   = 16,
        cShift_TypeOption = 24,
    
        cShift_HitType    = 0,
        cShift_SlipAttr   = 4,
        cShift_Attr       = 8,
    };

    static BgUnitCode makeBgUnitCode(HitType hitType, Attr attr, SlipAttr slipAttr, Type type, TypeInfo typeInfo, TypeOpt typeOption)
    {
        BgUnitCode data{};
    
        setHitType(data, hitType);
        setAttr(data, attr);
        setSlipAttr(data, slipAttr);
        setType(data, type);
        setTypeInfo(data, typeInfo);
        setTypeOption(data, typeOption);
    
        return data;
    }
    
    static Type getType(BgUnitCode data)
    {
        return Type((data.lo & cPanelTypeMask) >> cShift_Type);
    }
    
    static void setType(BgUnitCode& data, Type type)
    {
        data.lo &= ~cPanelTypeMask;
        data.lo |= (u32(type) << cShift_Type) & cPanelTypeMask;
    }

    static TypeInfo getTypeInfo(BgUnitCode data)
    {
        return TypeInfo((data.lo & cPanelTypeInfoMask) >> cShift_TypeInfo);
    }

    template <typename Type>
    static Type getTypeInfo(BgUnitCode data)
    {
        return Type((data.lo & cPanelTypeInfoMask) >> cShift_TypeInfo);
    }
    
    static void setTypeInfo(BgUnitCode& data, TypeInfo type)
    {
        data.lo &= ~cPanelTypeInfoMask;
        data.lo |= (u32(type) << cShift_TypeInfo) & cPanelTypeInfoMask;
    }

    static TypeOpt getTypeOption(BgUnitCode data)
    {
        return TypeOpt((data.lo & cPanelTypeOptionMask) >> cShift_TypeOption);
    }
    
    static void setTypeOption(BgUnitCode& data, TypeOpt type)
    {
        data.lo &= ~cPanelTypeOptionMask;
        data.lo |= (u32(type) << cShift_TypeOption) & cPanelTypeOptionMask;
    }
    
    static HitType getHitType(BgUnitCode data)
    {
        return HitType((data.hi & cPanelHitTypeMask) >> cShift_HitType);
    }
    
    static void setHitType(BgUnitCode& data, HitType hitType)
    {
        data.hi &= ~cPanelHitTypeMask;
        data.hi |= (u32(hitType) << cShift_HitType) & cPanelHitTypeMask;
    }    

    static SlipAttr getSlipAttr(BgUnitCode data)
    {
        return SlipAttr((data.hi & cPanelSlipAttrMask) >> cShift_SlipAttr);
    }
    
    static void setSlipAttr(BgUnitCode& data, SlipAttr hitType)
    {
        data.hi &= ~cPanelSlipAttrMask;
        data.hi |= (u32(hitType) << cShift_SlipAttr) & cPanelSlipAttrMask;
    }  

    static Attr getAttr(BgUnitCode data)
    {
        return Attr((data.hi & cPanelAttrMask) >> cShift_Attr);
    }
    
    static void setAttr(BgUnitCode& data, Attr hitType)
    {
        data.hi &= ~cPanelAttrMask;
        data.hi |= (u32(hitType) << cShift_Attr) & cPanelAttrMask;
    }  

private:
    /* 0x0 */  u32 lo;  // The low byte of the BgUnitCode.
    /* 0x4 */  u32 hi;  // The high byte of the BgUnitCode.
};

enum SubBehaviorLine : u64
{
    SUB_BHVR_LINE_HORIZONTAL              = 4,
    SUB_BHVR_LINE_VERTICAL                = 5,
    SUB_BHVR_LINE_CORNER_TL               = 2,
    SUB_BHVR_LINE_CORNER_BL               = 3,
    SUB_BHVR_LINE_SLOPE_1x1_UP            = 0,
    SUB_BHVR_LINE_SLOPE_1x1_DOWN          = 1,
    SUB_BHVR_LINE_SLOPE_2x1_UP_1          = 8,
    SUB_BHVR_LINE_SLOPE_2x1_UP_2          = 7,
    SUB_BHVR_LINE_SLOPE_2x1_DOWN_1        = 10,
    SUB_BHVR_LINE_SLOPE_2x1_DOWN_2        = 9,
    SUB_BHVR_LINE_SLOPE_1x2_UP_1          = 12,
    SUB_BHVR_LINE_SLOPE_1x2_UP_2          = 11,
    SUB_BHVR_LINE_SLOPE_1x2_DOWN_1        = 14,
    SUB_BHVR_LINE_SLOPE_1x2_DOWN_2        = 13,
    SUB_BHVR_LINE_CIRCLE_1x1              = 15,
    SUB_BHVR_LINE_CIRCLE_2x2_TR           = 16,
    SUB_BHVR_LINE_CIRCLE_2x2_TL           = 17,
    SUB_BHVR_LINE_CIRCLE_2x2_BR           = 18,
    SUB_BHVR_LINE_CIRCLE_2x2_BL           = 19,
    SUB_BHVR_LINE_CIRCLE_4x4_TL           = 20,
    SUB_BHVR_LINE_CIRCLE_4x4_TML          = 21,
    SUB_BHVR_LINE_CIRCLE_4x4_TMR          = 22,
    SUB_BHVR_LINE_CIRCLE_4x4_TR           = 23,
    SUB_BHVR_LINE_CIRCLE_4x4_LMT          = 24,
    SUB_BHVR_LINE_CIRCLE_4x4_RMT          = 25,
    SUB_BHVR_LINE_CIRCLE_4x4_LMB          = 26,
    SUB_BHVR_LINE_CIRCLE_4x4_RMB          = 27,
    SUB_BHVR_LINE_CIRCLE_4x4_BL           = 28,
    SUB_BHVR_LINE_CIRCLE_4x4_BML          = 29,
    SUB_BHVR_LINE_CIRCLE_4x4_BMR          = 30,
    SUB_BHVR_LINE_CIRCLE_4x4_BR           = 31,
    SUB_BHVR_LINE_STOP                    = 32,
};

enum SubBehaviorCoin : u64
{
    SUB_BHVR_COIN_NORMAL                  = 0,
    SUB_BHVR_COIN_RED_COIN                = 1,
    SUB_BHVR_COIN_BLUE_COIN               = 2,
};

enum SubBehaviorExplodeBlock : u64
{
    SUB_BHVR_EXPLODE_BLOCK_USED           = 0,
    SUB_BHVR_EXPLODE_BLOCK_STONE          = 1,
    SUB_BHVR_EXPLODE_BLOCK_WOOD           = 2,
    SUB_BHVR_EXPLODE_BLOCK_RED            = 3,
    SUB_BHVR_EXPLODE_BLOCK_BLUE           = 4,
};

enum SubBehaviorPartlySolid : u64
{
    SUB_BHVR_PARTLY_SOLID_TL              = 0,
    SUB_BHVR_PARTLY_SOLID_TR              = 1,
    SUB_BHVR_PARTLY_SOLID_BR              = 2,
    SUB_BHVR_PARTLY_SOLID_BL              = 3,
    SUB_BHVR_PARTLY_SOLID_TOP             = 4,
    SUB_BHVR_PARTLY_SOLID_RIGHT           = 5,
    SUB_BHVR_PARTLY_SOLID_BOTTOM          = 6,
    SUB_BHVR_PARTLY_SOLID_LEFT            = 7,
};

enum SubBehaviorInvisibleBlock : u64
{
    SUB_BHVR_INV_BLOCK_FIRE_FLOWER        = 0,
    SUB_BHVR_INV_BLOCK_SUPER_STAR         = 1,
    SUB_BHVR_INV_BLOCK_COIN               = 2,
    SUB_BHVR_INV_BLOCK_VINE               = 3,
    SUB_BHVR_INV_BLOCK_1UP                = 4,
    SUB_BHVR_INV_BLOCK_MINI               = 5,
    SUB_BHVR_INV_BLOCK_SUPER_LEAF         = 6,
    SUB_BHVR_INV_BLOCK_GOLD_FLOWER        = 7,
};

enum SubBehaviorSlope : u64
{
    SUB_BHVR_SLOPE_1x1_UP                 = 0,
    SUB_BHVR_SLOPE_1x1_DOWN               = 1,
    SUB_BHVR_SLOPE_2x1_UP_1               = 2,
    SUB_BHVR_SLOPE_2x1_UP_2               = 3,
    SUB_BHVR_SLOPE_2x1_DOWN_1             = 4,
    SUB_BHVR_SLOPE_2x1_DOWN_2             = 5,
    SUB_BHVR_SLOPE_1x2_UP_1               = 6,
    SUB_BHVR_SLOPE_1x2_UP_2               = 7,
    SUB_BHVR_SLOPE_1x2_DOWN_1             = 9,
    SUB_BHVR_SLOPE_1x2_DOWN_2             = 8,
    SUB_BHVR_SLOPE_4x1_UP_1               = 11,
    SUB_BHVR_SLOPE_4x1_UP_2               = 12,
    SUB_BHVR_SLOPE_4x1_UP_3               = 13,
    SUB_BHVR_SLOPE_4x1_UP_4               = 14,
    SUB_BHVR_SLOPE_4x1_DOWN_1             = 15,
    SUB_BHVR_SLOPE_4x1_DOWN_2             = 16,
    SUB_BHVR_SLOPE_4x1_DOWN_3             = 17,
    SUB_BHVR_SLOPE_4x1_DOWN_4             = 18,
    SUB_BHVR_SLOPE_8x1_UP_1               = 19,
    SUB_BHVR_SLOPE_8x1_UP_2               = 20,
    SUB_BHVR_SLOPE_8x1_UP_3               = 21,
    SUB_BHVR_SLOPE_8x1_UP_4               = 22,
    SUB_BHVR_SLOPE_8x1_UP_5               = 23,
    SUB_BHVR_SLOPE_8x1_UP_6               = 24,
    SUB_BHVR_SLOPE_8x1_UP_7               = 25,
    SUB_BHVR_SLOPE_8x1_UP_8               = 26,
    SUB_BHVR_SLOPE_8x1_DOWN_1             = 27,
    SUB_BHVR_SLOPE_8x1_DOWN_2             = 28,
    SUB_BHVR_SLOPE_8x1_DOWN_3             = 29,
    SUB_BHVR_SLOPE_8x1_DOWN_4             = 30,
    SUB_BHVR_SLOPE_8x1_DOWN_5             = 31,
    SUB_BHVR_SLOPE_8x1_DOWN_6             = 32,
    SUB_BHVR_SLOPE_8x1_DOWN_7             = 33,
    SUB_BHVR_SLOPE_8x1_DOWN_8             = 34,
};

enum SubBehaviorUpsideSlope : u64
{
    SUB_BHVR_UPSIDE_SLOPE_1x1_DOWN        = 0,
    SUB_BHVR_UPSIDE_SLOPE_1x1_UP          = 1,
    SUB_BHVR_UPSIDE_SLOPE_2x1_DOWN_1      = 2,
    SUB_BHVR_UPSIDE_SLOPE_2x1_DOWN_2      = 3,
    SUB_BHVR_UPSIDE_SLOPE_2x1_UP_1        = 4,
    SUB_BHVR_UPSIDE_SLOPE_2x1_UP_2        = 5,
    SUB_BHVR_UPSIDE_SLOPE_1x2_DOWN_1      = 6,
    SUB_BHVR_UPSIDE_SLOPE_1x2_DOWN_2      = 7,
    SUB_BHVR_UPSIDE_SLOPE_1x2_UP_1        = 9,
    SUB_BHVR_UPSIDE_SLOPE_1x2_UP_2        = 8,
    SUB_BHVR_UPSIDE_SLOPE_4x1_DOWN_1      = 11,
    SUB_BHVR_UPSIDE_SLOPE_4x1_DOWN_2      = 12,
    SUB_BHVR_UPSIDE_SLOPE_4x1_DOWN_3      = 13,
    SUB_BHVR_UPSIDE_SLOPE_4x1_DOWN_4      = 14,
    SUB_BHVR_UPSIDE_SLOPE_4x1_UP_1        = 15,
    SUB_BHVR_UPSIDE_SLOPE_4x1_UP_2        = 16,
    SUB_BHVR_UPSIDE_SLOPE_4x1_UP_3        = 17,
    SUB_BHVR_UPSIDE_SLOPE_4x1_UP_4        = 18,
    SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_1      = 19,
    SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_2      = 20,
    SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_3      = 21,
    SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_4      = 22,
    SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_5      = 23,
    SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_6      = 24,
    SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_7      = 25,
    SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_8      = 26,
    SUB_BHVR_UPSIDE_SLOPE_8x1_UP_1        = 27,
    SUB_BHVR_UPSIDE_SLOPE_8x1_UP_2        = 28,
    SUB_BHVR_UPSIDE_SLOPE_8x1_UP_3        = 29,
    SUB_BHVR_UPSIDE_SLOPE_8x1_UP_4        = 30,
    SUB_BHVR_UPSIDE_SLOPE_8x1_UP_5        = 31,
    SUB_BHVR_UPSIDE_SLOPE_8x1_UP_6        = 32,
    SUB_BHVR_UPSIDE_SLOPE_8x1_UP_7        = 33,
    SUB_BHVR_UPSIDE_SLOPE_8x1_UP_8        = 34,
};

enum SubBehaviorLiquid : u64
{
    SUB_BHVR_LIQUID_UNK1                  = 0,
    SUB_BHVR_LIQUID_UNK2                  = 1,
    SUB_BHVR_LIQUID_UNK3                  = 2,
    SUB_BHVR_LIQUID_UNK4                  = 3,
    SUB_BHVR_LIQUID_SAND                  = 4,
};

enum SubBehaviorClimbable : u64
{
    SUB_BHVR_CLIMABLE_VINE                = 0,
    SUB_BHVR_CLIMABLE_WALL                = 1,
    SUB_BHVR_CLIMABLE_SPIDERWEB           = 2,
    SUB_BHVR_CLIMABLE_FENCE_TL            = 3,
    SUB_BHVR_CLIMABLE_FENCE_TOP           = 4,
    SUB_BHVR_CLIMABLE_FENCE_TR            = 5,
    SUB_BHVR_CLIMABLE_FENCE_LEFT          = 6,
    SUB_BHVR_CLIMABLE_FENCE_MIDDLE        = 7,
    SUB_BHVR_CLIMABLE_FENCE_RIGHT         = 8,
    SUB_BHVR_CLIMABLE_FENCE_BL            = 9,
    SUB_BHVR_CLIMABLE_FENCE_BOTTOM        = 10,
    SUB_BHVR_CLIMABLE_FENCE_BR            = 11,
};

enum SubBehaviorDamage : u64
{
    SUB_BHVR_DAMAGE_ICICLE_1x1            = 0,
    SUB_BHVR_DAMAGE_ICICLE_1x2_T          = 1,
    SUB_BHVR_DAMAGE_ICICLE_1x2_B          = 2,
    SUB_BHVR_DAMAGE_SPIKES_LEFT           = 3,
    SUB_BHVR_DAMAGE_SPIKES_RIGHT          = 4,
    SUB_BHVR_DAMAGE_SPIKES_TOP            = 5,
    SUB_BHVR_DAMAGE_SPIKES_BOTTOM         = 6,
    SUB_BHVR_DAMAGE_SPIKES_TL             = 10,
    SUB_BHVR_DAMAGE_SPIKES_TR             = 11,
    SUB_BHVR_DAMAGE_SPIKES_BL             = 12,
    SUB_BHVR_DAMAGE_SPIKES_BR             = 13,
    SUB_BHVR_DAMAGE_INSTA_KILL            = 7,
    SUB_BHVR_DAMAGE_LAVA                  = 8,
    SUB_BHVR_DAMAGE_POISON                = 9,
};

enum SubBehaviorPipe : u64
{
    SUB_BHVR_PIPE_VERT_LEFT               = 12,
    SUB_BHVR_PIPE_VERT_RIGHT              = 13,
    SUB_BHVR_PIPE_VERT_TL                 = 0,
    SUB_BHVR_PIPE_VERT_TR                 = 1,
    SUB_BHVR_PIPE_VERT_BL                 = 2,
    SUB_BHVR_PIPE_VERT_BR                 = 3,
    SUB_BHVR_PIPE_HORIZ_TOP               = 16,
    SUB_BHVR_PIPE_HORIZ_BOTTOM            = 17,
    SUB_BHVR_PIPE_HORIZ_TL                = 4,
    SUB_BHVR_PIPE_HORIZ_BL                = 5,
    SUB_BHVR_PIPE_HORIZ_TR                = 6,
    SUB_BHVR_PIPE_HORIZ_BR                = 7,
    SUB_BHVR_PIPE_VERT_JOINT_LEFT         = 14,
    SUB_BHVR_PIPE_VERT_JOINT_RIGHT        = 15,
    SUB_BHVR_PIPE_HORIZ_JOINT_TOP         = 18,
    SUB_BHVR_PIPE_HORIZ_JOINT_BOTTOM      = 19,
    SUB_BHVR_PIPE_VERT_MINI               = 23,
    SUB_BHVR_PIPE_HORIZ_MINI              = 24,
    SUB_BHVR_PIPE_VERT_MINI_TOP           = 8,
    SUB_BHVR_PIPE_VERT_MINI_BOTTOM        = 9,
    SUB_BHVR_PIPE_HORIZ_MINI_LEFT         = 10,
    SUB_BHVR_PIPE_HORIZ_MINI_RIGHT        = 11,
    SUB_BHVR_PIPE_VERT_MINI_JOINT         = 36,
    SUB_BHVR_PIPE_HORIZ_MINI_JOINT        = 37,
    SUB_BHVR_PIPE_JOINT                   = 35,
};

enum SubBehaviorConveyor : u64
{
    SUB_BHVR_CONVEYOR_LEFT                = 0,
    SUB_BHVR_CONVEYOR_RIGHT               = 1,
    SUB_BHVR_CONVEYOR_LEFT_FAST           = 2,
    SUB_BHVR_CONVEYOR_RIGHT_FAST          = 3,
};

enum SubBehaviorDonutPlatform : u64
{
    SUB_BHVR_DONUT_1x1                    = 0,
    SUB_BHVR_DONUT_2x1_L                  = 1,
    SUB_BHVR_DONUT_2x1_R                  = 2,
    SUB_BHVR_DONUT_3x1_L                  = 3,
    SUB_BHVR_DONUT_3x1_M                  = 4,
    SUB_BHVR_DONUT_3x1_R                  = 5,
};

enum SubBehaviorObakeSpring : u64
{
    SUB_BHVR_OBAKE_SPRING_UNK1            = 0,
    SUB_BHVR_OBAKE_SPRING_UNK2            = 1,
    SUB_BHVR_OBAKE_SPRING_UNK3            = 2,
    SUB_BHVR_OBAKE_SPRING_UNK4            = 3,
    SUB_BHVR_OBAKE_SPRING_UNK5            = 4,
    SUB_BHVR_OBAKE_SPRING_UNK6            = 5,
};
