#include "StageLo.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

StageLo::StageLo(GameObject* parent)
    :GameObject(parent, "StageLo"), hStageLo_(-1)
{
}

StageLo::~StageLo()
{
}

void StageLo::Initialize()
{
    transform_.position_ = XMFLOAT3(loPosX, loPosY, loPosZ);
    transform_.scale_ = XMFLOAT3(loSizeX, loSizeY, loSizeZ);
     
    //モデルデータのロード
    hStageLo_ = Model::Load("Model/Stage_tr.fbx");
    assert(hStageLo_ >= 0);

    BoxCollider* collision =
        new BoxCollider(XMFLOAT3(boxCollPosX, boxCollPosY, boxCollPosZ),
            XMFLOAT3(boxCollSizeX, boxCollSizeY, boxCollSizeZ));
    AddCollider(collision);
}

void StageLo::Update()
{
    transform_.position_.x -= posChangeX;
    if (transform_.position_.x <= WORLD_EDGE) {
        this->KillMe();
    }
}

void StageLo::Draw()
{
    Model::SetTransform(hStageLo_, transform_);
    Model::Draw(hStageLo_);
}

void StageLo::Release()
{
}