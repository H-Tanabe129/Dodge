#include "Stage.h"
#include "Engine/Model.h"

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
    hModel_ = Model::Load("Model/Stage_1.fbx");
    assert(hModel_ >= 0);
    transform_.position_ = XMFLOAT3(10, -5, 0);
}

void Stage::Update()
{
}

void Stage::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Stage::Release()
{
}
