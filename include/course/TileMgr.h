#pragma once

#include "sead.h"
#include "mapobj/BgActorLiquid.h"

class BgChk;

class LiquidSplashReq
{
public:
    f32 x;                     // 00
    f32 y;                     // 04
    u8 type;                   // 08
    u8 _09[3];
    u32 _0C;
    bool active;               // 10  Cleared once LiquidTop turns this into a ripple
    u8 _11[3];
    sead::ListNode node;       // 14

    static LiquidSplashReq* fromNode(sead::ListNode* node)
    {
        return reinterpret_cast<LiquidSplashReq*>(reinterpret_cast<uptr>(node) - offsetof(LiquidSplashReq, node));
    }
};

size_assert(LiquidSplashReq, 0x1C);

class TileMgr : public sead::IDisposer
{
public:
    enum LiquidType : u8
    {
        LIQUID_TYPE_NONE    = 0,
        LIQUID_TYPE_WATER   = 1,
        LIQUID_TYPE_SAND    = 2,
        LIQUID_TYPE_LAVA    = 3,
        LIQUID_TYPE_POISON  = 4,
    };

    enum Behavior3D : u64
    {
        BEHAVIOR_3D_MASK = 0xF00000000000000,

        BEHAVIOR_3D_NORMAL     = 0x0llu << 56,
        BEHAVIOR_3D_FOREGROUD  = 0x1llu << 56,
        BEHAVIOR_3D_BACKGROUND = 0x2llu << 56,
    };

    enum SurfaceType : u64
    {
        SURFACE_TYPE_MASK = 0xF0000000000llu,

        SURFACE_TYPE_NORMAL         = 0x0llu << 10,
        SURFACE_TYPE_ICE            = 0x1llu << 10,
        SURFACE_TYPE_SNOW           = 0x2llu << 10,
        SURFACE_TYPE_QUICKSAND      = 0x3llu << 10,
        SURFACE_TYPE_SAND_DESERT    = 0x4llu << 10,
        SURFACE_TYPE_GRASS          = 0x5llu << 10,
        SURFACE_TYPE_CLOUD          = 0x6llu << 10,
        SURFACE_TYPE_SAND_BEACH     = 0x7llu << 10,
        SURFACE_TYPE_CARPET         = 0x8llu << 10,
        SURFACE_TYPE_LEAVES         = 0x9llu << 10,
        SURFACE_TYPE_WOOD           = 0xAllu << 10,
        SURFACE_TYPE_WATER          = 0xBllu << 10,
    };

    enum Hitbox : u64
    {
        HITBOX_MASK = 0xFF0000000llu,
        
        HITBOX_AIR                           = 0x00llu << 32,
        HITBOX_FULL_SOLID                    = 0x01llu << 32,
        HITBOX_SOLID_ON_TOP                  = 0x02llu << 32,
        HITBOX_SOLID_ON_BOTTOM               = 0x03llu << 32,
        HITBOX_SOLID_ON_TOP_BOTTOM           = 0x04llu << 32,
        HITBOX_SLIDE_2x1                     = 0x11llu << 32,
        HITBOX_STEEP_SLIDE_1x1               = 0x12llu << 32,
        HITBOX_GHOSTHOUSE_STAIR              = 0x21llu << 32,
        HITBOX_SOLID_ON_TOP_SLOPE            = 0x22llu << 32,
    };

    enum PipeColor : u64
    {
        PIPE_COLOR_MASK = 0xF000000llu,

        PIPE_COLOR_GREEN    = 0x00llu << 24,
        PIPE_COLOR_RED      = 0x01llu << 24,
        PIPE_COLOR_YELLOW   = 0x02llu << 24,
        PIPE_COLOR_BLUE     = 0x03llu << 24,
    };

    enum SubBehavior : u64
    {
        SUB_BHVR_MASK = 0xFF0000llu,
    };

    enum SubBehaviorNormal : u64
    {
        SUB_BHVR_NORMAL_NORMAL          = 0x00llu << 16,
        SUB_BHVR_NORMAL_STOP_VINE       = 0x01llu << 16,
    };

