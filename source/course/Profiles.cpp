#include "course/Profiles.h"
#include "course/ProfileId.h"
#include "sys/Preprocessor.h"

#define FWD_DECL_RES(resname)               \
    static sead::SafeString resname [];

#define FWD_DECL_PROC(name, ...)            \
class name                                  \
{                                           \
public:                                     \
    static fBase* build();                  \
    static void destroy(fBase*);            \
    FWD_DECL_RES(resources)                 \
    PP_FOR_EACH(FWD_DECL_RES, __VA_ARGS__)  \
    static ActorInfo info;                  \
}


#define PSTR(ptr, name) \
    ((const char*) (ptr))

ProfileInfo ProfileInfos[ProfileId::Num] =
{
    {   0, PSTR(0x005d59e3, "BsRoot"),                       0x0000, 0x01d5 },
    {   1, PSTR(0x005d59dc, "ScBoot"),                       0x0001, 0x0002 },
    {   2, PSTR(0x005d56a4, "BsFogMgr"),                     0x0002, 0x0001 },
    {   3, PSTR(0x005d466f, "BsCamera"),                     0x0003, 0x0000 },
    {   4, PSTR(0x005d546e, "ScStartUp"),                    0x0004, 0x0003 },
    {   5, PSTR(0x005d5aa8, "ScTitleMenu"),                  0x0005, 0x0004 },
    {   6, PSTR(0x005d53ac, "ScOpeningDemo"),                0x0006, 0x0005 },
    {   7, PSTR(0x005d5ab4, "ScCoinRushMenu"),               0x0007, 0x0006 },
    {   8, PSTR(0x005d57be, "ScCoinRushMiiSelect"),          0x0008, 0x0007 },
    {   9, PSTR(0x005d58e9, "ScCoinRushResult"),             0x0009, 0x0008 },
    {  10, PSTR(0x005d4cac, "ScMatching"),                   0x000a, 0x0009 },
    {  11, PSTR(0x005d56fb, "ScPiaErr"),                     0x000b, 0x000a },
    {  12, PSTR(0x005d551b, "ScShop"),                       0x000c, 0x000b },
    {  13, PSTR(0x005d57d2, "ScPackSelect"),                 0x000d, 0x000c },
    {  14, PSTR(0x005d5114, "ScCongratulation"),             0x000e, 0x0011 },
    {  15, PSTR(0x005d4ff7, "ScExceedCoinNum"),              0x000f, 0x0012 },
    {  16, PSTR(0x005d4b3d, "ScCourse"),                     0x0010, 0x000d },
    {  17, PSTR(0x005d5007, "ScCourseIn"),                   0x0011, 0x000e },
    {  18, PSTR(0x005d57af, "ScCourseSelect"),               0x0012, 0x000f },
    {  19, PSTR(0x005d5629, "ScGameOver"),                   0x0013, 0x0010 },
    {  20, PSTR(0x005d45d0, "BsArea"),                       0x0014, 0x0013 },
    {  21, PSTR(0x005d4bf3, "FlagSwitchTag"),                0x0015, 0x01a1 },
    {  22, PSTR(0x005d4bb8, "FlagSwitchIf"),                 0x0016, 0x01a2 },
    {  23, PSTR(0x005d48f1, "FlagSwitchChange"),             0x0017, 0x01a3 },
    {  24, PSTR(0x005d4b74, "FlagSwitchContinue"),           0x0018, 0x01a4 },
    {  25, PSTR(0x005d4fe6, "FlagSwitchRandom"),             0x0019, 0x01a5 },
    {  26, PSTR(0x005d55fe, "FlagSwitchCreateAfter"),        0x001a, 0x01a6 },
    {  27, PSTR(0x005d591d, "PairObjParent"),                0x001b, 0x0143 },
    {  28, PSTR(0x005d5970, "RailPolyParent"),               0x001c, 0x0144 },
    {  29, PSTR(0x005d4774, "GroupId"),                      0x001d, 0x01a7 },
    {  30, PSTR(0x005d5125, "CenterRotation"),               0x001e, 0x013f },
    {  31, PSTR(0x005d4f45, "CenterRotationRail"),           0x001f, 0x0140 },
    {  32, PSTR(0x005d4cb7, "CenterSwing"),                  0x0020, 0x0141 },
    {  33, PSTR(0x005d4f35, "CenterSwingRail"),              0x0021, 0x0142 },
    {  34, PSTR(0x005d537e, "KokoopaDemo"),                  0x0022, 0x01aa },
    {  35, PSTR(0x005d53ba, "BuiBuiDemo"),                   0x0023, 0x01ab },
    {  36, PSTR(0x005d5bd9, "BuiBuiDemoRoy"),                0x0024, 0x01ac },
    {  37, PSTR(0x005d5baf, "BuiBuiDemoIggy"),               0x0025, 0x01ad },
    {  38, PSTR(0x005d5b79, "BuiBuiDemoWendy"),              0x0026, 0x01ae },
    {  39, PSTR(0x005d517d, "BuiBuiDemoMorton"),             0x0027, 0x01af },
    {  40, PSTR(0x005d4c63, "BuiBuiDemoLudwig"),             0x0028, 0x01b0 },
    {  41, PSTR(0x005d4aa0, "BuiBuiDemoNone"),               0x0029, 0x01b1 },
    {  42, PSTR(0x005d5374, "KoopaDemo"),                    0x002a, 0x01b2 },
    {  43, PSTR(0x005d4b9c, "LiftRideHmove"),                0x002b, 0x00ea },
    {  44, PSTR(0x005d4baa, "LiftRideVmove"),                0x002c, 0x00eb },
    {  45, PSTR(0x005d4fd3, "LiftRideVmoveTotem"),           0x002d, 0x00ec },
    {  46, PSTR(0x005d5873, "KinokoLift"),                   0x002e, 0x00ed },
    {  47, PSTR(0x005d5b36, "KinokoLiftSnow"),               0x002f, 0x00ee },
    {  48, PSTR(0x005d52cb, "KinokoLiftUpDown"),             0x0030, 0x00ef },
    {  49, PSTR(0x005d5323, "LiftSlideKinoko"),              0x0031, 0x00f0 },
    {  50, PSTR(0x005d474d, "LiftSlideKinokoSync"),          0x0032, 0x00f1 },
    {  51, PSTR(0x005d4a5e, "LiftLine"),                     0x0033, 0x00f4 },
    {  52, PSTR(0x005d4db1, "LiftWaki"),                     0x0034, 0x00f5 },
    {  53, PSTR(0x005d548c, "LiftWakiStep"),                 0x0035, 0x00f6 },
    {  54, PSTR(0x005d4f16, "LiftWaterWheel"),               0x0036, 0x00f9 },
    {  55, PSTR(0x005d5012, "LiftMoveOn"),                   0x0037, 0x00f7 },
    {  56, PSTR(0x005d5a38, "LiftMoveOnGhost"),              0x0038, 0x00f8 },
    {  57, PSTR(0x005d5b0d, "LiftSeeSaw"),                   0x0039, 0x00fa },
    {  58, PSTR(0x005d508b, "LiftTenbin"),                   0x003a, 0x00fb },
    {  59, PSTR(0x005d5499, "LiftTenbinStep"),               0x003b, 0x00fc },
    {  60, PSTR(0x005d4acb, "TightRope"),                    0x003c, 0x0139 },
    {  61, PSTR(0x005d5348, "TrplnKinoko"),                  0x003d, 0x00f2 },
    {  62, PSTR(0x005d4a18, "TrplnKinokoCastle"),            0x003e, 0x00f3 },
    {  63, PSTR(0x005d55e6, "BgActorWater"),                 0x003f, 0x0176 },
    {  64, PSTR(0x005d46f0, "BgActorLava"),                  0x0040, 0x0177 },
    {  65, PSTR(0x005d5163, "BgActorPoison"),                0x0041, 0x0178 },
    {  66, PSTR(0x005d4899, "BgActorCloud"),                 0x0042, 0x0179 },
    {  67, PSTR(0x005d55f3, "WendyWater"),                   0x0043, 0x017a },
    {  68, PSTR(0x005d49b6, "WanwanPile"),                   0x0044, 0x0160 },
    {  69, PSTR(0x005d4f9c, "ObjPol"),                       0x0045, 0x0161 },
    {  70, PSTR(0x005d5587, "ObjPolChecker"),                0x0046, 0x0162 },
    {  71, PSTR(0x005d4a0b, "ObjPolCastle"),                 0x0047, 0x0163 },
    {  72, PSTR(0x005d5a2c, "ObjPolGhost"),                  0x0048, 0x0164 },
    {  73, PSTR(0x005d45c6, "ObjPolSea"),                    0x0049, 0x0165 },
    {  74, PSTR(0x005d59ea, "ObjPolDesert"),                 0x004a, 0x0166 },
    {  75, PSTR(0x005d46e5, "ObjPolLava"),                   0x004b, 0x0167 },
    {  76, PSTR(0x005d5bf3, "ObjPolLarry"),                  0x004c, 0x0168 },
    {  77, PSTR(0x005d4dc5, "ObjPolIseki"),                  0x004d, 0x0169 },
    {  78, PSTR(0x005d4860, "ObjPolSand"),                   0x004e, 0x016a },
    {  79, PSTR(0x005d4dda, "ObjPolKazari"),                 0x004f, 0x016b },
    {  80, PSTR(0x005d48d9, "ObjPolToride"),                 0x0050, 0x016c },
    {  81, PSTR(0x005d4f25, "Barrel"),                       0x0051, 0x017f },
    {  82, PSTR(0x005d5b56, "WoodBox"),                      0x0052, 0x0180 },
    {  83, PSTR(0x005d45a2, "LiftM"),                        0x0053, 0x00fd },
    {  84, PSTR(0x005d4dba, "LiftMIseki"),                   0x0054, 0x00fe },
    {  85, PSTR(0x005d5b00, "Uzu"),                          0x0055, 0x0182 },
    {  86, PSTR(0x005d4fb1, "WaterStream"),                  0x0056, 0x015c },
    {  87, PSTR(0x005d4bca, "WaterStreamBg"),                0x0057, 0x015d },
    {  88, PSTR(0x005d4bd8, "WaterBubbleTag"),               0x0058, 0x015e },
    {  89, PSTR(0x005d4e38, "SnakeBlock"),                   0x0059, 0x0159 },
    {  90, PSTR(0x005d472e, "SnakeBlockSync"),               0x005a, 0x015a },
    {  91, PSTR(0x005d5141, "ShipCannon"),                   0x005b, 0x0126 },
    {  92, PSTR(0x005d55c6, "Burner"),                       0x005c, 0x0127 },
    {  93, PSTR(0x005d5868, "BurnerLeft"),                   0x005d, 0x0128 },
    {  94, PSTR(0x005d5455, "BurnerUp"),                     0x005e, 0x0129 },
    {  95, PSTR(0x005d52dc, "BurnerDown"),                   0x005f, 0x012a },
    {  96, PSTR(0x005d4a53, "BurnerLine"),                   0x0060, 0x012b },
    {  97, PSTR(0x005d5811, "BurnerLineLeft"),               0x0061, 0x012c },
    {  98, PSTR(0x005d53ff, "BurnerLineUp"),                 0x0062, 0x012d },
    {  99, PSTR(0x005d5275, "BurnerLineDown"),               0x0063, 0x012e },
    { 100, PSTR(0x005d4e92, "BurnerBlock"),                  0x0064, 0x012f },
    { 101, PSTR(0x005d5820, "BurnerBlockLeft"),              0x0065, 0x0130 },
    { 102, PSTR(0x005d540c, "BurnerBlockUp"),                0x0066, 0x0131 },
    { 103, PSTR(0x005d5284, "BurnerBlockDown"),              0x0067, 0x0132 },
    { 104, PSTR(0x005d576d, "BurnerCross"),                  0x0068, 0x0133 },
    { 105, PSTR(0x005d5c1e, "TarzanIvy"),                    0x0069, 0x013a },
    { 106, PSTR(0x005d4ac0, "TarzanRope"),                   0x006a, 0x013b },
    { 107, PSTR(0x005d56b9, "TarzanChainMgr"),               0x006b, 0x013c },
    { 108, PSTR(0x005d507f, "TarzanChain"),                  0x006c, 0x013d },
    { 109, PSTR(0x005d4e9e, "RouletBlock"),                  0x006d, 0x0146 },
    { 110, PSTR(0x005d4e66, "RouletCoinBlock"),              0x006e, 0x0147 },
    { 111, PSTR(0x005d4b93, "WallMove"),                     0x006f, 0x013e },
    { 112, PSTR(0x005d5a1e, "LiftRailGhost"),                0x0070, 0x00ff },
    { 113, PSTR(0x005d4f58, "LiftRail"),                     0x0071, 0x0100 },
    { 114, PSTR(0x005d4a41, "YukaBane"),                     0x0072, 0x0109 },
    { 115, PSTR(0x005d4799, "YukaBaneChild"),                0x0073, 0x010a },
    { 116, PSTR(0x005d48be, "YukaBaneHide"),                 0x0074, 0x010b },
    { 117, PSTR(0x005d462e, "LarryYuka"),                    0x0075, 0x010c },
    { 118, PSTR(0x005d57f3, "GasaNet"),                      0x0076, 0x001a },
    { 119, PSTR(0x005d4eec, "RotBlockNormal"),               0x0077, 0x016d },
    { 120, PSTR(0x005d5577, "RotBlockChecker"),              0x0078, 0x016e },
    { 121, PSTR(0x005d50b7, "FireCoin"),                     0x0079, 0x00e1 },
    { 122, PSTR(0x005d5567, "FireCoinChanger"),              0x007a, 0x00e3 },
    { 123, PSTR(0x005d57df, "FireCoinJet"),                  0x007b, 0x00e2 },
    { 124, PSTR(0x005d5096, "FunkaCoin"),                    0x007c, 0x00e4 },
    { 125, PSTR(0x005d50c0, "FunsuiCoin"),                   0x007d, 0x00e5 },
    { 126, PSTR(0x005d4cd8, "BubbleArch"),                   0x007e, 0x010d },
    { 127, PSTR(0x005d5c0d, "BubbleArchEntity"),             0x007f, 0x010e },
    { 128, PSTR(0x005d4846, "RailPolyChild"),                0x0080, 0x016f },
    { 129, PSTR(0x005d48b2, "RailPolyIce"),                  0x0081, 0x0170 },
    { 130, PSTR(0x005d4a7a, "LiftRailBone"),                 0x0082, 0x0103 },
    { 131, PSTR(0x005d48a6, "LiftRailIce"),                  0x0083, 0x0104 },
    { 132, PSTR(0x005d4d48, "BeltSwitch"),                   0x0084, 0x010f },
    { 133, PSTR(0x005d4edb, "BeltSwitchNormal"),             0x0085, 0x0110 },
    { 134, PSTR(0x005d52b8, "LiftRideMoveUpDown"),           0x0086, 0x0101 },
    { 135, PSTR(0x005d4b10, "BossFire"),                     0x0087, 0x0114 },
    { 136, PSTR(0x005d4b19, "KoopaLastFire"),                0x0088, 0x0115 },
    { 137, PSTR(0x005d4f86, "RoyWall"),                      0x0089, 0x0088 },
    { 138, PSTR(0x005d578e, "BsLarryObjPolEffect"),          0x008a, 0x0094 },
    { 139, PSTR(0x005d4f06, "LiftBuiBuiWheel"),              0x008b, 0x008c },
    { 140, PSTR(0x005d4f74, "LiftHMoveRideFall"),            0x008c, 0x0102 },
    { 141, PSTR(0x005d52ef, "KoopaClown"),                   0x008d, 0x0079 },
    { 142, PSTR(0x005d49c1, "GoalPole"),                     0x008e, 0x00e9 },
    { 143, PSTR(0x005d4ab5, "CannonPipe"),                   0x008f, 0x017b },
    { 144, PSTR(0x005d552d, "CannonWarp"),                   0x0090, 0x017c },
    { 145, PSTR(0x005d4aaf, "LudwigCannonPipe"),             0x0091, 0x017d },
    { 146, PSTR(0x005d587e, "KoopaLastLift"),                0x0092, 0x0118 },
    { 147, PSTR(0x005d5171, "DokanMorton"),                  0x0093, 0x017e },
    { 148, PSTR(0x005d4790, "IggySled"),                     0x0094, 0x0090 },
    { 149, PSTR(0x005d477c, "KoopaHead"),                    0x0095, 0x0112 },
    { 150, PSTR(0x005d455a, "KoopaHead2"),                   0x0096, 0x0113 },
    { 151, PSTR(0x005d53d4, "KoopaLastDemo"),                0x0097, 0x0119 },
    { 152, PSTR(0x005d54a8, "TreasureShip"),                 0x0098, 0x0111 },
    { 153, PSTR(0x005d5a5f, "LiftKoopaNext"),                0x0099, 0x0086 },
    { 154, PSTR(0x005d45b6, "LiftChandelierS"),              0x009a, 0x0105 },
    { 155, PSTR(0x005d4592, "LiftChandelierM"),              0x009b, 0x0106 },
    { 156, PSTR(0x005d4582, "LiftChandelierL"),              0x009c, 0x0107 },
    { 157, PSTR(0x005d4e43, "PunchBlock"),                   0x009d, 0x0181 },
    { 158, PSTR(0x005d4b87, "LemmyStatue"),                  0x009e, 0x009a },
    { 159, PSTR(0x005d545e, "KoopaLastLiftUp"),              0x009f, 0x0108 },
    { 160, PSTR(0x005d4e4e, "ObjNukiBlock"),                 0x00a0, 0x01b6 },
    { 161, PSTR(0x005d4eb3, "Block"),                        0x00a1, 0x00b4 },
    { 162, PSTR(0x005d4e5b, "BreakBlock"),                   0x00a2, 0x00b5 },
    { 163, PSTR(0x005d5c28, "BlockOutIvy"),                  0x00a3, 0x00b6 },
    { 164, PSTR(0x005d4935, "ActorBlockRengaAngle"),         0x00a4, 0x00b8 },
    { 165, PSTR(0x005d494a, "ActorBlockHatenaAngle"),        0x00a5, 0x00b9 },
    { 166, PSTR(0x005d4960, "ActorBlockUnbrokenAngle"),      0x00a6, 0x00ba },
    { 167, PSTR(0x005d47b2, "ActorBlockRengaPairChild"),     0x00a7, 0x00bb },
    { 168, PSTR(0x005d47cb, "ActorBlockHatenaPairChild"),    0x00a8, 0x00bc },
    { 169, PSTR(0x005d4cc3, "ActorBlockHatenaLong"),         0x00a9, 0x00bd },
    { 170, PSTR(0x005d45f1, "ActorBlockHatenaLongChika"),    0x00aa, 0x00be },
    { 171, PSTR(0x005d46cc, "ActorBlockHatenaLongLava"),     0x00ab, 0x00bf },
    { 172, PSTR(0x005d4cf5, "ActorBlockHatenaSwitch"),       0x00ac, 0x00c0 },
    { 173, PSTR(0x005d4ce3, "ActorBlockPSwitch"),            0x00ad, 0x00c1 },
    { 174, PSTR(0x005d4d25, "ActorBlockBikkuriSwitch"),      0x00ae, 0x00c2 },
    { 175, PSTR(0x005d46b4, "ActorBlockPata"),               0x00af, 0x00c5 },
    { 176, PSTR(0x005d54b5, "ActorBlockJump"),               0x00b0, 0x00c3 },
    { 177, PSTR(0x005d482e, "ActorBlockJumpPairChild"),      0x00b1, 0x00c4 },
    { 178, PSTR(0x005d4e0f, "ActorBlockShock"),              0x00b2, 0x00c9 },
    { 179, PSTR(0x005d47e5, "ActorBlockShockPairChild"),     0x00b3, 0x00ca },
    { 180, PSTR(0x005d5ac3, "ActorBlockPataNigeru"),         0x00b4, 0x00cb },
    { 181, PSTR(0x005d5478, "ActorBlockHatenaCap"),          0x00b5, 0x00c6 },
    { 182, PSTR(0x005d5a01, "ActorBlockAssist"),             0x00b6, 0x00b7 },
    { 183, PSTR(0x005d4811, "ActorBlockHatenaCapPairChild"), 0x00b7, 0x00c8 },
    { 184, PSTR(0x005d4d0c, "ActorBlockRouletteSwitch"),     0x00b8, 0x00cc },
    { 185, PSTR(0x005d460b, "ActorBlockFunka"),              0x00b9, 0x00cd },
    { 186, PSTR(0x005d4691, "ActorBlockGoldPata"),           0x00ba, 0x00ce },
    { 187, PSTR(0x005d4e1f, "ChikuwaBlock"),                 0x00bb, 0x0155 },
    { 188, PSTR(0x005d51ae, "SwitchHatenaButton"),           0x00bc, 0x0136 },
    { 189, PSTR(0x005d51d5, "SwitchPbutton"),                0x00bd, 0x0137 },
    { 190, PSTR(0x005d51c1, "SwitchBikkuriButton"),          0x00be, 0x0138 },
    { 191, PSTR(0x005d4d7a, "KillerHoudai"),                 0x00bf, 0x0054 },
    { 192, PSTR(0x005d4d74, "MagnumKillerHoudai"),           0x00c0, 0x0057 },
    { 193, PSTR(0x005d4d67, "KaitenHoudai"),                 0x00c1, 0x0058 },
    { 194, PSTR(0x005d55a2, "MagnumKiller"),                 0x00c2, 0x0056 },
    { 195, PSTR(0x005d55a8, "Killer"),                       0x00c3, 0x0053 },
    { 196, PSTR(0x005d5595, "SearchKiller"),                 0x00c4, 0x0055 },
    { 197, PSTR(0x005d5052, "Battan"),                       0x00c5, 0x0038 },
    { 198, PSTR(0x005d5b6e, "GateOneway"),                   0x00c6, 0x0145 },
    { 199, PSTR(0x005d5538, "FireBar"),                      0x00c7, 0x015b },
    { 200, PSTR(0x005d561d, "BossShutter"),                  0x00c8, 0x0116 },
    { 201, PSTR(0x005d4648, "BossShutterKoopa"),             0x00c9, 0x0117 },
    { 202, PSTR(0x005d4eaa, "KoopaLastBlock"),               0x00ca, 0x019c },
    { 203, PSTR(0x005d4d53, "LemmySwitch"),                  0x00cb, 0x0099 },
    { 204, PSTR(0x005d4f6a, "LemmyBall"),                    0x00cc, 0x0096 },
    { 205, PSTR(0x005d4709, "LemmyBallMagic"),               0x00cd, 0x0097 },
    { 206, PSTR(0x005d49fb, "LemmyBallCastle"),              0x00ce, 0x0098 },
    { 207, PSTR(0x005d50f4, "ActorCoin"),                    0x00cf, 0x00cf },
    { 208, PSTR(0x005d54c4, "ActorCoinJump"),                0x00d0, 0x00d0 },
    { 209, PSTR(0x005d461b, "ActorCoinJumpFunka"),           0x00d1, 0x00d1 },
    { 210, PSTR(0x005d4dee, "ActorCoinJumpFunsui"),          0x00d2, 0x00d2 },
    { 211, PSTR(0x005d4afe, "ActorCoinJumpFire"),            0x00d3, 0x00d3 },
    { 212, PSTR(0x005d54d2, "ActorCoinDemoJump"),            0x00d4, 0x00d4 },
    { 213, PSTR(0x005d54e4, "ActorCoinShowerJump"),          0x00d5, 0x00d5 },
    { 214, PSTR(0x005d50a0, "RedCoin"),                      0x00d6, 0x00d6 },
    { 215, PSTR(0x005d4978, "RedCoinAngle"),                 0x00d7, 0x00d7 },
    { 216, PSTR(0x005d590b, "RedCoinParaParent"),            0x00d8, 0x00d8 },
    { 217, PSTR(0x005d50cb, "CollectionCoin"),               0x00d9, 0x0016 },
    { 218, PSTR(0x005d4985, "CollectionCoinAngle"),          0x00da, 0x0017 },
    { 219, PSTR(0x005d5a76, "ActorCoinPuku"),                0x00db, 0x00d9 },
    { 220, PSTR(0x005d4565, "ActorCoinPuku2"),               0x00dc, 0x00da },
    { 221, PSTR(0x005d4916, "ActorCoinBubble"),              0x00dd, 0x00db },
    { 222, PSTR(0x005d4adf, "ActorCoinBubbleFire"),          0x00de, 0x00dc },
    { 223, PSTR(0x005d59b8, "ActorCoinRot"),                 0x00df, 0x00dd },
    { 224, PSTR(0x005d49a7, "ActorCoinAngle"),               0x00e0, 0x00de },
    { 225, PSTR(0x005d5749, "ActorCoinBros"),                0x00e1, 0x00df },
    { 226, PSTR(0x005d47fe, "ActorCoinPairChild"),           0x00e2, 0x00e0 },
    { 227, PSTR(0x005d4b62, "ActorCoinRoulette"),            0x00e3, 0x00e6 },
    { 228, PSTR(0x005d5aef, "ActorCoinHakusyu"),             0x00e4, 0x00e7 },
    { 229, PSTR(0x005d50da, "MoonCoin"),                     0x00e5, 0x0018 },
    { 230, PSTR(0x005d4999, "MoonCoinAngle"),                0x00e6, 0x0019 },
    { 231, PSTR(0x005d4d9c, "ActorCoinNagareboshi"),         0x00e7, 0x00e8 },
    { 232, PSTR(0x005d4f2c, "WireRail"),                     0x00e8, 0x0171 },
    { 233, PSTR(0x005d4f8e, "WireRailSmall"),                0x00e9, 0x0172 },
    { 234, PSTR(0x005d4926, "WireRailMiddle"),               0x00ea, 0x0173 },
    { 235, PSTR(0x005d4a4a, "WireLine"),                     0x00eb, 0x0174 },
    { 236, PSTR(0x005d48cb, "WireLineSlide"),                0x00ec, 0x0175 },
    { 237, PSTR(0x005d5152, "Balloon"),                      0x00ed, 0x0014 },
    { 238, PSTR(0x005d57a2, "PlayerObject"),                 0x00ee, 0x0015 },
    { 239, PSTR(0x005d5640, "KuriboTower"),                  0x00ef, 0x001b },
    { 240, PSTR(0x005d530a, "Kuribo"),                       0x00f0, 0x001c },
    { 241, PSTR(0x005d4a87, "KuriboBone"),                   0x00f1, 0x001d },
    { 242, PSTR(0x005d52fa, "PataKuribo"),                   0x00f2, 0x001e },
    { 243, PSTR(0x005d5305, "BeansKuribo"),                  0x00f3, 0x001f },
    { 244, PSTR(0x005d536b, "Nokonoko"),                     0x00f4, 0x0020 },
    { 245, PSTR(0x005d46c3, "Patapata"),                     0x00f5, 0x0021 },
    { 246, PSTR(0x005d45a8, "NetNokonokoLR"),                0x00f6, 0x0023 },
    { 247, PSTR(0x005d4574, "NetNokonokoUD"),                0x00f7, 0x0024 },
    { 248, PSTR(0x005d59ac, "PatapataRot"),                  0x00f8, 0x0022 },
    { 249, PSTR(0x005d593b, "PatapataRotParent"),            0x00f9, 0x0185 },
    { 250, PSTR(0x005d515d, "Karon"),                        0x00fa, 0x0025 },
    { 251, PSTR(0x005d515a, "BigKaron"),                     0x00fb, 0x0026 },
    { 252, PSTR(0x005d4786, "KaronHead"),                    0x00fc, 0x0027 },
    { 253, PSTR(0x005d57ef, "Met"),                          0x00fd, 0x0028 },
    { 254, PSTR(0x005d53f8, "Togezo"),                       0x00fe, 0x0029 },
    { 255, PSTR(0x005d53f1, "ReverseTogezo"),                0x00ff, 0x002a },
    { 256, PSTR(0x005d467e, "Basabasa"),                     0x0100, 0x002b },
    { 257, PSTR(0x005d4d8b, "Bomhei"),                       0x0101, 0x002c },
    { 258, PSTR(0x005d4d87, "ParaBomhei"),                   0x0102, 0x002d },
    { 259, PSTR(0x005d526e, "Dossun"),                       0x0103, 0x002e },
    { 260, PSTR(0x005d526b, "BigDossun"),                    0x0104, 0x002f },
    { 261, PSTR(0x005d5a9f, "Pukupuku"),                     0x0105, 0x0030 },
    { 262, PSTR(0x005d5a8d, "WakiPukupuku"),                 0x0106, 0x0031 },
    { 263, PSTR(0x005d550e, "PukupukuJump"),                 0x0107, 0x0032 },
    { 264, PSTR(0x005d50e3, "PukupukuJumpCoin"),             0x0108, 0x0033 },
    { 265, PSTR(0x005d54f8, "WakiPukupukuJump"),             0x0109, 0x0034 },
    { 266, PSTR(0x005d59c5, "PukupukuRot"),                  0x010a, 0x005c },
    { 267, PSTR(0x005d594d, "PukupukuRotParent"),            0x010b, 0x0184 },
    { 268, PSTR(0x005d5a9a, "WendyPukupuku"),                0x010c, 0x0035 },
    { 269, PSTR(0x005d5509, "WendyPukupukuJump"),            0x010d, 0x0036 },
    { 270, PSTR(0x005d4640, "Keronpa"),                      0x010e, 0x0037 },
    { 271, PSTR(0x005d488e, "JugemCloud"),                   0x010f, 0x0039 },
    { 272, PSTR(0x005d50a8, "JugemCloudCoin"),               0x0110, 0x003a },
    { 273, PSTR(0x005d5b97, "JugemBody"),                    0x0111, 0x003b },
    { 274, PSTR(0x005d4fbd, "WakiJugem"),                    0x0112, 0x003c },
    { 275, PSTR(0x005d5757, "HammerBros"),                   0x0113, 0x003d },
    { 276, PSTR(0x005d5724, "BoomerangBros"),                0x0114, 0x003e },
    { 277, PSTR(0x005d571b, "FireBros"),                     0x0115, 0x003f },
    { 278, PSTR(0x005d5068, "Fugumannen"),                   0x0116, 0x0041 },
    { 279, PSTR(0x005d525f, "JimenPakkun"),                  0x0117, 0x0042 },
    { 280, PSTR(0x005d520e, "JimenBonePakkun"),              0x0118, 0x0044 },
    { 281, PSTR(0x005d5241, "JimenBigPakkun"),               0x0119, 0x0043 },
    { 282, PSTR(0x005d51fb, "JimenBigBonePakkun"),           0x011a, 0x0045 },
    { 283, PSTR(0x005d5231, "JimenFirePakkun"),              0x011b, 0x0046 },
    { 284, PSTR(0x005d521e, "JimenBigFirePakkun"),           0x011c, 0x0047 },
    { 285, PSTR(0x005d543e, "DokanPakkunUp"),                0x011d, 0x0048 },
    { 286, PSTR(0x005d52a8, "DokanPakkunDown"),              0x011e, 0x0049 },
    { 287, PSTR(0x005d5858, "DokanPakkunLeft"),              0x011f, 0x004a },
    { 288, PSTR(0x005d58ce, "DokanPakkunRight"),             0x0120, 0x004b },
    { 289, PSTR(0x005d541a, "DokanBonePakkunUp"),            0x0121, 0x004c },
    { 290, PSTR(0x005d5830, "DokanBonePakkunLeft"),          0x0122, 0x004d },
    { 291, PSTR(0x005d58a4, "DokanBonePakkunRight"),         0x0123, 0x004e },
    { 292, PSTR(0x005d542c, "DokanFirePakkunUp"),            0x0124, 0x004f },
    { 293, PSTR(0x005d5294, "DokanFirePakkunDown"),          0x0125, 0x0050 },
    { 294, PSTR(0x005d5844, "DokanFirePakkunLeft"),          0x0126, 0x0051 },
    { 295, PSTR(0x005d58b9, "DokanFirePakkunRight"),         0x0127, 0x0052 },
    { 296, PSTR(0x005d5a84, "Togepuku"),                     0x0128, 0x0059 },
    { 297, PSTR(0x005d4c49, "PukupukuBig"),                  0x0129, 0x005a },
    { 298, PSTR(0x005d50fe, "PukupukuCoin"),                 0x012a, 0x005b },
    { 299, PSTR(0x005d468a, "Teresa"),                       0x012b, 0x005d },
    { 300, PSTR(0x005d4687, "BigTeresa"),                    0x012c, 0x005e },
    { 301, PSTR(0x005d45d7, "TeresaMega"),                   0x012d, 0x005f },
    { 302, PSTR(0x005d53eb, "Gesso"),                        0x012e, 0x0061 },
    { 303, PSTR(0x005d4b27, "GessoKodure"),                  0x012f, 0x0062 },
    { 304, PSTR(0x005d47a7, "GessoChild"),                   0x0130, 0x0063 },
    { 305, PSTR(0x005d5ad8, "Birikyu"),                      0x0131, 0x0064 },
    { 306, PSTR(0x005d59d1, "BirikyuRot"),                   0x0132, 0x0065 },
    { 307, PSTR(0x005d595f, "BirikyuRotParent"),             0x0133, 0x0186 },
    { 308, PSTR(0x005d5064, "WakiFugumannen"),               0x0134, 0x0066 },
    { 309, PSTR(0x005d5311, "Sanbo"),                        0x0135, 0x0067 },
    { 310, PSTR(0x005d4ecf, "SanboDeadEl"),                  0x0136, 0x0068 },
    { 311, PSTR(0x005d491f, "Bubble"),                       0x0137, 0x0069 },
    { 312, PSTR(0x005d4723, "BubbleSync"),                   0x0138, 0x006a },
    { 313, PSTR(0x005d490c, "FireSnake"),                    0x0139, 0x011a },
    { 314, PSTR(0x005d5033, "Hanachan"),                     0x013a, 0x006b },
    { 315, PSTR(0x005d505d, "Wanwan"),                       0x013b, 0x006c },
    { 316, PSTR(0x005d57eb, "TogeMet"),                      0x013c, 0x006d },
    { 317, PSTR(0x005d5a6d, "Bakubaku"),                     0x013d, 0x006e },
    { 318, PSTR(0x005d573f, "HimanBros"),                    0x013e, 0x0040 },
    { 319, PSTR(0x005d5b45, "Crow"),                         0x013f, 0x006f },
    { 320, PSTR(0x005d53e2, "Gasagoso"),                     0x0140, 0x0070 },
    { 321, PSTR(0x005d59a2, "TeresaRot"),                    0x0141, 0x0060 },
    { 322, PSTR(0x005d592b, "TeresaRotParent"),              0x0142, 0x0183 },
    { 323, PSTR(0x005d4678, "Unira"),                        0x0143, 0x0071 },
    { 324, PSTR(0x005d5073, "UniraKaiten"),                  0x0144, 0x0072 },
    { 325, PSTR(0x005d473d, "UniraKaitenSync"),              0x0145, 0x0073 },
    { 326, PSTR(0x005d4a71, "FishBone"),                     0x0146, 0x0074 },
    { 327, PSTR(0x005d4dd1, "Garigari"),                     0x0147, 0x0075 },
    { 328, PSTR(0x005d4c29, "GarigariBig"),                  0x0148, 0x0076 },
    { 329, PSTR(0x005d510b, "Chorobon"),                     0x0149, 0x0077 },
    { 330, PSTR(0x005d4d92, "Gamaguchi"),                    0x014a, 0x0078 },
    { 331, PSTR(0x005d5059, "IggyWanwan"),                   0x014b, 0x0091 },
    { 332, PSTR(0x005d531b, "Kinopio"),                      0x014c, 0x007a },
    { 333, PSTR(0x005d4877, "EndingBird"),                   0x014d, 0x007c },
    { 334, PSTR(0x005d59f7, "KoopaLast"),                    0x014e, 0x007d },
    { 335, PSTR(0x005d4a92, "KoopaLastBone"),                0x014f, 0x007e },
    { 336, PSTR(0x005d465d, "Koopa"),                        0x0150, 0x007f },
    { 337, PSTR(0x005d4a67, "KoopaBone"),                    0x0151, 0x0080 },
    { 338, PSTR(0x005d5bef, "Roy"),                          0x0152, 0x0087 },
    { 339, PSTR(0x005d5b91, "Wendy"),                        0x0153, 0x0089 },
    { 340, PSTR(0x005d51a7, "Morton"),                       0x0154, 0x008a },
    { 341, PSTR(0x005d4de7, "BuiBui"),                       0x0155, 0x008b },
    { 342, PSTR(0x005d5bc6, "Iggy"),                         0x0156, 0x008f },
    { 343, PSTR(0x005d4c7c, "Ludwig"),                       0x0157, 0x0092 },
    { 344, PSTR(0x005d5c07, "Larry"),                        0x0158, 0x0093 },
    { 345, PSTR(0x005d5bd3, "Lemmy"),                        0x0159, 0x0095 },
    { 346, PSTR(0x005d5762, "EndingBoss"),                   0x015a, 0x009b },
    { 347, PSTR(0x005d5667, "FireBallPlayer"),               0x015b, 0x009c },
    { 348, PSTR(0x005d5732, "FireBallBros"),                 0x015c, 0x009d },
    { 349, PSTR(0x005d5250, "FireBallPakkun"),               0x015d, 0x009e },
    { 350, PSTR(0x005d4638, "FireBallKeronpa"),              0x015e, 0x009f },
    { 351, PSTR(0x005d55bf, "Hammer"),                       0x015f, 0x00a0 },
    { 352, PSTR(0x005d4c83, "Boomerang"),                    0x0160, 0x00a1 },
    { 353, PSTR(0x005d55af, "MegaHammer"),                   0x0161, 0x00a2 },
    { 354, PSTR(0x005d46fc, "KokoopaMagic"),                 0x0162, 0x00a3 },
    { 355, PSTR(0x005d4718, "LarryMagic"),                   0x0163, 0x00a4 },
    { 356, PSTR(0x005d4af3, "BuiBuiFire"),                   0x0164, 0x00a5 },
    { 357, PSTR(0x005d4ad5, "KoopaFire"),                    0x0165, 0x00a6 },
    { 358, PSTR(0x005d55ba, "KoopaHammer"),                  0x0166, 0x00a7 },
    { 359, PSTR(0x005d5364, "Kinoko"),                       0x0167, 0x00a9 },
    { 360, PSTR(0x005d565c, "FireFlower"),                   0x0168, 0x00aa },
    { 361, PSTR(0x005d5651, "GoldFlower"),                   0x0169, 0x00ab },
    { 362, PSTR(0x005d5545, "Star"),                         0x016a, 0x00ac },
    { 363, PSTR(0x005d5333, "MameKinoko"),                   0x016b, 0x00ad },
    { 364, PSTR(0x005d5354, "OneUpKinoko"),                  0x016c, 0x00ae },
    { 365, PSTR(0x005d533e, "BigKinoko"),                    0x016d, 0x00af },
    { 366, PSTR(0x005d4bc5, "Leaf"),                         0x016e, 0x00b0 },
    { 367, PSTR(0x005d4b58, "LeafWhite"),                    0x016f, 0x00b1 },
    { 368, PSTR(0x005d564c, "PanelGoldFlower"),              0x0170, 0x00b2 },
    { 369, PSTR(0x005d5540, "PanelStar"),                    0x0171, 0x00b3 },
    { 370, PSTR(0x005d4c8d, "RedRing"),                      0x0172, 0x011c },
    { 371, PSTR(0x005d4c95, "YellowRing"),                   0x0173, 0x011d },
    { 372, PSTR(0x005d5ae4, "TogeTekkyu"),                   0x0174, 0x011e },
    { 373, PSTR(0x005d4c55, "TogeTekkyuBig"),                0x0175, 0x011f },
    { 374, PSTR(0x005d45e2, "TogeTekkyuMega"),               0x0176, 0x0120 },
    { 375, PSTR(0x005d519d, "TogeTekkyuMorton"),             0x0177, 0x0121 },
    { 376, PSTR(0x005d5ae0, "WakiTogeTekkyu"),               0x0178, 0x019f },
    { 377, PSTR(0x005d4761, "WakiTogeTekkyuSync"),           0x0179, 0x01a0 },
    { 378, PSTR(0x005d4e0a, "Rock"),                         0x017a, 0x0122 },
    { 379, PSTR(0x005d4c35, "RockBig"),                      0x017b, 0x0123 },
    { 380, PSTR(0x005d4f61, "SnowBall"),                     0x017c, 0x0124 },
    { 381, PSTR(0x005d4c3d, "SnowBallBig"),                  0x017d, 0x0125 },
    { 382, PSTR(0x005d5b4a, "KanbanArrow"),                  0x017e, 0x0134 },
    { 383, PSTR(0x005d5522, "KanbanWarp"),                   0x017f, 0x0135 },
    { 384, PSTR(0x005d4d3d, "DoorSwitch"),                   0x0180, 0x0148 },
    { 385, PSTR(0x005d4efb, "DoorNormal"),                   0x0181, 0x0149 },
    { 386, PSTR(0x005d4902, "DoorObake"),                    0x0182, 0x014a },
    { 387, PSTR(0x005d48e6, "DoorToride"),                   0x0183, 0x014b },
    { 388, PSTR(0x005d4a2a, "DoorCastle"),                   0x0184, 0x014c },
    { 389, PSTR(0x005d4659, "DoorKoopa"),                    0x0185, 0x014d },
    { 390, PSTR(0x005d4b33, "DoorClose"),                    0x0186, 0x014e },
    { 391, PSTR(0x005d5360, "DoorKinoko"),                   0x0187, 0x014f },
    { 392, PSTR(0x005d5317, "DoorKinopio"),                  0x0188, 0x0150 },
    { 393, PSTR(0x005d503c, "WakiDokan"),                    0x0189, 0x019e },
    { 394, PSTR(0x005d4c1a, "CheckPointFlag"),               0x018a, 0x00a8 },
    { 395, PSTR(0x005d502a, "Kazandan"),                     0x018b, 0x0187 },
    { 396, PSTR(0x005d55da, "DiveInWater"),                  0x018c, 0x011b },
    { 397, PSTR(0x005d5a48, "ActorBlockHatenaCapPut"),       0x018d, 0x00c7 },
    { 398, PSTR(0x005d56ef, "BuiBuiFloor"),                  0x018e, 0x008d },
    { 399, PSTR(0x005d4f0a, "BuiBuiWheel"),                  0x018f, 0x008e },
    { 400, PSTR(0x005d56e4, "KoopaFloor"),                   0x0190, 0x0084 },
    { 401, PSTR(0x005d4d5f, "Jumpdai"),                      0x0191, 0x0156 },
    { 402, PSTR(0x005d4eb9, "TimerClock"),                   0x0192, 0x0157 },
    { 403, PSTR(0x005d4ec4, "LeaderMark"),                   0x0193, 0x0158 },
    { 404, PSTR(0x005d5779, "ActorItemStockEffect"),         0x0194, 0x01b5 },
    { 405, PSTR(0x005d53c5, "KoopaClownDemo"),               0x0195, 0x0081 },
    { 406, PSTR(0x005d539e, "PeachCageDemo"),                0x0196, 0x0085 },
    { 407, PSTR(0x005d538a, "KokoopaPeachEndDemo"),          0x0197, 0x0082 },
    { 408, PSTR(0x005d5ba1, "CastleBossKey"),                0x0198, 0x0083 },
    { 409, PSTR(0x005d4ca0, "PeachEnding"),                  0x0199, 0x007b },
    { 410, PSTR(0x005d5805, "BigPileLeft"),                  0x019a, 0x0151 },
    { 411, PSTR(0x005d5897, "BigPileRight"),                 0x019b, 0x0152 },
    { 412, PSTR(0x005d554a, "BigPileUnder"),                 0x019c, 0x0153 },
    { 413, PSTR(0x005d55cd, "BigPileUpper"),                 0x019d, 0x0154 },
    { 414, PSTR(0x005d5b5e, "ItemTreasureBox"),              0x019e, 0x0188 },
    { 415, PSTR(0x005d4fa3, "BubbleControl"),                0x019f, 0x015f },
    { 416, PSTR(0x005d57fb, "MaxUeLeft"),                    0x01a0, 0x0189 },
    { 417, PSTR(0x005d588c, "MaxUeRight"),                   0x01a1, 0x018a },
    { 418, PSTR(0x005d544c, "LrStopUp"),                     0x01a2, 0x018b },
    { 419, PSTR(0x005d5b04, "LrStopDw"),                     0x01a3, 0x018c },
    { 420, PSTR(0x005d5614, "BgCenter"),                     0x01a4, 0x018d },
    { 421, PSTR(0x005d4c01, "AutoScrollTag"),                0x01a5, 0x018e },
    { 422, PSTR(0x005d5b18, "ScrollView"),                   0x01a6, 0x018f },
    { 423, PSTR(0x005d58df, "RailLimit"),                    0x01a7, 0x0190 },
    { 424, PSTR(0x005d51e3, "NukiAtariKun"),                 0x01a8, 0x0191 },
    { 425, PSTR(0x005d5704, "PlayerBigRes"),                 0x01a9, 0x0192 },
    { 426, PSTR(0x005d5711, "BattanRes"),                    0x01aa, 0x0193 },
    { 427, PSTR(0x005d4a35, "DorifuAnime"),                  0x01ab, 0x0194 },
    { 428, PSTR(0x005d4fc7, "NoStockItem"),                  0x01ac, 0x0195 },
    { 429, PSTR(0x005d514c, "NoItemBalloon"),                0x01ad, 0x0196 },
    { 430, PSTR(0x005d4c0f, "EnvStarTag"),                   0x01ae, 0x0197 },
    { 431, PSTR(0x005d4be7, "EnvSporeTag"),                  0x01af, 0x0198 },
    { 432, PSTR(0x005d4e76, "NextGotoBlock"),                0x01b0, 0x0199 },
    { 433, PSTR(0x005d4e84, "ObjClearBlock"),                0x01b1, 0x019a },
    { 434, PSTR(0x005d4e2c, "ChangeBlock"),                  0x01b2, 0x019b },
    { 435, PSTR(0x005d56ad, "KazandanMgr"),                  0x01b3, 0x01a8 },
    { 436, PSTR(0x005d5697, "ItemHouseMgr"),                 0x01b4, 0x01b3 },
    { 437, PSTR(0x005d4e02, "ItemObj"),                      0x01b5, 0x01b4 },
    { 438, PSTR(0x005d51f0, "HakushuKun"),                   0x01b6, 0x019d },
    { 439, PSTR(0x005d56c8, "KoopaLastLiftMgr"),             0x01b7, 0x01a9 },
    { 440, PSTR(0x005d56d9, "BsEventMgr"),                   0x01b8, 0x01b8 },
    { 441, PSTR(0x005d5689, "BsSequenceMgr"),                0x01b9, 0x01b9 },
    { 442, PSTR(0x005d486b, "MapObjBoard"),                  0x01ba, 0x01b7 },
    { 443, PSTR(0x005d4854, "MapObjWorld"),                  0x01bb, 0x01bb },
    { 444, PSTR(0x005d597f, "MapObjCoursePoint"),            0x01bc, 0x01bc },
    { 445, PSTR(0x005d5991, "MapObjStartPoint"),             0x01bd, 0x01bd },
    { 446, PSTR(0x005d5b23, "MapObjPointRainbow"),           0x01be, 0x01be },
    { 447, PSTR(0x005d49ca, "MapObjKoopaCastle"),            0x01bf, 0x01bf },
    { 448, PSTR(0x005d49dc, "MapObjPeachCastle"),            0x01c0, 0x01c0 },
    { 449, PSTR(0x005d49ee, "MapObjCastle"),                 0x01c1, 0x01c1 },
    { 450, PSTR(0x005d5634, "MapObjTower"),                  0x01c2, 0x01c2 },
    { 451, PSTR(0x005d5a12, "MapObjGhost"),                  0x01c3, 0x01c3 },
    { 452, PSTR(0x005d4b46, "MapObjKinokoHouse"),            0x01c4, 0x01c4 },
    { 453, PSTR(0x005d5134, "MapObjCannon"),                 0x01c5, 0x01c5 },
    { 454, PSTR(0x005d501d, "MapObjKanban"),                 0x01c6, 0x01c7 },
    { 455, PSTR(0x005d5046, "MapObjDokan"),                  0x01c7, 0x01c8 },
    { 456, PSTR(0x005d5557, "MapObjSurrender"),              0x01c8, 0x01c9 },
    { 457, PSTR(0x005d4882, "MapObjCloud"),                  0x01c9, 0x01ca },
    { 458, PSTR(0x005d5bbe, "BossDemoIggy"),                 0x01ca, 0x01cb },
    { 459, PSTR(0x005d52e7, "BossDemoKoopaClown"),           0x01cb, 0x01cc },
    { 460, PSTR(0x005d5bff, "BossDemoLarry"),                0x01cc, 0x01cd },
    { 461, PSTR(0x005d5bcb, "BossDemoLemmy"),                0x01cd, 0x01ce },
    { 462, PSTR(0x005d4c74, "BossDemoLudwig"),               0x01ce, 0x01cf },
    { 463, PSTR(0x005d518e, "BossDemoMorton"),               0x01cf, 0x01d0 },
    { 464, PSTR(0x005d5be7, "BossDemoRoy"),                  0x01d0, 0x01d1 },
    { 465, PSTR(0x005d5b89, "BossDemoWendy"),                0x01d1, 0x01d2 },
    { 466, PSTR(0x005d5676, "CourseSelectPlayer"),           0x01d2, 0x01d3 },
    { 467, PSTR(0x005d46a4, "MapObjBlockPata"),              0x01d3, 0x01c6 },
    { 468, PSTR(0x005d58fa, "BsEventAssistant"),             0x01d4, 0x01d4 },
    { 469, PSTR(0x005d4663, "CourseSelectBsCamera"),         0x01d5, 0x01ba },
};


