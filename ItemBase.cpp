#include "ItemBase.h"

ItemBase::ItemBase(GameObject* parent)
    :GameObject(parent, "ItemBase"), hModel_(-1), hSound_(-1)
{
}

ItemBase::~ItemBase()
{
}

void ItemBase::Initialize()
{
    transform_.position_.x = trPosiX;

    //サウンドデータのロード
    hSound_ = Audio::Load("A1_18278.WAV");
    assert(hSound_ >= 0);

    BoxCollider* collision = new BoxCollider
    (XMFLOAT3(BCollPosiX, BCollPosiY, BCollPosiZ),
        XMFLOAT3(BCollSizeX, BCollSizeY, BCollSizeZ));
    AddCollider(collision);
}

void ItemBase::Update()
{
    transform_.position_.x -= trPosiChangeX;
    transform_.rotate_.y += trRoteChangeY;

    if (transform_.position_.x <= LEdge) {
        this->KillMe();
    }
}

void ItemBase::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void ItemBase::Release()
{
}

void ItemBase::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Player") {
        this->KillMe();
        Audio::Play(hSound_);
    }

    if (pTarget->GetObjectName() == "StageUp") {
        this->KillMe();
    }
    if (pTarget->GetObjectName() == "StageLo") {
        this->KillMe();
    }
}

void ItemBase::SetPosition(int x, int y, int z)
{
    transform_.position_ = XMFLOAT3(x, y, z);
}