    enum SubBehaviorLine : u64
    {
        SUB_BHVR_LINE_HORIZONTAL              = 0x04llu << 16,
        SUB_BHVR_LINE_VERTICAL                = 0x05llu << 16,
        SUB_BHVR_LINE_CORNER_TL               = 0x02llu << 16,
        SUB_BHVR_LINE_CORNER_BL               = 0x03llu << 16,
        SUB_BHVR_LINE_SLOPE_1x1_UP            = 0x00llu << 16,
        SUB_BHVR_LINE_SLOPE_1x1_DOWN          = 0x01llu << 16,
        SUB_BHVR_LINE_SLOPE_2x1_UP_1          = 0x08llu << 16,
        SUB_BHVR_LINE_SLOPE_2x1_UP_2          = 0x07llu << 16,
        SUB_BHVR_LINE_SLOPE_2x1_DOWN_1        = 0x0Allu << 16,
        SUB_BHVR_LINE_SLOPE_2x1_DOWN_2        = 0x09llu << 16,
        SUB_BHVR_LINE_SLOPE_1x2_UP_1          = 0x0Cllu << 16,
        SUB_BHVR_LINE_SLOPE_1x2_UP_2          = 0x0Bllu << 16,
        SUB_BHVR_LINE_SLOPE_1x2_DOWN_1        = 0x0Ellu << 16,
        SUB_BHVR_LINE_SLOPE_1x2_DOWN_2        = 0x0Dllu << 16,
        SUB_BHVR_LINE_CIRCLE_1x1              = 0x0Fllu << 16,
        SUB_BHVR_LINE_CIRCLE_2x2_TR           = 0x10llu << 16,
        SUB_BHVR_LINE_CIRCLE_2x2_TL           = 0x11llu << 16,
        SUB_BHVR_LINE_CIRCLE_2x2_BR           = 0x12llu << 16,
        SUB_BHVR_LINE_CIRCLE_2x2_BL           = 0x13llu << 16,
        SUB_BHVR_LINE_CIRCLE_4x4_TL           = 0x14llu << 16,
        SUB_BHVR_LINE_CIRCLE_4x4_TML          = 0x15llu << 16,
        SUB_BHVR_LINE_CIRCLE_4x4_TMR          = 0x16llu << 16,
        SUB_BHVR_LINE_CIRCLE_4x4_TR           = 0x17llu << 16,
        SUB_BHVR_LINE_CIRCLE_4x4_LMT          = 0x18llu << 16,
        SUB_BHVR_LINE_CIRCLE_4x4_RMT          = 0x19llu << 16,
        SUB_BHVR_LINE_CIRCLE_4x4_LMB          = 0x1Allu << 16,
        SUB_BHVR_LINE_CIRCLE_4x4_RMB          = 0x1Bllu << 16,
        SUB_BHVR_LINE_CIRCLE_4x4_BL           = 0x1Cllu << 16,
        SUB_BHVR_LINE_CIRCLE_4x4_BML          = 0x1Dllu << 16,
        SUB_BHVR_LINE_CIRCLE_4x4_BMR          = 0x1Ellu << 16,
        SUB_BHVR_LINE_CIRCLE_4x4_BR           = 0x1Fllu << 16,
        SUB_BHVR_LINE_STOP                    = 0x20llu << 16,
    };

    enum SubBehaviorCoin : u64
    {
        SUB_BHVR_COIN_NORMAL                  = 0x0llu << 16,
        SUB_BHVR_COIN_RED_COIN                = 0x1llu << 16,
        SUB_BHVR_COIN_BLUE_COIN               = 0x2llu << 16,
    };

    enum SubBehaviorExplodeBlock : u64
    {
        SUB_BHVR_EXPLODE_BLOCK_USED           = 0x0llu << 16,
        SUB_BHVR_EXPLODE_BLOCK_STONE          = 0x1llu << 16,
        SUB_BHVR_EXPLODE_BLOCK_WOOD           = 0x2llu << 16,
        SUB_BHVR_EXPLODE_BLOCK_RED            = 0x3llu << 16,
        SUB_BHVR_EXPLODE_BLOCK_BLUE           = 0x4llu << 16,
    };

    enum SubBehaviorPartlySolid : u64
    {
        SUB_BHVR_PARTLY_SOLID_TL              = 0x0llu << 16,
        SUB_BHVR_PARTLY_SOLID_TR              = 0x1llu << 16,
        SUB_BHVR_PARTLY_SOLID_BR              = 0x2llu << 16,
        SUB_BHVR_PARTLY_SOLID_BL              = 0x3llu << 16,
        SUB_BHVR_PARTLY_SOLID_TOP             = 0x4llu << 16,
        SUB_BHVR_PARTLY_SOLID_RIGHT           = 0x5llu << 16,
        SUB_BHVR_PARTLY_SOLID_BOTTOM          = 0x6llu << 16,
        SUB_BHVR_PARTLY_SOLID_LEFT            = 0x7llu << 16,
    };

