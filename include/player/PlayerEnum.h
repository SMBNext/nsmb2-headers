#pragma once

#include "types.h"

#include "utility/BitFlag.h"
#include "utility/EnumUtil.h"

enum class BoneNames : u8
{
    cBoneRootAll        = 0x0,
    cBonePlayerBody     = 0x1,
    cBoneCap            = 0x2,
    cBoneHair           = 0x3,
    cBoneHands_A        = 0x4,
    cBoneHands_B        = 0x5,
    cBoneTailCap        = 0x6,
    cBoneSklRoot        = 0x7,
    cBoneLegL1          = 0x8,
    cBoneLegL2          = 0x9,
    cBoneAnkleL1        = 0xA,
    cBoneLegR1          = 0xB,
    cBoneLegR2          = 0xC,
    cBoneAnkleR1        = 0xD,
    cBoneSpin           = 0xE,
    cBoneArmL1          = 0xF,
    cBoneArmL2          = 0x10,
    cBoneWristL1        = 0x11,
    cBoneArmR1          = 0x12,
    cBoneArmR2          = 0x13,
    cBoneWristR1        = 0x14,
    cBoneFace1          = 0x15,
};

enum class AnimId : s16
{
    cInvalid            = -1,
    cWait               = 0x0,
    cWalk               = 0x1,
    cRun                = 0x2,
    cB_Dash             = 0x3,
    cB_Dash_2           = 0x4,
    cT_B_Dash_2         = 0x5,
    cB_Dash_3           = 0x6,
    cJump               = 0x7,
    cJump2              = 0x8,
    cJumped             = 0x9,
    c2_Jmp_C_1          = 0xA,
    c2_Jmp_C_2          = 0xB,
    c2_Jumped           = 0xC,
    cRollJump           = 0xD,
    c2_Jump2            = 0xE,
    cMameJump2          = 0xF,
    cTurn               = 0x10,
    cTurned             = 0x11,
    cHipsr              = 0x12,
    cHipat              = 0x13,
    cHiped              = 0x14,
    cHipToStoop         = 0x15,
    cStoop              = 0x16,
    cStoopStart         = 0x17,
    cSlip               = 0x18,
    cSliped             = 0x19,
    cSlipToStoop        = 0x1A,
    cCarryWalk          = 0x1B,
    cCarryThrow         = 0x1C,
    cCarryWait          = 0x1D,
    cWsld               = 0x1E,
    cFireAt             = 0x1F,
    cSwimFireAt         = 0x20,
    cSwim               = 0x21,
    cSwimWait           = 0x22,
    cSwimThrow          = 0x23,
    cSwimWalk           = 0x24,
    cSwimStanding       = 0x25,
    cPaddle1            = 0x26,
    cPaddle2            = 0x27,
    cPaddleCarry        = 0x28,
    cTreeStart          = 0x29,
    cTreeWait           = 0x2A,
    cTreeClimb          = 0x2B,
    cTreePose           = 0x2C,
    cMonkeyStart        = 0x2D,
    cMonkeyWait_R       = 0x2E,
    cMonkeyWait_L       = 0x2F,
    cMonkey_R_To_L      = 0x30,
    cMonkey_L_To_R      = 0x31,
    cNetWait            = 0x32,
    cNetWalk1           = 0x33,
    cNetWalk2           = 0x34,
    cNetAttack          = 0x35,
    cPeaPlant           = 0x36,
    cPeaPlantSt         = 0x37,
    cPeaPlantWait       = 0x38,
    cDamf               = 0x39,
    cDamb               = 0x3A,
    cDowf               = 0x3B,
    cDowb               = 0x3C,
    cFirejmp            = 0x3D,
    cE_Shock            = 0x3E,
    cE_ShockCarry       = 0x3F,
    cDead               = 0x40,
    cDeadPose           = 0x41,
    cDeadLoop           = 0x42,
    cGoalStart          = 0x43,
    cGoalWait           = 0x44,
    cGoalPoleDown       = 0x45,
    cGoalPose           = 0x46,
    cGoalJump           = 0x47,
    cGoalJumpEd         = 0x48,
    cGoalDemo           = 0x49,
    cStarRoll           = 0x4A,
    cS_Jump             = 0x4B,
    cS_Jump2            = 0x4C,
    cS_Jumped           = 0x4D,
    cIceTurn            = 0x4E,
    cIceTurned          = 0x4F,
    cIceSlipf           = 0x50,
    cIceSlipb           = 0x51,
    cRopeSwing          = 0x52,
    cShoot              = 0x53,
    cShootSlip          = 0x54,
    cShootSlipEnd       = 0x55,
    cLowWalkStart       = 0x56,
    cLowWalk            = 0x57,
    cSwimPipe           = 0x58,
    cDoorWalk           = 0x59,
    cWait_L             = 0x5A,
    cWait_R             = 0x5B,
    cStamp              = 0x5C,
    cWaitR3             = 0x5D,
    cWaitL3             = 0x5E,
    cWaitR32            = 0x5F,
    cWaitL32            = 0x60,
    cBossKeyGet         = 0x61,
    cBalloonWait        = 0x62,
    cSlopeWait_L        = 0x63,
    cSlopeWait_R        = 0x64,
    cSlopeWaitL2        = 0x65,
    cSlopeWaitR2        = 0x66,
    cCarryWait_L        = 0x67,
    cCarryWait_R        = 0x68,
    cDmNotice           = 0x69,
    cDmNotice_R         = 0x6A,
    cDmNotiWait         = 0x6B,
    cDmNotiWait_R       = 0x6C,
    cDmSurprise         = 0x6D,
    cDmSurpWait         = 0x6E,
    cDmSurpriseLoop     = 0x6F,
    cWaitSelect         = 0x70,
    cCourseIn           = 0x71,
    cWait2              = 0x72,
    cWait3              = 0x73,
    cDmEscort           = 0x74,
    cDmGlad             = 0x75,
    cCoinComp           = 0x76,
    cT_Attackl          = 0x77,
    cT_Attackr          = 0x78,
    cT_Fly              = 0x79,
    cT_Fly2             = 0x7A,
    cT_Fall             = 0x7B,
    cT_FlySt            = 0x7C,
    cT_FlyCarry         = 0x7D,
    cT_Fly2Carry        = 0x7E,
    cT_FallStCarry      = 0x7F,
    cRopeWait           = 0x80,
    cRopeWait2          = 0x81,
    cRopeWalk           = 0x82,
    cBigWalk            = 0x83,
    cBigJumpSt          = 0x84,
    cBigJmp2            = 0x85,
    cBigJumpEd          = 0x86,
    cBigHipSt           = 0x87,
    cBigHipAt           = 0x88,
    cBigHipEd           = 0x89,
    cBigScaleUp         = 0x8A,
    cBigGoal            = 0x8B,
    cGoalDemoTail       = 0x8C,
    cEndingWait         = 0x8D,
    cEndingTakeoff      = 0x8E,
    cNumAnims,
};