#define PROFILE(c, d) \
    { (ProcCreateFunction)c, (ProcDestroyFunction)d }

Profile Profiles[ProfileId::Num] =
{
    PROFILE(0x00557334, 0x0055b1f0),    //   0
    PROFILE(0x00557374, 0x0055b208),    //   1
    PROFILE(0x005573d4, 0x0055b238),    //   2
    PROFILE(0x005573b4, 0x0055b220),    //   3
    PROFILE(0x0055b028, 0x0055d7a0),    //   4
    PROFILE(0x00558164, 0x0055bac0),    //   5
    PROFILE(0x00558be0, 0x0055c0c0),    //   6
    PROFILE(0x00559444, 0x0055c5d0),    //   7
    PROFILE(0x00559de8, 0x0055cc60),    //   8
    PROFILE(0x005599e8, 0x0055c9a8),    //   9
    PROFILE(0x00557a30, 0x0055b658),    //  10
    PROFILE(0x0055ab74, 0x0055d4e8),    //  11
    PROFILE(0x0055a5a4, 0x0055d140),    //  12
    PROFILE(0x00558620, 0x0055bda8),    //  13
    PROFILE(0x00559a08, 0x0055c9c0),    //  14
    PROFILE(0x005597d4, 0x0055c840),    //  15
    PROFILE(0x0055ab54, 0x0055d4d0),    //  16
    PROFILE(0x005579f0, 0x0055b628),    //  17
    PROFILE(0x00559464, 0x0055c5e8),    //  18
    PROFILE(0x00557a10, 0x0055b640),    //  19
    PROFILE(0x0055a3ac, 0x0055d020),    //  20
    PROFILE(0x00558944, 0x0055bef8),    //  21
    PROFILE(0x005583b0, 0x0055bbf8),    //  22
    PROFILE(0x00559910, 0x0055c918),    //  23
    PROFILE(0x00559c18, 0x0055cb28),    //  24
    PROFILE(0x00559934, 0x0055c930),    //  25
    PROFILE(0x00559f48, 0x0055cd50),    //  26
    PROFILE(0x00558b50, 0x0055c060),    //  27
    PROFILE(0x005593fc, 0x0055c5a0),    //  28
    PROFILE(0x0055a70c, 0x0055d200),    //  29
    PROFILE(0x00559200, 0x0055c468),    //  30
    PROFILE(0x00559bf4, 0x0055cb10),    //  31
    PROFILE(0x00557d2c, 0x0055b808),    //  32
    PROFILE(0x005595c0, 0x0055c6d8),    //  33
    PROFILE(0x00557ec8, 0x0055b928),    //  34
    PROFILE(0x0055745c, 0x0055b298),    //  35
    PROFILE(0x0055745c, 0x0055b298),    //  36
    PROFILE(0x0055745c, 0x0055b298),    //  37
    PROFILE(0x0055745c, 0x0055b298),    //  38
    PROFILE(0x0055745c, 0x0055b298),    //  39
    PROFILE(0x0055745c, 0x0055b298),    //  40
    PROFILE(0x0055745c, 0x0055b298),    //  41
    PROFILE(0x0055aef0, 0x0055d6c8),    //  42
    PROFILE(0x00558a18, 0x0055bf88),    //  43
    PROFILE(0x00558a38, 0x0055bfa0),    //  44
    PROFILE(0x00558a38, 0x0055bfa0),    //  45
    PROFILE(0x005577b4, 0x0055b4d8),    //  46
    PROFILE(0x005577b4, 0x0055b4d8),    //  47
    PROFILE(0x00559958, 0x0055c948),    //  48
    PROFILE(0x0055976c, 0x0055c7f8),    //  49
    PROFILE(0x0055976c, 0x0055c7f8),    //  50
    PROFILE(0x0055aa88, 0x0055d440),    //  51
    PROFILE(0x0055aaac, 0x0055d458),    //  52
    PROFILE(0x00558484, 0x0055bc88),    //  53
    PROFILE(0x00559380, 0x0055c570),    //  54
    PROFILE(0x00557864, 0x0055b550),    //  55
    PROFILE(0x00559748, 0x0055c7e0),    //  56
    PROFILE(0x00557888, 0x0055b568),    //  57
    PROFILE(0x005578ac, 0x0055b580),    //  58
    PROFILE(0x0055935c, 0x0055c558),    //  59
    PROFILE(0x0055b18c, 0x0055d7e8),    //  60
    PROFILE(0x005581a8, 0x0055baf0),    //  61
    PROFILE(0x005581a8, 0x0055baf0),    //  62
    PROFILE(0x005582dc, 0x0055bb68),    //  63
    PROFILE(0x00557c0c, 0x0055b748),    //  64
    PROFILE(0x00558754, 0x0055be80),    //  65
    PROFILE(0x005582bc, 0x0055bb50),    //  66
    PROFILE(0x00557bc4, 0x0055b718),    //  67
    PROFILE(0x00557ba0, 0x0055b700),    //  68
    PROFILE(0x0055a584, 0x0055d128),    //  69
    PROFILE(0x00558b2c, 0x0055c048),    //  70
    PROFILE(0x00558530, 0x0055bd00),    //  71
    PROFILE(0x00558004, 0x0055b9d0),    //  72
    PROFILE(0x0055afc4, 0x0055d758),    //  73
    PROFILE(0x00558550, 0x0055bd18),    //  74
    PROFILE(0x00557960, 0x0055b5c8),    //  75
    PROFILE(0x00558024, 0x0055b9e8),    //  76
    PROFILE(0x005593d8, 0x0055c588),    //  77
    PROFILE(0x005593d8, 0x0055c588),    //  78
    PROFILE(0x005593d8, 0x0055c588),    //  79
    PROFILE(0x005593d8, 0x0055c588),    //  80
    PROFILE(0x0055a344, 0x0055cfd8),    //  81
    PROFILE(0x0055a868, 0x0055d2d8),    //  82
    PROFILE(0x0055a2b8, 0x0055cf78),    //  83
    PROFILE(0x0055a2b8, 0x0055cf78),    //  84
    PROFILE(0x0055a0d0, 0x0055ce58),    //  85
    PROFILE(0x005581f0, 0x0055bb20),    //  86
    PROFILE(0x00558c48, 0x0055c108),    //  87
    PROFILE(0x00559510, 0x0055c660),    //  88
    PROFILE(0x00557a94, 0x0055b6a0),    //  89
    PROFILE(0x00557a94, 0x0055b6a0),    //  90
    PROFILE(0x00557a70, 0x0055b688),    //  91
    PROFILE(0x0055a410, 0x0055d068),    //  92
    PROFILE(0x0055a410, 0x0055d068),    //  93
    PROFILE(0x0055a410, 0x0055d068),    //  94
    PROFILE(0x0055a410, 0x0055d068),    //  95
    PROFILE(0x005574a0, 0x0055b2c8),    //  96
    PROFILE(0x005574a0, 0x0055b2c8),    //  97
    PROFILE(0x005574a0, 0x0055b2c8),    //  98
    PROFILE(0x005574a0, 0x0055b2c8),    //  99
    PROFILE(0x00557ce4, 0x0055b7d8),    // 100
    PROFILE(0x00557ce4, 0x0055b7d8),    // 101
    PROFILE(0x00557ce4, 0x0055b7d8),    // 102
    PROFILE(0x00557ce4, 0x0055b7d8),    // 103
    PROFILE(0x00557d08, 0x0055b7f0),    // 104
    PROFILE(0x0055b048, 0x0055d7b8),    // 105
    PROFILE(0x0055b048, 0x0055d7b8),    // 106
    PROFILE(0x00559484, 0x0055c600),    // 107
    PROFILE(0x00558184, 0x0055bad8),    // 108
    PROFILE(0x0055811c, 0x0055ba90),    // 109
    PROFILE(0x005597b0, 0x0055c828),    // 110
    PROFILE(0x0055abb8, 0x0055d518),    // 111
    PROFILE(0x005589f4, 0x0055bf70),    // 112
    PROFILE(0x005589f4, 0x0055bf70),    // 113
    PROFILE(0x0055ac20, 0x0055d560),    // 114
    PROFILE(0x00558d94, 0x0055c138),    // 115
    PROFILE(0x005586a8, 0x0055be08),    // 116
    PROFILE(0x0055af80, 0x0055d728),    // 117
    PROFILE(0x0055a6e8, 0x0055d1e8),    // 118
    PROFILE(0x00559420, 0x0055c5b8),    // 119
    PROFILE(0x0055978c, 0x0055c810),    // 120
    PROFILE(0x0055a968, 0x0055d380),    // 121
    PROFILE(0x00559650, 0x0055c738),    // 122
    PROFILE(0x00557e18, 0x0055b8b0),    // 123
    PROFILE(0x0055adbc, 0x0055d638),    // 124
    PROFILE(0x00557664, 0x0055b400),    // 125
    PROFILE(0x00557664, 0x0055b400),    // 126
    PROFILE(0x005598c8, 0x0055c8e8),    // 127
    PROFILE(0x00558b98, 0x0055c090),    // 128
    PROFILE(0x005580f8, 0x0055ba78),    // 129
    PROFILE(0x00558460, 0x0055bc70),    // 130
    PROFILE(0x00557fc4, 0x0055b9a0),    // 131
    PROFILE(0x005573f4, 0x0055b250),    // 132
    PROFILE(0x00559884, 0x0055c8b8),    // 133
    PROFILE(0x00559c84, 0x0055cb70),    // 134
    PROFILE(0x0055a8f4, 0x0055d338),    // 135
    PROFILE(0x0055a8f4, 0x0055d338),    // 136
    PROFILE(0x0055a804, 0x0055d2a8),    // 137
    PROFILE(0x00559d14, 0x0055cbd0),    // 138
    PROFILE(0x00559728, 0x0055c7c8),    // 139
    PROFILE(0x00559afc, 0x0055ca68),    // 140
    PROFILE(0x005577d8, 0x0055b4f0),    // 141
    PROFILE(0x0055a9f8, 0x0055d3e0),    // 142
    PROFILE(0x005574c4, 0x0055b2e0),    // 143
    PROFILE(0x005574e8, 0x0055b2f8),    // 144
    PROFILE(0x005599a0, 0x0055c978),    // 145
    PROFILE(0x005589b0, 0x0055bf40),    // 146
    PROFILE(0x00557d90, 0x0055b850),    // 147
    PROFILE(0x0055aa40, 0x0055d410),    // 148
    PROFILE(0x0055af38, 0x0055d6f8),    // 149
    PROFILE(0x0055af38, 0x0055d6f8),    // 150
    PROFILE(0x0055898c, 0x0055bf28),    // 151
    PROFILE(0x00558660, 0x0055bdd8),    // 152
    PROFILE(0x005589d0, 0x0055bf58),    // 153
    PROFILE(0x00559338, 0x0055c540),    // 154
    PROFILE(0x00559338, 0x0055c540),    // 155
    PROFILE(0x00559338, 0x0055c540),    // 156
    PROFILE(0x005579cc, 0x0055b610),    // 157
    PROFILE(0x00557f7c, 0x0055b970),    // 158
    PROFILE(0x005596e0, 0x0055c798),    // 159
    PROFILE(0x0055850c, 0x0055bce8),    // 160
    PROFILE(0x0055a1e4, 0x0055cee8),    // 161
    PROFILE(0x00557438, 0x0055b280),    // 162
    PROFILE(0x00557c54, 0x0055b778),    // 163
    PROFILE(0x00559e74, 0x0055ccc0),    // 164
    PROFILE(0x00559f24, 0x0055cd38),    // 165
    PROFILE(0x00559fb0, 0x0055cd98),    // 166
    PROFILE(0x00559fd4, 0x0055cdb0),    // 167
    PROFILE(0x0055a040, 0x0055cdf8),    // 168
    PROFILE(0x00559e2c, 0x0055cc90),    // 169
    PROFILE(0x00559e2c, 0x0055cc90),    // 170
    PROFILE(0x00559e2c, 0x0055cc90),    // 171
    PROFILE(0x0055983c, 0x0055c888),    // 172
    PROFILE(0x0055983c, 0x0055c888),    // 173
    PROFILE(0x0055983c, 0x0055c888),    // 174
    PROFILE(0x005591b8, 0x0055c438),    // 175
    PROFILE(0x00559194, 0x0055c420),    // 176
    PROFILE(0x00559f90, 0x0055cd80),    // 177
    PROFILE(0x0055957c, 0x0055c6a8),    // 178
    PROFILE(0x0055a01c, 0x0055cde0),    // 179
    PROFILE(0x00559e50, 0x0055cca8),    // 180
    PROFILE(0x00559ccc, 0x0055cba0),    // 181
    PROFILE(0x0055981c, 0x0055c870),    // 182
    PROFILE(0x0055a064, 0x0055ce10),    // 183
    PROFILE(0x00559ff8, 0x0055cdc8),    // 184
    PROFILE(0x00559558, 0x0055c690),    // 185
    PROFILE(0x00559bac, 0x0055cae0),    // 186
    PROFILE(0x0055836c, 0x0055bbc8),    // 187
    PROFILE(0x00559ca8, 0x0055cb88),    // 188
    PROFILE(0x00558c00, 0x0055c0d8),    // 189
    PROFILE(0x00559e08, 0x0055cc78),    // 190
    PROFILE(0x0055841c, 0x0055bc40),    // 191
    PROFILE(0x0055841c, 0x0055bc40),    // 192
    PROFILE(0x005583f8, 0x0055bc28),    // 193
    PROFILE(0x005584c8, 0x0055bcb8),    // 194
    PROFILE(0x0055a4d0, 0x0055d0b0),    // 195
    PROFILE(0x00558640, 0x0055bdc0),    // 196
    PROFILE(0x0055a364, 0x0055cff0),    // 197
    PROFILE(0x00557688, 0x0055b418),    // 198
    PROFILE(0x0055a6c4, 0x0055d1d0),    // 199
    PROFILE(0x00557c78, 0x0055b790),    // 200
    PROFILE(0x00557c78, 0x0055b790),    // 201
    PROFILE(0x005592f4, 0x0055c510),    // 202
    PROFILE(0x00557fa0, 0x0055b988),    // 203
    PROFILE(0x0055afa0, 0x0055d740),    // 204
    PROFILE(0x00559314, 0x0055c528),    // 205
    PROFILE(0x00559704, 0x0055c7b0),    // 206
    PROFILE(0x0055ac40, 0x0055d578),    // 207
    PROFILE(0x005586ec, 0x0055be38),    // 208
    PROFILE(0x005586ec, 0x0055be38),    // 209
    PROFILE(0x005586ec, 0x0055be38),    // 210
    PROFILE(0x005586ec, 0x0055be38),    // 211
    PROFILE(0x00559a6c, 0x0055ca08),    // 212
    PROFILE(0x00559cf0, 0x0055cbb8),    // 213
    PROFILE(0x0055a7bc, 0x0055d278),    // 214
    PROFILE(0x005585fc, 0x0055bd90),    // 215
    PROFILE(0x00559b68, 0x0055cab0),    // 216
    PROFILE(0x00559244, 0x0055c498),    // 217
    PROFILE(0x00559d34, 0x0055cbe8),    // 218
    PROFILE(0x00558710, 0x0055be50),    // 219
    PROFILE(0x00558710, 0x0055be50),    // 220
    PROFILE(0x005595a0, 0x0055c6c0),    // 221
    PROFILE(0x005595a0, 0x0055c6c0),    // 222
    PROFILE(0x00558298, 0x0055bb38),    // 223
    PROFILE(0x005591dc, 0x0055c450),    // 224
    PROFILE(0x005586c8, 0x0055be20),    // 225
    PROFILE(0x00559bd0, 0x0055caf8),    // 226
    PROFILE(0x00559a90, 0x0055ca20),    // 227
    PROFILE(0x00559860, 0x0055c8a0),    // 228
    PROFILE(0x0055aacc, 0x0055d470),    // 229
    PROFILE(0x00558a5c, 0x0055bfb8),    // 230
    PROFILE(0x00559e98, 0x0055ccd8),    // 231
    PROFILE(0x0055abfc, 0x0055d548),    // 232
    PROFILE(0x00559534, 0x0055c678),    // 233
    PROFILE(0x00559534, 0x0055c678),    // 234
    PROFILE(0x0055abdc, 0x0055d530),    // 235
    PROFILE(0x0055abdc, 0x0055d530),    // 236
    PROFILE(0x0055a634, 0x0055d1a0),    // 237
    PROFILE(0x00558590, 0x0055bd48),    // 238
    PROFILE(0x00557f58, 0x0055b958),    // 239
    PROFILE(0x0055a518, 0x0055d0e0),    // 240
    PROFILE(0x0055a518, 0x0055d0e0),    // 241
    PROFILE(0x005579a8, 0x0055b5f8),    // 242
    PROFILE(0x00557be8, 0x0055b730),    // 243
    PROFILE(0x0055aaf0, 0x0055d488),    // 244
    PROFILE(0x0055ab14, 0x0055d4a0),    // 245
    PROFILE(0x00558a80, 0x0055bfd0),    // 246
    PROFILE(0x00558aa4, 0x0055bfe8),    // 247
    PROFILE(0x0055806c, 0x0055ba18),    // 248
    PROFILE(0x00559b20, 0x0055ca80),    // 249
    PROFILE(0x0055a22c, 0x0055cf18),    // 250
    PROFILE(0x0055a22c, 0x0055cf18),    // 251
    PROFILE(0x0055aeac, 0x0055d698),    // 252
    PROFILE(0x0055a088, 0x0055ce28),    // 253
    PROFILE(0x0055a5ec, 0x0055d170),    // 254
    PROFILE(0x00558bbc, 0x0055c0a8),    // 255
    PROFILE(0x0055a8b0, 0x0055d308),    // 256
    PROFILE(0x0055a388, 0x0055d008),    // 257
    PROFILE(0x00557984, 0x0055b5e0),    // 258
    PROFILE(0x0055a434, 0x0055d080),    // 259
    PROFILE(0x0055a434, 0x0055d080),    // 260
    PROFILE(0x0055ab34, 0x0055d4b8),    // 261
    PROFILE(0x00558684, 0x0055bdf0),    // 262
    PROFILE(0x005585d8, 0x0055bd78),    // 263
    PROFILE(0x005599c4, 0x0055c990),    // 264
    PROFILE(0x00559a4c, 0x0055c9f0),    // 265
    PROFILE(0x005580d4, 0x0055ba60),    // 266
    PROFILE(0x00559b44, 0x0055ca98),    // 267
    PROFILE(0x00558d70, 0x0055c120),    // 268
    PROFILE(0x00559b88, 0x0055cac8),    // 269
    PROFILE(0x0055a774, 0x0055d248),    // 270
    PROFILE(0x00557770, 0x0055b4a8),    // 271
    PROFILE(0x00557770, 0x0055b4a8),    // 272
    PROFILE(0x0055ae88, 0x0055d680),    // 273
    PROFILE(0x0055b1d0, 0x0055d818),    // 274
    PROFILE(0x00557710, 0x0055b478),    // 275
    PROFILE(0x00558778, 0x0055be98),    // 276
    PROFILE(0x0055a93c, 0x0055d368),    // 277
    PROFILE(0x00557644, 0x0055b3e8),    // 278
    PROFILE(0x00557e5c, 0x0055b8e0),    // 279
    PROFILE(0x00559698, 0x0055c768),    // 280
    PROFILE(0x005592ac, 0x0055c4e0),    // 281
    PROFILE(0x00559c3c, 0x0055cb40),    // 282
    PROFILE(0x005596bc, 0x0055c780),    // 283
    PROFILE(0x00559c60, 0x0055cb58),    // 284
    PROFILE(0x00558920, 0x0055bee0),    // 285
    PROFILE(0x005595e4, 0x0055c6f0),    // 286
    PROFILE(0x00559608, 0x0055c708),    // 287
    PROFILE(0x005598ec, 0x0055c900),    // 288
    PROFILE(0x00559ab4, 0x0055ca38),    // 289
    PROFILE(0x00559d58, 0x0055cc00),    // 290
    PROFILE(0x00559edc, 0x0055cd08),    // 291
    PROFILE(0x00559ad8, 0x0055ca50),    // 292
    PROFILE(0x00559d7c, 0x0055cc18),    // 293
    PROFILE(0x00559da0, 0x0055cc30),    // 294
    PROFILE(0x00559f00, 0x0055cd20),    // 295
    PROFILE(0x0055ab94, 0x0055d500),    // 296
    PROFILE(0x005580b0, 0x0055ba48),    // 297
    PROFILE(0x005585b4, 0x0055bd60),    // 298
    PROFILE(0x0055a5c8, 0x0055d158),    // 299
    PROFILE(0x0055a5c8, 0x0055d158),    // 300
    PROFILE(0x00557b34, 0x0055b6b8),    // 301
    PROFILE(0x0055a208, 0x0055cf00),    // 302
    PROFILE(0x00557e3c, 0x0055b8c8),    // 303
    PROFILE(0x005576a8, 0x0055b430),    // 304
    PROFILE(0x0055a658, 0x0055d1b8),    // 305
    PROFILE(0x00557414, 0x0055b268),    // 306
    PROFILE(0x005598a4, 0x0055c8d0),    // 307
    PROFILE(0x005594d0, 0x0055c630),    // 308
    PROFILE(0x0055a2dc, 0x0055cf90),    // 309
    PROFILE(0x00558140, 0x0055baa8),    // 310
    PROFILE(0x0055a3cc, 0x0055d038),    // 311
    PROFILE(0x0055a3cc, 0x0055d038),    // 312
    PROFILE(0x0055ad98, 0x0055d620),    // 313
    PROFILE(0x0055aa1c, 0x0055d3f8),    // 314
    PROFILE(0x0055a610, 0x0055d188),    // 315
    PROFILE(0x0055a828, 0x0055d2c0),    // 316
    PROFILE(0x0055a88c, 0x0055d2f0),    // 317
    PROFILE(0x0055ae04, 0x0055d668),    // 318
    PROFILE(0x0055a0f4, 0x0055ce70),    // 319
    PROFILE(0x0055a9d4, 0x0055d3c8),    // 320
    PROFILE(0x0055b16c, 0x0055d7d0),    // 321
    PROFILE(0x005597f8, 0x0055c858),    // 322
    PROFILE(0x0055a300, 0x0055cfa8),    // 323
    PROFILE(0x005581cc, 0x0055bb08),    // 324
    PROFILE(0x005581cc, 0x0055bb08),    // 325
    PROFILE(0x0055a98c, 0x0055d398),    // 326
    PROFILE(0x0055a9b0, 0x0055d3b0),    // 327
    PROFILE(0x0055a9b0, 0x0055d3b0),    // 328
    PROFILE(0x0055a918, 0x0055d350),    // 329
    PROFILE(0x0055ade0, 0x0055d650),    // 330
    PROFILE(0x0055774c, 0x0055b490),    // 331
    PROFILE(0x0055a798, 0x0055d260),    // 332
    PROFILE(0x005575bc, 0x0055b388),    // 333
    PROFILE(0x0055af5c, 0x0055d710),    // 334
    PROFILE(0x00558968, 0x0055bf10),    // 335
    PROFILE(0x0055a250, 0x0055cf30),    // 336
    PROFILE(0x0055aed0, 0x0055d6b0),    // 337
    PROFILE(0x0055a0ac, 0x0055ce40),    // 338
    PROFILE(0x0055a320, 0x0055cfc0),    // 339
    PROFILE(0x0055a560, 0x0055d110),    // 340
    PROFILE(0x0055a3ec, 0x0055d050),    // 341
    PROFILE(0x0055a158, 0x0055ce88),    // 342
    PROFILE(0x0055a53c, 0x0055d0f8),    // 343
    PROFILE(0x0055a270, 0x0055cf48),    // 344
    PROFILE(0x0055a294, 0x0055cf60),    // 345
    PROFILE(0x005575e0, 0x0055b3a0),    // 346
    PROFILE(0x00559288, 0x0055c4c8),    // 347
    PROFILE(0x0055838c, 0x0055bbe0),    // 348
    PROFILE(0x00559268, 0x0055c4b0),    // 349
    PROFILE(0x0055962c, 0x0055c720),    // 350
    PROFILE(0x0055a458, 0x0055d098),    // 351
    PROFILE(0x0055aca8, 0x0055d5c0),    // 352
    PROFILE(0x005578f4, 0x0055b5b0),    // 353
    PROFILE(0x00558440, 0x0055bc58),    // 354
    PROFILE(0x00557820, 0x0055b520),    // 355
    PROFILE(0x00557480, 0x0055b2b0),    // 356
    PROFILE(0x0055af14, 0x0055d6e0),    // 357
    PROFILE(0x00557eec, 0x0055b940),    // 358
    PROFILE(0x0055a4f4, 0x0055d0c8),    // 359
    PROFILE(0x00557620, 0x0055b3d0),    // 360
    PROFILE(0x005576cc, 0x0055b448),    // 361
    PROFILE(0x0055a1c4, 0x0055ced0),    // 362
    PROFILE(0x005578d0, 0x0055b598),    // 363
    PROFILE(0x00558048, 0x0055ba00),    // 364
    PROFILE(0x0055ac84, 0x0055d5a8),    // 365
    PROFILE(0x0055a17c, 0x0055cea0),    // 366
    PROFILE(0x0055a17c, 0x0055cea0),    // 367
    PROFILE(0x0055afe4, 0x0055d770),    // 368
    PROFILE(0x0055afe4, 0x0055d770),    // 369
    PROFILE(0x0055a7e0, 0x0055d290),    // 370
    PROFILE(0x0055a7e0, 0x0055d290),    // 371
    PROFILE(0x00557b7c, 0x0055b6e8),    // 372
    PROFILE(0x00558c24, 0x0055c0f0),    // 373
    PROFILE(0x005594ac, 0x0055c618),    // 374
    PROFILE(0x00559a28, 0x0055c9d8),    // 375
    PROFILE(0x005594f0, 0x0055c648),    // 376
    PROFILE(0x005594f0, 0x0055c648),    // 377
    PROFILE(0x0055a1a0, 0x0055ceb8),    // 378
    PROFILE(0x0055a1a0, 0x0055ceb8),    // 379
    PROFILE(0x00557b7c, 0x0055b6e8),    // 380
    PROFILE(0x00558c24, 0x0055c0f0),    // 381
    PROFILE(0x00557e80, 0x0055b8f8),    // 382
    PROFILE(0x00557794, 0x0055B4C0),    // 383
    PROFILE(0x00557574, 0x0055b358),    // 384
    PROFILE(0x00557550, 0x0055b340),    // 385
    PROFILE(0x0055ad74, 0x0055d608),    // 386
    PROFILE(0x00557598, 0x0055b370),    // 387
    PROFILE(0x00557508, 0x0055b310),    // 388
    PROFILE(0x0055ad50, 0x0055d5f0),    // 389
    PROFILE(0x0055ad2c, 0x0055d5d8),    // 390
    PROFILE(0x0055752c, 0x0055b328),    // 391
    PROFILE(0x00557db4, 0x0055b868),    // 392
    PROFILE(0x0055b1b0, 0x0055d800),    // 393
    PROFILE(0x00559220, 0x0055c480),    // 394
    PROFILE(0x0055aa64, 0x0055d428),    // 395
    PROFILE(0x00557d70, 0x0055b838),    // 396
    PROFILE(0x00559f6c, 0x0055cd68),    // 397
    PROFILE(0x00557c9c, 0x0055b7a8),    // 398
    PROFILE(0x00557cc0, 0x0055b7c0),    // 399
    PROFILE(0x005577fc, 0x0055b508),    // 400
    PROFILE(0x0055a750, 0x0055d230),    // 401
    PROFILE(0x00557b58, 0x0055b6d0),    // 402
    PROFILE(0x00557844, 0x0055b538),    // 403
    PROFILE(0x00559ebc, 0x0055ccf0),    // 404
    PROFILE(0x005592d0, 0x0055c4f8),    // 405
    PROFILE(0x00558b74, 0x0055c078),    // 406
    PROFILE(0x00559dc4, 0x0055cc48),    // 407
    PROFILE(0x005588fc, 0x0055bec8),    // 408
    PROFILE(0x00558090, 0x0055ba30),    // 409
    PROFILE(0x00557c30, 0x0055b760),    // 410
    PROFILE(0x00558300, 0x0055bb80),    // 411
    PROFILE(0x00558324, 0x0055bb98),    // 412
    PROFILE(0x00558348, 0x0055bbb0),    // 413
    PROFILE(0x00559674, 0x0055c750),    // 414
    PROFILE(0x005587b8, 0x0055beb0),    // 415
    PROFILE(0x005584a8, 0x0055bca0),    // 416
    PROFILE(0x005584a8, 0x0055bca0),    // 417
    PROFILE(0x005584a8, 0x0055bca0),    // 418
    PROFILE(0x005584a8, 0x0055bca0),    // 419
    PROFILE(0x0055a8d4, 0x0055d320),    // 420
    PROFILE(0x00558734, 0x0055be68),    // 421
    PROFILE(0x00557a50, 0x0055b670),    // 422
    PROFILE(0x0055b008, 0x0055d788),    // 423
    PROFILE(0x005584ec, 0x0055bcd0),    // 424
    PROFILE(0x00558570, 0x0055bd30),    // 425
    PROFILE(0x0055ac64, 0x0055d590),    // 426
    PROFILE(0x00557dd8, 0x0055b880),    // 427
    PROFILE(0x00557fe4, 0x0055b9b8),    // 428
    PROFILE(0x00558aec, 0x0055c018),    // 429
    PROFILE(0x00557600, 0x0055b3b8),    // 430
    PROFILE(0x00557df8, 0x0055b898),    // 431
    PROFILE(0x00558ac8, 0x0055c000),    // 432
    PROFILE(0x00558b0c, 0x0055c030),    // 433
    PROFILE(0x00557d4c, 0x0055b820),    // 434
    PROFILE(0x00557ea4, 0x0055b910),    // 435
    PROFILE(0x005583d4, 0x0055bc10),    // 436
    PROFILE(0x0055a72c, 0x0055d218),    // 437
    PROFILE(0x005576f0, 0x0055b460),    // 438
    PROFILE(0x0055997c, 0x0055c960),    // 439
    PROFILE(0x00558db4, 0x0055c150),    // 440
    PROFILE(0x00558f94, 0x0055c2b8),    // 441
    PROFILE(0x00558df4, 0x0055c180),    // 442
    PROFILE(0x00558e94, 0x0055c1f8),    // 443
    PROFILE(0x00559094, 0x0055c360),    // 444
    PROFILE(0x00559074, 0x0055c348),    // 445
    PROFILE(0x00559154, 0x0055c3f0),    // 446
    PROFILE(0x005590d4, 0x0055c390),    // 447
    PROFILE(0x005590f4, 0x0055c3a8),    // 448
    PROFILE(0x00558ef4, 0x0055c240),    // 449
    PROFILE(0x00558e74, 0x0055c1e0),    // 450
    PROFILE(0x00558e54, 0x0055c1c8),    // 451
    PROFILE(0x005590b4, 0x0055c378),    // 452
    PROFILE(0x00558ed4, 0x0055c228),    // 453
    PROFILE(0x00558f14, 0x0055c258),    // 454
    PROFILE(0x00558e34, 0x0055c1b0),    // 455
    PROFILE(0x00559014, 0x0055c318),    // 456
    PROFILE(0x00558e14, 0x0055c198),    // 457
    PROFILE(0x00558eb4, 0x0055c210),    // 458
    PROFILE(0x00559114, 0x0055c3c0),    // 459
    PROFILE(0x00558f34, 0x0055c270),    // 460
    PROFILE(0x00558f54, 0x0055c288),    // 461
    PROFILE(0x00558fb4, 0x0055c2d0),    // 462
    PROFILE(0x00558fd4, 0x0055c2e8),    // 463
    PROFILE(0x00558dd4, 0x0055c168),    // 464
    PROFILE(0x00558f74, 0x0055c2a0),    // 465
    PROFILE(0x00559134, 0x0055c3d8),    // 466
    PROFILE(0x00558ff4, 0x0055c300),    // 467
    PROFILE(0x00559034, 0x0055c330),    // 468
    PROFILE(0x00559174, 0x0055c408),    // 469
};