    enum SubBehaviorInvisibleBlock : u64
    {
        SUB_BHVR_INV_BLOCK_FIRE_FLOWER        = 0x0llu << 16,
        SUB_BHVR_INV_BLOCK_SUPER_STAR         = 0x1llu << 16,
        SUB_BHVR_INV_BLOCK_COIN               = 0x2llu << 16,
        SUB_BHVR_INV_BLOCK_VINE               = 0x3llu << 16,
        SUB_BHVR_INV_BLOCK_1UP                = 0x4llu << 16,
        SUB_BHVR_INV_BLOCK_MINI               = 0x5llu << 16,
        SUB_BHVR_INV_BLOCK_SUPER_LEAF         = 0x6llu << 16,
        SUB_BHVR_INV_BLOCK_GOLD_FLOWER        = 0x7llu << 16,
    };

    enum SubBehaviorSlope : u64
    {
        SUB_BHVR_SLOPE_1x1_UP                 = 0x00llu << 16,
        SUB_BHVR_SLOPE_1x1_DOWN               = 0x01llu << 16,
        SUB_BHVR_SLOPE_2x1_UP_1               = 0x02llu << 16,
        SUB_BHVR_SLOPE_2x1_UP_2               = 0x03llu << 16,
        SUB_BHVR_SLOPE_2x1_DOWN_1             = 0x04llu << 16,
        SUB_BHVR_SLOPE_2x1_DOWN_2             = 0x05llu << 16,
        SUB_BHVR_SLOPE_1x2_UP_1               = 0x06llu << 16,
        SUB_BHVR_SLOPE_1x2_UP_2               = 0x07llu << 16,
        SUB_BHVR_SLOPE_1x2_DOWN_1             = 0x09llu << 16,
        SUB_BHVR_SLOPE_1x2_DOWN_2             = 0x08llu << 16,
        SUB_BHVR_SLOPE_4x1_UP_1               = 0x0bllu << 16,
        SUB_BHVR_SLOPE_4x1_UP_2               = 0x0cllu << 16,
        SUB_BHVR_SLOPE_4x1_UP_3               = 0x0dllu << 16,
        SUB_BHVR_SLOPE_4x1_UP_4               = 0x0ellu << 16,
        SUB_BHVR_SLOPE_4x1_DOWN_1             = 0x0fllu << 16,
        SUB_BHVR_SLOPE_4x1_DOWN_2             = 0x10llu << 16,
        SUB_BHVR_SLOPE_4x1_DOWN_3             = 0x11llu << 16,
        SUB_BHVR_SLOPE_4x1_DOWN_4             = 0x12llu << 16,
        SUB_BHVR_SLOPE_8x1_UP_1               = 0x13llu << 16,
        SUB_BHVR_SLOPE_8x1_UP_2               = 0x14llu << 16,
        SUB_BHVR_SLOPE_8x1_UP_3               = 0x15llu << 16,
        SUB_BHVR_SLOPE_8x1_UP_4               = 0x16llu << 16,
        SUB_BHVR_SLOPE_8x1_UP_5               = 0x17llu << 16,
        SUB_BHVR_SLOPE_8x1_UP_6               = 0x18llu << 16,
        SUB_BHVR_SLOPE_8x1_UP_7               = 0x19llu << 16,
        SUB_BHVR_SLOPE_8x1_UP_8               = 0x1allu << 16,
        SUB_BHVR_SLOPE_8x1_DOWN_1             = 0x1bllu << 16,
        SUB_BHVR_SLOPE_8x1_DOWN_2             = 0x1cllu << 16,
        SUB_BHVR_SLOPE_8x1_DOWN_3             = 0x1dllu << 16,
        SUB_BHVR_SLOPE_8x1_DOWN_4             = 0x1ellu << 16,
        SUB_BHVR_SLOPE_8x1_DOWN_5             = 0x1fllu << 16,
        SUB_BHVR_SLOPE_8x1_DOWN_6             = 0x20llu << 16,
        SUB_BHVR_SLOPE_8x1_DOWN_7             = 0x21llu << 16,
        SUB_BHVR_SLOPE_8x1_DOWN_8             = 0x22llu << 16,
    };