ENUM_CLASS_ENABLE_ALL(AnimId, s16);

enum class JumpAnimId : s16
{
    cJump               = 0x0,
    cJump_B             = 0x1,
    cJump_C             = 0x2,
};

enum class FlagMask : u32
{
    cHatVisible         = 0x1,
    cUnk2               = 0x2,
    cUnk3               = 0x4,
    cUnk4               = 0x8,
    cUnk5               = 0x10,
    cUnk6               = 0x20,
    cUnk7               = 0x40,
    cUnk9               = 0x800,
    cStarActive         = 0x100,
    cUnk11              = 0x200,
    cTailVisible        = 0x400,
    cUnk13              = 0x800,
    cUnk14              = 0x1000,
    cGoldBlockActive    = 0x2000,
    cStoneActive        = 0x4000,
    cUnk17              = 0x8000,
    cUnk18              = 0x10000,
    cUnk19              = 0x20000,
    cUnk20              = 0x40000,
    cUnk21              = 0x80000,
};


enum class Powerup : u8
{
    cSmall              = 0x0,
    cSuper              = 0x1,
    cFire               = 0x2,
    cMini               = 0x3,
    cTanooki            = 0x4,
    cMega               = 0x5,
    cGold               = 0x6,
    cWhiteTanooki       = 0x7,
    COUNT,
};

