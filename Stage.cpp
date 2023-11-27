#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1)
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Model/Stage.fbx");
    assert(hModel_ >= 0);
    StaUpper.position_ = XMFLOAT3(20, 6.8f, 0);
    StaLower.position_ = XMFLOAT3(20, -5.7f, 0);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 12, 1));
    AddCollider(collision);
}

void Stage::Update()
{
    StaUpper.position_.x -= 0.1f;
    StaLower.position_.x -= 0.1f;
}

void Stage::Draw()
{
    Model::SetTransform(hModel_, StaUpper);
    Model::Draw(hModel_);
    Model::SetTransform(hModel_, StaLower);
    Model::Draw(hModel_);
}

void Stage::Release()
{
}
