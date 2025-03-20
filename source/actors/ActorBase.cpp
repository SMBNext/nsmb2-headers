#include "actors/ActorBase.h"

#include "gfx/AnimModel.h"

void ActorBase::updateModelMatrixWithOffset(Model* model)
{
    if (!model)
        return;

    Mtx34 mtx, offsetMtx;

    mtx.identity();
    mtx.translate(position.x, position.y, position.z);
    mtx.rotateY(rotation.y);
    
    offsetMtx.identity();
    offsetMtx.translateY(centerOffset.y);
    Mtx34::multiply(&mtx, mtx, offsetMtx);

    mtx.rotateX(rotation.x);

    offsetMtx.identity();
    offsetMtx.translateY(-centerOffset.y);
    Mtx34::multiply(&mtx, mtx, offsetMtx);

    mtx.rotateZ(rotation.z);

    model->setScale(scale);
    model->setDrawMatrix(&mtx);
    model->update();
}

void ActorBase::updateModelMatrixWithOffset(AnimModelBase* model)
{
    if (!model)
        return;

    model->updateAnimation();
    updateModelMatrixWithOffset(static_cast<Model*>(model));
}


void ActorBase::updateModelMatrix(Model* model)
{
    if (!model)
        return;

    Mtx34 mtx;
    mtx.setRotationAndTranslation(rotation, position);
    
    model->setScale(scale);
    model->setDrawMatrix(&mtx);
    model->update();
}

void ActorBase::updateModelMatrix(AnimModelBase* model)
{
    if (!model)
        return;

    model->updateAnimation();
    updateModelMatrix(static_cast<Model*>(model));
}
