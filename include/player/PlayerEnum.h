#pragma once

#include "types.h"


enum class RenderMode : u8
{
    NORMAL                          = 0x0,
    SMALL                           = 0x1,
    TANOOKI                         = 0x2,
    GOLD                            = 0x3,
    MEGA                            = 0x4,
    MAX                             = 0x5,
};

enum class BoneNames : u8
{
    BONE_ROOT_ALL                   = 0x0,
    BONE_PLAYER_BODY                = 0x1,
    BONE_CAP                        = 0x2,
    BONE_HAIR                       = 0x3,
    BONE_HANDS_A                    = 0x4,
    BONE_HANDS_B                    = 0x5,
    BONE_TAIL_CAP                   = 0x6,
    BONE_SKL_ROOT                   = 0x7,
    BONE_LEG_L1                     = 0x8,
    BONE_LEG_L2                     = 0x9,
    BONE_ANKLE_L1                   = 0xA,
    BONE_LEG_R1                     = 0xB,
    BONE_LEG_R2                     = 0xC,
    BONE_ANKLE_R1                   = 0xD,
    BONE_SPIN                       = 0xE,
    BONE_ARM_L1                     = 0xF,
    BONE_ARM_L2                     = 0x10,
    BONE_WRIST_L1                   = 0x11,
    BONE_ARM_R1                     = 0x12,
    BONE_ARM_R2                     = 0x13,
    BONE_WRIST_R1                   = 0x14,
    BONE_FACE_1                     = 0x15,
};

