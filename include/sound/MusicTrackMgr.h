#pragma once

#include "sead.h"

// size: 0x76C
class MusicTrackMgr : public sead::IDisposer
{
public:
    static MusicTrackMgr* instance;

    void setTrackVolume(u32 trackBitFlag, f32 volume, u32 frames = 0);
    void setVolumeOfAllHandles(f32 volume, s32 frames);
    void setPitchOfAllHandles(f32 pitch);

    void playStream(u32 soundID, u32 fadeFrames);
    void playTrackById(u32 soundId, u32 fadeFrames);
    void stopOverrides(s32 fadeFrames);
    void stopOverride(s32 overrideId, s32 fadeFrames);
    void stopMusicStreams(s32 fadeFrames);
    void stopAll(s32 fadeFrames);
    void reset();

    /* 0x10 */  u8 _10[52];
    /* 0x44 */  u32 samplesPerBeat;
    /* 0x48 */  u8 _48[8];
    /* 0x50 */  u32 prevChordNotes;
    /* 0x54 */  u32 chordNotes;
    /* 0x58 */  s8 prevChordRoot;
    /* 0x59 */  s8 chordRoot;

};
