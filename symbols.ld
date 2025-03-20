/* aeabi */
__aeabi_ldivmod = 0x00106D44;
__aeabi_uidivmod = 0x00119DC4;
__aeabi_idivmod = 0x0011B6E8;
__aeabi_memclr4 = 0x00110894;
__aeabi_memclr8 = 0x00110854;
__aeabi_memset = 0x00110858;
__aeabi_memcpy4 = 0x00114E34;
__aeabi_memcpy = 0x00119D3C;

/* string.h */
memclr = 0x00110854;
memset = 0x00110834;
memcpy = 0x00119D3C;
strcmp = 0x001037C8;
strncmp = 0x0011F1B0;
strncpy = 0x0011F2A0;
strcpy = 0x0011F368;
strlen = 0x001107D4;

/* math.h */
fmodf = 0x004B5208;
sinf = 0x004B5A5C;
cosf = 0x004B4C64;
tanf = 0x004B5C24;
acosf = 0x004B4824;
atan2f = 0x004B4964;
powf = 0x004B52E8;

/* stdio.h */
snprintf = 0x001636AC;      /* not actual snprintf: nn::nstd::TSNPrintf */


/* Temp Zone. Sort/delete me */

_Z7playSfxjRKN4sead7Vector3IfEEj = 0x002147D0;
_Z7playSfxPKcRKN4sead7Vector3IfEEj = 0x0021465C; 
_Z18playSfxWhileCalledjjRKN4sead7Vector3IfEE = 0x002144A8;

_Z11spawnEffectjRKN4sead7Vector3IfEEPNS0_IiEEPS1_ = 0x001D0B28;

_Z14smoothRotationRiRKiS1_ = 0x003A99DC;
_Z17smoothStepTowardsRfffff = 0x0040A550;
_Z11moveTowardsRN4sead7Vector3IfEERKS1_f = 0x0055FA68;

_ZN5Mtx334copyERS_RKS_ = 0x004618C4;
_ZN5Mtx3311makeRzxyIdxERS_jjj = 0x004617F8;
_ZN5Mtx335makeRERS_N4sead7Vector3IfEE = 0x004618C4;


_ZN5Mtx3425setRotationAndTranslationERKN4sead7Vector3IiEERKNS1_IfEE = 0x004620D8;
_ZN5Mtx347rotateXERKj = 0x0040A610;
_ZN5Mtx347rotateYERKj = 0x0040A6A0;
_ZN5Mtx347rotateZERKj = 0x0040A730;
_ZN5Mtx345identE = 0x006C3B40;
_ZN5Mtx348multiplyEPS_RKS_S2_ = 0x0011E4F0;

_ZN5Mtx446swapXYEv = 0x00469774;

playerMaxJumpHeight = 0x0057F314;
playerDescentRate = 0x0057F324;

playerRegularJumpArc = 0x0057FE64;
playerMiniJumpArc = 0x0057FEAC;
playerUnkJumpArc = 0x0057FEF4;

GetServiceHandle = 0x0010C698;
CreateMemoryBlock = 0x0011F0F8;

FindArchive = 0x005511A8;
FileServer_ControlArchive = 0x00140D74;

_ZN18UnkLightRelatedMgr8instanceE = 0x005E7348;


/* Profiles */
profileTablePtr = 0x005F399C;
profileInfoTablePtr = 0x005F3998;
numProfiles = 0x005F39A0;


/* (De)allocation */
AllocFromActorHeap = 0x004578CC;
FreeToActorHeap = 0x004578C8;
_Z18AllocFromActorHeapj = 0x004578CC;
_Z15FreeToActorHeapPv = 0x004578C8;
_Znwj = 0x0010EBEC;
_Znaj = 0x0010EBEC;
_ZnwjPN4sead4HeapEj = 0x0010EBA4;
_ZnajPN4sead4HeapEj = 0x0010EBA4;
_ZdlPv = 0x004B3978;
_ZdlPvj = 0x004B3978;
_ZdaPv = 0x004B3978;
_ZdaPvj = 0x004B3978;


SystemHeap = 0x005EFD30;
ActorHeap = 0x005EFCE0;
ModelResourceHeap = 0x005EFCE4;
ModelSetupHeap = 0x005EFCE8;
BgUnitHeap = 0x005EFCEC;
CourseHeap = 0x005EFCF0;
AreaHeap = 0x005EFCF4;
SeadParticleHeap = 0x005EFCF8;
FaderHeap = 0x005EFCFC;
FontHeap = 0x005EFD00;
SaveHeap = 0x005EFD04;
UIHeap = 0x005EFD08;
SoundResourceHeap = 0x005EFD0C;
SoundHeap = 0x005EFD10;
NetHeap = 0x005EFD14;
WorkHeap = 0x005EFD18;
DebugHeap = 0x005EFD1C;


/* Heap Allocator */
_ZN13HeapAllocatorC1Ev = 0x0010A210;
_ZN13HeapAllocatorC2Ev = 0x0010A210;
_ZN13HeapAllocator4linkEPN4sead4HeapE = 0x0010A204;

_Z13AllocFromHeapjPN4sead4HeapEj = 0x0010EBA4;


/* PtclMgr */
_ZN7PtclMgr9sInstanceE = 0x005E6190;
_ZN7PtclMgr7executeEv = 0x003F4AC8;
_ZN7PtclMgr14createInstanceEPN4sead4HeapE = 0x003F4688;
_ZN7PtclMgr6unloadEv = 0x003F4788;
_ZN7PtclMgr4drawEiPN4sead6CameraE = 0x003F4430;

/* Effect */
_ZN6EffectC1Ev = 0x001D0A24;
_ZN6Effect11setEffectIdEj = 0x001D04C4;
_ZN6Effect6updateEPKN4sead7Vector3IfEEPKNS1_IiEES4_ = 0x001D0838;
_ZN6Effect6removeEv = 0x001D0740;
_ZN6Effect7isAliveEv = 0x00497510;

/* ScopedEffect */
_ZN12ScopedEffectC1Ev = 0x003125A0;
_ZN12ScopedEffectD1Ev = 0x00312544;
_ZN12ScopedEffectD2Ev = 0x00312544;
_ZN12ScopedEffect3vf0Ev = 0x0;
_ZN12ScopedEffect3vf4Ev = 0x0;
_ZN12ScopedEffect18getRuntimeTypeInfoEv = 0x004A31DC;
_ZN12ScopedEffect12createEffectEjPKN4sead7Vector3IfEEPKNS1_IiEES4_ = 0x00236E84;

/* UnkEffect */
_ZN13UnkEffectTypeC1Ev = 0x00237100;
_ZN13UnkEffectType18getRuntimeTypeInfoEv = 0x0049C628;

/* nn::gx */
_Z40nn_gxlow_CTR_detail_GetInterruptReceiverv = 0x0011879C;
_Z37nn_gxlow_CTR_CmdReqQueueTx_TryEnqueuePhPj = 0x0011AAC4;

/* nngx */
nngxActiveDisplay = 0x001067F4;
nngxSwapBuffers = 0x00542428;
nngxGetDisplaybufferParameteri = 0x00542144;
nngxGetPhysicalAddr = 0x0011ABC0;
nngxMoveCommandbufferPointer = 0x0010FF54;
nngxGetCmdlistParameteri = 0x0010FD7C;
nngxAddBlockImageCopyCommand = 0x005419A8;
nngxUpdateState = 0x00542658;
nngxValidateState = 0x00542CD4;
nngxWaitCmdlistDone = 0x00542EB8;
nngxBindDisplaybuffer = 0x00106880;

/* nn::gr */
_ZN2nn2gr3CTR19CopyMtx34WithHeaderEPfPKNS_4math5MTX34Ej = 0x0011D6D0;
_ZN2nn2gr3CTR19CopyMtx34WithHeaderEPfPKN4sead8Matrix34IfEEj = 0x0011D6D0;
_ZN2nn2gr3CTR19CopyMtx44WithHeaderEPfPKNS_4math5MTX44Ej = 0x0011D70C;
_ZNK2nn2gr3CTR6Vertex15MakeDrawCommandEPjRKNS2_11IndexStreamE = 0x004882B8;
_ZNK2nn2gr3CTR6Vertex22MakeEnableAttrCommand_EPj = 0x00488358;
_ZNK2nn2gr3CTR8Combiner11MakeCommandEPj = 0x00489050;
_ZNK2nn2gr3CTR7Texture11MakeCommandEPjb = 0x00488E48;

/* gl */
__gl_state = 0x005F4F08;
__vbman = 0x005F4F30;
__shminpgID = 0x005F4BF4;
__shminshID = 0x005F4BF8;
__shman = 0x005F4BFC;
__dmpgl_allocator = 0x005F2EB0;
__dmpgl_deallocator = 0x005F2EB4;
__cb_current_command_buffer = 0x005F2EA0;
__cb_current_max_command_buffer = 0x005F2EA4;

shm_uniformiv = 0x00547E7C;
shm_uniformfv = 0x0054343C;
shm_deleteProgramObject = 0x00543298;

glBindTexture = 0x0053B7BC;
glGetTexParameteriv = 0x0053D7E0;
glCreateProgram = 0x0053C474;
glCreateShader = 0x0053C58C;
glShaderBinary = 0x0053F614;
glAttachShader = 0x0053B170;
glDetachShader = 0x0053CF4C;
glDeleteShader = 0x0053C8B8;
glBindAttribLocation = 0x0053B22C;
glLinkProgram = 0x0053DB78;
glUseProgram = 0x0541064;
glGenBuffers = 0x0053D574;
glBindBuffer = 0x0053B378;
glBufferData = 0x0053BFF8;
glDrawArrays = 0x0053D0E8;
glGetUniformLocation = 0x0053DA00;
glUniform1i = 0x00541018;
glUniform4fv = 0x00541034;
glViewport = 0x005415AC;
glTexParameteri = 0x00540D2C;
glTexParameteriv = 0x00540D40;
glDeleteTextures = 0x0053C9F4;

/* nn::tpl */
_ZN2nn3tpl10GetTextureEPiPjPKvs = 0x0012E03C;
_ZN2nn3tpl15GetTextureIndexEPKvPKc = 0x0012E0E4;

/* nn::hid */
_ZN2nn3hid6getPadEv = 0x0014D684;
_ZN2nn3hid9PadReaderC1ERNS0_3PadE = 0x0014DB58;
_ZN2nn3hid9PadReaderC2ERNS0_3PadE = 0x0014DB58;
_ZN2nn3hid9PadReader4ReadEPNS0_9PadStatusEPii = 0x0014DA14;
_ZN2nn3hid9PadReader10ReadLatestEPNS0_9PadStatusE = 0x0014D8CC;

/* nn::cfg */
_ZN2nn3cfg11GetUserNameEPNS0_8UserNameE = 0x001484A8;
_ZN2nn3cfg11GetLanguageEv = 0x00103AD0;
_ZN2nn3cfg9GetRegionEv = 0x00107568;
_ZN2nn3cfg17GetLanguageCodeA2Eh = 0x001485B0;
_ZN2nn3cfg12IsAgreedEulaEv = 0x001484E0;
_ZN2nn3cfg16IsRestrictP2pCecEv = 0x00148578;
_ZN2nn3cfg17GetTransferableIdEj = 0x001485D0;
_ZN2nn3cfg18GetLocalFriendCodeEv = 0x001485F8;

/* nn::fnd */
_ZN2nn3fnd8DateTimeC2Eiiiiiii = 0x001075B0;
_ZN2nn3fnd8DateTime6GetNowEv = 0x00101EAC;
_ZNK2nn3fnd8DateTime14GetMilliSecondEv = 0x00103350;
_ZNK2nn3fnd8DateTime6GetDayEv = 0x001033A4;
_ZNK2nn3fnd8DateTime7GetHourEv = 0x001033FC;
_ZNK2nn3fnd8DateTime7GetWeekEv = 0x00103464;
_ZNK2nn3fnd8DateTime7GetYearEv = 0x001034F4;
_ZNK2nn3fnd8DateTime8GetMonthEv = 0x0010354C;
_ZNK2nn3fnd8DateTime9GetMinuteEv = 0x001035A4;
_ZNK2nn3fnd8DateTime9GetSecondEv = 0x00103610;

/* nn::applet */
_ZN2nn6applet18StartLibraryAppletEjPKhjNS_6HandleE = 0x0016501C;
_ZN2nn6applet27PrepareToStartLibraryAppletEj = 0x00165818;
_ZN2nn6applet15WaitForStartingEPjPhjPiPNS_6HandleENS_3fnd8TimeSpanE = 0x00107B58;
_ZN2nn6applet13WAIT_INFINITEE = 0x005F30D8;


/* nn::srv */
_ZN2nn3srv16GetServiceHandleEPNS_6HandleEPKcij = 0x0010C698;

/* nn::ulcd::CTR::StereoCamera */
_ZN2nn4ulcd3CTR12StereoCameraC2Ev = 0x00163EF0;
_ZN2nn4ulcd3CTR12StereoCamera10InitializeEv = 0x00163704;
_ZN2nn4ulcd3CTR12StereoCamera13SetBaseCameraEPKNS_4math5MTX34E = 0x001637D4;
_ZN2nn4ulcd3CTR12StereoCamera16SetLimitParallaxEf = 0x00163824;
_ZN2nn4ulcd3CTR12StereoCamera17CalculateMatricesEPNS_4math5MTX44EPNS3_5MTX34ES5_S7_ffNS3_14PivotDirectionE = 0x00163854;
_ZN2nn4ulcd3CTR12StereoCamera21CalculateMatricesRealEPNS_4math5MTX44EPNS3_5MTX34ES5_S7_ffNS3_14PivotDirectionE = 0x00163B8C;
_ZNK2nn4ulcd3CTR12StereoCamera11GetParallaxEf = 0x0048A27C;
_ZNK2nn4ulcd3CTR12StereoCamera14GetMaxParallaxEv = 0x0048A2B4;
_ZNK2nn4ulcd3CTR12StereoCamera25GetCoefficientForParallaxEv = 0x0048A2F8;

/* File Related */
/* _Z11TryOpenFilePPvPKwj = 0x0013FC70; */
_Z14TryGetFileSizePxPv = 0x0013FED4;
_Z11TryReadFilePiPvxS0_j = 0x0013FD04;
_Z12TryWriteFilePiPvxS0_jb = 0x0013FD64;
_Z8MountRomPKcjjPvjb = 0x00117F3C;
_Z8MountRomjjPvjb = 0x00114FD0;
_Z9MountSdmcPKc = 0x001416E0;
_Z7UnmountPKc = 0x0014155C;

_Z16TryOpenDirectoryPPvPKw = 0x0013FF48;
_Z14CloseDirectoryPv = 0x0013FEBC;
_Z16TryReadDirectoryPiPvP14DirectoryEntryi = 0x0013FFD4;

/* SarcMgr */
_ZN7SarcMgr8instanceE = 0x005ED378;
_ZN7SarcMgr13getCourseFileERKN4sead14SafeStringBaseIcEEPj = 0x003DE0F0;
_ZN7SarcMgr7getFileERKN4sead14SafeStringBaseIcEES4_Pj = 0x003DE3F0;

/* CtpkTexture */
_ZN11CtpkTextureC1Ev = 0x0045CFA0;
_ZN11CtpkTextureC2Ev = 0x0045CFA0;
_ZN11CtpkTextureD1Ev = 0x0045CFE4;
_ZN11CtpkTexture12loadFromCtpkEPvRKN4sead14SafeStringBaseIcEEj = 0x003FCA04;
_ZN11CtpkTexture11loadFromResEPN2nw3gfx3res10ResTextureE = 0x003FAD00;
_ZN11CtpkTexture15loadFromArchiveERKN4sead14SafeStringBaseIcEEijPNS0_4HeapE = 0x0045C328;

/* sead::RuntimeTypeInfo::Root */
_ZTVN4sead15RuntimeTypeInfo4RootE = 0x005D1C00;
_ZNK4sead15RuntimeTypeInfo4Root9isDerivedEPKNS0_9InterfaceE = 0x004B19C0;

/* sead::IDisposer */
_ZTVN4sead9IDisposerE = 0x005D3354;
_ZN4sead9IDisposerC2Ev = 0x0010E5F0;
_ZN4sead9IDisposerD2Ev = 0x0010A028;

/* sead::SafeString */
_ZTVN4sead14SafeStringBaseIcEE = 0x005D1984;    /* 0x005D198C */
_ZN4sead14SafeStringBaseIcED0Ev = 0x0055E968;
_ZN4sead14SafeStringBaseIcED1Ev = 0x0055E968;
_ZNK4sead14SafeStringBaseIcE22assureTerminationImpl_Ev = 0x005668A4;
_ZNK4sead14SafeStringBaseIcE9findIndexERKS1_ = 0x00119B78;
_ZNK4sead14SafeStringBaseIcE10rfindIndexERKS1_ = 0x0056652C;
_ZNK4sead14SafeStringBaseIcE7isEqualERKS1_ = 0x005668A8;
_ZNK4sead14SafeStringBaseIcE8comparenERKS1_i = 0x00566930;
_ZNK4sead14SafeStringBaseIcE2atEi = 0x005669FC;
_ZN4sead14SafeStringBaseIcE9cNullCharE = 0x0059939C;
_ZN4sead14SafeStringBaseIwE9cNullCharE = 0x0059939E;
_ZN4sead14SafeStringBaseIcE12cEmptyStringE = 0x006032F0;
_ZN4sead14SafeStringBaseIwE12cEmptyStringE = 0x006032F8;

/* sead::BufferedSafeStringBase */
_ZN4sead22BufferedSafeStringBaseIcE6formatEPKcz = 0x00467730;
_ZN4sead22BufferedSafeStringBaseIwE6formatEPKwz = 0x00467824;
_ZN4sead22BufferedSafeStringBaseIcE4copyERKNS_14SafeStringBaseIcEEi = 0x0055F440;
_ZN4sead22BufferedSafeStringBaseIcE6copyAtEiRKNS_14SafeStringBaseIcEEi = 0x00119A64;

/* sead::ControllerBase  */
_ZN4sead14ControllerBase15cInvalidPointerE = 0x005F3B18;
_ZN4sead14ControllerBase18cInvalidPointerS32E = 0x005F3B20;

/* sead::MathCtr */
_ZN4sead7MathCtrIfE9sinCosIdxEPfS2_j = 0x0011DE48;
_ZN4sead7MathCtrIfE6tanIdxEj = 0x0011DE88;
_ZN4sead7MathCtrIfE7atanIdxEj = 0x0045FEB0;
_ZN4sead7MathCtrIfE8atan2IdxEff = 0x0045FD9C;

/* sead::FileHandle */
_ZTVN4sead10FileHandleE = 0x005D11D0;
_ZN4sead10FileHandleD1Ev = 0x0045B6D0;
_ZN4sead10FileHandleD2Ev = 0x0045B6D0;
_ZN4sead10FileHandle5closeEv = 0x0010D8AC;
_ZN4sead10FileHandle4readEPhj = 0x0045B510;
_ZN4sead10FileHandle7tryReadEPjPhj = 0x0010D91C;
_ZN4sead10FileHandle5writeEPKhj = 0x0045B5D0;
_ZN4sead10FileHandle8tryWriteEPjPKhj = 0x0045B658;
_ZN4sead10FileHandle11getFileSizeEv = 0x0045B45C;
_Z11sdmcFileIncv = 0x0047EA38;
_Z11sdmcFileDecv = 0x0047EE50;