#define RESENTRY(f, u) \
    { (sead::SafeString*)f, u }

ResTableEntry ResTable[ProfileId::Num] =
{
    RESENTRY(nullptr, 0),               //   0
    RESENTRY(nullptr, 0),               //   1
    RESENTRY(nullptr, 0),               //   2
    RESENTRY(nullptr, 0),               //   3
    RESENTRY(nullptr, 0),               //   4
    RESENTRY(nullptr, 0),               //   5
    RESENTRY(nullptr, 0),               //   6
    RESENTRY(nullptr, 0),               //   7
    RESENTRY(nullptr, 0),               //   8
    RESENTRY(nullptr, 0),               //   9
    RESENTRY(nullptr, 0),               //  10
    RESENTRY(nullptr, 0),               //  11
    RESENTRY(nullptr, 0),               //  12
    RESENTRY(nullptr, 0),               //  13
    RESENTRY(nullptr, 0),               //  14
    RESENTRY(nullptr, 0),               //  15
    RESENTRY(nullptr, 0),               //  16
    RESENTRY(nullptr, 0),               //  17
    RESENTRY(nullptr, 0),               //  18
    RESENTRY(nullptr, 0),               //  19
    RESENTRY(nullptr, 0),               //  20
    RESENTRY(0x0061609c, 2),            //  21
    RESENTRY(0x0061603c, 2),            //  22
    RESENTRY(0x00615fcc, 2),            //  23
    RESENTRY(0x00615ffc, 2),            //  24
    RESENTRY(0x0061606c, 2),            //  25
    RESENTRY(0x0061602c, 2),            //  26
    RESENTRY(0x00618844, 2),            //  27
    RESENTRY(0x00618b14, 2),            //  28
    RESENTRY(0x00616364, 2),            //  29
    RESENTRY(0x00615894, 2),            //  30
    RESENTRY(0x00615964, 2),            //  31
    RESENTRY(0x00615974, 2),            //  32
    RESENTRY(0x006159c4, 2),            //  33
    RESENTRY(0x00605c54, 2),            //  34
    RESENTRY(0x00604c70, 2),            //  35
    RESENTRY(0x00604cac, 2),            //  36
    RESENTRY(0x00604ce8, 2),            //  37
    RESENTRY(0x00604d60, 2),            //  38
    RESENTRY(0x00604d24, 2),            //  39
    RESENTRY(0x00604d9c, 2),            //  40
    RESENTRY(0x00604c60, 2),            //  41
    RESENTRY(0x00606174, 2),            //  42
    RESENTRY(0x006181ac, 2),            //  43
    RESENTRY(0x0061826c, 2),            //  44
    RESENTRY(0x0061827c, 2),            //  45
    RESENTRY(0x0061776c, 2),            //  46
    RESENTRY(0x0061777c, 2),            //  47
    RESENTRY(0x0061780c, 2),            //  48
    RESENTRY(0x0061831c, 2),            //  49
    RESENTRY(0x0061832c, 2),            //  50
    RESENTRY(0x00617ef4, 2),            //  51
    RESENTRY(0x00618604, 2),            //  52
    RESENTRY(0x00618614, 2),            //  53
    RESENTRY(0x00618684, 2),            //  54
    RESENTRY(0x00617fcc, 2),            //  55
    RESENTRY(0x0061809c, 2),            //  56
    RESENTRY(0x006182ec, 2),            //  57
    RESENTRY(0x0061851c, 2),            //  58
    RESENTRY(0x006185f4, 2),            //  59
    RESENTRY(0x00619214, 2),            //  60
    RESENTRY(0x006194e8, 2),            //  61
    RESENTRY(0x006194f8, 2),            //  62
    RESENTRY(0x00614f40, 2),            //  63
    RESENTRY(0x00614eec, 2),            //  64
    RESENTRY(0x00614f28, 2),            //  65
    RESENTRY(0x00614edc, 2),            //  66
    RESENTRY(0x0060810c, 2),            //  67
    RESENTRY(0x006120c4, 2),            //  68
    RESENTRY(0x00610ddc, 2),            //  69
    RESENTRY(0x00610e5c, 2),            //  70
    RESENTRY(0x00610e4c, 2),            //  71
    RESENTRY(0x00610ef4, 2),            //  72
    RESENTRY(0x00610f24, 2),            //  73
    RESENTRY(0x00610e6c, 2),            //  74
    RESENTRY(0x00610f14, 2),            //  75
    RESENTRY(0x00607968, 2),            //  76
    RESENTRY(0x00610eb4, 2),            //  77
    RESENTRY(0x00610ec4, 2),            //  78
    RESENTRY(0x00610ed4, 2),            //  79
    RESENTRY(0x00610ee4, 2),            //  80
    RESENTRY(0x00614b88, 2),            //  81
    RESENTRY(0x006199cc, 2),            //  82
    RESENTRY(0x00617f8c, 2),            //  83
    RESENTRY(0x00617f9c, 2),            //  84
    RESENTRY(0x00619608, 2),            //  85
    RESENTRY(0x006197e4, 2),            //  86
    RESENTRY(0x0061980c, 2),            //  87
    RESENTRY(0x0061976c, 2),            //  88
    RESENTRY(0x00618fa0, 2),            //  89
    RESENTRY(0x00618fb0, 2),            //  90
    RESENTRY(0x0060e4a4, 2),            //  91
    RESENTRY(0x006153a4, 2),            //  92
    RESENTRY(0x006153b4, 2),            //  93
    RESENTRY(0x006153c4, 2),            //  94
    RESENTRY(0x006153d4, 2),            //  95
    RESENTRY(0x0061559c, 2),            //  96
    RESENTRY(0x006155ac, 2),            //  97
    RESENTRY(0x006155bc, 2),            //  98
    RESENTRY(0x006155cc, 2),            //  99
    RESENTRY(0x00615504, 2),            // 100
    RESENTRY(0x00615514, 2),            // 101
    RESENTRY(0x00615524, 2),            // 102
    RESENTRY(0x00615534, 2),            // 103
    RESENTRY(0x0061558c, 2),            // 104
    RESENTRY(0x0061915c, 2),            // 105
    RESENTRY(0x0061916c, 2),            // 106
    RESENTRY(0x0061914c, 2),            // 107
    RESENTRY(0x0061913c, 2),            // 108
    RESENTRY(0x00618dc8, 2),            // 109
    RESENTRY(0x00618e20, 2),            // 110
    RESENTRY(0x0061969c, 2),            // 111
    RESENTRY(0x006180f4, 2),            // 112
    RESENTRY(0x0061810c, 2),            // 113
    RESENTRY(0x00619a24, 2),            // 114
    RESENTRY(0x00619a34, 2),            // 115
    RESENTRY(0x00619a44, 2),            // 116
    RESENTRY(0x00606aa4, 2),            // 117
    RESENTRY(0x006161a0, 2),            // 118
    RESENTRY(0x00618d94, 2),            // 119
    RESENTRY(0x00618d84, 2),            // 120
    RESENTRY(0x00615ed8, 2),            // 121
    RESENTRY(0x00615f28, 2),            // 122
    RESENTRY(0x00615f88, 2),            // 123
    RESENTRY(0x006160cc, 2),            // 124
    RESENTRY(0x0061611c, 2),            // 125
    RESENTRY(0x0061612c, 2),            // 126
    RESENTRY(0x0060e450, 2),            // 127
    RESENTRY(0x0061897c, 2),            // 128
    RESENTRY(0x006189e4, 2),            // 129
    RESENTRY(0x006180e4, 2),            // 130
    RESENTRY(0x0061819c, 2),            // 131
    RESENTRY(0x00614d20, 2),            // 132
    RESENTRY(0x00614d60, 2),            // 133
    RESENTRY(0x0061825c, 2),            // 134
    RESENTRY(0x00615304, 2),            // 135
    RESENTRY(0x00615314, 2),            // 136
    RESENTRY(0x00607da4, 2),            // 137
    RESENTRY(0x00604abc, 0),            // 138
    RESENTRY(0x00607144, 2),            // 139
    RESENTRY(0x00617ee4, 2),            // 140
    RESENTRY(0x0061797c, 2),            // 141
    RESENTRY(0x00616354, 2),            // 142
    RESENTRY(0x006156f4, 2),            // 143
    RESENTRY(0x006157d0, 2),            // 144
    RESENTRY(0x00607590, 2),            // 145
    RESENTRY(0x00606690, 2),            // 146
    RESENTRY(0x00604fe0, 2),            // 147
    RESENTRY(0x006054b4, 2),            // 148
    RESENTRY(0x006179d8, 2),            // 149
    RESENTRY(0x006179f0, 2),            // 150
    RESENTRY(0x006065a4, 2),            // 151
    RESENTRY(0x006194d8, 2),            // 152
    RESENTRY(0x00607194, 2),            // 153
    RESENTRY(0x00617b34, 2),            // 154
    RESENTRY(0x00617b44, 2),            // 155
    RESENTRY(0x00617b54, 2),            // 156
    RESENTRY(0x00618954, 2),            // 157
    RESENTRY(0x0060709c, 2),            // 158
    RESENTRY(0x006067e8, 2),            // 159
    RESENTRY(0x006187b0, 2),            // 160
    RESENTRY(0x006150e0, 2),            // 161
    RESENTRY(0x00615348, 2),            // 162
    RESENTRY(0x00615210, 1),            // 163
    RESENTRY(0x00614360, 2),            // 164
    RESENTRY(0x00613f70, 2),            // 165
    RESENTRY(0x006144d0, 2),            // 166
    RESENTRY(0x00614370, 2),            // 167
    RESENTRY(0x00614120, 2),            // 168
    RESENTRY(0x006140f0, 2),            // 169
    RESENTRY(0x00614100, 2),            // 170
    RESENTRY(0x00614110, 2),            // 171
    RESENTRY(0x00614458, 2),            // 172
    RESENTRY(0x00614468, 2),            // 173
    RESENTRY(0x00614478, 2),            // 174
    RESENTRY(0x0061429c, 2),            // 175
    RESENTRY(0x00614130, 2),            // 176
    RESENTRY(0x006141c8, 2),            // 177
    RESENTRY(0x006143d8, 2),            // 178
    RESENTRY(0x00614448, 2),            // 179
    RESENTRY(0x00614350, 2),            // 180
    RESENTRY(0x00613fa4, 2),            // 181
    RESENTRY(0x00613d38, 2),            // 182
    RESENTRY(0x00613ff8, 2),            // 183
    RESENTRY(0x006143a4, 2),            // 184
    RESENTRY(0x00613e48, 2),            // 185
    RESENTRY(0x00613f60, 2),            // 186
    RESENTRY(0x00615af4, 2),            // 187
    RESENTRY(0x0061911c, 2),            // 188
    RESENTRY(0x0061912c, 2),            // 189
    RESENTRY(0x00618fe8, 2),            // 190
    RESENTRY(0x00610410, 2),            // 191
    RESENTRY(0x00610440, 2),            // 192
    RESENTRY(0x0060ffa4, 2),            // 193
    RESENTRY(0x006104d0, 2),            // 194
    RESENTRY(0x00610334, 2),            // 195
    RESENTRY(0x00610510, 2),            // 196
    RESENTRY(0x0060dd38, 2),            // 197
    RESENTRY(0x00616270, 2),            // 198
    RESENTRY(0x00615e4c, 2),            // 199
    RESENTRY(0x00604a3c, 2),            // 200
    RESENTRY(0x00604a4c, 2),            // 201
    RESENTRY(0x006064e0, 2),            // 202
    RESENTRY(0x006070ec, 2),            // 203
    RESENTRY(0x00606e18, 2),            // 204
    RESENTRY(0x0060702c, 2),            // 205
    RESENTRY(0x00617ae0, 2),            // 206
    RESENTRY(0x00614500, 2),            // 207
    RESENTRY(0x00614810, 2),            // 208
    RESENTRY(0x00614820, 2),            // 209
    RESENTRY(0x00614830, 2),            // 210
    RESENTRY(0x00614840, 2),            // 211
    RESENTRY(0x00614730, 2),            // 212
    RESENTRY(0x00614a00, 2),            // 213
    RESENTRY(0x00618b24, 2),            // 214
    RESENTRY(0x00618b34, 2),            // 215
    RESENTRY(0x00618b44, 2),            // 216
    RESENTRY(0x00615b04, 2),            // 217
    RESENTRY(0x00615b14, 2),            // 218
    RESENTRY(0x00614918, 2),            // 219
    RESENTRY(0x00614928, 2),            // 220
    RESENTRY(0x00614710, 2),            // 221
    RESENTRY(0x00614720, 2),            // 222
    RESENTRY(0x00614938, 2),            // 223
    RESENTRY(0x00614510, 2),            // 224
    RESENTRY(0x00614658, 2),            // 225
    RESENTRY(0x00614908, 2),            // 226
    RESENTRY(0x00614990, 2),            // 227
    RESENTRY(0x00614780, 2),            // 228
    RESENTRY(0x00618694, 2),            // 229
    RESENTRY(0x006186a4, 2),            // 230
    RESENTRY(0x00614898, 2),            // 231
    RESENTRY(0x0061993c, 2),            // 232
    RESENTRY(0x006199ac, 2),            // 233
    RESENTRY(0x006199bc, 2),            // 234
    RESENTRY(0x006198bc, 2),            // 235
    RESENTRY(0x006198cc, 2),            // 236
    RESENTRY(0x00614b4c, 1),            // 237
    RESENTRY(0x0061AE00, 1),            // 238
    RESENTRY(0x00610948, 2),            // 239
    RESENTRY(0x00610808, 2),            // 240
    RESENTRY(0x00610830, 2),            // 241
    RESENTRY(0x00611018, 2),            // 242
    RESENTRY(0x0060df30, 2),            // 243
    RESENTRY(0x00610c60, 2),            // 244
    RESENTRY(0x00611080, 2),            // 245
    RESENTRY(0x00610b5c, 2),            // 246
    RESENTRY(0x00610bbc, 2),            // 247
    RESENTRY(0x00611188, 2),            // 248
    RESENTRY(0x006111c0, 2),            // 249
    RESENTRY(0x0060ffe4, 2),            // 250
    RESENTRY(0x0060fff4, 2),            // 251
    RESENTRY(0x0061014c, 2),            // 252
    RESENTRY(0x00610960, 2),            // 253
    RESENTRY(0x00611d04, 2),            // 254
    RESENTRY(0x00611594, 2),            // 255
    RESENTRY(0x0060daf4, 2),            // 256
    RESENTRY(0x0060e0f4, 2),            // 257
    RESENTRY(0x00610f5c, 2),            // 258
    RESENTRY(0x0060ec38, 2),            // 259
    RESENTRY(0x0060ec48, 2),            // 260
    RESENTRY(0x0061134c, 2),            // 261
    RESENTRY(0x0061203c, 2),            // 262
    RESENTRY(0x00611480, 2),            // 263
    RESENTRY(0x006114dc, 2),            // 264
    RESENTRY(0x0061208c, 2),            // 265
    RESENTRY(0x00611530, 2),            // 266
    RESENTRY(0x00611584, 2),            // 267
    RESENTRY(0x00612350, 2),            // 268
    RESENTRY(0x0061236c, 2),            // 269
    RESENTRY(0x0061031c, 2),            // 270
    RESENTRY(0x0060fe94, 2),            // 271
    RESENTRY(0x0060febc, 2),            // 272
    RESENTRY(0x0060fdd8, 2),            // 273
    RESENTRY(0x00611ff4, 2),            // 274
    RESENTRY(0x0060f8e8, 2),            // 275
    RESENTRY(0x0060e298, 2),            // 276
    RESENTRY(0x0060ef50, 2),            // 277
    RESENTRY(0x0060f214, 2),            // 278
    RESENTRY(0x0060fc60, 2),            // 279
    RESENTRY(0x0060fbcc, 2),            // 280
    RESENTRY(0x0060fbb4, 2),            // 281
    RESENTRY(0x0060fb84, 2),            // 282
    RESENTRY(0x0060fbe4, 2),            // 283
    RESENTRY(0x0060fb9c, 2),            // 284
    RESENTRY(0x0060ec00, 2),            // 285
    RESENTRY(0x0060ebb8, 2),            // 286
    RESENTRY(0x0060ebd0, 2),            // 287
    RESENTRY(0x0060ebe8, 2),            // 288
    RESENTRY(0x0060e778, 2),            // 289
    RESENTRY(0x0060e748, 2),            // 290
    RESENTRY(0x0060e760, 2),            // 291
    RESENTRY(0x0060e92c, 2),            // 292
    RESENTRY(0x0060e8e4, 2),            // 293
    RESENTRY(0x0060e8fc, 2),            // 294
    RESENTRY(0x0060e914, 2),            // 295
    RESENTRY(0x00611c2c, 2),            // 296
    RESENTRY(0x0061135c, 2),            // 297
    RESENTRY(0x00611404, 2),            // 298
    RESENTRY(0x00611930, 2),            // 299
    RESENTRY(0x00611948, 2),            // 300
    RESENTRY(0x006119e0, 2),            // 301
    RESENTRY(0x0060f764, 2),            // 302
    RESENTRY(0x0060f8d0, 2),            // 303
    RESENTRY(0x0060f88c, 2),            // 304
    RESENTRY(0x0060e030, 2),            // 305
    RESENTRY(0x0060e040, 2),            // 306
    RESENTRY(0x0060e094, 2),            // 307
    RESENTRY(0x00611fe4, 2),            // 308
    RESENTRY(0x006116a0, 2),            // 309
    RESENTRY(0x006116d0, 2),            // 310
    RESENTRY(0x0060e3f0, 2),            // 311
    RESENTRY(0x0060e400, 2),            // 312
    RESENTRY(0x0060ef68, 2),            // 313
    RESENTRY(0x0060f9fc, 2),            // 314
    RESENTRY(0x0061215c, 2),            // 315
    RESENTRY(0x00611b78, 2),            // 316
    RESENTRY(0x0060d9f0, 2),            // 317
    RESENTRY(0x0060fa0c, 2),            // 318
    RESENTRY(0x0060e728, 2),            // 319
    RESENTRY(0x0060f514, 2),            // 320
    RESENTRY(0x00611b18, 2),            // 321
    RESENTRY(0x00611b48, 2),            // 322
    RESENTRY(0x00611f58, 2),            // 323
    RESENTRY(0x00611fb4, 2),            // 324
    RESENTRY(0x00611fcc, 2),            // 325
    RESENTRY(0x0060f120, 2),            // 326
    RESENTRY(0x0060f40c, 2),            // 327
    RESENTRY(0x0060f41c, 2),            // 328
    RESENTRY(0x0060e610, 2),            // 329
    RESENTRY(0x0060f398, 2),            // 330
    RESENTRY(0x006054e0, 2),            // 331
    RESENTRY(0x00610670, 2),            // 332
    RESENTRY(0x0060ee18, 2),            // 333
    RESENTRY(0x00606430, 2),            // 334
    RESENTRY(0x006064f0, 2),            // 335
    RESENTRY(0x00605e44, 2),            // 336
    RESENTRY(0x00606094, 2),            // 337
    RESENTRY(0x00607be8, 2),            // 338
    RESENTRY(0x00607fa0, 2),            // 339
    RESENTRY(0x0060784c, 2),            // 340
    RESENTRY(0x00604bb4, 2),            // 341
    RESENTRY(0x00605060, 2),            // 342
    RESENTRY(0x0060734c, 2),            // 343
    RESENTRY(0x006068e8, 2),            // 344
    RESENTRY(0x00606d04, 2),            // 345
    RESENTRY(0x00605050, 2),            // 346
    RESENTRY(0x00608530, 2),            // 347
    RESENTRY(0x00608370, 2),            // 348
    RESENTRY(0x00608438, 2),            // 349
    RESENTRY(0x006083ec, 2),            // 350
    RESENTRY(0x00608540, 2),            // 351
    RESENTRY(0x00608134, 2),            // 352
    RESENTRY(0x00608590, 2),            // 353
    RESENTRY(0x00605cd0, 2),            // 354
    RESENTRY(0x00606a94, 2),            // 355
    RESENTRY(0x00604df0, 2),            // 356
    RESENTRY(0x00606184, 2),            // 357
    RESENTRY(0x00606270, 2),            // 358
    RESENTRY(0x00613bd0, 1),            // 359
    RESENTRY(0x006138c0, 1),            // 360
    RESENTRY(0x006138d0, 1),            // 361
    RESENTRY(0x00613ce0, 1),            // 362
    RESENTRY(0x00613ca0, 1),            // 363
    RESENTRY(0x00613cb0, 1),            // 364
    RESENTRY(0x006138b0, 2),            // 365
    RESENTRY(0x00613c80, 1),            // 366
    RESENTRY(0x00613c90, 1),            // 367
    RESENTRY(0x00613cc0, 1),            // 368
    RESENTRY(0x00613cd0, 1),            // 369
    RESENTRY(0x00618b94, 2),            // 370
    RESENTRY(0x00618ba4, 2),            // 371
    RESENTRY(0x00619348, 2),            // 372
    RESENTRY(0x006193f8, 2),            // 373
    RESENTRY(0x0061943c, 2),            // 374
    RESENTRY(0x006194b8, 2),            // 375
    RESENTRY(0x00619640, 2),            // 376
    RESENTRY(0x00619650, 2),            // 377
    RESENTRY(0x00618d00, 2),            // 378
    RESENTRY(0x00618d10, 2),            // 379
    RESENTRY(0x00619358, 2),            // 380
    RESENTRY(0x00619408, 2),            // 381
    RESENTRY(0x00617518, 2),            // 382
    RESENTRY(0x00617528, 2),            // 383
    RESENTRY(0x00615e08, 2),            // 384
    RESENTRY(0x00615de8, 2),            // 385
    RESENTRY(0x00615df8, 2),            // 386
    RESENTRY(0x00615e18, 2),            // 387
    RESENTRY(0x00615d98, 2),            // 388
    RESENTRY(0x00615dd8, 2),            // 389
    RESENTRY(0x00615da8, 2),            // 390
    RESENTRY(0x00615db8, 2),            // 391
    RESENTRY(0x00615dc8, 2),            // 392
    RESENTRY(0x00619618, 2),            // 393
    RESENTRY(0x00615a84, 2),            // 394
    RESENTRY(0x0061759c, 2),            // 395
    RESENTRY(0x00615cf8, 1),            // 396
    RESENTRY(0x00614008, 1),            // 397
    RESENTRY(0x00604e40, 2),            // 398
    RESENTRY(0x00604e70, 2),            // 399
    RESENTRY(0x00606240, 2),            // 400
    RESENTRY(0x00617454, 1),            // 401
    RESENTRY(0x00619284, 2),            // 402
    RESENTRY(0x00617a90, 1),            // 403
    RESENTRY(0x00614a50, 2),            // 404
    RESENTRY(0x006060d4, 2),            // 405
    RESENTRY(0x00607a18, 2),            // 406
    RESENTRY(0x00605dbc, 2),            // 407
    RESENTRY(0x00604f58, 2),            // 408
    RESENTRY(0x006111e8, 2),            // 409
    RESENTRY(0x00615058, 2),            // 410
    RESENTRY(0x00615068, 2),            // 411
    RESENTRY(0x00615078, 2),            // 412
    RESENTRY(0x00615088, 2),            // 413
    RESENTRY(0x00617444, 2),            // 414
    RESENTRY(0x00615358, 1),            // 415
    RESENTRY(0x0061e084, 2),            // 416
    RESENTRY(0x0061e094, 2),            // 417
    RESENTRY(0x0061e0a4, 2),            // 418
    RESENTRY(0x0061e0b4, 2),            // 419
    RESENTRY(0x0061e044, 2),            // 420
    RESENTRY(0x0061e00c, 2),            // 421
    RESENTRY(0x0061e124, 2),            // 422
    RESENTRY(0x0061e114, 2),            // 423
    RESENTRY(0x0061e0e4, 2),            // 424
    RESENTRY(0x0061e0f4, 2),            // 425
    RESENTRY(0x0061e01c, 2),            // 426
    RESENTRY(0x0061e054, 2),            // 427
    RESENTRY(0x0061e0d4, 2),            // 428
    RESENTRY(0x0061e0c4, 2),            // 429
    RESENTRY(0x0061e074, 2),            // 430
    RESENTRY(0x0061e064, 2),            // 431
    RESENTRY(0x0061874c, 2),            // 432
    RESENTRY(0x0061875c, 2),            // 433
    RESENTRY(0x006159d4, 2),            // 434
    RESENTRY(0x006176f4, 2),            // 435
    RESENTRY(0x00617238, 2),            // 436
    RESENTRY(0x006172e8, 2),            // 437
    RESENTRY(0x00617208, 2),            // 438
    RESENTRY(0x00606720, 2),            // 439
    RESENTRY(nullptr, 0),               // 440
    RESENTRY(nullptr, 0),               // 441
    RESENTRY(nullptr, 0),               // 442
    RESENTRY(nullptr, 0),               // 443
    RESENTRY(nullptr, 0),               // 444
    RESENTRY(nullptr, 0),               // 445
    RESENTRY(nullptr, 0),               // 446
    RESENTRY(nullptr, 0),               // 447
    RESENTRY(nullptr, 0),               // 448
    RESENTRY(nullptr, 0),               // 449
    RESENTRY(nullptr, 0),               // 450
    RESENTRY(nullptr, 0),               // 451
    RESENTRY(nullptr, 0),               // 452
    RESENTRY(nullptr, 0),               // 453
    RESENTRY(nullptr, 0),               // 454
    RESENTRY(nullptr, 0),               // 455
    RESENTRY(nullptr, 0),               // 456
    RESENTRY(nullptr, 0),               // 457
    RESENTRY(nullptr, 0),               // 458
    RESENTRY(nullptr, 0),               // 459
    RESENTRY(nullptr, 0),               // 460
    RESENTRY(nullptr, 0),               // 461
    RESENTRY(nullptr, 0),               // 462
    RESENTRY(nullptr, 0),               // 463
    RESENTRY(nullptr, 0),               // 464
    RESENTRY(nullptr, 0),               // 465
    RESENTRY(nullptr, 0),               // 466
    RESENTRY(nullptr, 0),               // 467
    RESENTRY(nullptr, 0),               // 468
    RESENTRY(nullptr, 0),               // 469
};

