#pragma once

#include "sys/Allocator.h"
#include "gfx/AnimModel.h"
#include "sys/ResourceMgr.h"


template <u32 TNumModels, u8 TNumModelTypes>
class ModelMgr
{
public:
    HeapAllocator allocator;

    AnimModelBase* models[TNumModelTypes][TNumModels];
    bool usedIndices[TNumModels];

    u32 numModels;
    u8 numModelTypes;
    u32 numModelsCreated;


    ModelMgr()
    {
        this->numModels = TNumModels;
        this->numModelTypes = TNumModelTypes;

        numModelsCreated = 0;

        for (u8 i = 0; i < TNumModelTypes; i++)
        {
            for (u32 j = 0; j < TNumModels; j++)
            {
                models[i][j] = nullptr;
                usedIndices[j] = false;
            }
        }
    }

    virtual ~ModelMgr()
    {
        freeModels();
    }

    virtual bool createModels() = 0;

    void freeModels()
    {
        for (u8 i = 0; i < TNumModelTypes; i++)
        {
            for (u32 j = 0; j < TNumModels; j++)
            {
                AnimModelBase* model = models[i][j];
                if (model)
                {
                    model->cleanup();
                    delete model;
                }
                models[i][j] = nullptr;
            }
        }
    }

    s32 getFreeIdx()
    {
        for (u32 i = 0; i < numModels; i++)
        {
            if (usedIndices[i] == false)
                return i;
        }

        return -1;
    }

    bool acquireIdx(s32 idx)
    {
        if (usedIndices[idx])
            return false;

        usedIndices[idx] = true;
        return true;
    }

    void freeIdx(s32 idx)
    {
        usedIndices[idx] = false;
    }

    AnimModelBase* getModel(u8 type, s32 idx)
    {
        return models[type][idx];
    }
};