enum class GroundType : u8
{
    cRock               = 0x0,
    cSnow               = 0x1,
    cSand               = 0x2,
    cRock2              = 0x3,
    cDirt               = 0x4,
    cWater              = 0x5,
    cCloud              = 0x6,
    cBlowsand           = 0x7,
    cManta              = 0x8,
    cSand2              = 0x9,
    cCarpet             = 0xA,
    cLeaf               = 0xB,
    cWood               = 0xC,
    cWater2             = 0xD,
};

// Size: 0x1C
class PlayerStatus : public BitFlag<224>
{
public:
    enum Bit
    {
        c_0                                 = 0x0,
        cActiveThisFrame                    = 0x1,          // The player has or will execute this frame
        cStopExecute                        = 0x2,          // The player will not execute
        cDisableAnim                        = 0x3,          // The player will not update animations
        cDisableStateChange                 = 0x4,          // The player cannot change states
        cPendingDelete                      = 0x5,
        cDisplayOutDead                     = 0x6,          // The player is outside of the view bounds and should die
        cDisplayOutNoDamage                 = 0x7,
        c8                                  = 0x8,
        cOutOfPlay                          = 0x9,          // The player is dead or in a bubble
        c10                                 = 0xA,
        cStunned                            = 0xB,          // The player is stunned by an electric shock or ice
        cStone                              = 0xC,          // The player is a frozen stone statue
        cQuake                              = 0xD,          // The player is stunned by a quake
        c14                                 = 0xE,
        c15                                 = 0xF,
        c16                                 = 0x10,
        cJump                               = 0x11,         // The player is doing a jump
        cMegaJump                           = 0x12,         // The player is doing a jump with the Mega powerup
        cStarJump                           = 0x13,         // The player is doing a jump with Star power
        cKaniJump                           = 0x14,         // Player is in a cliff (Kani) jump: disables horizontal turning in jumpExecAir (leftover)
        cQuicksandJump                      = 0x15,         // The player is doing a jump in/from quicksand
        cSitJump                            = 0x16,         // The player is doing a crouch jump
        c23                                 = 0x17,
        c24                                 = 0x18,
        c25                                 = 0x19,
        cWaitJump                           = 0x1A,         // The player is doing a small forced jump (i.e. from a quake)
        cWallSlide                          = 0x1B,         // The player is sliding down a wall
        cBigJump                            = 0x1C,         // The player is performing a big jump (off of a springboard, or another player, etc.)
        cJumpDai                            = 0x1D,         // The player is jumping off of a springboard
        cPlayerJumpDai                      = 0x1E,         // The player is bouncing off of another player
        cThrow                              = 0x1F,         // The player is throwing an actor
        cKaniWalk                           = 0x20,         // The player is doing a crab walk on a cliff (leftover)
        cSlopeHeadPushL                     = 0x21,         // The player cannot move leftward on a slope due to a ceiling
        cSlopeHeadPushR                     = 0x22,         // The player cannot move rightward on a slope due to a ceiling
        cHipAttackFall                      = 0x23,         // The player is falling and in a ground pound
        cHipAttackLand                      = 0x24,         // The player has landed after ground pounding (active on one frame)
        cHipAttackStandUp                   = 0x25,         // The player is standing up after ground pounding (active on one frame)
        cPressAttach                        = 0x26,         // The player is attached while ground pounding
        cHipBlockBreak                      = 0x27,         // The player can break Brick blocks while ground pounding
        c40                                 = 0x28,
        c41                                 = 0x29,
        cTanukiShake                        = 0x2A,         // The player is swiping their tail
        cTanukiFly                          = 0x2B,         // The player is flying
        cTanukiNoTakeoff                    = 0x2C,         // The player is not allowed to take off to fly
        cTanukiGlide                        = 0x2D,         // The player is gliding
        c46                                 = 0x2E,
        c47                                 = 0x2F,
        c48                                 = 0x30,
        c49                                 = 0x31,
        c50                                 = 0x32,
        c51                                 = 0x33,
        c52                                 = 0x34,
        cVine                               = 0x35,         // The player is on a climbable wall / vine
        cHang                               = 0x36,         // The player is hanging from a horizontal rope
        cPole                               = 0x37,         // The player is on a slippery pole
        cTarzanRope                         = 0x38,         // The player is on a swinging vine/rope/chain
        c57                                 = 0x39,
        cKaniHang                           = 0x3A,         // The player is hanging from a cliff edge
        c59                                 = 0x3B,
        c60                                 = 0x3C,
        cSwim                               = 0x3D,         // The player is swimming
        c62                                 = 0x3E,
        c63                                 = 0x3F,
        c64                                 = 0x40,
        c65                                 = 0x41,
        c66                                 = 0x42,
        c67                                 = 0x43,
        cSlipStart                          = 0x44,         // Set when the player is starting a slide (used in initialSlip())
        c69                                 = 0x45,
        c70                                 = 0x46,
        c71                                 = 0x47,
        c72                                 = 0x48,
        c73                                 = 0x49,
        c74                                 = 0x4A,
        c75                                 = 0x4B,
        c76                                 = 0x4C,
        c77                                 = 0x4D,
        c78                                 = 0x4E,
        c79                                 = 0x4F,
        cJumpDaiCooldown                    = 0x50,         // The player failed to perform a springboard jump (hit a ceiling)
        c81                                 = 0x51,
        c82                                 = 0x52,
        c83                                 = 0x53,
        c84                                 = 0x54,
        c85                                 = 0x55,
        c86                                 = 0x56,
        c87                                 = 0x57,
        c88                                 = 0x58,
        c89                                 = 0x59,
        c90                                 = 0x5A,
        c91                                 = 0x5B,
        cExtraPushForce                     = 0x5C,
        cInsideDokan                        = 0x5D,         // The player is in a pipe
        cJumpComboIncreased                 = 0x5E,         // The jump combo counter was incremented this frame
        c95                                 = 0x5F,
        c96                                 = 0x60,
        c97                                 = 0x61,
        c98                                 = 0x62,
        cAutoBounce                         = 0x63,
        c100                                = 0x64,
        c101                                = 0x65,
        cQuakeBig                           = 0x66,         // A big quake (that stuns the player) was triggered
        cQuakeSmall                         = 0x67,         // A small quake (that jumps the player) was triggered
        c104                                = 0x68,
        c105                                = 0x69,
        c106                                = 0x6A,
        c107                                = 0x6B,
        cCanLand                            = 0x6C,
        cCanCarry                           = 0x6D,
        cCanVine                            = 0x6E,
        cCanTarzan                          = 0x6F,         // Whether the player can hang from ropes or hang onto swinging ropes
        cCanPole                            = 0x70,
        cCanFire                            = 0x71,
        c114                                = 0x72,
        c115                                = 0x73,
        c116                                = 0x74,
        c117                                = 0x75,
        c118                                = 0x76,
        c119                                = 0x77,
        c120                                = 0x78,
        cPrepareShoot                       = 0x79,         // The player is about to shoot a projectile (fireball, etc.)
        cFollowMameKuribo                   = 0x7A,         // Mini Goombas are attached to the player
        cInvisible                          = 0x7B,         // The player is invisible
        cInvulnBlink                        = 0x7C,         // Don't draw the player this frame (for the invulnerable blinking state)
        c125                                = 0x7D,
        c126                                = 0x7E,
        c127                                = 0x7F,
        cCanWalkWater                       = 0x80,         // The player can walk on water
        cIsWalkWater                        = 0x81,         // The player is walking on water
        c130                                = 0x82,
        c131                                = 0x83,
        c132                                = 0x84,
        cGoalPoleTouched                    = 0x85,
        c134                                = 0x86,
        c135                                = 0x87,
        c136                                = 0x88,
        c137                                = 0x89,
        c138                                = 0x8A,
        c139                                = 0x8B,
        c140                                = 0x8C,
        c141                                = 0x8D,
        c142                                = 0x8E,
        cGoalPoleNotGoalNoMove              = 0x8F,         // The player did not reach the goal pole in time, and cannot move
        c144                                = 0x90,
        c145                                = 0x91,
        c146                                = 0x92,
        c147                                = 0x93,
        c148                                = 0x94,
        c149                                = 0x95,
        c150                                = 0x96,
        cDemoControl                        = 0x97,         // Frozen or driven by PlayerDemoMgr, with isDemo cleared
        c152                                = 0x98,
        c153                                = 0x99,
        c154                                = 0x9A,
        c155                                = 0x9B,
        cAmbushClear                        = 0x9C,         // Seemingly leftover from NSMBWii, set when an ambush course is cleared
        c157                                = 0x9D,
        c158                                = 0x9E,
        c159                                = 0x9F,
        c160                                = 0xA0,         // Disable collision check related
        c161                                = 0xA1,
        c162                                = 0xA2,         // Disable collision check related
        c163                                = 0xA3,
        c164                                = 0xA4,
        c165                                = 0xA5,
        c166                                = 0xA6,
        c167                                = 0xA7,
        c168                                = 0xA8,
        c169                                = 0xA9,
        c170                                = 0xAA,
        c171                                = 0xAB,
        c172                                = 0xAC,
        c173                                = 0xAD,
        c174                                = 0xAE,
        c175                                = 0xAF,
        c176                                = 0xB0,
        cNoAutoSetZPos                      = 0xB1,       // If set, the player will not have their Z position automatically set every frame
        c178                                = 0xB2,
        c179                                = 0xB3,
        c180                                = 0xB4,
        cNoWallSlide                        = 0xB5,
        c182                                = 0xB6,
        c183                                = 0xB7,
        cIsPenguinMaybe                     = 0xB8,       // NSMBWii leftover, checked in getPowerChangeType()
        c185                                = 0xB9,
        c186                                = 0xBA,
        c187                                = 0xBB,
        c188                                = 0xBC,
        c189                                = 0xBD,
        c190                                = 0xBE,
        c191                                = 0xBF,
        c192                                = 0xC0,
        c193                                = 0xC1,
        c194                                = 0xC2,
        c195                                = 0xC3,
        c196                                = 0xC4,
        c197                                = 0xC5,
        c198                                = 0xC6,
        c199                                = 0xC7,
        c200                                = 0xC8,
        c201                                = 0xC9,
        c202                                = 0xCA,
        c203                                = 0xCB,
        c204                                = 0xCC,
        c205                                = 0xCD,
        c206                                = 0xCE,
        c207                                = 0xCF,
        c208                                = 0xD0,
        cEndingDanceAuto                    = 0xD1,
        c210                                = 0xD2,
        c211                                = 0xD3,
        c212                                = 0xD4,
        c213                                = 0xD5,
        c214                                = 0xD6,
        c215                                = 0xD7,
        c216                                = 0xD8,
        c217                                = 0xD9,
        c218                                = 0xDA,
        c219                                = 0xDB,
        c220                                = 0xDC,
        c221                                = 0xDD,
        c222                                = 0xDE,
        c223                                = 0xDF,

    };
};
size_assert(PlayerStatus, 0x1C);