u8 ProfileSoundActorKinds[ProfileId::Num] =
{
    0, 0, 0, 0, 0, 0, 0, 0,    //     0-7
    0, 0, 0, 0, 0, 0, 0, 0,    //    8-15
    0, 0, 0, 0, 0, 0, 0, 0,    //   16-23
    0, 0, 0, 0, 0, 0, 0, 0,    //   24-31
    0, 0, 0, 0, 0, 0, 0, 0,    //   32-39
    0, 0, 0, 0, 0, 0, 0, 0,    //   40-47
    0, 0, 0, 0, 0, 0, 0, 0,    //   48-55
    0, 0, 0, 0, 0, 0, 0, 0,    //   56-63
    0, 0, 0, 0, 0, 0, 0, 0,    //   64-71
    0, 0, 0, 0, 0, 0, 0, 0,    //   72-79
    0, 0, 0, 0, 0, 0, 0, 0,    //   80-87
    0, 0, 0, 0, 0, 0, 0, 0,    //   88-95
    0, 0, 0, 0, 0, 0, 0, 0,    //  96-103
    0, 0, 0, 0, 0, 0, 0, 0,    // 104-111
    0, 0, 0, 0, 0, 0, 0, 0,    // 112-119
    0, 0, 0, 0, 0, 0, 0, 1,    // 120-127
    0, 0, 0, 0, 0, 0, 0, 0,    // 128-135
    0, 0, 0, 0, 0, 1, 0, 0,    // 136-143
    0, 0, 0, 0, 0, 0, 0, 0,    // 144-151
    0, 0, 0, 0, 0, 0, 0, 1,    // 152-159
    0, 0, 0, 0, 0, 0, 0, 0,    // 160-167
    0, 0, 0, 0, 0, 0, 0, 0,    // 168-175
    0, 0, 0, 0, 0, 0, 0, 0,    // 176-183
    0, 0, 0, 0, 0, 1, 0, 0,    // 184-191
    0, 0, 1, 1, 1, 1, 0, 0,    // 192-199
    0, 0, 0, 0, 1, 1, 1, 0,    // 200-207
    0, 0, 0, 0, 0, 0, 0, 0,    // 208-215
    0, 0, 0, 0, 0, 0, 0, 0,    // 216-223
    0, 0, 0, 0, 0, 0, 0, 0,    // 224-231
    0, 0, 0, 0, 0, 0, 6, 1,    // 232-239
    1, 1, 1, 1, 1, 0, 0, 0,    // 240-247
    0, 0, 1, 1, 1, 1, 1, 1,    // 248-255
    1, 1, 1, 1, 1, 0, 0, 1,    // 256-263
    1, 1, 0, 0, 0, 0, 1, 1,    // 264-271
    0, 1, 0, 1, 1, 1, 1, 1,    // 272-279
    1, 1, 1, 1, 1, 1, 1, 1,    // 280-287
    1, 1, 1, 1, 1, 1, 1, 1,    // 288-295
    0, 0, 0, 1, 1, 1, 1, 1,    // 296-303
    0, 1, 1, 0, 1, 0, 0, 1,    // 304-311
    0, 1, 1, 1, 0, 1, 1, 1,    // 312-319
    1, 1, 0, 0, 1, 0, 1, 1,    // 320-327
    1, 1, 1, 1, 1, 0, 5, 5,    // 328-335
    5, 5, 1, 1, 1, 1, 1, 1,    // 336-343
    1, 1, 0, 0, 0, 0, 0, 1,    // 344-351
    1, 1, 0, 0, 0, 0, 0, 0,    // 352-359
    0, 0, 0, 0, 0, 0, 0, 0,    // 360-367
    0, 0, 0, 0, 0, 0, 0, 0,    // 368-375
    0, 0, 0, 0, 0, 0, 0, 0,    // 376-383
    0, 0, 0, 0, 0, 0, 0, 0,    // 384-391
    0, 0, 0, 0, 0, 0, 0, 0,    // 392-399
    0, 1, 1, 1, 1, 0, 0, 0,    // 400-407
    0, 0, 0, 0, 0, 0, 0, 0,    // 408-415
    0, 0, 0, 0, 0, 0, 0, 0,    // 416-423
    0, 0, 0, 0, 0, 0, 0, 0,    // 424-431
    0, 0, 0, 0, 0, 0, 0, 0,    // 432-439
    0, 0, 0, 0, 0, 0, 0, 0,    // 440-447
    0, 0, 0, 0, 0, 0, 0, 0,    // 448-455
    0, 0, 0, 0, 0, 0, 0, 0,    // 456-463
    0, 0, 0, 0, 0, 0,          // 464-469
};


