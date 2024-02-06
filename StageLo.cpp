#include "StageLo.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

StageLo::StageLo(GameObject* parent)
    :GameObject(parent, "StageLo"), hModel_(-1)
{
}

StageLo::~StageLo()
{
}

void StageLo::Initialize()
{
    transform_.position_ = XMFLOAT3(35, -6.0f, 0);

    //モデルデータのロード
    hModel_ = Model::Load("Model/Stage.fbx");
    assert(hModel_ >= 0);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0.1f, 0, 0), XMFLOAT3(1, 4, 1));
    AddCollider(collision);
}

void StageLo::Update()
{
    /*transform_.position_.x -= 0.1f;

    if (transform_.position_.x == -10) {
        KillMe();
    }*/
}

void StageLo::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void StageLo::Release()
{
}