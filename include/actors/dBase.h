#pragma once

#include "fBase.h"

class dBase : public fBase      // size: 0x14
{
public:
    dBase();
    virtual ~dBase();

    int beforeCreate() override;
    void afterCreate(int) override;
    int beforeDelete() override;
    void afterDelete(int) override;
    int beforeExecute() override;
    void afterExecute(int) override;
    int beforeDraw() override;
    void afterDraw(int) override;

    virtual void vf3C();        // deleted
};
