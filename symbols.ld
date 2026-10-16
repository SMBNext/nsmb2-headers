/* aeabi */
__aeabi_ldivmod = 0x00106D44;
__aeabi_uidivmod = 0x00119DC4;
__aeabi_uidiv = 0x00119DC4;
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

/* svc */
svcExitProcess = 0x00100F9C;
svcGetSystemTick = 0x001104BC;
svcGetProcessId = 0x001104A0;
svcBreak = 0x00114D6C;

/* Temp Zone. Sort/delete me */

_Z7playSfxjRKN4sead7Vector3IfEEb = 0x002147D0;
_Z7playSfxjRKN4sead7Vector2IfEEb = 0x00214750;
_Z7playSfxPKcRKN4sead7Vector3IfEEb = 0x0021465C; 
_Z18playSfxWhileCalledj13ActorUniqueIDRKN4sead7Vector3IfEE = 0x002144A8;
_Z18playSfxWhileCalledj13ActorUniqueIDRKN4sead7Vector2IfEE = 0x002142F8;
_Z18playSfxWhileCalledj13ActorUniqueIDRKN4sead7Vector2IfEEs = 0x002143A0;
_Z18playSfxWhileCalledPKc13ActorUniqueIDRKN4sead7Vector3IfEEs = 0x002142A4;
_Z17playSfxPositionaljRKN4sead7Vector2IfEEb = 0x00214118; 
_Z28playSfxPositionalWhileCalledj13ActorUniqueIDRKN4sead7Vector2IfEE = 0x00214070;
_Z7stopSfxji = 0x002145E8;
_Z9setSfxArgPN2nw3snd11SoundHandleEjis = 0x00214184;

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
_ZN5Mtx344copyEPS_PKS_ = 0x0011D3B8;
_ZN5Mtx348multiplyEPS_RKS_RKS_ = 0x0011D3B8;
_ZN5Mtx345identE = 0x006C3B40;
_ZN5Mtx348multiplyEPS_RKS_S2_ = 0x0011E4F0;

_ZN5Mtx446swapXYEv = 0x00469774;

playerMaxJumpHeight = 0x0057F314;
playerDescentRate = 0x0057F324;

playerPMeterMax = 0x0057FC80;
playerWhitePMeterMax = 0x0057FC82;
playerMaxFlightTime = 0x0057FC92;

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
_Z14FreeCourseHeapv = 0x00458034;
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


/* Unk33FB74 */
_ZN9Unk33FB74C1Ev = 0x0033FB74;
_ZN9Unk33FB74D1Ev = 0x00283540;


/* PtclMgr */
_ZTVN7PtclMgrE = 0x005C94AC;
_ZN7PtclMgr9sInstanceE = 0x005E6190;
_ZN7PtclMgr4initEPN4sead4HeapE = 0x003F4110;
_ZN7PtclMgr10unk_3F437CEiPvPv = 0x003F437C;
_ZN7PtclMgr4drawEiPN4sead6CameraE = 0x003F4430;
_ZN7PtclMgr14createInstanceEPN4sead4HeapE = 0x003F4688;
_ZN7PtclMgr6unloadEv = 0x003F4788;
_ZN7PtclMgr16createEmitterSetEPN2nw4ptcl6HandleERKN4sead8Matrix34IfEEj = 0x003F4860;
_ZN7PtclMgr10unk_3F4908Ev = 0x003F4908;
_ZN7PtclMgr7executeEv = 0x003F4AC8;
_ZN7PtclMgr12setupForAreaEPN4sead4HeapE = 0x003F4DC0;
_ZN7PtclMgr5resetEv = 0x003F51A0;
_ZN7PtclMgrD1Ev = 0x003F526C;
_ZNK7PtclMgr8getParamEj = 0x004ABA24;

/* PtclMgr::SingetonDisposer_ */
_ZTVN7PtclMgr15sStaticDisposerE = 0x005C949C;
_ZN7PtclMgr18SingletonDisposer_D1Ev = 0x003F4810;
_ZN7PtclMgr18SingletonDisposer_15sStaticDisposerE = 0x005E6194;

/* PtclParamMgr */
_ZN12PtclParamMgrC1Ev = 0x0027CDDC;
_ZN12PtclParamMgr9loadParamEPN4sead4HeapE = 0x0027CD40;
_ZN12PtclParamMgr8getParamEj = 0x0049E550;

/* Effect */
_ZN6EffectC1Ev = 0x001D0A24;
_ZN6EffectC1Ej = 0x001D07D4;
_ZN6Effect11setEffectIdEj = 0x001D04C4;
_ZN6Effect8setScaleERKN4sead7Vector2IfEE = 0x001D062C;
_ZN6Effect15setLoopIntervalEf = 0x001D0694;
_ZN6Effect13getEmitterSetEv = 0x001D070C;
_ZN6Effect6removeEv = 0x001D0740;
_ZN6Effect4killEv = 0x001D0788;
_ZN6Effect6updateEPKN4sead7Vector3IfEEPKNS1_IiEES4_ = 0x001D0838;
_ZN6Effect6updateERK5Mtx34b = 0x001D0970;
_ZN6Effect7_updateEv = 0x001D0A44;
_ZN6Effect12createEffectEjPKN4sead7Vector3IfEEPKNS1_IiEES4_ = 0x0029FB2C;
_ZN6Effect18getRuntimeUserDataEv = 0x004974E4;
_ZN6Effect7isAliveEv = 0x00497510;

/* EffectUtil */
_ZN10EffectUtil12createEffectEjPKN4sead7Vector3IfEEPKNS1_IiEES4_ = 0x001D0B28;
_ZN10EffectUtil18createPlayerEffectEijPKN4sead7Vector3IfEEPKNS1_IiEES4_ = 0x001D0B80;
_ZN10EffectUtil18createPlayerEffectEiP13UnkEffectTypejPKN4sead7Vector3IfEEPKNS3_IiEES6_ = 0x001D0C00;
_ZN10EffectUtil18createPlayerEffectEiP6EffectjPKN4sead7Vector3IfEEPKNS3_IiEES6_ = 0x001D0C5C;

/* LevelEffect */
_ZN11LevelEffectC1Ev = 0x003125A0;
_ZN11LevelEffectD1Ev = 0x00312544;
_ZN11LevelEffect3vf0Ev = 0x0;
_ZN11LevelEffect3vf4Ev = 0x0;
_ZN11LevelEffect18getRuntimeTypeInfoEv = 0x004A31DC;
_ZZN11LevelEffect24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603984;

/* UnkEffect */
_ZN13UnkEffectTypeC1Ev = 0x00237100;
_ZN13UnkEffectTypeD1Ev = 0x00237118;
_ZN13UnkEffectType12createEffectEjPKN4sead7Vector3IfEEPKNS1_IiEES4_ = 0x00236E84;
_ZN13UnkEffectType12createEffectEjRKN4sead8Matrix34IfEEb = 0x00236F10;
_ZN13UnkEffectType6updateEPKN4sead7Vector3IfEEPKNS1_IiEES4_ = 0x00236FC0;
_ZN13UnkEffectType6updateERKN4sead8Matrix34IfEEb = 0x00237060;
_ZN13UnkEffectType18getRuntimeTypeInfoEv = 0x0049C628;
_ZZN13UnkEffectType24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006035A4;

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

/* nn::gr::CTR::RenderState */
_ZN2nn2gr3CTR11RenderStateC1Ev = 0x0010BE20;
_ZNK2nn2gr3CTR11RenderState11MakeCommandEPjb = 0x0010E900;
_ZN2nn2gr3CTR11RenderState18MakeDisableCommandEPjb = 0x00142DFC;

/* nn::gr::CTR::RenderState::Blend */
_ZNK2nn2gr3CTR11RenderState5Blend11MakeCommandEPjb = 0x00112F20;

/* nn::gr::CTR::RenderState::ShadowMap */
_ZNK2nn2gr3CTR11RenderState9ShadowMap11MakeCommandEPjbb = 0x00113204;

/* nn::gr::CTR::RenderState::AlphaTest */
_ZNK2nn2gr3CTR11RenderState9AlphaTest11MakeCommandEPjb = 0x0048784C;

/* nn::gr::CTR::RenderState::DepthTest */
_ZNK2nn2gr3CTR11RenderState9DepthTest11MakeCommandEPjb = 0x004878A4;

/* nn::gr::CTR::RenderState::Culling */
_ZNK2nn2gr3CTR11RenderState7Culling11MakeCommandEPjb = 0x004877CC;

/* nn::gr::CTR::RenderState::WBuffer */
_ZNK2nn2gr3CTR11RenderState7WBuffer11MakeCommandEPj = 0x00112FE4;

/* nn::gr::CTR::RenderState::FBAccess */
_ZNK2nn2gr3CTR11RenderState8FBAccess11MakeCommandEPjb = 0x0011747C;

/* nn::gr::CTR::Vertex */
_ZN2nn2gr3CTR6VertexC1Ev = 0x001443DC;
_ZN2nn2gr3CTR6Vertex12DisableAttr_EKj = 0x0014400C;
_ZNK2nn2gr3CTR6Vertex22MakeEnableAttrCommand_EPj = 0x00488358;
_ZN2nn2gr3CTR6Vertex17EnableAttrAsArrayERKNS1_17BindSymbolVSInputEj22PicaDataVertexAttrType = 0x00144118;
_ZN2nn2gr3CTR6Vertex22EnableInterleavedArrayERKNS2_14InterleaveInfoEKj = 0x00144248;
_ZNK2nn2gr3CTR6Vertex22MakeEnableAttrCommand_EPj = 0x00488358;
_ZNK2nn2gr3CTR6Vertex15MakeDrawCommandEPjRKNS2_11IndexStreamE = 0x004882B8;

/* nn::gr::CTR::LoadArray */
_ZN2nn2gr3CTR6Vertex9LoadArrayC1Ev = 0x001443D0;
_ZN2nn2gr3CTR6Vertex9LoadArray10DisableAllEv = 0x00144390;

/* nn::gr::CTR::AttrConst */
_ZN2nn2gr3CTR6Vertex9AttrConstC1Ev = 0x00144384;


/* gl */
__gl_state = 0x005F4F08;
g_cuBlendFunc = 0x005F4F0C;
__vbman = 0x005F4F30;
__shminpgID = 0x005F4BF4;
__shminshID = 0x005F4BF8;
__shman = 0x005F4BFC;
__dmpgl_allocator = 0x005F2EB0;
__dmpgl_deallocator = 0x005F2EB4;
__cb_current_command_buffer = 0x005F2EA0;
__cb_current_max_command_buffer = 0x005F2EA4;
__vldtr_validateAllState = 0x0053AB74;
__shv_preDraw = 0x004B9984;
arp_drawHostArrays = 0x0053AC04;

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

/* nn::cx */
_ZN2nn2cx12ReadUncompLZEPNS0_15UncompContextLZEPKvj = 0x0010B988;
_ZN2nn2cx19GetUncompressedSizeEPKv = 0x0010BC5C;
_ZN2nn2cx19InitUncompContextLZEPNS0_15UncompContextLZEPv = 0x0010BC8;

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
_ZN2nn3fnd8DateTimeC1Eiiiiiii = 0x001075B0;
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
_ZN2nn6applet17SetTransitionTypeENS0_14TransitionTypeE = 0x00107A50;
_ZN2nn6applet15CloseAppletHookEv = 0x00104384;
_ZN2nn6applet6handleE = 0x005F5000;
_ZN2nn6applet6detail14LockAndConnectEv = 0x00111EE4;
_ZN2nn6applet6detail19DisconnectAndUnlockEv = 0x0011205C;
_ZN2nn6applet6detail14AssignDspRightEb = 0x00111E94;
_ZN2nn6applet6detail17AssignCameraRightEb = 0x001124AC;
_ZN2nn6applet6detail14AssignGpuRightEb = 0x00107AD0;
_ZN2nn6applet6detail11SetInactiveEv = 0x00107ABC;

/* nn::os */
_ZN2nn2os6Thread9SleepImplENS_3fnd8TimeSpanE = 0x00110DB8;

/* nn::os::SharedMemoryBlock */
_ZN2nn2os17SharedMemoryBlock12AttachAndMapENS_6HandleEjb = 0x0011A754;
_ZN2nn2os17SharedMemoryBlock8FinalizeEv = 0x00107224;
_ZN2nn2os17SharedMemoryBlockD1Ev = 0x0014492C;
_ZN2nn2os17SharedMemoryBlockD2Ev = 0x0014492C; 

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

/* Applets */
_ZN7Applets23sShouldCloseApplicationE = 0x005E3038;

/* File Related */
_Z13TryDeleteFilePKw = 0x0013FE50;
_Z13TryCreateFilePKwx = 0x0013FDD4;
_Z11TryOpenFilePPvPKwj = 0x0013FC70;
_Z14TryGetFileSizePxPv = 0x0013FED4;
_Z11TryReadFilePiPvxS0_j = 0x0013FD04;
_Z12TryWriteFilePiPvxS0_jb = 0x0013FD64;
_Z8MountRomPKcjjPvjb = 0x00117F3C;
_Z8MountRomjjPvjb = 0x00114FD0;
_Z9MountSdmcPKc = 0x001416E0;
_Z7UnmountPKc = 0x0014155C;
_ZN4File8TryFlushEv = 0x001400B0;

_Z16TryOpenDirectoryPPvPKw = 0x0013FF48;
_Z14CloseDirectoryPv = 0x0013FEBC;
_Z16TryReadDirectoryPiPvP14DirectoryEntryi = 0x0013FFD4;

_Z10fileExistsPKc = 0x0012A884;
_Z23ensureSdDirectoryExistsRKN4sead14SafeStringBaseIcEE = 0x00485234;

/* SarcMgr */
_ZN7SarcMgr9sInstanceE = 0x005ED378;
_ZN7SarcMgr14createInstanceEPN4sead4HeapE = 0x00102908;
_ZN7SarcMgr14deleteInstanceEv = 0x003DE394;
_ZN7SarcMgr9close1814Ev = 0x003DE368;
_ZN7SarcMgr13getCourseFileERKN4sead14SafeStringBaseIcEEPj = 0x003DE0F0;
_ZN7SarcMgr7getFileERKN4sead14SafeStringBaseIcEES4_Pj = 0x003DE3F0;

/* sead::TextureCtrGL */
_ZN4sead12TextureCtrGLC1Ev = 0x0045CFA0;
_ZN4sead12TextureCtrGLC2Ev = 0x0045CFA0;
_ZN4sead12TextureCtrGLD1Ev = 0x0045CFE4;

_ZTVN4sead12TextureCtrGL = 0x005D13BC;

_ZN4sead12TextureCtrGL8getWidthEv = 0x004B106C;
_ZN4sead12TextureCtrGL9getHeightEv = 0x004B1074;
_ZN4sead12TextureCtrGL15getPhysicalAddrEv = 0x004B1034;
_ZN4sead12TextureCtrGL9getFormatEv = 0x004B0F18;

_ZN4sead12TextureCtrGL12loadFromCtpkEPvRKNS_14SafeStringBaseIcEEj = 0x003FCA04;
_ZN4sead12TextureCtrGL15loadFromArchiveERKNS_14SafeStringBaseIcEEijPNS_4HeapE = 0x0045C328;

/* sead::TextureCtrGR */
_ZN4sead12TextureCtrGRC1Ev = 0x0045D01C;
_ZN4sead12TextureCtrGRC2Ev = 0x0045D01C;
_ZN4sead12TextureCtrGRD1Ev = 0x0045BD20;

_ZTVN4sead12TextureCtrGR = 0x005D13E4;

_ZN4sead12TextureCtrGR8getWidthEv = 0x004B108C;
_ZN4sead12TextureCtrGR9getHeightEv = 0x004B1094;
_ZN4sead12TextureCtrGR15getPhysicalAddrEv = 0x004B1084;
_ZN4sead12TextureCtrGR9getFormatEv = 0x004B107C;

_ZN4sead12TextureCtrGR11loadFromResEPN2nw3gfx3res10ResTextureE = 0x003FAD00;

/* sead::RuntimeTypeInfo::Root */
_ZTVN4sead15RuntimeTypeInfo4RootE = 0x005D1C00;
_ZNK4sead15RuntimeTypeInfo4Root9isDerivedEPKNS0_9InterfaceE = 0x004B19C0;

/* sead::ListImpl */
_ZN4sead8ListImpl13pushFrontImplEPNS_8ListNodeE = 0x0047AB24;

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
_ZN4sead22BufferedSafeStringBaseIwE6appendERKNS_14SafeStringBaseIwEEi = 0x0055F654;

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
_ZN4sead10FileHandle17getCurrentSeekPosEv = 0x0045B49C;
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
_ZN4sead13FileDeviceMgr7tryLoadERNS_10FileDevice7LoadArgE = 0x0045E224;
_ZNK4sead13FileDeviceMgr10findDeviceERKNS_14SafeStringBaseIcEE = 0x00112858;
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

/* sead::ExpHeap */
_ZN4sead7ExpHeap9tryCreateEjRKNS_14SafeStringBaseIcEEPNS_4HeapENS5_13HeapDirectionEb = 0x00109D04;
_ZN4sead7ExpHeap7freeAllEv = 0x00478778;

/* vtable */
_ZTVN134sead7ExpHeapE = 0x005D2F68;

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

/* sead::GraphicsContext */
_ZTVN4sead15GraphicsContextE = 0x005D1BC0;
_ZN4sead15GraphicsContextC1Ev = 0x00109994;
_ZNK4sead15GraphicsContext5applyEv = 0x0010A600;

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
_ZN4sead15Matrix44CalcCtrIfE8multiplyERN2nn4math5MTX44ERKS4_S7_ = 0x0011E654;

/* sead::BoundBox3 */
_ZN4sead9BoundBox3IfEC1Ev = 0x002AF360;
_ZN4sead9BoundBox3IfEC1ERKNS_7Vector3IfEES5_ = 0x002AF304;

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

/* sead::CriticalSection */
_ZN4sead15CriticalSectionC0Ev = 0x00116DE4;
_ZN4sead15CriticalSectionC1Ev = 0x00116DE4;
_ZN4sead15CriticalSectionD0Ev = 0x0046071C;
_ZN4sead15CriticalSectionD1Ev = 0x0046071C;
_ZN4sead15CriticalSection4lockEv = 0x001152B8;
_ZN4sead15CriticalSection6unlockEv = 0x001193AC;


/* CourseTimer */
_ZN11CourseTimer9sInstanceE = 0x005E7138;
_ZN11CourseTimer14createInstanceEPN4sead4HeapE = 0x00224264;
_ZN11CourseTimer14deleteInstanceEv = 0x002242D4;
_ZN11CourseTimer18SingletonDisposer_D1Ev = 0x00224310;
_ZN11CourseTimer15sStaticDisposerE = 0x005E713C;
_ZTVN11CourseTimer18SingletonDisposer_E = 0x005A5074;

_ZN11CourseTimer11getTimeLeftEv = 0x0049BC24;
_ZN11CourseTimer7addTimeEj = 0x002243E8;
_ZN11CourseTimer7setTimeEj = 0x00224478;
_ZN11CourseTimer12setTimeLimitEj = 0x00224430;

/* CourseActorMgr */
_ZN14CourseActorMgr10searchByIdE13ActorUniqueID = 0x00496C0C;
_ZN14CourseActorMgr17searchByProfileIdEj = 0x004AD248;
_ZN14CourseActorMgr17searchByProfileIdEjP9ActorBase = 0x00496D50;
_ZN14CourseActorMgr16countByProfileIdEj = 0x00496E58;
_ZN14CourseActorMgr9sInstanceE = 0x005E2D18;
_ZN14CourseActorMgr14createInstanceEPN4sead4HeapE = 0x003FD554;
_ZN14CourseActorMgr14deleteInstanceEv = 0x003FD5E4;
_ZN14CourseActorMgr18SingletonDisposer_D1Ev = 0x003FD6B0;
_ZN14CourseActorMgr15sStaticDisposerE = 0x005E2D1C;
_ZTVN14CourseActorMgr18SingletonDisposer_E = 0x005C9CA8;
_ZN14CourseActorMgr6createEPN9ActorBase10CreateInfoE = 0x00430C70;

/* ActorCreateMgr */
_ZN14ActorCreateMgr9sInstanceE = 0x005E2CE0;
_ZN14ActorCreateMgr14createInstanceEPN4sead4HeapE = 0x002E2A44;
_ZN14ActorCreateMgr14deleteInstanceEv = 0x002E2B2C;
_ZN14ActorCreateMgr18SingletonDisposer_D1Ev = 0x002E2B78;
_ZN14ActorCreateMgr15sStaticDisposerE = 0x005E2CE4;
_ZTVN14ActorCreateMgr18SingletonDisposer_E = 0x005B17D4;

/* ActorStatus */
_ZN11ActorStatus9sInstanceE = 0x005E2E88;
_ZN11ActorStatus14createInstanceEPN4sead4HeapE = 0x00210DD4;
_ZN11ActorStatus14deleteInstanceEv = 0x00210E80;
_ZN11ActorStatus18SingletonDisposer_D1Ev = 0x00210EF4;
_ZN11ActorStatus15sStaticDisposerE = 0x005E2E8C;
_ZTVN11ActorStatus18SingletonDisposer_E = 0x005A3DA8;

/* ScrollEffect */
_ZN12ScrollEffectC1Ev = 0x0028367C;
_ZN12ScrollEffect7executeERN4sead7Vector2IfEES2_fff = 0x00283560;

/* PlayerBoundMgr::Interpolator */
_ZN14PlayerBoundMgr12InterpolatorC1Eh = 0x00348564;
_ZN14PlayerBoundMgr12Interpolator11interpolateEPfbfffff = 0x003482B4;
_ZN14PlayerBoundMgr12Interpolator10cubicCurveEf = 0x0040A364;

/* PlayerBound::Info */
_ZN11PlayerBound4InfoC1Ev = 0x0033FCB8;
_ZN11PlayerBound4InfoC2ERKS0_ = 0x0033FCB8;

/* PlayerBound */
_ZN11PlayerBoundC1Ev = 0x00346078;
_ZN11PlayerBound16sortPlayerBoundsEv = 0x0033FC50;
_ZN11PlayerBound18updatePlayerBoundsEv = 0x00345E80;
_ZN11PlayerBound17playersAreWarpingEv = 0x004A53D4;

/* PlayerBoundMgr */
_ZN14PlayerBoundMgrC1ERKN15PlayerWarpBoundE = 0x00337FCC;
_ZN14PlayerBoundMgr7executeERKN15PlayerWarpBoundERKN4sead9BoundBox2IfEE = 0x00337AC0;

/* AutoScrollMgr */
_ZN13AutoScrollMgr14getUnkPositionEv = 0x0049EBE0;

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
_ZN11BgScrollMgr16playerIsClimbingEv = 0x00204340;

/* BgScrollMgr::SingletonDisposer_ */
_ZN11BgScrollMgr18SingletonDisposer_D1Ev = 0x0021DC84;
_ZN11BgScrollMgr18SingletonDisposer_15sStaticDisposerE = 0x005ECF5C;
_ZTVN11BgScrollMgr18SingletonDisposer_E = 0x005A44D8;

/* BgScrollMgr_C4 */
_ZN14BgScrollMgr_C417zoomToEventTargetERfS0_ = 0x0049E818;
_ZN14BgScrollMgr_C415isCenteredZoneXEv = 0x0049E8CC;

_ZN14BgScrollMgr_C420getPlayerBoundScalarEv = 0x004A3480;
_ZN14BgScrollMgr_C414getBlendFactorEv = 0x0049E910;

/* BgScrollMgr_C4::CameraSettings */
_ZN14BgScrollMgr_C414CameraSettings21getUnkYExpandingFloatEb = 0x004B00F0;
_ZN14BgScrollMgr_C414CameraSettings24getUnkYExandingFloatInitEb = 0x004AFFE0;

/* ZoomEtc::Unk4 */
_ZN7ZoomEtc4Unk414getZoneCenterXEv = 0x002043CC;

_ZN7ZoomEtc4Unk421setZoomToCloserTargetEfP14BgScrollMgr_C4 = 0x003381AC;
_ZN7ZoomEtc4Unk420setWidthHeightToZoomEv = 0x003380AC;
_ZN7ZoomEtc4Unk419setZoomToBoundWidthERKN4sead9BoundBox2IfEE = 0x0033808C;
_ZN7ZoomEtc4Unk420setViewYToZoneBottomEv = 0x00338234;

_ZN7ZoomEtc4Unk427clampViewToScrollableBoundXERKN4sead9BoundBox2IfEE = 0x003381C4;
_ZN7ZoomEtc4Unk427clampViewToScrollableBoundYERKN4sead9BoundBox2IfEE = 0x003381FC;

_ZN7ZoomEtc4Unk419handleDemoGoalEventERKN4sead9BoundBox2IfEEPv = 0x003380D4;

_ZN7ZoomEtc4Unk419getCloserZoomTargetEfP14BgScrollMgr_C4 = 0x0049E8B8;
_ZN7ZoomEtc4Unk415smoothLookaheadEPff = 0x00345C74;

/* ZoomEtc::Unk4::TrackerX */
_ZN7ZoomEtc4Unk48TrackerX4calcEPfRKN4sead9BoundBox2IfEEbfffffffP14PlayerBoundMgr = 0x002A706C;

/* ZoomEtc::Unk4::TrackerY */
_ZN7ZoomEtc4Unk48TrackerY4calcEPfRKN4sead9BoundBox2IfEEP14BgScrollMgr_C4fffffffP14PlayerBoundMgrb = 0x002F8774;

/* ZoomEtc::Unk4::ZoomHolder */
_ZN7ZoomEtc4Unk410ZoomHolder7executeEP14BgScrollMgr_C4P14PlayerBoundMgr = 0x00456E2C;
_ZN7ZoomEtc4Unk410ZoomHolder7getStepEfffff = 0x0040A1D4;

/* ZoomEtc::Unk4::VerticalScroll */
_ZN7ZoomEtc4Unk414VerticalScrollC1ERKN6Course10ScrollDataE = 0x00337994;
_ZN7ZoomEtc4Unk414VerticalScrollC2ERKN6Course10ScrollDataE = 0x00337994;

_ZN7ZoomEtc4Unk414VerticalScroll6updateEv = 0x003378A4;
_ZN7ZoomEtc4Unk414VerticalScroll14getDistOutsideEbfff = 0x00317BFC;
_ZN7ZoomEtc4Unk414VerticalScroll11toViewSpaceEPfPff = 0x004A4BFC;

/* LookaheadMgr */
_ZN12LookaheadMgr7executeEP14PlayerBoundMgrbN11BgScrollMgr10CameraModeE = 0x0033FBB4;

/* CourseBgInfoMgr */
_ZN15CourseBgInfoMgr9sInstanceE = 0x005E6FC8;
_ZN15CourseBgInfoMgr14createInstanceEPN4sead4HeapE = 0x001C7A64;
_ZN15CourseBgInfoMgr14deleteInstanceEv = 0x001C7AC4;

_ZN15CourseBgInfoMgr12loadCourseBgEv = 0x001C7B88;
_ZN15CourseBgInfoMgr9getBgNameEv = 0x001C7B6C;

bgAudioFxPresetIds = 0x005E6FE0;


/* CourseData */
_ZN10CourseData9sInstanceE = 0x005E9AA8;
_ZN10CourseData7getFileEh = 0x001CECBC;
_ZN10CourseData4loadEv = 0x001CEB30;
_ZN10CourseData14createInstanceEPN4sead4HeapE = 0x001CEA80;
_ZN10CourseData14deleteInstanceEv = 0x001CEAF0;
_ZN10CourseData13getCourseNameEPN4sead19FixedSafeStringBaseIcLi8EEEhhh = 0x001CEBD8;
_ZN10CourseData14unloadTilesetsEv = 0x00201110;

/* CourseData::SingletonDisposer_ */
_ZTVN10CourseData18SingletonDisposer_E = 0x0059F198;
_ZN10CourseData18SingletonDisposer_D1Ev = 0x001CEC88;
_ZN10CourseData18SingletonDisposer_15sStaticDisposerE = 0x005E9AAC;

/* Course */
_ZN6Course27findLocationContainingPointEPhRKN4sead7Vector3IfEEff = 0x004AAB14;
_ZN6Course17getBackgroundByIdEt = 0x004AABF0;
_ZN6Course15getEntranceByIdEh = 0x004AAC2C;
_ZN6Course11getZoneByIdEhPN4sead9BoundBox2IfEE = 0x004AAD34;
_ZN6Course11getPathByIdEh = 0x004AADA4;
_ZN6Course17getScrollDataByIdEt = 0x004AADE0;
_ZN6Course15getLocationByIdEPN4sead9BoundBox2IfEEh = 0x004AAE1C;
_ZN6Course16getPathNodesByIdEh = 0x004AAEDC;

/* StageInfo */
_ZN9StageInfo9sInstanceE = 0x005E72B0;
_ZN9StageInfo14createInstanceEPN4sead4HeapE = 0x00102E38;
_ZN9StageInfo24setCurrentToDestEntranceEv = 0x0043058C;

/* CourseId */
_Z19isCourseIdToadhousej = 0x002D261C;

/* NextGoto */
_ZN8NextGoto9sInstanceE = 0x005E9AE0;
_ZN8NextGoto14createInstanceEPN4sead4HeapE = 0x00422944;
_ZN8NextGoto14deleteInstanceEv = 0x004229D4;
_ZN8NextGoto18SingletonDisposer_D1Ev = 0x00422A14;
_ZN8NextGoto15sStaticDisposerE = 0x005E9AE4;
_ZTVN8NextGoto18SingletonDisposer_E = 0x005CC908;

_ZN8NextGoto21isDestinationMismatchEhh = 0x00422A48;
_ZN8NextGoto14setDestinationEhh = 0x00422AC0;

/* Unk5E9240 */
_ZN9Unk5E92409sInstanceE = 0x005E9240;
_ZN9Unk5E924014createInstanceEPN4sead4HeapE = 0x00314170;
_ZN9Unk5E924014deleteInstanceEv = 0x003141DC;
_ZN9Unk5E924018SingletonDisposer_D1Ev = 0x00314218;
_ZN9Unk5E924015sStaticDisposerE = 0x005E9244;
_ZTVN9Unk5E924018SingletonDisposer_E = 0x005B662C;


/* TileMgr */
_ZN7TileMgr8instanceE = 0x005E97FC;
_ZN7TileMgr11setTileTypeEttj = 0x00349538;
_ZN7TileMgr15getTileBehaviorEjjb = 0x00349C2C;
_ZN7TileMgr19requestLiquidSplashERKN4sead7Vector2IfEEt = 0x00349620;

/* LiquidTop ripple parameter tables, indexed by the splash type 0x00 - 0x0C */
_ZN9LiquidTop17cRippleWaveCountsE = 0x0057E000;
_ZN9LiquidTop19cRippleHeightScalesE = 0x0057E034;
_ZN9LiquidTop13cRippleSpeedsE = 0x0057E068;
_ZN9LiquidTop17cRippleFadeSpeedsE = 0x0057E09C;
_ZN9LiquidTop17cRippleFadeLimitsE = 0x0057E0D0;
_ZN9LiquidTop17cRippleFadePowersE = 0x0057E104;
_ZN9LiquidTop20cRippleMinAmplitudesE = 0x0057E138;


/* TileLayer */
_ZN9TileLayer6Layer1E = 0x005E9804;
_ZN9TileLayer10getTilePtrEjjPj = 0x004A7C70;


/* SaveMgr */
_ZN7SaveMgr9sInstanceE = 0x005ED3AC;
_ZN7SaveMgr8loadFileEhb = 0x004ABF38;
_ZN7SaveMgr9clearFileEh = 0x003F7C50;
_ZN7SaveMgr8copyFileEhh = 0x003FA864;
_ZN7SaveMgr8saveFileEhb = 0x003F8BB0;
_ZN7SaveMgr13setLastFileIdEh = 0x003F8B3C;
_ZN7SaveMgr5writeEv = 0x003FAA58;
_ZN7SaveMgr11getSaveDataEv = 0x004ABBF0;


/* GameState */
_ZN9GameState9sInstanceE = 0x005ED308;
_ZN9GameState14createInstanceEPN4sead4HeapE = 0x00102190;
_ZN9GameState14deleteInstanceEv = 0x00000000;
_ZN9GameState18SingletonDisposer_D1Ev = 0x001D6D00;
_ZN9GameState15sStaticDisposerE = 0x005ED30C;
_ZTVN9GameState18SingletonDisposer_E = 0x005A0800;

/* net::game::Mgr */
_ZN3net4game3Mgr13isCoopSessionEv = 0x001BF430;
_ZN3net4game3Mgr13playerIsGuestEv = 0x001C5248;

_ZN9GameState17isRainbowUnlockedEj = 0x00497C98;
_ZN9GameState17loadControlSchemeEv = 0x001D6D80;
_ZN9GameState20starCoinGateIsClosedEth = 0x001D6CEC;
_ZN9GameState12setMissCountEjjj = 0x001D6F3C;
_ZN9GameState18incrementMissCountEv = 0x001D7130;
_ZN9GameState14resetMissCountEv = 0x001D7098;

/* GameState::Flag */
_ZN9GameState4FlagC1Ev = 0x0011028C;

/* GameState::CourseFlags */
_ZN9GameState11CourseFlagsC1Ev = 0x0010B950;

/* GameState::StreetPassChallenger */
_ZN9GameState20StreetPassChallengerC1Ev = 0x00108958;

/* CollectionCoinSaveData */
_ZN22CollectionCoinSaveData11getForLevelEjj = 0x004A23C0;
_ZN22CollectionCoinSaveData11getForLevelEjjj = 0x004A2414;

/* CollectionCoinBase */
_ZN18CollectionCoinBase5setupEv = 0x003356C0;


/* LevelPlayerStateData */
_ZN20LevelPlayerStateData9sInstanceE = 0x005E7158;
_ZN20LevelPlayerStateData14createInstanceEPN4sead4HeapE = 0x001022B4;
_ZN20LevelPlayerStateData14deleteInstanceEv = 0x00000000;
_ZN20LevelPlayerStateData18SingletonDisposer_D1Ev = 0x0032FD48;
_ZN20LevelPlayerStateData15sStaticDisposerE = 0x005E715C;
_ZTVN20LevelPlayerStateData18SingletonDisposer_E = 0x005B92CC;


/* RNG */
_ZN3RNG8instanceE = 0x005ED360;
_ZN3RNG7randF32Ev = 0x003DDFE0;
_ZN3RNG7randF32Ef = 0x003DDFAC;
_ZN3RNG7randF32Eff = 0x003DDF04;
_ZN3RNG7randU32Ej = 0x003DE004;
_ZN3RNG7randS32Eii = 0x003DDF40;
_ZN3RNG8randBoolEv = 0x003DE01C;


/* SwitchFlagMgr */
_ZN13SwitchFlagMgr8makeMaskExj = 0x0011F160;
_ZN13SwitchFlagMgr11initForAreaEbh = 0x002A7EFC;
_ZN13SwitchFlagMgr3setEhjbbbj = 0x002A8080;
_ZN13SwitchFlagMgr11updateFlagsEv = 0x002A82C8;
_ZN13SwitchFlagMgr5resetEv = 0x002A84EC;
_ZN13SwitchFlagMgr11getFlagMaskEjj = 0x002A8564;
_ZN13SwitchFlagMgr14createInstanceEPN4sead4HeapE = 0x002A85AC;
_ZN13SwitchFlagMgr14deleteInstanceEv = 0x002A860C;
_ZN13SwitchFlagMgr14updateSwitchesEv = 0x002A8648;
_ZN13SwitchFlagMgr14getIndexOfMaskEj = 0x002A8850;
_ZN13SwitchFlagMgr17setLiquidMoveInfoEhRKNS_14LiquidMoveInfoE = 0x002A88D0;
_ZN13SwitchFlagMgr7executeEv = 0x002A8934;
_ZN13SwitchFlagMgr18resetFlagTimerInfoEv = 0x002A89D4;

_ZN13SwitchFlagMgr9sInstanceE = 0x005E9AF8;

/* SwitchFlagMgr::SingletonDisposer_ */
_ZTVN13SwitchFlagMgr18SingletonDisposer_E = 0x005AF3B4;
_ZN13SwitchFlagMgr18SingletonDisposer_D1Ev = 0x002A889C;
_ZN13SwitchFlagMgr18SingletonDisposer_15sStaticDisposerE = 0x005E9AFC;


/* PersistentDataMgr */
_ZN17PersistentDataMgr9sInstanceE = 0x005E7170;
_ZN17PersistentDataMgr14createInstanceEPN4sead4HeapE = 0x00345B68;
_ZN17PersistentDataMgr14deleteInstanceEv = 0x00345BC0;
_ZN17PersistentDataMgr18SingletonDisposer_D1Ev = 0x00345BFC;
_ZN17PersistentDataMgr15sStaticDisposerE = 0x005E7174;
_ZTVN17PersistentDataMgr18SingletonDisposer_E = 0x005BCD5C;

_ZN17PersistentDataMgr3getEff = 0x004A52D0;
_ZN17PersistentDataMgr3setEfft = 0x00345A6C;

/* UnkMgr_210B18 */
_ZN13UnkMgr_210B189sInstanceE = 0x005E75A8;
_ZN13UnkMgr_210B1814createInstanceEPN4sead4HeapE = 0x00210B18;
_ZN13UnkMgr_210B1814deleteInstanceEv = 0x00210B90;
_ZN13UnkMgr_210B1818SingletonDisposer_D1Ev = 0x00210B90;
_ZN13UnkMgr_210B1815sStaticDisposerE = 0x005E75AC;
_ZTVN13UnkMgr_210B1818SingletonDisposer_E = 0x005A3D98;

/* BgGlobal */
_ZN8BgGlobal9sInstanceE = 0x005E9820;
_ZN8BgGlobal14createInstanceEPN4sead4HeapE = 0x004015E4;
_ZN8BgGlobal14deleteInstanceEv = 0x00401640;
_ZN8BgGlobal18SingletonDisposer_D1Ev = 0x00401B24;
_ZN8BgGlobal15sStaticDisposerE = 0x005E9824;
_ZTVN8BgGlobal18SingletonDisposer_E = 0x005CA158;
_ZN8BgGlobal14getTilesetNameEhh = 0x004016B8;
_ZN8BgGlobal16loadTilesetNamesEv = 0x004016F4;
_ZN8BgGlobal13setObjectTileEPvj = 0x004A7DD8;

_ZN8BgGlobal15sStairSourceIdsE = 0x00619B88;
_ZN8BgGlobal13sStairDestIdsE = 0x00619B94;
_ZN8BgGlobal14sBounceTileIdsE = 0x0057EB60;
_ZN8BgGlobal16sJumpblockTileIdE = 0x0057EA4E;
_ZN8BgGlobal12sTileIdTableE = 0x00619ED4;

/* BgRenderer */
_ZN10BgRenderer9sInstanceE = 0x005E9878;
_ZN10BgRenderer14createInstanceEPN4sead4HeapE = 0x001CA59C;
_ZN10BgRenderer14deleteInstanceEv = 0x001CA604;
_ZN10BgRenderer4initEv = 0x001CA86C;
_ZN10BgRenderer10init3DInfoEv = 0x001CA738;
_ZN10BgRenderer4drawEv = 0x001CA6A8;
_ZN10BgRenderer13drawTileLayerEPN4sead9BoundBox2IfEEi = 0x001C9368;
_ZN10BgRenderer11addTileQuadEjtPN4sead7Vector3IfEES3_S3_S3_ = 0x001CA30C;
_ZN10BgRenderer19submitLayer0DrawCmdEv = 0x001C9358;
_ZN10BgRenderer19submitLayer1DrawCmdEv = 0x001C9360;
_ZN10BgRenderer19submitLayer2DrawCmdEv = 0x001C9848;
_ZN10BgRenderer19submitLayer3DrawCmdEv = 0x001CA650;
_ZN10BgRenderer18submitLayerDrawCmdEi = 0x001C9850;
_ZN10BgRenderer21submitBgSetupCommandsEv = 0x001CA7EC;
_ZN10BgRenderer16resetTexturePtrsEv = 0x001C995C;
_ZN10BgRenderer14paddedTileSizeE = 0x005E9880;
_ZN10BgRenderer8tileSizeE = 0x005E9884;
_ZN10BgRenderer11tilesPerRowE = 0x005E9888;
_ZN10BgRenderer11tilesPerColE = 0x005E988C;
_ZN10BgRenderer10tileSizeUvE = 0x005E9890;
_ZN10BgRenderer6xScaleE = 0x005E9898;
_ZN10BgRenderer6yScaleE = 0x005E989C;
_ZN10BgRenderer18SingletonDisposer_D1Ev = 0x001CA658;
_ZN10BgRenderer15sStaticDisposerE = 0x005E987C;
_ZTVN10BgRenderer18SingletonDisposer_E = 0x0059E798;

/* PointGetTop */
_ZN11PointGetTopC1Ev = 0x0031F6B4;
_ZN11PointGetTopD1Ev = 0x0031F79C;
_ZN11PointGetTop12StateID_ShowE = 0x0061B5D0;
_ZN11PointGetTop20initializeState_ShowEv = 0x0031F404;
_ZN11PointGetTop17executeState_ShowEv = 0x0031F134;
_ZN11PointGetTop18finalizeState_ShowEv = 0x0031F314;
_ZN11PointGetTop12StateID_RiseE = 0x0061B5F0;
_ZN11PointGetTop20initializeState_RiseEv = 0x0031F310;
_ZN11PointGetTop17executeState_RiseEv = 0x0031F030;
_ZN11PointGetTop18finalizeState_RiseEv = 0x0031F098;
_ZN11PointGetTop12StateID_HoldE = 0x0061B610;
_ZN11PointGetTop20initializeState_HoldEv = 0x0031F360;
_ZN11PointGetTop17executeState_HoldEv = 0x0031F09C;
_ZN11PointGetTop18finalizeState_HoldEv = 0x0031F304;
_ZN11PointGetTop15StateID_VisibleE = 0x0061B630;
_ZN11PointGetTop23initializeState_VisibleEv = 0x0031F498;
_ZN11PointGetTop20executeState_VisibleEv = 0x0031EF28;
_ZN11PointGetTop21finalizeState_VisibleEv = 0x0031F488;
_ZN11PointGetTop14StateID_AppearE = 0x0061B650;
_ZN11PointGetTop22initializeState_AppearEv = 0x0031F5FC;
_ZN11PointGetTop19executeState_AppearEv = 0x0031F320;
_ZN11PointGetTop20finalizeState_AppearEv = 0x0031F3DC;
_ZN11PointGetTop17StateID_DisappearE = 0x0061B670;
_ZN11PointGetTop25initializeState_DisappearEv = 0x0031F48C;
_ZN11PointGetTop22executeState_DisappearEv = 0x0031F36C;
_ZN11PointGetTop23finalizeState_DisappearEv = 0x0031F460;
_ZN11PointGetTop12StateID_IdleE = 0x0061B690;
_ZN11PointGetTop20initializeState_IdleEv = 0x0031F50C;
_ZN11PointGetTop17executeState_IdleEv = 0x0031F02C;
_ZN11PointGetTop18finalizeState_IdleEv = 0x0031F094;
_ZN11PointGetTop5buildEv = 0x0031E934;
_ZN11PointGetTop6updateEv = 0x0038D478;
_ZN11PointGetTop4drawEv = 0x0031F4BC;
_ZN11PointGetTop5resetEv = 0x0031F510;
_ZN11PointGetTop4showERKN4sead7Vector3IfEEjRKh = 0x0031EF8C;
_ZN11PointGetTop11setPositionERKN4sead7Vector3IfEE = 0x0031F4F0;
_ZN11PointGetTop9disappearEv = 0x0031F49C;
_ZN11PointGetTop6isIdleEv = 0x0031F670;
_ZN11PointGetTop14updatePositionEv = 0x0031ED40;
_ZN11PointGetTop11updatePulseEv = 0x0031EE58;
_ZN11PointGetTop14createX2EffectEv = 0x0031EF2C;

/* SmallScoreMgr */
_ZN13SmallScoreMgr9sInstanceE = 0x005E7280;
_ZN13SmallScoreMgr14createInstanceEPN4sead4HeapE = 0x002A79FC;
_ZN13SmallScoreMgr14deleteInstanceEv = 0x002A7A80;
_ZN13SmallScoreMgr6createEv = 0x002A7E48;
_ZN13SmallScoreMgr6updateEv = 0x002A7EC0;
_ZN13SmallScoreMgr4drawEv = 0x002A7E0C;
_ZN13SmallScoreMgr5resetEv = 0x002A77E0;
_ZN13SmallScoreMgr4showERKN4sead7Vector3IfEEjab = 0x002A7AE4;
_ZN13SmallScoreMgr4hideERKi = 0x002A7850;
_ZN13SmallScoreMgr9disappearERKi = 0x002A792C;
_ZN13SmallScoreMgr11setPositionERKN4sead7Vector3IfEERKi = 0x002A7BFC;
_ZN13SmallScoreMgr6isIdleERKi = 0x002A7CCC;

/* SoundRelated */
_ZTV12SoundRelated = 0x00599418;
_ZN12SoundRelated9sInstanceE = 0x005E30B0;
_ZN12SoundRelated14createInstanceEPN4sead4HeapE = 0x00106DA4;
_ZN12SoundRelated14deleteInstanceEv = 0x001393A4;
_ZN12SoundRelated13playGlobalSfxEj = 0x00139B0C;
_ZN12SoundRelated13holdGlobalSfxEj = 0x001399E0;
_ZN12SoundRelated9holdSoundEPN2nw3snd11SoundHandleEi = 0x001399D0;
_ZN12SoundRelated12prepareSoundEPN2nw3snd11SoundHandleEii = 0x0019688C;
_ZN12SoundRelated6fadeInEPKci = 0x00139C98;
_ZN12SoundRelated14getSfxNameByIdEj = 0x001390BC;
_ZN12SoundRelated14getSfxIdByNameEPKc = 0x001390CC;
_ZN12SoundRelated21getMusicStreamSoundIdEv = 0x00139C08;
_ZN12SoundRelated15setPlayerVolumeEjf = 0x00195F98;
_ZN12SoundRelated15getPlayerVolumeEj = 0x0013886C;
_ZN12SoundRelated18pauseAllSfxPlayersEi = 0x00138828;
_ZN12SoundRelated20unpauseAllSfxPlayersEi = 0x00138D44;
_ZN12SoundRelated19unmuteAllSfxPlayersEv = 0x00139838;
_ZN12SoundRelated20setPitchOfAllHandlesEf = 0x001388F4;
_ZN12SoundRelated21setVolumeOfAllHandlesEfi = 0x00138ABC;
_ZN12SoundRelated11pauseHandleEPN2nw3snd11SoundHandleEi = 0x001393F4;
_ZN12SoundRelated13unpauseHandleEPN2nw3snd11SoundHandleEi = 0x001397BC;
_ZN12SoundRelated16stopPlayerSoundsEji = 0x00195AD4;
_ZN12SoundRelated17pausePlayerSoundsEji = 0x00195B30;
_ZN12SoundRelated13stopSoundByIdEii = 0x004605B0;
_ZN12SoundRelated14stopAllHandlesEi = 0x00460568;
_ZN12SoundRelated21stopAndFreeHandleListEi = 0x00138DBC;
_ZN12SoundRelated16stopMusicStreamsEi = 0x0045C254;

/* SoundRelated::SingletonDisposer_ */
_ZN12SoundRelated18SingletonDisposer_15sStaticDisposerE = 0x005E30B4;
_ZTVN12SoundRelated18SingletonDisposer_E = 0x0059C488;

/* SoundRelated_28 */
_ZN15SoundRelated_2813getFreeHandleEv = 0x004B15A0;
_ZN15SoundRelated_2819allocHandleForActorE13ActorUniqueID = 0x00485F1C;
_ZN15SoundRelated_2817findOrAllocHandleEib = 0x004B1680;
_ZN15SoundRelated_2813getHandleByIdEib = 0x004B15F4;
_ZN15SoundRelated_2815findSoundHandleE13ActorUniqueIDjb = 0x00485F7C;
_ZN15SoundRelated_2813stopSoundByIdEii = 0x004605B8;

/* SndSceneMgr */
_ZN11SndSceneMgr9sInstanceE = 0x005E3450;
_ZN11SndSceneMgr14createInstanceEPN4sead4HeapE = 0x0028B808;
_ZN11SndSceneMgr14deleteInstanceEv = 0x0028C29C;
_ZN11SndSceneMgrD1Ev = 0x0028D098;
_ZN11SndSceneMgr18SingletonDisposer_D1Ev = 0x00000000;
_ZN11SndSceneMgr15sStaticDisposerE = 0x005E3454;
_ZTVN11SndSceneMgr18SingletonDisposer_E = 0x005AC934;

_ZN11SndSceneMgr7stopAllEv = 0x0028B3E0;
_ZN11SndSceneMgr19stopAllActorPlayersEv = 0x0028AEA4;
_ZN11SndSceneMgr9stopAudioEb = 0x0028B428;
_ZN11SndSceneMgr9stopMusicEv = 0x0028B358;
_ZN11SndSceneMgr12fadeOutAudioEv = 0x0028B4A0;
_ZN11SndSceneMgr12updateFxSendEv = 0x0028BA70;

_ZN11SndSceneMgr10pauseAudioEi = 0x0028C880;
_ZN11SndSceneMgr11resumeAudioEi = 0x0028CD60;
_ZN11SndSceneMgr17muteAllSfxPlayersEv = 0x0028B2CC;
_ZN11SndSceneMgr18muteForCourseClearEv = 0x0028ACD8;
_ZN11SndSceneMgr17setSystemExVolumeEf = 0x0028C62C;

_ZN11SndSceneMgr14playDialogueInEv = 0x0028CE80;
_ZN11SndSceneMgr18restoreMusicVolumeEv = 0x0028D07C;

_ZN11SndSceneMgr15playCourseMusicEv = 0x0028C960;
_ZN11SndSceneMgr13playBossMusicEv = 0x0028BEC8;
_ZN11SndSceneMgr21playBossBeatenFanfareEv = 0x0028C2EC;
_ZN11SndSceneMgr11playHurryUpEv = 0x0028C494;
_ZN11SndSceneMgr17playWorldSelectedEv = 0x0028B090;
_ZN11SndSceneMgr15playCourseIntroEv = 0x0028B50C;
_ZN11SndSceneMgr12playGameOverEv = 0x0028AAB0;
_ZN11SndSceneMgr15playCoinFanfareEj = 0x0028BB78;

_ZN11SndSceneMgr13startBossDemoEi = 0x0028BB00;
_ZN11SndSceneMgr14updateBossDemoEv = 0x0028B388;
_ZN11SndSceneMgr17startAllBubbleOutEv = 0x0028C488;
_ZN11SndSceneMgr18updateAllBubbleOutEv = 0x0028B918;

_ZN11SndSceneMgr16musicStopRelatedEb = 0x0028B314;
_ZN11SndSceneMgr17enableCourseMusicEv = 0x0028CE14;

_ZN11SndSceneMgr17getPlayingMusicIdEv = 0x0028CEBC;
_ZN11SndSceneMgr21getCurrentZoneMusicIdEv = 0x0028B14C;

/* MusicTrackMgr */
_ZN13MusicTrackMgr8instanceE = 0x005E3058;
_ZN13MusicTrackMgr14setTrackVolumeEjfj = 0x00211B8C;
_ZN13MusicTrackMgr21setVolumeOfAllHandlesEfi = 0x00211684;
_ZN13MusicTrackMgr20setPitchOfAllHandlesEf = 0x00211508;
_ZN13MusicTrackMgr10playStreamEjj = 0x00213160;
_ZN13MusicTrackMgr13playTrackByIdEjj = 0x00211694;
_ZN13MusicTrackMgr13stopOverridesEi = 0x00211850;
_ZN13MusicTrackMgr12stopOverrideEii = 0x002117F4;
_ZN13MusicTrackMgr16stopMusicStreamsEi = 0x00213038;
_ZN13MusicTrackMgr7stopAllEi = 0x002113B0;
_ZN13MusicTrackMgr5resetEv = 0x00212F1C;

/* Resource */
_ZN8Resource11loadArchiveERKN4sead14SafeStringBaseIcEEPNS0_4HeapEi = 0x001B22D0;
_ZN8Resource16setVramLocationsEjjj = 0x001B0498;
_ZN8Resource20setupResGraphicsFileEP9AllocatorPS_b = 0x001B0568;

/* ResourceMgr */
_ZN11ResourceMgr8instanceE = 0x005E74B8;
_ZN11ResourceMgr11getResourceERKN4sead14SafeStringBaseIcEE = 0x0049C77C;
_ZN11ResourceMgr8loadFileERKN4sead14SafeStringBaseIcEEjjjb = 0x0023D6F8;
_ZN11ResourceMgr9loadFile2ERKN4sead14SafeStringBaseIcEEjjjbS4_ = 0x0023D0E0;
_ZN11ResourceMgr10unloadFileERKN4sead14SafeStringBaseIcEE = 0x0023D548;
_ZN11ResourceMgr6unloadE11ResLoadMode = 0x002E4478;
_ZN11ResourceMgr30loadCourseMergedModelResourcesEv = 0x002E3D84;
_ZN11ResourceMgr32unloadCourseMergedModelResourcesEv = 0x0023D8EC;

/* course_select::MapResources */
_ZN13course_select12MapResources9sInstanceE = 0x005E5CD8;
_ZN13course_select12MapResources14createInstanceEPN4sead4HeapE = 0x002BB698;
_ZN13course_select12MapResources14deleteInstanceEv = 0x002BB74C;
_ZN13course_select12MapResources18SingletonDisposer_D1Ev = 0x002BB900;
_ZN13course_select12MapResources15sStaticDisposerE = 0x005E5CDC;
_ZTVN13course_select12MapResources18SingletonDisposer_E = 0x005B033C;

/* vtable */
_ZTVN13course_select12MapResourcesE = 0x005B034C;

/* functions */
_ZN13course_select12MapResources11getResourceERKN4sead14SafeStringBaseIcEE = 0x004A0D64;
_ZN13course_select12MapResources14insertResourceERKN4sead14SafeStringBaseIcEE = 0x002BB798;


/* TransformNodeWrapper */
_ZTV20TransformNodeWrapper = 0x0059E1EC;
_ZN20TransformNodeWrapperC1Ev = 0x001B2248;
_ZN20TransformNodeWrapperC2Ev = 0x001B2248;
_ZN20TransformNodeWrapperD1Ev = 0x001B2260;
_ZN20TransformNodeWrapper13setDrawMatrixEP5Mtx34 = 0x001B2224;
_ZN20TransformNodeWrapper6acceptEj = 0x001B2194;
_ZN20TransformNodeWrapper7cleanupEv = 0x001B21D4;
_ZN20TransformNodeWrapper15updateTransformEv = 0x001B221C;
_ZNK20TransformNodeWrapper12getTransformEv = 0x00495588;
_ZN20TransformNodeWrapper17createSharedModelEP13HeapAllocator = 0x0024B01C;


/* ModelWrapper */
_ZTV12ModelWrapper = 0x0059E1D0;
_ZN12ModelWrapperD1Ev = 0x001B1D84;
_ZN12ModelWrapperC1Ev = 0x001B1D6C;
_ZN12ModelWrapper7cleanupEv = 0x001B21B0;
_ZN12ModelWrapper15updateTransformEv = 0x001B3718;
_ZN12ModelWrapper12createObjectEPN2nw3gfx3res18ResSceneObjectDataEPNS0_2os10IAllocatorEPNS6_ENS1_5Model12BufferOptionEbi = 0x001B4858;
_ZN12ModelWrapper12createObjectEPN2nw3gfx5ModelEPNS0_2os10IAllocatorE = 0x00317C70;
_ZN12ModelWrapper8getModelEv = 0x001B49B8;

/* SkeletalModelWrapper */
_ZTV20SkeletalModelWrapper = 0x005D0048;
_ZN20SkeletalModelWrapper27setBoneLocalTransformMatrixEiRK5Mtx34 = 0x001B1658;
_ZN20SkeletalModelWrapper26setBoneLocalTransformScaleEiRKN4sead7Vector3IfEE = 0x001B16E0;
_ZN20SkeletalModelWrapper27getBoneLocalTransformMatrixER5Mtx34i = 0x0049539C;
_ZN20SkeletalModelWrapper26getBoneLocalTransformScaleERN4sead7Vector3IfEEi = 0x0049549C;
_ZN20SkeletalModelWrapper21getBoneLocalTransformEi = 0x001B1B20;
_ZN20SkeletalModelWrapper21getBoneWorldTransformEi = 0x00495524;
_ZN20SkeletalModelWrapper10getBoneIdxEPKc = 0x004952C0;
_ZN20SkeletalModelWrapper12getBoneCountEv = 0x00495248;
_ZN20SkeletalModelWrapper13evaluateAnimsEv = 0x001B4334;
_ZN20SkeletalModelWrapper11updateAnimsEv = 0x001B436C;
_ZN20SkeletalModelWrapper11getBoneNameEi = 0x00495190;
_ZN20SkeletalModelWrapper15getBonePositionERN4sead7Vector3IfEEi = 0x00495024;
_ZN20SkeletalModelWrapper27getBoneWorldTransformMatrixER5Mtx34i = 0x00494E90;
_ZNK20SkeletalModelWrapper16getSkeletalModelEv = 0x00495450;
_ZN20SkeletalModelWrapper16getSkeletalModelEv = 0x001B17B4;
_ZN20SkeletalModelWrapper20getSkeletalAnimGroupEv = 0x001B1AD4;
_ZN20SkeletalModelWrapper20getMaterialAnimGroupEv = 0x001B4540;
_ZN20SkeletalModelWrapper27linkToUnkSkeletalAnimHolderEP21UnkSkeletalAnimHolder = 0x001B1CD8;
_ZN20SkeletalModelWrapper17sortMeshDataByUnkEv = 0x001B4A04;
_ZN20SkeletalModelWrapper18unbindMaterialAnimEj = 0x001B46D0;
_ZN20SkeletalModelWrapper22getVisibilityAnimGroupEv = 0x001B4688;

/* SharedModelWrapper */
_ZTV18SharedModelWrapper = 0x005B6A98;

/* UnkSkeletalAnimHolder */
_ZTV21UnkSkeletalAnimHolder = 0x0059E23C;
_ZN21UnkSkeletalAnimHolderD1Ev = 0x001B32A8;
_ZN21UnkSkeletalAnimHolderC1Ev = 0x001B3264;
_ZN21UnkSkeletalAnimHolder5setupEP20SkeletalModelWrapperN2nw4anim3res7ResAnimEP13HeapAllocatorj = 0x001B2DC0;

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

/* SharedModel */
_ZTV11SharedModel = 0x005A8644;
_ZN11SharedModel13getGfxWrapperEv = 0x0024B170;
_ZN11SharedModelD0Ev = 0x0024B178;

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

/* SkeletalAnim */
_ZTV12SkeletalAnim = 0x0059E24C;

/* ActorCollisionCheck */
_ZN19ActorCollisionCheckC1Ev = 0x004367DC;
_ZN19ActorCollisionCheckC2Ev = 0x004367DC;
_ZN19ActorCollisionCheckD1Ev = 0x00436864;
_ZN19ActorCollisionCheckD2Ev = 0x00436864;
_ZN19ActorCollisionCheck3setEP9ActorBaseRKNS_13CollisionDataE = 0x004366C4;
_ZN19ActorCollisionCheck3setEP9ActorBaseRKNS_13CollisionDataERKN4sead7BitFlagIhEE = 0x004366E8;
_ZN19ActorCollisionCheck3setEP9ActorBaseRKNS_13CollisionDataERKN4sead7BitFlagIhEEh = 0x00436710;

/* ActorCollisionCheckMgr */
_ZN22ActorCollisionCheckMgr9sInstanceE = 0x005E54E8;
_ZN22ActorCollisionCheckMgr14createInstanceEPN4sead4HeapE = 0x00254E78;
_ZN22ActorCollisionCheckMgr14deleteInstanceEv = 0x00254EDC;
_ZN22ActorCollisionCheckMgr18SingletonDisposer_D1Ev = 0x00254F18;
_ZN22ActorCollisionCheckMgr15sStaticDisposerE = 0x005E54EC;
_ZTVN22ActorCollisionCheckMgr18SingletonDisposer_E = 0x005A99C0;
_ZN22ActorCollisionCheckMgr9addToListEP19ActorCollisionCheck = 0x00255018;
_ZN22ActorCollisionCheckMgr14removeFromListEP19ActorCollisionCheck = 0x00255050;


/* BasicBgCollisionCheck */
_ZN21BasicBgCollisionCheckC1Ev = 0x0044A37C;
_ZN21BasicBgCollisionCheckC1ERKNS_7InitArgE = 0x0044A31C;
_ZN21BasicBgCollisionCheck10initializeERKNS_7InitArgE = 0x0044A2E0;
_ZNK21BasicBgCollisionCheck8hitCheckEP26BgCollisionCheckResultAreaRKN4sead7Vector2IfEES6_13DirectionMask = 0x004AEB68;
_ZNK21BasicBgCollisionCheck13hitCheckActorEP26BgCollisionCheckResultAreaRKN4sead7Vector2IfEES6_13DirectionMask = 0x004AECC4;
_ZNK21BasicBgCollisionCheck12hitCheckUnitER26BgCollisionCheckResultAreaRKN4sead7Vector2IfEES6_13DirectionMask = 0x004AF35C;
_ZNK21BasicBgCollisionCheck10canCollideERK11BgCollision = 0x004AEF28;
_ZNK21BasicBgCollisionCheck8hitCheckEP10BgUnitCodeRKN4sead7Vector2IfEE = 0x004AF060;
_ZNK21BasicBgCollisionCheck13hitCheckActorEP10BgUnitCodeRKN4sead7Vector2IfEE = 0x004AF23C;
_ZNK21BasicBgCollisionCheck12hitCheckUnitEP10BgUnitCodeRKN4sead7Vector2IfEE = 0x004AEE5C;

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
_ZN11BgCollision5resetEv = 0x0044C790;
_ZN11BgCollision18removeFromListFootEP21ActorBgCollisionCheck = 0x0044C5A4;
_ZN11BgCollision11clearBcListEv = 0x0044C1C0;
_ZN11BgCollision10sub_44C780Ev = 0x0044C780;


/* LoopRideLineBgCollision */
_ZTV23LoopRideLineBgCollision = 0x005B7ED8;
_ZN23LoopRideLineBgCollisionD2Ev = 0x00324964;
_ZN23LoopRideLineBgCollisionD0Ev = 0x00324950;

/* virtual functions */
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


/* RopeCollision */
_ZN13RopeCollisionC1Ev = 0x002A61A4;
_ZN13RopeCollisionD0Ev = 0x002A6220;
_ZN13RopeCollisionD1Ev = 0x002A6220;
_ZN13RopeCollisionD2Ev = 0x002A6220;

/* vtable */
_ZTV13RopeCollision = 0x005AF1C4;

/* virtual functions */
_ZN13RopeCollision4vf14Ev = 0x002A5078;
_ZN13RopeCollision7executeEv = 0x002A5C04;
_ZN13RopeCollision4vf1CEPjjS0_PN4sead7Vector2IfEEh = 0x002A619C;
_ZN13RopeCollision4vf20EjPjjj = 0x002A5084;
_ZN13RopeCollision4vf24EjPN4sead7Vector2IfEE = 0x004A02CC;
_ZN13RopeCollision4vf28Ev = 0x004A0454;
_ZN13RopeCollision4vf2CEv = 0x00000000;
_ZN13RopeCollision4vf30Ev = 0x002A5BDC;
_ZN13RopeCollision4vf34Ev = 0x002A59BC;
_ZN13RopeCollision4vf38Ev = 0x002A5C00;


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


/* LineCollision */
_ZTV13LineCollision = 0x005AE054;

/* virtual functions */
_ZN13LineCollisionD2Ev = 0x0044CFCC;
_ZN13LineCollision4vf14Ev = 0x0029C96C;
_ZN13LineCollision7executeEv = 0x0029D088;
_ZN13LineCollision4vf1CEPjjS0_PN4sead7Vector2IfEEh = 0x0029D29C;
_ZN13LineCollision4vf20EjPjjj = 0x0029C978;
_ZN13LineCollision4vf24EjPN4sead7Vector2IfEE = 0x0049F970;
_ZN13LineCollision4vf28Ev = 0x0049F978;
_ZN13LineCollision4vf2CEv = 0x00000000;
_ZN13LineCollision4vf30Ev = 0x0029D01C;
_ZN13LineCollision4vf34Ev = 0x0029CE88;
_ZN13LineCollision4vf38Ev = 0x0029D040;

/* functions */
_ZN13LineCollisionC1EjPN4sead7Vector2IfEEP13BasicRideLineS5_ = 0x0029D5E4;
_ZN13LineCollisionC2EjPN4sead7Vector2IfEEP13BasicRideLineS5_ = 0x0029D5E4;
_ZN13LineCollision5setupEP9ActorBaseRKNS_4InfoE = 0x0029CC84;


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
_ZN19ActorBgCollisionMgr9sInstanceE = 0x005E3CE0;
_ZN19ActorBgCollisionMgr14createInstanceEPN4sead4HeapE = 0x00210DD4;
_ZN19ActorBgCollisionMgr14deleteInstanceEv = 0x00210E80;
_ZN19ActorBgCollisionMgr15sStaticDisposerE = 0x005E2E8C;
_ZN19ActorBgCollisionMgr7executeEv = 0x002E4A60;
_ZN19ActorBgCollisionMgr17findBestCollisionER27ActorBgCollisionCheckResult9Direction19BgCollisionCategoryRK21ActorBgCollisionCheck = 0x002E4A90;
_ZN19ActorBgCollisionMgr9addToListER11BgCollision = 0x002E4C94;
_ZN19ActorBgCollisionMgr10sub_2E4D60ER27ActorBgCollisionCheckResultPK11BgCollisionKP22TarzanBgCollisionChecki = 0x002E4D60;
_ZN19ActorBgCollisionMgr10sub_2E4E74ER27ActorBgCollisionCheckResultRKN11LineNodeMgrI11BgCollisionEEPK22TarzanBgCollisionCheck = 0x002E4E74;
_ZN19ActorBgCollisionMgr14removeFromListER11BgCollision = 0x002E519C;
_ZN19ActorBgCollisionMgr15addToListTarzanER11BgCollision = 0x002E532C;
_ZN19ActorBgCollisionMgr14updateCategoryER11BgCollisionRK10BgUnitCodeS4_ = 0x002E5360;
_ZN19ActorBgCollisionMgr18removeFromListCoinER11BgCollision = 0x002E54D0;
_ZN19ActorBgCollisionMgr20removeFromListTarzanER11BgCollision = 0x002E5504;
_ZN19ActorBgCollisionMgr19removeFromListSolidER11BgCollision = 0x002E556C;
_ZN19ActorBgCollisionMgr22removeFromListNonSolidER11BgCollision = 0x002E55A0;
_ZN19ActorBgCollisionMgr23removeFromListCandidateER11BgCollision = 0x002E55D4;
_ZN19ActorBgCollisionMgr18buildCandidateListERK21ActorBgCollisionCheck = 0x002E5608;
_ZNK19ActorBgCollisionMgr18activeListContainsERK11BgCollision = 0x004A188C;
_ZNK19ActorBgCollisionMgr18tarzanListContainsERK11BgCollision = 0x004A1898;

/* ActorBgCollisionMgr::SingletonDisposer_ */
_ZTVN19ActorBgCollisionMgr18SingletonDisposer_E = 0x005A3DA8;
_ZN19ActorBgCollisionMgr18SingletonDisposer_D1Ev = 0x00210EF4;

/* ActorBgHitCheckCallback */

/* virtual functions */
_ZN23ActorBgHitCheckCallback3hitERK26BgCollisionCheckResultArea = 0x004A5980;
_ZN23ActorBgHitCheckCallback3hitERK27BgCollisionCheckResultPoint = 0x004A59F4;

/* ActorBgCollisionCheck */
_ZTV21ActorBgCollisionCheck = 0x005A44A0;
_ZN21ActorBgCollisionCheckC1Ev = 0x0021D0C4;
_ZN21ActorBgCollisionCheckC2Ev = 0x0021D0C4;
_ZNK21ActorBgCollisionCheck18getRuntimeTypeInfoEv = 0x0;
_ZN21ActorBgCollisionCheckD1Ev = 0x0021D394;
_ZN21ActorBgCollisionCheckD2Ev = 0x0021D394;
_ZN21ActorBgCollisionCheckD0Ev = 0x0;
_ZN21ActorBgCollisionCheck7checkBgEv = 0x0021C9E0;
_ZN21ActorBgCollisionCheck7clearBgEv = 0x0021CEE0;
_ZN21ActorBgCollisionCheck12atFrameStartEv = 0x002190EC;
_ZNK21ActorBgCollisionCheck18getOwnerAtRevCheckEf = 0x00100ECF;
_ZNK21ActorBgCollisionCheck13getOwnerAtHitERK11BgCollision9Direction = 0x00100ECF;
_ZN21ActorBgCollisionCheck11getPlayerNumEf = 0x00100ECF;
_ZN21ActorBgCollisionCheck20buildBgCollisionListEv = 0x0021C6E8;
_ZN21ActorBgCollisionCheck18sweepCollisionFootEv = 0x00217A80;
_ZN21ActorBgCollisionCheck18sweepCollisionHeadEv = 0x00217CF8;
_ZN21ActorBgCollisionCheck18sweepCollisionWallE9Direction = 0x00217F70;
_ZN21ActorBgCollisionCheck10checkWaterEPfRKN4sead7Vector3IfEE = 0x002182A4;
_ZN21ActorBgCollisionCheck3setEP9ActorBasePKNS_6SensorES4_S4_ = 0x002182E8;
_ZN21ActorBgCollisionCheck17checkBgSimplifiedEv = 0x00218460;
_ZN21ActorBgCollisionCheck13applyFootSnapEv = 0x00218608;
_ZN21ActorBgCollisionCheck8hitCheckEPN4sead7Vector2IfEEP5Angle10BgUnitCodeP11BgCollisionRKS2_SA_h13DirectionMask = 0x0021866C;
_ZN21ActorBgCollisionCheck19adjustYForWallSlopeERKN4sead7Vector2IfEE = 0x00218750;
_ZN21ActorBgCollisionCheck17applyWallPushbackERNS_6OutputE9DirectionS2_ = 0x00218A68;
_ZN21ActorBgCollisionCheck12updateBoundsEv = 0x00218C58;
_ZN21ActorBgCollisionCheck13shockHitCheckERKN4sead7Vector2IfEEjbb = 0x00218D70;
_ZN21ActorBgCollisionCheck15explodeHitCheckERKN4sead7Vector2IfEES4_9Direction = 0x0021916C;
_ZN21ActorBgCollisionCheck18isOverlappingRightEv = 0x00219430;
_ZN21ActorBgCollisionCheck16detectGroundDropEv = 0x002194F0;
_ZN21ActorBgCollisionCheck22isOnLowerVisualSurfaceEv = 0x00219740;
_ZN21ActorBgCollisionCheck9setSensorEPKNS_6SensorE9Direction = 0x002197C0;
_ZN21ActorBgCollisionCheck11stepTowardsEPfff = 0x00219860;
_ZN21ActorBgCollisionCheck15checkWaterDepthEffh = 0x002198D8;
_ZN21ActorBgCollisionCheck19sweepActorCollisionER18BgCheckResultArray9Direction = 0x002199A8;
_ZN21ActorBgCollisionCheck17snapCollisionFootEv = 0x00219CA4;
_ZN21ActorBgCollisionCheck13blockHitCheckERKN4sead7Vector2IfEE9Direction = 0x00219F88;
_ZN21ActorBgCollisionCheck17snapCollisionWallE9Direction = 0x0021A204;
_ZN21ActorBgCollisionCheck14trimWallSensorE9Direction = 0x0021A5E0;
_ZN21ActorBgCollisionCheck22sweepTileCollisionFootER27ActorBgCollisionCheckResult = 0x0021ACA0;
_ZN21ActorBgCollisionCheck22sweepTileCollisionHeadER27ActorBgCollisionCheckResult = 0x0021B154;
_ZN21ActorBgCollisionCheck22sweepTileCollisionWallER27ActorBgCollisionCheckResult9Direction = 0x0021B4E4;
_ZN21ActorBgCollisionCheck12resetBgCheckEv = 0x0021B8F0;
_ZN21ActorBgCollisionCheck19computeSensorBoundsEv = 0x0021B9AC;
_ZN21ActorBgCollisionCheck17processResultFootEv = 0x0021BC48;
_ZN21ActorBgCollisionCheck17processResultHeadEv = 0x0021BF08;
_ZN21ActorBgCollisionCheck17processResultWallE9Direction = 0x0021C098;
_ZN21ActorBgCollisionCheck13updateSensorsEv = 0x0021C2AC;
_ZN21ActorBgCollisionCheck24checkGroundTileCollisionER27ActorBgCollisionCheckResult = 0x0021C408;
_ZN21ActorBgCollisionCheck22checkWallTileCollisionER27ActorBgCollisionCheckResult9Direction = 0x0021C534;
_ZN21ActorBgCollisionCheck16getConveyorSpeedE9Direction = 0x0021C6C0;
_ZN21ActorBgCollisionCheck16setConveyorSpeedE9Directionf = 0x0021C6D4;
_ZN21ActorBgCollisionCheck22checkForSuitableGroundERKN4sead7Vector2IfEEfff = 0x0021CFF4;
_ZNK21ActorBgCollisionCheck16getSakaDirectionEv = 0x0049A948;
_ZNK21ActorBgCollisionCheck10checkOnNetERKN4sead7Vector2IfEE = 0x0049A968;
_ZNK21ActorBgCollisionCheck12getWallAngleE9Direction = 0x0049AA4C;
_ZNK21ActorBgCollisionCheck13isFlagSetWallEN10SensorFlag3BitE = 0x0049AA6C;
_ZNK21ActorBgCollisionCheck12getFootAngleEv = 0x0049AAB8;
_ZNK21ActorBgCollisionCheck12getHeadAngleEv = 0x0049AACC;
_ZNK21ActorBgCollisionCheck23getCollisionCheckResultE9Direction = 0x0049AAFC;
_ZNK21ActorBgCollisionCheck21getCollisionOwnerFootEv = 0x0049AB34;
_ZNK21ActorBgCollisionCheck21getCollisionOwnerHeadEv = 0x0049AB50;
_ZNK21ActorBgCollisionCheck21getCollisionOwnerWallE9Direction = 0x0049AB6C;
_ZNK21ActorBgCollisionCheck17canBreakCollisionERK11BgCollision9Direction = 0x0049ABCC;
_ZNK21ActorBgCollisionCheck12getSlopeTypeE5Angle = 0x0049ACAC;
_ZNK21ActorBgCollisionCheck10sub_49AD18ERK11BgCollision9Direction = 0x0049AD18;
_ZNK21ActorBgCollisionCheck10sub_49AF0CERK11BgCollision9Direction = 0x0049AF0C;
_ZNK21ActorBgCollisionCheck22buildSensorQueryPointsERN4sead7Vector2IfEES3_S3_PNS_6SensorES5_9Direction = 0x0049AFE4;
_ZNK21ActorBgCollisionCheck16getFootAnglePrevEv = 0x0049B0D0;
_ZNK21ActorBgCollisionCheck12getFootAngleE9Direction = 0x0049B0E4;
_ZNK21ActorBgCollisionCheck25getCollisionOwnerFootPrevEv = 0x0049B104;
_ZNK21ActorBgCollisionCheck18getCheckResultFootEv = 0x0049B120;
_ZNK21ActorBgCollisionCheck18getCheckResultHeadEv = 0x0049B154;
_ZNK21ActorBgCollisionCheck18getCheckResultWallE9Direction = 0x0049B190;
_ZNK21ActorBgCollisionCheck14canCollideWithERK11BgCollision = 0x0049B238;
_ZNK21ActorBgCollisionCheck15canInteractWithERK11BgCollision9Direction = 0x0049B2B8;
_ZNK21ActorBgCollisionCheck22getCheckResultFootPrevEv = 0x0049B3FC;
_ZNK21ActorBgCollisionCheck22getCheckResultHeadPrevEv = 0x0049B430;
_ZNK21ActorBgCollisionCheck13getWorkSensorE9Direction = 0x0049B46C;
_ZNK21ActorBgCollisionCheck10sub_49B4D0E9Direction = 0x0049B4D0;
_ZNK21ActorBgCollisionCheck10sub_49B520Ev = 0x0049B520;


/* ActorBgCollisionObjCheck */
_ZTV24ActorBgCollisionObjCheck = 0x005B8AE0;
_ZN24ActorBgCollisionObjCheckC2Ev = 0x0032D600;
_ZN24ActorBgCollisionObjCheckC1Ev = 0x0032D600;
_ZN24ActorBgCollisionObjCheck8hitCheckEPN4sead7Vector2IfEERKS2_S5_13DirectionMask = 0x0032D5C0;
_ZNK24ActorBgCollisionObjCheck12getPlayerNumEf = 0x004A438C;
_ZNK24ActorBgCollisionObjCheck13getOwnerAtHitERK11BgCollision9Direction = 0x004A4394;
_ZNK24ActorBgCollisionObjCheck18getOwnerAtRevCheckEf = 0x004A439C;


/* TarzanBgCollisionCheck */

/* PlayerBgCollisionCheck */

_ZN22TarzanBgCollisionCheck12atFrameStartEv = 0x003054FC;
_ZNK22TarzanBgCollisionCheck18getOwnerAtRevCheckEf = 0x004A2A40;
_ZNK22TarzanBgCollisionCheck13getOwnerAtHitERK11BgCollision9Direction = 0x004A2A38;
_ZN22TarzanBgCollisionCheck12getPlayerNumEf = 0x004A2A24;


/* PlayerBgCollisionCheck */

/* virtual functions */
_ZN22PlayerBgCollisionCheck7checkBgEv = 0x0032DEBC;
_ZN22PlayerBgCollisionCheck7clearBgEv = 0x0021CEE0;
_ZN22PlayerBgCollisionCheck12atFrameStartEv = 0x003054F8;
_ZNK22PlayerBgCollisionCheck18getOwnerAtRevCheckEf = 0x004A4470;
_ZNK22PlayerBgCollisionCheck13getOwnerAtHitERK11BgCollision9Direction = 0x004A43F4;
_ZN22PlayerBgCollisionCheck12getPlayerNumEf = 0x004A43A4;
_ZN22PlayerBgCollisionCheck12checkCeilingERKN4sead7Vector3IfEEPff = 0x0032DE1C;
_ZN22PlayerBgCollisionCheck9checkWallEPN4sead7Vector3IfEES3_f = 0x0032DCA0;
_ZN22PlayerBgCollisionCheck18checkVineCollisionEPN21ActorBgCollisionCheck6SensorE = 0x0032E210;

/* UnitCollider */
_ZN12UnitCollider9sInstanceE = 0x005E55C0;
_ZN12UnitColliderC1Ev = 0x00285E5C;
_ZN12UnitCollider12setSolidTileEjjh = 0x00285500;
_ZN12UnitCollider7setTileEjjh = 0x00285848;
_ZN12UnitCollider18setSlopeBottomTileEjjh = 0x00285AD0;
_ZN12UnitCollider25setReverseSlopeBottomTileEjjh = 0x00285C94;
_ZN12UnitCollider14createInstanceEPN4sead4HeapE = 0x00285788;
_ZN12UnitCollider14deleteInstanceEv = 0x002857E8;


/* UnitCollider::SingletonDisposer_ */
_ZTVN12UnitCollider18SingletonDisposer_E = 0x005ABF6C;
_ZN12UnitCollider18SingletonDisposer_15sStaticDisposerE = 0x005E55C4;
_ZN12UnitCollider18SingletonDisposer_D1Ev = 0x00285E00;


/* PairChild */
_ZN9PairChildC1Ev = 0x002A0924;
_ZN9PairChildC2Ev = 0x002A0924;
_ZN9PairChild4linkERKN4sead7Vector3IfEEjh = 0x0029FE30;
_ZN9PairChild7executeEv = 0x002A0914;
_ZN9PairChild22getMaskForMovementTypeEj = 0x002A015C;


/* RailParent */
_ZN10RailParent10initializeERKN4sead7Vector2IfEEhbfhtt = 0x0020079C;

/* RailPolyParent */

/* states */
_ZN14RailPolyParent11StateID_4B6E = 0x00618AD4;
_ZN14RailPolyParent11StateID_4B7E = 0x00618AF4;


/* LineFollower */
_ZN12LineFollowerC1Ev = 0x0023C508;
_ZN12LineFollowerC2Ev = 0x0023C508;
_ZN12LineFollower4initERKN4sead7Vector2IfEEfhhb = 0x002379A4;
_ZN12LineFollower9initStateEb = 0x00237F20;
_ZN12LineFollower11getLineTypeEff = 0x00237A94;


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
_ZN9PlayerMgr21EntrancePlayerOffsetsE = 0x0058036C;

/* PlayerMgr::SingletonDisposer_ */
_ZN9PlayerMgr14createInstanceEPN4sead4HeapE = 0x0044DC84;
_ZN9PlayerMgr14deleteInstanceEv = 0x0044DCE8;
_ZN9PlayerMgr18SingletonDisposer_15sStaticDisposerE = 0x005EB534;
_ZTVN9PlayerMgr18SingletonDisposer_E = 0x005D0364;
_ZN9PlayerMgr18SingletonDisposer_D1Ev = 0x0044DE2C;

/* ActorUniqueID */
_ZN13ActorUniqueIDC1Ev = 0x0042D830;

/* AttentionLook */
_ZTV13AttentionLook = 0x005AC924;
_ZN13AttentionLookC1E13ActorUniqueID = 0x0028A940;
_ZN13AttentionLookD1Ev = 0x0028A988;

/* AttentionMgr */
_ZTV12AttentionMgr = 0x005A8ED0;
_ZN12AttentionMgrD1Ev = 0x00252358;
_ZN12AttentionMgrD2Ev = 0x0025235C;
_ZN12AttentionMgr9addToListEP13AttentionLook = 0x002522F8;
_ZN12AttentionMgr14removeFromListEP13AttentionLook = 0x00252320;
_ZN12AttentionMgr17findTargetInRangeEP9ActorBaseRKN4sead7Vector2IfEE = 0x0049CE34;
_ZN12AttentionMgr17findTargetInRangeEP9ActorBaseRKN4sead7Vector2IfEE9Direction = 0x0049CF10;
_ZN12AttentionMgr9sInstanceE = 0x005E2EC0;
_ZN12AttentionMgr14createInstanceEPN4sead4HeapE = 0x002521DC;
_ZN12AttentionMgr14deleteInstanceEv = 0x0025225C;

/* AttentionMgr::SingletonDisposer_ */
_ZTVN12AttentionMgr18SingletonDisposer_E = 0x005A8EC0;
_ZN12AttentionMgr18SingletonDisposer_D1Ev = 0x002522A8;
_ZN12AttentionMgr18SingletonDisposer_15sStaticDisposerE = 0x005E2EC4;

/* PlayerStateData::CheckPointData */
_ZN15PlayerStateData14CheckPointDataC1Ev = 0x001085E8;
_ZN15PlayerStateData14CheckPointDataC2Ev = 0x001085E8;
_ZN15PlayerStateData14CheckPointData5clearEv = 0x002E671C;
_ZN15PlayerStateData14CheckPointData3setEiaccffcccccccccbPc = 0x002E6760;
_ZN15PlayerStateData14CheckPointData15getCheckPointIDEhhh = 0x004A193C;

/* PlayerStateData */
_ZN15PlayerStateData12setLifeCountEii = 0x004106CC;
_ZN15PlayerStateData16setInventoryItemEha = 0x0041052C;

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

/* ProcessMgr */
_ZN10ProcessMgr8instanceE = 0x005F3980;
_ZN10ProcessMgr11getInstanceEv = 0x001C550C;
_ZN10ProcessMgr17getFirstProcChildEP5fBase = 0x00496A7C;
_ZN10ProcessMgr18getNextProcSiblingEP5fBase = 0x00496B44;
_ZN10ProcessMgr18getProcByProfileIdEsP5fBase = 0x00496D7C;

_ZN10ProcessMgr13createProcessEtP5fBasejh = 0x004576EC;

/* ProcessMgr::TreeNode */
_ZN10ProcessMgr8TreeNode7getNextEv = 0x00496F38;


/* fBase */
_ZTV5fBase = 0x0059E4DC;
_ZN5fBaseC1Ev = 0x001C7060;
_ZN5fBaseC2Ev = 0x001C7060;
_ZN5fBaseD1Ev = 0x001C70AC;
_ZN5fBaseD2Ev = 0x001C70AC;

_ZN5fBase9preCreateEv = 0x001C7050;
_ZN5fBase8onCreateEv = 0x001C6FDC;
_ZN5fBase10postCreateENS_6ResultE = 0x001C655C;
_ZN5fBase9preDeleteEv = 0x001C7058;
_ZN5fBase8onDeleteEv = 0x001C7010;
_ZN5fBase10postDeleteENS_6ResultE = 0x001C6564;
_ZN5fBase10preExecuteEv = 0x001C6568;
_ZN5fBase9onExecuteEv = 0x001C6FE4;
_ZN5fBase11postExecuteENS_6ResultE = 0x001C665C;
_ZN5fBase7preDrawEv = 0x001C6FEC;
_ZN5fBase6onDrawEv = 0x001C6FD4;
_ZN5fBase8postDrawENS_6ResultE = 0x001C7018;
_ZN5fBase11deleteReadyEv = 0x001C6658;

_ZN5fBase13requestDeleteEv = 0x001C5B8C;
_ZN5fBase10commonPackEMS_FivEMS_FivEMS_FvNS_6ResultEE = 0x001C6570;
_ZN5fBase10createPackEv = 0x001C65F4;
_ZN5fBase10deletePackEv = 0x001C6624;
_ZN5fBase11executePackEv = 0x001C6660;
_ZN5fBase13setCreateDataEtjNS_9GroupTypeE = 0x001C6694;
_ZN5fBase8drawPackEv = 0x001C701C;
_ZNK5fBase9getParentEv = 0x00496B9C;


/* dBase */
_ZTV5dBase = 0x0059A874;
_ZN5dBaseC1Ev = 0x0047F00C;
_ZN5dBaseC2Ev = 0x0047F00C;
_ZN5dBaseD1Ev = 0x0047F028;
_ZN5dBaseD2Ev = 0x0047F028;

_ZN5dBase9preCreateEv = 0x0047EFE4;
_ZN5dBase10postCreateEN5fBase6ResultE = 0x0047EF78;
_ZN5dBase9preDeleteEv = 0x0047EFF8;
_ZN5dBase10postDeleteEN5fBase6ResultE = 0x0047EF80;
_ZN5dBase10preExecuteEv = 0x0047EF84;
_ZN5dBase11postExecuteEN5fBase6ResultE = 0x0047EFCC;
_ZN5dBase7preDrawEv = 0x0047EFD0;
_ZN5dBase8postDrawEN5fBase6ResultE = 0x00457874;
_ZN5dBase4vf3CEv = 0x00000000;

_ZN5dBase11createChildEtPS_j = 0x0047EFB0;

isPaused = 0x005EF8C0;

/* ActorBase */

/* vtable */
_ZTV9ActorBase = 0x005CD980;

/* ctor */
_ZN9ActorBaseC1Ev = 0x004318D8;
_ZN9ActorBaseC2Ev = 0x004318D8;

/* dtor */
_ZN9ActorBaseD1Ev = 0x00431A24;
_ZN9ActorBaseD2Ev = 0x00431A24;

/* virtual functions */
_ZN9ActorBase10postCreateEN5fBase6ResultE = 0x00430928;
_ZN9ActorBase10postDeleteEN5fBase6ResultE = 0x00430990;
_ZN9ActorBase10preExecuteEv = 0x004309D0;
_ZN9ActorBase11postExecuteEN5fBase6ResultE = 0x00430CD4;
_ZN9ActorBase7preDrawEv = 0x00431748;

_ZNK9ActorBase18getRuntimeTypeInfoEv = 0x004AE360;
_ZN9ActorBase19getBgCollisionCheckEv = 0x004318A8;
_ZNK9ActorBase19getBgCollisionCheckEv = 0x004AE1E4;
_ZN9ActorBase12setPlayerNumEa = 0x00430CD8;
_ZN9ActorBase20removeCollisionCheckEv = 0x004318B0;
_ZN9ActorBase17addCollisionCheckEv = 0x004318C4;
_ZN9ActorBase12setCarryFallEPS_i = 0x00430D20;
_ZN9ActorBase18isSpinLiftUpEnableEv = 0x004AE3AC;
_ZN9ActorBase18setSpinLiftUpActorEPS_ = 0x004311FC;
_ZN9ActorBase4vf64Ev = 0x00430E00;
_ZN9ActorBase4vf68Ev = 0x00430CE0;
_ZN9ActorBase15levelClearDeathEv = 0x00431434;
_ZN9ActorBase17waterSplashEffectERKN4sead7Vector3IfEEf = 0x00430F50;
_ZN9ActorBase16lavaSplashEffectERKN4sead7Vector3IfEEf = 0x0043101C;
_ZN9ActorBase18poisonSplashEffectERKN4sead7Vector3IfEEf = 0x004310D8;
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
_ZN9ActorBase9playVoiceEjhh = 0x00430B0C;
_ZN9ActorBase16playVoiceVariantEjjjf = 0x00430B58;
_ZN9ActorBase13playFootSoundEjjf = 0x00430E98;
_ZN9ActorBase19playVoiceFullVolumeEjjj = 0x0043163C;
_ZN9ActorBase9playSoundEjRKN4sead7Vector2IfEEb = 0x00214740;
_ZN9ActorBase20isBoundSoundCooldownEv = 0x004310A4;
_ZN9ActorBase21setBoundSoundCooldownEj = 0x00430F14;
_ZN9ActorBase19setupFromCreateInfoEPNS_10CreateInfoE = 0x004314D8;
_ZN9ActorBase14executeLastAllEv = 0x00430CD0;
_ZN9ActorBase11isOutOfViewEv = 0x00431200;
_ZN9ActorBase12powActivatedEv = 0x00430E04;
_ZN9ActorBase16spawnDeathEffectERKN4sead7Vector3IfEENS_15DeathEffectTypeERKNS1_IiEE = 0x004AE1EC;

/* functions */
_ZN9ActorBase10updateZoneEv = 0x00430AF4;
_ZN9ActorBase19assignExistLocationEh = 0x004311A4;
_ZN9ActorBase9cullCheckEj = 0x004312B4;
_ZN9ActorBase18directionToPlayerHERKN4sead7Vector3IfEE = 0x004AE234;
_ZN9ActorBase18directionToPlayerVERKN4sead7Vector3IfEE = 0x004AE2D8;
_ZN9ActorBase16getNearestPlayerERN4sead7Vector2IfEE = 0x004AE324;
_ZN9ActorBase18moveToTargetSpeedYEff = 0x00430E50;
_ZN9ActorBase15incrementSpeedYEff = 0x00430C54;
_ZN9ActorBase18applyAccelerationXEv = 0x00430BB8;
_ZN9ActorBase7despawnEb = 0x00430CEC;
_ZN9ActorBase13playStreakSfxEib = 0x00430D24;

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
_ZN14ActorCollision10postCreateEN5fBase6ResultE = 0x00430908;
_ZN14ActorCollision8onDeleteEv = 0x001C6FF4;
_ZN14ActorCollision10preExecuteEv = 0x002E1F28;
_ZN14ActorCollision11postExecuteEN5fBase6ResultE = 0x002E20AC;

_ZNK14ActorCollision18getRuntimeTypeInfoEv = 0x004A1830;
_ZN14ActorCollision19getBgCollisionCheckEv = 0x002E2628;
_ZNK14ActorCollision19getBgCollisionCheckEv = 0x004A1828;

_ZN14ActorCollision4vfD8Ev = 0x00000000;
_ZN14ActorCollision4vfDCEv = 0x00000000;
_ZN14ActorCollision4vfE0Ev = 0x00000000;
_ZN14ActorCollision4vfE4Ev = 0x00000000;
_ZN14ActorCollision4vfE8Ev = 0x00000000;
_ZN14ActorCollision4vfECEv = 0x00000000;
_ZN14ActorCollision4vfF0Ev = 0x00000000;
_ZN14ActorCollision4vfF4Ev = 0x00000000;

_ZN14ActorCollision21quakeCollisionEnabledEv = 0x004A1820;
_ZN14ActorCollision16onCollisionQuakeENS_18QuakeCollisionTypeE = 0x002E2044;
_ZN14ActorCollision15onCollisionLavaEP9ActorBase = 0x002E23EC;
_ZN14ActorCollision21getLiquidSpeedScalarXEv = 0x002E2448;
_ZN14ActorCollision12getUnkSpeedYEf = 0x002E23D8;

/* functions */
_ZN14ActorCollision21applyFallAccelerationEv = 0x00430C0C;
_ZN14ActorCollision15processMovementEv = 0x002E2648;
_ZN14ActorCollision10isSquishedEv = 0x002E1E9C;
_ZN14ActorCollision20collisionMgrRelated2Ev = 0x002E25D0;
_ZN14ActorCollision18applyAccelerationYEv = 0x00430E08;

_ZGVZN14ActorCollision24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603828;
_ZZN14ActorCollision24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060382C;

_ZTVN4sead15RuntimeTypeInfo6DeriveI14ActorCollisionEE = 0x005D1D5C;
_ZNK4sead15RuntimeTypeInfo6DeriveI14ActorCollisionE9isDerivedEPKNS0_9InterfaceE = 0x00567718;


/* ActorState */

/* ctor */
_ZN10ActorStateC1Ev = 0x001C79C8;
_ZN10ActorStateC2Ev = 0x001C79C8;

/* virtual functions */
_ZNK10ActorState18getRuntimeTypeInfoEv = 0x00496FC4;

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


/* LiquidTopRenderer */
_ZN17LiquidTopRenderer11swapBuffersEv = 0x002FCF10;
_ZN17LiquidTopRenderer11drawSegmentEj = 0x002FCEEC;


/* DiveInWater */

/* ctor */
_ZN11DiveInWaterC1Ev = 0x00224CA8;
_ZN11DiveInWaterC2Ev = 0x00224CA8;

/* vtable */
_ZTV11DiveInWater = 0x005A5084;

_ZN11DiveInWater9onExecuteEv = 0x00224C40;
_ZN11DiveInWater6onDrawEv = 0x00224B80;
_ZN11DiveInWater8onDeleteEv = 0x00224C64;

_ZN11DiveInWater11createModelEv = 0x00224504;
_ZN11DiveInWater17updateModelMatrixEv = 0x00224484;


/* FlagSwitchBase */
_ZTV14FlagSwitchBase = 0x005B1E1C;
_ZN14FlagSwitchBaseC1Ev = 0x002E9D64;
_ZN14FlagSwitchBaseC2Ev = 0x002E9D64;

_ZN14FlagSwitchBase9onExecuteEv = 0x002E9D30;
_ZN14FlagSwitchBase7preDrawEv = 0x002E9D54;
_ZN14FlagSwitchBase10culllCheckEv = 0x002E9C00;
_ZN14FlagSwitchBase9getPlayerEv = 0x002E9CD8;
_ZNK14FlagSwitchBase18getRuntimeTypeInfoEv = 0x004A1BF0;
_ZGVZN14FlagSwitchBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603858;
_ZZN14FlagSwitchBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060385C;
_ZTVN4sead15RuntimeTypeInfo6DeriveI14FlagSwitchBaseEE = 0x005D1D68;
_ZNK4sead15RuntimeTypeInfo6DeriveI14FlagSwitchBaseE9isDerivedEPKNS0_9InterfaceE = 0x0056778C;

/* LiftBase */
_ZTV8LiftBase = 0x005CC2DC;
_ZN8LiftBaseC1Ev = 0x004204F0;
_ZN8LiftBaseC2Ev = 0x004204F0;
_ZN8LiftBase12updateLiquidEf = 0x0041FFF8;
_ZN8LiftBase17initScaleAndDepthERN4sead7Vector3IfEERf = 0x0042015C;
_ZN8LiftBase12hasPlayersOnERK11BgCollisiona = 0x00420180;
_ZN8LiftBase15getPlayerOnMaskERK11BgCollision = 0x00420240;
_ZN8LiftBase16getPlayerOnCountERK11BgCollision = 0x004202C0;
_ZN8LiftBase17createBreakEffectERKN4sead7Vector3IfEEf = 0x00420354;

/* WireLine */

/* ctor */
_ZN8WireLineC1Ev = 0x0042F3C8;
_ZN8WireLineC2Ev = 0x0042F3C8;

/* states */
_ZN8WireLine14StateID_ActiveE = 0x006198FC;

/* static members */
_ZN8WireLine6speedsE = 0x0057E1F0;

/* Enemy */

/* ctor */
_ZN5EnemyC1Ev = 0x003AD534;
_ZN5EnemyC2Ev = 0x003AD534;

/* vtable */
_ZTV5Enemy = 0x005C3760;

/* virtual functions */
_ZN5Enemy10preExecuteEv = 0x003AB858;
_ZN15PlayerDownTimer12updateTimersEv = 0x002E8478;
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
_ZN5Enemy14checkComboClapEj = 0x004A69A4;
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
_ZN5Enemy13onDefeatQuakeEN14ActorCollision18QuakeCollisionTypeEa = 0x003AC6BC;
_ZN5Enemy11isQuakeableEv = 0x004A680C;
_ZN5Enemy14deathSoundFireEv = 0x004A6C34;
_ZN5Enemy17deathSoundHipDropEv = 0x004A6D90;
_ZN5Enemy8onDefeatEv = 0x003AD310;
_ZN5Enemy11fumiJumpSetEP10PlayerBase = 0x004A6644;
_ZN5Enemy9giveScoreEP10PlayerBase = 0x004A669C;
_ZN5Enemy10sub_4A6C48EN8ScoreMgr10RewardTypeEii = 0x004A6C48;
_ZN5Enemy15mameFumiJumpSetEP10PlayerBase = 0x004A6A14;
_ZN5Enemy6fumiSEEP10PlayerBase = 0x004A6DC4;
_ZN5Enemy10fumiEffectEP10PlayerBase = 0x004A64BC;
_ZN5Enemy10mameFumiSEEv = 0x004A64F4;
_ZN5Enemy14mameFumiEffectEP10PlayerBase = 0x004A69C8;
_ZN5Enemy15hitEffectCommonERKN4sead7Vector2IfEE = 0x004A69CC;
_ZN5Enemy16hitEffectHipDropERKN4sead7Vector2IfEE = 0x004A67C4;
_ZN5Enemy14hitEffectQuakeERKN4sead7Vector2IfEE = 0x004A6C28;
_ZN5Enemy13doQuakeBounceEv = 0x003AB840;
_ZN5Enemy16isInRangeOfQuakeEv = 0x004A65CC;
_ZN5Enemy23initializeState_DieFumiEv = 0x003AD184;
_ZN5Enemy20executeState_DieFumiEv = 0x003ACF9C;
_ZN5Enemy21finalizeState_DieFumiEv = 0x003AD164;
_ZN5Enemy23initializeState_DieFallEv = 0x003AD17C;
_ZN5Enemy20executeState_DieFallEv = 0x003ACECC;
_ZN5Enemy21finalizeState_DieFallEv = 0x003AD15C;
_ZN5Enemy24initializeState_DieSmokeEv = 0x003AD38C;
_ZN5Enemy21executeState_DieSmokeEv = 0x003AD154;
_ZN5Enemy22finalizeState_DieSmokeEv = 0x003AD174;
_ZN5Enemy24initializeState_DieOtherEv = 0x003AD388;
_ZN5Enemy21executeState_DieOtherEv = 0x003AD150;
_ZN5Enemy22finalizeState_DieOtherEv = 0x003AD16C;

/* functions */
_ZN5Enemy9fumiCheckEP19ActorCollisionCheckS1_NS_14FumiEffectTypeE = 0x004A68B8;
_ZN5Enemy11getFumiTypeEPvPNS_20PlayerCollisionEventE = 0x0049ED50;
_ZN5Enemy13killWithStateEP9ActorBaseRKN4sead7Vector2IfEERK7StateID = 0x003AC404;
_ZN5Enemy9giveScoreERKN4sead7Vector3IfEEN8ScoreMgr10RewardTypeEa = 0x004A6A98;
_ZN5Enemy19getDirectionToActorEP9ActorBase = 0x00432080;
_ZN5Enemy17setDeathInfo_FallEhaN8ScoreMgr10RewardTypeE = 0x003ACC90;

/* static members */
_ZN5Enemy15StateID_DieFumiE = 0x0060EE80;
_ZN5Enemy15StateID_DieFallE = 0x0060EEA4;
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

/* Combo */
_ZN5ComboC1Ev = 0x001CEA74;
_ZN5Combo13getComboScoreEj = 0x00497404;
_ZN5Combo13getQuakeScoreEj = 0x00497448;
_ZN5Combo14getDamageScoreEv = 0x0049746C;
_ZN5Combo8setScoreEP9ActorBaseN8ScoreMgr10RewardTypeEa = 0x00497480;

/* Carry */

/* ctor */
_ZN5CarryC1Ev = 0x003AB7F4;
_ZN5CarryC2Ev = 0x003AB7F4;

/* vtable */
_ZTV5Carry = 0x005C3544;

/* virtual functions */
_ZNK5Carry18getRuntimeTypeInfoEv = 0x004A63F4;
_ZN5Carry15collisionPlayerEP19ActorCollisionCheckS1_ = 0x003AAF3C;
_ZN5Carry5vf1D4Ev = 0x003AAA9C;
_ZN5Carry13reactFumiProcEP9ActorBase = 0x003AB10C;
_ZN5Carry17reactMameFumiProcEP9ActorBase = 0x003AAC90;
_ZN5Carry21collisionPlayer_AwakeEP19ActorCollisionCheckS1_ = 0x003AACE0;
_ZN5Carry21collisionPlayer_SleepEP19ActorCollisionCheckS1_ = 0x003AB7F0;

_ZN5Carry13StateID_CarryE = 0x0060E554;
_ZN5Carry21initializeState_CarryEv = 0x003AB778;
_ZN5Carry18executeState_CarryEv = 0x003AB540;
_ZN5Carry19finalizeState_CarryEv = 0x003AB6B0;

_ZN5Carry13StateID_SleepE = 0x0060E578;
_ZN5Carry21initializeState_SleepEv = 0x003AB444;
_ZN5Carry18executeState_SleepEv = 0x003AAF30;
_ZN5Carry19finalizeState_SleepEv = 0x003AB0CC;

_ZN5Carry13StateID_SlideE = 0x0060E59C;
_ZN5Carry21initializeState_SlideEv = 0x003AB448;
_ZN5Carry18executeState_SlideEv = 0x003AAF34;
_ZN5Carry19finalizeState_SlideEv = 0x003AB0E0;

/* functions */
_ZN5Carry22setSlideCollisionCheckEv = 0x003AAAA0;
_ZN5Carry24resetSlideCollisionCheckEv = 0x003AAB20;
_ZN5Carry10sub_3AAB38EP19ActorCollisionCheckS1_ = 0x003AAB38;
_ZN5Carry24setSlideBgCollisionCheckEv = 0x003AAC94;
_ZN5Carry10sub_3AAD50EP19ActorCollisionCheckS1_ = 0x003AAD50;
_ZN5Carry26resetSlideBgCollisionCheckEv = 0x003AB050;
_ZN5Carry10sub_3AB09CEP9ActorBase = 0x003AB09C;
_ZN5Carry10sub_3AB110EP9ActorBase = 0x003AB110;
_ZN5Carry10sub_3AB424EP19ActorCollisionCheck = 0x003AB424;
_ZN5Carry15setDeathInfoUnkEP9ActorBaseb = 0x003AB490;
_ZN5Carry16getCarryPositionERN4sead7Vector3IfEE = 0x003ABA6C;

/* static members */
_ZN5Carry13StateID_CarryE = 0x0060E554;
_ZN5Carry16StateID_LiftableE = 0x0060E578;
_ZN5Carry13StateID_ThrowE = 0x0060E59C;

_ZGVZN5Carry24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603BE0;
_ZZN5Carry24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603BE4;

_ZTVN4sead15RuntimeTypeInfo6DeriveI5CarryEE = 0x005D1E7C;
_ZNK4sead15RuntimeTypeInfo6DeriveI5CarryE9isDerivedEPKNS0_9InterfaceE = 0x005681F8;


/* Shell */
_ZTV5Shell = 0x005C4FA0;
_ZN5ShellC1Ev = 0x003C277C;
_ZN5Shell8onCreateEv = 0x003C24BC;
_ZN5Shell8onDeleteEv = 0x003C25B0;
_ZN5Shell10preExecuteEv = 0x003BF628;
_ZN5Shell9onExecuteEv = 0x003C25A8;
_ZN5Shell11postExecuteEN5fBase6ResultE = 0x003BF6FC;
_ZN5Shell18getRuntimeTypeInfoEv = 0x004A7770;
_ZN5Shell12setCarryFallEPS_i = 0x003BF748;
_ZN5Shell18isSpinLiftUpEnableEv = 0x004A77BC;
_ZN5Shell12powActivatedEv = 0x003BF888;
_ZN5Shell5vf114Ev = 0x003C0C08;
_ZN5Shell5vf11CEv = 0x003BFC50;
_ZN5Shell22collisionHandlerActorsEP19ActorCollisionCheckS1_ = 0x003C0224;
_ZN5Shell14collisionEnemyEP19ActorCollisionCheckS1_ = 0x003C134C;
_ZN5Shell15collisionPlayerEP19ActorCollisionCheckS1_ = 0x003AAF38;
_ZN5Shell20collisionGroundPoundEP19ActorCollisionCheckS1_ = 0x003C1304;
_ZN5Shell20collisionTanookiTailEP19ActorCollisionCheckS1_ = 0x003C02C0;
_ZN5Shell14collisionShellEP19ActorCollisionCheckS1_ = 0x003C0760;
_ZN5Shell11fumiJumpSetEP10PlayerBase = 0x004A7660;
_ZN5Shell9giveScoreEP10PlayerBase = 0x004A7704;
_ZN5Shell15StateID_DieFallE = 0x00611888;
_ZN5Shell23initializeState_DieFallEv = 0x003C2190;
_ZN5Shell20executeState_DieFallEv = 0x003C17FC;
_ZN5Shell21finalizeState_DieFallEv = 0x003C18C4;
_ZN5Shell5vf1D4Ev = 0x003BF778;
_ZN5Shell13reactFumiProcEP9ActorBase = 0x003C1634;
_ZN5Shell21collisionPlayer_AwakeEP19ActorCollisionCheckS1_ = 0x003C08F8;
_ZN5Shell21collisionPlayer_SleepEP19ActorCollisionCheckS1_ = 0x003BFA0C;
_ZN5Shell13StateID_CarryE = 0x006117D4;
_ZN5Shell21initializeState_CarryEv = 0x003C224C;
_ZN5Shell18executeState_CarryEv = 0x003C1B40;
_ZN5Shell19finalizeState_CarryEv = 0x003C215C;
_ZN5Shell13StateID_SleepE = 0x006117B0;
_ZN5Shell21initializeState_SleepEv = 0x003C18C8;
_ZN5Shell18executeState_SleepEv = 0x003C0C80;
_ZN5Shell19finalizeState_SleepEv = 0x003C1514;
_ZN5Shell11createShellEv = 0x003C08EC;
_ZN5Shell12setEnemyTurnEv = 0x003BF774;
_ZN5Shell18setAfterSleepStateEv = 0x003C14C0;
_ZN5Shell10isDieShellEv = 0x003BF740;
_ZN5Shell8turnProcEv = 0x003C2644;
_ZN5Shell10checkSleepEv = 0x003C0144;
_ZN5Shell5vf224Ev = 0x003C08E4;
_ZN5Shell15setPlayerDamageEP9ActorBase = 0x003C046C;
_ZN5Shell5vf22CEv = 0x0;
_ZN5Shell15isBlockHitDeathEv = 0x003C0464;
_ZN5Shell13isFumiInvalidEv = 0x004A7768;
_ZN5Shell11slideEffectEv = 0x003C08F4;
_ZN5Shell18StateID_ShellSlideE = 0x006117F8;
_ZN5Shell26initializeState_ShellSlideEv = 0x003C195C;
_ZN5Shell23executeState_ShellSlideEv = 0x003C0E20;
_ZN5Shell24finalizeState_ShellSlideEv = 0x003C153C;
_ZN5Shell14StateID_WakeupE = 0x0061181C;
_ZN5Shell22initializeState_WakeupEv = 0x003C1F94;
_ZN5Shell19executeState_WakeupEv = 0x003C14C8;
_ZN5Shell20finalizeState_WakeupEv = 0x003C18C0;
_ZN5Shell18StateID_WakeupTurnE = 0x00611840;
_ZN5Shell26initializeState_WakeupTurnEv = 0x003C23E8;
_ZN5Shell23executeState_WakeupTurnEv = 0x003C2110;
_ZN5Shell24finalizeState_WakeupTurnEv = 0x003C2248;
_ZN5Shell21StateID_WakeupReverseE = 0x00611864;
_ZN5Shell29initializeState_WakeupReverseEv = 0x003C2424;
_ZN5Shell26executeState_WakeupReverseEv = 0x003C2360;
_ZN5Shell27finalizeState_WakeupReverseEv = 0x003C2420;
_ZN5Shell13StateID_BoundE = 0x006118AC;
_ZN5Shell21initializeState_BoundEv = 0x003C2320;
_ZN5Shell18executeState_BoundEv = 0x003C1D14;
_ZN5Shell19finalizeState_BoundEv = 0x003C218C;
_ZN5Shell12setKickSlideEP19ActorCollisionCheckS1_b = 0x003BFA14;
_ZN5Shell14calcShellModelEv = 0x003BFC58;
_ZN5Shell13smoothRotateYEii = 0x003C026C;
_ZN5Shell11flipUprightEibb = 0x003C0474;
_ZN5Shell15checkMugenComboEP9ActorBase = 0x003C04E8;
_ZN5Shell18setSlideThrowSpeedEP9ActorBaseb = 0x003C1770;
_ZN5Shell9stopSlideEv = 0x003C1FE4;
_ZN5Shell9cullCheckEj = 0x003C264C;
_ZN5Shell9drawShellEv = 0x003C26EC;

_ZGVZN5Shell24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603C18;
_ZZN5Shell24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603C1C;


_ZTVN4sead15RuntimeTypeInfo6DeriveI5ShellEE = 0x005D1EA0;
_ZNK4sead15RuntimeTypeInfo6DeriveI5ShellE9isDerivedEPKNS0_9InterfaceE = 0x00568354;


/* Nokonoko */
_ZTV8Nokonoko = 0x005CC910;
_ZN8NokonokoC1Ev = 0x00425290;
_ZN8NokonokoD0Ev = 0x0042532C;
_ZN8Nokonoko8onCreateEv = 0x00424770;
_ZN8Nokonoko8onDeleteEv = 0x00424E0C;
_ZN8Nokonoko10preExecuteEv = 0x00422DCC;
_ZN8Nokonoko9onExecuteEv = 0x00424B78;
_ZN8Nokonoko6onDrawEv = 0x00424674;
_ZN8Nokonoko18getRuntimeTypeInfoEv = 0x004ADCC0;
_ZN8Nokonoko12damagePlayerEP9ActorBase = 0x004251C4;
_ZN8Nokonoko14collisionEnemyEP19ActorCollisionCheckS1_ = 0x003C1348;
_ZN8Nokonoko20collisionTanookiTailEP19ActorCollisionCheckS1_ = 0x003C02BC;
_ZN8Nokonoko21initializeState_SleepEv = 0x004240B8;
_ZN8Nokonoko18executeState_SleepEv = 0x003C0C7C;
_ZN8Nokonoko19finalizeState_SleepEv = 0x003C1510;
_ZN8Nokonoko11createShellEv = 0x0042353C;
_ZN8Nokonoko12setEnemyTurnEv = 0x004232EC;
_ZN8Nokonoko18setAfterSleepStateEv = 0x00423AD4;
_ZN8Nokonoko10isDieShellEv = 0x00423290;
_ZN8Nokonoko8turnProcEv = 0x00424E38;
_ZN8Nokonoko11slideEffectEv = 0x004237FC;
_ZN8Nokonoko14StateID_WakeupE = 0x00610D18;
_ZN8Nokonoko22initializeState_WakeupEv = 0x00424178;
_ZN8Nokonoko19executeState_WakeupEv = 0x00423BD8;
_ZN8Nokonoko20finalizeState_WakeupEv = 0x00423DF8;
_ZN8Nokonoko18StateID_WakeupTurnE = 0x00610D3C;
_ZN8Nokonoko26initializeState_WakeupTurnEv = 0x0042454C;
_ZN8Nokonoko23executeState_WakeupTurnEv = 0x004242DC;
_ZN8Nokonoko24finalizeState_WakeupTurnEv = 0x004243D0;
_ZN8Nokonoko5vf278Ev = 0x0;
_ZN8Nokonoko15setInitialStateEv = 0x00423CB0;
_ZN8Nokonoko13danceWithMoveENS_9DanceMoveE = 0x004230AC;
_ZN8Nokonoko9calcModelEv = 0x00424E98;
_ZN8Nokonoko16playerDamageTurnEP9ActorBase = 0x00423D2C;
_ZN8Nokonoko12StateID_WalkE = 0x00610C78;
_ZN8Nokonoko20initializeState_WalkEv = 0x00423EB8;
_ZN8Nokonoko17executeState_WalkEv = 0x00423908;
_ZN8Nokonoko18finalizeState_WalkEv = 0x00423AD0;
_ZN8Nokonoko12StateID_TurnE = 0x00610C98;
_ZN8Nokonoko20initializeState_TurnEv = 0x00423E2C;
_ZN8Nokonoko17executeState_TurnEv = 0x004238A8;
_ZN8Nokonoko18finalizeState_TurnEv = 0x00423ACC;
_ZN8Nokonoko11StateID_2E5E = 0x00610CB8;
_ZN8Nokonoko19initializeState_2E5Ev = 0x004244F8;
_ZN8Nokonoko16executeState_2E5Ev = 0x003C210C;
_ZN8Nokonoko17finalizeState_2E5Ev = 0x00424174;
_ZN8Nokonoko16StateID_BgmDanceE = 0x00610CD8;
_ZN8Nokonoko24initializeState_BgmDanceEv = 0x004243EC;
_ZN8Nokonoko21executeState_BgmDanceEv = 0x00424014;
_ZN8Nokonoko22finalizeState_BgmDanceEv = 0x00424170;
_ZN8Nokonoko18StateID_BgmDanceEdE = 0x00610CF8;
_ZN8Nokonoko26initializeState_BgmDanceEdEv = 0x004245C4;
_ZN8Nokonoko23executeState_BgmDanceEdEv = 0x004242FC;
_ZN8Nokonoko24finalizeState_BgmDanceEdEv = 0x00424548;
_ZN8Nokonoko10checkLedgeEv = 0x00422F7C;
_ZN8Nokonoko11createModelEv = 0x004230CC;
_ZN8Nokonoko12setAnimShellERKN4sead14SafeStringBaseIcEE10PlayPolicyf = 0x00423350;
_ZN8Nokonoko13calcModelNokoEv = 0x004234CC;
_ZN8Nokonoko13syncModelGoldEv = 0x00423AE8;
_ZN8Nokonoko11setAnimBodyERKN4sead14SafeStringBaseIcEE10PlayPolicyf = 0x00424D20;
_ZN8Nokonoko18processBgCollisionEv = 0x0042520C;
_ZNK8Nokonoko8canDanceEv = 0x004ADD0C;
_ZGVZN8Nokonoko24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603DB0;
_ZZN8Nokonoko24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603DB4;
_ZTVN4sead15RuntimeTypeInfo6DeriveI8NokonokoEE = 0x005D1F3C;
_ZNK4sead15RuntimeTypeInfo6DeriveI8NokonokoE9isDerivedEPKNS0_9InterfaceE = 0x00568938;

/* Patapata */
_ZTV8Patapata = 0x005CCBA4;
_ZN8PatapataC1Ev = 0x00426B54;
_ZN8PatapataD0Ev = 0x00426BB4;
_ZN8Patapata8onDeleteEv = 0x00424E08;
_ZN8Patapata10preExecuteEv = 0x004253C4;
_ZN8Patapata6onDrawEv = 0x0042670C;
_ZNK8Patapata18getRuntimeTypeInfoEv = 0x004ADE40;
_ZN8Patapata14collisionEnemyEP19ActorCollisionCheckS1_ = 0x00425C18;
_ZN8Patapata13doQuakeBounceEv = 0x004253C0;
_ZN8Patapata12setEnemyTurnEv = 0x00425508;
_ZN8Patapata15setPlayerDamageEP9ActorBase = 0x004255C8;
_ZN8Patapata15setInitialStateEv = 0x00425D04;
_ZN8Patapata13danceWithMoveEN8Nokonoko9DanceMoveE = 0x00425474;
_ZN8Patapata9calcModelEv = 0x0042682C;
_ZN8Patapata16playerDamageTurnEP9ActorBase = 0x00426084;
_ZNK8Patapata8canDanceEv = 0x004ADE8C;

_ZN8Patapata12StateID_FlyVE = 0x006110D0;
_ZN8Patapata20initializeState_FlyVEv = 0x004265BC;
_ZN8Patapata17executeState_FlyVEv = 0x00425A70;
_ZN8Patapata18finalizeState_FlyVEv = 0x00425D00;

_ZN8Patapata12StateID_FlyHE = 0x006110F0;
_ZN8Patapata20initializeState_FlyHEv = 0x004264DC;
_ZN8Patapata17executeState_FlyHEv = 0x00425808;
_ZN8Patapata18finalizeState_FlyHEv = 0x00425CFC;

_ZN8Patapata12StateID_JumpE = 0x00611110;
_ZN8Patapata20initializeState_JumpEv = 0x004261E4;
_ZN8Patapata17executeState_JumpEv = 0x0042568C;
_ZN8Patapata18finalizeState_JumpEv = 0x00425C14;

_ZN8Patapata16StateID_JumpTurnE = 0x00611130;
_ZN8Patapata24initializeState_JumpTurnEv = 0x00426688;
_ZN8Patapata21executeState_JumpTurnEv = 0x00426304;
_ZN8Patapata22finalizeState_JumpTurnEv = 0x00426684;

_ZN8Patapata15updateDanceAnimEv = 0x00425C1C;
_ZN8Patapata7setAnimERKN4sead14SafeStringBaseIcEE10PlayPolicyf = 0x0042677C;


_ZGVZN8Patapata24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603DB8;
_ZZN8Patapata24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603DBC;


/* TogezoBase */
_ZTV10TogezoBase = 0x005A3898;
_ZN10TogezoBaseC1Ev = 0x0020FA4C;
_ZN10TogezoBase8onCreateEv = 0x0020F4D8;
_ZN10TogezoBase8onDeleteEv = 0x0020F838;
_ZN10TogezoBase9onExecuteEv = 0x0020F5B8;
_ZN10TogezoBase6onDrawEv = 0x0020F430;
_ZNK10TogezoBase18getRuntimeTypeInfoEv = 0x0049A75C;
_ZN10TogezoBase12powActivatedEv = 0x0020D5E0;
_ZN10TogezoBase5vf114Ev = 0x003C0C04;
_ZN10TogezoBase12damagePlayerEP9ActorBase = 0x0020F9D0;
_ZN10TogezoBase14collisionSlideEP19ActorCollisionCheckS1_ = 0x0020DAD4;
_ZN10TogezoBase20collisionTanookiTailEP19ActorCollisionCheckS1_ = 0x0020DB14;
_ZN10TogezoBase11createShellEv = 0x0020DC0C;
_ZN10TogezoBase12setEnemyTurnEv = 0x0020D57C;
_ZN10TogezoBase18setAfterSleepStateEv = 0x0020E610;
_ZN10TogezoBase10isDieShellEv = 0x0020D564;
_ZN10TogezoBase8turnProcEv = 0x0020F9B4;
_ZN10TogezoBase15setPlayerDamageEP9ActorBase = 0x0020DBE4;
_ZN10TogezoBase15isBlockHitDeathEv = 0x0020DB54;
_ZNK10TogezoBase13isFumiInvalidEv = 0x0049A720;

_ZN10TogezoBase14StateID_WakeupE = 0x00611E20;
_ZN10TogezoBase22initializeState_WakeupEv = 0x0020ED0C;
_ZN10TogezoBase19executeState_WakeupEv = 0x003C14C4;
_ZN10TogezoBase20finalizeState_WakeupEv = 0x003C18BC;

_ZN10TogezoBase18StateID_WakeupTurnE = 0x00611E44;
_ZN10TogezoBase26initializeState_WakeupTurnEv = 0x0020F2C0;
_ZN10TogezoBase23executeState_WakeupTurnEv = 0x0020EDE0;
_ZN10TogezoBase24finalizeState_WakeupTurnEv = 0x003C2244;

_ZN10TogezoBase21StateID_WakeupReverseE = 0x00611E68;
_ZN10TogezoBase29initializeState_WakeupReverseEv = 0x0020F3B0;
_ZN10TogezoBase26executeState_WakeupReverseEv = 0x0020F12C;
_ZN10TogezoBase27finalizeState_WakeupReverseEv = 0x0020F308;

_ZN10TogezoBase13StateID_BoundE = 0x00611DFC;
_ZN10TogezoBase21initializeState_BoundEv = 0x0020F084;
_ZN10TogezoBase18executeState_BoundEv = 0x0020EB54;
_ZN10TogezoBase19finalizeState_BoundEv = 0x0020EE00;

_ZN10TogezoBase10initializeEv = 0x0020E654;
_ZNK10TogezoBase13isCullCheckOkEv = 0x0049A718;
_ZN10TogezoBase5vf280Ev = 0x0020D560;
_ZN10TogezoBase5vf284Ev = 0x0;
_ZN10TogezoBase5vf288Ev = 0x0;
_ZN10TogezoBase12isBGMReactOkEv = 0x0049A7A8;

_ZN10TogezoBase11StateID_340E = 0x00611E8C;
_ZN10TogezoBase19initializeState_340Ev = 0x0020ECFC;
_ZN10TogezoBase16executeState_340Ev = 0x0020E64C;
_ZN10TogezoBase17finalizeState_340Ev = 0x0020E73C;

_ZN10TogezoBase11StateID_341E = 0x00611EB0;
_ZN10TogezoBase19initializeState_341Ev = 0x0020F30C;
_ZN10TogezoBase16executeState_341Ev = 0x0020EE50;
_ZN10TogezoBase17finalizeState_341Ev = 0x0020F060;

_ZN10TogezoBase10sub_20D1E0Ev = 0x0020D1E0;
_ZN10TogezoBase11createModelEv = 0x0020D270;
_ZN10TogezoBase12paipoRollingEv = 0x0020D4B0;
_ZN10TogezoBase14calcPaipoModelEv = 0x0020D6A0;
_ZN10TogezoBase15calcTogezoModelEv = 0x0020D794;

_ZN10TogezoBase12StateID_WalkE = 0x00611D3C;
_ZN10TogezoBase20initializeState_WalkEv = 0x0020E844;
_ZN10TogezoBase17executeState_WalkEv = 0x0020E12C;
_ZN10TogezoBase18finalizeState_WalkEv = 0x0020E60C;

_ZN10TogezoBase11StateID_337E = 0x00611D5C;
_ZN10TogezoBase19initializeState_337Ev = 0x0020E740;
_ZN10TogezoBase16executeState_337Ev = 0x0020DCB0;
_ZN10TogezoBase17finalizeState_337Ev = 0x0020E5E8;

_ZN10TogezoBase20StateID_Change_PaipoE = 0x00611D7C;
_ZN10TogezoBase28initializeState_Change_PaipoEv = 0x0020F210;
_ZN10TogezoBase25executeState_Change_PaipoEv = 0x0020ED20;
_ZN10TogezoBase26finalizeState_Change_PaipoEv = 0x0020EE04;

_ZN10TogezoBase21StateID_Change_TogezoE = 0x00611D9C;
_ZN10TogezoBase29initializeState_Change_TogezoEv = 0x0020F360;
_ZN10TogezoBase26executeState_Change_TogezoEv = 0x0020EE54;
_ZN10TogezoBase27finalizeState_Change_TogezoEv = 0x0020F1EC;

_ZN10TogezoBase12StateID_TurnE = 0x00611DBC;
_ZN10TogezoBase20initializeState_TurnEv = 0x0020E780;
_ZN10TogezoBase17executeState_TurnEv = 0x0020E030;
_ZN10TogezoBase18finalizeState_TurnEv = 0x0020E608;

_ZN10TogezoBase13StateID_PaipoE = 0x00611DDC;
_ZN10TogezoBase21initializeState_PaipoEv = 0x0020EA90;
_ZN10TogezoBase18executeState_PaipoEv = 0x0020E3B4;
_ZN10TogezoBase19finalizeState_PaipoEv = 0x0020E650;

_ZN10TogezoBase11setAnimWalkEv = 0x0020E320;
_ZN10TogezoBase19setupCollisionCheckEv = 0x0020E35C;
_ZN10TogezoBase10sub_20E3B0Ev = 0x0020E3B0;
_ZN10TogezoBase17setCollisionPaipoEv = 0x0020E658;
_ZN10TogezoBase18setCollisionTogezoEv = 0x0020E984;
_ZN10TogezoBase13effectDieGoldEv = 0x0020F8E8;

_ZNK10TogezoBase11getTurnStepEv = 0x0049A708;
_ZNK10TogezoBase16getMovementSpeedEh = 0x0049A738;


_ZGVZN10TogezoBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006034C0;
_ZZN10TogezoBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006034C4;

_ZTVN4sead15RuntimeTypeInfo6DeriveI10TogezoBaseEE = 0x005D1C54;
_ZNK4sead15RuntimeTypeInfo6DeriveI10TogezoBaseE9isDerivedEPKNS0_9InterfaceE = 0x00566D20;


/* BrosBase */

/* ctor */
_ZN8BrosBaseC1Ev = 0x0040A100;
_ZN8BrosBaseC2Ev = 0x0040A100;

/* vtable */
_ZTV8BrosBase = 0x005CA840;

/* virtual functions */
_ZN8BrosBase8onCreateEv = 0x00409540;
_ZN8BrosBase8onDeleteEv = 0x00409C68;
_ZN8BrosBase9onExecuteEv = 0x00409B08;
_ZN8BrosBase6onDrawEv = 0x00409508;
_ZN8BrosBase12damagePlayerEP10PlayerBase = 0x0040A088;
_ZN8BrosBase15collisionPlayerEP19ActorCollisionCheckS1_ = 0x00408A90;
_ZN8BrosBase20collisionGroundPoundEP19ActorCollisionCheckS1_ = 0x00408994;
_ZN8BrosBase13doQuakeBounceEv = 0x004081F0;

_ZN8BrosBase15StateID_DieFumiE = 0x0060E388;
_ZN8BrosBase23initializeState_DieFumiEv = 0x00409420;
_ZN8BrosBase20executeState_DieFumiEv = 0x00408F30;
_ZN8BrosBase21finalizeState_DieFumiEv = 0x00409040;

_ZN8BrosBase15StateID_DieFallE = 0x0060E3AC;
_ZN8BrosBase23initializeState_DieFallEv = 0x00409374;
_ZN8BrosBase20executeState_DieFallEv = 0x00408EEC;
_ZN8BrosBase21finalizeState_DieFallEv = 0x0040903C;

_ZN8BrosBase12StateID_WalkE = 0x0060E2B0;
_ZN8BrosBase20initializeState_WalkEv = 0x00408FB0;
_ZN8BrosBase17executeState_WalkEv = 0x004087AC;
_ZN8BrosBase18finalizeState_WalkEv = 0x00408990;

_ZN8BrosBase14StateID_AttackE = 0x0060E2D4;
_ZN8BrosBase22initializeState_AttackEv = 0x0040923C;
_ZN8BrosBase19executeState_AttackEv = 0x00408B38;
_ZN8BrosBase20finalizeState_AttackEv = 0x00408F64;

_ZN8BrosBase14StateID_JumpStE = 0x0060E2F8;
_ZN8BrosBase22initializeState_JumpStEv = 0x00409300;
_ZN8BrosBase19executeState_JumpStEv = 0x00408DD8;
_ZN8BrosBase20finalizeState_JumpStEv = 0x00408F6C;

_ZN8BrosBase12StateID_JumpE = 0x0060E31C;
_ZN8BrosBase20initializeState_JumpEv = 0x00408F70;
_ZN8BrosBase17executeState_JumpEv = 0x0040870C;
_ZN8BrosBase18finalizeState_JumpEv = 0x0040898C;

_ZN8BrosBase14StateID_JumpEdE = 0x0060E340;
_ZN8BrosBase22initializeState_JumpEdEv = 0x00409264;
_ZN8BrosBase19executeState_JumpEdEv = 0x00408D30;
_ZN8BrosBase20finalizeState_JumpEdEv = 0x00408F68;

_ZN8BrosBase18StateID_JumpAttackE = 0x0060E364;
_ZN8BrosBase26initializeState_JumpAttackEv = 0x004094CC;
_ZN8BrosBase23executeState_JumpAttackEv = 0x00409044;
_ZN8BrosBase24finalizeState_JumpAttackEv = 0x00409360;

_ZNK8BrosBase15throwStartFrameEv = 0x004AD5EC;
_ZNK8BrosBase17throwReleaseFrameEv = 0x004AD5E0;
_ZN8BrosBase10changeGoldEv = 0x00408584;
_ZN8BrosBase19createActorCoinBrosEv = 0x0040839C;
_ZN8BrosBase12setWalkSpeedEv = 0x00409CF0;
_ZN8BrosBase5vf230Ev = 0x00000000;
_ZN8BrosBase11getBrosTypeEv = 0x00409CE4;
_ZN8BrosBase17setAttackCooldownEv = 0x0040849C;
_ZN8BrosBase5vf23CEv = 0x00000000;
_ZN8BrosBase12updatePatrolEv = 0x0040826C;
_ZN8BrosBase11updateThrowEv = 0x00408578;
_ZN8BrosBase16createProjectileEv = 0x00408580;
_ZN8BrosBase17releaseProjectileEv = 0x0040857C;
_ZN8BrosBase15setJumpCooldownEv = 0x00408234;
_ZN8BrosBase12setJumpSpeedEv = 0x00409C48;
_ZN8BrosBase18changeToJumpAttackEv = 0x00409D28;
_ZN8BrosBase5vf25CEv = 0x00408494;
_ZNK8BrosBase19attackWhileGroundedEv = 0x004AD5D8;
_ZN8BrosBase14changeToAttackEv = 0x00409CF4;
_ZN8BrosBase17setThrowAnimationEv = 0x00408538;
_ZN8BrosBase5vf26CEv = 0x00408484;
_ZN8BrosBase5vf270Ev = 0x0040A084;
_ZN8BrosBase5vf274Ev = 0x00409CEC;

_ZNK8BrosBase14isCollidedWallEv = 0x004084E8;
_ZN8BrosBase7setAnimERKN4sead14SafeStringBaseIcEE10PlayPolicyf = 0x004097D8;
_ZNK8BrosBase18projectilePositionEv = 0x0040831C;
_ZN8BrosBase16processCollisionEv = 0x00409C4C;
_ZN8BrosBase9calcModelEv = 0x00409904;

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
_ZN10KillerBase23initializeState_DieFumiEv = 0x001DF12C;
_ZN10KillerBase20executeState_DieFumiEv = 0x001DF018;
_ZN10KillerBase21finalizeState_DieFumiEv = 0x003AD160;
_ZN10KillerBase23initializeState_DieFallEv = 0x001DF078;
_ZN10KillerBase20executeState_DieFallEv = 0x001DEF9C;
_ZN10KillerBase21finalizeState_DieFallEv = 0x001DF074;
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
_ZN8DoorBase12StateID_OpenE = 0x00615D08;
_ZN8DoorBase13StateID_CloseE = 0x00615D2C;
_ZN8DoorBase12StateID_IdleE = 0x00615D50;
_ZN8DoorBase14StateID_VanishE = 0x00615D74;
_ZN8DoorBase5vf20CEv = 0x0;
_ZN8DoorBase5vf210Ev = 0x0;

_ZNK8DoorBase18getRuntimeTypeInfoEv = 0x004AD644;
_ZGVZN8DoorBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D58;
_ZZN8DoorBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D5C;

/* TarzanIvy */

/* vtable */
_ZTV9TarzanIvy = 0x005D0690;

/* dtor */
_ZN9TarzanIvyD0Ev = 0x0453374;

_ZN9TarzanIvyD2Ev = 0x0453374;

/* virtual functions */
_ZN9TarzanIvy8onCreateEv = 0x0452C04;
_ZN9TarzanIvy8onDeleteEv = 0x0452D04;
_ZN9TarzanIvy9onExecuteEv = 0x0452C8C;
_ZN9TarzanIvy6onDrawEv = 0x0452BEC;
_ZN9TarzanIvy5vf110Ev = 0x00000000;
_ZN9TarzanIvy5vf114Ev = 0x0452FCC;
_ZN9TarzanIvy5vf118Ev = 0x0452D38;


/* BlockBase */
_ZTV9BlockBase = 0x005CDEB0;   /* 0x005CDEB8 */
_ZN9BlockBaseC1Ev = 0x004349C0;
_ZN9BlockBaseC2Ev = 0x004349C0;
_ZN9BlockBase15isRightOfPlayerEP12PlayerObject = 0x00431FD0;
_ZN9BlockBase10sub_432BC0Ev = 0x00432BC0;
_ZN9BlockBase24resolveStarChainContentsEPNS_8ContentsEh = 0x00432D3C;
_ZN9BlockBase18initalizeCollisionEv = 0x00432D94;
_ZN9BlockBase22bottomCallbackInactiveEP11BgCollisionP21ActorBgCollisionCheck = 0x00432DFC;
_ZN9BlockBase40adjacentCallbackInactiveCallbackInactiveEP11BgCollisionP21ActorBgCollisionCheck9Direction = 0x00433054;
_ZN9BlockBase10sub_43326CEP12PlayerObject = 0x0043326C;
_ZN9BlockBase10sub_43332CERKN4sead7Vector3IfEEjjjj = 0x0043332C;
_ZN9BlockBase9spawnItemERKN4sead7Vector3IfEEjjjb = 0x0043345C;
_ZN9BlockBase22spawnGoldBlockEruptionEv = 0x0043358C;
_ZN9BlockBase14topCallbackUnkEP11BgCollisionP21ActorBgCollisionCheck = 0x004336A4;
_ZN9BlockBase10sub_433754Ev = 0x00433754;
_ZN9BlockBase10sub_433768Ef = 0x00433768;
_ZN9BlockBase10sub_43383CEv = 0x0043383C;
_ZN9BlockBase10sub_43384CEv = 0x0043384C;
_ZN9BlockBase10sub_433990ERKN4sead7Vector3IfEEjjjj = 0x00433990;
_ZN9BlockBase10sub_433A1CERKN4sead7Vector3IfEEjjj = 0x00433A1C;
_ZN9BlockBase19topCallbackInactiveEP11BgCollisionP21ActorBgCollisionCheck = 0x00433C74;
_ZN9BlockBase10sub_433EB0EP11BgCollisionP21ActorBgCollisionCheck = 0x00433EB0;
_ZN9BlockBase10sub_43406CEP11BgCollisionP21ActorBgCollisionCheck = 0x0043406C;
_ZN9BlockBase10sub_434170EP11BgCollisionP21ActorBgCollisionCheck9Direction = 0x00434170;
_ZN9BlockBase10isHitShellEP5ShellP19ActorCollisionCheckh = 0x00434284;
_ZN9BlockBase13spawnContentsERKN4sead7Vector3IfEEjjjb = 0x004343B8;
_ZN9BlockBase20collisionCallbackTopEP11BgCollisionP21ActorBgCollisionCheck = 0x0043446C;

_ZNK9BlockBase18getRuntimeTypeInfoEv = 0x004AE4A0;

_ZN9BlockBase13onUpMoveStartEv = 0x00432D34;
_ZN9BlockBase15onDownMoveStartEv = 0x00433450;
_ZN9BlockBase20onDownMoveSpawnStartEv = 0x0043450C;
_ZN9BlockBase8onUpMoveEv = 0x00432A20;
_ZN9BlockBase11spawnItemUpEv = 0x00432D38;
_ZN9BlockBase10onDownMoveEv = 0x00432A28;
_ZN9BlockBase13onDownMoveEndEv = 0x00433458;
_ZN9BlockBase13spawnItemUpEv = 0x00433454;
_ZN9BlockBase18onDownMoveSpawnEndEv = 0x0043454C;
_ZN9BlockBase13doScaleEffectEh = 0x00432A2C;
_ZN9BlockBase12spawnJumpdaiEv = 0x00432AA8;
_ZN9BlockBase14spawnHatenaCapEv = 0x00433930;
_ZN9BlockBase12changeToCoinEv = 0x00432A24;

_ZN9BlockBase14StateID_UpMoveE = 0x006150F0;
_ZN9BlockBase22initializeState_UpMoveEv = 0x00433938;
_ZN9BlockBase19executeState_UpMoveEv = 0x00433634;
_ZN9BlockBase20finalizeState_UpMoveEv = 0x00433838;

_ZN9BlockBase17StateID_UpMoveEndE = 0x00615114;
_ZN9BlockBase25initializeState_UpMoveEndEv = 0x00434718;
_ZN9BlockBase22executeState_UpMoveEndEv = 0x00434550;
_ZN9BlockBase23finalizeState_UpMoveEndEv = 0x0043462C;

_ZN9BlockBase16StateID_DownMoveE = 0x00615138;
_ZN9BlockBase24initializeState_DownMoveEv = 0x00434510;
_ZN9BlockBase21executeState_DownMoveEv = 0x004338C0;
_ZN9BlockBase22finalizeState_DownMoveEv = 0x00433934;

_ZN9BlockBase19StateID_DownMoveEndE = 0x0061515C;
_ZN9BlockBase27initializeState_DownMoveEndEv = 0x004347D0;
_ZN9BlockBase24executeState_DownMoveEndEv = 0x004346E4;
_ZN9BlockBase25finalizeState_DownMoveEndEv = 0x00434714;

_ZN9BlockBase19StateID_UpMoveSpawnE = 0x00615180;
_ZN9BlockBase27initializeState_UpMoveSpawnEv = 0x00434728;
_ZN9BlockBase24executeState_UpMoveSpawnEv = 0x00434564;
_ZN9BlockBase25finalizeState_UpMoveSpawnEv = 0x00434634;

_ZN9BlockBase21StateID_DownMoveSpawnE = 0x006151A4;
_ZN9BlockBase29initializeState_DownMoveSpawnEv = 0x00434794;
_ZN9BlockBase26executeState_DownMoveSpawnEv = 0x00434638;
_ZN9BlockBase27finalizeState_DownMoveSpawnEv = 0x00434710;

_ZN9BlockBase24StateID_DownMoveSpawnEndE = 0x006151C8;
_ZN9BlockBase32initializeState_DownMoveSpawnEndEv = 0x004349B0;
_ZN9BlockBase29executeState_DownMoveSpawnEndEv = 0x004347E0;
_ZN9BlockBase30finalizeState_DownMoveSpawnEndEv = 0x004349AC;

_ZGVZN9BlockBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603E10;
_ZZN9BlockBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603E14;

_ZTVN4sead15RuntimeTypeInfo6DeriveI9BlockBaseEE = 0x005D1F78;
_ZNK4sead15RuntimeTypeInfo6DeriveI9BlockBaseE9isDerivedEPKNS0_9InterfaceE = 0x00568B7C;

/* ObjBgCollisionCullCheck */
_ZN23ObjBgCollisionCullCheckC1Ev = 0x0032F378;
_ZN23ObjBgCollisionCullCheck10initializeERKN4sead7Vector3IfEERKNS0_7Vector2IfEES8_RK11BgCollision = 0x0032F314;
_ZN23ObjBgCollisionCullCheck9cullCheckERKN4sead7Vector3IfEE = 0x0032F238;

/* ChangeBlockBase */
_ZTV15ChangeBlockBase = 0x005B4AB8;
_ZN15ChangeBlockBaseC1Ev = 0x00306968;
_ZN15ChangeBlockBaseC2Ev = 0x00306968;
_ZN15ChangeBlockBase10sub_305DBCEv = 0x00305DBC;
_ZN15ChangeBlockBase14handleBlockHitEv = 0x00305FA4;
_ZN15ChangeBlockBase10sub_3061A8Ev = 0x003061A8;
_ZN15ChangeBlockBase13initCullCheckEv = 0x003061E0;
_ZN15ChangeBlockBase19handlePSwitchToggleEv = 0x00306224;
_ZN15ChangeBlockBase9cullCheckEv = 0x00306538;
_ZN15ChangeBlockBase11setTileCoinEv = 0x00306564;
_ZN15ChangeBlockBase12setTileBrickEv = 0x003065B8;
_ZN15ChangeBlockBase17initCollisionCoinEv = 0x00306650;
_ZN15ChangeBlockBase18initCollisionBlockEv = 0x003066E0;

_ZNK15ChangeBlockBase18getRuntimeTypeInfoEv = 0x004A2A94;
_ZN15ChangeBlockBase11spawnItemUpEv = 0x00306514;
_ZN15ChangeBlockBase13spawnItemDownEv = 0x003065AC;
_ZN15ChangeBlockBase12changeToCoinEv = 0x00305DEC;
_ZN15ChangeBlockBase5vf198Ev = 0x00306560;
_ZN15ChangeBlockBase5vf19CEv = 0x00306170;
_ZN15ChangeBlockBase11onDestroyedEv = 0x0030616C;
_ZN15ChangeBlockBase9isChangedEv = 0x00306614;

_ZN15ChangeBlockBase12StateID_CoinE = 0x006159E4;
_ZN15ChangeBlockBase20initializeState_CoinEv = 0x003067E0;
_ZN15ChangeBlockBase17executeState_CoinEv = 0x00306714;
_ZN15ChangeBlockBase18finalizeState_CoinEv = 0x003067D8;

_ZN15ChangeBlockBase13StateID_BlockE = 0x00615A04;
_ZN15ChangeBlockBase21initializeState_BlockEv = 0x003067E4;
_ZN15ChangeBlockBase18executeState_BlockEv = 0x003067B0;
_ZN15ChangeBlockBase19finalizeState_BlockEv = 0x003067DC;

_ZN15ChangeBlockBase11StateID_HitE = 0x00615A24;
_ZN15ChangeBlockBase19initializeState_HitEv = 0x003067E8;
_ZN15ChangeBlockBase16executeState_HitEv = 0x003067E8;
_ZN15ChangeBlockBase17finalizeState_HitEv = 0x003068B8;

_ZGVZN15ChangeBlockBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603918;
_ZZN15ChangeBlockBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060391C;

_ZTVN4sead15RuntimeTypeInfo6DeriveI15ChangeBlockBaseEE = 0x005D1DD4;
_ZNK4sead15RuntimeTypeInfo6DeriveI15ChangeBlockBaseE9isDerivedEPKNS0_9InterfaceE = 0x00567BA0;


/* ActorBlockBase */

/* vtable */
_ZTV14ActorBlockBase = 0x005B0EF8;  /* 0x005B0F00 */

/* ctor */
_ZN14ActorBlockBaseC1Ev = 0x002DECFC;
_ZN14ActorBlockBaseC2Ev = 0x002DECFC;

/* virtual functions */
_ZN14ActorBlockBase9onExecuteEv = 0x002DE9D4;
_ZN14ActorBlockBase6onDrawEv = 0x002DE968;
_ZN14ActorBlockBasee18getRuntimeTypeInfoEv = 0x004A16F0;
_ZN14ActorBlockBase12powActivatedEv = 0x002DD63C;
_ZN14ActorBlockBase20onDownMoveSpawnStartEv = 0x002197AC;
_ZN14ActorBlockBase11spawnItemUpEv = 0x002DD9E0;
_ZN14ActorBlockBase13spawnItemDownEv = 0x002DDFFC;
_ZN14ActorBlockBase18onDownMoveSpawnEndEv = 0x002DE74C;

_ZN14ActorBlockBase17fetchInitialStateEv = 0x002DD8C4;
_ZN14ActorBlockBase5onHitEv = 0x002DD96C;
_ZN14ActorBlockBase14getContentsIdxEv = 0x002DDB34;
_ZN14ActorBlockBase5vf1B4Ev = 0x002DE210;
_ZN14ActorBlockBase5vf1B8Ev = 0x002DDB28;
_ZN14ActorBlockBase7onBreakEv = 0x002DD7E4;
_ZN14ActorBlockBase5vf1C0Ev = 0x002DE144;
_ZN14ActorBlockBase11doCullCheckEv = 0x002DD668;
_ZN14ActorBlockBase5vf1C8Ev = 0x002DDC54;
_ZN14ActorBlockBase5vf1CCEv = 0x002DD970;
_ZN14ActorBlockBase5vf1D0Ev = 0x002DE458;
_ZN14ActorBlockBase20initializeState_WaitEv = 0x002DE82C;
_ZN14ActorBlockBase17executeState_WaitEv = 0x002DD670;
_ZN14ActorBlockBase18finalizeState_WaitEv = 0x002DE5C8;
_ZN14ActorBlockBase23initializeState_HitWaitEv = 0x002DE850;
_ZN14ActorBlockBase20executeState_HitWaitEv = 0x002DE760;
_ZN14ActorBlockBase21finalizeState_HitWaitEv = 0x002DE834;

/* functions */
_ZN14ActorBlockBase7destroyEN9ActorBase15DeathEffectTypeE = 0x002DD584;
_ZN14ActorBlockBase10sub_2DD9E4Ev = 0x002DD9E4;
_ZN14ActorBlockBase10sub_2DDB40Ev = 0x002DDB40;
_ZN14ActorBlockBase15updatePairChildEv = 0x002DDB74;
_ZN14ActorBlockBase20disableGoldBlockFlagEv = 0x002DDC9C;
_ZNK14ActorBlockBase16getBlockContentsEv = 0x002DDCB0;
_ZN14ActorBlockBase10sub_2DDCD0Ej = 0x002DDCD0;
_ZN14ActorBlockBase10sub_2DDE90Ev = 0x002DDE90;
_ZN14ActorBlockBase13linkPairChildEv = 0x002DE020;
_ZN14ActorBlockBase10sub_2DE2F0EPN9ActorBaseEPN10PlayerBaseEj = 0x002DE2F0;
_ZN14ActorBlockBase10sub_2DE3FCEv = 0x002DE3FC;
_ZN14ActorBlockBase10sub_2DE5CCEv = 0x002DE5CC;
_ZNK14ActorBlockBase16getBlockContentsEh = 0x002DE838;
_ZN14ActorBlockBase17spawnHatenaCapPutEh = 0x002DE8C0;
_ZN14ActorBlockBase4initEb = 0x002DEB04;

/* static functions */
_ZN14ActorBlockBase21collisionCallbackSideEP11BgCollisionP21ActorBgCollisionCheckh = 0x002DE854;

/* static members */
_ZN14ActorBlockBase12StateID_WaitE = 0x00613E00;
_ZN14ActorBlockBase15StateID_HitWaitE = 0x00613E24;

_ZGVZN14ActorBlockBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603808;
_ZZN14ActorBlockBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060380C;

_ZTVN4sead15RuntimeTypeInfo6DeriveI14ActorBlockBaseEE = 0x005D1D44;
_ZNK4sead15RuntimeTypeInfo6DeriveI14ActorBlockBaseE9isDerivedEPKNS0_9InterfaceE = 0x00567630;


/* BlockMgr */
_ZN8BlockMgrC1Ev = 0x004043F8;
_ZN8BlockMgr9sInstanceE = 0x005E7BE8;
_ZN8BlockMgr8hitBlockERKNS_12HitBlockInfoE = 0x004033F0;
_ZN8BlockMgr10sub_4038A8ERKN4sead7Vector3IfEE = 0x004038A8;
_ZN8BlockMgr20createActorBlockJumpERKN4sead7Vector2IfEE = 0x00403998;
_ZN8BlockMgr14createInstanceEPN4sead4HeapE = 0x00403A6C;
_ZN8BlockMgr14deleteInstanceEv = 0x00403ACC;
_ZN8BlockMgr7executeEv = 0x00403B08;
_ZN8BlockMgr10breakBlockERKNS_9BreakInfoE = 0x00403B44;
_ZN8BlockMgr13getBlockStateERKN4sead7Vector3IfEEh = 0x00403CC8;
_ZN8BlockMgr13setBlockStateERKN4sead7Vector3IfEENS_10BlockStateEh = 0x00403DD8;
_ZN8BlockMgr18createChikuwaBlockERKN4sead7Vector2IfEEjt = 0x00403F40;
_ZN8BlockMgr21createActorBlockShockERKN4sead7Vector2IfEEa13ActorUniqueID = 0x0040400C;
_ZN8BlockMgr19createYukaBaneChildERKN4sead7Vector2IfEE = 0x00404118;
_ZN8BlockMgr16createBreakBlockERKNS_14BreakBlockInfoE = 0x00404208;
_ZN8BlockMgr19createBlockFragmentERKNS_12FragmentInfoEbb = 0x00404320;

/* BlockMgr::HitInfo */
_ZN8BlockMgr7HitInfoC1Ev = 0x00403F3C;

/* BlockMgr::StateInfo */
_ZN8BlockMgr9StateInfoC1Ev = 0x004038A4;

/* BlockMgr::SingletonDisposer_ */
_ZTVN8BlockMgr18SingletonDisposer_E = 0x005CA178;
_ZN8BlockMgr18SingletonDisposer_D1Ev = 0x004040E4;
_ZN8BlockMgr18SingletonDisposer_15sStaticDisposerE = 0x005E7BEC;


/* ItemBase */
_ZTV8ItemBase = 0x005CBE58;
_ZN8ItemBaseC1Ev = 0x0041E40C;
_ZN8ItemBaseC2Ev = 0x0041E40C;

_ZN8ItemBase8onDeleteEv = 0x0041E3B0;
_ZN8ItemBase6onDrawEv = 0x0041E378;
_ZNK8ItemBase18getRuntimeTypeInfoEv = 0x004ADB90;

_ZN8ItemBase11StateID_382E = 0x00613A40;
_ZN8ItemBase19initializeState_382Ev = 0x0041D3F4;
_ZN8ItemBase16executeState_382Ev = 0x0041CB14;
_ZN8ItemBase17finalizeState_382Ev = 0x0041CE94;

_ZN8ItemBase11StateID_383E = 0x00613A64;
_ZN8ItemBase19initializeState_383Ev = 0x0041E12C;
_ZN8ItemBase16executeState_383Ev = 0x0041DD14;
_ZN8ItemBase17finalizeState_383Ev = 0x0041DF5C;

_ZN8ItemBase11StateID_384E = 0x00613A88;
_ZN8ItemBase19initializeState_384Ev = 0x0041DA24;
_ZN8ItemBase16executeState_384Ev = 0x0041D658;
_ZN8ItemBase17finalizeState_384Ev = 0x0041D878;

_ZN8ItemBase11createModelEv = 0x0;
_ZN8ItemBase11removeModelEv = 0x0041B9F4;
_ZN8ItemBase16decideStateSpawnEv = 0x0041C650;
_ZN8ItemBase15decideStateIdleEv = 0x0041D9D8;
_ZN8ItemBase15changeState_382Ev = 0x0041E08C;
_ZN8ItemBase12setAnimOutUpEv = 0x0041C0A0;
_ZN8ItemBase14setAnimOutDownEv = 0x0041C528;
_ZN8ItemBase11setAnimWaitEv = 0x0041B724;
_ZN8ItemBase17setAnimWaitBubbleEv = 0x0041BFA4;
_ZN8ItemBase14setAnimOutJumpEv = 0x0041B720;
_ZN8ItemBase5vf15CEv = 0x0;
_ZN8ItemBase5vf160Ev = 0x0;
_ZN8ItemBase22setActorCollisionCheckEv = 0x0041C2B0;
_ZN8ItemBase15checkCollectionEv = 0x0041BCB0;
_ZN8ItemBase14setSensorAboveEv = 0x0041CEA0;
_ZN8ItemBase14setSensorBelowEv = 0x0041CECC;
_ZN8ItemBase17setSensorAdjacentEv = 0x0041CEF8;
_ZN8ItemBase16setLiquidGravityEv = 0x0041DF38;
_ZN8ItemBase9calcModelEv = 0x0041B44C;
_ZN8ItemBase17onCollisionGroundEv = 0x0041C340;

_ZNK8ItemBase15horizontalSpeedEj = 0x0041B554;
_ZNK8ItemBase15horizontalSpeedEv = 0x0041B584;
_ZNK8ItemBase15givePlayerStockEa = 0x0041B5B4;
_ZN8ItemBase17doEffectItemTrailEv = 0x0041B728;
_ZN8ItemBase10initializeEv = 0x0041B820;
_ZNK8ItemBase7inWaterEv = 0x0041B9D8;
_ZNK8ItemBase10checkWaterERKN4sead7Vector3IfEE = 0x0041B9DC;
_ZN8ItemBase10sub_41BA38Eb = 0x0041BA38;
_ZN8ItemBase4killEv = 0x0041BC38;
_ZN8ItemBase16handleCollectionENS_16CollectionStatusEa = 0x0041BCB8;
_ZN8ItemBase10sub_41BE98Ev = 0x0041BE98;
_ZN8ItemBase15changeStateIdleEv = 0x0041BFA8;
_ZNK8ItemBase15checkTrampolineEv = 0x0041C00C;
_ZNK8ItemBase14getLayerZDepthEv = 0x0041C03C;
_ZN8ItemBase20enableCollisionCheckEv = 0x0041C08C;
_ZN8ItemBase16updateItemEffectEv = 0x0041C0A4;
_ZN8ItemBase10sub_41C2C8Ev = 0x0041C2C8;
_ZNK8ItemBase13powerUpPlayerEa = 0x0041C304;
_ZNK8ItemBase12checkAreaOutEb = 0x0041C344;
_ZNK8ItemBase14getQuakeSpeedYEv = 0x0041C4B0;
_ZN8ItemBase15getQuakeOffsetYEv = 0x0041C4B0;
_ZN8ItemBase11handleDanceEv = 0x0041C4BC;
_ZN8ItemBase10tryCollectERNS_16CollectionStatusE7Powerupb = 0x0041C52C;
_ZN8ItemBase15getQuakeOffsetYEv = 0x0041C644;
_ZN8ItemBase17collisionCallbackEP19ActorCollisionCheckS1_ = 0x0041CA10;
_ZN8ItemBase13checkSquishedEv = 0x0041CAF0;
_ZN8ItemBase15speedIncrementXEv = 0x0041CCA0;
_ZN8ItemBase10sub_41D87CEv = 0x0041D87C;

_ZN8ItemBase13StateID_OutUpE = 0x006138E0;
_ZN8ItemBase21initializeState_OutUpEv = 0x0041E0B4;
_ZN8ItemBase18executeState_OutUpEv = 0x0041DBB8;
_ZN8ItemBase19finalizeState_OutUpEv = 0x0041DF48;

_ZN8ItemBase15StateID_OutDownE = 0x00613900;
_ZN8ItemBase23initializeState_OutDownEv = 0x0041E300;
_ZN8ItemBase20executeState_OutDownEv = 0x0041DF60;
_ZN8ItemBase21finalizeState_OutDownEv = 0x0041E0A0;

_ZN8ItemBase11StateID_379E = 0x00613920;
_ZN8ItemBase19initializeState_379Ev = 0x0041D654;
_ZN8ItemBase16executeState_379Ev = 0x0041CC98;
_ZN8ItemBase17finalizeState_379Ev = 0x0041CE9C;

_ZN8ItemBase11StateID_37AE = 0x00613940;
_ZN8ItemBase19initializeState_37AEv = 0x0041E034;
_ZN8ItemBase16executeState_37AEv = 0x0041DAB8;
_ZN8ItemBase17finalizeState_37AEv = 0x0041DF34;

_ZN8ItemBase11StateID_37BE = 0x00613960;
_ZN8ItemBase19initializeState_37BEv = 0x0041D874;
_ZN8ItemBase16executeState_37BEv = 0x0041CE68;
_ZN8ItemBase17finalizeState_37BEv = 0x0041D270;

_ZN8ItemBase11StateID_37CE = 0x00613980;
_ZN8ItemBase19initializeState_37CEv = 0x0041D90C;
_ZN8ItemBase16executeState_37CEv = 0x0041CF64;
_ZN8ItemBase17finalizeState_37CEv = 0x0041D3EC;

_ZN8ItemBase11StateID_37DE = 0x006139A0;
_ZN8ItemBase19initializeState_37DEv = 0x0041D4A0;
_ZN8ItemBase16executeState_37DEv = 0x0041CB88;
_ZN8ItemBase17finalizeState_37DEv = 0x0041CE98;

_ZN8ItemBase11StateID_37EE = 0x006139C0;
_ZN8ItemBase19initializeState_37EEv = 0x0041D718;
_ZN8ItemBase16executeState_37EEv = 0x0041CCAC;
_ZN8ItemBase17finalizeState_37EEv = 0x0041D26C;

_ZN8ItemBase16StateID_OutChestE = 0x006139E0;
_ZN8ItemBase24initializeState_OutChestEv = 0x0041D9DC;
_ZN8ItemBase21executeState_OutChestEv = 0x0041D284;
_ZN8ItemBase22finalizeState_OutChestEv = 0x0041D714;

_ZN8ItemBase20StateID_KinopioThrowE = 0x00613A00;
_ZN8ItemBase28initializeState_KinopioThrowEv = 0x0041D93C;
_ZN8ItemBase25executeState_KinopioThrowEv = 0x0041D150;
_ZN8ItemBase26finalizeState_KinopioThrowEv = 0x0041D3F0;

_ZN8ItemBase11StateID_381E = 0x00613A20;
_ZN8ItemBase19initializeState_381Ev = 0x0041D274;
_ZN8ItemBase16executeState_381Ev = 0x0041C964;
_ZN8ItemBase17finalizeState_381Ev = 0x0041CC9C;

_ZGVZN8ItemBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D90;
_ZZN8ItemBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D94;
_ZTVN4sead15RuntimeTypeInfo6DeriveI8ItemBaseEE = 0x005D1F18;
_ZNK4sead15RuntimeTypeInfo6DeriveI8ItemBaseE9isDerivedEPKNS0_9InterfaceE = 0x005687DC;


/* ItemActorBase */
_ZTV13ItemActorBase = 0x005AD514;
_ZN13ItemActorBaseC1Ev = 0x00294254;
_ZN13ItemActorBaseC2Ev = 0x00294254;

_ZNK13ItemActorBase18getRuntimeTypeInfoEv = 0x0049EE50;
_ZN13ItemActorBase5vf184Ev = 0x00293BB0;
_ZN13ItemActorBase5vf188Ev = 0x00293BB4;
_ZN13ItemActorBase18setHorizontalSpeedEv = 0x00293BB8;

_ZN13ItemActorBase14StateID_MovingE = 0x00613B70;
_ZN13ItemActorBase22initializeState_MovingEv = 0x002941F8;
_ZN13ItemActorBase19executeState_MovingEv = 0x00293CC4;
_ZN13ItemActorBase20finalizeState_MovingEv = 0x00294190;

_ZN13ItemActorBase18StateID_StationaryE = 0x00613B90;
_ZN13ItemActorBase26initializeState_StationaryEv = 0x0041C058;
_ZN13ItemActorBase23executeState_StationaryEv = 0x00294048;
_ZN13ItemActorBase24finalizeState_StationaryEv = 0x00294194;

_ZN13ItemActorBase15StateID_JumpingE = 0x00613BB0;
_ZN13ItemActorBase23initializeState_JumpingEv = 0x00294198;
_ZN13ItemActorBase20executeState_JumpingEv = 0x00293BCC;
_ZN13ItemActorBase21finalizeState_JumpingEv = 0x00294044;

_ZGVZN13ItemActorBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603758;
_ZZN13ItemActorBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x0060375C;
_ZTVN4sead15RuntimeTypeInfo6DeriveI13ItemActorBaseEE = 0x005D1D08;
_ZNK4sead15RuntimeTypeInfo6DeriveI13ItemActorBaseE9isDerivedEPKNS0_9InterfaceE = 0x005673EC;

/* ItemHouseMgr */
_ZN12ItemHouseMgr14isItemHouseUnkEv = 0x00258448;


/* FireFlower */

/* vtable */
_ZTV10FireFlower = 0x005A0060;   /* 0x005A0058 */

/* ctor */
_ZN10FireFlowerC1Ev = 0x001D2F1C;
_ZN10FireFlowerC2Ev = 0x001D2F1C;

/* dtor */
_ZN10FireFlowerD1Ev = 0x001D2F34;
_ZN10FireFlowerD2Ev = 0x001D2F34;

/* virtual functions */
_ZNK10FireFlower18getRuntimeTypeInfoEv = 0x004976C8;
_ZN10FireFlower5buildEv = 0x00557620;
_ZN10FireFlower7destroyEP5fBase = 0x0055B3D0;
_ZN10FireFlower8onCreateEv = 0x001D2E98;
_ZN10FireFlower9onExecuteEv = 0x001D2EDC;
_ZN10FireFlower12powActivatedEv = 0x001D2B64;
_ZN10FireFlower11createModelEv = 0x001D2974;
_ZN10FireFlower15decideIdleStateEv = 0x001D2E70;
_ZN10FireFlower12setAnimOutUpEv = 0x001D2CA0;
_ZN10FireFlower14setAnimOutDownEv = 0x001D2D84;
_ZN10FireFlower11setAnimWaitEv = 0x001D28A0;
_ZN10FireFlower18setAnimaWaitBubbleEv = 0x001D2BD0;
_ZN10FireFlower14setAnimOutJumpEv = 0x001D27D0;
_ZN10FireFlower15checkCollectionEv = 0x001D2B94;
_ZN10FireFlower16setLiquidGravityEv = 0x001D2E84;


/* ItemMgr */
_ZTV7ItemMgr = 0x005AD4FC;
_ZN7ItemMgr9sInstanceE = 0x005E7698;
_ZN7ItemMgrD1Ev = 0x00293BAC;
_ZN7ItemMgrD0Ev = 0x00293BA8;
_ZNK7ItemMgr10createItemERKN4sead7Vector3IfEEx8ItemType = 0x00293300;
_ZN7ItemMgr14createInstanceEPN4sead4HeapE = 0x002933B4;
_ZN7ItemMgr14deleteInstanceEv = 0x0029341C;
_ZNK7ItemMgr14createItemUnk1ERKN4sead7Vector3IfEEy = 0x00293468;
_ZNK7ItemMgr15createItemStockERKN4sead7Vector3IfEE8ItemTypea = 0x00293488;
_ZNK7ItemMgr15createItemBlockERKNS_9SpawnInfoEj = 0x002934DC;
_ZNK7ItemMgr14createItemUnk2ERKNS_9SpawnInfoE = 0x0029360C;
_ZNK7ItemMgr17createItemRedRingERKN4sead7Vector3IfEEja = 0x002936F4;
_ZNK7ItemMgr15createItemDokanERKN4sead7Vector3IfEEjjj = 0x002937A0;
_ZNK7ItemMgr15getPickupEffectE8ItemType = 0x00293890;
_ZNK7ItemMgr14createItemUnk3ERKN4sead7Vector3IfEEja = 0x002938A4;
_ZNK7ItemMgr22canSpawnAdvancePowerupEa = 0x002938E0;
_ZNK7ItemMgr14createItemUnk4ERKN4sead7Vector3IfEERKNS0_7Vector2IfEEj = 0x00293920;
_ZNK7ItemMgr19getNumCoopBonusItemEv = 0x00293964;
_ZNK7ItemMgr11getItemTypeER8ItemTypejb = 0x00293988;
_ZNK7ItemMgr13getItemEffectE8ItemType = 0x00293AA4;
_ZNK7ItemMgr21createItemTreasureBoxERKN4sead7Vector3IfEEja = 0x00293AB8;
_ZNK7ItemMgr12createKinokoERKN4sead7Vector3IfEE = 0x00293AE8;

/* ItemMgr::SingletonDisposer_ */
_ZTVN7ItemMgr18SingletonDisposer_E = 0x005AD4EC;
_ZN7ItemMgr18SingletonDisposer_D1Ev = 0x00293750;
_ZN7ItemMgr18SingletonDisposer_15sStaticDisposerE = 0x005E769C;

/* NokonokoModelMgr */
_ZN16NokonokoModelMgr9sInstanceE = 0x005E2F68;
_ZN16NokonokoModelMgr14createInstanceEPN4sead4HeapE = 0x003217DC;
_ZN16NokonokoModelMgr14deleteInstanceEv = 0x00321838;

_ZN16NokonokoModelMgr12createModelsEv = 0x00320EA0;
_ZN16NokonokoModelMgr13destroyModelsEv = 0x00321478;
_ZN16NokonokoModelMgr13applyEnvLightEv = 0x00321990;


/* KuriboModelMgr */
_ZN14KuriboModelMgr9sInstanceE = 0x005E2F28;
_ZN14KuriboModelMgr14createInstanceEPN4sead4HeapE = 0x002ED4A0;
_ZN14KuriboModelMgr14deleteInstanceEv = 0x002ED5C4;

_ZN14KuriboModelMgr12createModelsEv = 0x002ECE34;
_ZN14KuriboModelMgr13destroyModelsEv = 0x002ED2DC;
_ZN14KuriboModelMgr13applyEnvLightEv = 0x002ED6BC;


/* TeresaModelMgr */
_ZN14TeresaModelMgr9sInstanceE = 0x005E2FB8;
_ZN14TeresaModelMgr14createInstanceEPN4sead4HeapE = 0x002FC5B0;
_ZN14TeresaModelMgr14deleteInstanceEv = 0x002FC60C;

_ZN14TeresaModelMgr12createModelsEv = 0x002FBA8C;
_ZN14TeresaModelMgr13destroyModelsEv = 0x002FC238;
_ZN14TeresaModelMgr13applyEnvLightEv = 0x002FC72C;


/* KillerModelMgr */
_ZN14KillerModelMgr9sInstanceE = 0x005E2F00;
_ZN14KillerModelMgr14createInstanceEPN4sead4HeapE = 0x002EAD2C;
_ZN14KillerModelMgr14deleteInstanceEv = 0x002EAE50;

_ZN14KillerModelMgr12createModelsEv = 0x002EA748;
_ZN14KillerModelMgr13destroyModelsEv = 0x002EAB68;
_ZN14KillerModelMgr13applyEnvLightEv = 0x002EAF48;


/* KaitenHodaiModelMgr */
_ZN19KaitenHodaiModelMgr9sInstanceE = 0x005E2ED8;
_ZN19KaitenHodaiModelMgr14createInstanceEPN4sead4HeapE = 0x0033B67C;
_ZN19KaitenHodaiModelMgr14deleteInstanceEv = 0x0033B6D8;

_ZN19KaitenHodaiModelMgr12createModelsEv = 0x0033AFFC;
_ZN19KaitenHodaiModelMgr13destroyModelsEv = 0x0033B3E8;
_ZN19KaitenHodaiModelMgr13applyEnvLightEv = 0x0033B7F8;


/* PukupukuModelMgr */
_ZN16PukupukuModelMgr9sInstanceE = 0x005E2F90;
_ZN16PukupukuModelMgr14createInstanceEPN4sead4HeapE = 0x00325F58;
_ZN16PukupukuModelMgr14deleteInstanceEv = 0x0032607C;

_ZN16PukupukuModelMgr12createModelsEv = 0x003258F8;
_ZN16PukupukuModelMgr13destroyModelsEv = 0x00325D94;
_ZN16PukupukuModelMgr13applyEnvLightEv = 0x00326174;


/* BossBase */

/* ctor */
_ZN8BossBaseC1Ev = 0x405278;
_ZN8BossBaseC2Ev = 0x405278;

/* virtual functions */
_ZN8BossBase8onCreateEv = 0x4050B8;
_ZN8BossBase10preExecuteEv = 0x404538;
_ZN8BossBase11postExecuteEN5fBase6ResultE = 0x404628;
_ZNK8BossBase18getRuntimeTypeInfoEv = 0x4AD4B4;
_ZN8BossBase15collisionPlayerEP19ActorCollisionCheckS1_ = 0x404ED8;
_ZN8BossBase17collisionStarMegaEP19ActorCollisionCheckS1_ = 0x404A64;
_ZN8BossBase14collisionSlideEP19ActorCollisionCheckS1_ = 0x404A5C;
_ZN8BossBase19collisionFencePunchEP19ActorCollisionCheckS1_ = 0x404ED0;
_ZN8BossBase20collisionGroundPoundEP19ActorCollisionCheckS1_ = 0x404D80;
_ZN8BossBase20collisionTanookiTailEP19ActorCollisionCheckS1_ = 0x404BB8;
_ZN8BossBase14collisionShellEP19ActorCollisionCheckS1_ = 0x404BD0;
_ZN8BossBase17collisionFireballEP19ActorCollisionCheckS1_ = 0x4048A4;
_ZN8BossBase13onDefeatQuakeEN14ActorCollision18QuakeCollisionTypeEaEv = 0x404C44;
_ZN8BossBase11isQuakeableEv = 0x4AD470;
_ZN8BossBase9giveScoreEP10PlayerBaseEv = 0x4AD45C;
_ZN8BossBase23initializeState_DieFumiEv = 0x3AD180;
_ZN8BossBase20executeState_DieFumiEv = 0x404FD4;
_ZN8BossBase21finalizeState_DieFumiEv = 0x405048;
_ZN8BossBase23initializeState_DieFireEv = 0x40507C;
_ZN8BossBase20executeState_DieFireEv = 0x404FC8;
_ZN8BossBase21finalizeState_DieFireEv = 0x40503C;
_ZN8BossBase23initializeState_DieUnk1Ev = 0x4050AC;
_ZN8BossBase20executeState_DieUnk1Ev = 0x405030;
_ZN8BossBase21finalizeState_DieUnk1Ev = 0x405070;
_ZN8BossBase23initializeState_DieUnk2Ev = 0x4050A0;
_ZN8BossBase20executeState_DieUnk2Ev = 0x405024;
_ZN8BossBase21finalizeState_DieUnk2Ev = 0x405064;
_ZN8BossBase23initializeState_DieStarEv = 0x405088;
_ZN8BossBase20executeState_DieStarEv = 0x404FD8;
_ZN8BossBase21finalizeState_DieStarEv = 0x40504C;
_ZN8BossBase23initializeState_DieUnk3Ev = 0x405094;
_ZN8BossBase20executeState_DieUnk3Ev = 0x404FE4;
_ZN8BossBase21finalizeState_DieUnk3Ev = 0x405058;
_ZN8BossBase9demoStartEv = 0x405138;
_ZN8BossBase7demoEndEv = 0x405148;
_ZN8BossBase5vf218Ev = 0x404844;
_ZN8BossBase5vf21CEv = 0x00000000;
_ZN8BossBase5vf220Ev = 0x00000000;
_ZN8BossBase5vf224Ev = 0x00000000;
_ZN8BossBase12hitWasDamageEv = 0x4AD4A4;
_ZN8BossBase9damageRevEi = 0x40449C;
_ZN8BossBase5vf244Ev = 0x00000000;
_ZN8BossBase5vf248Ev = 0x00000000;
_ZN8BossBase5vf250Ev = 0x4AD4AC;
_ZN8BossBase13tenmetsuReadyEv = 0x40483C;
_ZN8BossBase12tenmetsuProcEv = 0x4047E0;
_ZN8BossBase11tenmetsuFinEv = 0x4046D0;
_ZN8BossBase16tenmetsuTimeFireEv = 0x404F84;
_ZN8BossBase17tenmetsuTimeShellEv = 0x00000000;
_ZN8BossBase17tenmetsuTimePressEv = 0x404F8C;
_ZN8BossBase11deadAllKillEv = 0x4045F8;
_ZN8BossBase8fumiProcEP9ActorBase = 0x405160;
_ZN8BossBase13setFumiDamageEP9ActorBase = 0x404828;
_ZN8BossBase11setFumiDeadEP9ActorBase = 0x4046A8;
_ZN8BossBase13setFireDamageEP9ActorBase = 0x404824;
_ZN8BossBase11setFireDeadEP9ActorBase = 0x404694;
_ZN8BossBase15setHipAtkDamageEP9ActorBase = 0x404BC0;
_ZN8BossBase13setHipAtkDeadEP9ActorBase = 0x40482C;
_ZN8BossBase5vf28CEv = 0x00000000;
_ZN8BossBase5vf290Ev = 0x00000000;
_ZN8BossBase13setStarDamageEP9ActorBase = 0x404838;
_ZN8BossBase11setStarDeadEP9ActorBase = 0x4046BC;
_ZN8BossBase14setQuakeDamageEP9ActorBase = 0x404848;
_ZN8BossBase12setQuakeDeadEP9ActorBase = 0x404794;
_ZN8BossBase5vf2A4Ev = 0x00000000;
_ZN8BossBase5vf2A8Ev = 0x00000000;
_ZN8BossBase10damageProcEv = 0x4044C0;
_ZN8BossBase8deadProcEv = 0x405158;
_ZN8BossBase13isFumiInvalidEv = 0x4AD468;
_ZN8BossBase19isFumiDamageInvalidEv = 0x4AD500;
_ZN8BossBase5vf2DCEv = 0x4AD508;
_ZN8BossBase13isFireInvalidEv = 0x4AD460;
_ZN8BossBase5vf2C4Ev = 0x00000000;
_ZN8BossBase5vf2C8Ev = 0x00000000;
_ZN8BossBase13isStarInvalidEv = 0x4AD49C;
_ZN8BossBase14fumiDeadEffectEv = 0x404840;
_ZN8BossBase16fumiDamageEffectEv = 0x404BCC;
_ZN8BossBase13hitFireEffectEv = 0x4047E8;
_ZN8BossBase14hitShellEffectEv = 0x00000000;
_ZN8BossBase12fumiDamageSEEv = 0x404760;
_ZN8BossBase10fumiDeadSEEv = 0x404500;
_ZN8BossBase12starDamageSEEv = 0x4047A8;
_ZN8BossBase10starDeadSEEv = 0x4045BC;
_ZN8BossBase5vf2F0Ev = 0x00000000;
_ZN8BossBase5vf2F4Ev = 0x00000000;
_ZN8BossBase12fireDamageSEEv = 0x4046D8;
_ZN8BossBase10fireDeadSEEv = 0x4044C4;
_ZN8BossBase13quakeDamageSEEv = 0x4047EC;
_ZN8BossBase11quakeDeadSEEv = 0x404658;
_ZN8BossBase10fumiDeadVoEv = 0x4047E4;
_ZN8BossBase9damageSVoEv = 0x00000000;
_ZN8BossBase9damageLVoEv = 0x00000000;
_ZN8BossBase11createModelEv = 0x4046D4;
_ZN8BossBase9calcModelEv = 0x4044BC;
_ZN8BossBase12setHitPointsEv = 0x404790;
_ZN8BossBase14setHitToDamageEv = 0x404D7C;
_ZN8BossBase5setupEv = 0x404620;
_ZN8BossBase12enableLookAtEv = 0x40484C;
_ZN8BossBase13disableLookAtEv = 0x404C2C;

_ZGVZN8BossBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D38;
_ZZN8BossBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D3C;

_ZTVN4sead15RuntimeTypeInfo6DeriveI8BossBaseEE = 0x005D1F00;
_ZNK4sead15RuntimeTypeInfo6DeriveI8BossBaseE9isDerivedEPKNS0_9InterfaceE = 0x005686F4;


/* CoursePlayerInfoMgr */
_ZN19CoursePlayerInfoMgr9sInstanceE = 0x005E9F50;
_ZN19CoursePlayerInfoMgr14createInstanceEPN4sead4HeapE = 0x002F3AEC;
_ZN19CoursePlayerInfoMgr14deleteInstanceEv = 0x002F3B68;
_ZN19CoursePlayerInfoMgr18SingletonDisposer_D1Ev = 0x002F3BA4;
_ZN19CoursePlayerInfoMgr15sStaticDisposerE = 0x005E9F54;
_ZTVN19CoursePlayerInfoMgr18SingletonDisposer_E = 0x005B3108;

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
_ZN8BossDemo7preDrawEv = 0x406C48;
_ZNK8BossDemo18getRuntimeTypeInfoEv = 0x4AD540;

_ZN8BossDemo13StateID_ReadyE = 0x00604918;
_ZN8BossDemo21initializeState_ReadyEv = 0x405EBC;
_ZN8BossDemo18executeState_ReadyEv = 0x405AD8;
_ZN8BossDemo19finalizeState_ReadyEv = 0x405CB0;

_ZN8BossDemo20StateID_BattleStDemoE = 0x0060493C;
_ZN8BossDemo28initializeState_BattleStDemoEv = 0x406B64;
_ZN8BossDemo25executeState_BattleStDemoEv = 0x406A5C;
_ZN8BossDemo26finalizeState_BattleStDemoEv = 0x406AF4;

_ZN8BossDemo16StateID_BattleInE = 0x00604960;
_ZN8BossDemo24initializeState_BattleInEv = 0x405F44;
_ZN8BossDemo21executeState_BattleInEv = 0x405E5C;
_ZN8BossDemo22finalizeState_BattleInEv = 0x405ED0;

_ZN8BossDemo20StateID_BattleEdDemoE = 0x00604984;
_ZN8BossDemo28initializeState_BattleEdDemoEv = 0x406B0C;
_ZN8BossDemo25executeState_BattleEdDemoEv = 0x4060AC;
_ZN8BossDemo26finalizeState_BattleEdDemoEv = 0x406A58;

_ZNK8BossDemo5vf13CEv = 0x4AD520;
_ZNK8BossDemo5vf140Ev = 0x4AD528;
_ZN8BossDemo10killActorsEv = 0x4052BC;
_ZN8BossDemo5vf148Ev = 0x406C70;
_ZN8BossDemo5vf14CEv = 0x406C50;
_ZN8BossDemo12entranceDemoEv = 0x405E4C;
_ZN8BossDemo10doBattleInEv = 0x405C98;
_ZN8BossDemo15preBattleStDemoEv = 0x405430;
_ZN8BossDemo7getBossEv = 0x4052B4;
_ZN8BossDemo11getEndActorEv = 0x000000;
_ZN8BossDemo7createdEv = 0x405438;
_ZNK8BossDemo11hasEndActorEv = 0x405EE8;
_ZN8BossDemo13createEdActorEv = 0x405EC8;
_ZN8BossDemo18isEndActorFinishedEv = 0x405CA4;
_ZN8BossDemo5vf174Ev = 0x405E54;
_ZNK8BossDemo15hasExitSequenceEv = 0x4AD530;
_ZN8BossDemo20closeEntranceShutterEv = 0x405CB4;
_ZN8BossDemo21entranceShutterClosedEv = 0x405958;
_ZN8BossDemo15openExitShutterEv = 0x405B80;
_ZN8BossDemo5vf188Ev = 0x405954;
_ZN8BossDemo5vf18CEv = 0x406AF0;
_ZN8BossDemo17startBattleEdDemoEv = 0x405ED4;
_ZNK8BossDemo14getKokoopaTypeEv = 0x4AD538;
_ZN8BossDemo5vf198Ev = 0x405950;

/* functions */
_ZN8BossDemo16movePlayerToExitEv = 0x0040543C;
_ZNK8BossDemo23getExitShutterPositionXEv = 0x00405FE0;
_ZN8BossDemo14doEntranceWalkEf = 0x4056C8;

_ZGVZN8BossDemo24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D40;
_ZZN8BossDemo24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603D44;

_ZTVN4sead15RuntimeTypeInfo6DeriveI8BossDemoEE = 0x005D1F0C;
_ZNK4sead15RuntimeTypeInfo6DeriveI8BossDemoE9isDerivedEPKNS0_9InterfaceE = 0x00568768;


/* PlayerBase */
_ZN10PlayerBase14incrementComboEv = 0x001CE900;
_ZN10PlayerBase6isDemoEv = 0x00499E7C;
_ZN10PlayerBase11changeStateERK7StateIDjPv = 0x001F3B30;
_ZN10PlayerBase11changeStateERK7StateIDj = 0x001EF3A4;
_ZN10PlayerBase11checkLiquidEv = 0x001EF3AC;
_ZN10PlayerBase15changeStateDemoERK7StateIDj = 0x001F3A1C;
_ZN10PlayerBase15restoreFromDemoEv = 0x001F7190;
_ZN10PlayerBase19checkDisplayOutDeadEv = 0x001F80BC;
_ZN10PlayerBase13checkDispOverEv = 0x001F1E84;
_ZN10PlayerBase14executeLastAllEv = 0x001EF524;
_ZN10PlayerBase15isOnGroundDemoEv = 0x001F2228;
_ZN10PlayerBase10freezeDemoEv = 0x001F5D24;
_ZN10PlayerBase16initDemoGoalBaseEv = 0x001F861C;
_ZN10PlayerBase27calcCollisionCheckPlayerRevEPf = 0x001F36E4;
_ZN10PlayerBase18posMoveAnglePlayerERKN4sead7Vector3IfEE = 0x001F5FEC;
_ZN10PlayerBase13setSandEffectEv = 0x001F23D4;
_ZN10PlayerBase16setAddLiftSpeedFEv = 0x001FD4D8;
_ZN10PlayerBase10setGravityEv = 0x001F2C9C;
_ZN10PlayerBase14setJumpGravityEv = 0x001F2D8C;
_ZN10PlayerBase18setStartJumpEffectEv = 0x001F7558;
_ZN10PlayerBase15setMaxFallSpeedEv = 0x001F9144;
_ZN10PlayerBase18setSimpleMoveSpeedEv = 0x001F7778;
_ZN10PlayerBase12setMoveSpeedEv = 0x001F16C8;
_ZN10PlayerBase11setAirPowerEv = 0x001F0C98;
_ZN10PlayerBase8setPowerEv = 0x001F1B7C;
_ZN10PlayerBase14normalPowerSetEv = 0x001F2EF8;
_ZN10PlayerBase9turnAngleEv = 0x001EF364;
_ZN10PlayerBase9checkSlipEv = 0x001EF0D8;
_ZN10PlayerBase9checkTurnEv = 0x001F27D4;
_ZN10PlayerBase16checkJumpTriggerEv = 0x001F47EC;
_ZN10PlayerBase16checkStandUpRoofEv = 0x001F4830;
_ZN10PlayerBase12getYRotationE9Direction = 0x004996E0;
_ZN10PlayerBase21getSideDirectionAngleE9Direction = 0x001F7250;
_ZN10PlayerBase21spawnRotateTailEffectEv = 0x001F9234;
_ZN10PlayerBase24resetCollisionCheck1DataEv = 0x001F230C;
_ZN10PlayerBase20spawnDashSmokeEffectEv = 0x001F7AB0;
_ZN10PlayerBase8isChangeEv = 0x004998E8;
_ZN10PlayerBase19spawnJumpNoteEffectEv = 0x001F6650;
_ZN10PlayerBase15spawnLandEffectEv = 0x001F7640;
_ZN10PlayerBase10sub_1FE908Ev = 0x001FE908;
_ZN10PlayerBase17executeState_FallEv = 0x001F4BB8;
_ZN10PlayerBase10sub_1F90CCEff = 0x001F90CC;
_ZN10PlayerBase22moveTowardsDemoTargetXEff = 0x001F2A28;
_ZN10PlayerBase22moveTowardsDemoTargetYEff = 0x001F2ACC;

_ZGVZN10PlayerBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603480;
_ZZN10PlayerBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603484;

_ZTVN4sead15RuntimeTypeInfo6DeriveI10PlayerBaseEE = 0x005D1C48;
_ZNK4sead15RuntimeTypeInfo6DeriveI10PlayerBaseE9isDerivedEPKNS0_9InterfaceE = 0x00566CAC;

_ZN10PlayerBase12StateID_NoneE = 0x0061A984;
_ZN10PlayerBase12StateID_WalkE = 0x0061A9A8;
_ZN10PlayerBase16StateID_SideSlideE = 0x0061A9CC;
_ZN10PlayerBase11StateID_SlipE = 0x0061A9F0;
_ZN10PlayerBase11StateID_JumpE = 0x0061AA14;
_ZN10PlayerBase16StateID_HipAttackE = 0x0061AA38;
_ZN10PlayerBase14StateID_CrouchE = 0x0061AA5C;
_ZN10PlayerBase15StateID_SitJumpE = 0x0061AA80;
_ZN10PlayerBase11StateID_FallE = 0x0061AAA4;
_ZN10PlayerBase16StateID_SlowSwimE = 0x0061AAC8;
_ZN10PlayerBase13StateID_CloudE = 0x0061AAEC;
_ZN10PlayerBase12StateID_SwimE = 0x0061AB10;
_ZN10PlayerBase15StateID_JumpDaiE = 0x0061AB34;
_ZN10PlayerBase21StateID_PlayerJumpDaiE = 0x0061AB58;
_ZN10PlayerBase16StateID_WaitJumpE = 0x0061AB7C;
_ZN10PlayerBase13StateID_Unk16E = 0x0061ABA0;
_ZN10PlayerBase13StateID_Unk17E = 0x0061ABC4;
_ZN10PlayerBase13StateID_Unk18E = 0x0061ABE8;

_ZN10PlayerBase16StateID_DemoUnk1E = 0x0061A6A8;
_ZN10PlayerBase16StateID_DemoUnk2E = 0x0061A6CC;
_ZN10PlayerBase16StateID_DemoUnk3E = 0x0061A6F0;
_ZN10PlayerBase16StateID_DemoGoalE = 0x0061A714;
_ZN10PlayerBase16StateID_DemoUnk5E = 0x0061A738;
_ZN10PlayerBase16StateID_DemoWaitE = 0x0061A75C;
_ZN10PlayerBase20StateID_DemoInDokanUE = 0x0061A780;
_ZN10PlayerBase20StateID_DemoInDokanDE = 0x0061A7A4;
_ZN10PlayerBase20StateID_DemoInDokanRE = 0x0061A7C8;
_ZN10PlayerBase20StateID_DemoInDokanLE = 0x0061A7EC;
_ZN10PlayerBase21StateID_DemoOutDokanUE = 0x0061A810;
_ZN10PlayerBase21StateID_DemoOutDokanDE = 0x0061A834;
_ZN10PlayerBase21StateID_DemoOutDokanRE = 0x0061A858;
_ZN10PlayerBase21StateID_DemoOutDokanLE = 0x0061A87C;
_ZN10PlayerBase18StateID_DemoInDoorE = 0x0061A8A0;
_ZN10PlayerBase19StateID_DemoOutDoorE = 0x0061A8C4;
_ZN10PlayerBase17StateID_DemoUnk17E = 0x0061A8E8;
_ZN10PlayerBase25StateID_DemoNextGotoBlockE = 0x0061A90C;
_ZN10PlayerBase16StateID_DemoDownE = 0x0061A930;
_ZN10PlayerBase20StateID_DemoWarpJumpE = 0x0061A954;

_ZN10PlayerBase21splashOutWaterEffectsE = 0x0057F68C;
_ZN10PlayerBase28splashOutWaterShallowEffectsE = 0x0057F692;
_ZN10PlayerBase22powerupChangeYPosTableE = 0x00580BEC;
_ZN10PlayerBase30powerupHeightConversionRelatedE = 0x00580BFC;
_ZN10PlayerBase30playerMegaConversionScaleTableE = 0x00580C28;

/* functions */
_ZN10PlayerBase7playSfxEjj = 0x001F4060;
_ZN10PlayerBase12playVoiceSfxEjj = 0x001F4098;
_ZN10PlayerBase17playFootstepSoundEi = 0x001FA378;
_ZN10PlayerBase19doDiveInWaterEffectEv = 0x001F5BB0;
_ZN10PlayerBase22doSplashOutWaterEffectEv = 0x001F6C2C;
_ZN10PlayerBase20spawnBigChangeEffectEv = 0x001F73F8;
_ZN10PlayerBase12holdSoundArgEjjj = 0x001F29F0;
_ZN10PlayerBase18calcAccelOnIceLiftEv = 0x001F42A0;
_ZN10PlayerBase18calcSpeedOnIceLiftEv = 0x001F7078;
_ZN10PlayerBase18finalizeState_WalkEv = 0x001F5E98;
_ZN10PlayerBase18finalizeState_FallEv = 0x001F5D74;
_ZN10PlayerBase20initializeState_FallEv = 0x001F8AC4;
_ZN10PlayerBase20initializeState_JumpEv = 0x001F8B9C;
_ZN10PlayerBase17executeState_JumpEv = 0x001F4BE4;
_ZN10PlayerBase18finalizeState_JumpEv = 0x001F5DAC;
_ZN10PlayerBase23initializeState_SitJumpEv = 0x001FDC64;
_ZN10PlayerBase18getPowerChangeTypeEi = 0x00499C34;
_ZN10PlayerBase20initializeState_SlipEv = 0x001F8C00;
_ZN10PlayerBase18finalizeState_SlipEv = 0x001F5E4C;
_ZN10PlayerBase18spawnDashAddEffectEv = 0x001F52B0;
_ZN10PlayerBase20spawnDashStartEffectEv = 0x001F74D4;
_ZN10PlayerBase12setFootSoundEv = 0x001F163C;
_ZN10PlayerBase13updateEffectsEv = 0x001F7D24;
_ZN10PlayerBase19updateLiquidEffectsEv = 0x001FAC94;
_ZN10PlayerBase18calcReductionScaleEv = 0x001F6ED8;
_ZN10PlayerBase29createGoldSuperTanookiEffectsEv = 0x001F63B4;
_ZN10PlayerBase20spawnTailWhiteEffectEv = 0x001FB194;
_ZN10PlayerBase16executeDemoStateEv = 0x001F4B44;
_ZN10PlayerBase10sub_1F431CEv = 0x001F431C;
_ZN10PlayerBase16setDelayHelpJumpEv = 0x001F5370;
_ZN10PlayerBase36updateCollisionCheckStarWhiteTanookiEv = 0x001F0E50;
_ZN10PlayerBase28setCollisionCheckTanukiShakeEv = 0x001F0E80;
_ZN10PlayerBase7bgCheckEi = 0x001FF210;


/* PlayerObject */
_ZN12PlayerObject19sizeDefinitionSmallE = 0x00580734;
_ZN12PlayerObject20sizeDefinitionNormalE = 0x005807E8;
_ZN12PlayerObject18sizeDefinitionMiniE = 0x005805EC;
_ZN12PlayerObject18sizeDefinitionMegaE = 0x0058089C;

_ZN12PlayerObject16StateID_SlowSwimE = 0x0061AAC8;
_ZN12PlayerObject18StateID_DemoInJumpE = 0x0061AF24;
_ZN12PlayerObject18StateID_DemoEatDieE = 0x0061AFA4;
_ZN12PlayerObject22StateID_DemoOutRainbowE = 0x0061AFE4;
_ZN12PlayerObject23StateID_DemoDokanCannonE = 0x0061AFC4;
_ZN12PlayerObject16StateID_DemoDownE = 0x0061AF00;
_ZN12PlayerObject20StateID_DemoFallDownE = 0x0061AF64;
_ZN12PlayerObject20StateID_DemoFireDownE = 0x0061AF84;
_ZN12PlayerObject16StateID_DemoGoalE = 0x0061AE94;
_ZN12PlayerObject18StateID_DemoInDoorE = 0x0061AEB8;
_ZN12PlayerObject18StateID_DemoInVineE = 0x0061AF44;
_ZN12PlayerObject19StateID_DemoOutDoorE = 0x0061AEDC;
_ZN12PlayerObject14StateID_CrouchE = 0x0061B0D0;
_ZN12PlayerObject12StateID_FallE = 0x0061B118;
_ZN12PlayerObject12StateID_JumpE = 0x0061B088;
_ZN12PlayerObject18StateID_TanukiJumpE = 0x0061B464;
_ZN12PlayerObject12StateID_SlipE = 0x0061B064;
_ZN12PlayerObject15StateID_SitJumpE = 0x0061B0F4;
_ZN12PlayerObject15StateID_BalloonE = 0x0061B304;
_ZN12PlayerObject16StateID_KaniJumpE = 0x0061B424;
_ZN12PlayerObject17StateID_HipAttackE = 0x0061B0AC;
_ZN12PlayerObject12StateID_WalkE = 0x0061B01C;
_ZN12PlayerObject12StateID_VineE = 0x0061B384;
_ZN12PlayerObject13StateID_CloudE = 0x0061B13C;
_ZN12PlayerObject12StateID_HangE = 0x0061B3C4;
_ZN12PlayerObject15StateID_LandingE = 0x0061B184;
_ZN12PlayerObject12StateID_PoleE = 0x0061B3A4;
_ZN12PlayerObject13StateID_QuakeE = 0x0061B2C4;
_ZN12PlayerObject17StateID_SideSlideE = 0x0061B040;
_ZN12PlayerObject12StateID_SwimE = 0x0061B160;
_ZN12PlayerObject12StateID_FireE = 0x0061B1A4;
_ZN12PlayerObject13StateID_ThrowE = 0x0061B1C4;
_ZN12PlayerObject14StateID_LiftUpE = 0x0061B1E4;
_ZN12PlayerObject16StateID_WallJumpE = 0x0061B224;
_ZN12PlayerObject13StateID_None3E = 0x0061B244;
_ZN12PlayerObject16StateID_RollSlipE = 0x0061B264;
_ZN12PlayerObject17StateID_FlyDamageE = 0x0061B284;
_ZN12PlayerObject13StateID_StoneE = 0x0061B2A4;
_ZN12PlayerObject21StateID_ElectricShockE = 0x0061B2E4;
_ZN12PlayerObject18StateID_CannonJumpE = 0x0061B324;
_ZN12PlayerObject18StateID_CannonWarpE = 0x0061B344;
_ZN12PlayerObject15StateID_JumpUnkE = 0x0061B364;
_ZN12PlayerObject18StateID_TarzanRopeE = 0x0061B3E4;
_ZN12PlayerObject13StateID_None2E = 0x0061B404;
_ZN12PlayerObject19StateID_TanukiShakeE = 0x0061B444;
_ZN12PlayerObject20StateID_HatenaCapGetE = 0x0061B484;
_ZN12PlayerObject17StateID_CannonFlyE = 0x0061B4A4;
_ZN12PlayerObject17StateID_WallSlideE = 0x0061B204;

_ZN12PlayerObject14executeLastAllEv = 0x002637A8;
_ZN12PlayerObject19walkActionInit_WaitEj = 0x0026F264;
_ZN12PlayerObject19walkActionInit_MoveEi = 0x0026F248;
_ZN12PlayerObject10spinLiftUpEP9ActorBasei = 0x002624B8;
_ZN12PlayerObject13setSwimActionEv = 0x00266A58;
_ZN12PlayerObject19setTarzanRopeActionEv = 0x00268644;
_ZN12PlayerObject16setBalloonActionEv = 0x0026BEC4;
_ZN12PlayerObject13setVineActionEv = 0x00266C00;
_ZN12PlayerObject13setPoleActionEv = 0x00266968;
_ZN12PlayerObject13checkWallJumpEv = 0x00266568;
_ZN12PlayerObject17setFireBallActionEv = 0x0026C350;
_ZN12PlayerObject13setEatDieHideEv = 0x00264724;
_ZN12PlayerObject20setEatDieScreamVoiceEv = 0x00271004;
_ZN12PlayerObject14setPowerupDemoEh = 0x00268994;
_ZN12PlayerObject20startDemoDokanCannonERKN4sead7Vector3IfEEb = 0x0026C2B0;
_ZN12PlayerObject14setQuakeActionEv = 0x00272ADC;
_ZN12PlayerObject13setHangActionEv = 0x002710CC;
_ZN12PlayerObject19setTanukiJumpActionEv = 0x002714C4;
_ZN12PlayerObject20setTanukiShakeActionEv = 0x00271200;
_ZN12PlayerObject20setSpinLiftUpReserveEv = 0x00271344;
_ZN12PlayerObject17releaseCarryActorEP9ActorBase = 0x00262AC8;
_ZN12PlayerObject11setJumpInfoEPN10PlayerBase8JumpInfoE = 0x0027C0E0;
_ZN12PlayerObject12setSwimSpeedEff = 0x0026518C;
_ZN12PlayerObject10sub_274584Ev = 0x00274584;
_ZN12PlayerObject21setTanukiTailRotationEv = 0x00274550;
_ZN12PlayerObject11checkCrouchEv = 0x002689B0;

_ZN12PlayerObject15setCenterOffsetEv = 0x002683D8;
_ZN12PlayerObject12updateChangeEv = 0x0026C9B0;
_ZN12PlayerObject13calcStarTimerEv = 0x00265D00;
_ZN12PlayerObject10sub_26B0E0Ev = 0x0026B0E0;
_ZN12PlayerObject19checkSpawnStockItemEv = 0x00267778;
_ZN12PlayerObject13calcMegaTimerEv = 0x002659B0;
_ZN12PlayerObject13calcTimerProcEv = 0x00265DE4;
_ZN12PlayerObject13hatenaCapExecEv = 0x0026577C;
_ZN12PlayerObject10sub_264A10Ev = 0x00264A10;
_ZN12PlayerObject21setCollisionCheckDataEv = 0x002626B4;
_ZN12PlayerObject24updateCollisionCheckMegaEv = 0x00263D40;
_ZN12PlayerObject18clearMegaTimerFlagEv = 0x00266638;
_ZN12PlayerObject23setBgCollisionCheckDataEi = 0x0027C30C;
_ZN12PlayerObject10sub_26B40CEv = 0x0026B40C;
_ZN12PlayerObject24bgCollisionCrouchRelatedEv = 0x0026E658;
_ZN12PlayerObject12executeStateEv = 0x0013878C;
_ZN12PlayerObject15resetTanukiDataEv = 0x0026A04C;
_ZN12PlayerObject8jumpExecEv = 0x0026B004;
_ZN12PlayerObject14initTanukiJumpEv = 0x00267904;
_ZN12PlayerObject10sub_26D8D4Ev = 0x0026D8D4;
_ZN12PlayerObject18releaseCarryActor2Ei = 0x00269FA8;
_ZN12PlayerObject7endStarEv = 0x0027C094;
_ZN12PlayerObject13getRidePlayerEv = 0x0049DBA4;
_ZN12PlayerObject13getModelScaleEPN4sead7Vector3IfEE = 0x0049DCC8;

_ZN12PlayerObject21isDemoDokanCannonDoneEv = 0x0049DEA8;
_ZN12PlayerObject15isPMeterChargedEv = 0x0049E008;
_ZN12PlayerObject16isPMeterMaxSpeedEv = 0x0049E39C;
_ZN12PlayerObject15canUseStockItemEv = 0x0049E234;
_ZN12PlayerObject18canUseTouchButtonsEv = 0x0049E434;
_ZN12PlayerObject14isMoveOntoliftEv = 0x0049DD3C;
_ZN12PlayerObject12setTurnPowerEv = 0x00265288;
_ZN12PlayerObject16setWaterWalkFlagEv = 0x0026AF90;
_ZN12PlayerObject8isChangeEv = 0x0049DBD8;

_ZN12PlayerObject15removeHatenaCapEbb = 0x002642D0;
_ZN12PlayerObject13hideHatenaCapEv = 0x00264578;

_ZGVZN12PlayerObject24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006036C0;
_ZZN12PlayerObject24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006036C4;


/* PlayerDemoMgr */
_ZN13_ZN13PlayerDemoMgr9sInstanceEC1Eb = 0x002A3954;
_ZN13_ZN13PlayerDemoMgr9sInstanceEC2Eb = 0x002A3954;

_ZN13PlayerDemoMgr9sInstanceE = 0x005EA1C8;
_ZN13PlayerDemoMgr14createInstanceEPN4sead4HeapE = 0x002A1D30;
_ZN13PlayerDemoMgr14deleteInstanceEv = 0x002A1D8C;
_ZN13PlayerDemoMgr18SingletonDisposer_D1Ev = 0x002A2F64;
_ZN13PlayerDemoMgr15sStaticDisposerE = 0x005EA1CC;
_ZTVN13PlayerDemoMgr18SingletonDisposer_E = 0x005AED80;

_ZN13PlayerDemoMgr4initEv = 0x002A3490;
_ZN13PlayerDemoMgr7executeEv = 0x002A3584;
_ZN13PlayerDemoMgr19handleGoalDemoStateEv = 0x002A2CF4;

_ZN13PlayerDemoMgr6freezeEv = 0x002A30F0;
_ZN13PlayerDemoMgr16freezeIfOnGroundEv = 0x002A3248;
_ZN13PlayerDemoMgr8unfreezeEv = 0x002A2EB0;
_ZN13PlayerDemoMgr16setBossDemoStateEj = 0x002A2B2C;

_ZN13PlayerDemoMgr16pushPowerupEventEP12PlayerObject = 0x002A332C;
_ZN13PlayerDemoMgr21startPlayerDeathEventEP12PlayerObjecth = 0x002A2AC0;
_ZN13PlayerDemoMgr18startEntranceEventEv = 0x002A3204;
_ZN13PlayerDemoMgr14startUnkEventBEv = 0x002A2F1C;
_ZN13PlayerDemoMgr14startUnkEventCEv = 0x002A30A8;

_ZN13PlayerDemoMgr20isReadyCourseRelatedEv = 0x002A3460;
_ZN13PlayerDemoMgr16getEnterPositionEPN4sead7Vector3IfEE = 0x004A0070;
_ZN13PlayerDemoMgr14getPlayerCountEv = 0x002A31DC;

/* PlayerModelMgr */
_ZN14PlayerModelMgrC1Eb = 0x002F4050;
_ZN14PlayerModelMgrC2Eb = 0x002F4050;

/* vtable */
_ZTV14PlayerModelMgr = 0x005B3128;

_ZN14PlayerModelMgr12setAnimationE6AnimIdf = 0x002F4028;
_ZN14PlayerModelMgr12setAnimationE6AnimIdff = 0x002F3C54;


/* PlayerModelBase */

/* vtable */
_ZTV15PlayerModelBase = 0x005B6654;

/* virtual functions */
_ZN15PlayerModelBase19getHitboxScaleMaybeEv = 0x00000000;
_ZN15PlayerModelBase14setTextureAnimEi = 0x00000000;
_ZN15PlayerModelBase15setPersonalAnimERP8ResourcePN4sead14SafeStringBaseIcEE6AnimIdi = 0x00000000;
_ZN15PlayerModelBase15getTailAnimNameEPN4sead14SafeStringBaseIcEE6AnimId = 0x00000000;
_ZN15PlayerModelBase20getGoldBlockAnimNameEPN4sead14SafeStringBaseIcEE6AnimId = 0x00000000;
_ZN15PlayerModelBase17getEndingAnimNameEPN4sead14SafeStringBaseIcEE6AnimId = 0x00000000;
_ZN15PlayerModelBase19playBodyAnimPrimaryEP8ResourcePKN4sead14SafeStringBaseIcEE10PlayPolicyfff = 0x00000000;
_ZN15PlayerModelBase21playBodyAnimSecondaryEP8ResourcePKN4sead14SafeStringBaseIcEE10PlayPolicyfff = 0x00000000;
_ZN15PlayerModelBase19mapMismatchBodyBoneEv = 0x00000000;
_ZN15PlayerModelBase6updateEv = 0x00000000;
_ZN15PlayerModelBase10getBoneIdxEi = 0x00000000;
_ZN15PlayerModelBase12setColorTypeEh = 0x00314FD4;
_ZN15PlayerModelBase10setTanookiEi = 0x003150D4;
_ZN15PlayerModelBase13setDepthValueEf = 0x00000000;
_ZN15PlayerModelBase22setSpecularColorScalarEf = 0x00000000;
_ZN15PlayerModelBase18saveMaterialColorsEv = 0x00000000;
_ZN15PlayerModelBase21setTargetLookRotationEPN4sead7Vector3IiEEf = 0x00314B4C;
_ZN15PlayerModelBase15setLookRotationEPN4sead7Vector3IiEE = 0x003150DC;
_ZN15PlayerModelBase15getLookRotationEv = 0x00000000;
_ZN15PlayerModelBase11setLookModeEh = 0x00314ACC;
_ZN15PlayerModelBase21setTailTargetRotationEPN4sead7Vector3IiEE = 0x00314C2C;
_ZN15PlayerModelBase10setPowerupE7Powerup = 0x00314C5C;
_ZN15PlayerModelBase12setAnimationE6AnimIdfff = 0x00315338;
_ZN15PlayerModelBase11setBodyAnimE6AnimIdfff = 0x003149D4;
_ZN15PlayerModelBase11setLinkAnimEfff = 0x00314AE0;
_ZN15PlayerModelBase19setSkeletalAnimStepEif = 0x00314B50;
_ZN15PlayerModelBase16setCarryBodyAnimEf = 0x00314FD8;
_ZN15PlayerModelBase15releaseBodyAnimEf = 0x00314C64;
_ZN15PlayerModelBase15getJumpAnimNameEPN4sead14SafeStringBaseIcEEii = 0x003150E0;
_ZN15PlayerModelBase27getBoneWorldTransformMatrixEP5Mtx34i = 0x004A330C;
_ZN15PlayerModelBase16updateAnimationsEv = 0x00000000;
_ZN15PlayerModelBase4drawEv = 0x00315334;
_ZN15PlayerModelBase19playBigEndColorAnimEv = 0x003151E0;
_ZN15PlayerModelBase16stopBigColorAnimEv = 0x003150D8;
_ZN15PlayerModelBase13setStarActiveEv = 0x00314C30;
_ZN15PlayerModelBase15setStarDisabledEv = 0x003149C4;
_ZN15PlayerModelBase14setStoneActiveEv = 0x00314AD0;
_ZN15PlayerModelBase16setStoneDisabledEv = 0x003156A4;
_ZN15PlayerModelBase23getHitboxScaleByPowerupEv = 0x00000000;
_ZN15PlayerModelBase12setSoftLightEv = 0x003151E4;
_ZN15PlayerModelBase10setBaseMtxEPK5Mtx34 = 0x003151E8;
_ZN15PlayerModelBase8setFrameEf = 0x001B2840;
_ZN15PlayerModelBase15setJumpAnimRandEi = 0x00314DF8;
_ZN15PlayerModelBase16isFootStepTimingEv = 0x00314E6C;
_ZN15PlayerModelBase23setSkelAnimIdxFrameStepEf = 0x00315658;
_ZN15PlayerModelBase12setAnimFrameEf = 0x003156B4;

/* PlayerModel */

_ZN11PlayerModelD0Ev = 0x00244A84;
_ZN11PlayerModelD1Ev = 0x00244A74;

_ZN11PlayerModel16animationEntriesE = 0x005EA230;

/* vtable */
_ZTV11PlayerModel = 0x005A7C3C;

/* virtual functions */
_ZN11PlayerModel19getHitboxScaleMaybeEv = 0x002439BC;
_ZN11PlayerModel14setTextureAnimEi = 0x0024360C;
_ZN11PlayerModel15setPersonalAnimERP8ResourcePN4sead14SafeStringBaseIcEE6AnimIdi = 0x00242568;
_ZN10MarioModel15setPersonalAnimERP8ResourcePN4sead14SafeStringBaseIcEE6AnimIdi = 0x001EBD90;
_ZN11PlayerModel15getTailAnimNameEPN4sead14SafeStringBaseIcEE6AnimId = 0x00242690;
_ZN11PlayerModel20getGoldBlockAnimNameEPN4sead14SafeStringBaseIcEE6AnimId = 0x0024297C;
_ZN11PlayerModel17getEndingAnimNameEPN4sead14SafeStringBaseIcEE6AnimId = 0x00241E10;
_ZN11PlayerModel19playBodyAnimPrimaryEP8ResourcePKN4sead14SafeStringBaseIcEE10PlayPolicyfff = 0x00241764;
_ZN11PlayerModel21playBodyAnimSecondaryEP8ResourcePKN4sead14SafeStringBaseIcEE10PlayPolicyfff = 0x00241210;
_ZN11PlayerModel19mapMismatchBodyBoneEv = 0x002424EC;
_ZN11PlayerModel6updateEv = 0x00243CF8;
_ZN11PlayerModel10getBoneIdxEi = 0x00241ADC;
_ZN11PlayerModel12setColorTypeEh = 0x00242978;
_ZN11PlayerModel10setTanookiEi = 0x002430A4;
_ZN11PlayerModel13setDepthValueEf = 0x002430A8;
_ZN11PlayerModel22setSpecularColorScalarEf = 0x002412E0;
_ZN11PlayerModel18saveMaterialColorsEv = 0x00242594;
_ZN11PlayerModel21setTargetLookRotationEPN4sead7Vector3IiEEf = 0x00241B0C;
_ZN11PlayerModel15setLookRotationEPN4sead7Vector3IiEE = 0x002436A8;
_ZN11PlayerModel15getLookRotationEv = 0x00241AF0;
_ZN11PlayerModel11setLookModeEh = 0x002411E8;
_ZN11PlayerModel21setTailTargetRotationEPN4sead7Vector3IiEE = 0x00241B28;
_ZN11PlayerModel10setPowerupE7Powerup = 0x00241FC4;
_ZN11PlayerModel12setAnimationEifff = 0x00243AB8;
_ZN11PlayerModel16updateAnimationsEv = 0x00241BC4;
_ZN11PlayerModel4drawEv = 0x00315334;
_ZN11PlayerModel19playBigEndColorAnimEv = 0x003151E0;
_ZN11PlayerModel16stopBigColorAnimEv = 0x003150D8;
_ZN11PlayerModel13setStarActiveEv = 0x00314C30;
_ZN11PlayerModel15setStarDisabledEv = 0x003149C4;
_ZN11PlayerModel14setStoneActiveEv = 0x00314AD0;
_ZN11PlayerModel16setStoneDisabledEv = 0x003156A4;
_ZN11PlayerModel23getHitboxScaleByPowerupEv = 0x0049CBC8;
_ZN11PlayerModel12setSoftLightEv = 0x003151E4;
_ZN11PlayerModel4vf9CEv = 0x00000000;
_ZN11PlayerModel13setRenderModeEN11PlayerModel10RenderModeE = 0x00241AFC;

/* functions */
_ZN11PlayerModel16initBoneIndiciesEv = 0x00241D70;
_ZN11PlayerModel17setTransformFrameEf = 0x002438A8;
_ZN11PlayerModel16updateRenderModeEv = 0x00243B40;
_ZN11PlayerModel10stopLookLREv = 0x002437DC;
_ZN11PlayerModel10animIsDoneEv = 0x0049571C;
_ZN11PlayerModel14getUnkEndFrameEv = 0x004A3390;

_ZN11PlayerModel14setLookLRFrameEP13AnimModelBasef = 0x00241834;
_ZN11PlayerModel17playStarColorAnimEP13AnimModelBasef = 0x00241934;
_ZN11PlayerModel11setTailAnimEifff = 0x002419B0;
_ZN11PlayerModel16cleanupSomethingEv = 0x00241B98;
_ZN11PlayerModel17stopStarColorAnimEP13AnimModelBase = 0x00241CF4;
_ZN11PlayerModel18updateLookRotationEv = 0x0024212C;
_ZN11PlayerModel20toggleMeshVisibilityEP13AnimModelBasej = 0x002422B4;
_ZN11PlayerModel18setTanookiTexturesEi = 0x002427F4;
_ZN11PlayerModel17setTextureToStoneEP13AnimModelBase = 0x00242B78;
_ZN11PlayerModel21restoreMaterialColorsEP13AnimModelBase = 0x00243134;
_ZN11PlayerModel17syncMaterialAnimsEv = 0x002436CC;

/* MarioModel */
_ZN10MarioModelD0Ev = 0x00000000;
_ZN10MarioModelD1Ev = 0x005A2170;

/* vtable */
_ZTV10MarioModel = 0x005A213C;

/* virtual functions */
_ZN10MarioModel19getHitboxScaleMaybeEv = 0x001EC184;
_ZN10MarioModel14setTextureAnimEi = 0x00243608;
_ZN10MarioModel6updateEv = 0x00243CF4;
_ZN10MarioModel12setColorTypeEh = 0x001EC124;
_ZN10MarioModel10setTanookiEi = 0x001EC160;
_ZN10MarioModel16updateAnimationsEv = 0x00241BC0;
_ZN10MarioModel4drawEv = 0x00243A58;
_ZN10MarioModel13setRenderModeEN11PlayerModel10RenderModeE = 0x00241AF8;

/* functions */
_ZN10MarioModel18getBoneTranslationEPN4sead7Vector3IfEEi = 0x004A3354;
_ZN10MarioModel14modelIsAtFrameEf = 0x004955A0;
_ZN10MarioModel18getCurrentUnkFrameEv = 0x00495800;
_ZN10MarioModel11getEndFrameEv = 0x004A3390;

/* PlayerKey */
_ZN9PlayerKeyC1Ev = 0x0044DA40;
_ZN9PlayerKeyC2Ev = 0x0044DA40;
_ZN9PlayerKey7executeEv = 0x0044D840;
_ZN9PlayerKey13setDemoButtonEc = 0x0044D75C;
_ZN9PlayerKey8onStatusEi = 0x0044D970;
_ZN9PlayerKey9offStatusEc = 0x0044DA2C;

_ZN9PlayerKey10isHeldJumpEv = 0x004AF984;
_ZN9PlayerKey13isPressedJumpEv = 0x004AFA30;
_ZN9PlayerKey9isHeldRunEv = 0x004AF908;
_ZN9PlayerKey12isPressedRunEv = 0x004AFAA4;
_ZN9PlayerKey14isPressedShootEv = 0x004AFA20;
_ZN9PlayerKey11isHeldCarryEv = 0x004AF9CC;
_ZN9PlayerKey16getDirectionHeldEP9Direction = 0x004AF994;
_ZN9PlayerKey10buttonJumpEv = 0x004AF948;

_ZN9PlayerKey15isHeldDirectionEv = 0x004AF9DC;
_ZN9PlayerKey10isHeldDownEv = 0x004AFA60;
_ZN9PlayerKey10isHeldLeftEv = 0x004AF974;
_ZN9PlayerKey11isHeldRightEv = 0x004AFA00;
_ZN9PlayerKey8isHeldUpEv = 0x004AFBD0;
_ZN9PlayerKey17isHeldUpExclusiveEv = 0x004AF918;

_ZN9PlayerKey12isPressedAnyEv = 0x004AFA70;
_ZN9PlayerKey13isPressedDownEv = 0x004AFA10;
_ZN9PlayerKey13isPressedLeftEv = 0x004AFA40;
_ZN9PlayerKey14isPressedRightEv = 0x004AFA94;
_ZN9PlayerKey11isPressedUpEv = 0x004AFBF4;
_ZN9PlayerKey16isPressedBalloonEv = 0x004AFAB4;
_ZN9PlayerKey18isPressedStockItemEv = 0x004AFBC0;
_ZN9PlayerKey8isStatusEc = 0x004AFBE0;

_ZN9PlayerKey10sub_44D820Ev = 0x0044D820;
_ZN9PlayerKey10sub_4AFAC4Ei = 0x004AFAC4;
_ZN9PlayerKey10sub_4AFB44Ei = 0x004AFB44;

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
_ZN5Scene9preCreateEv = 0x00484198;
_ZN5Scene10postCreateEN5fBase6ResultE = 0x00483BBC;
_ZN5Scene9preDeleteEv = 0x00484240;
_ZN5Scene10postDeleteEN5fBase6ResultE = 0x00483BC0;
_ZN5Scene10preExecuteEv = 0x00483C6C;
_ZN5Scene11postExecuteEN5fBase6ResultE = 0x00484014;
_ZN5Scene7preDrawEv = 0x00484180;
_ZN5Scene8postDrawEN5fBase6ResultE = 0x00484194;

_ZN5Scene4vf3CEv = 0x0000000;
_ZN5Scene4vf40Ev = 0x00100ECF;

/* static members */
_ZN5Scene11changeSceneEjN12FaderMgrBase9FaderTypeES1_S1_S1_j = 0x00484034;
_ZN5Scene11changeSceneEjj = 0x00484074;
_ZN5Scene13setTransitionEhhhh = 0x00484018;
_ZN5Scene11nextSceneIdE = 0x005EF9A0;
_ZN5Scene14currentSceneIdE = 0x005EF9A2;
_ZN5Scene11lastSceneIdE = 0x005EF9A4;


/* ScCourse */
_ZN8ScCourse9sInstanceE = 0x005E7210;

_ZN8ScCourseC1Ev = 0x0042BDDC;
_ZN8ScCourseD1Ev = 0x0042BE60;

_ZN8ScCourse8onCreateEv = 0x0042B47C;
_ZN8ScCourse8onDeleteEv = 0x0042BC58;
_ZN8ScCourse9onExecuteEv = 0x0042B928;
_ZN8ScCourse6onDrawEv = 0x0042B368;
_ZN8ScCourse4vf40Ev = 0x004AE018;

_ZN8ScCourse12StateID_unk1E = 0x00613208;
_ZN8ScCourse12StateID_unk2E = 0x00613228;
_ZN8ScCourse12StateID_unk3E = 0x00613248;
_ZN8ScCourse12StateID_unk4E = 0x00613268;
_ZN8ScCourse12StateID_unk5E = 0x00613288;
_ZN8ScCourse12StateID_unk6E = 0x006132A8;

_ZN8ScCourse19initializeState_unk1Ev = 0x0042AD08;
_ZN8ScCourse17executeState_unk1Ev = 0x0042A25C;
_ZN8ScCourse18finalizeState_unk1Ev = 0x0042A810;
_ZN8ScCourse19initializeState_unk2Ev = 0x0042AD34;
_ZN8ScCourse17executeState_unk2Ev = 0x0042ACAC;
_ZN8ScCourse18finalizeState_unk2Ev = 0x0042AD0C;
_ZN8ScCourse20initializeState_unk3Ev = 0x0042AD10;
_ZN8ScCourse17executeState_unk3Ev = 0x0042A3D0;
_ZN8ScCourse18finalizeState_unk3Ev = 0x0042ACA8;
_ZN8ScCourse20initializeState_unk4Ev = 0x0042B2A4;
_ZN8ScCourse17executeState_unk4Ev = 0x0042AE14;
_ZN8ScCourse18finalizeState_unk4Ev = 0x0042B298;
_ZN8ScCourse20initializeState_unk5Ev = 0x00542270;
_ZN8ScCourse17executeState_unk5Ev = 0x0042B008;
_ZN8ScCourse18finalizeState_unk5Ev = 0x0042B2A0;
_ZN8ScCourse20initializeState_unk6Ev = 0x0042B29C;
_ZN8ScCourse17executeState_unk6Ev = 0x0042ADA0;
_ZN8ScCourse18finalizeState_unk6Ev = 0x0042AE10;

_ZN8ScCourse26setCollectionCoinCollectedEh = 0x00429C54;
_ZN8ScCourse13giveStockItemEhh = 0x00429CDC;
_ZN8ScCourse14setStockItemIdEhh = 0x00429CF8;
_ZN8ScCourse14createBsFogMgrEv = 0x00429D0C;
_ZN8ScCourse22showCourseClearMessageEv = 0x00429DD8;
_ZN8ScCourse15enableInventoryEb = 0x00429DE8;
_ZN8ScCourse13deleteLayoutsEv = 0x00429E14;
_ZN8ScCourse10exitCourseEv = 0x0042A030;
_ZN8ScCourse13setupEnvLightEv = 0x0042A260;
_ZN8ScCourse23setCollectionCoinStatusEhb = 0x0042A3BC;
_ZN8ScCourse13createLayoutsEv = 0x0042A814;
_ZN8ScCourse27doInfoMeterCollectionEffectEh = 0x0042AD4C;
_ZN8ScCourse9zeroTimerEv = 0x0042B304;
_ZN8ScCourse8addCoinsEia = 0x0042B750;
_ZN8ScCourse18incrementCoinCountEa = 0x0042B9F0;
_ZN8ScCourse18incrementLifeCountEv = 0x0042BB9C;
_ZN8ScCourse8addScoreEia = 0x0042BBE4;
_ZN8ScCourse23getCollectionCoinStatusEv = 0x004AD95C;
_ZN8ScCourse14getStockItemIdEh = 0x004ADF44;
_ZN8ScCourse24getCollectionCoinPanePosEh = 0x004ADF58;
_ZN8ScCourse19getStockItemPanePosEv = 0x004ADFB8;


/* ScCourseIn */ 
_ZN10ScCourseIn21StateID_LoadModelMgrsE = 0x00613410;
_ZN10ScCourseIn21StateID_WaitExitReadyE = 0x00613434;

_ZN10ScCourseIn29initializeState_LoadModelMgrsEv = 0x00201CEC;
_ZN10ScCourseIn27finalizeState_LoadModelMgrsEv = 0x00201CE4;

/* ScCourseSelect */
_ZN14ScCourseSelect8instanceE = 0x005E5F9C;

_ZN14ScCourseSelectC1Ev = 0x002F84F8;
_ZN14ScCourseSelectD1Ev = 0x002F8560;

_ZN14ScCourseSelect8onCreateEv = 0x002F7E98;
_ZN14ScCourseSelect8onDeleteEv = 0x002F83D0;
_ZN14ScCourseSelect9onExecuteEv = 0x002F824C;
_ZN14ScCourseSelect6onDrawEv = 0x002F7E40;

_ZN14ScCourseSelect11StateID_1AEE = 0x0060CDB0;
_ZN14ScCourseSelect11StateID_1AFE = 0x0060CDD4;

_ZN14ScCourseSelect19initializeState_1AEEv = 0x002F779C;
_ZN14ScCourseSelect16executeState_1AEEv = 0x002F74F8;
_ZN14ScCourseSelect17finalizeState_1AEEv = 0x002F74FC;

_ZN14ScCourseSelect19initializeState_1AFEv = 0x002F7E24;
_ZN14ScCourseSelect16executeState_1AFEv = 0x002F7D84;
_ZN14ScCourseSelect17finalizeState_1AFEv = 0x002F7E20;


/* BsArea */
_ZN6BsArea8instanceE = 0x005E7048;

_ZN6BsArea18startMidCourseWarpEv = 0x003CEAA0;
_ZN6BsArea9exitLevelEv = 0x003CE494;
_ZN6BsArea10exitLevel2Ev = 0x003CE45C;
_ZN6BsArea15exitLevelFailedEv = 0x003CE4D4;


/* SceneTransitionSettings */
_ZN23SceneTransitionSettings9sInstanceE = 0x005ECEF8;
_ZN23SceneTransitionSettings14createInstanceEPN4sead4HeapE = 0x0042C234;
_ZN23SceneTransitionSettings14deleteInstanceEv = 0x0042C2A0;

_ZNK23SceneTransitionSettings17shouldWaitForFadeEv = 0x004AE028;
_ZN23SceneTransitionSettings5clearEv = 0x0042C21C;


/* FaderMgrBase */
_ZN12FaderMgrBase6updateEv = 0x00255380;
_ZN12FaderMgrBase4drawEv = 0x00255340;

_ZN12FaderMgrBase17setTransitionTypeENS_9FaderTypeES0_ = 0x002553C0;
_ZN12FaderMgrBase12startFadeOutE6Screeni = 0x00255110;
_ZN12FaderMgrBase11startFadeInE6Screeni = 0x002551B8;
_ZN12FaderMgrBase16isFadeInCompleteE6Screen = 0x002552A8;
_ZN12FaderMgrBase17isFadeOutCompleteE6Screen = 0x00255210;
_ZN12FaderMgrBase8isFadeInE6Screen = 0x002552F4;
_ZN12FaderMgrBase11isFadingOutE6Screen = 0x0025525C;

/* vtable */
_ZTVN12FaderMgrBaseE = 0x005A99D0;


/* FaderMgr */
_ZN8FaderMgr8instanceE = 0x005ED2C0;
_ZN8FaderMgr9instance2E = 0x005ED2C4;

_ZN12FaderMgrBase10initializeEv = 0x00255380;
_ZN8FaderMgr10setColoredEb = 0x0040CDE8;

/* vtable */
_ZTVN8FaderMgrE = 0x005CAF80;

/* course_select::TransitTracker */
_ZN13course_select14TransitTracker9sInstanceE = 0x005E59D8;
_ZN13course_select14TransitTracker14createInstanceEPN4sead4HeapE = 0x002D0F84;
_ZN13course_select14TransitTracker14deleteInstanceEv = 0x002D1000;
_ZN13course_select14TransitTracker18SingletonDisposer_D1Ev = 0x002D1350;
_ZN13course_select14TransitTracker15sStaticDisposerE = 0x005E59DC;
_ZTVN13course_select14TransitTracker18SingletonDisposer_E = 0x005B0D68;

/* vtable */
_ZTVN13course_select14TransitTrackerE = 0x005B0D78;

/* functions */
_ZN13course_select14TransitTracker4initEv = 0x002D0F44;
_ZN13course_select14TransitTracker6recordEPNS_6CsInfo9PointInfo5PointES4_S4_ = 0x002D13A0;
_ZN13course_select14TransitTracker18getTransitDistanceEv = 0x002D104C;


/* course_select::SequenceMgr */
_ZN13course_select11SequenceMgr9sInstanceE = 0x005E5FC0;
_ZN13course_select11SequenceMgr14createInstanceEPN4sead4HeapE = 0x002B4768;
_ZN13course_select11SequenceMgr14deleteInstanceEv = 0x002B47C4;
_ZN13course_select11SequenceMgr18SingletonDisposer_D1Ev = 0x002B50E0;
_ZN13course_select11SequenceMgr15sStaticDisposerE = 0x005E5FC4;
_ZTVN13course_select11SequenceMgr18SingletonDisposer_E = 0x005B0034;

/* states */
_ZN13course_select11SequenceMgr14StateID_Unk1C0E = 0x0060D09C;
_ZN13course_select11SequenceMgr14StateID_Unk1C3E = 0x0060D0FC;
_ZN13course_select11SequenceMgr19StateID_CastleClearE = 0x0060D01C;
_ZN13course_select11SequenceMgr19StateID_CastleEnterE = 0x0060CFDC;
_ZN13course_select11SequenceMgr18StateID_CastleFailE = 0x0060CFFC;
_ZN13course_select11SequenceMgr19StateID_CourseClearE = 0x0060CEFC;
_ZN13course_select11SequenceMgr19StateID_CourseEnterE = 0x0060CEBC;
_ZN13course_select11SequenceMgr18StateID_CourseFailE = 0x0060CEDC;
_ZN13course_select11SequenceMgr19StateID_ExitToTitleE = 0x0060D0DC;
_ZN13course_select11SequenceMgr12StateID_IdleE = 0x0060CE9C;
_ZN13course_select11SequenceMgr22StateID_KanbanInteractE = 0x0060D0BC;
_ZN13course_select11SequenceMgr24StateID_KinopioHouseExitE = 0x0060D07C;
_ZN13course_select11SequenceMgr18StateID_ObakeClearE = 0x0060CF5C;
_ZN13course_select11SequenceMgr18StateID_ObakeEnterE = 0x0060CF1C;
_ZN13course_select11SequenceMgr17StateID_ObakeFailE = 0x0060CF3C;
_ZN13course_select11SequenceMgr18StateID_TowerClearE = 0x0060CFBC;
_ZN13course_select11SequenceMgr18StateID_TowerEnterE = 0x0060CF7C;
_ZN13course_select11SequenceMgr17StateID_TowerFailE = 0x0060CF9C;
_ZN13course_select11SequenceMgr18StateID_WorldBeginE = 0x0060D05C;
_ZN13course_select11SequenceMgr19StateID_WorldChangeE = 0x0060D03C;

/* functions */
_ZN13course_select11SequenceMgr6isIdleEv = 0x002B4C58;
_ZN13course_select11SequenceMgr10clearQueueEv = 0x002B41C0;

_ZN13course_select11SequenceMgr20setCourseClearScriptEv = 0x002B578C;
_ZN13course_select11SequenceMgr20setCourseEnterScriptEv = 0x002B524C;
_ZN13course_select11SequenceMgr19setCourseFailScriptEv = 0x002B5C70;
_ZN13course_select11SequenceMgr13setNextScriptERKNS_10BsEventMgr8ScriptIdE = 0x002B4578;
_ZN13course_select11SequenceMgr16setStateByScriptERKNS_10BsEventMgr8ScriptIdE = 0x002B4DF8;


/* course_select::Actor */
_ZN13course_select5ActorC2Ev = 0x02D97EC;

/* virtual functions */
_ZN13course_select5ActorD2Ev = 0x047F024;
_ZN13course_select5Actor10postCreateEN5fBase6ResultE = 0x047EF74;
_ZN13course_select5Actor10preExecuteEv = 0x02D9700;
_ZN13course_select5Actor10postDeleteEN5fBase6ResultE = 0x047EF7C;
_ZN13course_select5Actor11postExecuteEN5fBase6ResultE = 0x047EFC8;
_ZN13course_select5Actor7preDrawEv = 0x02D97C8;
_ZN13course_select5Actor4vf3CEv = 0x0;
_ZN13course_select5Actor4vf40Ev = 0x0;
_ZN13course_select5Actor4vf44Ev = 0x0;

/* functions */
_ZN13course_select5Actor18applyYAccelerationEff = 0x002D9740;
_ZN13course_select5Actor17updatePlanarSpeedEv = 0x002D9788;


/* course_select::ActorState */ 
_ZN13course_select10ActorStateC1Ev = 0x002AE8A0;
_ZN13course_select10ActorStateC2Ev = 0x002AE8A0;

_ZN13course_select10ActorStateD1Ev = 0x002AE918;
_ZN13course_select10ActorStateD2Ev = 0x002AE918;

_ZN13course_select10ActorState11changeStateERK7StateID = 0x001386A8;


/* MapObjWorld */
_ZN13course_select11MapObjWorld12StateID_Unk1E = 0x0060C080;
_ZN13course_select11MapObjWorld12StateID_Unk2E = 0x0060C0A4;

_ZN13course_select11MapObjWorld19updateModelMtxPathsEv = 0x002B1F1C;


/* MapObjGhost */
_ZN13course_select11MapObjGhost14StateID_Unk18FE = 0x0060AFC0;
_ZN13course_select11MapObjGhost14StateID_Unk190E = 0x0060AFE4;
_ZN13course_select11MapObjGhost14StateID_Unk191E = 0x0060B008;
_ZN13course_select11MapObjGhost14StateID_Unk192E = 0x0060B02C;

/* MapObjTower */
_ZN13course_select11MapObjTower14StateID_Unk1A6E = 0x0060BEFC;
_ZN13course_select11MapObjTower14StateID_Unk1A7E = 0x0060BF20;
_ZN13course_select11MapObjTower14StateID_Unk1A8E = 0x0060BF44;
_ZN13course_select11MapObjTower14StateID_Unk1A9E = 0x0060BF68;
_ZN13course_select11MapObjTower14StateID_Unk1AAE = 0x0060BF8C;
_ZN13course_select11MapObjTower14StateID_Unk1ABE = 0x0060BFB0;

/* MapObjCastle */
_ZN13course_select12MapObjCastle14StateID_Unk17DE = 0x0060AA38;
_ZN13course_select12MapObjCastle14StateID_Unk17EE = 0x0060AA5C;
_ZN13course_select12MapObjCastle14StateID_Unk17FE = 0x0060AA80;
_ZN13course_select12MapObjCastle14StateID_Unk180E = 0x0060AAA4;
_ZN13course_select12MapObjCastle14StateID_Unk181E = 0x0060AAC8;
_ZN13course_select12MapObjCastle14StateID_Unk182E = 0x0060AAEC;

/* MapObjDokan */
_ZN13course_select11MapObjDokan14StateID_HiddenE = 0x0060AE38;
_ZN13course_select11MapObjDokan12StateID_WaitE = 0x0060AE5C;
_ZN13course_select11MapObjDokan14StateID_AppearE = 0x0060AE80;
_ZN13course_select11MapObjDokan10StateID_InE = 0x0060AEA4;
_ZN13course_select11MapObjDokan11StateID_OutE = 0x0060AEC8;

/* MapObjCoursePoint */
_ZN13course_select17MapObjCoursePoint13StateID_ClearE = 0x0060ACB0;
_ZN13course_select17MapObjCoursePoint12StateID_HelpE = 0x0060ACD4;
_ZN13course_select17MapObjCoursePoint14StateID_UnlockE = 0x0060ACF8;
_ZN13course_select17MapObjCoursePoint12StateID_OpenE = 0x0060AD1C;
_ZN13course_select17MapObjCoursePoint14StateID_ClosedE = 0x0060AD40;

_ZN13course_select17MapObjCoursePoint12handleUnlockEv = 0x002C1B74;

/* Misc actor functions */
_ZN11TrplnKinoko25collisionCallbackOriginalEP11BgCollisionP21ActorBgCollisionCheck = 0x0024CF78;
_ZN11TrplnKinoko14StateID_ActiveE = 0x00619508;
_ZN11TrplnKinoko16StateID_InactiveE = 0x00619528;
_ZN14RailPolyParent11StateID_4B7E = 0x00618AF4;

_Z17Player_isPunchingP9ActorBase = 0x0026262C;


/* BsEventMgr */
_ZN13course_select10BsEventMgr8instanceE = 0x005E5778;
_ZN13course_select10BsEventMgr9hasScriptEv = 0x004A090C;
_ZN13course_select10BsEventMgr18getCurrentScriptIdEv = 0x004A08F8;
_ZN13course_select10BsEventMgr15getCurrentEventEv = 0x004A08D0;
_ZN13course_select10BsEventMgr15setNextScriptIdERKNS0_8ScriptIdE = 0x002AECE0;


/* course_select::CsInfo */
_ZN13course_select6CsInfo9sInstanceE = 0x005E5808;
_ZN13course_select6CsInfo14createInstanceEPN4sead4HeapE = 0x002BE9CC;
_ZN13course_select6CsInfo14deleteInstanceEv = 0x002BEA74;
_ZN13course_select6CsInfo18SingletonDisposer_D1Ev = 0x002BEAC0;
_ZN13course_select6CsInfo15sStaticDisposerE = 0x005E580C;
_ZTVN13course_select6CsInfo18SingletonDisposer_E = 0x005B0798;

/* CourseSelect related */
_ZN13course_select10getCsvDataEv = 0x002D1B14;
_ZN13course_select12getPointInfoEv = 0x002D1AF4;
_ZN13course_select12getRouteInfoEv = 0x002D2644;
_ZN13course_select11getRotationERKN4sead7Vector3IfEES4_ = 0x002D1944;

_ZN13course_select6CsInfo9PointInfo8getPointEi = 0x002D5148;
_ZN13course_select6CsInfo9PointInfo8getPointERKN4sead14SafeStringBaseIcEE = 0x002D5354;
_ZN13course_select6CsInfo9PointInfo18getPointByCourseIdEh = 0x002D51FC;

_ZN13course_select6CsInfo9RouteInfo8getRouteEPNS0_9PointInfo5PointES4_ = 0x002BC27C;
_ZN13course_select6CsInfo9RouteInfo22getFirstRouteWithPointEPNS0_9PointInfo5PointE = 0x002BC208;

/* course_select::CsInfo::CsvData */
_ZN13course_select6CsInfo7CsvData11getPointIdxERKN4sead14SafeStringBaseIcEE = 0x002D7968;


/* InputMgr */
_ZN8InputMgr9sInstanceE = 0x005E75F0;
_ZN8InputMgr14createInstanceEPN4sead4HeapE = 0x0041A52C;
_ZN8InputMgr14deleteInstanceEv = 0x0041A5FC;

_ZN8InputMgr10saveReplayERKN4sead14SafeStringBaseIcEE = 0x0041B12C;

/* UnkControllerInfo */
_ZN17UnkControllerInfo7player1E = 0x0069E7B0;
_ZN17UnkControllerInfo7player2E = 0x0069E7C4;

_ZN13course_select20getStarCoinGateIndexEi = 0x002D27E8;
_ZN13course_select16getToadHouseTypeEjj = 0x002D2778;
_ZN13course_select24getCourseIdFromPointNameEN4sead14SafeStringBaseIcEE = 0x002D2924;
_ZN13course_select20getTypeFromPointNameEN4sead14SafeStringBaseIcEE = 0x002D2D2C;
_ZN13course_select27getConnectedUnlockPointNameEhhNS_8ExitTypeE = 0x002D3108;
_ZN13course_select24getMaxConnectedDirectionEhNS_8ExitTypeE = 0x002D2F08;

_ZN13course_select17GetCurrentWorldIdEv = 0x002D1B74;
_ZN13course_select16GetCurrentNodeIdEv = 0x002D1C58;


/* course_select::CsActorMgr */
_ZN13course_select10CsActorMgr9sInstanceE = 0x005E5B28;
_ZN13course_select10CsActorMgr14createInstanceEPN4sead4HeapE = 0x002D4070;
_ZN13course_select10CsActorMgr14deleteInstanceEv = 0x002D4128;
_ZN13course_select10CsActorMgr18SingletonDisposer_D1Ev = 0x002D4258;
_ZN13course_select10CsActorMgr15sStaticDisposerE = 0x005E5B2C;
_ZTVN13course_select10CsActorMgr18SingletonDisposer_E = 0x005B0E0C;

/* functions */
_ZN13course_select10CsActorMgr21getParentBoneCourseIdEiP20SkeletalModelWrapper = 0x002D2830;
_ZN13course_select10CsActorMgr11createActorEtRKN4sead7Vector3IfEEhhj = 0x002D34B0;
_ZN13course_select10CsActorMgr18getActorAtCourseIdEth = 0x004A13D0;
_ZN13course_select10CsActorMgr9getPlayerEh = 0x004A146C;


/* course_select::CourseSelectLayoutMgr */
_ZN13course_select21CourseSelectLayoutMgr9sInstanceE = 0x005E57D8;
_ZN13course_select21CourseSelectLayoutMgr14createInstanceEPN4sead4HeapE = 0x002CF6F0;
_ZN13course_select21CourseSelectLayoutMgr14deleteInstanceEv = 0x002CF74C;
_ZN13course_select21CourseSelectLayoutMgr18SingletonDisposer_D1Ev = 0x002CF914;
_ZN13course_select21CourseSelectLayoutMgr15sStaticDisposerE = 0x005E57DC;
_ZTVN13course_select21CourseSelectLayoutMgr18SingletonDisposer_E = 0x005B0D58;

_ZN13course_select21CourseSelectLayoutMgr11StateID_15AE = 0x00609E6C;
_ZN13course_select21CourseSelectLayoutMgr11StateID_15BE = 0x00609E8C;
_ZN13course_select21CourseSelectLayoutMgr11StateID_162E = 0x00609F6C;
_ZN13course_select21CourseSelectLayoutMgr11StateID_163E = 0x00609F8C;
_ZN13course_select21CourseSelectLayoutMgr19StateID_EnterCourseE = 0x00609ECC;
_ZN13course_select21CourseSelectLayoutMgr23StateID_LoadMapSceneTopE = 0x00609EAC;
_ZN13course_select21CourseSelectLayoutMgr31StateID_ShowCoinMilestoneDialogE = 0x00609FAC;
_ZN13course_select21CourseSelectLayoutMgr21StateID_ShowPauseMenuE = 0x00609EEC;
_ZN13course_select21CourseSelectLayoutMgr33StateID_ShowSaveDialogAfterCourseE = 0x00609F4C;
_ZN13course_select21CourseSelectLayoutMgr34StateID_ShowSaveDialogForSignboardE = 0x00609F2C;
_ZN13course_select21CourseSelectLayoutMgr27StateID_ShowSignBoardDialogE = 0x00609F0C;


/* course_select::CourseSelectBsCamera */
_ZN13course_select20CourseSelectBsCamera8instanceE = 0x005E5738;

_ZN13course_select20CourseSelectBsCamera29getBoundAroundConnectedPointsEhbPfS1_S1_S1_ = 0x004A1628;
_ZN13course_select20CourseSelectBsCamera21expandBoundToPositionERKN4sead7Vector3IfEEPfS6_S6_S6_ = 0x004A1498;
_ZN13course_select20CourseSelectBsCamera10unk_2D81C0Ev = 0x002D81C0;

_ZN13course_select20CourseSelectBsCamera21worldPosToScreenSpaceERKN4sead7Vector3IfEE = 0x002D1B88;


/* course_select::CourseSelectPlayer */

/* functions */
_ZN13course_select18CourseSelectPlayer14prepareForWalkEv = 0x002CE354;
_ZN13course_select18CourseSelectPlayer10handleWalkEv = 0x002C8A68;
_ZN13course_select18CourseSelectPlayer10updateWalkEv = 0x002CDFE4;
_ZN13course_select18CourseSelectPlayer14prepareForJumpEv = 0x002CE204;
_ZN13course_select18CourseSelectPlayer10handleJumpEv = 0x002C88E4;
_ZN13course_select18CourseSelectPlayer10updateJumpEv = 0x002C82B4;
_ZN13course_select18CourseSelectPlayer16updateCourseJumpEv = 0x002CDE44;
_ZN13course_select18CourseSelectPlayer18calculateJumpSpeedERKN4sead7Vector3IfEES5_jf = 0x002C951C;
_ZN13course_select18CourseSelectPlayer24prepareForJumpCourseExitEv = 0x002CE0F0;

_ZN13course_select18CourseSelectPlayer25initPositionForCourseExitEv = 0x002C8D38;

_ZN13course_select18CourseSelectPlayer17handleVictorySpinEv = 0x002CBB00;
_ZN13course_select18CourseSelectPlayer19handleVictoryDialogEv = 0x002CB928;
_ZN13course_select18CourseSelectPlayer16handleSaveDialogEv = 0x002CE3C8;
_ZN13course_select18CourseSelectPlayer24handleTitlescreenFadeOutEv = 0x002CB9FC;
_ZN13course_select18CourseSelectPlayer17handleWorldChangeEv = 0x002CC2C0;
_ZN13course_select18CourseSelectPlayer15handleMoveInputEv = 0x002CA188;
_ZN13course_select18CourseSelectPlayer16handleCourseFailEv = 0x002CAEA4;
_ZN13course_select18CourseSelectPlayer17handleCourseClearEv = 0x002CA54C;
_ZN13course_select18CourseSelectPlayer20handleStructureEnterEv = 0x002C90F4;
_ZN13course_select18CourseSelectPlayer19handleStructureExitEv = 0x002C96D8;

_ZN13course_select18CourseSelectPlayer10loadCourseEv = 0x002CADA0;
_ZN13course_select18CourseSelectPlayer17updateModelMatrixEv = 0x002C83A8;

_ZN13course_select18CourseSelectPlayer7playSfxEj = 0x002CAC58;
_ZN13course_select18CourseSelectPlayer13playLandSoundEv = 0x002C8774;
_ZN13course_select18CourseSelectPlayer16createLandEffectEv = 0x002CC434;
_ZN13course_select18CourseSelectPlayer12setAnimationEj = 0x002C873C;
_ZN13course_select18CourseSelectPlayer11setRotationERKi = 0x002C85D4;
_ZN13course_select18CourseSelectPlayer19startRouteTraversalEv = 0x002CA758;

/* states */
_ZN13course_select18CourseSelectPlayer12StateID_WaitE = 0x0060A114;
_ZN13course_select18CourseSelectPlayer12StateID_TurnE = 0x0060A138;
_ZN13course_select18CourseSelectPlayer20StateID_RouteTransitE = 0x0060A15C;
_ZN13course_select18CourseSelectPlayer23StateID_KoopaCastleWalkE = 0x0060A180;
_ZN13course_select18CourseSelectPlayer18StateID_CourseJumpE = 0x0060A1A4;
_ZN13course_select18CourseSelectPlayer18StateID_CourseFailE = 0x0060A1C8;
_ZN13course_select18CourseSelectPlayer12StateID_PipeE = 0x0060A1EC;
_ZN13course_select18CourseSelectPlayer19StateID_RouteUnlockE = 0x0060A210;
_ZN13course_select18CourseSelectPlayer18StateID_FollowWaitE = 0x0060A234;
_ZN13course_select18CourseSelectPlayer16StateID_FollowStE = 0x0060A258;
_ZN13course_select18CourseSelectPlayer14StateID_FollowE = 0x0060A27C;
_ZN13course_select18CourseSelectPlayer20StateID_CourseFailP2E = 0x0060A2A0;
_ZN13course_select18CourseSelectPlayer20StateID_CourseJumpP2E = 0x0060A2C4;
_ZN13course_select18CourseSelectPlayer26StateID_StructureEnterWaitE = 0x0060A2E8;
_ZN13course_select18CourseSelectPlayer25StateID_KoopaCastleWalkP2E = 0x0060A30C;

/* constants */
_ZN13course_select18CourseSelectPlayer9rotationsE = 0x00570C20;

_ZN13course_select18CourseSelectPlayer9jumpSpeedE = 0x005E58C8;
_ZN13course_select18CourseSelectPlayer16jumpAccelerationE = 0x005E58D4;
_ZN13course_select18CourseSelectPlayer12jumpDurationE = 0x005E58DC;
_ZN13course_select18CourseSelectPlayer8jumpApexE = 0x005E58E0;
_ZN13course_select18CourseSelectPlayer7gravityE = 0x005E58CC;

_ZN13course_select18CourseSelectPlayer18pipeEnterThresholdE = 0x005E5898;
_ZN13course_select18CourseSelectPlayer12pipeJumpApexE = 0x005E589C;
_ZN13course_select18CourseSelectPlayer14pipeYThresholdE = 0x005E58A0;
_ZN13course_select18CourseSelectPlayer11pipeYOffsetE = 0x005E58A4;
_ZN13course_select18CourseSelectPlayer15pipeMoveToSpeedE = 0x005E58A8;
_ZN13course_select18CourseSelectPlayer13pipeMoveSpeedE = 0x005E58AC;
_ZN13course_select18CourseSelectPlayer13pipeJumpSpeedE = 0x005E58B0;
_ZN13course_select18CourseSelectPlayer15pipeJumpGravityE = 0x005E58B4;
_ZN13course_select18CourseSelectPlayer16pipeAccelerationE = 0x005E58BC;
_ZN13course_select18CourseSelectPlayer16pipeJumpDurationE = 0x005E58C4;


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

/* nw::snd::internal::MoveValue */
_ZN2nw3snd8internal9MoveValueIfiE9SetTargetEfi = 0x005534EC;

/* nw::snd::internal::StreamSound */
_ZNK2nw3snd8internal11StreamSound21GetPlaySamplePositionEv = 0x0049003C;

/* nw::snd::SoundHandle */
_ZNK2nw3snd11SoundHandle15IsAttachedSoundEv = 0x004B0CFC;
_ZNK2nw3snd11SoundHandle5GetIdEv = 0x004B0CE8;
_ZN2nw3snd11SoundHandle4StopEi = 0x0045C280;
_ZN2nw3snd11SoundHandle5PauseEi = 0x0045C294;
_ZN2nw3snd11SoundHandle7UnPauseEi = 0x0045C2C4;
_ZN2nw3snd11SoundHandle9SetVolumeEfi = 0x0045C2F4;
_ZN2nw3snd11SoundHandle8SetPitchEf = 0x0045C2E0;
_ZN2nw3snd11SoundHandle6SetPanEf = 0x0045C2B0;
_ZN2nw3snd11SoundHandle18detail_AttachSoundEPNS0_8internal10BasicSoundE = 0x00195AA8;
_ZN2nw3snd11SoundHandle11DetachSoundEv = 0x00195A6C;

/* nw::snd::StreamSoundHandle */
_ZN2nw3snd17StreamSoundHandleC1EPNS0_11SoundHandleE = 0x00196D78;
_ZN2nw3snd17StreamSoundHandle11DetachSoundEv = 0x00196D3C;

/* nw::snd::SequenceSoundHandle */
_ZN2nw3snd19SequenceSoundHandleC1EPNS0_11SoundHandleE = 0x00198BC4;
_ZN2nw3snd19SequenceSoundHandle11DetachSoundEv = 0x00198B90;

/* nw::snd::internal::SequenceSound */
_ZN2nw3snd8internal13SequenceSound13WriteVariableEis = 0x0019CD54;
_ZN2nw3snd8internal13SequenceSound18SetChannelPriorityEi = 0x0019CDA0;
_ZN2nw3snd8internal13SequenceSound21SetReleasePriorityFixEb = 0x0019CF78;
_ZNK2nw3snd8internal13SequenceSound7GetTickEv = 0x00490098;

/* nw::snd::WaveSoundHandle */
_ZN2nw3snd15WaveSoundHandleC1EPNS0_11SoundHandleE = 0x001969E8;
_ZN2nw3snd15WaveSoundHandle11DetachSoundEv = 0x001969B4;

/* nw::snd::internal::WaveSound */
_ZN2nw3snd8internal9WaveSound18SetChannelPriorityEi = 0x001A7E60;
_ZN2nw3snd8internal9WaveSound21SetReleasePriorityFixEb = 0x001A7FB0;
_ZNK2nw3snd8internal9WaveSound21GetPlaySamplePositionEv = 0x0049310C;

/* nw::snd::SoundPlayer */
_ZN2nw3snd11SoundPlayer12StopAllSoundEi = 0x00195AF4;
_ZN2nw3snd11SoundPlayer13PauseAllSoundEbi = 0x00195B54;
_ZN2nw3snd11SoundPlayer9SetVolumeEf = 0x00195FC0;

/* nw::lyt::Pane */
_ZN2nw3lyt4Pane21FindExtUserDataByNameEPKc = 0x00191120;
_ZNK2nw3lyt4Pane9GetVtxPosEv = 0x0048E48C;

/* nw::lyt::TextBox */
_ZN2nw3lyt7TextBox9SetStringEPKwt = 0x00194534;

/* nw::lyt::ResourceAccessor */
_ZN2nw3lyt16ResourceAccessorC1Ev = 0x0018F9F0;
_ZN2nw3lyt16ResourceAccessorD1Ev = 0x0018FA08;
_ZN2nw3lyt16ResourceAccessor11LoadTextureEPKc = 0x0018F8A4;
_ZN2nw3lyt16ResourceAccessor8LoadFontEPKc = 0x0018F944;

/* nw::lyt::ArcResourceAccessor */
_ZN2nw3lyt19ArcResourceAccessorC1Ev = 0x001906EC;
_ZN2nw3lyt19ArcResourceAccessor11GetResourceEjPKcPj = 0x001905CC;
_ZN2nw3lyt19ArcResourceAccessor7GetFontEPKc = 0x00190698;
_ZN2nw3lyt19ArcResourceAccessor10GetTextureEPKc = 0x00190558;
_ZN2nw3lyt19ArcResourceAccessor10RegistFontEPKcPNS_4font4FontE = 0x0018F10C;
_ZN2nw3lyt19ArcResourceAccessor12UnregistFontEPKv = 0x0018F1A8;

/* nw::font::ResFontBase */
_ZN2nw4font11ResFontBaseC1Ev = 0x001AB2DC;
_ZN2nw4font11ResFontBaseD1Ev = 0x001ABCC0;
_ZN2nw4font11ResFontBase16SetAlternateCharEt = 0x001AB1DC;

/* nw::font::ResFont */
_ZN2nw4font7ResFontC1Ev = 0x001ABF98;
_ZN2nw4font7ResFontD1Ev = 0x001ABFB0;
_ZN2nw4font7ResFont11SetResourceEPv = 0x001ABCD4;
_ZN2nw4font7ResFont13SetDrawBufferEPv = 0x001ABEAC;
_ZN2nw4font7ResFont17GetDrawBufferSizeEPKv = 0x001ABF00;


/* m2d */
_ZN3m2d13fitTextToPaneEPN2nw3lyt7TextBoxEPKwjRKNS1_4SizeEff = 0x0038D82C;
_ZN3m2d12getTextWidthEPKN2nw3lyt7TextBoxE = 0x0038D67C;
_ZN3m2d24getPaneGlobalTranslationEPKN2nw3lyt4PaneE = 0x0038D9AC;
_ZN3m2d12isPidTextBoxEPN2nw3lyt7TextBoxE = 0x0038D974;
_ZN3m2d13isCopyTextBoxEPN2nw3lyt7TextBoxE = 0x0038D9F4;
_ZN3m2d13isPstrTextBoxEPN2nw3lyt7TextBoxE = 0x0038DA28;
_ZN3m2d14getCopyToCountEPN2nw3lyt7TextBoxE = 0x0038DA5C;
_ZN3m2d13getCopyToNameEPN2nw3lyt7TextBoxEi = 0x0038DB38;

/* m2d::ResAcc_c */
_ZN3m2d8ResAcc_cC1Ev = 0x0047CAE4;
_ZN3m2d8ResAcc_cD1Ev = 0x0047CB54;
_ZN3m2d8ResAcc_cD2Ev = 0x0047CB54;
_ZN3m2d8ResAcc_c4loadEPKcj = 0x0047CA44;
_ZN3m2d8ResAcc_c6unloadEv = 0x0047CABC;

/* m2d::Anm_c */
_ZN3m2d5Anm_cC1Ev = 0x0038EBD0;
_ZN3m2d5Anm_cD1Ev = 0x0047E0D4;
_ZN3m2d5Anm_cD2Ev = 0x0047E0D4;
_ZN3m2d5Anm_c5buildEPKcPNS_8ResAcc_cE = 0x0047DE5C;
_ZN3m2d5Anm_c12setTransformEPN2nw3lyt13AnimTransformE = 0x0047DFD0;
_ZN3m2d5Anm_c6updateEv = 0x0047DD1C;
_ZN3m2d5Anm_c8setFrameEf = 0x0047E07C;
_ZN3m2d5Anm_c20setPlaybackDirectionEb = 0x0038EBA0;
_ZN3m2d5Anm_c7setLoopEb = 0x0038EBB8;
_ZN3m2d5Anm_c13getStartFrameEv = 0x004B347C;
_ZN3m2d5Anm_c11getEndFrameEv = 0x004B3450;
_ZN3m2d5Anm_c6isDoneEv = 0x004B34A8;
_ZN3m2d5Anm_c10checkFrameEf = 0x004B338C;

/* m2d::EmbedLayoutBase_c */
_ZN3m2d17EmbedLayoutBase_cC1Ev = 0x0047DB94;
_ZN3m2d17EmbedLayoutBase_cD1Ev = 0x0047DC8C;
_ZN3m2d17EmbedLayoutBase_cD2Ev = 0x0047DC8C;
_ZN3m2d17EmbedLayoutBase_c4drawEv = 0x0047D9CC;
_ZN3m2d17EmbedLayoutBase_c6updateEv = 0x0047D550;
_ZN3m2d17EmbedLayoutBase_c5buildEPKcPNS_8ResAcc_cEj = 0x0047D9D4;
_ZN3m2d17EmbedLayoutBase_c21setupProjectionMatrixEv = 0x0047D0CC;
_ZN3m2d17EmbedLayoutBase_c18recordDrawCommandsEv = 0x0047DAB0;
_ZN3m2d17EmbedLayoutBase_c11drawCmdListEPN2nw3lyt8DrawInfoE = 0x0047D710;
_ZN3m2d17EmbedLayoutBase_c12calcParallaxEv = 0x0047D2D8;
_ZN3m2d17EmbedLayoutBase_c7bindAnmEPNS_5Anm_cEPN2nw3lyt5GroupEb = 0x0047CFB8;
_ZN3m2d17EmbedLayoutBase_c9unbindAnmEPNS_5Anm_cEPN2nw3lyt5GroupEb = 0x0047D284;
_ZN3m2d17EmbedLayoutBase_c12unbindAllAnmEv = 0x0047D0B0;
_ZN3m2d17EmbedLayoutBase_c15setGroupVisibleEPN2nw3lyt5GroupEb = 0x0047D3A8;
_ZN3m2d17EmbedLayoutBase_c8getGroupEPKc = 0x0018F32C;
_ZN3m2d17EmbedLayoutBase_c7getPaneEPKc = 0x0047D0B8;
_ZN3m2d17EmbedLayoutBase_c10getTextBoxEPKc = 0x0047D498;
_ZN3m2d17EmbedLayoutBase_c10getPictureEPKc = 0x0047D43C;
_ZN3m2d17EmbedLayoutBase_c9getWindowEPKc = 0x0047D3E0;
_ZN3m2d17EmbedLayoutBase_c11getBoundingEPKc = 0x0047D4F4;

/* m2d::EmbedLayout_c */
_ZN3m2d13EmbedLayout_cC1Ev = 0x0038D4C4;
_ZN3m2d13EmbedLayout_cD1Ev = 0x0047DC88;
_ZN3m2d13EmbedLayout_cD2Ev = 0x0047DC88;
_ZN3m2d13EmbedLayout_c4drawEv = 0x0047D9C8;
_ZN3m2d13EmbedLayout_c6updateEv = 0x0038D4A8;
_ZN3m2d13EmbedLayout_c21setupProjectionMatrixEv = 0x0038CF50;
_ZN3m2d13EmbedLayout_c18recordDrawCommandsEv = 0x0047DAAC;
_ZN3m2d13EmbedLayout_c21copyTransformFromPaneEPN2nw3lyt4PaneE = 0x0038CED0;
_ZN3m2d13EmbedLayout_c11setPositionERKN4sead7Vector3IfEE = 0x0038D11C;
_ZN3m2d13EmbedLayout_c17screenToLayoutPosERKN4sead7Vector2IfEERS3_ = 0x0047D010;
_ZN3m2d13EmbedLayout_c12getBoundingsEPPN2nw3lyt8BoundingEPKN4sead14SafeStringBaseIcEERKj = 0x0038D14C;
_ZN3m2d13EmbedLayout_c9getGroupsEPPN2nw3lyt5GroupEPKN4sead14SafeStringBaseIcEERKj = 0x0038D1B8;
_ZN3m2d13EmbedLayout_c8getPanesEPPN2nw3lyt4PaneEPKN4sead14SafeStringBaseIcEERKj = 0x0038D224;
_ZN3m2d13EmbedLayout_c11getPicturesEPPN2nw3lyt7PictureEPKN4sead14SafeStringBaseIcEERKj = 0x0038D290;
_ZN3m2d13EmbedLayout_c12getTextBoxesEPPN2nw3lyt7TextBoxEPKN4sead14SafeStringBaseIcEERKj = 0x0038D3A0;
_ZN3m2d13EmbedLayout_c12getTextBoxesEPNS_9TextBox_cEPKN4sead14SafeStringBaseIcEERKjP12TagProcessorPN10MessageMgr6HandleE = 0x0038D2FC;
_ZN3m2d13EmbedLayout_c10getWindowsEPPN2nw3lyt6WindowEPKN4sead14SafeStringBaseIcEERKj = 0x0038D40C;

/* m2d::DrawMgr_c */
_ZN3m2d9DrawMgr_c14createInstanceEPN4sead4HeapE = 0x0038EC0C;
_ZN3m2d9DrawMgr_c11getInstanceEv = 0x0038EBFC;
_ZN3m2d9DrawMgr_c13addToDrawListEPNS_17EmbedLayoutBase_cE6Screen = 0x0038ECD8;
_ZN3m2d9DrawMgr_c11drawTopLeftEv = 0x0038ECEC;
_ZN3m2d9DrawMgr_c12drawTopRightEv = 0x0038ED00;
_ZN3m2d9DrawMgr_c10drawBottomEv = 0x0038EBE8;

/* m2d::TextBox_c */
_ZN3m2d9TextBox_cC1Ev = 0x0038E5B8;
_ZN3m2d9TextBox_cD1Ev = 0x0038E5F0;
_ZN3m2d9TextBox_cD2Ev = 0x0038E5F0;
_ZN3m2d9TextBox_c5buildEPNS_13EmbedLayout_cEPN2nw3lyt7TextBoxEP12TagProcessorPN10MessageMgr6HandleE = 0x0038E360;
_ZN3m2d9TextBox_c7setTextERKN4sead14SafeStringBaseIwEEt = 0x0038E544;
_ZN3m2d9TextBox_c10setMessageERKN4sead14SafeStringBaseIcEEiz = 0x0038DBC8;
_ZN3m2d9TextBox_c10setMessageERKN4sead14SafeStringBaseIcEEPN10MessageMgr6HandleEiz = 0x0038DB9C;
_ZN3m2d9TextBox_c11setMessageVERKN4sead14SafeStringBaseIcEEPN10MessageMgr6HandleEbiPKj = 0x0038DD98;
_ZN3m2d9TextBox_c13setPidMessageEiiz = 0x0038E0F0;
_ZN3m2d9TextBox_c13setPidMessageEiPN10MessageMgr6HandleEiz = 0x0038E074;
_ZN3m2d9TextBox_c19getPidMessageLengthEiPN10MessageMgr6HandleE = 0x0038DF74;
_ZN3m2d9TextBox_c17allocStringBufferEt = 0x0038E298;
_ZN3m2d9TextBox_c27allocStringBufferForMessageERKN4sead14SafeStringBaseIcEEPN10MessageMgr6HandleE = 0x0038E16C;
_ZN3m2d9TextBox_c23allocStringBufferForPidEiPN10MessageMgr6HandleE = 0x0038E300;
_ZN3m2d9TextBox_c14updateChildrenEv = 0x0038DC08;


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

/* FragmentLight */
_ZN13FragmentLightC1Ev = 0x001B1628;
_ZN13FragmentLightC2Ev = 0x001B1628;
_ZN13FragmentLightD1Ev = 0x001B1654;

_ZN13FragmentLight5setupE = 0x001B14E8;
_ZN13FragmentLight4vf14E = 0x00000000;

_ZN13FragmentLight10setAmbientERKN4sead7Color4fE = 0x001B1418;
_ZN13FragmentLight10setDiffuseERKN4sead7Color4fE = 0x001B144C;
_ZN13FragmentLight12setDirectionERKN4sead7Vector3IfEE = 0x001B13D4;
_ZN13FragmentLight12setSpecular0ERKN4sead7Color4fE = 0x001B1480;
_ZN13FragmentLight12setSpecular1ERKN4sead7Color4fE = 0x001B14B4;
_ZN13FragmentLight15updateTransformEv = 0x001B2218;

/* EnvironmentalLightSet */
_ZN21EnvironmentalLightSetC1Ev = 0x003458E8;
_ZN21EnvironmentalLightSetC2Ev = 0x003458E8;
_ZN21EnvironmentalLightSetD1Ev = 0x00345938;
_ZN21EnvironmentalLightSet4loadERKN4sead14SafeStringBaseIcEEj = 0x003455BC;
_ZN21EnvironmentalLightSet6unloadEv = 0x003458DC;
_ZN21EnvironmentalLightSet7executeEv = 0x003458D0;

/* LightMgr */
_ZN8LightMgr9sInstanceE = 0x005E74A0;
_ZN8LightMgr14createInstanceEPN4sead4HeapE = 0x00420AD0;
_ZN8LightMgr18SingletonDisposer_D1Ev = 0x00420DA0;
_ZN8LightMgr15sStaticDisposerE = 0x005E74A4;
_ZTVN8LightMgr18SingletonDisposer_E = 0x005CC4DC;
_ZN8LightMgrD1Ev = 0x0042132C;

_ZN8LightMgr11insertLightERK21EnvironmentalLightSet = 0x00420DF0;
_ZN8LightMgr20applyEnvColorToModelEPN2nw3gfx5ModelE = 0x00421174;

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
_ZN9EventBase6isJoinERK9ActorBase = 0x004AE5FC;

/* EventMgr */
_ZN8EventMgr9sInstanceE = 0x005E6EC8;
_ZN8EventMgr14createInstanceEPN4sead4HeapE = 0x0040CA60;
_ZN8EventMgr14deleteInstanceEv = 0x0040CAD0;
_ZN8EventMgr18SingletonDisposer_D1Ev = 0x0040CB0C;
_ZN8EventMgr15sStaticDisposerE = 0x005E6ECC;
_ZTVN8EventMgr18SingletonDisposer_E = 0x005CAF70;
_ZN8EventMgr9pushEventEP9EventBase = 0x0040CBC8;
_ZNL8EventMgr6isJoinERK9ActorBase = 0x004AD690;

/* QuakeMgr */
_ZTV8QuakeMgr = 0x005CD240;
_ZN8QuakeMgrD1Ev = 0x00428F74;
_ZN8QuakeMgrD2Ev = 0x00428F70;
_ZN8QuakeMgr7doQuakeEaNS_9ShockTypeENS_9ShockFlagEj = 0x00428A60;
_ZN8QuakeMgr7doQuakeEaNS_9ShockTypeEj = 0x00428AE0;
_ZN8QuakeMgr17doContinuousQuakeENS_19ContinuousShockTypeENS_9ShockFlagE = 0x00428B34;
_ZN8QuakeMgr7doQuakeENS_9ShockTypeENS_9ShockFlagEj = 0x00428B78;
_ZN8QuakeMgr14createInstanceEPN4sead4HeapE = 0x00428BF8;
_ZN8QuakeMgr14deleteInstanceEv = 0x00428CE0;
_ZN8QuakeMgr7executeEv = 0x00428D7C;
_ZN8QuakeMgr9stopQuakeEv = 0x00428F60;
_ZN8QuakeMgr9sInstanceE = 0x005E7198;


/* QuakeMgr::SingletonDisposer_ */
_ZTVN8QuakeMgr18SingletonDisposer_E = 0x005CD230;
_ZN8QuakeMgr18SingletonDisposer_D1Ev = 0x00428D2C;
_ZN8QuakeMgr18SingletonDisposer_15sStaticDisposerE = 0x005E719C;

/* BalloonMgr */
_ZN10BalloonMgr9sInstanceE = 0x005E7030;
_ZN10BalloonMgr14createInstanceEPN4sead4HeapE = 0x001C8418;
_ZN10BalloonMgr14deleteInstanceEv = 0x001C84C0;
_ZN10BalloonMgr18SingletonDisposer_D1Ev = 0x001C8534;
_ZN10BalloonMgr15sStaticDisposerE = 0x005E7034;
_ZTVN10BalloonMgr18SingletonDisposer_E = 0x0059E674;

/* FragmentMgr */
_ZTVN11FragmentMgrE = 0x005A5C44;
_ZN11FragmentMgrD1Ev = 0x00227B30;
_ZN11FragmentMgrD2Ev = 0x00227B2C;
_ZN11FragmentMgr9sInstanceE = 0x005E6FA0;
_ZN11FragmentMgr14createInstanceEPN4sead4HeapE = 0x00227108;
_ZN11FragmentMgr14deleteInstanceEv = 0x00227198;
_ZN11FragmentMgr17createWaterSplashERKN4sead7Vector3IfEE16WaterSplashFlagsS4_ = 0x002271E4;
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
_ZN16BigBlockFragment14sResourceNamesE = 0x006123BC;
_ZN16BigBlockFragment11sModelNamesE = 0x0061243C;
_ZN16BigBlockFragment18sRotationIncrementE = 0x005E6F10;

/* CoinOrigin */
_ZN10CoinOrigin9sInstanceE = 0x005E9A88;
_ZN10CoinOrigin14createInstanceEPN4sead4HeapE = 0x001CE770;
_ZN10CoinOrigin14deleteInstanceEv = 0x001CE800;
_ZN10CoinOrigin18SingletonDisposer_D1Ev = 0x001CE84C;
_ZN10CoinOrigin15sStaticDisposerE = 0x005E9A8C;
_ZTVN10CoinOrigin18SingletonDisposer_E = 0x0059F178;

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

/* ActorCoinBase */
_ZTV13ActorCoinBase = 0x005AC180;
_ZN13ActorCoinBaseC1Ev = 0x00288A04;
_ZN13ActorCoinBaseC2Ev = 0x00288A04;

_ZN13ActorCoinBase17updateCoinPhysicsEbbf = 0x00287528;
_ZN13ActorCoinBase18setupCollisionJumpEb = 0x002877BC;
_ZN13ActorCoinBase10sub_287890Ev = 0x00287890;
_ZN13ActorCoinBase17initLiquidPhysicsEv = 0x002878E8;
_ZN13ActorCoinBase20setupCollisionNormalEb = 0x00287950;
_ZN13ActorCoinBase11initPhysicsEv = 0x002879D8;
_ZN13ActorCoinBase21setupCollisionSensorsEv = 0x00287A08;
_ZN13ActorCoinBase11initCullingEv = 0x00287B44;
_ZN13ActorCoinBase15enableCollisionEv = 0x00287B88;
_ZN13ActorCoinBase10sub_287C0CEb = 0x00287C0C;
_ZN13ActorCoinBase13linkPairChildEv = 0x00287C9C;
_ZN13ActorCoinBase13checkSquishedE16SquishEffectType = 0x00287D3C;
_ZN13ActorCoinBase14initializeTileEb = 0x002888D8;
_ZN13ActorCoinBase15updateRotationYEv = 0x002889F4;

_ZN13ActorCoinBase8onCreateEv = 0x00288724;
_ZN13ActorCoinBase8onDeleteEv = 0x002889BC;
_ZN13ActorCoinBase9onExecuteEv = 0x0028872C;
_ZN13ActorCoinBase6onDrawEv = 0x0028869C;
_ZN13ActorCoinBase18getRuntimeTypeInfoEv = 0x0049EAA0;
_ZN13ActorCoinBase20removeCollisionCheckEv = 0x002889C4;
_ZN13ActorCoinBase17addCollisionCheckEv = 0x002889DC;
_ZN13ActorCoinBase12powActivatedEv = 0x00287848;
_ZN13ActorCoinBase21quakeCollisionEnabledEv = 0x0049EA98;
_ZN13ActorCoinBase16onCollisionQuakeEN14ActorCollision18QuakeCollisionTypeE = 0x002874AC;

_ZN13ActorCoinBase11StateID_3B2E = 0x00614588;
_ZN13ActorCoinBase19initializeState_3B2Ev = 0x00288458;
_ZN13ActorCoinBase16executeState_3B2Ev = 0x00287F18;
_ZN13ActorCoinBase17finalizeState_3B2Ev = 0x00288320;

_ZN13ActorCoinBase11StateID_3B3E = 0x006145AC;
_ZN13ActorCoinBase19initializeState_3B3Ev = 0x0028832C;
_ZN13ActorCoinBase16executeState_3B3Ev = 0x00287DF4;
_ZN13ActorCoinBase17finalizeState_3B3Ev = 0x0028831C;

_ZN13ActorCoinBase11StateID_3B4E = 0x006145D0;
_ZN13ActorCoinBase19initializeState_3B4Ev = 0x0028848C;
_ZN13ActorCoinBase16executeState_3B4Ev = 0x00287F80;
_ZN13ActorCoinBase17finalizeState_3B4Ev = 0x00288324;

_ZN13ActorCoinBase11StateID_3B5E = 0x006145F4;
_ZN13ActorCoinBase19initializeState_3B5Ev = 0x002885B8;
_ZN13ActorCoinBase16executeState_3B5Ev = 0x0028809C;
_ZN13ActorCoinBase17finalizeState_3B5Ev = 0x00288328;

_ZGVZN13ActorCoinBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603710;
_ZZN13ActorCoinBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x00603714;
_ZNK4sead15RuntimeTypeInfo6DeriveI13ActorCoinBaseE9isDerivedEPKNS0_9InterfaceE = 0x00567304;
_ZTVN4sead15RuntimeTypeInfo6DeriveI13ActorCoinBaseEE = 0x005D1CF8;

/* FunsuiCoin */
_ZN10FunsuiCoin12StateID_WaitE = 0x006160DC;
_ZN10FunsuiCoin16StateID_ActivateE = 0x006160FC;
_ZN10FunsuiCoin9spawnCoinEv = 0x001D46BC;


/* BgTexMgr */
_ZN8BgTexMgrC1Ev = 0x00000000;
_ZN8BgTexMgr14createInstanceEPN4sead4HeapE = 0x00401F90;
_ZN8BgTexMgr14deleteInstanceEv = 0x0040205C;
_ZN8BgTexMgr9sInstanceE = 0x005E98B0;
_ZN8BgTexMgrD1Ev = 0x004032C0;

_ZN8BgTexMgr11CoinRelatedE = 0x005E9877;
_ZN8BgTexMgr15BlueCoinRelatedE = 0x005E9838;
_ZN8BgTexMgr14RedCoinRelatedE = 0x005E9876;


_ZN8BgTexMgr20loadAnimatedTileByIdERKN4sead14SafeStringBaseIcEEj = 0x004021A0;
_ZN8BgTexMgr19setAnimatedTileDataEjciiPvi = 0x00401E98;

_ZN8BgTexMgr16sConveyorTileIdsE = 0x00619C34;
_ZN8BgTexMgr14sFlowerTileIdsE = 0x00619D24;
_ZN8BgTexMgr12sSandTileIdsE = 0x005E98E0;
_ZN8BgTexMgr13sTorchTileIdsE = 0x00619EC4;

_ZN8BgTexMgr9sAnimArg1E = 0x0057E5EC;
_ZN8BgTexMgr9sAnimArg2E = 0x005E9910;
_ZN8BgTexMgr9sAnimArg3E = 0x005E995C;
_ZN8BgTexMgr9sAnimArg4E = 0x0057E5A0;
_ZN8BgTexMgr15sRainbowPaletteE = 0x005E98F0;
_ZN8BgTexMgr12rainbowIndexEv = 0x004ADB68;

/* BgTexMgr::SingletonDisposer_ */
_ZTVN8BgTexMgr18SingletonDisposer_E = 0x005CA168;
_ZN8BgTexMgr18SingletonDisposer_D1Ev = 0x004022CC;
_ZN8BgTexMgr18SingletonDisposer_15sStaticDisposerE = 0x005E98B4;


/* MessageMgr */
_ZTVN10MessageMgrE = 0x005C2580;
_ZN10MessageMgr9sInstanceE = 0x005E9DA8;
_ZN10MessageMgr3vf0Ev = 0x0;
_ZN10MessageMgrD1Ev = 0x00396004;
_ZN10MessageMgrD0Ev = 0x0;
_ZN10MessageMgr14createInstanceEPN4sead4HeapE = 0x00102510;
_ZN10MessageMgr10initializeERKN4sead14SafeStringBaseIcEEj = 0x001023F0;
_ZN10MessageMgr4loadERKN4sead14SafeStringBaseIcEE = 0x00395C20;
_ZN10MessageMgr6unloadERKN4sead14SafeStringBaseIcEE = 0x00395CE8;
_ZN10MessageMgr9getHandleERKN4sead14SafeStringBaseIcEE = 0x00395D40;
_ZN10MessageMgr9findEntryERKN4sead14SafeStringBaseIcEE = 0x00395D54;
_ZN10MessageMgr11insertEntryERKN4sead14SafeStringBaseIcEE = 0x00395E38;
_ZN10MessageMgr14getLanguageIdxEv = 0x0010309C;
_ZN10MessageMgr16getLanguageByIdxEj = 0x00103168;
_ZN10MessageMgr16getDirectoryInfoERKN4sead14SafeStringBaseIcEE = 0x003960DC;
_ZN10MessageMgr8getFilesERKN4sead14SafeStringBaseIcEE = 0x00396180;
_ZN10MessageMgr12getFileCountERKN4sead14SafeStringBaseIcEE = 0x00396194;
_ZN10MessageMgr15formatLifeCountEPN4sead22BufferedSafeStringBaseIwEEi = 0x003962DC;

/* MessageMgr::SingletonDisposer_ */
_ZTVN10MessageMgr18SingletonDisposer_E = 0x005C2570;
_ZN10MessageMgr18SingletonDisposer_15sStaticDisposerE = 0x005E9DAC;
_ZN10MessageMgr18SingletonDisposer_D1Ev = 0x00395FB4;

/* MessageMgr::Handle */
_ZTVN10MessageMgr6HandleE = 0x005C2594;
_ZN10MessageMgr6HandleC1Ev = 0x003960B8;
_ZN10MessageMgr6HandleD1Ev = 0x0;
_ZN10MessageMgr6HandleD0Ev = 0x003960D8;
_ZN10MessageMgr6Handle8loadDataEPKvS2_ = 0x00396020;
_ZN10MessageMgr6Handle10unloadDataEv = 0x00396074;
_ZN10MessageMgr6Handle3getEPKc = 0x0012E210;
_ZN10MessageMgr6Handle11getTextSizeEPKc = 0x004A5E6C;

/* TagProcessor */
_ZTV12TagProcessor = 0x005B35A0;
_ZN12TagProcessorC1Ev = 0x002FB89C;
_ZN12TagProcessorD1Ev = 0x002FB8B4;
_ZN12TagProcessor7ProcessEtPv = 0x002FB540;
_ZN12TagProcessor8CalcRectEPvtS0_ = 0x002FB768;
_ZN12TagProcessor13formatMessageEPwjPKwjiiPibiPKj = 0x002F993C;

/* ScoreMgr */
_ZN8ScoreMgr9sInstanceE = 0x005E7268;
_ZN8ScoreMgr14createInstanceEPN4sead4HeapE = 0x0042C5B0;
_ZN8ScoreMgr14deleteInstanceEv = 0x0042C614;
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


/* SimpleRenderer */
_ZN14SimpleRendererC1Ev = 0x002F983C;
_ZN14SimpleRendererD1Ev = 0x002F9898;
_ZN14SimpleRenderer16renderUnTexturedEv = 0x0024BD44;
_ZN14SimpleRenderer14renderTexturedEv = 0x0024BE78;
_ZN14SimpleRenderer10drawCircleERKN4sead7Vector3IfEEjRKNS0_7Color4fERKNS0_7Vector2IfEESB_fff = 0x002F8D70;
_ZN14SimpleRenderer11swapBuffersEv = 0x002F8FC4;
_ZN14SimpleRenderer4drawEv = 0x002F8FE0;
_ZN14SimpleRenderer10initializeEPN4sead4HeapERKNS0_10TextureCtrEj = 0x002F904C;
_ZN14SimpleRenderer10initializeEPN4sead4HeapEj = 0x002F9080;
_ZN14SimpleRenderer8drawLineERKN4sead7Vector3IfEES4_RKNS0_7Color4fERKNS0_7Vector2IfEESB_ff = 0x002F90AC; 
_ZN14SimpleRenderer8drawQuadERKN4sead7Vector3IfEERKNS0_7Vector2IfEERKNS1_IiEES4_f = 0x002F91F4;
_ZN14SimpleRenderer8drawQuadERKN4sead7Vector3IfEERKNS0_7Vector2IfEES8_S8_RKNS1_IiEES4_f = 0x002F9244;
_ZN14SimpleRenderer8drawQuadERKN4sead7Vector3IfEES4_S4_S4_RKNS0_7Vector2IfEES8_f = 0x002F95A0;
_ZN14SimpleRenderer8drawQuadERKN4sead7Vector3IfEES4_S4_S4_f = 0x002F97F0;

/* sead::Delegate<SimpleRenderer> */
_ZTVN4sead8DelegateI14SimpleRendererEE = 0x005D301C;
_ZN4sead8DelegateIN14SimpleRendererEE6invokeEv = 0x0055FBBC;

/* EnvShaderBinding */
_ZN16EnvShaderBindingC1Ev = 0x0030C728;
_ZN16EnvShaderBinding10initializeEbb = 0x0030C4C8;

/* EnvEffectBase */
_ZN13EnvEffectBase4initEPN4sead4HeapE = 0x002929B8;
_ZN13EnvEffectBase10drawLayerAEPv = 0x002929BC;
_ZN13EnvEffectBase10drawLayerBEPv = 0x002929B0;
_ZN13EnvEffectBase10drawLayerCEPv = 0x002929C4;
_ZN13EnvEffectBase9emitBurstERKN4sead7Vector3IfEE = 0x002929CC;

/* EnvSnow */
_ZTV7EnvSnow = 0x005C8A68;
_ZN7EnvSnowD0Ev = 0x003ED8A4;
_ZN7EnvSnow4initEPN4sead4HeapE = 0x003ED500;
_ZN7EnvSnow7executeEv = 0x003ED4E4;
_ZN7EnvSnow10drawLayerAEPv = 0x003ED894;
_ZN7EnvSnow10drawLayerCEPv = 0x003ED89C;
_ZN7EnvSnow7cleanupEv = 0x003ED828;
_ZN7EnvSnow7canDrawEv = 0x003ED820;
_ZN7EnvSnow16pauseDuringEventEv = 0x003ED4DC;

/* EnvFire */
_ZTV7EnvFire = 0x005CAF08;
_ZN7EnvFireD0Ev = 0x0040C5F4;
_ZN7EnvFire4initEPN4sead4HeapE = 0x0040C278;
_ZN7EnvFire7executeEv = 0x0040C25C;
_ZN7EnvFire10drawLayerAEPv = 0x0040C5E4;
_ZN7EnvFire10drawLayerCEPv = 0x0040C5EC;
_ZN7EnvFire7cleanupEv = 0x0040C578;
_ZN7EnvFire7canDrawEv = 0x0040C570;
_ZN7EnvFire16pauseDuringEventEv = 0x0040C254;

/* EnvGhostFog */
_ZTV11EnvGhostFog = 0x005A5830;
_ZN11EnvGhostFogD0Ev = 0x00225CF4;
_ZN11EnvGhostFog4initEPN4sead4HeapE = 0x00225AD4;
_ZN11EnvGhostFog7executeEv = 0x00225ACC;
_ZN11EnvGhostFog10drawLayerCEPv = 0x00225CEC;
_ZN11EnvGhostFog7cleanupEv = 0x00225CA4;
_ZN11EnvGhostFog7canDrawEv = 0x00225C9C;
_ZN11EnvGhostFog16pauseDuringEventEv = 0x00225AC4;

/* EnvSunRay */
_ZTV9EnvSunRay = 0x005CAED8;
_ZN9EnvSunRayD0Ev = 0x0040C234;
_ZN9EnvSunRay4initEPN4sead4HeapE = 0x005CAEE8;
_ZN9EnvSunRay7executeEv = 0x0040BFF0;
_ZN9EnvSunRay10drawLayerCEPv = 0x0040C22C;
_ZN9EnvSunRay7cleanupEv = 0x0040C1E4;
_ZN9EnvSunRay7canDrawEv = 0x0040C1DC;
_ZN9EnvSunRay16pauseDuringEventEv = 0x0040BFE8;

/* EnvFish */
_ZTV7EnvFish = 0x005C8A38;
_ZN7EnvFishD0Ev = 0x003ED4B4;
_ZN7EnvFish4initEPN4sead4HeapE = 0x003ED0F4;
_ZN7EnvFish7executeEv = 0x003ED0B8;
_ZN7EnvFish10drawLayerAEPv = 0x003ED4A4;
_ZN7EnvFish10drawLayerCEPv = 0x003ED4AC;
_ZN7EnvFish7cleanupEv = 0x003ED424;
_ZN7EnvFish7canDrawEv = 0x003ED41C;
_ZN7EnvFish16pauseDuringEventEv = 0x003ED0B0;

/* EnvEffectMgr */
_ZN12EnvEffectMgr14createInstanceEPN4sead4HeapE = 0x0030C254;
_ZN12EnvEffectMgr9sInstanceE = 0x005E73A0;
_ZN12EnvEffectMgr14deleteInstanceEv = 0x0030C2CC;
_ZN12EnvEffectMgr7executeEv = 0x0030C33C;
_ZN12EnvEffectMgr12insertEffectEP13EnvEffectBase = 0x0030C3A4;
_ZN12EnvEffectMgr4unkAEv = 0x0030C3C8;
_ZN12EnvEffectMgr4unkBEv = 0x0030C448;

/* EnvEffectMgr::SingletonDisposer_ */
_ZTVN12EnvEffectMgr18SingletonDisposer_E = 0x005B5884;
_ZN12EnvEffectMgr18SingletonDisposer_D1Ev = 0x0030C308;
_ZN12EnvEffectMgr18SingletonDisposer_15sStaticDisposerE = 0x005E73A4;

/* EnvEffectHolder */
_ZN15EnvEffectHolder14createInstanceEPN4sead4HeapE = 0x00256A84;
_ZN15EnvEffectHolder9sInstanceE = 0x005E73B8;
_ZN15EnvEffectHolder14deleteInstanceEv = 0x00256B18;
_ZN15EnvEffectHolderD1Ev = 0x00257258;
_ZN15EnvEffectHolder17createSporeEffectEPN4sead4HeapE = 0x00256A1C;
_ZN15EnvEffectHolder17createKillerSmokeERKN4sead7Vector3IfEE = 0x00256BA8;
_ZN15EnvEffectHolder23createMagnumKillerSmokeERKN4sead7Vector3IfEE = 0x00256BB0;
_ZN15EnvEffectHolder21createTailSmokeKazanBERKN4sead7Vector3IfEE = 0x00256BB8;
_ZN15EnvEffectHolder21createTailSmokeKazanAERKN4sead7Vector3IfEE = 0x0033142C;
_ZN15EnvEffectHolder7executeEv = 0x00256BC0;
_ZN15EnvEffectHolder4initEPN4sead4HeapE = 0x00256BD0;
_ZN15EnvEffectHolder16createShellTrailERKN4sead7Vector3IfEENS_14ShellTrailTypeEP9ActorBase = 0x0024B230;
_ZN15EnvEffectHolder16createStarEffectERKN4sead9BoundBox2IfEENS0_4HeapE = 0x002569B4;

/* EnvEffectHolder::SingletonDisposer_ */
_ZTVN15EnvEffectHolder18SingletonDisposer_E = 0x00256B60;
_ZN15EnvEffectHolder18SingletonDisposer_D1Ev = 0x005E73BC;
_ZN15EnvEffectHolder18SingletonDisposer_15sStaticDisposerE = 0x005A9DD8;

/* EnvEffectEmitter */
_ZTV16EnvEffectEmitter = 0x005A9DE0;
_ZN16EnvEffectEmitterC1Ev = 0x00257FF0;
_ZN16EnvEffectEmitterD0Ev = 0x002581FC;
_ZN16EnvEffectEmitter7executeEv = 0x002574F8;
_ZN16EnvEffectEmitter4drawEPv = 0x00257634;
_ZN16EnvEffectEmitter4initEPN4sead12TextureCtrGLEhbPNS0_4HeapE = 0x00257AD4;
_ZN16EnvEffectEmitter7cleanupEv = 0x00257E58;

/* RotShake */
_ZN8RotShake4initERKNS_3ArgE = 0x00429B48;
_ZN8RotShake11updateShakeEv = 0x00429B5C;

/* Bomhei */
_ZTV6Bomhei = 0x005C5D64;
_ZN6BomheiC1Ev = 0x003CE1B8;
_ZN6BomheiD1Ev = 0x003CE224;
_ZN6Bomhei18getRuntimeTypeInfoEv = 0x004AA9C4;
_ZN6Bomhei5buildEv = 0x0055A388;
_ZN6Bomhei7destroyEP5fBase = 0x0055D008;

_ZN6Bomhei8onCreateEv = 0x003CDDB0;
_ZN6Bomhei8onDeleteEv = 0x003CE01C;
_ZN6Bomhei10preExecuteEv = 0x003CBDB0;
_ZN6Bomhei9onExecuteEv = 0x003CDFE4;
_ZN6Bomhei6onDrawEv = 0x003CDD78;
_ZN6Bomhei12powActivatedEv = 0x003CC09C;

_ZN6Bomhei13reactFumiProcEP9ActorBase = 0x003CD1CC;
_ZN6Bomhei14collisionEnemyEP19ActorCollisionCheckS1_ = 0x003CCFEC;
_ZN6Bomhei21collisionPlayer_AwakeEP19ActorCollisionCheckS1_ = 0x003CCB50;
_ZN6Bomhei21collisionPlayer_SleepEP19ActorCollisionCheckS1_ = 0x003CE170;
_ZN6Bomhei17collisionFireballEP19ActorCollisionCheckS1_ = 0x003CC364;
_ZN6Bomhei14collisionSlideEP19ActorCollisionCheckS1_ = 0x003CC4F0;
_ZN6Bomhei20collisionGroundPoundEP19ActorCollisionCheckS1_ = 0x003CCE98;
_ZN6Bomhei20collisionTanookiTailEP19ActorCollisionCheckS1_ = 0x003CC684;

_ZN6Bomhei12createModelsEv = 0x003CBE20;
_ZN6Bomhei17updateModelMatrixEv = 0x003CBBF4;

_ZN6Bomhei12StateID_WalkE = 0x0060E104;
_ZN6Bomhei20initializeState_WalkEv = 0x003CD4C4;
_ZN6Bomhei17executeState_WalkEv = 0x003CCA48;
_ZN6Bomhei18finalizeState_WalkEv = 0x003CCE94;

_ZN6Bomhei12StateID_TurnE = 0x0060E124;
_ZN6Bomhei20initializeState_TurnEv = 0x003CD4A8;
_ZN6Bomhei17executeState_TurnEv = 0x003CC9AC;
_ZN6Bomhei18finalizeState_TurnEv = 0x003CCE90;

_ZN6Bomhei13StateID_0x1ECE = 0x0060E144;
_ZN6Bomhei21initializeState_0x1ECEv = 0x003CD948;
_ZN6Bomhei18executeState_0x1ECEv = 0x003CD6EC;
_ZN6Bomhei19finalizeState_0x1ECEv = 0x003CD764;

_ZN6Bomhei13StateID_0x1EDE = 0x0060E164;
_ZN6Bomhei21initializeState_0x1EDEv = 0x003CDCC8;
_ZN6Bomhei18executeState_0x1EDEv = 0x003CDA1C;
_ZN6Bomhei19finalizeState_0x1EDEv = 0x003CDBE0;

_ZN6Bomhei13StateID_0x1EEE = 0x0060E184;
_ZN6Bomhei21initializeState_0x1EEEv = 0x003CDC30;
_ZN6Bomhei18executeState_0x1EEEv = 0x003CDA18;
_ZN6Bomhei19finalizeState_0x1EEEv = 0x003CDB90;

_ZN6Bomhei17StateID_ExplosionE = 0x0060E1A4;
_ZN6Bomhei25initializeState_ExplosionEv = 0x003CD838;
_ZN6Bomhei22executeState_ExplosionEv = 0x003CD2E8;
_ZN6Bomhei23finalizeState_ExplosionEv = 0x003CD5C8;

_ZN6Bomhei13StateID_CarryE = 0x0060E1C4;
_ZN6Bomhei21initializeState_CarryEv = 0x003CD8F8;
_ZN6Bomhei18executeState_CarryEv = 0x003CD6C0;
_ZN6Bomhei19finalizeState_CarryEv = 0x003CD740;

_ZN6Bomhei13StateID_SleepE = 0x0060E20C;
_ZN6Bomhei21initializeState_SleepEv = 0x003CD5D0;
_ZN6Bomhei18executeState_SleepEv = 0x003CCC64;
_ZN6Bomhei19finalizeState_SleepEv = 0x003CD1B4;

_ZN6Bomhei13StateID_SlideE = 0x0060E1E8;
_ZN6Bomhei21initializeState_SlideEv = 0x003CD62C;
_ZN6Bomhei18executeState_SlideEv = 0x003CCD44;
_ZN6Bomhei19finalizeState_SlideEv = 0x003CD1B8;

_ZN6Bomhei13StateID_0x1F3E = 0x0060E230;
_ZN6Bomhei21initializeState_0x1F3Ev = 0x003CD370;
_ZN6Bomhei18executeState_0x1F3Ev = 0x003CC7F8;
_ZN6Bomhei19finalizeState_0x1F3Ev = 0x003AB0D0;

_ZN6Bomhei15StateID_DieFumiE = 0x0060E250;
_ZN6Bomhei23initializeState_DieFumiEv = 0x003CD7DC;
_ZN6Bomhei20executeState_DieFumiEv = 0x003CD2E4;
_ZN6Bomhei21finalizeState_DieFumiEv = 0x003CD5C4;

_ZN6Bomhei15StateID_DieFallE = 0x0060E274;
_ZN6Bomhei23initializeState_DieFallEv = 0x003CD780;
_ZN6Bomhei20executeState_DieFallEv = 0x003CD2E0;
_ZN6Bomhei21finalizeState_DieFallEv = 0x003CD5C0;

/* Bomhei data */
_ZN6Bomhei9resourcesE = 0x0060E0F4;
_ZN6Bomhei4infoE = 0x005724E4;
_ZN6Bomhei6apInfoE = 0x00572424;
_ZN6Bomhei15apInfoExplosionE = 0x00572448;
_ZN6Bomhei20collisionSensorAboveE = 0x0057246C;
_ZN6Bomhei20collisionSensorBelowE = 0x00572478;
_ZN6Bomhei19collisionSensorSideE = 0x00572484;
_ZN6Bomhei21collisionSensorAbove2E = 0x00572490;
_ZN6Bomhei21collisionSensorBelow2E = 0x0057249C;
_ZN6Bomhei20collisionSensorSide2E = 0x005724A8;

/* Bullet */
_ZN6Bullet8onCreateEv = 0x003D2B40;
_ZN6Bullet10preExecuteEv = 0x003D2448;
_ZN6Bullet9onExecuteEv = 0x003D2B78;
_ZN6Bullet11deleteReadyEv = 0x003D251C;

_ZN6Bullet17waterSplashEffectERKN4sead7Vector3IfEEf = 0x003D2950;
_ZN6Bullet12powActivatedEv = 0x003D2760;

_ZNK6Bullet10isCollidedEv = 0x004AAAB8;
_ZN6Bullet9calcModelEv = 0x0;
_ZN6Bullet11createModelEv = 0x0;
_ZN6Bullet11deleteModelEv = 0x0;
_ZN6Bullet10initializeEv = 0x0;
_ZN6Bullet13setDeathSpeedERKN4sead7Vector3IfEEi = 0x003D2520;
_ZN6Bullet11cullingProcEv = 0x003D2514;
_ZN6Bullet12hitProc_StarEP19ActorCollisionCheck = 0x003D25A4;
_ZN6Bullet13hitProc_ShellEP19ActorCollisionCheck = 0x003D27D4;
_ZN6Bullet12hitProc_TailEP19ActorCollisionCheck = 0x003D2660;
_ZN6Bullet8spitRollEv = 0x003D2C54;
_ZN6Bullet6moveSEEv = 0x0;
_ZN6Bullet8deadRollEv = 0x003D2C20;
_ZN6Bullet17collisionCallbackEP19ActorCollisionCheckS1_ = 0x003D2888;

_ZN6Bullet13StateID_EatInE = 0x006081E4;
_ZN6Bullet21initializeState_EatInEv = 0x003D2A50;
_ZN6Bullet18executeState_EatInEv = 0x003D2998;
_ZN6Bullet19finalizeState_EatInEv = 0x003D29A8;

_ZN6Bullet14StateID_EatNowE = 0x00608208;
_ZN6Bullet22initializeState_EatNowEv = 0x003D2AA8;
_ZN6Bullet19executeState_EatNowEv = 0x003D299C;
_ZN6Bullet20finalizeState_EatNowEv = 0x003D2A0C;

_ZN6Bullet16StateID_SpitMoveE = 0x0060822C;
_ZN6Bullet24initializeState_SpitMoveEv = 0x003D2AF8;
_ZN6Bullet21executeState_SpitMoveEv = 0x003D2A54;
_ZN6Bullet22finalizeState_SpitMoveEv = 0x003D2A4C;

_ZN6Bullet15StateID_ReflectE = 0x00608250;
_ZN6Bullet23initializeState_ReflectEv = 0x003D2AEC;
_ZN6Bullet20executeState_ReflectEv = 0x003D29E4;
_ZN6Bullet21finalizeState_ReflectEv = 0x003D2AE4;

_ZN6Bullet18StateID_HitReflectE = 0x00608274;
_ZN6Bullet26initializeState_HitReflectEv = 0x003D2AFC;
_ZN6Bullet23executeState_HitReflectEv = 0x003D2AAC;
_ZN6Bullet24finalizeState_HitReflectEv = 0x003D2AF0;

_ZN6Bullet15StateID_HitStarE = 0x00608298;
_ZN6Bullet23initializeState_HitStarEv = 0x003D2AE8;
_ZN6Bullet20executeState_HitStarEv = 0x003D29AC;
_ZN6Bullet21finalizeState_HitStarEv = 0x003D2A48;

_ZN6Bullet16StateID_HitShellE = 0x006082BC;
_ZN6Bullet24initializeState_HitShellEv = 0x003D2AF4;
_ZN6Bullet21executeState_HitShellEv = 0x003D2A10;
_ZN6Bullet22finalizeState_HitShellEv = 0x003D2AA4;

_ZN6Bullet22StateID_HitYoshiBulletE = 0x006082E0;
_ZN6Bullet30initializeState_HitYoshiBulletEv = 0x003D2B3C;
_ZN6Bullet27executeState_HitYoshiBulletEv = 0x003D2B00;
_ZN6Bullet28finalizeState_HitYoshiBulletEv = 0x003D2B38;

/* Gasagoso */
_ZN8Gasagoso14StateID_HidingE = 0x0060F42C;
_ZN8Gasagoso22initializeState_HidingEv = 0x00412024;
_ZN8Gasagoso19executeState_HidingEv = 0x00411980;
_ZN8Gasagoso20finalizeState_HidingEv = 0x00411CA0;

_ZN8Gasagoso15StateID_HangingE = 0x0060F44C;
_ZN8Gasagoso23initializeState_HangingEv = 0x00412274;
_ZN8Gasagoso20executeState_HangingEv = 0x00411F6C;
_ZN8Gasagoso21finalizeState_HangingEv = 0x0041205C;

_ZN8Gasagoso11StateID_257E = 0x0060F46C;
_ZN8Gasagoso19initializeState_257Ev = 0x00412270;
_ZN8Gasagoso16executeState_257Ev = 0x00411EF4;
_ZN8Gasagoso17finalizeState_257Ev = 0x00412058;

_ZN8Gasagoso11StateID_258E = 0x0060F48C;
_ZN8Gasagoso19initializeState_258Ev = 0x00412060;
_ZN8Gasagoso16executeState_258Ev = 0x00411C34;
_ZN8Gasagoso17finalizeState_258Ev = 0x00411EF0;

_ZN8Gasagoso11StateID_259E = 0x0060F4AC;
_ZN8Gasagoso19initializeState_259Ev = 0x004121E4;
_ZN8Gasagoso16executeState_259Ev = 0x00411E5C;
_ZN8Gasagoso17finalizeState_259Ev = 0x00411FEC;

_ZN8Gasagoso15StateID_DieFumiE = 0x0060F4CC;
_ZN8Gasagoso23initializeState_DieFumiEv = 0x004120EC;
_ZN8Gasagoso20executeState_DieFumiEv = 0x00411D80;
_ZN8Gasagoso21finalizeState_DieFumiEv = 0x00411FE8;

_ZN8Gasagoso15StateID_DieFallE = 0x0060F4F0;
_ZN8Gasagoso23initializeState_DieFallEv = 0x00412064;
_ZN8Gasagoso20executeState_DieFallEv = 0x00411CA4;
_ZN8Gasagoso21finalizeState_DieFallEv = 0x00411FE4;

/* KuriboTower */
_ZTV11KuriboTower = 0x005A6C28;
_ZN11KuriboTowerC1Ev = 0x00235A24;
_ZN11KuriboTowerD1Ev = 0x00235AEC;
_ZN11KuriboTower18getRuntimeTypeInfoEv = 0x0049C484;
_ZN11KuriboTower5buildEv = 0x00557F58;
_ZN11KuriboTower7destroyEP5fBase = 0x0055B958;

_ZN11KuriboTower8onCreateEv = 0x00235130;
_ZN11KuriboTower8onDeleteEv = 0x00235818;
_ZN11KuriboTower9onExecuteEv = 0x00235570;
_ZN11KuriboTower6onDrawEv = 0x00234F74;
_ZN11KuriboTower13doQuakeBounceEv = 0x00231EF0;
_ZN11KuriboTower12powActivatedEv = 0x00232368;
_ZN11KuriboTower5vf110Ev = 0x00234D9C;
_ZN11KuriboTower5vf114Ev = 0x002348A0;
_ZN11KuriboTower15levelClearDeathEv = 0x00234C94;
_ZN11KuriboTower12damagePlayerEP9ActorBase = 0x002359DC;
_ZNK11KuriboTower8inBoundsERKN4sead10BoundBox2fE = 0x0049C4D0;

_ZN11KuriboTower14collisionEnemyEP19ActorCollisionCheckS1_ = 0x00234B28;
_ZN11KuriboTower15collisionPlayerEP19ActorCollisionCheckS1_ = 0x00234B68;
_ZN11KuriboTower17collisionStarMegaEP19ActorCollisionCheckS1_ = 0x00233A84;
_ZN11KuriboTower14collisionSlideEP19ActorCollisionCheckS1_ = 0x00233940;
_ZN11KuriboTower20collisionGroundPoundEP19ActorCollisionCheckS1_ = 0x002349FC;
_ZN11KuriboTower19collisionPipeCannonEP19ActorCollisionCheckS1_ = 0x0023438C;
_ZN11KuriboTower20collisionTanookiTailEP19ActorCollisionCheckS1_ = 0x00233BF0;
_ZN11KuriboTower14collisionShellEP19ActorCollisionCheckS1_ = 0x00233D1C;
_ZN11KuriboTower17collisionFireballEP19ActorCollisionCheckS1_ = 0x00233728;
_ZN11KuriboTower13onDefeatQuakeEN14ActorCollision18QuakeCollisionTypeEa = 0x00234690;
_ZN11KuriboTower11fumiJumpSetEP10PlayerBase = 0x0049C3F8;
_ZN11KuriboTower9giveScoreEP10PlayerBase = 0x0049C41C;

_ZN11KuriboTower5vf1D4Ev = 0x00234830;
_ZN11KuriboTower5vf1D8Ev = 0x00234BF4;
_ZN11KuriboTower5vf1DCEv = 0x00232B2C;
_ZN11KuriboTower5vf1E4Ev = 0x0049C588;

_ZN11KuriboTower10sub_231CDCEv = 0x00231CDC;
_ZN11KuriboTower11reduceStackEi = 0x00231F00;
_ZN11KuriboTower10sub_23215CEji = 0x0023215C;
_ZN11KuriboTower10sub_232234Ev = 0x00232234;
_ZN11KuriboTower10sub_232484Ev = 0x00232484;
_ZN11KuriboTower10sub_232698Ei = 0x00232698;
_ZN11KuriboTower10sub_232A18Ev = 0x00232A18;
_ZN11KuriboTower7setAnimEjRKN4sead14SafeStringBaseIcEE10PlayPolicyf = 0x00232B74;
_ZN11KuriboTower10sub_232D20EPN4sead7Vector3IfEEi = 0x00232D20;
_ZN11KuriboTower10sub_232E38Ev = 0x00232E38;
_ZN11KuriboTower10sub_233098Ej = 0x00233098;
_ZN11KuriboTower10sub_233364Ev = 0x00233364;
_ZN11KuriboTower10sub_233E70Ev = 0x00233E70;
_ZN11KuriboTower10sub_2344D4EjiPKN4sead7Vector3IfEE = 0x002344D4;
_ZN11KuriboTower10sub_2358E4ERKN4sead14SafeStringBaseIcEE10PlayPolicyf = 0x002358E4;

_ZN11KuriboTower11StateID_2C9E = 0x00610858;
_ZN11KuriboTower19initializeState_2C9Ev = 0x00234F70;
_ZN11KuriboTower16executeState_2C9Ev = 0x00234EF4;
_ZN11KuriboTower17finalizeState_2C9Ev = 0x00234F5C;

_ZN11KuriboTower11StateID_2CAE = 0x00610878;
_ZN11KuriboTower19initializeState_2CAEv = 0x00234D74;
_ZN11KuriboTower16executeState_2CAEv = 0x00234318;
_ZN11KuriboTower17finalizeState_2CAEv = 0x002349F8;

_ZN11KuriboTower11StateID_2CBE = 0x00610898;
_ZN11KuriboTower19initializeState_2CBEv = 0x00234D58;
_ZN11KuriboTower16executeState_2CBEv = 0x002342C8;
_ZN11KuriboTower17finalizeState_2CBEv = 0x002349F4;

_ZN11KuriboTower15StateID_DieFumiE = 0x006108B8;
_ZN11KuriboTower23initializeState_DieFumiEv = 0x00234F64;
_ZN11KuriboTower20executeState_DieFumiEv = 0x00234D54;
_ZN11KuriboTower21finalizeState_DieFumiEv = 0x00234D98;

_ZN11KuriboTower15StateID_DieFallE = 0x006108DC;
_ZN11KuriboTower23initializeState_DieFallEv = 0x00234F60;
_ZN11KuriboTower20executeState_DieFallEv = 0x00234D50;
_ZN11KuriboTower21finalizeState_DieFallEv = 0x00234D94;

_ZN11KuriboTower16StateID_DieSmokeE = 0x00610900;
_ZN11KuriboTower24initializeState_DieSmokeEv = 0x00234F6C;
_ZN11KuriboTower21executeState_DieSmokeEv = 0x00234D90;
_ZN11KuriboTower22finalizeState_DieSmokeEv = 0x00234F58;

_ZN11KuriboTower16StateID_DieOtherE = 0x00610924;
_ZN11KuriboTower24initializeState_DieOtherEv = 0x00234F68;
_ZN11KuriboTower21executeState_DieOtherEv = 0x00234D8C;
_ZN11KuriboTower22finalizeState_DieOtherEv = 0x00234F54;

/* KuriboTower data */
_ZN11KuriboTower7xSpeedsE = 0x005752C0;
_ZN11KuriboTower7apInfo1E = 0x005752C8;
_ZN11KuriboTower7apInfo2E = 0x005752EC;
_ZN11KuriboTower4infoE = 0x00575344;
_ZN11KuriboTower9resourcesE = 0x00610948;

/* Hanachan */
_ZTV8Hanachan = 0x005CBA78;
_ZN8HanachanC1Ev = 0x00418450;
_ZN8HanachanD1Ev = 0x00418514;
_ZN8Hanachan18getRuntimeTypeInfoEv = 0x004ADA50;
_ZN8Hanachan5buildEv = 0x0055AA1C;
_ZN8Hanachan7destroyEP5fBase = 0x0055D3F8;

_ZN8Hanachan8onCreateEv = 0x00417E40;
_ZN8Hanachan8onDeleteEv = 0x004181C4;
_ZN8Hanachan9onExecuteEv = 0x004180C4;
_ZN8Hanachan6onDrawEv = 0x00417E10;
_ZN8Hanachan13doQuakeBounceEv = 0x004161E8;
_ZN8Hanachan5vf110Ev = 0x00417414;
_ZN8Hanachan15levelClearDeathEv = 0x004170E8;

_ZN8Hanachan17collisionFireballEP19ActorCollisionCheckS1_ = 0x004165C4;
_ZN8Hanachan14collisionSlideEP19ActorCollisionCheckS1_ = 0x004166D4;
_ZN8Hanachan20collisionTanookiTailEP19ActorCollisionCheckS1_ = 0x00416758;
_ZN8Hanachan20collisionGroundPoundEP19ActorCollisionCheckS1_ = 0x00416E8C;
_ZN8Hanachan14collisionEnemyEP19ActorCollisionCheckS1_ = 0x00416F90;
_ZN8Hanachan25removeActorCollisionCheckEv = 0x00418244;
_ZN8Hanachan22addActorCollisionCheckEv = 0x0041829C;

_ZN8Hanachan10sub_4162B4EPN4sead7Vector3IfEE = 0x004162B4;

_ZN8Hanachan12StateID_WalkE = 0x0060F958;
_ZN8Hanachan20initializeState_WalkEv = 0x004173C4;
_ZN8Hanachan17executeState_WalkEv = 0x00416B40;
_ZN8Hanachan18finalizeState_WalkEv = 0x00416E88;

_ZN8Hanachan11StateID_276E = 0x0060F978;
_ZN8Hanachan19initializeState_276Ev = 0x00417454;
_ZN8Hanachan16executeState_276Ev = 0x00416CB4;
_ZN8Hanachan17finalizeState_276Ev = 0x0041711C;

_ZN8Hanachan11StateID_277E = 0x0060F998;
_ZN8Hanachan19initializeState_277Ev = 0x00417644;
_ZN8Hanachan16executeState_277Ev = 0x00417230;
_ZN8Hanachan17finalizeState_277Ev = 0x004173E8;

_ZN8Hanachan11StateID_278E = 0x0060F9B8;
_ZN8Hanachan19initializeState_278Ev = 0x004173A4;
_ZN8Hanachan16executeState_278Ev = 0x00416954;
_ZN8Hanachan17finalizeState_278Ev = 0x00416E84;

_ZN8Hanachan15StateID_DieFallE = 0x0060F9D8;
_ZN8Hanachan23initializeState_DieFallEv = 0x0041759C;
_ZN8Hanachan20executeState_DieFallEv = 0x00417120;
_ZN8Hanachan21finalizeState_DieFallEv = 0x004173E4;

/* Hanachan data */
_ZN8Hanachan12bottomSensorE = 0x00574050;
_ZN8Hanachan14adjacentSensorE = 0x0057405C;
_ZN8Hanachan14collisionData1E = 0x00574068;
_ZN8Hanachan14collisionData2E = 0x0057408C;
_ZN8Hanachan4infoE = 0x005740D8;
_ZN8Hanachan9resourcesE = 0x0060F9FC;

/* HanachanBodyBase */
_ZTV16HanachanBodyBase = 0x005B7B20;

/* VertexBuffer */
_ZN12VertexBufferC1Ev = 0x0024BF90;
_ZN12VertexBuffer10sub_24B970EPN4sead4HeapEjRKN4sead12TextureCtrGRE = 0x0024B970;
_ZN12VertexBuffer10sub_24BD4CEv = 0x0024BD4C;
_ZN12VertexBuffer10sub_24BE80Ev = 0x0024BE80;

/* DistantViewMgr */
_ZTVN14DistantViewMgrE = 0x005B1B44;
_ZN14DistantViewMgrC1Ev = 0x002E80D4;
_ZN14DistantViewMgrD0Ev = 0x002E82F4;
_ZN14DistantViewMgrD1Ev = 0x002E83B8;
_ZN14DistantViewMgr14createInstanceEPN4sead4HeapE = 0x002E7A68;
_ZN14DistantViewMgr14deleteInstanceEv = 0x002E7AD0;
_ZN14DistantViewMgr9sInstanceE = 0x005E60E8;
_ZN14DistantViewMgr7executeEv = 0x002E6A74;
_ZN14DistantViewMgr11updateModelEv = 0x002E6A78;
_ZN14DistantViewMgr4loadEhhRKN4sead9BoundBox2IfEE = 0x002E6CB4;
_ZN14DistantViewMgr16setMaterialAlphaEjf = 0x002E7B6C;
_ZN14DistantViewMgr4drawEv = 0x002E7BB0;
_ZN14DistantViewMgr11unkCallbackEv = 0x002E80A0;

/* DistantViewMgr::SingletonDisposer_ */
_ZTVN14DistantViewMgr18SingletonDisposer_E = 0x005B1B34;
_ZN14DistantViewMgr18SingletonDisposer_15sStaticDisposerE = 0x005E60EC;
_ZN14DistantViewMgr18SingletonDisposer_D1Ev = 0x002E7B1C;

/* sead::Delegate<DistantViewMgr> */
_ZTVN4sead8DelegateI14DistantViewMgrEE = 0x005D300C;
_ZN4sead8DelegateIN14DistantViewMgrEE6invokeEv = 0x0055FB6C;

/* DistantViewMgr::Material */
_ZN14DistantViewMgr8MaterialC1Ev = 0x002E7A5C;

/* BeansKuriboMgr */
_ZN14BeansKuriboMgr9sInstanceE = 0x005E6238;
_ZN14BeansKuriboMgr14createInstanceEPN4sead4HeapE = 0x002E46D0;
_ZN14BeansKuriboMgr14deleteInstanceEv = 0x002E47BC;
_ZN14BeansKuriboMgr18SingletonDisposer_D1Ev = 0x002E4800;
_ZN14BeansKuriboMgr15sStaticDisposerE = 0x005E6240;
_ZTVN14BeansKuriboMgr18SingletonDisposer_E = 0x005B17F4;

/* Sanbo */
_ZTV5Sanbo = 0x005C4DC4;
_ZN5SanboC1Ev = 0x003BF4F4;
_ZN5SanboD1Ev = 0x003BF5A0;
_ZN5Sanbo8onCreateEv = 0x003BEF28;
_ZN5Sanbo8onDeleteEv = 0x003BF2DC;
_ZN5Sanbo9onExecuteEv = 0x003BF10C;
_ZN5Sanbo6onDrawEv = 0x003BEED4;
_ZN5Sanbo18getRuntimeTypeInfoEv = 0x004A7614;
_ZN5Sanbo20removeCollisionCheckEv = 0x003BF3AC;
_ZN5Sanbo17addCollisionCheckEv = 0x003BF3F8;
_ZN5Sanbo15levelClearDeathEv = 0x003BEAC8;
_ZN5Sanbo12powActivatedEv = 0x003BDAE4;
_ZN5Sanbo5vf110Ev = 0x003BEDAC;
_ZN5Sanbo23collisionHandlerEnemiesEP19ActorCollisionCheckS1_ = 0x003BE88C;
_ZN5Sanbo17collisionStarMegaEP19ActorCollisionCheckS1_ = 0x003BDF94;
_ZN5Sanbo14collisionSlideEP19ActorCollisionCheckS1_ = 0x003BDF84;
_ZN5Sanbo20collisionGroundPoundEP19ActorCollisionCheckS1_ = 0x003BE884;
_ZN5Sanbo20collisionTanookiTailEP19ActorCollisionCheckS1_ = 0x003BE064;
_ZN5Sanbo14collisionShellEP19ActorCollisionCheckS1_ = 0x003BE1A8;
_ZN5Sanbo17collisionFireballEP19ActorCollisionCheckS1_ = 0x003BDE2C;
_ZN5Sanbo13onDefeatQuakeEN14ActorCollision18QuakeCollisionTypeEa = 0x003BE5E4;

_ZN5Sanbo12StateID_idleE = 0x00611640;
_ZN5Sanbo20initializeState_idleEv = 0x003BEC14;
_ZN5Sanbo17executeState_idleEv = 0x003BE344;
_ZN5Sanbo18finalizeState_idleEv = 0x003BE818;

_ZN5Sanbo19StateID_reduceStackE = 0x00611660;
_ZN5Sanbo27initializeState_reduceStackEv = 0x003BEE10;
_ZN5Sanbo24executeState_reduceStackEv = 0x003BEB28;
_ZN5Sanbo25finalizeState_reduceStackEv = 0x003BEC10;

_ZN5Sanbo16StateID_collapseE = 0x00611680;
_ZN5Sanbo24initializeState_collapseEv = 0x003BEE74;
_ZN5Sanbo21executeState_collapseEv = 0x003BEE60;
_ZN5Sanbo22finalizeState_collapseEv = 0x003BEE64;

_ZN5Sanbo12createDeadElEP10PlayerBasej = 0x003BE6A8;
_ZN5Sanbo13removeElementEP10PlayerBasej = 0x003BF444;
_ZN5Sanbo4killEP12PlayerObjectN8ScoreMgr10RewardTypeE = 0x003BE57C;

/* SanboRenderer */
_ZTV13SanboRenderer = 0x005AF32C;
_ZN13SanboRendererC1Ev = 0x002A6E64;
_ZN13SanboRendererD1Ev = 0x002A6E88;
_ZN13SanboRenderer3vf8Ev = 0x002A6CFC;
_ZN13SanboRenderer9drawModelEv = 0x002A6E34;
_ZN13SanboRenderer12setTransformERKN7SanboEl9TransformE = 0x002A6D00;
_ZN13SanboRenderer13setDeathDepthEv = 0x002A6CC0;

/* SanboElCtrl */
_ZN11SanboElCtrl7setModeENS_4ModeE = 0x002493C8;

/* RotParentBase */
_ZTV13RotParentBase = 0x005AF200;
_ZN13RotParentBaseC1Ev = 0x002A6C28;
_ZN13RotParentBaseC2Ev = 0x002A6C28;
_ZN13RotParentBase8onCreateEv = 0x002A6698;
_ZN13RotParentBase8onDeleteEv = 0x002A6BEC;
_ZN13RotParentBase9onExecuteEv = 0x002A6B5C;
_ZN13RotParentBase6onDrawEv = 0x002A65D4;
_ZN13RotParentBase18getRuntimeTypeInfoEv = 0x004A0488;
_ZN13RotParentBase8getModelEv = 0x0;
_ZN13RotParentBase11createChildERKN4sead7Vector3IfEEj = 0x0;
_ZN13RotParentBase15createChildCoinERKN4sead7Vector3IfEEj = 0x002A6A68;
_ZN13RotParentBase11createModelEv = 0x0;
_ZN13RotParentBase15updateAnimationEv = 0x0;
_ZN13RotParentBase13isInViewRangeEv = 0x002A6224;
_ZN13RotParentBase15isInActiveRangeEv = 0x002A62CC;
_ZN13RotParentBase17setChildrenActiveEb = 0x002A6440;
_ZN13RotParentBase14calcChildAngleEjRN4sead7Vector2IfEE = 0x002A63B4;
_ZNK4sead15RuntimeTypeInfo6DeriveI13RotParentBaseE9isDerivedEPKNS0_9InterfaceE = 0x00567548;
_ZTVN4sead15RuntimeTypeInfo6DeriveI13RotParentBaseEE = 0x005D1D34;
_ZGVZN13RotParentBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006037E0;
_ZZN13RotParentBase24getRuntimeTypeInfoStaticEvE8typeInfo = 0x006037E4;
_ZN13RotParentBase14StateID_RotateE = 0x00611610;
_ZN13RotParentBase22initializeState_RotateEv = 0x002A65D0;
_ZN13RotParentBase19executeState_RotateEv = 0x002A659C;
_ZN13RotParentBase20finalizeState_RotateEv = 0x002A65CC;

/* AnimBlendingCalcRatio */
_ZTV21AnimBlendingCalcRatio = 0x005BCC14;
_ZN21AnimBlendingCalcRatioC1Ei = 0x00345454;
_ZN21AnimBlendingCalcRatioD0Ev = 0x00345538;
_ZN21AnimBlendingCalcRatioD2Ev = 0x0034557C;
_ZN21AnimBlendingCalcRatio4calcEv = 0x003453C8;
_ZN21AnimBlendingCalcRatio3setEf = 0x00345374;
_ZN21AnimBlendingCalcRatio7applyToEPN4sead8Matrix34IfEEPKS2_PNS0_7Vector3IfEEPKS7_i = 0x0034508C;
_ZN21AnimBlendingCalcRatio7applyToEP20SkeletalModelWrapper = 0x00344FB0;

/* BsFogMgr */
_ZN8BsFogMgr8instanceEv = 0x00484D80;
_ZN8BsFogMgr9sInstanceE = 0x005EF91C;
_ZN8BsFogMgrD1Ev = 0x00484EDC;
_ZN8BsFogMgrC1Ev = 0x00484EAC;
_ZTV8BsFogMgr = 0x0059AC40;
_ZN8BsFogMgr17setMinDepthOffsetENS_8FogLayerEi = 0x00484D90;
_ZN8BsFogMgr9updateFogEv = 0x00484C8C;
_ZN8BsFogMgr8onCreateEv = 0x00484DD0;
_ZN8BsFogMgr9onExecuteEv = 0x00484E5C;
_ZN8BsFogMgr6onDrawEv = 0x00484D9C;
_ZN8BsFogMgr8onDeleteEv = 0x00484E6C;

/* FogWrapper */
_ZTV10FogWrapper = 0x0059E2F4;
_ZN10FogWrapperC1Ev = 0x001B4170;
_ZN10FogWrapperD1Ev = 0x001B4198;
_ZN10FogWrapper15updateTransformEv = 0x001B416C;
_ZN10FogWrapper6createEP13HeapAllocator = 0x001B40B8;

_ZN8BsFogMgr8sFogWorkE = 0x005EF938;
_ZN8BsFogMgr10sFogActiveE = 0x0062A7AC;

_ZN8BsFogMgr9sFogColorE = 0x0062A7D4;

/* Lyt::LayoutBase */
_ZN3Lyt10LayoutBase3vf0Ev = 0x0;

/* Lyt::Layout */
_ZTVN3Lyt6LayoutE = 0x005C17F0;
_ZN3Lyt6LayoutC1Ev = 0x0038F580;
_ZN3Lyt6LayoutD1Ev = 0x0038F590;

/* Lyt::StateLayout */
_ZTVN3Lyt11StateLayoutE = 0x005C187C;
_ZN3Lyt11StateLayoutC1Ev = 0x0038FB08;
_ZN3Lyt11StateLayoutD1Ev = 0x0038FB7C;
_ZN3Lyt11StateLayout11changeStateERK7StateID = 0x0038FA90;

/* Lyt::StateLayoutType1 */
_ZTVN3Lyt16StateLayoutType1E = 0x005C1894;
_ZN3Lyt16StateLayoutType1C1Ev = 0x0038FD98;
_ZN3Lyt16StateLayoutType1C2Ev = 0x0038FD98;
_ZN3Lyt16StateLayoutType1D1Ev = 0x0038FB78;
_ZN3Lyt16StateLayoutType1D2Ev = 0x0038FB78;

_ZN3Lyt16StateLayoutType16appearEv = 0x0038FC14;
_ZN3Lyt16StateLayoutType19disappearEv = 0x0038FC80;

_ZN3Lyt16StateLayoutType114StateID_hiddenE = 0x00629F8C;
_ZN3Lyt16StateLayoutType122initializeState_hiddenEv = 0x0038FBFC;
_ZN3Lyt16StateLayoutType119executeState_hiddenEv = 0x0038FBD4;
_ZN3Lyt16StateLayoutType120finalizeState_hiddenEv = 0x0038FBE4;

_ZN3Lyt16StateLayoutType114StateID_appearE = 0x00629FB0;
_ZN3Lyt16StateLayoutType122initializeState_appearEv = 0x0038FBE0;
_ZN3Lyt16StateLayoutType119executeState_appearEv = 0x0038FBA0;
_ZN3Lyt16StateLayoutType120finalizeState_appearEv = 0x0038FBC8;

_ZN3Lyt16StateLayoutType115StateID_visibleE = 0x00629FD4;
_ZN3Lyt16StateLayoutType123initializeState_visibleEv = 0x0038FC04;
_ZN3Lyt16StateLayoutType120executeState_visibleEv = 0x0038FBF0;
_ZN3Lyt16StateLayoutType121finalizeState_visibleEv = 0x0038FBF8;

_ZN3Lyt16StateLayoutType117StateID_disappearE = 0x00629FF8;
_ZN3Lyt16StateLayoutType125initializeState_disappearEv = 0x0038FBEC;
_ZN3Lyt16StateLayoutType122executeState_disappearEv = 0x0038FBB4;
_ZN3Lyt16StateLayoutType123finalizeState_disappearEv = 0x0038FBD0;

_ZN3Lyt16StateLayoutType114StateID_pausedE = 0x0062A01C;
_ZN3Lyt16StateLayoutType122initializeState_pausedEv = 0x0038FC00;
_ZN3Lyt16StateLayoutType119executeState_pausedEv = 0x0038FBD8;
_ZN3Lyt16StateLayoutType120finalizeState_pausedEv = 0x0038FBE8;

_ZN3Lyt16StateLayoutType112StateID_Unk6E = 0x0062A040;
_ZN3Lyt16StateLayoutType120initializeState_Unk6Ev = 0x0038FBF4;
_ZN3Lyt16StateLayoutType117executeState_Unk6Ev = 0x0038FBCC;
_ZN3Lyt16StateLayoutType118finalizeState_Unk6Ev = 0x0038FBDC;

_ZN3Lyt16StateLayoutType110showLayoutEv = 0x0;
_ZN3Lyt16StateLayoutType110hideLayoutEv = 0x0;
_ZN3Lyt16StateLayoutType19setPausedEb = 0x0038FCE0;
_ZN3Lyt16StateLayoutType14vf6CEv = 0x0;

/* Lyt::PlaySceneRadarTeresa_00 */
_ZTVN3Lyt23PlaySceneRadarTeresa_00E = 0x005C0A8C;
_ZN3Lyt23PlaySceneRadarTeresa_009sInstanceE = 0x005EF2C4;
_ZN3Lyt23PlaySceneRadarTeresa_0014createInstanceEPN4sead4HeapE = 0x00380298;
_ZN3Lyt23PlaySceneRadarTeresa_0014deleteInstanceEv = 0x00380360;
_ZN3Lyt23PlaySceneRadarTeresa_006createEv = 0x00380524;
_ZN3Lyt23PlaySceneRadarTeresa_007executeEv = 0x0038070C;
_ZN3Lyt23PlaySceneRadarTeresa_004drawEv = 0x00380480;
_ZN3Lyt23PlaySceneRadarTeresa_007delete_Ev = 0x00380704;
_ZN3Lyt23PlaySceneRadarTeresa_0020copyPositionFromPaneEPKN2nw3lyt4PaneE = 0x0038026C;
_ZN3Lyt23PlaySceneRadarTeresa_0010sub_380230Ev = 0x00380230;

/* Lyt::PlaySceneRadar_00 */
_ZTVN3Lyt17PlaySceneRadar_00E = 0x005BF85C;
_ZN3Lyt17PlaySceneRadar_009sInstanceE = 0x005EF310;
_ZN3Lyt17PlaySceneRadar_0014createInstanceEPN4sead4HeapE = 0x0036C9FC;
_ZN3Lyt17PlaySceneRadar_0014deleteInstanceEv = 0x0036CADC;
_ZN3Lyt17PlaySceneRadar_006createEv = 0x0036D1C0;
_ZN3Lyt17PlaySceneRadar_007executeEv = 0x0036D424;
_ZN3Lyt17PlaySceneRadar_004drawEv = 0x0036D0E8;
_ZN3Lyt17PlaySceneRadar_007delete_Ev = 0x0036D35C;
_ZN3Lyt17PlaySceneRadar_0020copyPositionFromPaneEPKN2nw3lyt4PaneE = 0x0036C9D0;
_ZN3Lyt17PlaySceneRadar_0010sub_36C954Ev = 0x0036C954;
_ZN3Lyt17PlaySceneRadar_0010sub_36CE14Ev = 0x0036CE14;

/* StockIconNext */
_ZN13StockIconNext9sInstanceE = 0x005EF4E8;

/* Lyt::PlaySceneTop1P_00 */
_ZN3Lyt17PlaySceneTop1P_009sInstanceE = 0x005EF344;
_ZN3Lyt17PlaySceneTop1P_0014createInstanceEPN4sead4HeapE = 0x0036DA70;
_ZN3Lyt17PlaySceneTop1P_0014deleteInstanceEv = 0x0036DAD8;
_ZN3Lyt17PlaySceneTop1P_0018initForCurrentAreaEv = 0x0036F068;
_ZN3Lyt17PlaySceneTop1P_0018SingletonDisposer_D1Ev = 0x002E4800;
_ZN3Lyt17PlaySceneTop1P_0015sStaticDisposerE = 0x005EF348;

/* Lyt::CountDownStartTop_00 */
_ZTVN3Lyt20CountDownStartTop_00E = 0x005C0020;
_ZN3Lyt20CountDownStartTop_00C1Ev = 0x00376B10;
_ZN3Lyt20CountDownStartTop_006createEv = 0x00376918;
_ZN3Lyt20CountDownStartTop_005resetEv = 0x003763C4;
_ZN3Lyt20CountDownStartTop_007executeEv = 0x00376A00;
_ZN3Lyt20CountDownStartTop_004drawEv = 0x00376880;
_ZN3Lyt20CountDownStartTop_007delete_Ev = 0x003769F8;
_ZN3Lyt20CountDownStartTop_0017StateID_countdownE = 0x00621148;
_ZN3Lyt20CountDownStartTop_0010StateID_goE = 0x0062116C;
_ZN3Lyt20CountDownStartTop_0012StateID_doneE = 0x00621190;

/* Lyt::CommonWindowA_00 */
_ZTVN3Lyt16CommonWindowA_00E = 0x005BF318;
_ZN3Lyt16CommonWindowA_00C1Ev = 0x00367728;
_ZN3Lyt16CommonWindowA_00D1Ev = 0x003678D8;

_ZN3Lyt16CommonWindowA_0014StateID_hiddenE = 0x006205C8;
_ZN3Lyt16CommonWindowA_0022initializeState_hiddenEv = 0x00366AD4;
_ZN3Lyt16CommonWindowA_0019executeState_hiddenEv = 0x003666F0;
_ZN3Lyt16CommonWindowA_0020finalizeState_hiddenEv = 0x0036683C;

_ZN3Lyt16CommonWindowA_0014StateID_appearE = 0x006205EC;
_ZN3Lyt16CommonWindowA_0022initializeState_appearEv = 0x00366774;
_ZN3Lyt16CommonWindowA_0019executeState_appearEv = 0x00366290;
_ZN3Lyt16CommonWindowA_0020finalizeState_appearEv = 0x00366460;

_ZN3Lyt16CommonWindowA_0015StateID_visibleE = 0x00620610;
_ZN3Lyt16CommonWindowA_0023initializeState_visibleEv = 0x00366B80;
_ZN3Lyt16CommonWindowA_0020executeState_visibleEv = 0x0036699C;
_ZN3Lyt16CommonWindowA_0021finalizeState_visibleEv = 0x00366A08;

_ZN3Lyt16CommonWindowA_0017StateID_disappearE = 0x00620634;
_ZN3Lyt16CommonWindowA_0025initializeState_disappearEv = 0x003668F4;
_ZN3Lyt16CommonWindowA_0022executeState_disappearEv = 0x0036639C;
_ZN3Lyt16CommonWindowA_0023finalizeState_disappearEv = 0x00366514;

_ZN3Lyt16CommonWindowA_009disappearEv = 0x00366E94;
_ZN3Lyt16CommonWindowA_0010hideLayoutEv = 0x00366164;

_ZN3Lyt16CommonWindowA_0020StateID_waitCircleInE = 0x00620658;
_ZN3Lyt16CommonWindowA_0028initializeState_waitCircleInEv = 0x0038FC08;
_ZN3Lyt16CommonWindowA_0025executeState_waitCircleInEv = 0x00366C28;
_ZN3Lyt16CommonWindowA_0026finalizeState_waitCircleInEv = 0x00366DEC;

_ZN3Lyt16CommonWindowA_0021StateID_waitCircleOutE = 0x0062067C;
_ZN3Lyt16CommonWindowA_0029initializeState_waitCircleOutEv = 0x0038FC74;
_ZN3Lyt16CommonWindowA_0026executeState_waitCircleOutEv = 0x00366D2C;
_ZN3Lyt16CommonWindowA_0027finalizeState_waitCircleOutEv = 0x00366E28;

_ZN3Lyt16CommonWindowA_0016StateID_windowInE = 0x006206A0;
_ZN3Lyt16CommonWindowA_0024initializeState_windowInEv = 0x003669F0;
_ZN3Lyt16CommonWindowA_0021executeState_windowInEv = 0x0036650C;
_ZN3Lyt16CommonWindowA_0022finalizeState_windowInEv = 0x00366748;

_ZN3Lyt16CommonWindowA_0015StateID_menu4InE = 0x006206C4;
_ZN3Lyt16CommonWindowA_0023initializeState_menu4InEv = 0x00366AF0;
_ZN3Lyt16CommonWindowA_0020executeState_menu4InEv = 0x00366704;
_ZN3Lyt16CommonWindowA_0021finalizeState_menu4InEv = 0x00366898;

_ZN3Lyt16CommonWindowA_0015StateID_menu3InE = 0x006206E8;
_ZN3Lyt16CommonWindowA_0023initializeState_menu3InEv = 0x00366AE4;
_ZN3Lyt16CommonWindowA_0020executeState_menu3InEv = 0x003666FC;
_ZN3Lyt16CommonWindowA_0021finalizeState_menu3InEv = 0x0036686C;

_ZN3Lyt16CommonWindowA_0018StateID_windowLoopE = 0x0062070C;
_ZN3Lyt16CommonWindowA_0026initializeState_windowLoopEv = 0x00367574;
_ZN3Lyt16CommonWindowA_0023executeState_windowLoopEv = 0x00366500;
_ZN3Lyt16CommonWindowA_0024finalizeState_windowLoopEv = 0x00366718;

_ZN3Lyt16CommonWindowA_0015StateID_menu2InE = 0x00620730;
_ZN3Lyt16CommonWindowA_0023initializeState_menu2InEv = 0x00366AD8;
_ZN3Lyt16CommonWindowA_0020executeState_menu2InEv = 0x003666F4;
_ZN3Lyt16CommonWindowA_0021finalizeState_menu2InEv = 0x00366840;

_ZN3Lyt16CommonWindowA_0017StateID_balloonInE = 0x00620754;
_ZN3Lyt16CommonWindowA_0025initializeState_balloonInEv = 0x00366E2C;
_ZN3Lyt16CommonWindowA_0022executeState_balloonInEv = 0x00366B38;
_ZN3Lyt16CommonWindowA_0023finalizeState_balloonInEv = 0x00366C8C;

_ZN3Lyt16CommonWindowA_0019StateID_balloonIdleE = 0x00620778;
_ZN3Lyt16CommonWindowA_0027initializeState_balloonIdleEv = 0x00366E70;
_ZN3Lyt16CommonWindowA_0024executeState_balloonIdleEv = 0x00366C20;
_ZN3Lyt16CommonWindowA_0025finalizeState_balloonIdleEv = 0x00366DC0;

_ZN3Lyt16CommonWindowA_0018StateID_balloonOutE = 0x0062079C;
_ZN3Lyt16CommonWindowA_0026initializeState_balloonOutEv = 0x00366E64;
_ZN3Lyt16CommonWindowA_0023executeState_balloonOutEv = 0x00366BE4;
_ZN3Lyt16CommonWindowA_0024finalizeState_balloonOutEv = 0x00366D90;

_ZN3Lyt16CommonWindowA_0014StateID_msg1InE = 0x006207C0;
_ZN3Lyt16CommonWindowA_0022initializeState_msg1InEv = 0x00366BC0;
_ZN3Lyt16CommonWindowA_0019executeState_msg1InEv = 0x003669D4;
_ZN3Lyt16CommonWindowA_0020finalizeState_msg1InEv = 0x00366A4C;

_ZN3Lyt16CommonWindowA_0014StateID_msg2InE = 0x006207E4;
_ZN3Lyt16CommonWindowA_0022initializeState_msg2InEv = 0x00366BCC;
_ZN3Lyt16CommonWindowA_0019executeState_msg2InEv = 0x003669DC;
_ZN3Lyt16CommonWindowA_0020finalizeState_msg2InEv = 0x00366A78;

_ZN3Lyt16CommonWindowA_0017StateID_msgOnlyInE = 0x00620808;
_ZN3Lyt16CommonWindowA_0025initializeState_msgOnlyInEv = 0x00366BD8;
_ZN3Lyt16CommonWindowA_0022executeState_msgOnlyInEv = 0x003669E8;
_ZN3Lyt16CommonWindowA_0023finalizeState_msgOnlyInEv = 0x00366AA8;

_ZN3Lyt16CommonWindowA_0018StateID_msg1LongInE = 0x0062082C;
_ZN3Lyt16CommonWindowA_0026initializeState_msg1LongInEv = 0x00366CBC;
_ZN3Lyt16CommonWindowA_0023executeState_msg1LongInEv = 0x003669FC;
_ZN3Lyt16CommonWindowA_0024finalizeState_msg1LongInEv = 0x00366B08;

_ZN3Lyt16CommonWindowA_0017StateID_windowOutE = 0x00620850;
_ZN3Lyt16CommonWindowA_0025initializeState_windowOutEv = 0x00366AFC;
_ZN3Lyt16CommonWindowA_0022executeState_windowOutEv = 0x00366710;
_ZN3Lyt16CommonWindowA_0023finalizeState_windowOutEv = 0x003668C8;

_ZN3Lyt16CommonWindowA_0017StateID_backBtnInE = 0x00620874;
_ZN3Lyt16CommonWindowA_0025initializeState_backBtnInEv = 0x00366E7C;
_ZN3Lyt16CommonWindowA_0022executeState_backBtnInEv = 0x00366D20;
_ZN3Lyt16CommonWindowA_0023finalizeState_backBtnInEv = 0x00366DF8;

_ZN3Lyt16CommonWindowA_0018StateID_backBtnOutE = 0x00620898;
_ZN3Lyt16CommonWindowA_0026initializeState_backBtnOutEv = 0x00366E88;
_ZN3Lyt16CommonWindowA_0023executeState_backBtnOutEv = 0x00366DF0;
_ZN3Lyt16CommonWindowA_0024finalizeState_backBtnOutEv = 0x00366E38;

_ZN3Lyt16CommonWindowA_0010initializeEv = 0x00365B80;
_ZN3Lyt16CommonWindowA_007setTextENS0_9TextBoxIdERKN4sead14SafeStringBaseIcEES6_iz = 0x00365C54;
_ZN3Lyt16CommonWindowA_008playAnimENS0_6AnimIdEb = 0x00365D20;
_ZN3Lyt16CommonWindowA_0017setButtonDisabledENS0_9TextBoxIdEb = 0x00365DA8;
_ZN3Lyt16CommonWindowA_0010setupMenusEv = 0x00365E14;
_ZN3Lyt16CommonWindowA_0012setupLayoutsEv = 0x00365F84;
_ZN3Lyt16CommonWindowA_0014createInstanceEPN4sead4HeapE = 0x003660DC;
_ZN3Lyt16CommonWindowA_0019getSelectedMenuItemEv = 0x00366144;
_ZN3Lyt16CommonWindowA_0013initTextBoxesEv = 0x003665FC;
_ZN3Lyt16CommonWindowA_0016setButtonKeybindENS0_9TextBoxIdEN4sead10Controller7PadFlagE = 0x003667DC;
_ZN3Lyt16CommonWindowA_0017setSelectedButtonENS0_9TextBoxIdE = 0x00366CC8;
_ZN3Lyt16CommonWindowA_004drawEv = 0x00366F1C;
_ZN3Lyt16CommonWindowA_006createEv = 0x00366FD4;
_ZN3Lyt16CommonWindowA_006updateEv = 0x003670C4;
_ZN3Lyt16CommonWindowA_009setLayoutENS0_10LayoutTypeEb = 0x00367184;
_ZN3Lyt16CommonWindowA_009setupAnimENS0_6AnimIdEb = 0x00367580;
_ZN3Lyt16CommonWindowA_0011setupButtonENS0_9TextBoxIdERKN4sead14SafeStringBaseIcEES6_jiz = 0x00367600;
_ZN3Lyt16CommonWindowA_0012drawInstanceEv = 0x0034FED0;

_ZN3Lyt16CommonWindowA_009sInstanceE = 0x005ED878;

/* Lyt::CommonWindowA_00::SingletonDisposer_ */
_ZTVN3Lyt16CommonWindowA_0018SingletonDisposer_E = 0x005BF310;
_ZN3Lyt16CommonWindowA_0018SingletonDisposer_D1Ev = 0x003666A0;
_ZN3Lyt16CommonWindowA_0018SingletonDisposer_15sStaticDisposerE = 0x005ED87C;

/* Lyt::ButtonRect */
_ZTVN3Lyt10ButtonRectE = 0x005C159C;
_ZN3Lyt10ButtonRectC1Ev = 0x0038BE74;
_ZN3Lyt10ButtonRectD1Ev = 0x0038BF70;

_ZN3Lyt10ButtonRect10StateID_OnE = 0x0062A364;
_ZN3Lyt10ButtonRect18initializeState_OnEv = 0x0038BAB8;
_ZN3Lyt10ButtonRect15executeState_OnEv = 0x0038B948;
_ZN3Lyt10ButtonRect16finalizeState_OnEv = 0x0038B96C;

_ZN3Lyt10ButtonRect12StateID_IdleE = 0x0062A388;
_ZN3Lyt10ButtonRect20initializeState_IdleEv = 0x0038BBBC;
_ZN3Lyt10ButtonRect17executeState_IdleEv = 0x0038B970;
_ZN3Lyt10ButtonRect18finalizeState_IdleEv = 0x0038BA64;

_ZN3Lyt10ButtonRect11StateID_OffE = 0x0062A3AC;
_ZN3Lyt10ButtonRect19initializeState_OffEv = 0x0038BB54;
_ZN3Lyt10ButtonRect16executeState_OffEv = 0x0038B958;
_ZN3Lyt10ButtonRect17finalizeState_OffEv = 0x0038B9E0;

_ZN3Lyt10ButtonRect14StateID_NormalE = 0x0062A3D0;
_ZN3Lyt10ButtonRect22initializeState_NormalEv = 0x0038BBD4;
_ZN3Lyt10ButtonRect19executeState_NormalEv = 0x0038B9DC;
_ZN3Lyt10ButtonRect20finalizeState_NormalEv = 0x0038BAB4;

_ZN3Lyt10ButtonRect14StateID_DecideE = 0x0062A3F4;
_ZN3Lyt10ButtonRect22initializeState_DecideEv = 0x0038BBEC;
_ZN3Lyt10ButtonRect19executeState_DecideEv = 0x0038BAD0;
_ZN3Lyt10ButtonRect20finalizeState_DecideEv = 0x0038BB6C;

_ZN3Lyt10ButtonRect16StateID_DisabledE = 0x0062A418;
_ZN3Lyt10ButtonRect24initializeState_DisabledEv = 0x0038B744;
_ZN3Lyt10ButtonRect21executeState_DisabledEv = 0x0038B944;
_ZN3Lyt10ButtonRect22finalizeState_DisabledEv = 0x0038B968;

_ZN3Lyt10ButtonRect9setVisualEjb = 0x0038B750;
_ZN3Lyt10ButtonRect5setupEPN3m2d13EmbedLayout_cEPN2nw3lyt13AnimTransformES7_S7_S7_S7_S7_S7_S7_S7_ = 0x0038B804;
_ZN3Lyt10ButtonRect11setNeighborEjPS0_ = 0x0038BA50;
_ZN3Lyt10ButtonRect11setButtonOnENS0_11CursorStateE = 0x0038BC04;
_ZN3Lyt10ButtonRect12setButtonOffENS0_11CursorStateE = 0x0038BC2C;
_ZN3Lyt10ButtonRect11setDisabledEbb = 0x0038BC94;
_ZN3Lyt10ButtonRect15setButtonNormalENS0_11CursorStateE = 0x0038BCE4;
_ZN3Lyt10ButtonRect16setLayoutContextERKNS0_13LayoutContextE = 0x0038BD18;
_ZN3Lyt10ButtonRect9isTouchedEv = 0x0038BD50;
_ZN3Lyt10ButtonRect15setButtonDecideENS0_11CursorStateE = 0x0038BDA8;
_ZN3Lyt10ButtonRect6updateEv = 0x0038BDD0;
_ZN3Lyt10ButtonRect7setAnimEjb = 0x0038BDD8;

/* Lyt::ButtonRect::LayoutContext */
_ZN3Lyt10ButtonRect13LayoutContextC1Ev = 0x0038BE60;

/* Lyt::ButtonMenu */
_ZTVN3Lyt10ButtonMenuE = 0x005C1570;
_ZN3Lyt10ButtonMenuC1Ev = 0x0038B61C;
_ZN3Lyt10ButtonMenuD1Ev = 0x0038B6F8;
_ZN3Lyt10ButtonMenuD0Ev = 0x0;

_ZN3Lyt10ButtonMenu18StateID_CheckInputE = 0x0062A310;
_ZN3Lyt10ButtonMenu26initializeState_CheckInputEv = 0x0038B0DC;
_ZN3Lyt10ButtonMenu23executeState_CheckInputEv = 0x0038AE44;
_ZN3Lyt10ButtonMenu24finalizeState_CheckInputEv = 0x0038B0D4;

_ZN3Lyt10ButtonMenu15StateID_DecidedE = 0x0062A334;
_ZN3Lyt10ButtonMenu23initializeState_DecidedEv = 0x0038B0E0;
_ZN3Lyt10ButtonMenu20executeState_DecidedEv = 0x0038B0B0;
_ZN3Lyt10ButtonMenu21finalizeState_DecidedEv = 0x0038B0D8;

_ZN3Lyt10ButtonMenu9isPadTrigEN4sead10Controller7PadFlagE = 0x0038A73C;
_ZN3Lyt10ButtonMenu18highlightSelectionEv = 0x0038A7D0;
_ZN3Lyt10ButtonMenu12processTouchEv = 0x0038A87C;
_ZN3Lyt10ButtonMenu17validateSelectionEv = 0x0038AA64;
_ZN3Lyt10ButtonMenu11setupButtonEPNS_10ButtonRectE = 0x0038AB60;
_ZN3Lyt10ButtonMenu22getSelectedButtonIndexEv = 0x0038ABB8;
_ZN3Lyt10ButtonMenu16handleNavigationEv = 0x0038ABCC;
_ZN3Lyt10ButtonMenu10sub_38AE30Ev = 0x0038AE30;
_ZN3Lyt10ButtonMenu21getFirstEnabledButtonEv = 0x0038AEB0;
_ZN3Lyt10ButtonMenu14processHotkeysEv = 0x0038AEF4;
_ZN3Lyt10ButtonMenu19selectDefaultButtonEv = 0x0038B13C;
_ZN3Lyt10ButtonMenu14clearSelectionEv = 0x0038B1DC;
_ZN3Lyt10ButtonMenu10initializeERKNS0_12LayoutConfigE = 0x0038B274;
_ZN3Lyt10ButtonMenu15onButtonPressedENS_10ButtonRect11CursorStateE = 0x0038B34C;
_ZN3Lyt10ButtonMenu6updateEv = 0x0038B438;
_ZN3Lyt10ButtonMenu9isPadHoldEN4sead10Controller7PadFlagE = 0x0038B540;
_ZN3Lyt10ButtonMenu12appendButtonEPNS_10ButtonRectE = 0x0047EF0C;

/* Lyt::ButtonMenu::LayoutConfig */
_ZN3Lyt10ButtonMenu12LayoutConfigC1Ev = 0x0038B5D4;

/* ListNode */
_ZTV8ListNode = 0x005D35FC;
_ZN8ListNodeC1Ev = 0x0010E8E4;
_ZN8ListNodeD1Ev = 0x0;
_ZN8ListNodeD0Ev = 0x0;

/* IntrusiveList */
_ZTV13IntrusiveList = 0x005D35EC;
_ZN13IntrusiveListC1Ev = 0x0010E8C8;
_ZN13IntrusiveListD1Ev = 0x0047EF70;
_ZN13IntrusiveListD0Ev = 0x0;
_ZN13IntrusiveList5clearEv = 0x0010E85C;
_ZN13IntrusiveList6removeEP8ListNode = 0x0010E88C;
_ZN13IntrusiveList8containsEP8ListNode = 0x0047EEDC;
_ZN13IntrusiveList6appendEP8ListNode = 0x0047EF2C;

/* Lyt::Dialog */
_ZTVN3Lyt6DialogE = 0x005C17A4;
_ZN3Lyt6DialogC1Ev = 0x0038F53C;
_ZN3Lyt6DialogD1Ev = 0x0038F57C;
_ZN3Lyt6DialogD0Ev = 0x0038F568;

_ZN3Lyt6Dialog11StateID_674E = 0x006226F8;
_ZN3Lyt6Dialog19initializeState_674Ev = 0x0038F490;
_ZN3Lyt6Dialog16executeState_674Ev = 0x0038F464;
_ZN3Lyt6Dialog17finalizeState_674Ev = 0x0038F480;

_ZN3Lyt6Dialog11StateID_675E = 0x0062271C;
_ZN3Lyt6Dialog19initializeState_675Ev = 0x0038F4AC;
_ZN3Lyt6Dialog16executeState_675Ev = 0x0038F4A0;
_ZN3Lyt6Dialog17finalizeState_675Ev = 0x0038F4A4;

_ZN3Lyt6Dialog11StateID_676E = 0x00622740;
_ZN3Lyt6Dialog19initializeState_676Ev = 0x0038F4B4;
_ZN3Lyt6Dialog16executeState_676Ev = 0x0038F4A8;
_ZN3Lyt6Dialog17finalizeState_676Ev = 0x0038F4B0;

_ZN3Lyt6Dialog16createDialogHeapERKN4sead14SafeStringBaseIcEEj = 0x0038F2F4;
_ZN3Lyt6Dialog11changeStateERK7StateID = 0x0038F358;
_ZN3Lyt6Dialog4vf40Ev = 0x004A5CB8;

/* Lyt::LayoutResLoader */
_ZTVN3Lyt15LayoutResLoaderE = 0x005C163C;
_ZN3Lyt15LayoutResLoader3vf0Ev = 0x0;
_ZN3Lyt15LayoutResLoaderD1Ev = 0x0038CB44;
_ZN3Lyt15LayoutResLoaderD0Ev = 0x0;

_ZN3Lyt15LayoutResLoader9sInstanceE = 0x005EF768;
_ZN3Lyt15LayoutResLoader14createInstanceEPN4sead4HeapE = 0x0038C950;

/* Lyt::LayoutResLoader::SingletonDisposer_ */
_ZTVN3Lyt15LayoutResLoader18SingletonDisposer_E = 0x005C162C;
_ZN3Lyt15LayoutResLoader18SingletonDisposer_15sStaticDisposerE = 0x005EF76C;
_ZN3Lyt15LayoutResLoader18SingletonDisposer_D1Ev = 0x0038C9E4;

/* Lyt::LayoutResMgr */
_ZTVN3Lyt12LayoutResMgrE = 0x005C1608;
_ZN3Lyt12LayoutResMgr9sInstanceE = 0x005EF7C8;
_ZN3Lyt17LayoutResAccessor3vf0Ev = 0x0;
_ZN3Lyt12LayoutResMgrD1Ev = 0x0038C924;
_ZN3Lyt12LayoutResMgrD0Ev = 0x0;
_ZN3Lyt12LayoutResMgr10initializeEj = 0x0038BFE4;
_ZN3Lyt12LayoutResMgr11getResourceERKN4sead14SafeStringBaseIcEE = 0x0038C154;
_ZN3Lyt12LayoutResMgr12loadResourceERKN4sead14SafeStringBaseIcEE = 0x0038C1C0;
_ZN3Lyt12LayoutResMgr14createInstanceEPN4sead4HeapE = 0x0038C41C;
_ZN3Lyt12LayoutResMgr14unloadResourceERKN4sead14SafeStringBaseIcEE = 0x0038C490;
_ZN3Lyt12LayoutResMgr8getEntryERKN4sead14SafeStringBaseIcEE = 0x0038C674;
_ZN3Lyt12LayoutResMgr6insertERKN4sead14SafeStringBaseIcEE = 0x0038C758;

/* Lyt::LayoutResource */
_ZTVN3Lyt14LayoutResourceE = 0x005C161C;
_ZN3Lyt14LayoutResourceC1Ev = 0x0038C928;
_ZN3Lyt14LayoutResourceD1Ev = 0x0;
_ZN3Lyt14LayoutResourceD0Ev = 0x0038C940;

/* Lyt::LayoutResMgr::Entry */
_ZN3Lyt12LayoutResMgr5EntryC1Ev = 0x0038C168;

/* Lyt::LayoutResMgr::SingletonDisposer_ */
_ZTVN3Lyt12LayoutResMgr18SingletonDisposer_E = 0x005C15F8;
_ZN3Lyt12LayoutResMgr18SingletonDisposer_15sStaticDisposerE = 0x005EF7CC;
_ZN3Lyt12LayoutResMgr18SingletonDisposer_D1Ev = 0x0038C8D4;

/* FontMgr */
_ZN7FontMgr9sInstanceE = 0x005EFAE0;

/* UnkControllerInfo */
_ZN19UnkControllerInfo7player1E = 0x0069E7B0;

/* Angle */
_ZNK5Angle10getTangentEv = 0x004A6278;
