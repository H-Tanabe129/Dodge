#include "Ceiling.h"
#include "Engine/Model.h"

Ceiling::Ceiling(GameObject* parent)
    :GameObject(parent, "Ceiling"), hModel_(-1)
{
}

Ceiling::~Ceiling()
{
}

void Ceiling::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Model/Stage.fbx");
    assert(hModel_ >= 0);

    transform_.position_ = XMFLOAT3(10, -14, 0);
    transform_.rotate_.z = 90;
    transform_.scale_ = XMFLOAT3(2.5f, 1.0f, 1.0f);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(20, 2, 1));
    AddCollider(collision);
}

void Ceiling::Update()
{
}

void Ceiling::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Ceiling::Release()
{
}
