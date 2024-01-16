#include "Abyss.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

Abyss::Abyss(GameObject* parent)
    :GameObject(parent, "Abyss"), hModel_(-1)
{
}

Abyss::~Abyss()
{
}

void Abyss::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Model/Stage.fbx");
    assert(hModel_ >= 0);

    transform_.position_ = XMFLOAT3(0, 14, 0);
    transform_.rotate_.z = 90;
    transform_.scale_ = XMFLOAT3(1.0f, 1.0f, 1.0f);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(10, 2, 1));
    AddCollider(collision);
}

void Abyss::Update()
{
}

void Abyss::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Abyss::Release()
{
}