// Size: 0x10
class BgCross : public BitFlag<96>
{
public:
    enum Bit
    {
        cFoot                               = 0x0,
        cHead                               = 0x1,
        cWall                               = 0x2,
        cWallPressL                         = 0x3,
        cWallPressR                         = 0x4,
        cWallTouchL                         = 0x5,
        cWallTouchR                         = 0x6,
        cWallTouchCarryL                    = 0x7,
        cWallTouchCarryR                    = 0x8,
        c9                                  = 0x9,
        c10                                 = 0xA,
        c11                                 = 0xB,
        c12                                 = 0xC,
        c13                                 = 0xD,
        c14                                 = 0xE,
        cWaterShallow                       = 0xF,          // The player's hip at least slightly in water
        cWaterTouch                         = 0x10,         // The player is touching water at all
        cWaterSubmerged                     = 0x11,         // The player is completely in water
        cOnWaterMove                        = 0x12,         // The player is walking on water (by being Mini, White Tanooki, etc.)
        c19                                 = 0x13,
        cViewWallL                          = 0x14,         // At left edge of view
        cViewWallR                          = 0x15,         // At right edge of view
        cSnow                               = 0x16,
        cIce                                = 0x17,
        cIceNoSlip                          = 0x18,
        cSlopeAndHead                       = 0x19,
        c26                                 = 0x1A,
        cOnQuicksand                        = 0x1B,
        cInQuickSand                        = 0x1C,
        c29                                 = 0x1D,
        cOnBeltL                            = 0x1E,
        cOnBeltR                            = 0x1F,
        cDonutLift                          = 0x20,
        cSemisolid                          = 0x21,
        cLift                               = 0x22,
        cHangRope                           = 0x23,
        cAutoSlip                           = 0x24,
        c37                                 = 0x25,
        cGroundedMoveUp                     = 0x26,
        c39                                 = 0x27,
        cSlope                              = 0x28,
        c41                                 = 0x29,
        c42                                 = 0x2A,
        cCliff                              = 0x2B,
        cCliffAbove1                        = 0x2C,
        cCliffAbove2                        = 0x2D,
        cCanClimb                           = 0x2E,
        cVineTouchFull                      = 0x2F,
        cVineTouchUp                        = 0x30,
        cVineTouchDown                      = 0x31,
        cVineTouch2                         = 0x32,
        cVineTouch                          = 0x33,
        cVineTouchL                         = 0x34,
        cVineTouchR                         = 0x35,
        c54                                 = 0x36,
        cCoinBlockHit                       = 0x37,
        c56                                 = 0x38,
        c57                                 = 0x39,
        c58                                 = 0x3A,
        c59                                 = 0x3B,
        c60                                 = 0x3C,
        c61                                 = 0x3D,
        c62                                 = 0x3E,
        c63                                 = 0x3F,
        c64                                 = 0x40,
        cBreakPipeRel                       = 0x41,
        c66                                 = 0x42,
        c67                                 = 0x43,
        c68                                 = 0x44,
        c69                                 = 0x45,
        c70                                 = 0x46,
        c71                                 = 0x47,
        c72                                 = 0x48,
        c73                                 = 0x49,
        c74                                 = 0x4A,
        c75                                 = 0x4B,
        c76                                 = 0x4C,
        c77                                 = 0x4D,
        c78                                 = 0x4E,
        c79                                 = 0x4F,
        c80                                 = 0x50,
        c81                                 = 0x51,
        c82                                 = 0x52,
        c83                                 = 0x53,
        c84                                 = 0x54,
        c85                                 = 0x55,
        c86                                 = 0x56,
        c87                                 = 0x57,
        c88                                 = 0x58,
        c89                                 = 0x59,
        c90                                 = 0x5A,
        c91                                 = 0x5B,
        c92                                 = 0x5C,
        c93                                 = 0x5D,
        c94                                 = 0x5E,
        c95                                 = 0x5F,
    };
};

enum class DamageType : u32
{
    cNormal             = 0,
    cUnk1               = 1,
    cSlide              = 2,
    cSlideNoHurt        = 3,
    cUnk4               = 4,
    cUnk5               = 5,
    cUnk6               = 6,
    cFire               = 7,
    cLava               = 8,
    cStone              = 9,
    cElectric           = 10,
    cUnk11Crash         = 11,
    cInstakill          = 12,
    cInstakillAlt       = 13,
    cEaten              = 14,
    cEatenNoKill        = 15,
    cShrinkNoHurt       = 16
};


enum class StoneSubstate : u32
{
    cIntro  = 0,
    cFall   = 1,
    cBounce = 2,
    cRest   = 3,
};

enum class SwimArg : u32
{
    cInitial,        // The player was already in the water
    cEntering,       // The player entered the water on their own
    cFireball,       // The player was hit by a fireball
};