    enum SubBehaviorUpsideSlope : u64
    {
        SUB_BHVR_UPSIDE_SLOPE_1x1_DOWN        = 0x00llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_1x1_UP          = 0x01llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_2x1_DOWN_1      = 0x02llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_2x1_DOWN_2      = 0x03llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_2x1_UP_1        = 0x04llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_2x1_UP_2        = 0x05llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_1x2_DOWN_1      = 0x06llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_1x2_DOWN_2      = 0x07llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_1x2_UP_1        = 0x09llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_1x2_UP_2        = 0x08llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_4x1_DOWN_1      = 0x0bllu << 16,
        SUB_BHVR_UPSIDE_SLOPE_4x1_DOWN_2      = 0x0cllu << 16,
        SUB_BHVR_UPSIDE_SLOPE_4x1_DOWN_3      = 0x0dllu << 16,
        SUB_BHVR_UPSIDE_SLOPE_4x1_DOWN_4      = 0x0ellu << 16,
        SUB_BHVR_UPSIDE_SLOPE_4x1_UP_1        = 0x0fllu << 16,
        SUB_BHVR_UPSIDE_SLOPE_4x1_UP_2        = 0x10llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_4x1_UP_3        = 0x11llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_4x1_UP_4        = 0x12llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_1      = 0x13llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_2      = 0x14llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_3      = 0x15llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_4      = 0x16llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_5      = 0x17llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_6      = 0x18llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_7      = 0x19llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_DOWN_8      = 0x1allu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_UP_1        = 0x1bllu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_UP_2        = 0x1cllu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_UP_3        = 0x1dllu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_UP_4        = 0x1ellu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_UP_5        = 0x1fllu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_UP_6        = 0x20llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_UP_7        = 0x21llu << 16,
        SUB_BHVR_UPSIDE_SLOPE_8x1_UP_8        = 0x22llu << 16,
    };

    enum SubBehaviorLiquid : u64
    {
        SUB_BHVR_LIQUID_UNK1                  = 0x0llu << 16,
        SUB_BHVR_LIQUID_UNK2                  = 0x1llu << 16,
        SUB_BHVR_LIQUID_UNK3                  = 0x2llu << 16,
        SUB_BHVR_LIQUID_UNK4                  = 0x3llu << 16,
        SUB_BHVR_LIQUID_SAND                  = 0x4llu << 16,
    };

    enum SubBehaviorClimbable : u64
    {
        SUB_BHVR_CLIMABLE_VINE                = 0x0llu << 16,
        SUB_BHVR_CLIMABLE_WALL                = 0x1llu << 16,
        SUB_BHVR_CLIMABLE_SPIDERWEB           = 0x2llu << 16,
        SUB_BHVR_CLIMABLE_FENCE_TL            = 0x3llu << 16,
        SUB_BHVR_CLIMABLE_FENCE_TOP           = 0x4llu << 16,
        SUB_BHVR_CLIMABLE_FENCE_TR            = 0x5llu << 16,
        SUB_BHVR_CLIMABLE_FENCE_LEFT          = 0x6llu << 16,
        SUB_BHVR_CLIMABLE_FENCE_MIDDLE        = 0x7llu << 16,
        SUB_BHVR_CLIMABLE_FENCE_RIGHT         = 0x8llu << 16,
        SUB_BHVR_CLIMABLE_FENCE_BL            = 0x9llu << 16,
        SUB_BHVR_CLIMABLE_FENCE_BOTTOM        = 0xAllu << 16,
        SUB_BHVR_CLIMABLE_FENCE_BR            = 0xBllu << 16,
    };

