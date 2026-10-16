#pragma once

#include "sys/Allocator.h"
#include "gfx/AnimModel.h"
#include "gfx/Light.h"
#include "sys/ResourceMgr.h"

/// @brief  A base class for singletons that pre-allocate and dispense models.
/// @tparam TNumModels      The number of models to create for each model type.
/// @tparam TNumModelTypes  The number of different model types.
/// @tparam TAcquireAll     If set, actors have to acquire all models at once. Useful for models that must be used together.
template <u32 TNumModels, u8 TNumModelTypes, bool TAcquireAll>
class ModelMgr
{
public:
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
                usedIndices[i][j] = false;
            }
        }
    }

    virtual ~ModelMgr()
    {
        destroyModels();
    }

    virtual bool createModels() = 0;

    void destroyModels()
    {
        for (u8 i = 0; i < TNumModelTypes; i++)
        {
            for (u32 j = 0; j < TNumModels; j++)
            {
                Model* model = models[i][j];
                if (model)
                {
                    model->cleanup();
                    delete model;
                }
                models[i][j] = nullptr;
            }
        }
    }

    void applyEnvLight()
    {
        for (u8 i = 0; i < TNumModelTypes; i++)
        {
            for (u32 j = 0; j < TNumModels; j++)
            {
                Model* model = models[i][j];
                if (!model)
                    continue;

                nw::gfx::Model* gfxModel = model->getGfxWrapper()->getModel();
                if (gfxModel)
                    LightMgr::instance()->applyEnvColorToModel(gfxModel);
            }
        }
    }

    s32 acquireModelIdx(u8 type)
    {
        if (type >= numModelTypes)
            return -1;

        if (TAcquireAll)
            type = 0;

        for (u32 i = 0; i < numModelsCreated; i++)
        {
            if (usedIndices[type][i] == false)
            {
                usedIndices[type][i] = true;
                return i;
            }
        }

        return -1;
    }

    s32 acquireModelIdx()
    {
        static_assert(TAcquireAll, "acquireModelIdx() requires TAcquireAll = true");
        return acquireModelIdx(0);
    }

    void freeModelIdx(s32 idx, u8 type)
    {
        if (TAcquireAll)
            type = 0;

        usedIndices[type][idx] = false;
    }

    void freeModelIdx(s32 idx)
    {
        static_assert(TAcquireAll, "freeModelIdx(s32 idx) requires TAcquireAll = true");
        freeModelIdx(idx, 0);
    }

    Model* getModel(s32 idx, u8 type)
    {
        const u8 usedType = TAcquireAll ? 0 : type;

        if (usedIndices[usedType][idx] == false)
            return nullptr;

        return models[type][idx];
    }

    Model* getModel(s32 idx)
    {
        static_assert(TNumModelTypes == 1, "getModel(s32 idx) requires TNumModelTypes == 1");
        return getAnimModel(idx, 0);
    }

    AnimModelBase* getAnimModel(s32 idx, u8 type)
    {
        return static_cast<AnimModelBase*>(getModel(idx, type));
    }

    AnimModelBase* getAnimModel(s32 idx)
    {
        static_assert(TNumModelTypes == 1, "getAnimModel(s32 idx) requires TNumModelTypes == 1");
        return static_cast<AnimModelBase*>(getModel(idx, 0));
    }

protected:
    HeapAllocator allocator;

    Model* models[TNumModelTypes][TNumModels];
    bool usedIndices[TNumModelTypes][TNumModels];

    u32 numModels;
    u8 numModelTypes;
    u32 numModelsCreated;
};