/* sead::FileDevice */
_ZN4sead10FileDevice14tryIsExistFileEPbRKNS_14SafeStringBaseIcEE = 0x0045AEFC;
_ZN4sead10FileDevice14tryGetFileSizeEPjPNS_10FileHandleE = 0x0010D714;
_ZN4sead10FileDevice17tryCloseDirectoryEPNS_15DirectoryHandleE = 0x0045AFFC;
_ZN4sead10FileDevice19tryIsExistDirectoryEPbRKNS_14SafeStringBaseIcEE = 0x0045B064;

/* sead::FileDeviceMgr */
_ZN4sead13FileDeviceMgr9sInstanceE = 0x005F3B78;
_ZN4sead13FileDeviceMgr7tryOpenEPNS_10FileHandleERKNS_14SafeStringBaseIcEENS_10FileDevice12FileOpenFlagEj = 0x0010D948;
_ZNK4sead13FileDeviceMgr18findDeviceFromPathERKNS_14SafeStringBaseIcEEPNS_22BufferedSafeStringBaseIcEE = 0x00112A0C;

/* sead::Arena */
_ZN4sead5ArenaC1Ev = 0x0047788C;
_ZN4sead5ArenaD1Ev = 0x004778A0;
_ZN4sead5Arena10initializeEm = 0x001193B4;


/* sead::Heap */
_ZN4sead4HeapC2ERKNS_14SafeStringBaseIcEEPS0_PvmNS0_13HeapDirectionEb = 0x00116E44;
_ZN4sead4Heap15appendDisposer_EPNS_9IDisposerE = 0x0011AE3C;
_ZN4sead4Heap9destruct_Ev = 0x00469828;
_ZN4sead4Heap8dispose_EPKvS2_ = 0x00469788;
_ZN4sead4Heap16findContainHeap_EPKv = 0x0011C4E4;
_ZN4sead4Heap18getRuntimeTypeInfoEv = 0x004B2428;
_ZN4sead4Heap15removeDisposer_EPNS_9IDisposerE = 0x0010DEF8;
_ZN4sead4HeapD2Ev = 0x004698D8;
_ZZN4sead4Heap24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603F9C;
_ZN4sead4Heap15genInformation_EPNS_6hosito7ContextE = 0x0;
_ZNK4sead4Heap4dumpEv = 0x0;

/* sead::HeapMgr */
_ZN4sead7HeapMgr9sInstanceE = 0x005F3E50;
_ZN4sead7HeapMgr12sInstancePtrE = 0x005F3E48;
_ZN4sead7HeapMgr15sHeapTreeLockCSE = 0x006B664C;
_ZN4sead7HeapMgr10sRootHeapsE = 0x006B6630;
_ZN4sead7HeapMgr13sDefaultArenaE = 0x006B6624;
_ZN4sead7HeapMgr6sArenaE = 0x005F3E4C;
_ZNK4sead7HeapMgr15findContainHeapEPKv = 0x001197C8;
_ZNK4sead7HeapMgr14getCurrentHeapEv = 0x0011340C;
_ZN4sead7HeapMgr10initializeEj = 0x0011732C;
_ZN4sead7HeapMgr15setCurrentHeap_EPNS_4HeapE = 0x00109E10;
_ZN4sead7HeapMgrD2Ev = 0x00478A64;

/* sead::PrimitiveRenderer */
_ZN4sead17PrimitiveRenderer9sInstanceE = 0x005F3DC8;

/* sead::Projection */
_ZTVN4sead10ProjectionE = 0x005D1234;
_ZNK4sead10Projection20doUpdateDeviceMatrixEPNS_8Matrix44IfEERKS2_NS_8Graphics13DevicePostureE = 0x004B0A68;
_ZNK4sead10Projection25getDeviceProjectionMatrixEv = 0x004B0C4C;
_ZZN4sead10Projection24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603EC4;
_ZNK4sead10Projection19getProjectionMatrixEv = 0x004B08E0;


/* sead::PerspectiveProjection */
_ZN4sead21PerspectiveProjectionC1Ev = 0x004668E4;
_ZN4sead21PerspectiveProjectionC2Ev = 0x004668E4;
_ZN4sead21PerspectiveProjection3setEffff = 0x00466830;
_ZN4sead21PerspectiveProjection8setFovy_Ef = 0x00466894;

/* sead::OrthoProjection */
_ZTVN4sead15OrthoProjectionE = 0x005D1BD0;
_ZN4sead15OrthoProjectionC1Ev = 0x004621EC;
_ZNK4sead15OrthoProjection18getRuntimeTypeInfoEv = 0x004B1974;
_ZNK4sead15OrthoProjection17getProjectionTypeEv = 0x004B196C;
_ZNK4sead15OrthoProjection14doUpdateMatrixEPNS_8Matrix44IfEE = 0x004B18A0;
_ZN4sead15OrthoProjection7setTBLREffff = 0x004621D8;

/* sead::Graphics */
_ZN4sead8Graphics9sInstanceE = 0x005F3D98;
_ZN4sead8Graphics21sDefaultDevicePostureE = 0x005F3D9C;
_ZN4sead8Graphics20sDefaultDeviceZScaleE = 0x005F3DA0;
_ZN4sead8Graphics21sDefaultDeviceZOffsetE = 0x005F3DA4;


/* sead::Camera */
_ZTVN4sead6CameraE = 0x005D2EE0;
_ZNK4sead6Camera27worldPosToCameraPosByMatrixEPNS_7Vector3IfEERKS2_ = 0x004B24CC;

/* sead::LookAtCamera */
_ZTVN4sead12LookAtCameraE = 0x005D1374;
_ZNK4sead12LookAtCamera14doUpdateMatrixEP5Mtx34 = 0x004B0DD8;

/* sead::OrthoCamera */
_ZTVN4sead11OrthoCameraE = 0x005D1304;
_ZN4sead11OrthoCameraC1Ev = 0x0045BF04;
_ZN4sead11OrthoCameraC2ERKNN4sead7Vector2IfEEEf = 0x0045BE60;

/* sead::Vector4 */
_ZN4sead7Vector4IfE4zeroE = 0x006C3848;
_ZN4sead7Vector4IfE2exE = 0x006C3808;
_ZN4sead7Vector4IfE2eyE = 0x006C3818;
_ZN4sead7Vector4IfE2ezE = 0x006C3828;
_ZN4sead7Vector4IfE2ewE = 0x006C37F8;
_ZN4sead7Vector4IfE4onesE = 0x006C3838;

/* sead::Matrix44 */
_ZN4sead8Matrix44IfE5identE = 0x006C3CB0;
/*_ZN4sead15Matrix44CalcCtrIfE8multiplyERN2nn4math5MTX44ERKS4_S7_ = 0x0011E654;*/

/* sead::BoundBox3 */
_ZN4sead9BoundBox3IfEC1Ev = 0x002AF360;
_ZN4sead9BoundBox3IfEC1ERKNS_7Vector3IfEES5_ = 0x002AF304;

/* sead::Graphics */
_ZN4sead8Graphics9sInstanceE = 0x005F3D98;

/* sead::DateTime */
_ZN4sead8DateTime6setNowEv = 0x0047A2BC;
_ZNK4sead8DateTime15getCalendarTimeEPNS_12CalendarTimeE = 0x004B2A6C;

/* sead::CalendarTime */
_ZN4sead12CalendarTimeC1ERKNS0_4YearERKNS0_5MonthERKNS0_3DayERKNS0_4HourERKNS0_6MinuteERKNS0_6SecondE = 0x0045C98C;
_ZN4sead12CalendarTimeC2ERKNS0_4YearERKNS0_5MonthERKNS0_3DayERKNS0_4HourERKNS0_6MinuteERKNS0_6SecondE = 0x0045C98C;
_ZN4sead12CalendarTime12cDefaultYearE = 0x005F4068;
_ZN4sead12CalendarTime13cDefaultMonthE = 0x005F406C;
_ZN4sead12CalendarTime11cDefaultDayE = 0x005F4070;
_ZN4sead12CalendarTime12cDefaultHourE = 0x005F4074;
_ZN4sead12CalendarTime14cDefaultMinuteE = 0x005F4078;
_ZN4sead12CalendarTime14cDefaultSecondE = 0x005F407C;

/* sead::MathCalcCommon<float> */
_ZN4sead14MathCalcCommonIfE9sinCosIdxEPfS2_j = 0x0011DE48;
_ZN4sead14MathCalcCommonIfE6tanIdxEj = 0x0011DE88;
_ZN4sead14MathCalcCommonIfE8atan2IdxEff = 0x0045FD9C;
_ZN4sead14MathCalcCommonIfE8atanIdx_Ef = 0x0045FEB0;
_ZN4sead14MathCalcCommonIfE10cSinCosTblE = 0x00597F84;
_ZN4sead14MathCalcCommonIfE8cAtanTblE = 0x00598F94;

/* sead::Vector2<float> */
_ZN4sead7Vector2IfEC1Ev = 0x0055FA64;
_ZN4sead7Vector2IfE2exE = 0x00603300;
_ZN4sead7Vector2IfE2eyE = 0x00603308;
_ZN4sead7Vector2IfE4onesE = 0x00603310;
_ZN4sead7Vector2IfE4zeroE = 0x00603318;

/* sead::Vector2<double> */
_ZN4sead7Vector2IdE2exE = 0x006C35C8;
_ZN4sead7Vector2IdE2eyE = 0x006C35D8;
_ZN4sead7Vector2IdE4onesE = 0x006C35E8;
_ZN4sead7Vector2IdE4zeroE = 0x006C35F8;

/* sead::Vector2<int> */
_ZN4sead7Vector2IiE2exE = 0x00603340;
_ZN4sead7Vector2IiE2eyE = 0x00603348;
_ZN4sead7Vector2IiE4onesE = 0x00603350;
_ZN4sead7Vector2IiE4zeroE = 0x00603358;

/* sead::Vector2<uint> */
_ZN4sead7Vector2IjE2exE = 0x00603320;
_ZN4sead7Vector2IjE2eyE = 0x00603328;
_ZN4sead7Vector2IjE4onesE = 0x00603330;
_ZN4sead7Vector2IjE4zeroE = 0x00603338;

/* sead::Vector3<float> */
_ZN4sead7Vector3IfEC1Ev = 0x0055FB14;
_ZN4sead7Vector3IfE2exE = 0x006C3680;
_ZN4sead7Vector3IfE2eyE = 0x006C368C;
_ZN4sead7Vector3IfE2ezE = 0x006C3698;
_ZN4sead7Vector3IfE4onesE = 0x006C36A4;
_ZN4sead7Vector3IfE4zeroE = 0x006C36B0;

/* sead::Vector3<double> */
_ZN4sead7Vector3IdE2exE = 0x006C3608;
_ZN4sead7Vector3IdE2eyE = 0x006C3620;
_ZN4sead7Vector3IdE2ezE = 0x006C3638;
_ZN4sead7Vector3IdE4onesE = 0x006C3650;
_ZN4sead7Vector3IdE4zeroE = 0x006C3668;

/* sead::Vector3<int> */
_ZN4sead7Vector3IiE2exE = 0x006C36F8;
_ZN4sead7Vector3IiE2eyE = 0x006C3704;
_ZN4sead7Vector3IiE2ezE = 0x006C3710;
_ZN4sead7Vector3IiE4onesE = 0x006C371C;
_ZN4sead7Vector3IiE4zeroE = 0x006C3728;

/* sead::Vector3<uint> */
_ZN4sead7Vector3IjE2exE = 0x006C36BC;
_ZN4sead7Vector3IjE2eyE = 0x006C36C8;
_ZN4sead7Vector3IjE2ezE = 0x006C36D4;
_ZN4sead7Vector3IjE4onesE = 0x006C36E0;
_ZN4sead7Vector3IjE4zeroE = 0x006C36EC;

/* sead::Vector4<float> */
_ZN4sead7Vector4IfE2ewE = 0x006C37F8;
_ZN4sead7Vector4IfE2exE = 0x006C3808;
_ZN4sead7Vector4IfE2eyE = 0x006C3818;
_ZN4sead7Vector4IfE2ezE = 0x006C3828;
_ZN4sead7Vector4IfE4onesE = 0x006C3838;
_ZN4sead7Vector4IfE4zeroE = 0x006C3848;

/* sead::Vector4<double> */
_ZN4sead7Vector4IdE2ewE = 0x006C3738;
_ZN4sead7Vector4IdE2exE = 0x006C3758;
_ZN4sead7Vector4IdE2eyE = 0x006C3778;
_ZN4sead7Vector4IdE2ezE = 0x006C3798;
_ZN4sead7Vector4IdE4onesE = 0x006C37B8;
_ZN4sead7Vector4IdE4zeroE = 0x006C37D8;

/* sead::Vector4<int> */
_ZN4sead7Vector4IfE2ewE = 0x006C38B8;
_ZN4sead7Vector4IfE2exE = 0x006C38C8;
_ZN4sead7Vector4IfE2eyE = 0x006C38D8;
_ZN4sead7Vector4IfE2ezE = 0x006C38E8;
_ZN4sead7Vector4IfE4onesE = 0x006C38F8;
_ZN4sead7Vector4IfE4zeroE = 0x006C3908;

/* sead::Vector4<uint> */
_ZN4sead7Vector4IfE2ewE = 0x006C3858;
_ZN4sead7Vector4IfE2exE = 0x006C3868;
_ZN4sead7Vector4IfE2eyE = 0x006C3878;
_ZN4sead7Vector4IfE2ezE = 0x006C3888;
_ZN4sead7Vector4IfE4onesE = 0x006C3898;
_ZN4sead7Vector4IfE4zeroE = 0x006C38A8;

/* CourseActorMgr */
_ZN14CourseActorMgr10searchByIdEi = 0x00496C0C;
_ZN14CourseActorMgr17searchByProfileIdEj = 0x004AD248;
_ZN14CourseActorMgr17searchByProfileIdEjP9ActorBase = 0x00496D50;
_ZN14CourseActorMgr16countByProfileIdEj = 0x00496E58;
_ZN14CourseActorMgr9sInstanceE = 0x005E2D18;
_ZN14CourseActorMgr14createInstanceEPN4sead4HeapE = 0x003FD554;
_ZN14CourseActorMgr14deleteInstanceEv = 0x003FD5E4;
_ZN14CourseActorMgr18SingletonDisposer_D1Ev = 0x003FD6B0;
_ZN14CourseActorMgr15sStaticDisposerE = 0x005E2D1C;
_ZTVN14CourseActorMgr18SingletonDisposer_E = 0x005C9CA8;

/* BgScrollMgr */
_ZTV11BgScrollMgr = 0x005A44E8;
_ZN11BgScrollMgr9sInstanceE = 0x005ECF58;
_ZN11BgScrollMgrC1Ev = 0x0021E010;
_ZN11BgScrollMgrD2Ev = 0x0021E1E4;
_ZN11BgScrollMgrD1Ev = 0x0021E1E0;
_ZN11BgScrollMgr23setAutoscrollSpeedAccelEff = 0x0021DCD4;
_ZN11BgScrollMgr14createInstanceEPN4sead4HeapE = 0x0021DA6C;
_ZN11BgScrollMgr14deleteInstanceEv = 0x0021DAD0;
_ZN11BgScrollMgr13initRailLimitEhhi = 0x0021DC70;

/* BgScrollMgr::SingletonDisposer_ */
_ZN11BgScrollMgr18SingletonDisposer_D1Ev = 0x0021DC84;
_ZN11BgScrollMgr18SingletonDisposer_15sStaticDisposerE = 0x005ECF5C;
_ZTVN11BgScrollMgr18SingletonDisposer_E = 0x005A44D8;

/* CourseData */
_ZN10CourseData9sInstanceE = 0x005E9AA8;
_ZN10CourseData7getFileEh = 0x001CECBC;
_ZN10CourseData4loadEv = 0x001CEB30;
_ZN10CourseData14createInstanceEPN4sead4HeapE = 0x001CEA80;
_ZN10CourseData14deleteInstanceEv = 0x001CEAF0;
_ZN10CourseData13getCourseNameEPN4sead19FixedSafeStringBaseIcLi8EEEhhh = 0x001CEBD8;

/* CourseData::SingletonDisposer_ */
_ZTVN10CourseData18SingletonDisposer_E = 0x0059F198;
_ZN10CourseData18SingletonDisposer_D1Ev = 0x001CEC88;
_ZN10CourseData18SingletonDisposer_15sStaticDisposerE = 0x005E9AAC;

/* Course */
_ZN6Course15getEntranceByIdEh = 0x004AAC2C;
_ZN6Course11getZoneByIdEhPN4sead9BoundBox2IfEE = 0x004AAD34;
_ZN6Course11getPathByIdEh = 0x004AADA4;
_ZN6Course15getLocationByIdEPN4sead9BoundBox2IfEEh = 0x004AAE1C;
_ZN6Course16getPathNodesByIdEh = 0x004AAEDC;

/* StageInfo */
_ZN9StageInfo8instanceE = 0x005E72B0;


/* TilesetGfxMgr */
_ZN13TilesetGfxMgr8instanceE = 0x005E98B0;


/* TileMgr */
_ZN7TileMgr8instanceE = 0x005E97FC;
_ZN7TileMgr11setTileTypeEttj = 0x00349538;


/* TileLayer */
_ZN9TileLayer6Layer1E = 0x005E9804;
_ZN9TileLayer10getTilePtrEjjPj = 0x004A7C70;


/* SaveMgr */
_ZN7SaveMgr8instanceE = 0x005ED3AC;
_ZN7SaveMgr8loadFileEhb = 0x004ABF38;
_ZN7SaveMgr9clearFileEh = 0x003F7C50;
_ZN7SaveMgr8copyFileEhh = 0x003FA864;
_ZN7SaveMgr8saveFileEhb = 0x003F8BB0;
_ZN7SaveMgr13setLastFileIdEh = 0x003F8B3C;
_ZN7SaveMgr5writeEv = 0x003FAA58;
_ZN7SaveMgr11getSaveDataEv = 0x004ABBF0;


/* GameState */
_ZN9GameState8instanceE = 0x005ED308;
_ZN9GameState17isRainbowUnlockedEj = 0x00497C98;

/* CollectionCoinStatesHolder */
_ZN26CollectionCoinStatesHolder11getForLevelEjj = 0x004A23C0;
_ZN26CollectionCoinStatesHolder11getForLevelEjjj = 0x004A2414;


/* GameState2 */
_ZN10GameState28instanceE = 0x005E7158;


_Z16getToadHouseTypejj = 0x002D2778;


/* RNG */
_ZN3RNG8instanceE = 0x005ED360;
_ZN3RNG7randF32Ev = 0x003DDFE0;
_ZN3RNG7randF32Ef = 0x003DDFAC;
_ZN3RNG7randF32Eff = 0x003DDF04;
_ZN3RNG7randU32Ej = 0x003DE004;
_ZN3RNG7randS32Eii = 0x003DDF40;
_ZN3RNG8randBoolEv = 0x003DE01C;


/* FlagMgr */
_ZN7FlagMgr8instanceE = 0x005E9AF8;
_ZN7FlagMgr3setEhjbbbj = 0x002A8080;

/* PersistentDataMgr */
_ZN17PersistentDataMgr8instanceE = 0x005E7170;
_ZN17PersistentDataMgr3getEff = 0x004A52D0;
_ZN17PersistentDataMgr3setEfft = 0x00345A6C;

/* BgmAnimMgr */
_ZN10BgmAnimMgr8instanceE = 0x005E75F0;
_ZN10BgmAnimMgr8getStateEv = 0x004ADB44;

