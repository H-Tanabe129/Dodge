#include "StageUp.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

StageUp::StageUp(GameObject* parent)
    :GameObject(parent, "StageUp"), hModel_(-1)
{
}

StageUp::~StageUp()
{
}

void StageUp::Initialize()
{
    transform_.position_ = XMFLOAT3(35, 7.0f, 0);

    //モデルデータのロード
    hModel_ = Model::Load("Model/Stage.fbx");
    assert(hModel_ >= 0);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(-0.1f, 0, 0), XMFLOAT3(1,4, 1));
    AddCollider(collision);
}

void StageUp::Update()
{
    transform_.position_.x -= 0.1f;

    if (transform_.position_.x <= -10) {
        this->KillMe();
    }
}

void StageUp::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void StageUp::Release()
{
}