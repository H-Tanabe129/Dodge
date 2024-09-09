#include "StageLoMore.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

StageLoMore::StageLoMore(GameObject* parent)
    :GameObject(parent, "StageLoMore"), hStageLoMore_(-1)
{
}

StageLoMore::~StageLoMore()
{
}

void StageLoMore::Initialize()
{
    transform_.position_ = XMFLOAT3(trPosiX, trPosiY, trPosiZ);
    transform_.scale_ = XMFLOAT3(trSizeX, trSizeY, trSizeZ);

    //モデルデータのロード
    hStageLoMore_ = Model::Load("Model/Stage_up.fbx");
    assert(hStageLoMore_ >= 0);

    BoxCollider* collision =
        new BoxCollider(XMFLOAT3(boxCollPosX, boxCollPosY, boxCollPosZ),
            XMFLOAT3(boxCollSizeX, boxCollSizeY, boxCollSizeZ));
    AddCollider(collision);
}

void StageLoMore::Update()
{
    transform_.position_.x -= posChangeX;
    if (transform_.position_.x <= WORLD_EDGE) {
        this->KillMe();
    }
}

void StageLoMore::Draw()
{
    Model::SetTransform(hStageLoMore_, transform_);
    Model::Draw(hStageLoMore_);
}

void StageLoMore::Release()
{
}