/* DemoMgr */
_ZN7DemoMgr8instanceE = 0x005EA1C8;
_ZN7DemoMgr6freezeEv = 0x002A30F0;
_ZN7DemoMgr16freezeIfOnGroundEv = 0x002A3248;
_ZN7DemoMgr8unfreezeEv = 0x002A2EB0;
_ZN7DemoMgr12setDemoStateEj = 0x002A2B2C;

/* PointGetTopMgr */
_ZN14PointGetTopMgr8instanceE = 0x005E7280;
_ZN14PointGetTopMgr4showERKN4sead7Vector3IfEEjjb = 0x002A7AE4;

/* SoundRelated */
_ZN12SoundRelated8instanceE = 0x005E30B0;
_ZN12SoundRelated13playGlobalSfxEj = 0x00139B0C;
_ZN12SoundRelated14getSfxNameByIdEj = 0x001390BC;
_ZN12SoundRelated15SetPlayerVolumeEjf = 0x00195F98;
_ZN12SoundRelated17UnpauseSfxPlayersEi = 0x00138D44;

/* SndSceneMgr */
_ZN11SndSceneMgr8instanceE = 0x005E3450;
_ZN11SndSceneMgr7stopAllEv = 0x0028B3E0;
_ZN11SndSceneMgr9stopMusicEv = 0x0028B358;
_ZN11SndSceneMgr13playBossMusicEv = 0x0028BEC8;
_ZN11SndSceneMgr21playBossBeatenFanfareEv = 0x000028C2EC;
_ZN11SndSceneMgr17getPlayingMusicIdEv = 0x0028CEBC;
_ZN11SndSceneMgr21getCurrentZoneMusicIdE = 0x0028B14C;

/* MusicTrackMgr */
_ZN13MusicTrackMgr8instanceE = 0x005E3058;
_ZN13MusicTrackMgr14setTrackVolumeEjfj = 0x00211B8C;

_ZN13MusicTrackMgr12playSoundUnkEjj = 0x00213160;

/* ResourceMgr */
_ZN11ResourceMgr8instanceE = 0x005E74B8;
_ZN11ResourceMgr11getResourceERKN4sead14SafeStringBaseIcEE = 0x0049C77C;
_ZN11ResourceMgr8loadFileERKN4sead14SafeStringBaseIcEEjjjb = 0x0023D6F8;
_ZN11ResourceMgr9loadFile2ERKN4sead14SafeStringBaseIcEEjjjbS4_ = 0x0023D0E0;
_ZN11ResourceMgr10unloadFileERKN4sead14SafeStringBaseIcEE = 0x0023D548;

/* WorldmapResourceMgr */
_ZN19WorldmapResourceMgr8instanceE = 0x005E5CD8;
_ZN19WorldmapResourceMgr11getResourceERKN4sead14SafeStringBaseIcEE = 0x004A0D64;


/* TransformNodeWrapper */
_ZTV20TransformNodeWrapper = 0x0059E1EC;
_ZN20TransformNodeWrapperC1Ev = 0x001B2248;
_ZN20TransformNodeWrapperC2Ev = 0x001B2248;
_ZN20TransformNodeWrapperD1Ev = 0x001B2260;
_ZN20TransformNodeWrapper13setDrawMatrixEP5Mtx34 = 0x001B2224;
_ZN20TransformNodeWrapper6acceptEj = 0x001B2194;
_ZN20TransformNodeWrapper7cleanupEv = 0x001B21D4;
_ZN20TransformNodeWrapper15updateTransformEPN2nw3gfx18WorldMatrixUpdaterEPNS1_12SceneContextE = 0x001B221C;
_ZNK20TransformNodeWrapper12getTransformEv = 0x00495588;

/* ModelWrapper */
_ZTV12ModelWrapper = 0x0059E1D0;
_ZN12ModelWrapperD1Ev = 0x001B1D84;
_ZN12ModelWrapperC1Ev = 0x001B1D6C;
_ZN12ModelWrapper7cleanupEv = 0x001B21B0;
_ZN12ModelWrapper15updateTransformEPN2nw3gfx18WorldMatrixUpdaterEPNS1_12SceneContextE = 0x001B3718;
_ZN12ModelWrapper12createObjectEPN2nw3gfx3res18ResSceneObjectDataEPNS0_2os10IAllocatorEPNS6_ENS1_5Model12BufferOptionEbi = 0x001B4858;
_ZN12ModelWrapper12createObjectEPN2nw3gfx5ModelEPNS0_2os10IAllocatorE = 0x00317C70;
_ZN12ModelWrapper8getModelEv = 0x001B49B8;

/* SkeletalModelWrapper */
_ZTV20SkeletalModelWrapper = 0x005D0048;
_ZN20SkeletalModelWrapper27setBoneLocalTransformMatrixEiRK5Mtx34 = 0x001B1658;
_ZN20SkeletalModelWrapper26setBoneLocalTransformScaleEiRKN4sead7Vector3IfEE = 0x001B16E0;
_ZN20SkeletalModelWrapper27getBoneLocalTransformMatrixER5Mtx34i = 0x0049539C;
_ZN20SkeletalModelWrapper26getBoneLocalTransformScaleERN4sead7Vector3IfEEi = 0x0049549C;
_ZN20SkeletalModelWrapper21getBoneLocalTransformEv = 0x001B1B20;
_ZN20SkeletalModelWrapper21getBoneWorldTransformEi = 0x00495524;
_ZN20SkeletalModelWrapper10getBoneIdxEPKc = 0x004952C0;
_ZN20SkeletalModelWrapper12getBoneCountEv = 0x00495248;
_ZN20SkeletalModelWrapper13evaluateAnimsEv = 0x001B4334;
_ZN20SkeletalModelWrapper11updateAnimsEv = 0x001B436C;
_ZN20SkeletalModelWrapper11getBoneNameEi = 0x00495190;
_ZN20SkeletalModelWrapper15getBonePositionERN4sead7Vector3IfEEi = 0x00495024;
_ZN20SkeletalModelWrapper27getBoneWorldTransformMatrixER5Mtx34i = 0x00494E90;
_ZNK20SkeletalModelWrapper19getSkeletalModelEv = 0x00495450;
_ZN20SkeletalModelWrapper19getSkeletalModelEv = 0x001B17B4;
_ZN20SkeletalModelWrapper20getSkeletalAnimGroupEv = 0x001B1AD4;
_ZN20SkeletalModelWrapper20getMaterialAnimGroupEv = 0x001B4540;
_ZN20SkeletalModelWrapper22getVisibilityAnimGroupEv = 0x001B4688;

/* Model */
_ZTV5Model = 0x005A8698;
_ZN5ModelC1Ev = 0x0024B5FC;
_ZN5ModelD0Ev = 0x0024B620;
_ZN5ModelD2Ev = 0x0024B640;
_ZN5Model6createEP8ResourceRKN4sead14SafeStringBaseIcEEP9AllocatorN2nw3gfx5Model12BufferOptionE = 0x0024B4B4;
_ZN5Model6createEPN2nw3gfx3res14ResSceneObjectEPNS0_2os10IAllocatorENS1_5Model12BufferOptionE = 0x0024B46C;
_ZN5Model7cleanupEv = 0x0024B5B4;
_ZN5Model6updateEv = 0x0024B5DC;
_ZN5Model13getGfxWrapperEv = 0x0024B5D4;

/* AnimModelBase */
_ZTV13AnimModelBase = 0x005AC908;
_ZN13AnimModelBaseC1EjPP8AnimBasejS2_jS2_ = 0x0028A880;
_ZN13AnimModelBaseC2EjPP8AnimBasejS2_jS2_ = 0x0028A880;
_ZN13AnimModelBase15updateAnimationEv = 0x0028A814;
_ZN13AnimModelBaseD0Ev = 0x0028A930;
_ZN13AnimModelBase7cleanupEv = 0x0028A620;
_ZN13AnimModelBase6updateEv = 0x0028A838;

_ZN13AnimModelBase5setupEPN2nw3gfx3res8ResModelEPNS0_4anim3res7ResAnimEP13HeapAllocatorP8ResourceSC_NS1_5Model12BufferOptionE = 0x0028A140;
_ZN13AnimModelBase15setSkeletalAnimEP8ResourceRKN4sead14SafeStringBaseIcEE = 0x0028A744;
_ZN13AnimModelBase15setSkeletalAnimEjP8ResourceRKN4sead14SafeStringBaseIcEE = 0x001B1B60;
_ZN13AnimModelBase15setMaterialAnimEjP8ResourceRKN4sead14SafeStringBaseIcEE = 0x001B454C;
_ZN13AnimModelBase17setVisibilityAnimEjP8ResourceRKN4sead14SafeStringBaseIcEE = 0x001B4724;

/* AnimBase */
_ZTV8AnimBase = 0x0059E344;
_ZN8AnimBase13animEvaluatorEv = 0x001B549C;
_ZN8AnimBase4vf10EN2nw4anim3res7ResAnimE = 0x001B54A4;
_ZN8AnimBase13setPlayPolicyE10PlayPolicy = 0x001B271C;
_ZN8AnimBase4unkAEN2nw4anim3res7ResAnimE = 0x001B2770;
_ZN8AnimBase12setFrameStepEf = 0x001B281C;
_ZN8AnimBase8setFrameEf = 0x001B284C;
_ZN8AnimBase11updateFrameEv = 0x001B548C;
_ZN8AnimBase7cleanupEv = 0x0;

_ZN8AnimBase9isAtFrameEf = 0x004955AC;
_ZN8AnimBase11getEndFrameEv = 0x004956EC;
_ZN8AnimBase13getStartFrameEv = 0x00495704;
_ZN8AnimBase6isDoneEv = 0x00495728;
_ZN8AnimBase12getFrameStepEv = 0x004957E8;
_ZN8AnimBase15getCurrentFrameEv = 0x0049580C;
_ZNK8AnimBase13animEvaluatorEv = 0x00495CE4;

/* ActorCollisionCheck */
_ZN19ActorCollisionCheckC1Ev = 0x004367DC;
_ZN19ActorCollisionCheckC2Ev = 0x004367DC;
_ZN19ActorCollisionCheckD1Ev = 0x00436864;
_ZN19ActorCollisionCheckD2Ev = 0x00436864;
_ZN19ActorCollisionCheck3setEP9ActorBaseRKNS_4InfoE = 0x004366C4;
_ZN19ActorCollisionCheck3setEP9ActorBaseRKNS_4InfoERKN4sead7BitFlagIhEE = 0x004366E8;
_ZN19ActorCollisionCheck3setEP9ActorBaseRKNS_4InfoERKN4sead7BitFlagIhEEh = 0x00436710;

/* ActorCollisionCheckMgr */
_ZN22ActorCollisionCheckMgr8instanceE = 0x005E54E8;
_ZN22ActorCollisionCheckMgr9addToListEP19ActorCollisionCheck = 0x00255018;
_ZN22ActorCollisionCheckMgr14removeFromListEP19ActorCollisionCheck = 0x00255050;


/* BasicBgCollisionCheck */
_ZN21BasicBgCollisionCheckC1Ev = 0x0044A37C;


/* UnkColliderClass */
_ZN17UnkCollisionClassC1Ev = 0x004368D8;
_ZN17UnkCollisionClass5resetEv = 0x00436888;
_ZN17UnkCollisionClass4copyEPS0_ = 0x00436930;


/* BasicRideLine */

_ZN13BasicRideLineC1Ev = 0x00421394;


/* BgCollision */
_ZTV11BgCollision = 0x005D005C;

/* virtual functions */
_ZN11BgCollision3vf0Ev = 0x00000000;
_ZN11BgCollisionD1Ev = 0x0044CFD0;
_ZN11BgCollisionD2Ev = 0x0044CFD0;
_ZN11BgCollision3vfCEPjj = 0x004AF6D4;
_ZN11BgCollision4vf10EPjj = 0x00000000;
_ZN11BgCollision4vf30Ev = 0x0044BC0C;

/* functions */
_ZN11BgCollisionC1Ev = 0x0044CE90;
_ZN11BgCollision7setTypeEj = 0x0044AB4C;
_ZN11BgCollision9setHitboxEj = 0x0044A530;
_ZN11BgCollision14setSurfaceTypeEj = 0x0044C7F4;
_ZN11BgCollision12setBehaviourEj = 0x0044C85C;
_ZN11BgCollision15setSubBehaviourEj = 0x0044AA88;
_ZN11BgCollision11getPositionEv = 0x004AF6B8;


/* LoopRideLineBgCollision */
_ZTV23LoopRideLineBgCollision = 0x005B7ED8;

/* virtual functions */
_ZN23LoopRideLineBgCollisionD2Ev = 0x00324964;
_ZN23LoopRideLineBgCollisionD0Ev = 0x00324950;
_ZN23LoopRideLineBgCollision4vf14Ev = 0x00321D44;
_ZN23LoopRideLineBgCollision7executeEv = 0x003241E8;
_ZN23LoopRideLineBgCollision4vf1CEPjjS0_PN4sead7Vector2IfEEh = 0x003243D0;
_ZN23LoopRideLineBgCollision4vf20EjPjjj = 0x00321D50;
_ZN23LoopRideLineBgCollision4vf24EjPN4sead7Vector2IfEE = 0x004A3BAC;
_ZN23LoopRideLineBgCollision4vf28Ev = 0x004A3F64;
_ZN23LoopRideLineBgCollision4vf2CEv = 0x00000000;
_ZN23LoopRideLineBgCollision4vf30Ev = 0x003229C4;
_ZN23LoopRideLineBgCollision4vf34Ev = 0x00322114;
_ZN23LoopRideLineBgCollision4vf38Ev = 0x00322C48;

/* functions */
_ZN23LoopRideLineBgCollisionC1EjPN4sead7Vector2IfEEP13BasicRideLineS5_ = 0x003248CC;
_ZN23LoopRideLineBgCollisionC2EjPN4sead7Vector2IfEEP13BasicRideLineS5_ = 0x003248CC;
_ZN23LoopRideLineBgCollision5setupEP9ActorBaseRKNS_4InfoE = 0x0032202C;


/* RectCollider */
_ZTV12RectCollider = 0x005B3244;

/* virtual functions */
_ZN12RectColliderD1Ev = 0x00324960;
_ZN12RectColliderD2Ev = 0x00324960;
_ZN12RectColliderD0Ev = 0x002F470C;

/* functions */
_ZN12RectColliderC1Ev = 0x002F463C;
_ZN12RectCollider5setupEP9ActorBaseRKNS_4InfoE = 0x002F4528;
_ZN12RectCollider9setBoundsERKN4sead7Vector2IfEES4_ = 0x002F45DC;


/* SolidOnTopColliderBase */
_ZTV22SolidOnTopColliderBase = 0x005AE054;

/* virtual functions */
_ZN22SolidOnTopColliderBaseD2Ev = 0x0044CFCC;
_ZN22SolidOnTopColliderBase4vf14Ev = 0x0029C96C;
_ZN22SolidOnTopColliderBase7executeEv = 0x0029D088;
_ZN22SolidOnTopColliderBase4vf1CEPjjS0_PN4sead7Vector2IfEEh = 0x0029D29C;
_ZN22SolidOnTopColliderBase4vf20EjPjjj = 0x0029C978;
_ZN22SolidOnTopColliderBase4vf24EjPN4sead7Vector2IfEE = 0x0049F970;
_ZN22SolidOnTopColliderBase4vf28Ev = 0x0049F978;
_ZN22SolidOnTopColliderBase4vf2CEv = 0x00000000;
_ZN22SolidOnTopColliderBase4vf30Ev = 0x0029D01C;
_ZN22SolidOnTopColliderBase4vf34Ev = 0x0029CE88;
_ZN22SolidOnTopColliderBase4vf38Ev = 0x0029D040;

/* functions */
_ZN22SolidOnTopColliderBaseC1EjPN4sead7Vector2IfEEP13BasicRideLineS5_ = 0x0029D5E4;
_ZN22SolidOnTopColliderBaseC2EjPN4sead7Vector2IfEEP13BasicRideLineS5_ = 0x0029D5E4;
_ZN22SolidOnTopColliderBase5setupEP9ActorBaseRKNS_4InfoE = 0x0029CC84;


/* ActorEllipseBgCollision */
_ZTV23ActorEllipseBgCollision = 0x005A5018;

/* virtual functions */
_ZN23ActorEllipseBgCollision3vfCEPjj = 0x0049B858;
_ZN23ActorEllipseBgCollision4vf10EPjj = 0x0049BC00;
_ZN23ActorEllipseBgCollision4vf14Ev = 0x002228D4;
_ZN23ActorEllipseBgCollision7executeEv = 0x00260CA4;
_ZN23ActorEllipseBgCollision4vf1CEPjjS0_PN4sead7Vector2IfEEh = 0x002231CC;
_ZN23ActorEllipseBgCollision4vf20EjPjjj = 0x002228E0;
_ZN23ActorEllipseBgCollision4vf24EjPN4sead7Vector2IfEE = 0x0049BAC8;
_ZN23ActorEllipseBgCollision4vf28Ev = 0x0049BB80;
_ZN23ActorEllipseBgCollision4vf2CEv = 0x00000000;
_ZN23ActorEllipseBgCollision4vf30Ev = 0x00222C94;
_ZN23ActorEllipseBgCollision4vf34Ev = 0x00222B74;
_ZN23ActorEllipseBgCollision4vf38Ev = 0x00222CCC;

/* functions */
_ZN23ActorEllipseBgCollision5setupEP9ActorBaseRKNS_4InfoE = 0x00222AC0;
_ZN23ActorEllipseBgCollisionC1Ev = 0x0022349C;


/* ActorBgCollisionMgr */
_ZN19ActorBgCollisionMgr8instanceE = 0x005E3CE0;
_ZN19ActorBgCollisionMgr9addToListEP11BgCollision = 0x002E4C94;
_ZN19ActorBgCollisionMgr14removeFromListEP11BgCollision = 0x002E519C;


/* ActorBgHitCheckCallback */

/* virtual functions */
_ZN23ActorBgHitCheckCallback3hitERK26BgCollisionCheckResultArea = 0x004A5980;
_ZN23ActorBgHitCheckCallback3hitERK27BgCollisionCheckResultPoint = 0x004A59F4;

/* ActorBgCollisionCheck */
_ZTV21ActorBgCollisionCheck = 0x005A44A8;
_ZN21ActorBgCollisionCheckC1Ev = 0x0021D0C4;
_ZN21ActorBgCollisionCheckC2Ev = 0x0021D0C4;
_ZN21ActorBgCollisionCheckD1Ev = 0x0021D394;
_ZN21ActorBgCollisionCheckD2Ev = 0x0021D394;
_ZN21ActorBgCollisionCheck4vf08Ev = 0x00000000;
_ZN21ActorBgCollisionCheck7processEv = 0x0021C9E0;
_ZN21ActorBgCollisionCheck7disposeEv = 0x0021CEE4;
_ZN21ActorBgCollisionCheck6updateEv = 0x002190EC;
_ZN21ActorBgCollisionCheck4vf18Ev = 0x00100ECF;
_ZN21ActorBgCollisionCheck4vf1CEv = 0x00100ECF;
_ZN21ActorBgCollisionCheck4vf20Ev = 0x00100ECF;
_ZN21ActorBgCollisionCheck4vf24Ev = 0x0021C6E8;
_ZN21ActorBgCollisionCheck4initEP9ActorBasePKNS_6SensorES4_S4_ = 0x002182E8;
_ZN21ActorBgCollisionCheck10initSensorEPKNS_6SensorEj = 0x002197C0;
_ZN21ActorBgCollisionCheck22checkForSuitableGroundERKN4sead7Vector3IfEEfff = 0x0021CFF4;
_ZN21ActorBgCollisionCheck13getSlopeAngleEh = 0x0049B0E4;
_ZN21ActorBgCollisionCheck13getLiquidInfoEPfRKN4sead7Vector3IfEE = 0x002182A4;