enum class AnimId : s16
{
    INVALID                         = -1,
    WAIT                            = 0x0,
    WALK                            = 0x1,
    RUN                             = 0x2,
    B_DASH                          = 0x3,
    B_DASH_2                        = 0x4,
    T_B_DASH_2                      = 0x5,
    B_DASH_3                        = 0x6,
    JUMP_2                          = 0x8,
    JUMPED                          = 0x9,
    _2_JMP_C_1                       = 0xA,
    _2_JMP_C_2                       = 0xB,
    _2_JUMPED                        = 0xC,
    ROLL_JUMP                       = 0xD,
    _2_JUMP_2                        = 0xE,
    MAME_JUMP_2                     = 0xF,
    TURN                            = 0x10,
    TURNED                          = 0x11,
    HIPSR                           = 0x12,
    HIPAT                           = 0x13,
    HIPED                           = 0x14,
    HIP_TO_STOOP                    = 0x15,
    STOOP                           = 0x16,
    STOOP_START                     = 0x17,
    SLIP                            = 0x18,
    SLIPED                          = 0x19,
    SLIP_TO_STOOP                   = 0x1A,
    CARRY_WALK                      = 0x1B,
    CARRY_THROW                     = 0x1C,
    CARRY_WAIT                      = 0x1D,
    WSLD                            = 0x1E,
    FIRE_AT                         = 0x1F,
    SWIM_FIRE_AT                    = 0x20,
    SWIM                            = 0x21,
    SWIM_WAIT                       = 0x22,
    SWIM_THROW                      = 0x23,
    SWIM_WALK                       = 0x24,
    SWIM_STANDING                   = 0x25,
    PADDLE_1                        = 0x26,
    PADDLE_2                        = 0x27,
    PADDLE_CARRY                    = 0x28,
    TREE_START                      = 0x29,
    TREE_WAIT                       = 0x2A,
    TREE_CLIMB                      = 0x2B,
    TREE_POSE                       = 0x2C,
    MONKEY_START                    = 0x2D,
    MONKEY_WAIT_R                   = 0x2E,
    MONKEY_WAIT_L                   = 0x2F,
    MONKEY_R_TO_L                   = 0x30,
    MONKEY_L_TO_R                   = 0x31,
    NET_WAIT                        = 0x32,
    NET_WALK_1                      = 0x33,
    NET_WALK_2                      = 0x34,
    NET_ATTACK                      = 0x35,
    PEA_PLANT                       = 0x36,
    PEA_PLANT_ST                    = 0x37,
    PEA_PLANT_WAIT                  = 0x38,
    DAMF                            = 0x39,
    DAMB                            = 0x3A,
    DOWF                            = 0x3B,
    DOWB                            = 0x3C,
    FIREJMP                         = 0x3D,
    E_SHOCK                         = 0x3E,
    E_SHOCK_CARRY                   = 0x3F,
    DEAD                            = 0x40,
    DEAD_POSE                       = 0x41,
    DEAD_LOOP                       = 0x42,
    GOAL_START                      = 0x43,
    GOAL_WAIT                       = 0x44,
    GOAL_POLE_DOWN                  = 0x45,
    GOAL_POSE                       = 0x46,
    GOAL_JUMP                       = 0x47,
    GOAL_JUMP_ED                    = 0x48,
    GOAL_DEMO                       = 0x49,
    STAR_ROLL                       = 0x4A,
    S_JUMP                          = 0x4B,
    S_JUMP_2                        = 0x4C,
    S_JUMPED                        = 0x4D,
    ICE_TURN                        = 0x4E,
    ICE_TURNED                      = 0x4F,
    ICE_SLIPF                       = 0x50,
    ICE_SLIPB                       = 0x51,
    ROPE_SWING                      = 0x52,
    SHOOT                           = 0x53,
    SHOOT_SLIP                      = 0x54,
    SHOOT_SLIP_END                  = 0x55,
    LOW_WALK_START                  = 0x56,
    LOW_WALK                        = 0x57,
    SWIM_PIPE                       = 0x58,
    DOOR_WALK                       = 0x59,
    WAIT_L                          = 0x5A,
    WAIT_R                          = 0x5B,
    STAMP                           = 0x5C,
    WAIT_R3                         = 0x5D,
    WAIT_L3                         = 0x5E,
    WAIT_R3_2                       = 0x5F,
    WAIT_L3_2                       = 0x60,
    BOSS_KEY_GET                    = 0x61,
    BALLOON_WAIT                    = 0x62,
    SLOPE_WAIT_L                    = 0x63,
    SLOPE_WAIT_R                    = 0x64,
    SLOPE_WAIT_L2                   = 0x65,
    SLOPE_WAIT_R2                   = 0x66,
    CARRY_WAIT_L                    = 0x67,
    CARRY_WAIT_R                    = 0x68,
    DM_NOTICE                       = 0x69,
    DM_NOTICE_R                     = 0x6A,
    DM_NOTI_WAIT                    = 0x6B,
    DM_NOTI_WAIT_R                  = 0x6C,
    DM_SURPRISE                     = 0x6D,
    DM_SURP_WAIT                    = 0x6E,
    DM_SURPRISE_LOOP                = 0x6F,
    WAIT_SELECT                     = 0x70,
    COURSE_IN                       = 0x71,
    WAIT_2                          = 0x72,
    WAIT_3                          = 0x73,
    DM_ESCORT                       = 0x74,
    DM_GLAD                         = 0x75,
    COIN_COMP                       = 0x76,
    T_ATTACKL                       = 0x77,
    T_ATTACKR                       = 0x78,
    T_FLY                           = 0x79,
    T_FLY_2                         = 0x7A,
    T_FALL                          = 0x7B,
    T_FLY_ST                        = 0x7C,
    T_FLY_CARRY                     = 0x7D,
    T_FLY_2_CARRY                   = 0x7E,
    T_FALL_ST_CARRY                 = 0x7F,
    ROPE_WAIT                       = 0x80,
    ROPE_WAIT2                      = 0x81,
    ROPE_WALK                       = 0x82,
    BIG_WALK                        = 0x83,
    BIG_JUMP_ST                     = 0x84,
    BIG_JMP_2                       = 0x85,
    BIG_JUMP_ED                     = 0x86,
    BIG_HIP_ST                      = 0x87,
    BIG_HIP_AT                      = 0x88,
    BIG_HIP_ED                      = 0x89,
    BIG_SCALE_UP                    = 0x8A,
    BIG_GOAL                        = 0x8B,
    GOAL_DEMO_TAIL                  = 0x8C,
    ENDING_WAIT                     = 0x8D,
    ENDING_TAKEOFF                  = 0x8E,
};