    enum SubBehaviorDamage : u64
    {
        SUB_BHVR_DAMAGE_ICICLE_1x1            = 0x0llu << 16,
        SUB_BHVR_DAMAGE_ICICLE_1x2_T          = 0x1llu << 16,
        SUB_BHVR_DAMAGE_ICICLE_1x2_B          = 0x2llu << 16,
        SUB_BHVR_DAMAGE_SPIKES_LEFT           = 0x3llu << 16,
        SUB_BHVR_DAMAGE_SPIKES_RIGHT          = 0x4llu << 16,
        SUB_BHVR_DAMAGE_SPIKES_TOP            = 0x5llu << 16,
        SUB_BHVR_DAMAGE_SPIKES_BOTTOM         = 0x6llu << 16,
        SUB_BHVR_DAMAGE_SPIKES_TL             = 0xAllu << 16,
        SUB_BHVR_DAMAGE_SPIKES_TR             = 0xBllu << 16,
        SUB_BHVR_DAMAGE_SPIKES_BL             = 0xCllu << 16,
        SUB_BHVR_DAMAGE_SPIKES_BR             = 0xDllu << 16,
        SUB_BHVR_DAMAGE_INSTA_KILL            = 0x7llu << 16,
        SUB_BHVR_DAMAGE_LAVA                  = 0x8llu << 16,
        SUB_BHVR_DAMAGE_POISON                = 0x9llu << 16,
    };

    enum SubBehaviorPipe : u64
    {
        SUB_BHVR_PIPE_VERT_LEFT               = 0x0Cllu << 16,
        SUB_BHVR_PIPE_VERT_RIGHT              = 0x0Dllu << 16,
        SUB_BHVR_PIPE_VERT_TL                 = 0x00llu << 16,
        SUB_BHVR_PIPE_VERT_TR                 = 0x01llu << 16,
        SUB_BHVR_PIPE_VERT_BL                 = 0x02llu << 16,
        SUB_BHVR_PIPE_VERT_BR                 = 0x03llu << 16,
        SUB_BHVR_PIPE_HORIZ_TOP               = 0x10llu << 16,
        SUB_BHVR_PIPE_HORIZ_BOTTOM            = 0x11llu << 16,
        SUB_BHVR_PIPE_HORIZ_TL                = 0x04llu << 16,
        SUB_BHVR_PIPE_HORIZ_BL                = 0x05llu << 16,
        SUB_BHVR_PIPE_HORIZ_TR                = 0x06llu << 16,
        SUB_BHVR_PIPE_HORIZ_BR                = 0x07llu << 16,
        SUB_BHVR_PIPE_VERT_JOINT_LEFT         = 0x0Ellu << 16,
        SUB_BHVR_PIPE_VERT_JOINT_RIGHT        = 0x0Fllu << 16,
        SUB_BHVR_PIPE_HORIZ_JOINT_TOP         = 0x12llu << 16,
        SUB_BHVR_PIPE_HORIZ_JOINT_BOTTOM      = 0x13llu << 16,
        SUB_BHVR_PIPE_VERT_MINI               = 0x17llu << 16,
        SUB_BHVR_PIPE_HORIZ_MINI              = 0x18llu << 16,
        SUB_BHVR_PIPE_VERT_MINI_TOP           = 0x08llu << 16,
        SUB_BHVR_PIPE_VERT_MINI_BOTTOM        = 0x09llu << 16,
        SUB_BHVR_PIPE_HORIZ_MINI_LEFT         = 0x0Allu << 16,
        SUB_BHVR_PIPE_HORIZ_MINI_RIGHT        = 0x0Bllu << 16,
        SUB_BHVR_PIPE_VERT_MINI_JOINT         = 0x24llu << 16,
        SUB_BHVR_PIPE_HORIZ_MINI_JOINT        = 0x25llu << 16,
        SUB_BHVR_PIPE_JOINT                   = 0x23llu << 16,
    };

    enum SubBehaviorConveyor : u64
    {
        SUB_BHVR_CONVEYOR_LEFT                = 0x0llu << 16,
        SUB_BHVR_CONVEYOR_RIGHT               = 0x1llu << 16,
        SUB_BHVR_CONVEYOR_LEFT_FAST           = 0x2llu << 16,
        SUB_BHVR_CONVEYOR_RIGHT_FAST          = 0x3llu << 16,
    };

    enum SubBehaviorDonutPlatform : u64
    {
        SUB_BHVR_DONUT_1x1                    = 0x0llu << 16,
        SUB_BHVR_DONUT_2x1_L                  = 0x1llu << 16,
        SUB_BHVR_DONUT_2x1_R                  = 0x2llu << 16,
        SUB_BHVR_DONUT_3x1_L                  = 0x3llu << 16,
        SUB_BHVR_DONUT_3x1_M                  = 0x4llu << 16,
        SUB_BHVR_DONUT_3x1_R                  = 0x5llu << 16,
    };