/* ActorBgCollisionObjCheck */
_ZTV24ActorBgCollisionObjCheck = 0x005B8AE0;
_ZN24ActorBgCollisionObjCheckC1Ev = 0x0032D600;
_ZN24ActorBgCollisionObjCheckC2Ev = 0x0032D600;
_ZN24ActorBgCollisionObjCheck4vf18Ev = 0x004A439C;
_ZN24ActorBgCollisionObjCheck4vf1CEv = 0x004A4394;
_ZN24ActorBgCollisionObjCheck11getPlayerIdEv = 0x004A438C;


/* PairChild */
_ZN9PairChildC1Ev = 0x002A0924;
_ZN9PairChildC2Ev = 0x002A0924;
_ZN9PairChild4linkERKN4sead7Vector3IfEEjh = 0x0029FE30;
_ZN9PairChild7executeEv = 0x002A0914;
_ZN9PairChild22getMaskForMovementTypeEj = 0x002A015C;


/* LineFollower */
_ZN12LineFollowerC1Ev = 0x0023C508;
_ZN12LineFollowerC2Ev = 0x0023C508;
_ZN12LineFollower4initERKN4sead7Vector2IfEEfhhb = 0x002379A4;
_ZN12LineFollower9initStateEb = 0x00237F20;


/* LiftRenderer */
_ZN12LiftRenderer4initEv = 0x0033CD50;
_ZN12LiftRenderer7cleanupEv = 0x0033CCB4;
_ZN12LiftRenderer7executeERKN4sead7Vector3IfEEf = 0x0033CE8C;
_ZN12LiftRenderer4drawEv = 0x0033CD0C;


/* PlayerMgr */
_ZTV9PlayerMgr = 0x005D0374;
_ZN9PlayerMgrC1Ev = 0x0044E58C;
_ZN9PlayerMgrD1Ev = 0x0044E640;
_ZN9PlayerMgrD2Ev = 0x0044E6B0;
_ZN9PlayerMgr9sInstanceE = 0x005EB530;
_ZN9PlayerMgr12gotoEntranceEhh = 0x0044E000;
_ZN9PlayerMgr7executeEv = 0x0044E2D0;
_ZN9PlayerMgr12removePlayerEi = 0x0044DECC;
_ZN9PlayerMgr5resetEv = 0x0044E43C;
_ZN9PlayerMgr13createPlayersEP15PlayerStateData = 0x0044E47C;
_ZN9PlayerMgr11doCoopQuakeEv = 0x0044DF0C;
_ZN9PlayerMgr7doQuakeENS_9QuakeTypeEi = 0x0044DD48;
_ZN9PlayerMgr9addPlayerEiP10PlayerBase = 0x0044DE90;
_ZN9PlayerMgr9getPlayerEi = 0x0044DE7C;
_ZNK9PlayerMgr9getPlayerEi = 0x0044DD34;
_ZN9PlayerMgr15enableStarMusicEv = 0x0044DC44;
_ZN9PlayerMgr16disableStarMusicEv = 0x0044DB7C;
_ZN9PlayerMgr15enableMegaMusicEv = 0x0044DBF4;
_ZN9PlayerMgr16disableMegaMusicEv = 0x0044DB04;
_ZN9PlayerMgr12doPlayerDownEi = 0x0044DC08;
_ZN9PlayerMgr10numPlayersEv = 0x004AFC04;
_ZN9PlayerMgr15numPlayersAliveEv = 0x004AFC60;
_ZN9PlayerMgr10getUnkFlagEv = 0x004AFCD8;

/* PlayerMgr::SingletonDisposer_ */
_ZN9PlayerMgr14createInstanceEPN4sead4HeapE = 0x0044DC84;
_ZN9PlayerMgr14deleteInstanceEv = 0x0044DCE8;
_ZN9PlayerMgr18SingletonDisposer_15sStaticDisposerE = 0x005EB534;
_ZTVN9PlayerMgr18SingletonDisposer_E = 0x005D0364;
_ZN9PlayerMgr18SingletonDisposer_D1Ev = 0x0044DE2C;

/* PlayerLookTarget */
_ZN16PlayerLookTargetC1Ei = 0x0028A940;
_ZN16PlayerLookTargetC2Ei = 0x0028A940;
_ZN16PlayerLookTargetD1Ev = 0x0028A988;
_ZN16PlayerLookTargetD2Ev = 0x0028A988;

/* PlayerLookTargetMgr */
_ZN19PlayerLookTargetMgr8instanceE = 0x005E2EC0;
_ZN19PlayerLookTargetMgr9addToListEP16PlayerLookTarget = 0x002522F8;
_ZN19PlayerLookTargetMgr14removeFromListEP16PlayerLookTarget = 0x00252320;

/* StateID */
_ZTV7StateID = 0x0059ABE4;
_ZN7StateID5cNullE = 0x005ED2A8;
_ZN7StateID11sNumberMemoE = 0x00603360;
_ZN7StateID6numberEv = 0x004B3514;

/* StateMethod */
_ZN11StateMethodC1ER13IStateFactoryRK7StateID = 0x00138800;
_ZN11StateMethod17changeStateMethodERK7StateID = 0x00138720;
_ZN11StateMethod24executeStateLocalMethod_Ev = 0x001387B0;
_ZNK11StateMethod10getStateIDEv = 0x004855D0;

/* ProcMgr */
_ZN7ProcMgr11getInstanceEv = 0x001C550C;
_ZN7ProcMgr17getFirstProcChildEP5fBase = 0x00496A7C;
_ZN7ProcMgr18getNextProcSiblingEP5fBase = 0x00496B44;
_ZN7ProcMgr18getProcByProfileIdEsP5fBase = 0x00496D7C;

/* ProcMgr::TreeNode */
_ZN7ProcMgr8TreeNode7getNextEv = 0x00496F38;


/* fBase */

/* ctor */
_ZN5fBaseC1Ev = 0x001C7060;
_ZN5fBaseC2Ev = 0x001C7060;

/* dtor */
_ZN5fBaseD1Ev = 0x001C70AC;
_ZN5fBaseD2Ev = 0x001C70AC;

/* vtable */
_ZTV5fBase = 0x0059E4DC;

/* virtual functions */
_ZN5fBase12beforeCreateEv = 0x001C7050;
_ZN5fBase8onCreateEv = 0x001C6FDC;
_ZN5fBase11afterCreateEi = 0x001C655C;
_ZN5fBase12beforeDeleteEv = 0x001C7058;
_ZN5fBase8onDeleteEv = 0x001C7010;
_ZN5fBase11afterDeleteEi = 0x001C6564;
_ZN5fBase13beforeExecuteEv = 0x001C6568;
_ZN5fBase9onExecuteEv = 0x001C6FE4;
_ZN5fBase12afterExecuteEi = 0x001C665C;
_ZN5fBase10beforeDrawEv = 0x001C6FEC;
_ZN5fBase6onDrawEv = 0x001C6FD4;
_ZN5fBase9afterDrawEi = 0x001C7018;
_ZN5fBase7onEraseEv = 0x001C6658;

/* functions */
_ZN5fBase5eraseEv = 0x001C5B8C;
_ZN5fBase9getParentEv = 0x00496B9C;

/* static members */
_ZN5fBase6searchEji = 0x00496C0C;


/* dBase */

/* ctor */
_ZN5dBaseC1Ev = 0x0047F00C;
_ZN5dBaseC2Ev = 0x0047F00C;

/* dtor */
_ZN5dBaseD1Ev = 0x0047F028;
_ZN5dBaseD2Ev = 0x0047F028;

/* vtable */
_ZTV5dBase = 0x0059A87C;

/* virtual functions */
_ZN5dBase12beforeCreateEv = 0x0047EFE4;
_ZN5dBase11afterCreateEi = 0x0047EF78;
_ZN5dBase12beforeDeleteEv = 0x0047EFF8;
_ZN5dBase11afterDeleteEi = 0x0047EF80;
_ZN5dBase13beforeExecuteEv = 0x0047EF84;
_ZN5dBase12afterExecuteEi = 0x0047EFCC;
_ZN5dBase10beforeDrawEv = 0x0047EFD0;
_ZN5dBase9afterDrawEi = 0x00457874;
_ZN5dBase4vf3CEv = 0x00000000;


/* ActorBase */

/* ctor */
_ZN9ActorBaseC1Ev = 0x004318D8;
_ZN9ActorBaseC2Ev = 0x004318D8;

/* dtor */
_ZN9ActorBaseD1Ev = 0x00431A24;
_ZN9ActorBaseD2Ev = 0x00431A24;

/* vtable */
_ZTV9ActorBase = 0x005CD980;

/* virtual functions */
_ZN9ActorBase11afterCreateEi = 0x00430928;
_ZN9ActorBase11afterDeleteEi = 0x00430990;
_ZN9ActorBase13beforeExecuteEv = 0x004309D0;
_ZN9ActorBase12afterExecuteEi = 0x00430CD4;
_ZN9ActorBase10beforeDrawEv = 0x00431748;

_ZNK9ActorBase18getRuntimeTypeInfoEv = 0x004AE360;
_ZN9ActorBase19getBgCollisionCheckEv = 0x004318A8;
_ZN9ActorBase20getBgCollisionCheck2Ev = 0x004AE1E4;
_ZN9ActorBase11setPlayerIdEa = 0x00430CD8;
_ZN9ActorBase20removeCollisionCheckEv = 0x004318B0;
_ZN9ActorBase17addCollisionCheckEv = 0x004318C4;
_ZN9ActorBase4vf58Ev = 0x00430D20;
_ZN9ActorBase4vf5CEv = 0x004AE3AC;
_ZN9ActorBase4vf60Ev = 0x004311FC;
_ZN9ActorBase4vf64Ev = 0x00430E00;
_ZN9ActorBase4vf68Ev = 0x00430CE0;
_ZN9ActorBase15levelClearDeathEv = 0x00431434;
_ZN9ActorBase11waterSplashERKN4sead7Vector3IfEEf = 0x00430F50;
_ZN9ActorBase10lavaSplashERKN4sead7Vector3IfEEf = 0x0043101C;
_ZN9ActorBase12poisonSplashERKN4sead7Vector3IfEEf = 0x004310D8;
_ZN9ActorBase4vf7CEv = 0x004AE3B4;
_ZNK9ActorBase8inBoundsERKN4sead9BoundBox2IfEE = 0x004AE3BC;
_ZN9ActorBase4vf84Ev = 0x00431638;
_ZN9ActorBase16createSoundActorEv = 0x00430EF0;
_ZN9ActorBase4vf8CEv = 0x00000000;
_ZN9ActorBase10startSoundEj = 0x00431828;
_ZN9ActorBase10startSoundEjj = 0x00431864;
_ZN9ActorBase10startSoundEPKc = 0x004317A8;
_ZN9ActorBase10startSoundEPKcj = 0x004317E4;
_ZN9ActorBase9holdSoundEj = 0x004316C4;
_ZN9ActorBase9holdSoundEjj = 0x00431700;
_ZN9ActorBase9holdSoundEPKc = 0x00431688;
_ZN9ActorBase4vfACEjhh = 0x00430B0C;
_ZN9ActorBase4vfB0Ejjj = 0x00430B58;
_ZN9ActorBase4vfB4Ejj = 0x00430E98;
_ZN9ActorBase4vfB8Ejjj = 0x0043163C;
_ZN9ActorBase9playSoundEjRKN4sead7Vector2IfEEb = 0x00214740;
_ZN9ActorBase4vfC0Ej = 0x004310A4;
_ZN9ActorBase4vfC4Ej = 0x00430F14;
_ZN9ActorBase19setupFromCreateInfoEPNS_10CreateInfoE = 0x004314D8;
_ZN9ActorBase4vfCCEv = 0x00430CD0;
_ZN9ActorBase11isOutOfViewEv = 0x00431200;
_ZN9ActorBase12powActivatedEv = 0x00430E04;
_ZN9ActorBase16spawnDeathEffectERKN4sead7Vector3IfEENS_20SpawnDeathEffectTypeES4_ = 0x004AE1EC;

/* functions */
_ZN9ActorBase9fetchZoneEv = 0x00430AF4;
_ZN9ActorBase14assignLocationEh = 0x004311A4;
_ZN9ActorBase9cullCheckEj = 0x004312B4;
_ZN9ActorBase18directionToPlayerHERKN4sead7Vector3IfEE = 0x004AE234;
_ZN9ActorBase18directionToPlayerVERKN4sead7Vector3IfEE = 0x004AE2D8;
_ZN9ActorBase19closestPlayerOffsetERN4sead7Vector3IfEE = 0x004AE324;
_ZN9ActorBase18moveToTargetYSpeedEff = 0x00430E50;
_ZN9ActorBase15incrementYSpeedEff = 0x00430C54;
_ZN9ActorBase18applyAccelerationHEv = 0x00430BB8;
_ZN9ActorBase7despawnEb = 0x00430CEC;

/* static functions */
_ZN9ActorBase6createEPNS_10CreateInfoE = 0x00430C78;

_ZGVZN9ActorBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603DF8;
_ZZN9ActorBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603DFC;

_ZTVN4sead15RuntimeTypeInfo6DeriveI5ActorEE = 0x005D1F6C;
_ZNK4sead15RuntimeTypeInfo6DeriveI5ActorE9isDerivedEPKNS0_9InterfaceE = 0x00568B08;


/* ActorCollision */

/* ctor */
_ZN14ActorCollisionC1Ev = 0x002E27A4;
_ZN14ActorCollisionC2Ev = 0x002E27A4;

/* vtable */
_ZTV14ActorCollision = 0x005B16C0;

/* virtual functions */
_ZN14ActorCollision11afterCreateEi = 0x00430908;
_ZN14ActorCollision8onDeleteEv = 0x001C6FF4;
_ZN14ActorCollision13beforeExecuteEv = 0x002E1F28;
_ZN14ActorCollision12afterExecuteEi = 0x002E20AC;

_ZNK14ActorCollision18getRuntimeTypeInfoEv = 0x004A1830;
_ZN14ActorCollision19getBgCollisionCheckEv = 0x002E2628;
_ZN14ActorCollision20getBgCollisionCheck2Ev = 0x004A1828;

_ZN14ActorCollision4vfD8Ev = 0x00000000;
_ZN14ActorCollision4vfDCEv = 0x00000000;
_ZN14ActorCollision4vfE0Ev = 0x00000000;
_ZN14ActorCollision4vfE4Ev = 0x00000000;
_ZN14ActorCollision4vfE8Ev = 0x00000000;
_ZN14ActorCollision4vfECEv = 0x00000000;
_ZN14ActorCollision4vfF0Ev = 0x00000000;
_ZN14ActorCollision4vfF4Ev = 0x00000000;

_ZN14ActorCollision4vfF8Ev = 0x004A1820;
_ZN14ActorCollision4vfFCEj = 0x002E2044;
_ZN14ActorCollision15onCollisionLavaEP9ActorBase = 0x002E23EC;
_ZN14ActorCollision5vf104Ev = 0x002E2448;
_ZN14ActorCollision5vf108Ev = 0x002E23D8;

/* functions */
_ZN14ActorCollision18applyYAccelerationEv = 0x00430C0C;
_ZN14ActorCollision15processMovementEv = 0x002E2648;
_ZN14ActorCollision20collisionMgrRelated2Ev = 0x002E25D0;
_ZN14ActorCollision21applyFallAccelerationEv = 0x00430E08;

_ZGVZN14ActorCollision24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603828;
_ZZN14ActorCollision24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060382C;

_ZTVN4sead15RuntimeTypeInfo6DeriveI14ActorCollisionEE = 0x005D1D5C;
_ZNK4sead15RuntimeTypeInfo6DeriveI14ActorCollisionE9isDerivedEPKNS0_9InterfaceE = 0x00567718;


/* ActorState */

/* ctor */
_ZN10ActorStateC1Ev = 0x001C79C8;
_ZN10ActorStateC2Ev = 0x001C79C8;

/* virtual functions */
_ZNK10ActorState18getRuntimeTypeInfoEv = 0x0496FC4;

_ZGVZN10ActorState24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603380;
_ZZN10ActorState24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603384;

_ZTVN4sead15RuntimeTypeInfo6DeriveI10ActorStateEE = 0x005D1C0C;
_ZNK4sead15RuntimeTypeInfo6DeriveI10ActorStateE9isDerivedEPKNS0_9InterfaceE = 0x00566A68;


/* ActorMultiState */

/* ctor */
_ZN15ActorMultiStateC1Ev = 0x00305328;
_ZN15ActorMultiStateC2Ev = 0x00305328;

/* vtable */
_ZTV15ActorMultiState = 0x005B47D0;

/* virtual functions */
_ZNK15ActorMultiState18getRuntimeTypeInfoEv = 0x004A2954;

_ZN15ActorMultiState11changeStateERK7StateID = 0x0030531C;

_ZGVZN15ActorMultiState24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603908;
_ZZN15ActorMultiState24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060390C;

_ZTVN4sead15RuntimeTypeInfo6DeriveI15ActorMultiStateEE = 0x005D1DC8;
_ZNK4sead15RuntimeTypeInfo6DeriveI15ActorMultiStateE9isDerivedEPKNS0_9InterfaceE = 0x00567B2C;


/* BgActorBase */
_ZGVZN11BgActorBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006034D8;
_ZZN11BgActorBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006034DC;

_ZTVN4sead15RuntimeTypeInfo6DeriveI11BgActorBaseEE = 0x005D1C60;
_ZNK4sead15RuntimeTypeInfo6DeriveI11BgActorBaseE9isDerivedEPKNS0_9InterfaceE = 0x00566D94;


/* FlagSwitchBase */

/* ctor */
_ZN14FlagSwitchBaseC1Ev = 0x002E9D64;
_ZN14FlagSwitchBaseC2Ev = 0x002E9D64;

/* vtable */
_ZTV14FlagSwitchBase = 0x005B1E24;

/* virtual functions */
_ZN14FlagSwitchBase9onExecuteEv = 0x002E9D30;
_ZN14FlagSwitchBase10beforeDrawEv = 0x002E9D54;

_ZNK14FlagSwitchBase18getRuntimeTypeInfoEv = 0x004A1BF0;

_ZGVZN14FlagSwitchBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603858;
_ZZN14FlagSwitchBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060385C;

_ZTVN4sead15RuntimeTypeInfo6DeriveI14FlagSwitchBaseEE = 0x005D1D68;
_ZNK4sead15RuntimeTypeInfo6DeriveI14FlagSwitchBaseE9isDerivedEPKNS0_9InterfaceE = 0x0056778C;


/* LiftBase */

/* ctor */
_ZN8LiftBaseC1Ev = 0x004204F0;
_ZN8LiftBaseC2Ev = 0x004204F0;

/* functions */
_ZN8LiftBase4isOnEP11BgCollisionj = 0x00420180;


/* WireLine */

/* ctor */
_ZN8WireLineC1Ev = 0x0042F3C8;
_ZN8WireLineC2Ev = 0x0042F3C8;

/* states */
_ZN8WireLine14StateID_ActiveE = 0x006198FC;

/* Enemy */

/* ctor */
_ZN5EnemyC1Ev = 0x003AD534;
_ZN5EnemyC2Ev = 0x003AD534;

