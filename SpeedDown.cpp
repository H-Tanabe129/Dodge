#include "SpeedDown.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

SpeedDown::SpeedDown(GameObject* parent)
    :GameObject(parent, "SpeedDown"), hSpeed_(-1)
{
}

SpeedDown::~SpeedDown()
{
}

void SpeedDown::Initialize()
{
    //モデルデータのロード
    hSpeed_ = Model::Load("Model/SpeedDown.fbx");
    assert(hSpeed_ >= 0);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
    AddCollider(collision);
}

void SpeedDown::Update()
{
}

void SpeedDown::Draw()
{
    Model::SetTransform(hSpeed_, transform_);
    Model::Draw(hSpeed_);
}

void SpeedDown::Release()
{
}
