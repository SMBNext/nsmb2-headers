#pragma once

#include "sead.h"
#include "gfx/M2d.h"
#include "state/FStateMgr.h"

class FaderBase
{
public:
    void* vtable;
    FStateMgr<FaderBase> stateMgr;
    u8 _28[4];
    m2d::EmbedLayout_c embedLyt;
    m2d::Anm_c anims[2];
    nw::lyt::Group* groupPtr;
    nw::lyt::Pane* panePtr;
    Vec3f _140;
    f32 frameStep;
};

size_assert(FaderBase, 0x1B0);


class FaderTypeA : public FaderBase
{
public:
    m2d::Anm_c anims2[2];
    u8 _200;
};

size_assert(FaderTypeA, 0x204);


class Faderunk_437BC4
{
public:
    void* vtable;
    u8 _4;
    u8 _5;
};

size_assert(Faderunk_437BC4, 0x08);


class Faderunk_235D3C : public Faderunk_437BC4
{
public:
    FaderTypeA* faderLyt;
};

size_assert(Faderunk_235D3C, 0xC);


class Faderunk_437DC4 : public Faderunk_235D3C
{
public:
};

size_assert(Faderunk_437DC4, 0xC);