/* vtable */
_ZTV5Enemy = 0x005C3760;

/* virtual functions */
_ZN5Enemy13beforeExecuteEv = 0x003AB858;
_ZNK5Enemy18getRuntimeTypeInfoEv = 0x004A6D44;
_ZN5Enemy12powActivatedEv = 0x003ABBBC;
_ZN5Enemy15onCollisionLavaEP9ActorBase = 0x003AC870;
_ZN5Enemy11changeStateERK7StateID = 0x003AB9B4;
_ZN5Enemy5vf110Ev = 0x003AB9C0;
_ZN5Enemy5vf114Ev = 0x003AC8D8;
_ZN5Enemy5vf118Ev = 0x004A6CF8;
_ZN5Enemy5vf11CEv = 0x003ABF90;
_ZN5Enemy5vf120Ev = 0x003AC5F4;
_ZN5Enemy12damagePlayerEP10PlayerBase = 0x003AD49C;
_ZN5Enemy5vf128Ej = 0x004A69A4;
_ZN5Enemy23collisionHandlerEnemiesEP19ActorCollisionCheckS1_ = 0x003ABCC4;
_ZN5Enemy23collisionHandlerPlayersEP19ActorCollisionCheckS1_ = 0x003ABCF4;
_ZN5Enemy22collisionHandlerActorsEP19ActorCollisionCheckS1_ = 0x003ABF98;
_ZN5Enemy14collisionEnemyEP19ActorCollisionCheckS1_ = 0x003ACC7C;
_ZN5Enemy15collisionPlayerEP19ActorCollisionCheckS1_ = 0x003ACC80;
_ZN5Enemy17collisionStarMegaEP19ActorCollisionCheckS1_ = 0x003AC1D8;
_ZN5Enemy14collisionSlideEP19ActorCollisionCheckS1_ = 0x003AC110;
_ZN5Enemy19collisionFencePunchEP19ActorCollisionCheckS1_ = 0x003ACB3C;
_ZN5Enemy20collisionGroundPoundEP19ActorCollisionCheckS1_ = 0x003ACA8C;
_ZN5Enemy19collisionPipeCannonEP19ActorCollisionCheckS1_ = 0x003AC538;
_ZN5Enemy20collisionTanookiTailEP19ActorCollisionCheckS1_ = 0x003AC294;
_ZN5Enemy14collisionShellEP19ActorCollisionCheckS1_ = 0x003AC31C;
_ZN5Enemy17collisionFireballEP19ActorCollisionCheckS1_ = 0x003AC080;
_ZN5Enemy5vf160Ev = 0x003AC6BC;
_ZN5Enemy5vf164Ev = 0x004A680C;
_ZN5Enemy5vf168Ev = 0x004A6C34;
_ZN5Enemy5vf16CEv = 0x004A6D90;
_ZN5Enemy8onDefeatEv = 0x003AD310;
_ZN5Enemy5vf174Ev = 0x004A6644;
_ZN5Enemy9giveScoreEP10PlayerBase = 0x004A669C;
_ZN5Enemy5vf17CEv = 0x004A6A14;
_ZN5Enemy20playStompSoundEffectEP10PlayerBase = 0x004A6DC4;
_ZN5Enemy5vf184Ev = 0x004A64BC;
_ZN5Enemy5vf188Ev = 0x004A64F4;
_ZN5Enemy5vf18CEv = 0x004A69C8;
_ZN5Enemy20spawnHitEffectCommonERKN4sead7Vector2IfEE = 0x004A69CC;
_ZN5Enemy21spawnHitEffectHipDropERKN4sead7Vector2IfEE = 0x004A67C4;
_ZN5Enemy5vf198EPN4sead7Vector3IfEE = 0x004A6C28;
_ZN5Enemy5vf19CEv = 0x003AB840;
_ZN5Enemy5vf1A0Ev = 0x004A65CC;
_ZN5Enemy23initializeState_DieFallEv = 0x003AD184;
_ZN5Enemy20executeState_DieFallEv = 0x003ACF9C;
_ZN5Enemy21finalizeState_DieFallEv = 0x003AD164;
_ZN5Enemy26initializeState_DieBigFallEv = 0x003AD17C;
_ZN5Enemy23executeState_DieBigFallEv = 0x003ACECC;
_ZN5Enemy24finalizeState_DieBigFallEv = 0x003AD15C;
_ZN5Enemy24initializeState_DieSmokeEv = 0x003AD38C;
_ZN5Enemy21executeState_DieSmokeEv = 0x003AD154;
_ZN5Enemy22finalizeState_DieSmokeEv = 0x003AD174;
_ZN5Enemy24initializeState_DieOtherEv = 0x003AD388;
_ZN5Enemy21executeState_DieOtherEv = 0x003AD150;
_ZN5Enemy22finalizeState_DieOtherEv = 0x003AD16C;

/* functions */
_ZN5Enemy22processPlayerCollisionEP19ActorCollisionCheckS1_b = 0x004A68B8;
_ZN5Enemy13killWithStateEP9ActorBasePN4sead7Vector2IfEERK7StateID = 0x003AC404;
_ZN5Enemy9giveScoreERKN4sead7Vector3IfEEN8ScoreMgr10RewardTypeEa = 0x004A6A98;
_ZN5Enemy19getDirectionToActorEP9ActorBase = 0x00432080;
_ZN5Enemy17setDeathInfo_FallEhaN8ScoreMgr10RewardTypeE = 0x003ACC90;

/* static members */
_ZN5Enemy15StateID_DieFallE = 0x0060EE80;
_ZN5Enemy18StateID_DieBigFallE = 0x0060EEA4;
_ZN5Enemy16StateID_DieSmokeE = 0x0060EEC8;
_ZN5Enemy16StateID_DieOtherE = 0x0060EEEC;
_ZN5Enemy17collisionCallbackEP19ActorCollisionCheckS1_ = 0x003ACFF4;
_ZN5Enemy15commonRotationsE = 0x005E6484;

_ZGVZN5Enemy24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603BE8;
_ZZN5Enemy24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603BEC;

_ZTVN4sead15RuntimeTypeInfo6DeriveI5EnemyEE = 0x005D1E88;
_ZNK4sead15RuntimeTypeInfo6DeriveI5EnemyE9isDerivedEPKNS0_9InterfaceE = 0x0056826C;

/* EnemyDeathInfo */
_ZN14EnemyDeathInfo12setNoRespawnERKS_ = 0x002E84B0;
_ZN14EnemyDeathInfo24sDefaultFallAccelerationE = 0x005E64E8;
_ZN14EnemyDeathInfo20sDefaultFallSpeedMaxE = 0x005733F4;

/* CarryableEnemy */

/* ctor */
_ZN14CarryableEnemyC1Ev = 0x003AB7F4;
_ZN14CarryableEnemyC2Ev = 0x003AB7F4;

/* vtable */
_ZTV14CarryableEnemy = 0x005C3544;

/* virtual functions */
_ZNK14CarryableEnemy18getRuntimeTypeInfoEv = 0x004A63F4;
_ZN14CarryableEnemy15collisionPlayerEP19ActorCollisionCheckS1_ = 0x003AAF3C;
_ZN14CarryableEnemy5vf1D4Ev = 0x003AAA9C;
_ZN14CarryableEnemy8jumpedOnEP9ActorBase = 0x003AB10C;
_ZN14CarryableEnemy12jumpedOnMiniEP9ActorBase = 0x003AAC90;
_ZN14CarryableEnemy21collisionPlayerNormalEP19ActorCollisionCheckS1_ = 0x003AACE0;
_ZN14CarryableEnemy23collisionPlayerLiftableEP19ActorCollisionCheckS1_ = 0x003AB7F0;
_ZN14CarryableEnemy21initializeState_CarryEv = 0x003AB778;
_ZN14CarryableEnemy18executeState_CarryEv = 0x003AB540;
_ZN14CarryableEnemy19finalizeState_CarryEv = 0x003AB6B0;
_ZN14CarryableEnemy24initializeState_LiftableEv = 0x003AB444;
_ZN14CarryableEnemy21executeState_LiftableEv = 0x003AAF30;
_ZN14CarryableEnemy22finalizeState_LiftableEv = 0x003AB0CC;
_ZN14CarryableEnemy21initializeState_ThrowEv = 0x003AB448;
_ZN14CarryableEnemy18executeState_ThrowEv = 0x003AAF34;
_ZN14CarryableEnemy19finalizeState_ThrowEv = 0x003AB0E0;

/* functions */
_ZN14CarryableEnemy16getCarryPositionERN4sead7Vector3IfEE = 0x003ABA6C;

/* static members */
_ZN14CarryableEnemy13StateID_CarryE = 0x0060E554;
_ZN14CarryableEnemy16StateID_LiftableE = 0x0060E578;
_ZN14CarryableEnemy13StateID_ThrowE = 0x0060E59C;

_ZGVZN14CarryableEnemy24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603BE0;
_ZZN14CarryableEnemy24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603BE4;

_ZTVN4sead15RuntimeTypeInfo6DeriveI14CarryableEnemyEE = 0x005D1E7C;
_ZNK4sead15RuntimeTypeInfo6DeriveI14CarryableEnemyE9isDerivedEPKNS0_9InterfaceE = 0x005681F8;


/* Shell Enemy */
_ZGVZN10ShellEnemy24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603C18;
_ZZN10ShellEnemy24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603C1C;

_ZN10ShellEnemy13StateID_CarryE = 0x006117D4;
_ZN10ShellEnemy16StateID_LiftableE = 0x006117B0;

_ZTVN4sead15RuntimeTypeInfo6DeriveI10ShellEnemyEE = 0x005D1EA0;
_ZNK4sead15RuntimeTypeInfo6DeriveI10ShellEnemyE9isDerivedEPKNS0_9InterfaceE = 0x00568354;


/* Nokonoko */
_ZGVZN8Nokonoko24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603DB0;
_ZZN8Nokonoko24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603DB4;

_ZTVN4sead15RuntimeTypeInfo6DeriveI8NokonokoEE = 0x005D1F3C;
_ZNK4sead15RuntimeTypeInfo6DeriveI8NokonokoE9isDerivedEPKNS0_9InterfaceE = 0x00568938;


/* Patapata */
_ZGVZN8Patapata24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603DB8;
_ZZN8Patapata24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603DBC;


/* TogezoBase */
_ZGVZN10TogezoBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006034C0;
_ZZN10TogezoBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006034C4;

_ZTVN4sead15RuntimeTypeInfo6DeriveI10TogezoBaseEE = 0x005D1C54;
_ZNK4sead15RuntimeTypeInfo6DeriveI10TogezoBaseE9isDerivedEPKNS0_9InterfaceE = 0x00566D20;


/* Bro */

/* ctor */
_ZN3BroC1Ev = 0x0040A100;
_ZN3BroC2Ev = 0x0040A100;

/* vtable */
_ZTV3Bro = 0x005CA840;

/* virtual functions */
_ZN3Bro8onCreateEv = 0x00409540;
_ZN3Bro8onDeleteEv = 0x00409C68;
_ZN3Bro9onExecuteEv = 0x00409B08;
_ZN3Bro6onDrawEv = 0x00409508;
_ZN3Bro12damagePlayerEP10PlayerBase = 0x0040A088;
_ZN3Bro15collisionPlayerEP19ActorCollisionCheckS1_ = 0x00408A90;
_ZN3Bro20collisionGroundPoundEP19ActorCollisionCheckS1_ = 0x00408994;
_ZN3Bro5vf19CEv = 0x004081F0;
_ZN3Bro23initializeState_DieFallEv = 0x00409420;
_ZN3Bro20executeState_DieFallEv = 0x00408F30;
_ZN3Bro21finalizeState_DieFallEv = 0x00409040;
_ZN3Bro26initializeState_DieBigFallEv = 0x00409374;
_ZN3Bro23executeState_DieBigFallEv = 0x00408EEC;
_ZN3Bro24finalizeState_DieBigFallEv = 0x0040903C;

_ZN3Bro23initializeState_WalkingEv = 0x00408FB0;
_ZN3Bro20executeState_WalkingEv = 0x004087AC;
_ZN3Bro21finalizeState_WalkingEv = 0x00408990;
_ZN3Bro5vf1E0Ev = 0x0040923C;
_ZN3Bro5vf1E4Ev = 0x00408B38;
_ZN3Bro5vf1E8Ev = 0x00408F64;
_ZN3Bro25initializeState_JumpStartEv = 0x00409300;
_ZN3Bro22executeState_JumpStartEv = 0x00408DD8;
_ZN3Bro23finalizeState_JumpStartEv = 0x00408F6C;
_ZN3Bro20initializeState_JumpEv = 0x00408F70;
_ZN3Bro17executeState_JumpEv = 0x0040870C;
_ZN3Bro18finalizeState_JumpEv = 0x0040898C;
_ZN3Bro23initializeState_JumpEndEv = 0x00409264;
_ZN3Bro20executeState_JumpEndEv = 0x00408D30;
_ZN3Bro21finalizeState_JumpEndEv = 0x00408F68;
_ZN3Bro5vf210Ev = 0x004094CC;
_ZN3Bro5vf214Ev = 0x00409044;
_ZN3Bro5vf218Ev = 0x00409360;
_ZN3Bro5vf21CEv = 0x004AD5EC;
_ZN3Bro13getThrowFrameEv = 0x004AD5E0;
_ZN3Bro15spawnGoldEffectEv = 0x00408584;
_ZN3Bro19spawnGoldProjectileEv = 0x0040839C;
_ZN3Bro12vfsetWalkSpeedEv = 0x00409CF0;
_ZN3Bro7null230Ev = 0x00000000;
_ZN3Bro12getTextureIdEv = 0x00409CE4;
_ZN3Bro5vf238Ev = 0x0040849C;
_ZN3Bro7null23CEv = 0x00000000;
_ZN3Bro5vf240Ev = 0x0040826C;
_ZN3Bro5vf244Ev = 0x00408578;
_ZN3Bro5vf248Ev = 0x00408580;
_ZN3Bro15spawnProjectileEv = 0x0040857C;
_ZN3Bro11setHopTimerEv = 0x00408234;
_ZN3Bro11setHopSpeedEv = 0x00409C48;
_ZN3Bro5vf258Ev = 0x00409D28;
_ZN3Bro5vf25CEv = 0x00408494;
_ZN3Bro17throwWhenOnGroundEv = 0x004AD5D8;
_ZN3Bro5vf264Ev = 0x00409CF4;
_ZN3Bro17setThrowAnimationEv = 0x00408538;
_ZN3Bro5vf26CEv = 0x00408484;
_ZN3Bro5vf270Ev = 0x0040A084;
_ZN3Bro5vf274Ev = 0x00409CEC;


/* KillerBase */
_ZTV10KillerBase = 0x005A11E4;

/* virtual functions */
_ZN10KillerBase8onCreateEv = 0x001DF2A0;
_ZN10KillerBase8onDeleteEv = 0x001DFE80;
_ZN10KillerBase9onExecuteEv = 0x001DF5C0;
_ZN10KillerBase6onDrawEv = 0x001DF1C4;
_ZNK10KillerBase18getRuntimeTypeInfoEv = 0x004991C4;
_ZN10KillerBase15levelClearDeathEv = 0x001DEF44;
_ZN10KillerBase14collisionEnemyEP19ActorCollisionCheckS1_ = 0x001DEB64;
_ZN10KillerBase15collisionPlayerEP19ActorCollisionCheckS1_ = 0x001DEDE0;
_ZN10KillerBase17collisionStarMegaEP19ActorCollisionCheckS1_ = 0x001DE890;
_ZN10KillerBase14collisionShellEP19ActorCollisionCheckS1_ = 0x001DE8C0;
_ZN10KillerBase17collisionFireballEP19ActorCollisionCheckS1_ = 0x001DE7B0;
_ZN10KillerBase23initializeState_DieFallEv = 0x001DF12C;
_ZN10KillerBase20executeState_DieFallEv = 0x001DF018;
_ZN10KillerBase21finalizeState_DieFallEv = 0x003AD160;
_ZN10KillerBase26initializeState_DieBigFallEv = 0x001DF078;
_ZN10KillerBase23executeState_DieBigFallEv = 0x001DEF9C;
_ZN10KillerBase24finalizeState_DieBigFallEv = 0x001DF074;
_ZN10KillerBase6updateEv = 0x001DFF40;
_ZN10KillerBase7canBahpEv = 0x00499210;
_ZN10KillerBase22removeCollisionCheckExEv = 0x001E0458;
_ZN10KillerBase19addCollisionCheckExEv = 0x001E0488;

/* functions */
_ZN10KillerBase11spawnKillerERKN4sead7Vector3IfEEjP9ActorBaseij = 0x001DE514;
_ZN10KillerBase17spawnSearchKillerERKN4sead7Vector3IfEEjP9ActorBasei = 0x001DEABC;
_ZN10KillerBase17spawnMagnumKillerERKN4sead7Vector3IfEEjP9ActorBasei = 0x001DEA14;

_ZGVZN10KillerBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603418;
_ZZN10KillerBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060341C;

_ZTVN4sead15RuntimeTypeInfo6DeriveI10KillerBaseEE = 0x005D1C30;
_ZNK4sead15RuntimeTypeInfo6DeriveI10KillerBaseE9isDerivedEPKNS0_9InterfaceE = 0x00566BC4;


/* Killer */
_ZTV6Killer = 0x005C6A1C;

/* virtual functions */
_ZN6KillerD0Ev = 0x003D623C;
_ZN6Killer8onCreateEv = 0x003D5F68;
_ZN6Killer9onExecuteEv = 0x003D61F4;
_ZN6Killer6onDrawEv = 0x003D5F48;
_ZNK6Killer18getRuntimeTypeInfoEv = 0x004AB284;

/* functions */
_ZN6KillerC1Ev = 0x003D6224;
_ZN6KillerC2Ev = 0x003D6224;
_ZN6Killer20initializeState_MoveEv = 0x003D5EEC;
_ZN6Killer17executeState_MoveEv = 0x003D5DD0;
_ZN6Killer18finalizeState_MoveEv = 0x003D5EE8;
_ZN6Killer12updateSpinExEv = 0x003D5CBC;

_ZGVZN6Killer24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603C68;
_ZZN6Killer24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603C6C;


/* KillerHoudai */
_ZN12KillerHoudai5buildEv = 0x0055841C;
_ZN12KillerHoudai7destroyEP5fBase = 0x0055BC40;

_ZGVZN12KillerHoudai24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603678;
_ZZN12KillerHoudai24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060367C;

