#include "StageUp.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

StageUp::StageUp(GameObject* parent)
    :GameObject(parent, "StageUp"), hStageUp_(-1)
{
}

StageUp::~StageUp()
{
}

void StageUp::Initialize()
{
    transform_.position_ = XMFLOAT3(trPosiX, trPosiY, trPosiZ);
    transform_.scale_ = XMFLOAT3(trSizeX, trSizeY, trSizeZ);

    //モデルデータのロード
      hStageUp_ = Model::Load("Model/Stage_tr.fbx");
    assert(hStageUp_ >= 0);

    BoxCollider* collision =
        new BoxCollider(XMFLOAT3(boxCollPosX, boxCollPosY, boxCollPosZ),
            XMFLOAT3(boxCollSizeX, boxCollSizeY, boxCollSizeZ));
    AddCollider(collision);
}

void StageUp::Update()
{
    transform_.position_.x -= posChangeX;
    if (transform_.position_.x <= WORLD_EDGE) {
        this->KillMe();
    }
}

void StageUp::Draw()
{
    Model::SetTransform(hStageUp_, transform_);
    Model::Draw(hStageUp_);
}

void StageUp::Release()
{
}