#define ACTENTRY(x) \
    (ActorInfo*)(x)

ActorInfo* ActorInfos[ProfileId::Num] =
{
    nullptr,                                    //   0
    nullptr,                                    //   1
    nullptr,                                    //   2
    nullptr,                                    //   3
    nullptr,                                    //   4
    nullptr,                                    //   5
    nullptr,                                    //   6
    nullptr,                                    //   7
    nullptr,                                    //   8
    nullptr,                                    //   9
    nullptr,                                    //  10
    nullptr,                                    //  11
    nullptr,                                    //  12
    nullptr,                                    //  13
    nullptr,                                    //  14
    nullptr,                                    //  15
    nullptr,                                    //  16
    nullptr,                                    //  17
    nullptr,                                    //  18
    nullptr,                                    //  19
    nullptr,                                    //  20
    ACTENTRY(0x0057ae7c),                       //  21
    ACTENTRY(0x0057ae1c),                       //  22
    ACTENTRY(0x0057ad70),                       //  23
    ACTENTRY(0x0057adac),                       //  24
    ACTENTRY(0x0057ae58),                       //  25
    ACTENTRY(0x0057add0),                       //  26
    ACTENTRY(0x0057cb1c),                       //  27
    ACTENTRY(0x0057cd70),                       //  28
    ACTENTRY(0x0057b150),                       //  29
    ACTENTRY(0x0057a51c),                       //  30
    ACTENTRY(0x0057a5b8),                       //  31
    ACTENTRY(0x0057a5dc),                       //  32
    ACTENTRY(0x0057a630),                       //  33
    ACTENTRY(0x0056da28),                       //  34
    ACTENTRY(0x0056cbf0),                       //  35
    ACTENTRY(0x00604c88),                       //  36
    ACTENTRY(0x00604cc4),                       //  37
    ACTENTRY(0x00604d3c),                       //  38
    ACTENTRY(0x00604d00),                       //  39
    ACTENTRY(0x00604d78),                       //  40
    ACTENTRY(0x00604c3c),                       //  41
    ACTENTRY(0x0056df88),                       //  42
    ACTENTRY(0x0057c2c8),                       //  43
    ACTENTRY(0x0057c440),                       //  44
    ACTENTRY(0x0057c464),                       //  45
    ACTENTRY(0x0057b9f0),                       //  46
    ACTENTRY(0x0057ba14),                       //  47
    ACTENTRY(0x0057bb74),                       //  48
    ACTENTRY(0x0057c5bc),                       //  49
    ACTENTRY(0x0057c5e0),                       //  50
    ACTENTRY(0x0057bf50),                       //  51
    ACTENTRY(0x0057c7dc),                       //  52
    ACTENTRY(0x0057c820),                       //  53
    ACTENTRY(0x0057c950),                       //  54
    ACTENTRY(0x0057c060),                       //  55
    ACTENTRY(0x0057c114),                       //  56
    ACTENTRY(0x0057c4d0),                       //  57
    ACTENTRY(0x0057c704),                       //  58
    ACTENTRY(0x0057c7b8),                       //  59
    ACTENTRY(0x0057d704),                       //  60
    ACTENTRY(0x0057dc50),                       //  61
    ACTENTRY(0x0057dc74),                       //  62
    ACTENTRY(0x00579868),                       //  63
    ACTENTRY(0x00579800),                       //  64
    ACTENTRY(0x00579824),                       //  65
    ACTENTRY(0x00579790),                       //  66
    ACTENTRY(0x0056fb1c),                       //  67
    ACTENTRY(0x0057708c),                       //  68
    ACTENTRY(0x00575828),                       //  69
    ACTENTRY(0x00575870),                       //  70
    ACTENTRY(0x0057584c),                       //  71
    ACTENTRY(0x00575948),                       //  72
    ACTENTRY(0x00575990),                       //  73
    ACTENTRY(0x00575894),                       //  74
    ACTENTRY(0x0057596c),                       //  75
    ACTENTRY(0x0056f538),                       //  76
    ACTENTRY(0x005758b8),                       //  77
    ACTENTRY(0x005758dc),                       //  78
    ACTENTRY(0x00575900),                       //  79
    ACTENTRY(0x00575924),                       //  80
    ACTENTRY(0x00579548),                       //  81
    ACTENTRY(0x0057e3d0),                       //  82
    ACTENTRY(0x0057c010),                       //  83
    ACTENTRY(0x0057c034),                       //  84
    ACTENTRY(0x0057dd10),                       //  85
    ACTENTRY(0x0057de5c),                       //  86
    ACTENTRY(0x0057df90),                       //  87
    ACTENTRY(0x0057de38),                       //  88
    ACTENTRY(0x0057d36c),                       //  89
    ACTENTRY(0x0057d390),                       //  90
    ACTENTRY(0x00572908),                       //  91
    ACTENTRY(0x0057a030),                       //  92
    ACTENTRY(0x0057a054),                       //  93
    ACTENTRY(0x0057a078),                       //  94
    ACTENTRY(0x0057a09c),                       //  95
    ACTENTRY(0x0057a208),                       //  96
    ACTENTRY(0x0057a22c),                       //  97
    ACTENTRY(0x0057a250),                       //  98
    ACTENTRY(0x0057a274),                       //  99
    ACTENTRY(0x0057a110),                       // 100
    ACTENTRY(0x0057a134),                       // 101
    ACTENTRY(0x0057a158),                       // 102
    ACTENTRY(0x0057a17c),                       // 103
    ACTENTRY(0x0057a1a0),                       // 104
    ACTENTRY(0x0057d678),                       // 105
    ACTENTRY(0x0057d69c),                       // 106
    ACTENTRY(0x0057d5ac),                       // 107
    ACTENTRY(0x0057d588),                       // 108
    ACTENTRY(0x0057d138),                       // 109
    ACTENTRY(0x0057d294),                       // 110
    ACTENTRY(0x0057de14),                       // 111
    ACTENTRY(0x0057c1e8),                       // 112
    ACTENTRY(0x0057c20c),                       // 113
    ACTENTRY(0x0057e3f4),                       // 114
    ACTENTRY(0x0057e418),                       // 115
    ACTENTRY(0x0057e448),                       // 116
    ACTENTRY(0x0056e988),                       // 117
    ACTENTRY(0x0057af84),                       // 118
    ACTENTRY(0x0057d114),                       // 119
    ACTENTRY(0x0057d0f0),                       // 120
    ACTENTRY(0x0057ac80),                       // 121
    ACTENTRY(0x0057ace8),                       // 122
    ACTENTRY(0x0057ad34),                       // 123
    ACTENTRY(0x0057aeb8),                       // 124
    ACTENTRY(0x0057af0c),                       // 125
    ACTENTRY(0x0057af30),                       // 126
    ACTENTRY(0x005727fc),                       // 127
    ACTENTRY(0x0057cca4),                       // 128
    ACTENTRY(0x0057cd1c),                       // 129
    ACTENTRY(0x0057c138),                       // 130
    ACTENTRY(0x0057c230),                       // 131
    ACTENTRY(0x0057959c),                       // 132
    ACTENTRY(0x005795e0),                       // 133
    ACTENTRY(0x0057c3cc),                       // 134
    ACTENTRY(0x00579ecc),                       // 135
    ACTENTRY(0x00579ef0),                       // 136
    ACTENTRY(0x0056f8b0),                       // 137
    ACTENTRY(0x0056ca10),                       // 138
    ACTENTRY(0x0056ee88),                       // 139
    ACTENTRY(0x0057be98),                       // 140
    ACTENTRY(0x0057bc08),                       // 141
    ACTENTRY(0x005e8148),                       // 142
    ACTENTRY(0x0057a3d0),                       // 143
    ACTENTRY(0x0057a494),                       // 144
    ACTENTRY(0x0056f238),                       // 145
    ACTENTRY(0x0056e404),                       // 146
    ACTENTRY(0x0056ce6c),                       // 147
    ACTENTRY(0x0056d264),                       // 148
    ACTENTRY(0x0057bc50),                       // 149
    ACTENTRY(0x0057bc74),                       // 150
    ACTENTRY(0x0056e3b0),                       // 151
    ACTENTRY(0x0057dbf0),                       // 152
    ACTENTRY(0x0056eedc),                       // 153
    ACTENTRY(0x0057bdd8),                       // 154
    ACTENTRY(0x0057bdfc),                       // 155
    ACTENTRY(0x0057be20),                       // 156
    ACTENTRY(0x0057cc80),                       // 157
    ACTENTRY(0x0056edd0),                       // 158
    ACTENTRY(0x0056e6fc),                       // 159
    ACTENTRY(0x0057cab0),                       // 160
    ACTENTRY(0x00579c54),                       // 161
    ACTENTRY(0x00579f14),                       // 162
    ACTENTRY(0x00579e34),                       // 163
    ACTENTRY(0x005788e8),                       // 164
    ACTENTRY(0x005783dc),                       // 165
    ACTENTRY(0x00578a98),                       // 166
    ACTENTRY(0x0057890c),                       // 167
    ACTENTRY(0x005785a0),                       // 168
    ACTENTRY(0x0057852c),                       // 169
    ACTENTRY(0x00578550),                       // 170
    ACTENTRY(0x00578574),                       // 171
    ACTENTRY(0x00578a2c),                       // 172
    ACTENTRY(0x00578a50),                       // 173
    ACTENTRY(0x00578a74),                       // 174
    ACTENTRY(0x00578838),                       // 175
    ACTENTRY(0x00578730),                       // 176
    ACTENTRY(0x00578754),                       // 177
    ACTENTRY(0x005789b4),                       // 178
    ACTENTRY(0x005789d8),                       // 179
    ACTENTRY(0x005788c4),                       // 180
    ACTENTRY(0x00578430),                       // 181
    ACTENTRY(0x00578244),                       // 182
    ACTENTRY(0x00578454),                       // 183
    ACTENTRY(0x00578930),                       // 184
    ACTENTRY(0x005782f0),                       // 185
    ACTENTRY(0x005783b8),                       // 186
    ACTENTRY(0x0057a79c),                       // 187
    ACTENTRY(0x0057d514),                       // 188
    ACTENTRY(0x0057d538),                       // 189
    ACTENTRY(0x0057d3b4),                       // 190
    ACTENTRY(0x00574dc0),                       // 191
    ACTENTRY(0x00574de4),                       // 192
    ACTENTRY(0x0057470c),                       // 193
    ACTENTRY(0x00574e28),                       // 194
    ACTENTRY(0x00574b64),                       // 195
    ACTENTRY(0x00574f1c),                       // 196
    ACTENTRY(0x00572048),                       // 197
    ACTENTRY(0x0057b03c),                       // 198
    ACTENTRY(0x0057abe0),                       // 199
    ACTENTRY(0x0056c9c8),                       // 200
    ACTENTRY(0x0056c9ec),                       // 201
    ACTENTRY(0x0056e320),                       // 202
    ACTENTRY(0x0056ee34),                       // 203
    ACTENTRY(0x0056ecac),                       // 204
    ACTENTRY(0x0056ed50),                       // 205
    ACTENTRY(0x0057bd9c),                       // 206
    ACTENTRY(0x00578ad4),                       // 207
    ACTENTRY(0x00578f20),                       // 208
    ACTENTRY(0x00578f44),                       // 209
    ACTENTRY(0x00578f68),                       // 210
    ACTENTRY(0x00578f8c),                       // 211
    ACTENTRY(0x00578db0),                       // 212
    ACTENTRY(0x005792e0),                       // 213
    ACTENTRY(0x0057cd94),                       // 214
    ACTENTRY(0x0057cdb8),                       // 215
    ACTENTRY(0x0057cddc),                       // 216
    ACTENTRY(0x0057a7c0),                       // 217
    ACTENTRY(0x0057a7e4),                       // 218
    ACTENTRY(0x00579068),                       // 219
    ACTENTRY(0x0057908c),                       // 220
    ACTENTRY(0x00578ce0),                       // 221
    ACTENTRY(0x00578d64),                       // 222
    ACTENTRY(0x005790b0),                       // 223
    ACTENTRY(0x00578b10),                       // 224
    ACTENTRY(0x00578c5c),                       // 225
    ACTENTRY(0x00579044),                       // 226
    ACTENTRY(0x005791e0),                       // 227
    ACTENTRY(0x00578dec),                       // 228
    ACTENTRY(0x0057c974),                       // 229
    ACTENTRY(0x0057c998),                       // 230
    ACTENTRY(0x00579020),                       // 231
    ACTENTRY(0x0057e334),                       // 232
    ACTENTRY(0x0057e358),                       // 233
    ACTENTRY(0x0057e37c),                       // 234
    ACTENTRY(0x0057e2a4),                       // 235
    ACTENTRY(0x0057e2c8),                       // 236
    ACTENTRY(0x00579434),                       // 237
    ACTENTRY(0x00580580),                       // 238
    ACTENTRY(0x00575344),                       // 239
    ACTENTRY(0x005751c8),                       // 240
    ACTENTRY(0x005751ec),                       // 241
    ACTENTRY(0x00610ff4),                       // 242
    ACTENTRY(0x005721a0),                       // 243
    ACTENTRY(0x005757a8),                       // 244
    ACTENTRY(0x00575b68),                       // 245
    ACTENTRY(0x005755e0),                       // 246
    ACTENTRY(0x00575684),                       // 247
    ACTENTRY(0x00575bc4),                       // 248
    ACTENTRY(0x00575be8),                       // 249
    ACTENTRY(0x005748cc),                       // 250
    ACTENTRY(0x005748f0),                       // 251
    ACTENTRY(0x00574a20),                       // 252
    ACTENTRY(0x0057548c),                       // 253
    ACTENTRY(0x00576b68),                       // 254
    ACTENTRY(0x005761b4),                       // 255
    ACTENTRY(0x00571e8c),                       // 256
    ACTENTRY(0x005724e4),                       // 257
    ACTENTRY(0x00575a4c),                       // 258
    ACTENTRY(0x00573178),                       // 259
    ACTENTRY(0x0057319c),                       // 260
    ACTENTRY(0x00575d88),                       // 261
    ACTENTRY(0x00576f84),                       // 262
    ACTENTRY(0x00575fb4),                       // 263
    ACTENTRY(0x00576094),                       // 264
    ACTENTRY(0x00576fc8),                       // 265
    ACTENTRY(0x00576114),                       // 266
    ACTENTRY(0x00576138),                       // 267
    ACTENTRY(0x00577384),                       // 268
    ACTENTRY(0x00577420),                       // 269
    ACTENTRY(0x00574b28),                       // 270
    ACTENTRY(0x00574694),                       // 271
    ACTENTRY(0x005746b8),                       // 272
    ACTENTRY(0x00574594),                       // 273
    ACTENTRY(0x00576f1c),                       // 274
    ACTENTRY(0x00573fac),                       // 275
    ACTENTRY(0x00572508),                       // 276
    ACTENTRY(0x00573480),                       // 277
    ACTENTRY(0x00573874),                       // 278
    ACTENTRY(0x00574408),                       // 279
    ACTENTRY(0x00574330),                       // 280
    ACTENTRY(0x0057430c),                       // 281
    ACTENTRY(0x005742c4),                       // 282
    ACTENTRY(0x0057439c),                       // 283
    ACTENTRY(0x005742e8),                       // 284
    ACTENTRY(0x00572fbc),                       // 285
    ACTENTRY(0x00572f50),                       // 286
    ACTENTRY(0x00572f74),                       // 287
    ACTENTRY(0x00572f98),                       // 288
    ACTENTRY(0x00572c74),                       // 289
    ACTENTRY(0x00572c2c),                       // 290
    ACTENTRY(0x00572c50),                       // 291
    ACTENTRY(0x00572da4),                       // 292
    ACTENTRY(0x00572d38),                       // 293
    ACTENTRY(0x00572d5c),                       // 294
    ACTENTRY(0x00572d80),                       // 295
    ACTENTRY(0x00576b2c),                       // 296
    ACTENTRY(0x00575ea0),                       // 297
    ACTENTRY(0x00575f54),                       // 298
    ACTENTRY(0x00576698),                       // 299
    ACTENTRY(0x005766bc),                       // 300
    ACTENTRY(0x005768ac),                       // 301
    ACTENTRY(0x00573d90),                       // 302
    ACTENTRY(0x00573ee8),                       // 303
    ACTENTRY(0x00573eac),                       // 304
    ACTENTRY(0x00572230),                       // 305
    ACTENTRY(0x00572294),                       // 306
    ACTENTRY(0x005722b8),                       // 307
    ACTENTRY(0x00576ee0),                       // 308
    ACTENTRY(0x00576310),                       // 309
    ACTENTRY(0x0057634c),                       // 310
    ACTENTRY(0x00572724),                       // 311
    ACTENTRY(0x00572748),                       // 312
    ACTENTRY(0x00573634),                       // 313
    ACTENTRY(0x005740d8),                       // 314
    ACTENTRY(0x00577284),                       // 315
    ACTENTRY(0x00576a44),                       // 316
    ACTENTRY(0x00571d60),                       // 317
    ACTENTRY(0x005742a0),                       // 318
    ACTENTRY(0x00572c08),                       // 319
    ACTENTRY(0x00573b54),                       // 320
    ACTENTRY(0x0057691c),                       // 321
    ACTENTRY(0x00576940),                       // 322
    ACTENTRY(0x00576dd0),                       // 323
    ACTENTRY(0x00576e98),                       // 324
    ACTENTRY(0x00576ebc),                       // 325
    ACTENTRY(0x005737a4),                       // 326
    ACTENTRY(0x00573a40),                       // 327
    ACTENTRY(0x00573a64),                       // 328
    ACTENTRY(0x00572a08),                       // 329
    ACTENTRY(0x00573970),                       // 330
    ACTENTRY(0x0056d4d0),                       // 331
    ACTENTRY(0x00575024),                       // 332
    ACTENTRY(0x00573238),                       // 333
    ACTENTRY(0x0056e2cc),                       // 334
    ACTENTRY(0x0056e344),                       // 335
    ACTENTRY(0x0056de38),                       // 336
    ACTENTRY(0x0056de5c),                       // 337
    ACTENTRY(0x0056f800),                       // 338
    ACTENTRY(0x0056faf8),                       // 339
    ACTENTRY(0x0056f514),                       // 340
    ACTENTRY(0x0056cb84),                       // 341
    ACTENTRY(0x0056d1a4),                       // 342
    ACTENTRY(0x0056f114),                       // 343
    ACTENTRY(0x0056e8a4),                       // 344
    ACTENTRY(0x0056ec38),                       // 345
    ACTENTRY(0x0056ced8),                       // 346
    ACTENTRY(0x0056ffd8),                       // 347
    ACTENTRY(0x0056fde8),                       // 348
    ACTENTRY(0x0056fee4),                       // 349
    ACTENTRY(0x0056fe84),                       // 350
    ACTENTRY(0x00570060),                       // 351
    ACTENTRY(0x0056fc14),                       // 352
    ACTENTRY(0x005700f0),                       // 353
    ACTENTRY(0x0056dae4),                       // 354
    ACTENTRY(0x0056e964),                       // 355
    ACTENTRY(0x0056cc38),                       // 356
    ACTENTRY(0x0056e034),                       // 357
    ACTENTRY(0x0056e164),                       // 358
    ACTENTRY(0x00578010),                       // 359
    ACTENTRY(0x00577ce4),                       // 360
    ACTENTRY(0x00577d08),                       // 361
    ACTENTRY(0x00578200),                       // 362
    ACTENTRY(0x00578134),                       // 363
    ACTENTRY(0x00578194),                       // 364
    ACTENTRY(0x00577c84),                       // 365
    ACTENTRY(0x005780ec),                       // 366
    ACTENTRY(0x00578110),                       // 367
    ACTENTRY(0x005781b8),                       // 368
    ACTENTRY(0x005781dc),                       // 369
    ACTENTRY(0x0057ce30),                       // 370
    ACTENTRY(0x0057ce54),                       // 371
    ACTENTRY(0x0057d88c),                       // 372
    ACTENTRY(0x0057da04),                       // 373
    ACTENTRY(0x0057dadc),                       // 374
    ACTENTRY(0x0057dbcc),                       // 375
    ACTENTRY(0x0057ddcc),                       // 376
    ACTENTRY(0x0057ddf0),                       // 377
    ACTENTRY(0x0057d078),                       // 378
    ACTENTRY(0x0057d09c),                       // 379
    ACTENTRY(0x0057d8b0),                       // 380
    ACTENTRY(0x0057da28),                       // 381
    ACTENTRY(0x0057B558),                       // 382
    ACTENTRY(0x0057b57c),                       // 383
    ACTENTRY(0x0057ab20),                       // 384
    ACTENTRY(0x0057aa90),                       // 385
    ACTENTRY(0x0057aad8),                       // 386
    ACTENTRY(0x0057ab68),                       // 387
    ACTENTRY(0x0057a94c),                       // 388
    ACTENTRY(0x0057aa48),                       // 389
    ACTENTRY(0x0057a994),                       // 390
    ACTENTRY(0x0057a9b8),                       // 391
    ACTENTRY(0x0057aa00),                       // 392
    ACTENTRY(0x0057dd34),                       // 393
    ACTENTRY(0x0057A730),                       // 394
    ACTENTRY(0x0057b63c),                       // 395
    ACTENTRY(0x0057a8c8),                       // 396
    ACTENTRY(0x00578508),                       // 397
    ACTENTRY(0x0056cca0),                       // 398
    ACTENTRY(0x0056cd04),                       // 399
    ACTENTRY(0x0056e0dc),                       // 400
    ACTENTRY(0x0057b510),                       // 401
    ACTENTRY(0x0057d76c),                       // 402
    ACTENTRY(0x0057bd38),                       // 403
    ACTENTRY(0x00579304),                       // 404
    ACTENTRY(0x0056dea4),                       // 405
    ACTENTRY(0x0056f5d4),                       // 406
    ACTENTRY(0x0056dbac),                       // 407
    ACTENTRY(0x0056cdf4),                       // 408
    ACTENTRY(0x00575c44),                       // 409
    ACTENTRY(0x00579a64),                       // 410
    ACTENTRY(0x00579ae0),                       // 411
    ACTENTRY(0x00579b5c),                       // 412
    ACTENTRY(0x00579bd8),                       // 413
    ACTENTRY(0x0057b430),                       // 414
    ACTENTRY(0x00579f50),                       // 415
    ACTENTRY(0x0058231c),                       // 416
    ACTENTRY(0x00582340),                       // 417
    ACTENTRY(0x00582364),                       // 418
    ACTENTRY(0x00582388),                       // 419
    ACTENTRY(0x0058228c),                       // 420
    ACTENTRY(0x00582244),                       // 421
    ACTENTRY(0x00582460),                       // 422
    ACTENTRY(0x0058243c),                       // 423
    ACTENTRY(0x005823f4),                       // 424
    ACTENTRY(0x00582418),                       // 425
    ACTENTRY(0x00582268),                       // 426
    ACTENTRY(0x005822b0),                       // 427
    ACTENTRY(0x005823d0),                       // 428
    ACTENTRY(0x005823ac),                       // 429
    ACTENTRY(0x005822f8),                       // 430
    ACTENTRY(0x005822d4),                       // 431
    ACTENTRY(0x0057ca34),                       // 432
    ACTENTRY(0x0057ca8c),                       // 433
    ACTENTRY(0x0057a654),                       // 434
    ACTENTRY(0x0057b93c),                       // 435
    ACTENTRY(0x0057b1b0),                       // 436
    ACTENTRY(0x0057b294),                       // 437
    ACTENTRY(0x0057b174),                       // 438
    ACTENTRY(0x0056e604),                       // 439
    nullptr,                                    // 440
    nullptr,                                    // 441
    nullptr,                                    // 442
    nullptr,                                    // 443
    nullptr,                                    // 444
    nullptr,                                    // 445
    nullptr,                                    // 446
    nullptr,                                    // 447
    nullptr,                                    // 448
    nullptr,                                    // 449
    nullptr,                                    // 450
    nullptr,                                    // 451
    nullptr,                                    // 452
    nullptr,                                    // 453
    nullptr,                                    // 454
    nullptr,                                    // 455
    nullptr,                                    // 456
    nullptr,                                    // 457
    nullptr,                                    // 458
    nullptr,                                    // 459
    nullptr,                                    // 460
    nullptr,                                    // 461
    nullptr,                                    // 462
    nullptr,                                    // 463
    nullptr,                                    // 464
    nullptr,                                    // 465
    nullptr,                                    // 466
    nullptr,                                    // 467
    nullptr,                                    // 468
    nullptr,                                    // 469
};


// All tables must have the same amount of entries
static_assert(sizeof(Profiles)/sizeof(Profile) == sizeof(ProfileInfos)/sizeof(ProfileInfo), "ProfileInfo size must match Profiles size"           );
static_assert(sizeof(Profiles)/sizeof(Profile) == sizeof(ResTable)/sizeof(ResTableEntry),   "ResTable size must match Profiles size"              );
static_assert(sizeof(Profiles)/sizeof(Profile) == (sizeof(ProfileSoundActorKinds)),         "ProfileSoundActorKinds size must match Profiles size");
static_assert(sizeof(Profiles)/sizeof(Profile) == sizeof(ActorInfos)/sizeof(ActorInfo*),    "ActorInfos size must match Profiles size"            );


extern Profile* profileTablePtr;
extern ProfileInfo* profileInfoTablePtr;
extern u32 numProfiles;

void InitProfileTablePtrs()
{
    profileTablePtr = Profiles;
    profileInfoTablePtr = ProfileInfos;
    numProfiles = sizeof(Profiles) / sizeof(Profile);
}

u16 numProfiles2 = sizeof(Profiles) / sizeof(Profile);