/* DoorBase */
_ZTV8DoorBase = 0x005CAC9C;
_ZN8DoorBaseC1Ev = 0x0040BFA8;
_ZN8DoorBaseC2Ev = 0x0040BFA8;
_ZN8DoorBase13playSoundOpenEv = 0x0040BFA4;
_ZN8DoorBase5vf220Ev = 0x0040BFA0;
_ZN8DoorBase10isOpenableEv = 0x0040BF58;
_ZN8DoorBase8onDeleteEv = 0x0040BF18;
_ZN8DoorBase16setupModelMatrixEv = 0x0040BE50;
_ZN8DoorBase12createModelsEv = 0x0040BE4C;
_ZN8DoorBase9onExecuteEv = 0x0040BD84;
_ZN8DoorBase17updateModelMatrixEv = 0x0040BD08;
_ZN8DoorBase8onCreateEv = 0x0040BB54;
_ZN8DoorBase6onDrawEv = 0x0040BB20;
_ZN8DoorBase22initializeState_VanishEv = 0x0040BA6C;
_ZN8DoorBase21initializeState_CloseEv = 0x0040BA60;
_ZN8DoorBase20initializeState_IdleEv = 0x0040BA44;
_ZN8DoorBase20initializeState_OpenEv = 0x0040BA18;
_ZN8DoorBase20finalizeState_VanishEv = 0x0040BA14;
_ZN8DoorBase19finalizeState_CloseEv = 0x0040BA10;
_ZN8DoorBase18finalizeState_IdleEv = 0x0040BA0C;
_ZN8DoorBase18finalizeState_OpenEv = 0x0040B9FC;
_ZN8DoorBase19executeState_VanishEv = 0x0040B9F4;
_ZN8DoorBase18executeState_CloseEv = 0x0040B984;
_ZN8DoorBase17executeState_IdleEv = 0x0040B924;
_ZN8DoorBase17executeState_OpenEv = 0x0040B8C0;
_ZN8DoorBase13playSoundMoveEv = 0x0040B8BC;
_ZN8DoorBase13isEventActiveEv = 0x0040B888;
_ZN8DoorBase17spawnAppearEffectEv = 0x0040B834;
_ZN8DoorBase12setAnimCloseEv = 0x0040B830;
_ZN8DoorBase10isFakeDoorEv = 0x0040B828;
_ZN8DoorBase11setAnimIdleEv = 0x0040B824;
_ZN8DoorBase11setAnimOpenEv = 0x0040B820;
_ZN8DoorBase14playSoundCloseEv = 0x0040B81C;
_ZN8DoorBase5vf21CEv = 0x0040B818;
_ZN8DoorBase19setupCollisionCheckEv = 0x0040B814;
_ZN8DoorBase17collisionCallbackEP19ActorCollisionCheckS1_ = 0x0040B628;
_ZZN8DoorBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D5C;
_ZN8DoorBase12StateID_OpenE = 0x00615D08;
_ZN8DoorBase13StateID_CloseE = 0x00615D2C;
_ZN8DoorBase12StateID_IdleE = 0x00615D50;
_ZN8DoorBase14StateID_VanishE = 0x00615D74;
_ZN8DoorBase5vf20CEv = 0x0;
_ZN8DoorBase5vf210Ev = 0x0;

/* TarzanIvy */

/* vtable */
_ZTV9TarzanIvy = 0x005D0690;

/* dtor */
_ZN9TarzanIvyD0Ev = 0x0453374;

_ZN9TarzanIvyD2Ev = 0x0453374;
_ZN9TarzanIvyD2Ev = 0x0453374;

/* virtual functions */
_ZN9TarzanIvy8onCreateEv = 0x0452C04;
_ZN9TarzanIvy8onDeleteEv = 0x0452D04;
_ZN9TarzanIvy9onExecuteEv = 0x0452C8C;
_ZN9TarzanIvy6onDrawEv = 0x0452BEC;
_ZN9TarzanIvy5vf110Ev = 0x00000000;
_ZN9TarzanIvy5vf114Ev = 0x0452FCC;
_ZN9TarzanIvy5vf118Ev = 0x0452D38;


/* BlockCoinBase */

/* ctor */
_ZN13BlockCoinBaseC1Ev = 0x004349C0;
_ZN13BlockCoinBaseC2Ev = 0x004349C0;

/* vtable */
_ZTV13BlockCoinBase = 0x005CDEB0;   /* 0x005CDEB8 */

/* virtual functions */
_ZNK13BlockCoinBase18getRuntimeTypeInfoEv = 0x004AE4A0;

_ZN13BlockCoinBase5vf110Ev = 0x00432D34;
_ZN13BlockCoinBase5vf114Ev = 0x00433450;
_ZN13BlockCoinBase5vf118Ev = 0x0043450C;
_ZN13BlockCoinBase5vf11CEv = 0x00432A20;
_ZN13BlockCoinBase11spawnItemUpEv = 0x00432D38;
_ZN13BlockCoinBase5vf124Ev = 0x00432A28;
_ZN13BlockCoinBase5vf128Ev = 0x00433458;
_ZN13BlockCoinBase13spawnItemUpEv = 0x00433454;
_ZN13BlockCoinBase5vf130Ev = 0x0043454C;
_ZN13BlockCoinBase5vf134Eb = 0x00432A2C;
_ZN13BlockCoinBase16spawnSpringboardEv = 0x00432AA8;
_ZN13BlockCoinBase14spawnGoldBlockEv = 0x00433930;
_ZN13BlockCoinBase5vf140Ev = 0x00432A24;
_ZN13BlockCoinBase5vf144Ev = 0x00433938;
_ZN13BlockCoinBase5vf148Ev = 0x00433634;
_ZN13BlockCoinBase5vf14CEv = 0x00433838;
_ZN13BlockCoinBase5vf150Ev = 0x00434718;
_ZN13BlockCoinBase5vf154Ev = 0x00434550;
_ZN13BlockCoinBase5vf158Ev = 0x0043462C;
_ZN13BlockCoinBase5vf15CEv = 0x00434510;
_ZN13BlockCoinBase5vf160Ev = 0x004338C0;
_ZN13BlockCoinBase5vf164Ev = 0x00433934;
_ZN13BlockCoinBase5vf168Ev = 0x004347D0;
_ZN13BlockCoinBase5vf16CEv = 0x004346E4;
_ZN13BlockCoinBase5vf170Ev = 0x00434714;
_ZN13BlockCoinBase5vf174Ev = 0x00434728;
_ZN13BlockCoinBase5vf178Ev = 0x00434564;
_ZN13BlockCoinBase5vf17CEv = 0x00434634;
_ZN13BlockCoinBase5vf180Ev = 0x00434794;
_ZN13BlockCoinBase5vf184Ev = 0x00434638;
_ZN13BlockCoinBase5vf188Ev = 0x00434710;
_ZN13BlockCoinBase5vf18CEv = 0x004349B0;
_ZN13BlockCoinBase5vf190Ev = 0x004347E0;
_ZN13BlockCoinBase5vf194Ev = 0x004349AC;

_ZGVZN13BlockCoinBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603E10;
_ZZN13BlockCoinBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603E14;

_ZTVN4sead15RuntimeTypeInfo6DeriveI13BlockCoinBaseEE = 0x005D1F78;
_ZNK4sead15RuntimeTypeInfo6DeriveI13BlockCoinBaseE9isDerivedEPKNS0_9InterfaceE = 0x00568B7C;


/* BlockCoinPairChildBase */

/* ctor */
_ZN22BlockCoinPairChildBaseC1Ev = 0x00306968;
_ZN22BlockCoinPairChildBaseC2Ev = 0x00306968;

/* vtable */
_ZTV22BlockCoinPairChildBase = 0x005B4AB0;  /* 0x005B4AB8 */

/* virtual functions */
_ZNK22BlockCoinPairChildBase18getRuntimeTypeInfoEv = 0x004A2A94;
_ZN22BlockCoinPairChildBase11spawnItemUpEv = 0x00306514;
_ZN22BlockCoinPairChildBase13spawnItemDownEv = 0x003065AC;
_ZN22BlockCoinPairChildBase5vf140Ev = 0x00305DEC;
_ZN22BlockCoinPairChildBase5vf198Ev = 0x00306560;
_ZN22BlockCoinPairChildBase5vf19CEv = 0x00306170;
_ZN22BlockCoinPairChildBase5vf1A0Ev = 0x0030616C;
_ZN22BlockCoinPairChildBase5vf1A4Ev = 0x00306614;

_ZGVZN22BlockCoinPairChildBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603918;
_ZZN22BlockCoinPairChildBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060391C;

_ZTVN4sead15RuntimeTypeInfo6DeriveI22BlockCoinPairChildBaseEE = 0x005D1DD4;
_ZNK4sead15RuntimeTypeInfo6DeriveI22BlockCoinPairChildBaseE9isDerivedEPKNS0_9InterfaceE = 0x00567BA0;


/* BlockBase */

/* ctor */
_ZN9BlockBaseC1Ev = 0x002DECFC;
_ZN9BlockBaseC2Ev = 0x002DECFC;

/* vtable */
_ZTV9BlockBase = 0x005B0EF8;  /* 0x005B0F00 */

/* virtual functions */
_ZN9BlockBase9onExecuteEv = 0x002DE9D4;
_ZN9BlockBase6onDrawEv = 0x002DE968;
_ZNK9BlockBase18getRuntimeTypeInfoEv = 0x004A16F0;
_ZN9BlockBase12powActivatedEv = 0x002DD63C;
_ZN9BlockBase5vf118Ev = 0x002197AC;
_ZN9BlockBase11spawnItemUpEv = 0x002DD9E0;
_ZN9BlockBase13spawnItemDownEv = 0x002DDFFC;
_ZN9BlockBase5vf130Ev = 0x002DE74C;

_ZN9BlockBase17fetchInitialStateEv = 0x002DD8C4;
_ZN9BlockBase5vf1ACEv = 0x002DD96C;
_ZN9BlockBase11getContentsEv = 0x002DDB34;
_ZN9BlockBase5vf1B4Ev = 0x002DE210;
_ZN9BlockBase5vf1B8Ev = 0x002DDB28;
_ZN9BlockBase5vf1BCEv = 0x002DD7E4;
_ZN9BlockBase5vf1C0Ev = 0x002DE144;
_ZN9BlockBase11doCullCheckEv = 0x002DD668;
_ZN9BlockBase5vf1C8Ev = 0x002DDC54;
_ZN9BlockBase5vf1CCEv = 0x002DD970;
_ZN9BlockBase5vf1D0Ev = 0x002DE458;
_ZN9BlockBase20initializeState_WaitEv = 0x002DE82C;
_ZN9BlockBase17executeState_WaitEv = 0x002DD670;
_ZN9BlockBase18finalizeState_WaitEv = 0x002DE5C8;
_ZN9BlockBase20initializeState_UsedEv = 0x002DE850;
_ZN9BlockBase17executeState_UsedEv = 0x002DE760;
_ZN9BlockBase18finalizeState_UsedEv = 0x002DE834;

/* functions */
_ZN9BlockBase4initEb = 0x002DEB04;
_ZN9BlockBase13linkPairChildEv = 0x002DE020;
_ZN9BlockBase15updatePairChildEv = 0x002DDB74;

/* static members */
_ZN9BlockBase12StateID_WaitE = 0x00613E00;
_ZN9BlockBase12StateID_UsedE = 0x00613E24;

_ZGVZN9BlockBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603808;
_ZZN9BlockBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060380C;

_ZTVN4sead15RuntimeTypeInfo6DeriveI9BlockBaseEE = 0x005D1D44;
_ZNK4sead15RuntimeTypeInfo6DeriveI9BlockBaseE9isDerivedEPKNS0_9InterfaceE = 0x00567630;


/* BlockStateMgr */
_ZN13BlockStateMgr8instanceE = 0x005E7BE8;
_ZN13BlockStateMgr13getBlockStateERKN4sead7Vector3IfEEh = 0x00403CC8;
_ZN13BlockStateMgr13setBlockStateERKN4sead7Vector3IfEEhh = 0x00403DD8;


/* ItemBase */

/* ctor */
_ZN8ItemBaseC1Ev = 0x0041E40C;
_ZN8ItemBaseC2Ev = 0x0041E40C;

/* vtable */
_ZTV8ItemBase = 0x005CBE58;   /* 0x005CBE60 */

/* virtual functions */
_ZN8ItemBase8onDeleteEv = 0x0041E3B0;
_ZN8ItemBase6onDrawEv = 0x0041E378;
_ZNK8ItemBase18getRuntimeTypeInfoEv = 0x004ADB90;
_ZN8ItemBase5vf110Ev = 0x0041D3F4;
_ZN8ItemBase5vf114Ev = 0x0041CB14;
_ZN8ItemBase5vf118Ev = 0x0041CE94;
_ZN8ItemBase5vf11CEv = 0x0041E12C;
_ZN8ItemBase5vf120Ev = 0x0041DD14;
_ZN8ItemBase5vf124Ev = 0x0041DF5C;
_ZN8ItemBase5vf128Ev = 0x0041DA24;
_ZN8ItemBase5vf12CEv = 0x0041D658;
_ZN8ItemBase5vf130Ev = 0x0041D878;
_ZN8ItemBase5vf138Ev = 0x0041B9F4;
_ZN8ItemBase16decideFirstStateEv = 0x0041C650;
_ZN8ItemBase15decideIdleStateEv = 0x0041D9D8;
_ZN8ItemBase5vf144Ev = 0x0041E08C;
_ZN8ItemBase17setAnimationOutUpEv = 0x0041C0A0;
_ZN8ItemBase19setAnimationOutDownv = 0x0041C528;
_ZN8ItemBase16setAnimationWaitEv = 0x0041B724;
_ZN8ItemBase17setAnimationWait2Ev = 0x0041BFA4;
_ZN8ItemBase19setAnimationOutJumpEv = 0x0041B720;
_ZN8ItemBase5vf15CEv = 0x00000000;
_ZN8ItemBase5vf160Ev = 0x00000000;
_ZN8ItemBase5vf164Ev = 0x0041C2B0;
_ZN8ItemBase15collectionCheckEv = 0x0041BCB0;
_ZN8ItemBase5vf16CEv = 0x0041CEA0;
_ZN8ItemBase5vf170Ev = 0x0041CECC;
_ZN8ItemBase5vf174Ev = 0x0041CEF8;
_ZN8ItemBase5vf178Ev = 0x0041DF38;
_ZN8ItemBase11updateModelEv = 0x0041B44C;
_ZN8ItemBase5vf180Ev = 0x0041C340;

/* functions */
_ZN8ItemBase4initEv = 0x0041B820;
_ZN8ItemBase20tryGivePlayerPowerupERj7Powerupb = 0x0041C52C;
_ZN8ItemBase9collectedEjj = 0x0041BCB8;

_ZGVZN8ItemBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D90;
_ZZN8ItemBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D94;

_ZTVN4sead15RuntimeTypeInfo6DeriveI8ItemBaseEE = 0x005D1F18;
_ZNK4sead15RuntimeTypeInfo6DeriveI8ItemBaseE9isDerivedEPKNS0_9InterfaceE = 0x005687DC;


/* Item */

/* vtable */
_ZTV4Item = 0x005AD50C;   /* 0x005AD514 */

/* ctor */
_ZN4ItemC1Ev = 0x00294254;
_ZN4ItemC2Ev = 0x00294254;

/* virtual functions */
_ZNK4Item18getRuntimeTypeInfoEv = 0x0049EE50;
_ZN4Item5vf184Ev = 0x00293BB0;
_ZN4Item5vf188Ev = 0x00293BB4;
_ZN4Item5vf18CEv = 0x00293BB8;

/* static members */
_ZN4Item14StateID_MovingE = 0x00613B70;
_ZN4Item18StateID_StationaryE = 0x00613B90;
_ZN4Item15StateID_JumpingE = 0x00613BB0;

_ZGVZN4Item24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603758;
_ZZN4Item24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060375C;

_ZTVN4sead15RuntimeTypeInfo6DeriveI4ItemEE = 0x005D1D08;
_ZNK4sead15RuntimeTypeInfo6DeriveI4ItemE9isDerivedEPKNS0_9InterfaceE = 0x005673EC;


/* ItemMgr */

/* static members */
_ZN7ItemMgr8instanceE = 0x005E7698;

/* functions */
_ZN7ItemMgr9spawnItemERKN4sead7Vector3IfEExh = 0x00293300;


/* Boss */

/* ctor */
_ZN4BossC1Ev = 0x405278;
_ZN4BossC2Ev = 0x405278;

/* virtual functions */
_ZN4Boss8onCreateEv = 0x4050B8;
_ZN4Boss13beforeExecuteEv = 0x404538;
_ZN4Boss12afterExecuteEi = 0x404628;
_ZNK4Boss18getRuntimeTypeInfoEv = 0x4AD4B4;
_ZN4Boss15collisionPlayerEP19ActorCollisionCheckS1_ = 0x404ED8;
_ZN4Boss17collisionStarMegaEP19ActorCollisionCheckS1_ = 0x404A64;
_ZN4Boss14collisionSlideEP19ActorCollisionCheckS1_ = 0x404A5C;
_ZN4Boss19collisionFencePunchEP19ActorCollisionCheckS1_ = 0x404ED0;
_ZN4Boss20collisionGroundPoundEP19ActorCollisionCheckS1_ = 0x404D80;
_ZN4Boss20collisionTanookiTailEP19ActorCollisionCheckS1_ = 0x404BB8;
_ZN4Boss14collisionShellEP19ActorCollisionCheckS1_ = 0x404BD0;
_ZN4Boss17collisionFireballEP19ActorCollisionCheckS1_ = 0x4048A4;
_ZN4Boss5vf160Ev = 0x404C44;
_ZN4Boss5vf164Ev = 0x4AD470;
_ZN4Boss5vf178Ev = 0x4AD45C;
_ZN4Boss23initializeState_DieFallEv = 0x3AD180;
_ZN4Boss20executeState_DieFallEv = 0x404FD4;
_ZN4Boss21finalizeState_DieFallEv = 0x405048;
_ZN4Boss27initializeState_DieFireballEv = 0x40507C;
_ZN4Boss24executeState_DieFireballEv = 0x404FC8;
_ZN4Boss25finalizeState_DieFireballEv = 0x40503C;
_ZN4Boss23initializeState_DieUnk1Ev = 0x4050AC;
_ZN4Boss20executeState_DieUnk1Ev = 0x405030;
_ZN4Boss21finalizeState_DieUnk1Ev = 0x405070;
_ZN4Boss23initializeState_DieUnk2Ev = 0x4050A0;
_ZN4Boss20executeState_DieUnk2Ev = 0x405024;
_ZN4Boss21finalizeState_DieUnk2Ev = 0x405064;
_ZN4Boss27initializeState_DieStarMegaEv = 0x405088;
_ZN4Boss24executeState_DieStarMegaEv = 0x404FD8;
_ZN4Boss25finalizeState_DieStarMegaEv = 0x40504C;
_ZN4Boss23initializeState_DieUnk3Ev = 0x405094;
_ZN4Boss20executeState_DieUnk3Ev = 0x404FE4;
_ZN4Boss21finalizeState_DieUnk3Ev = 0x405058;
_ZN4Boss9demoStartEv = 0x405138;
_ZN4Boss7demoEndEv = 0x405148;
_ZN4Boss5vf218Ev = 0x404844;
_ZN4Boss5vf21CEv = 0x00000000;
_ZN4Boss5vf220Ev = 0x00000000;
_ZN4Boss5vf224Ev = 0x00000000;
_ZN4Boss16lastDamageWasHitEv = 0x4AD4A4;
_ZN4Boss13processDamageEi = 0x40449C;
_ZN4Boss5vf244Ev = 0x00000000;
_ZN4Boss5vf248Ev = 0x00000000;
_ZN4Boss5vf250Ev = 0x4AD4AC;
_ZN4Boss15hitTimerStartedEv = 0x40483C;
_ZN4Boss15hitTimerRunningEv = 0x4047E0;
_ZN4Boss13hitTimerEndedEv = 0x4046D0;
_ZN4Boss15hitTimeFireballEv = 0x404F84;
_ZN4Boss5vf264Ev = 0x00000000;
_ZN4Boss14hitTimeStompedEv = 0x404F8C;
_ZN4Boss10killActorsEv = 0x4045F8;
_ZN4Boss15playerCollisionEv = 0x405160;
_ZN4Boss14stompCollisionEv = 0x404828;
_ZN4Boss18stompCollisionLastEv = 0x4046A8;
_ZN4Boss17fireballCollisionEv = 0x404824;
_ZN4Boss21fireballCollisionLastEv = 0x404694;
_ZN4Boss20groundPoundCollisionEv = 0x404BC0;
_ZN4Boss24groundPoundCollisionLastEv = 0x40482C;
_ZN4Boss5vf28CEv = 0x00000000;
_ZN4Boss5vf290Ev = 0x00000000;
_ZN4Boss17starMegaCollisionEv = 0x404838;
_ZN4Boss21starMegaCollisionLastEv = 0x4046BC;
_ZN4Boss12unkCollisionEv = 0x404848;
_ZN4Boss16unkCollisionLastEv = 0x404794;
_ZN4Boss5vf2A4Ev = 0x00000000;
_ZN4Boss5vf2A8Ev = 0x00000000;
_ZN4Boss7damagedEv = 0x4044C0;
_ZN4Boss11damagedLastEv = 0x405158;
_ZN4Boss24canCollidePlayerPreMaybeEv = 0x4AD468;
_ZN4Boss24canCollidePlayerTopMaybeEv = 0x4AD500;
_ZN4Boss25canCollidePlayerSideMaybeEv = 0x4AD508;
_ZN4Boss18canCollideFireballEv = 0x4AD460;
_ZN4Boss5vf2C4Ev = 0x00000000;
_ZN4Boss5vf2C8Ev = 0x00000000;
_ZN4Boss20invincibleToStarMegaEv = 0x4AD49C;
_ZN4Boss13onDamageAliveEv = 0x404840;
_ZN4Boss12onDamageDeadEv = 0x404BCC;
_ZN4Boss21onDamageFireballMaybeEv = 0x4047E8;
_ZN4Boss5vf2DCEv = 0x00000000;
_ZN4Boss16playSoundStompedEv = 0x404760;
_ZN4Boss20playSoundStompedLastEv = 0x404500;
_ZN4Boss19playSoundStarDefeatEv = 0x4047A8;
_ZN4Boss17playSoundStarLastEv = 0x4045BC;
_ZN4Boss5vf2F0Ev = 0x00000000;
_ZN4Boss5vf2F4Ev = 0x00000000;
_ZN4Boss19playSoundFireDamageEv = 0x4046D8;
_ZN4Boss23playSoundFireDamageLastEv = 0x4044C4;
_ZN4Boss20playSoundStarDefeat2Ev = 0x4047EC;
_ZN4Boss18playSoundStarLast2Ev = 0x404658;
_ZN4Boss13vf308_onDead2Ev = 0x4047E4;
_ZN4Boss5vf30CEv = 0x00000000;
_ZN4Boss5vf310Ev = 0x00000000;
_ZN4Boss10setupModelEv = 0x4046D4;
_ZN4Boss11updateModelEv = 0x4044BC;
_ZN4Boss18setupDamageToDeathEv = 0x404790;
_ZN4Boss16setupDamageToHitEv = 0x404D7C;
_ZN4Boss5setupEv = 0x404620;
_ZN4Boss19addPlayerLookTargetEv = 0x40484C;
_ZN4Boss22removePlayerLookTargetEv = 0x404C2C;

