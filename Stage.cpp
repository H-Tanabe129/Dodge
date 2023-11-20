#include "Stage.h"
#include "Engine/Model.h"

Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModelU_(-1), hModelL_(-1)
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
    //モデルデータのロード
    //hModelU_ = Model::Load("Model/Stage_1.fbx");
    //assert(hModelU_ >= 0);
    hModelL_ = Model::Load("Model/Stage_1.fbx");
    assert(hModelL_ >= 0);
    //StaUpper.position_ = XMFLOAT3(20, 15, 0);
    StaLower.position_ = XMFLOAT3(20, -5, 0);
}

void Stage::Update()
{
    transform_.position_.x -= 0.1f;
}

void Stage::Draw()
{
    //Model::SetTransform(hModelU_, StaUpper);
    //Model::Draw(hModelU_);
    Model::SetTransform(hModelL_, StaLower);
    Model::Draw(hModelL_);
}

void Stage::Release()
{
}