enum class JumpAnimId : s16
{
    JUMP                            = 0x0,
    JUMP_B                          = 0x1,
    JUMP_C                          = 0x2,
};

enum class FlagMask : u32
{
    HAT_VISIBLE                     = 0x1,
    UNK_2                           = 0x2,
    UNK_3                           = 0x4,
    UNK_4                           = 0x8,
    UNK_5                           = 0x10,
    UNK_6                           = 0x20,
    UNK_7                           = 0x40,
    UNK_9                           = 0x800,
    STAR_ACTIVE                     = 0x100,
    UNK_11                          = 0x200,
    TAIL_VISIBLE                    = 0x400,
    UNK_13                          = 0x800,
    UNK_14                          = 0x1000,
    GOLD_BLOCK_ACTIVE               = 0x2000,
    STONE_ACTIVE                    = 0x4000,
    UNK_17                          = 0x8000,
    UNK_18                          = 0x10000,
    UNK_19                          = 0x20000,
    UNK_20                          = 0x40000,
    UNK_21                          = 0x80000,
};


enum class Powerup : u8
{
    SMALL                           = 0x0,
    SUPER                           = 0x1,
    FIRE                            = 0x2,
    MINI                            = 0x3,
    TANOOKI                         = 0x4,
    MEGA                            = 0x5,
    GOLD                            = 0x6,
    WHITE_TANOOKI                   = 0x7,
    COUNT,
};

enum class GroundType : u8
{
    ROCK                            = 0x0,
    SNOW                            = 0x1,
    SAND                            = 0x2,
    ROCK2                           = 0x3,
    DIRT                            = 0x4,
    WATER                           = 0x5,
    CLOUD                           = 0x6,
    BLOWSAND                        = 0x7,
    MANTA                           = 0x8,
    SAND2                           = 0x9,
    CARPET                          = 0xA,
    LEAF                            = 0xB,
    WOOD                            = 0xC,
    WATER2                          = 0xD,
};

enum MoveStatus : u32
{
    MOVE_STATUS_UNK_1                           = 0X1,
    MOVE_STATUS_UNK_2                           = 0X2,
    MOVE_STATUS_UNK_4                           = 0X3,
    MOVE_STATUS_UNK_8                           = 0X4,
    MOVE_STATUS_UNK_10                          = 0X5,
    MOVE_STATUS_GROUND_POUND                    = 0X6,
    MOVE_STATUS_UNK_40                          = 0X7,
    MOVE_STATUS_UNK_80                          = 0X8,
    MOVE_STATUS_UNK_100                         = 0X9,
    MOVE_STATUS_UNK_200                         = 0XA,
    MOVE_STATUS_UNK_400                         = 0XB,
    MOVE_STATUS_UNK_800                         = 0XC,
    MOVE_STATUS_UNK_1000                        = 0XD,
    MOVE_STATUS_UNK_2000                        = 0XE,
    MOVE_STATUS_UNK_4000                        = 0XF,
    MOVE_STATUS_UNK_8000                        = 0X10,
    MOVE_STATUS_UNK_10000                       = 0X11,
    MOVE_STATUS_UNK_20000                       = 0X12,
    MOVE_STATUS_UNK_40000                       = 0X13,
    MOVE_STATUS_UNK_80000                       = 0X14,
    MOVE_STATUS_UNK_100000                      = 0X15,
    MOVE_STATUS_CLIMBING                        = 0X16,
    MOVE_STATUS_HANGING                         = 0X17,
    MOVE_STATUS_UNK_800000                      = 0X18,
    MOVE_STATUS_SWINGING                        = 0X19,
    MOVE_STATUS_UNK_2000000                     = 0X1A,
    MOVE_STATUS_UNK_4000000                     = 0X1B,
    MOVE_STATUS_UNK_8000000                     = 0X1C,
    MOVE_STATUS_UNK_10000000                    = 0X1D,
    MOVE_STATUS_UNK_20000000                    = 0X1E,
    MOVE_STATUS_UNK_40000000                    = 0X1F,
    MOVE_STATUS_UNK_80000000                    = 0X20,
};