_ZGVZN4Boss24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D38;
_ZZN4Boss24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D3C;

_ZTVN4sead15RuntimeTypeInfo6DeriveI4BossEE = 0x005D1F00;
_ZNK4sead15RuntimeTypeInfo6DeriveI4BossE9isDerivedEPKNS0_9InterfaceE = 0x005686F4;


/* BossDemo */
_ZTV8BossDemo = 0x005B16B8;

/* vtable */

/* ctor */
_ZN8BossDemoC1Ev = 0x406C74;
_ZN8BossDemoC2Ev = 0x406C74;

/* virtual functions */
_ZN8BossDemo8onCreateEv = 0x406BD8;
_ZN8BossDemo8onDeleteEv = 0x406C54;
_ZN8BossDemo9onExecuteEv = 0x406C30;
_ZN8BossDemo10beforeDrawEv = 0x406C48;
_ZNK8BossDemo18getRuntimeTypeInfoEv = 0x4AD540;
_ZN8BossDemo20initializeState_WaitEv = 0x405EBC;
_ZN8BossDemo17executeState_WaitEv = 0x405AD8;
_ZN8BossDemo18finalizeState_WaitEv = 0x405CB0;
_ZN8BossDemo21initializeState_IntroEv = 0x406B64;
_ZN8BossDemo18executeState_IntroEv = 0x406A5C;
_ZN8BossDemo19finalizeState_IntroEv = 0x406AF4;
_ZN8BossDemo21initializeState_FightEv = 0x405F44;
_ZN8BossDemo18executeState_FightEv = 0x405E5C;
_ZN8BossDemo19finalizeState_FightEv = 0x405ED0;
_ZN8BossDemo21initializeState_OutroEv = 0x406B0C;
_ZN8BossDemo18executeState_OutroEv = 0x4060AC;
_ZN8BossDemo19finalizeState_OutroEv = 0x406A58;
_ZN8BossDemo5vf13CEv = 0x4AD520;
_ZN8BossDemo5vf140Ev = 0x4AD528;
_ZN8BossDemo10killActorsEv = 0x4052BC;
_ZN8BossDemo5vf148Ev = 0x406C70;
_ZN8BossDemo5vf14CEv = 0x406C50;
_ZN8BossDemo16canStartBossDemoEv = 0x405E4C;
_ZN8BossDemo22isFightStillGoingMaybeEv = 0x405C98;
_ZN8BossDemo13canStartIntroEv = 0x405430;
_ZN8BossDemo15searchBossActorEv = 0x4052B4;
_ZN8BossDemo16searchOutroActorEv = 0x000000;
_ZN8BossDemo7createdEv = 0x405438;
_ZN8BossDemo13hasOutroActorEv = 0x405EE8;
_ZN8BossDemo15spawnOutroActorEv = 0x405EC8;
_ZN8BossDemo20isOutroActorFinishedEv = 0x405CA4;
_ZN8BossDemo5vf174Ev = 0x405E54;
_ZN8BossDemo17hasOutroCameraPanEv = 0x4AD530;
_ZN8BossDemo12unkShutters1Ev = 0x405CB4;
_ZN8BossDemo12unkShutters2Ev = 0x405958;
_ZN8BossDemo12openShuttersEv = 0x405B80;
_ZN8BossDemo5vf188Ev = 0x405954;
_ZN8BossDemo5vf18CEv = 0x406AF0;
_ZN8BossDemo18setAfterFightStateEv = 0x405ED4;
_ZN8BossDemo5vf194Ev = 0x4AD538;
_ZN8BossDemo5vf198Ev = 0x405950;

/* functions */
_ZN8BossDemo12walkInPlayerEf = 0x4056C8;

_ZGVZN8BossDemo24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D40;
_ZZN8BossDemo24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D44;

_ZTVN4sead15RuntimeTypeInfo6DeriveI8BossDemoEE = 0x005D1F0C;
_ZNK4sead15RuntimeTypeInfo6DeriveI8BossDemoE9isDerivedEPKNS0_9InterfaceE = 0x00568768;


/* PlayerBase */
_ZN10PlayerBase11changeStateERK7StateIDjj = 0x001F3B30;
_ZN10PlayerBase11changeStateERK7StateIDj = 0x001EF3A4;

_ZGVZN10PlayerBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603480;
_ZZN10PlayerBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603484;

_ZTVN4sead15RuntimeTypeInfo6DeriveI10PlayerBaseEE = 0x005D1C48;
_ZNK4sead15RuntimeTypeInfo6DeriveI10PlayerBaseE9isDerivedEPKNS0_9InterfaceE = 0x00566CAC;


/* PlayerObject */
_ZN12PlayerObject19sizeDefinitionSmallE = 0x00580734;
_ZN12PlayerObject20sizeDefinitionNormalE = 0x005807E8;
_ZN12PlayerObject18sizeDefinitionMiniE = 0x005805EC;
_ZN12PlayerObject18sizeDefinitionMegaE = 0x0058089C;

_ZN12PlayerObject15StateID_SitJumpE = 0x0061B0AC;
_ZN12PlayerObject12StateID_WalkE = 0x0061B01C;

_ZGVZN12PlayerObject24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006036C0;
_ZZN12PlayerObject24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006036C4;


/* PlayerModelMgr */

/* vtable */
_ZTV14PlayerModelMgr = 0x005B3128;

_ZN14PlayerModelMgr12setAnimationEjf = 0x002F4028;
_ZN14PlayerModelMgr12setAnimationEjff = 0x002F3C54;


/* PlayerModelBase */

/* vtable */
_ZTV15PlayerModelBase = 0x005B665C;


/* PlayerModel */

/* vtable */
_ZTV11PlayerModel = 0x005A7C44;


/* PlayerInput */
_ZN11PlayerInput10isJumpHeldEv = 0x004AF984;
_ZN11PlayerInput13isJumpPressedEv = 0x004AFA30;



/* Scene */

/* ctor */
_ZN5SceneC1Ev = 0x00484378;
_ZN5SceneC2Ev = 0x00484378;

/* dtor */
_ZN5SceneD1Ev = 0x004843A4;
_ZN5SceneD2Ev = 0x004843A4;

/* vtable */
_ZTV5Scene = 0x0059AB98;

/* virtual functions */
_ZN5Scene12beforeCreateEv = 0x00484198;
_ZN5Scene11afterCreateEi = 0x00483BBC;
_ZN5Scene12beforeDeleteEv = 0x00484240;
_ZN5Scene11afterDeleteEi = 0x00483BC0;
_ZN5Scene13beforeExecuteEv = 0x00483C6C;
_ZN5Scene12afterExecuteEi = 0x00484014;
_ZN5Scene10beforeDrawEv = 0x00484180;
_ZN5Scene9afterDrawEi = 0x00484194;

_ZN5Scene4vf3CEv = 0x0000000;
_ZN5Scene4vf40Ej = 0x00100ECF;

/* static members */
_ZN5Scene11changeSceneEjhhhhj = 0x00484034;
_ZN5Scene11changeSceneEjj = 0x00484074;
_ZN5Scene13setTransitionEhhhh = 0x00484018;
_ZN5Scene11nextSceneIdE = 0x005EF9A0;
_ZN5Scene14currentSceneIdE = 0x005EF9A2;
_ZN5Scene11lastSceneIdE = 0x005EF9A4;


/* ScCourse */
_ZN8ScCourse8instanceE = 0x005E7210;
_ZN8ScCourse14getStockItemIdEh = 0x004ADF44;
_ZN8ScCourse14setStockItemIdEhh = 0x00429CF8;
_ZN8ScCourse23setCollectionCoinStatusEhb = 0x0042A3BC;


/* ScCourseIn */
_ZN10ScCourseIn21StateID_WaitExitReadyE = 0x00613434;


/* FadeMgr */
_ZN7FadeMgr8instanceE = 0x005ED2C0;
_ZN7FadeMgr10setColoredEb = 0x0040CDE8;


/* CsActorBase */

/* virtual functions */
_ZN7CsActorD2Ev = 0x047F024;
_ZN7CsActor11afterCreateEi = 0x047EF74;
_ZN7CsActor13beforeExecuteEv = 0x02D9700;
_ZN7CsActor11afterDeleteEi = 0x047EF7C;
_ZN7CsActor12afterExecuteEi = 0x047EFC8;
_ZN7CsActor10beforeDrawEv = 0x02D97C8;
_ZN7CsActor4vf3CEv = 0x0;
_ZN7CsActor4vf40Ev = 0x0;
_ZN7CsActor4vf44Ev = 0x0;

/* functions */
_ZN7CsActorC2Ev = 0x02D97EC;


/* CsActorState */ 
_ZN12CsActorState11changeStateERK7StateID = 0x001386A8;


/* MapObjWorld */
_ZN14AcCourseSelect11MapObjWorld12StateID_Unk1E = 0x0060C080;
_ZN14AcCourseSelect11MapObjWorld12StateID_Unk2E = 0x0060C0A4;
_ZN14AcCourseSelect11MapObjWorld19updateModelMtxPathsEv = 0x002B1F1C;


/* Misc actor functions */
_Z17Player_isPunchingP9ActorBase = 0x0026262C;


/* BsEventMgr */
_ZN14AcCourseSelect10BsEventMgr8instanceE = 0x005E5778;
_ZN14AcCourseSelect10BsEventMgr9hasScriptEv = 0x004A090C;
_ZN14AcCourseSelect10BsEventMgr18getCurrentScriptIdEv = 0x004A08F8;
_ZN14AcCourseSelect10BsEventMgr15getCurrentEventEv = 0x004A08D0;
_ZN14AcCourseSelect10BsEventMgr15setNextScriptIdERK8ScriptId = 0x002AECE0;


/* Worldmap related */
_ZN14AcCourseSelect6CsInfo8instanceE = 0x005E5808;

_ZN14AcCourseSelect10getCsvDataEv = 0x002D1B14;
_ZN14AcCourseSelect12getPointInfoEv = 0x002D1AF4;
_ZN14AcCourseSelect12getRouteInfoEv = 0x002D2644;
_ZN14AcCourseSelect11getRotationERKN4sead7Vector3IfEES4_ = 0x002D1944;

_ZN14AcCourseSelect6CsInfo9PointInfo8getPointEj = 0x002D5148;
_ZN14AcCourseSelect6CsInfo9PointInfo8getPointERKN4sead14SafeStringBaseIcEE = 0x002D5354;

_ZN12GameInputMgr5inputE = 0x0069E7B8;

_ZN14AcCourseSelect20getPointTypeFromNameEN4sead14SafeStringBaseIcEE = 0x002D2D2C;

_ZN14AcCourseSelect20CourseSelectBsCamera8instanceE = 0x005E5738;

_ZN14AcCourseSelect18CourseSelectPlayer12setAnimationEj = 0x002C873C;
_ZN14AcCourseSelect18CourseSelectPlayer11setRotationERKi = 0x002C85D4;
_ZN14AcCourseSelect18CourseSelectPlayer18routeTargetReachedEv = 0x002CA758;
_ZN14AcCourseSelect18CourseSelectPlayer7playSfxEj = 0x002CAC58;

_ZN14AcCourseSelect18CourseSelectPlayer12StateID_WaitE = 0x0060A114;

_ZN14AcCourseSelect10CsActorMgr8instanceE = 0x005E5B28;
_ZN14AcCourseSelect10CsActorMgr11createActorEtRKN4sead7Vector3IfEEhhj = 0x002D34B0;
_ZN14AcCourseSelect17GetCurrentWorldIdEv = 0x002D1B74;
_ZN14AcCourseSelect16GetCurrentNodeIdEv = 0x002D1C58;


/* nw::snd */

/* nw::snd::internal::BasicSound */
_ZN2nw3snd8internal10BasicSound6FadeInEi = 0x0019A29C;
_ZN2nw3snd8internal10BasicSound5PauseEbi = 0x0019A0E0;
_ZN2nw3snd8internal10BasicSound4StopEi = 0x00199FCC;

_ZN2nw3snd8internal10BasicSound6SetPanEf = 0x0019A2DC;
_ZN2nw3snd8internal10BasicSound10SetPanModeENS0_7PanModeE = 0x0019E194;
_ZN2nw3snd8internal10BasicSound8SetPitchEf = 0x0019A8E4;
_ZN2nw3snd8internal10BasicSound9SetVolumeEfi = 0x0019A8F8;
_ZN2nw3snd8internal10BasicSound15SetBiquadFilterEif = 0x00199E64;

/* nw::snd::SoundHandle */
_ZNK2nw3snd11SoundHandle15IsAttachedSoundEv = 0x004B0CFC;
_ZN2nw3snd11SoundHandle11DetachSoundEv = 0x00195A6C;

/* nw::lyt */
_ZN2nw3lyt7TextBox9SetStringEPKwt = 0x00194534;


/* m2d */

/* m2d::Anm_c */
_ZN3m2d5Anm_cC1Ev = 0x0038EBD0;
_ZN3m2d5Anm_cD1Ev = 0x0047E0D4;
_ZN3m2d5Anm_cD2Ev = 0x0047E0D4;
_ZN3m2d5Anm_c5buildEPKcPNS_8ResAcc_cE = 0x0047DE5C;
_ZN3m2d5Anm_c6updateEv = 0x0047DD1C;
_ZN3m2d5Anm_c10sub_38EBA0Eb = 0x0038EBA0;
_ZN3m2d5Anm_c10sub_4B347CEv = 0x004B347C;
_ZN3m2d5Anm_c8setFrameEf = 0x0047E07C;

/* m2d::EmbedLayoutBase_c */
_ZN3m2d17EmbedLayoutBase_cD1Ev = 0x0047DC8C;
_ZN3m2d17EmbedLayoutBase_cD2Ev = 0x0047DC8C;
_ZN3m2d17EmbedLayoutBase_c5buildEPKcPNS_8ResAcc_cEj = 0x0047D9D4;
_ZN3m2d17EmbedLayoutBase_c7bindAnmEPNS_5Anm_cEPv = 0x0047CFB8;
_ZN3m2d17EmbedLayoutBase_c9unbindAnmEPNS_5Anm_cEPv = 0x0047D284;
_ZN3m2d17EmbedLayoutBase_c12unbindAllAnmEv = 0x0047D0B0;
_ZN3m2d17EmbedLayoutBase_c8getGroupEPKc = 0x0018F32C;
_ZN3m2d17EmbedLayoutBase_c10getTextBoxEPKc = 0x0047D498;
_ZN3m2d17EmbedLayoutBase_c10getPictureEPKc = 0x0047D43C;

/* m2d::EmbedLayout_c */
_ZN3m2d13EmbedLayout_cC1Ev = 0x0038D4C4;
_ZN3m2d13EmbedLayout_cD1Ev = 0x0047DC88;
_ZN3m2d13EmbedLayout_cD2Ev = 0x0047DC88;
_ZN3m2d13EmbedLayout_c9getGroupsEPPvPKN4sead14SafeStringBaseIcEERj = 0x0038D1B8;
_ZN3m2d13EmbedLayout_c12getTextBoxesEPPvPKN4sead14SafeStringBaseIcEERj = 0x0038D3A0;
_ZN3m2d13EmbedLayout_c11getPicturesEPPvPKN4sead14SafeStringBaseIcEERj = 0x0038D290;
_ZN3m2d13EmbedLayout_c6updateEv = 0x0038D4A8;

/* m2d::ResAccLoader_c */
_ZN3m2d14ResAccLoader_c7loadArcERKN4sead14SafeStringBaseIcEE = 0x0038C1C0;
_ZN3m2d14ResAccLoader_c9unloadArcERKN4sead14SafeStringBaseIcEE = 0x0038C490;
_ZN3m2d14ResAccLoader_c15getResAccByNameERKN4sead14SafeStringBaseIcEE = 0x0038C154;
_ZN3m2d14ResAccLoader_c8instanceE = 0x005EF7C8;

/* m2d::DrawMgr_c */
_ZN3m2d9DrawMgr_c11getInstanceEv = 0x0038EBFC;