    enum SubBehaviorObakeSpring : u64
    {
        SUB_BHVR_OBAKE_SPRING_UNK1            = 0x0llu << 16,
        SUB_BHVR_OBAKE_SPRING_UNK2            = 0x1llu << 16,
        SUB_BHVR_OBAKE_SPRING_UNK3            = 0x2llu << 16,
        SUB_BHVR_OBAKE_SPRING_UNK4            = 0x3llu << 16,
        SUB_BHVR_OBAKE_SPRING_UNK5            = 0x4llu << 16,
        SUB_BHVR_OBAKE_SPRING_UNK6            = 0x5llu << 16,
    };

    enum Behavior : u64
    {
        BEHAVIOR_MASK = 0xFFllu,

        BEHAVIOR_NORMAL                 = 0x00llu,
        BEHAVIOR_LINE                   = 0x01llu,
        BEHAVIOR_COIN_OUTLINE           = 0x02llu,
        BEHAVIOR_COIN                   = 0x03llu,
        BEHAVIOR_BLUE_COIN              = 0x04llu,
        BEHAVIOR_EXPLODABLE             = 0x05llu,
        BEHAVIOR_BRICK_BLOCK            = 0x06llu,
        BEHAVIOR_QUESTION_MARK_BLOCK    = 0x07llu,
        BEHAVIOR_PARTLY_SOLID           = 0x08llu,
        BEHAVIOR_RED_OUTLINE            = 0x09llu,
        BEHAVIOR_INVISIBLE_BLOCK        = 0x0Allu,
        BEHAVIOR_SLOPE                  = 0x0Bllu,
        BEHAVIOR_SLOPE_UPSIDE_DOWN      = 0x0Cllu,
        BEHAVIOR_LIQUID                 = 0x0Dllu,
        BEHAVIOR_CLIMBABLE              = 0x0Ellu,
        BEHAVIOR_DAMAGE                 = 0x0Fllu,
        BEHAVIOR_PIPE                   = 0x10llu,
        BEHAVIOR_CONVEYOR               = 0x11llu,
        BEHAVIOR_DONUT_PLATFORM         = 0x12llu,
        BEHAVIOR_CLIFF                  = 0x14llu,
        BEHAVIOR_HORIZONTAL_ROPE        = 0x15llu,
        BEHAVIOR_CLIMB_POLE             = 0x16llu,
        BEHAVIOR_FLIPPER_GATE           = 0x20llu,
        BEHAVIOR_CLOWN_CAR_FLASH_SAFE   = 0x21llu,
        BEHAVIOR_NO_HEADBONK            = 0x22llu,
        BEHAVIOR_NOTE_BLOCK             = 0x23llu,
        BEHAVIOR_OBAKE_SPRING           = 0x24llu,
        BEHAVIOR_POW_BLOCK              = 0x25llu,
    };


    static TileMgr* instance;

    u8 _10[0x14-0x10];                              // 10
    BgChk** bgchkEntries;                           // 14
    f32 liquidLevel;                                // 18
    f32 prevLiquidLevel;                            // 1C
    u8 _20[0x160-0x20];                             // 20
    LiquidType liquidType;                          // 160
    u8 _161[0x164-0x161];                           // 161
    sead::ListImpl liquidSplashes;                  // 164  Self-sentinel list of pending splashes.
    LiquidSplashReq* freeLiquidSplashReq;           // 170  Free list, threaded through `LiquidSplashReq::x`.
    LiquidSplashReq* liquidSplashReqPool;           // 174
    u32 liquidSplashReqPoolSize;                    // 178
    LiquidSplashReq liquidSplashRequests[0x20];     // 17C
    f32 waterStreamXPos[200];                       // 4FC
    f32 waterStreamYPos[200];                       // 81C
    u8 waterStream_3BC[200];                        // B3C
    u8 waterStream_404[200];                        // C04
    u16 waterStreamWidth[200];                      // CCC
    u16 waterStreamHeight[200];                     // E5C
    u8 waterStream_FEC[200];                        // FEC

    void setTileType(u16 x, u16 y, u32 tileIdx);

    u64 getTileBehavior(u32 x, u32 y, bool applyOverrides);         // Legacy; remove eventually and move all enums to use BgUnitCode
    BgUnitCode getUnitCode(u32 x, u32 y, bool applyOverrides);

    void requestLiquidSplash(const Vec2f& position, u16 splashType);   // 0x00349620
};

size_assert(TileMgr, 0x10B4);