enum MoveStatusMask : u32
{
    MOVE_STATUS_MASK_UNK_1                           = 0x1,
    MOVE_STATUS_MASK_UNK_2                           = 0x2,
    MOVE_STATUS_MASK_UNK_4                           = 0x4,
    MOVE_STATUS_MASK_UNK_8                           = 0x8,
    MOVE_STATUS_MASK_UNK_10                          = 0x10,
    MOVE_STATUS_MASK_GROUND_POUND                    = 0x20,
    MOVE_STATUS_MASK_UNK_40                          = 0x40,
    MOVE_STATUS_MASK_UNK_80                          = 0x80,
    MOVE_STATUS_MASK_UNK_100                         = 0x100,
    MOVE_STATUS_MASK_UNK_200                         = 0x200,
    MOVE_STATUS_MASK_UNK_400                         = 0x400,
    MOVE_STATUS_MASK_UNK_800                         = 0x800,
    MOVE_STATUS_MASK_UNK_1000                        = 0x1000,
    MOVE_STATUS_MASK_UNK_2000                        = 0x2000,
    MOVE_STATUS_MASK_UNK_4000                        = 0x4000,
    MOVE_STATUS_MASK_UNK_8000                        = 0x8000,
    MOVE_STATUS_MASK_UNK_10000                       = 0x10000,
    MOVE_STATUS_MASK_UNK_20000                       = 0x20000,
    MOVE_STATUS_MASK_UNK_40000                       = 0x40000,
    MOVE_STATUS_MASK_UNK_80000                       = 0x80000,
    MOVE_STATUS_MASK_UNK_100000                      = 0x100000,
    MOVE_STATUS_MASK_CLIMBING                        = 0x200000,
    MOVE_STATUS_MASK_HANGING                         = 0x400000,
    MOVE_STATUS_MASK_UNK_800000                      = 0x800000,
    MOVE_STATUS_MASK_SWINGING                        = 0x1000000,
    MOVE_STATUS_MASK_UNK_2000000                     = 0x2000000,
    MOVE_STATUS_MASK_UNK_4000000                     = 0x4000000,
    MOVE_STATUS_MASK_UNK_8000000                     = 0x8000000,
    MOVE_STATUS_MASK_UNK_10000000                    = 0x10000000,
    MOVE_STATUS_MASK_UNK_20000000                    = 0x20000000,
    MOVE_STATUS_MASK_UNK_40000000                    = 0x40000000,
    MOVE_STATUS_MASK_UNK_80000000                    = 0x80000000,
};



enum class Status : u32
{
    STATUS_17 = 17,             // Off in Jump end
    STATUS_18 = 18,             // Set in Jump begin with Mega powerup, Off in Jump end
    STATUS_80 = 80,             // Set in Jump begin with _15D0 != 0, Off in Jump execute with _15D0 == 0, Off in Jump end
    STATUS_81 = 81,             // Set in Cloud begin, Off in Cloud end
    STATUS_83 = 83,             // Off in Cloud end
    STATUS_84 = 84,             // Off in Walk execute/end
    STATUS_100 = 100,           // Off in Jump begin, Off in Jump end
    STATUS_114 = 114,           // Set in Jump begin, Off in Jump end
    STATUS_118 = 120,           // Set in Jump begin, Off in Jump execute if button not held or speed.y <= 1.0f, Off in Jump end
    STATUS_SET_GRAVITY = 176,   // If set, gravity is not changed by gravitySet()
    STATUS_SET_Z_POS = 177,     // If set, position.z is not changed by setZPosition()
    STATUS_183 = 183,           // Off in Jump end
};

enum class DamageType : u32
{
    NORMAL = 0,
    UNK_1 = 1,
    SLIDE = 2,
    SLIDE_NO_HURT = 3,
    UNK_4 = 4,
    UNK_5 = 5,
    UNK_6 = 6,
    FIRE = 7,
    LAVA = 8,
    STONE = 9,
    ELECTRIC = 10,
    UNK_11_CRASH = 11,
    INSTAKILL = 12,
    INSTAKILL_ALT = 13,
    LOCK_ANIM_NO_HURT_1 = 14,
    LOCK_ANIM_NO_HURT__2 = 15,
    SHRINK_NO_HURT = 16
};