/* Renderer */
_ZN8RendererC1Ev = 0x00429A90;
_ZN8Renderer14createInstanceEPN4sead4HeapE = 0x00429264;
_ZN8Renderer9sInstanceE = 0x005E74F0;
_ZN8Renderer10initializeEv = 0x00428F78;
_ZN8Renderer11setViewRectERKN4sead9BoundBox2IfEE = 0x004290B4;
_ZN8Renderer12updateCameraEv = 0x004290D8;
_ZN8Renderer9drawModelEP20SkeletalModelWrapper = 0x00429A1C;
_ZN8Renderer8drawTileEtRKN4sead7Vector3IfEE = 0x00429370;
_ZN8Renderer8drawTileEtRKN4sead7Vector3IfEERKiS4_ = 0x004293D8;
_ZN8Renderer14drawTileLayer3EtRKN4sead7Vector3IfEERKiS4_ = 0x004292C0;
_ZN8Renderer8drawTileEtRKN4sead7Vector3IfEERKNS1_IiEES4_ = 0x00429474;
_ZN8Renderer8drawTileEtRKN4sead7Vector3IfEES4_PPS2_S6_ = 0x004294F8;

/* Renderer::SingletonDisposer_ */
_ZTVN8Renderer18SingletonDisposer_E = 0x005CD250;
_ZN8Renderer18SingletonDisposer_D1Ev = 0x00429314;
_ZN8Renderer18SingletonDisposer_15sStaticDisposerE = 0x005E74F4;

/* Light */
_ZN5LightC1Ev = 0x003458E8;
_ZN5LightC2Ev = 0x003458E8;
_ZN5LightD1Ev = 0x00345938;
_ZN5Light4loadERKN4sead14SafeStringBaseIcEEj = 0x003455BC;
_ZN5Light6unloadEv = 0x003458DC;
_ZN5Light7executeEv = 0x003458D0;


/* EventBase */
_ZN9EventBaseC1Ev = 0x00437950;
_ZN9EventBaseC2Ev = 0x00437950;
_ZNK9EventBase18getRuntimeTypeInfoEv = 0x004AE55C;
_ZN9EventBase3vf4Ev = 0x00000000;
_ZN9EventBase3vf8Ev = 0x00000000;
_ZN9EventBase5enterEv = 0x0043794C;
_ZN9EventBase7executeEv = 0x00437940;
_ZN9EventBase4exitEv = 0x00437948;
_ZN9EventBase4vf18Ev = 0x00000000;
_ZN9EventBase4vf1CEv = 0x00000000;
_ZN9EventBase6isJoinEP9ActorBase = 0x004AE5FC;

/* EventMgr */
_ZN8EventMgr8instanceE = 0x005E6EC8;
_ZN8EventMgr9pushEventEP9EventBase = 0x0040CBC8;
_ZNL8EventMgr6isJoinEP9ActorBase = 0x004AD690;

/* QuakeMgr */
_ZN8QuakeMgr8instanceE = 0x005E7198;
_ZN8QuakeMgr5quakeEjbj = 0x00428B78;
_ZN8QuakeMgr8UnkQuakeEcjbj = 0x00428A60;
_ZN8QuakeMgr9UnkQuake2Ecjj = 0x00428AE0;
_ZN8QuakeMgr9UnkQuake3Ejb = 0x00428B34;
_ZN8QuakeMgr9stopQuakeEv = 0x00428F60;

/* FragmentMgr */
_ZTVN11FragmentMgrE = 0x005A5C44;
_ZN11FragmentMgrD1Ev = 0x00227B30;
_ZN11FragmentMgrD2Ev = 0x00227B2C;
_ZN11FragmentMgr9sInstanceE = 0x005E6FA0;
_ZN11FragmentMgr14createInstanceEPN4sead4HeapE = 0x00227108;
_ZN11FragmentMgr14deleteInstanceEv = 0x00227198;
_ZN11FragmentMgr17createWaterSplashERKN4sead7Vector3IfEE16WaterSplashFlagsS2_ = 0x002271E4;
_ZN11FragmentMgr18createCoinFragmentERKN4sead7Vector3IfEE24CoinFragmentHitDirectionibbb = 0x00227320;
_ZN11FragmentMgr19createBlockFragmentERKN4sead7Vector3IfEE18BlockFragmentFlagsi = 0x0022742C;
_ZN11FragmentMgr18createPipeFragmentERKN4sead7Vector3IfEE17PipeFragmentFlagsi = 0x00227534;
_ZN11FragmentMgr22createBigBlockFragmentERKN4sead7Vector3IfEEN16BigBlockFragment4TypeE = 0x0022763C;
_ZN11FragmentMgr22createCoinTailFragmentERKN4sead7Vector3IfEE = 0x00227728;
_ZN11FragmentMgr32createBigBlockFragmentUnderwaterERKN4sead7Vector3IfEEN16BigBlockFragment4TypeE = 0x0022780C;
_ZN11FragmentMgr4drawEv = 0x002278FC;
_ZN11FragmentMgr5resetEv = 0x00227954;
_ZN11FragmentMgr7executeEv = 0x002279C4;
_ZN11FragmentMgr22createFragmentUnitHeapEPN4sead4HeapE = 0x00227ACC;

/* FragmentMgr::SingletonDisposer_ */
_ZTVN11FragmentMgr18SingletonDisposer_E = 0x005A5C34;
_ZN11FragmentMgr18SingletonDisposer_15sStaticDisposerE = 0x005E6FA4;
_ZN11FragmentMgr18SingletonDisposer_D1Ev = 0x002272D0;

/* Fragment */
_ZTV8Fragment = 0x005CB510;
_ZN8Fragment8onCreateEv = 0x0;
_ZN8Fragment9onExecuteEv = 0x002568AC;
_ZN8Fragment6onDrawEv = 0x002568A4;
_ZN8Fragment8onDeleteEv = 0x002568A8;

/* BigBlockFragment */
_ZN16BigBlockFragmentC1EPN4sead4HeapERKNS0_7Vector3IfEEj = 0x0031AE04;
_ZN16BigBlockFragment17updateModelMatrixEv = 0x0031A728;
_ZN16BigBlockFragment8onCreateEv = 0x0031A848;
_ZN16BigBlockFragment9onExecuteEv = 0x0031AC88;
_ZN16BigBlockFragment6onDrawEv = 0x0031A7F8;
_ZN16BigBlockFragment8onDeleteEv = 0x0031AC38;
/* _ZN16BigBlockFragment14sResourceNamesE = 0x006123BC; */
/* _ZN16BigBlockFragment11sModelNamesE = 0x0061243C; */
_ZN16BigBlockFragment18sRotationIncrementE = 0x005E6F10;

/* CoinOrigin */
_ZN10CoinOrigin8instanceE = 0x005E9A88;

/* ActorCoinMgr */
_ZN12ActorCoinMgrC1Ev = 0x00251AF0;
_ZN12ActorCoinMgr14createInstanceEPN4sead4HeapE = 0x00250A3C;
_ZN12ActorCoinMgr14deleteInstanceEv = 0x00250A9C;
_ZN12ActorCoinMgr9sInstanceE = 0x005E79E0;
_ZN12ActorCoinMgr12collectCoinsERKN4sead7Vector2IfEEji = 0x00250994;
_ZN12ActorCoinMgr11collectCoinERKN4sead7Vector2IfEENS_8CoinTypeEi = 0x00250AE0;
_ZN12ActorCoinMgr7executeEv = 0x00250C90;
_ZN12ActorCoinMgr24registerBlueCoinLocationEj = 0x00250D64;
_ZN12ActorCoinMgr22incrementBlueCoinCountEj = 0x00250FB4;
_ZN12ActorCoinMgr23incrementBlueCoinTargetEj = 0x00251028;
_ZN12ActorCoinMgr23decrementBlueCoinTargetEj = 0x00251378;
_ZN12ActorCoinMgr17resetBlueCoinInfoEv = 0x002514DC;
_ZN12ActorCoinMgr23handleBlueCoinCollectedERKN4sead7Vector2IfEE = 0x0025121C;
_ZN12ActorCoinMgr14createCoinJumpERKNS_12CoinJumpInfoEbb = 0x0025105C;
_ZN12ActorCoinMgr19handleCoinCollectedERKN4sead7Vector2IfEEiNS_8CoinTypeE = 0x0025199C;
_ZN12ActorCoinMgr18createCoinJumpFireERKNS_12CoinJumpInfoE = 0x00251540;
_ZN12ActorCoinMgr19createCoinJumpFunkaERKNS_12CoinJumpInfoE = 0x002516A4;
_ZN12ActorCoinMgr20createCoinJumpFunsuiERKNS_12CoinJumpInfoE = 0x00251808;
_ZN12ActorCoinMgr20createCoinShowerJumpERKN4sead7Vector3IfEEiihiib = 0x002513D0;
_ZN12ActorCoinMgr4unk1ERKN4sead7Vector2IfEEii = 0x00250B54;
_ZN12ActorCoinMgr4unk2ERKN4sead7Vector2IfEENS_8CoinTypeEi = 0x00250F04;
_ZN12ActorCoinMgr4unk3Ev = 0x00251950;

/* ActorCoinMgr::SingletonDisposer_ */
_ZTVN12ActorCoinMgr18SingletonDisposer_E = 0x005A8CC0;
_ZN12ActorCoinMgr18SingletonDisposer_D2Ev = 0x00250C5C;
_ZN12ActorCoinMgr18SingletonDisposer_15sStaticDisposerE = 0x005E79E4;

/* ActorCoinMgr::UnkA */
_ZN12ActorCoinMgr4UnkAC1Ev = 0x00250ADC;

/* ActorCoinMgr::UnkB */
_ZN12ActorCoinMgr4UnkBC1Ev = 0x00250AD8;

/* MessageMgr */
_ZN10MessageMgr8instanceE = 0x005E9DA8;
_ZN10MessageMgr4loadERKN4sead14SafeStringBaseIcEE = 0x00395C20;
_ZN10MessageMgr6unloadERKN4sead14SafeStringBaseIcEE = 0x00395CE8;
_ZN10MessageMgr9getHandleERKN4sead14SafeStringBaseIcEE = 0x00395D40;
_ZN10MessageMgr14getLanguageIdxEv = 0x0010309C;
_ZN10MessageMgr16getLanguageByIdxEj = 0x00103168;
_ZN10MessageMgr6Handle3getEPKc = 0x0012E210;

/* ScoreMgr */
_ZN8ScoreMgr9sInstanceE = 0x005E7268;
_ZN8ScoreMgr14createInstanceEPN4sead4HeapE = 0x0042C5B0;
_ZN8ScoreMgr14deleteInstanceEPv = 0x0042C614;
_ZN8ScoreMgr7addLifeEahb = 0x0042C4C4;
_ZN8ScoreMgr8addCoinsERKN4sead7Vector3IfEENS_8CoinTypeEab = 0x0042C43C;
_ZN8ScoreMgr11addScoreBigERKN4sead7Vector3IfEENS_13RewardTypeBigEa = 0x0042C52C;
_ZN8ScoreMgr6showX2ERKN4sead7Vector3IfEEab = 0x0042C6E4;
_ZN8ScoreMgr8addScoreENS_10RewardTypeEab = 0x0042C650;
_ZN8ScoreMgr8addScoreERKN4sead7Vector3IfEENS_10RewardTypeEab = 0x0042CA70;
_ZN8ScoreMgr11addScoreAllERKN4sead7Vector3IfEENS_10RewardTypeE = 0x0042C714;
_ZN8ScoreMgr8addScoreERK9ActorBaseNS_10RewardTypeEaff = 0x0042C7A4;
_ZN8ScoreMgr8addCoinsERK9ActorBaseNS_8CoinTypeEaff = 0x0042C81C;
_ZN8ScoreMgr11addScoreBigERK9ActorBaseNS_13RewardTypeBigEaff = 0x0042C8C8;
_ZN8ScoreMgr11addScoreAllERK9ActorBaseNS_10RewardTypeEff = 0x0042C97C;
_ZN8ScoreMgr8showTimeERKN4sead7Vector3IfEENS_8TimeTypeEa = 0x0042CA3C;

/* ScoreMgr::SingletonDisposer_ */
_ZTVN8ScoreMgr18SingletonDisposer_E = 0x005CD328;
_ZN8ScoreMgr18SingletonDisposer_D1Ev = 0x0042C7E8;
_ZN8ScoreMgr18SingletonDisposer_15sStaticDisposerE = 0x005E726C;

/* BigRedFramework */
_ZN15BigRedFramework11getInstanceEv = 0x0013A77C;


nnnstdMemCpy = 0x00114620;


/* nw::gfx ----------------------------------------------------------- */
_ZN2nw3gfx3res16ResTextureMapper10SetTextureENS1_10ResTextureE = 0x0018156C;

/* gfx::AnimBinding */
_ZN2nw3gfx11AnimBindingD1Ev = 0x00167DD8;
_ZN2nw3gfx11AnimBindingD2Ev = 0x00167DD8;

/* gfx::AnimGroup */
_ZN2nw3gfx9AnimGroupD1Ev = 0x0018D984;
_ZN2nw3gfx9AnimGroupD2Ev = 0x0018D984;
_ZN2nw3gfx9AnimGroupC1ENS_4anim3res12ResAnimGroupEPNS0_9SceneNodeEPNS_2os10IAllocatorE = 0x0018D8D8;
_ZN2nw3gfx9AnimGroup10InitializeEb = 0x0018CA54;
_ZN2nw3gfx9AnimGroup26GetMemorySizeForInitializeEPNS_2os20MemorySizeCalculatorENS_4anim3res12ResAnimGroupEb = 0x0018D834;

/* gfx::AnimObject */
_ZN2nw3gfx10AnimObject10s_TypeInfoE = 0x005F32C0;

/* gfx::CalculatedTransform */
_ZNK2nw3gfx19CalculatedTransform8IdentityEv = 0x0017A90C;
_ZN2nw3gfx19CalculatedTransform5SetupENS0_3res7ResBoneE = 0x0017A628;
_ZN2nw3gfx19CalculatedTransform20UpdateTranslateFlagsEv = 0x0017A3A4;
_ZN2nw3gfx19CalculatedTransform20UpdateCompositeFlagsEv = 0x0017A370;
_ZN2nw3gfx19CalculatedTransform17UpdateRotateFlagsEv = 0x0017A26C;
_ZN2nw3gfx19CalculatedTransform12SetTransformERKN2nn4math10Transform3E = 0x0017A034;
_ZN2nw3gfx19CalculatedTransform11UpdateFlagsEv = 0x00179CF4;

/* gfx::Model */
_ZN2nw3gfx5ModelD1Ev = 0x00186CD4;
_ZN2nw3gfx5ModelD2Ev = 0x00186CD4;
_ZN2nw3gfx5Model18GetRuntimeTypeInfoEv = 0x0048E054;
_ZN2nw3gfx5Model10InitializeEPNS_2os10IAllocatorE = 0x00185098;
_ZN2nw3gfx5Model15CreateCallbacksEPNS_2os10IAllocatorE = 0x001852A4;
_ZN2nw3gfx5Model15CreateMaterialsEPNS_2os10IAllocatorE = 0x00185530;
_ZN2nw3gfx5Model15CreateResMeshesEPNS_2os10IAllocatorE = 0x00185740;
_ZN2nw3gfx5Model16BindMaterialAnimEPNS_3gfx9AnimGroupE = 0x00185A44;
_ZN2nw3gfx5Model16CreateAnimGroupsEPNS_2os10IAllocatorE = 0x00185CC8;
_ZN2nw3gfx5Model18BindVisibilityAnimEPNS_3gfx9AnimGroupE = 0x00185EB0;
_ZN2nw3gfx5Model29CreateResMeshNodeVisibilitiesEPNS_2os10IAllocatorE = 0x0018653C;
_ZN2nw3gfx5Model6AcceptEPNS0_13ISceneVisitorE = 0x001868A0;
_ZN2nw3gfx5Model6CreateEPNS0_9SceneNodeENS0_3res14ResSceneObjectERKNS1_11DescriptionEPNS_2os10IAllocatorE = 0x001868F4;

/* gfx::SceneNode */
_ZN2nw3gfx9SceneNode18GetRuntimeTypeInfoEv = 0x0048E14C;
_ZN2nw3gfx9SceneNode10s_TypeInfoE = 0x005F3498;

_ZN2nw3gfx9SceneNodeD1Ev = 0x0018E7E0;
_ZN2nw3gfx9SceneNodeD2Ev = 0x0018E7E0;

_ZN2nw3gfx9SceneNode19IsCircularReferenceEPKS1_ = 0x0048E158;
_ZN2nw3gfx9SceneNode6AcceptEPNS0_13ISceneVisitorE = 0x0018E56C;
_ZN2nw3gfx9SceneNode6CreateEPS1_NS0_3res14ResSceneObjectERKNS1_11DescriptionEPNS_2os10IAllocatorE = 0x0018E5C0;

_ZN2nw3gfx9SceneNode20TrackbackWorldMatrixEv = 0x0048E178;
_ZN2nw3gfx9SceneNode23TrackbackWorldTransformEv = 0x0048E234;
_ZN2nw3gfx9SceneNode23TrackbackLocalTransformEv = 0x0048E1A4;

_ZN2nw3gfx9SceneNode10InitializeEPNS_2os10IAllocatorE = 0x0018DA68;

_ZN2nw3gfx9SceneNode11AttachChildEPS1_ = 0x0018DAC0;

_ZN2nw3gfx9SceneNode17CreateAnimBindingEPNS_2os10IAllocatorE = 0x0018E174;
_ZN2nw3gfx9SceneNode15CreateCallbacksEPNS_2os10IAllocatorE = 0x0018E028;
_ZN2nw3gfx9SceneNode14CreateChildrenEPNS_2os10IAllocatorE = 0x0018DC20;

/* gfx::TransformNode */
_ZN2nw3gfx13TransformNode18GetRuntimeTypeInfoEv = 0x0048B668;
_ZN2nw3gfx13TransformNode6CreateEPNS0_9SceneNodeENS0_3res14ResSceneObjectERKNS1_11DescriptionEPNS_2os10IAllocatorE = 0x00173AEC;
_ZN2nw3gfx13TransformNode28InvalidateInverseWorldMatrixEv = 0x00173A8C;
_ZN2nw3gfx13TransformNode15UpdateTransformEPNS0_18WorldMatrixUpdaterEPNS0_12SceneContextE = 0x001B37AC;
_ZN2nw3gfx13TransformNode10InitializeEPNS_2os10IAllocatorE = 0x00173764;
_ZN2nw3gfx13TransformNode15CreateCallbacksEPNS_2os10IAllocatorE = 0x0017379C;
_ZN2nw3gfx13TransformNode26GetMemorySizeForInitializeEPNS_2os20MemorySizeCalculatorENS0_3res16ResTransformNodeENS1_11DescriptionE = 0x001738E8;
_ZN2nw3gfx13TransformNode6AcceptEPNS0_13ISceneVisitorE = 0x00173A98;
_ZN2nw3gfx13TransformNodeC1EPNS_2os10IAllocatorENS0_3res16ResTransformNodeERKNS1_11DescriptionE = 0x00173CB0;
_ZN2nw3gfx13TransformNodeD1Ev = 0x00174038;
_ZN2nw3gfx13TransformNodeD2Ev = 0x00174038;
_ZN2nw3gfx13TransformNode18InverseWorldMatrixEv = 0x0048B674;
_ZN2nw3gfx13TransformNode20TrackbackWorldMatrixEv = 0x0048B6D4;
_ZN2nw3gfx13TransformNode23TrackbackLocalTransformEv = 0x0048B6DC;
_ZN2nw3gfx13TransformNode23TrackbackWorldTransformEv = 0x0048B6E4;
/*-------------------------------------------------------------------- */

/* nw::ut::ResDicPatricia */
_ZNK2nw2ut14ResDicPatricia3GetEPKcj = 0x0048A410;

/* nw::ut::FloatColor */
_ZNK2nw2ut10FloatColor9ToPicaU32Ev = 0x0048A308;
