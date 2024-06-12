#include "JumpUp.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

JumpUp::JumpUp(GameObject* parent)
    :GameObject(parent, "JumpUp"), hJump_(-1)
{
}

JumpUp::~JumpUp()
{
}

void JumpUp::Initialize()
{
    transform_.position_.x = trPosiX;

    //モデルデータのロード
    hJump_ = Model::Load("Model/JumpUp.fbx");
    assert(hJump_ >= 0);

    BoxCollider* collision = new BoxCollider
    (XMFLOAT3(BColliderPosiX, BColliderPosiY, BColliderPosiZ), 
        XMFLOAT3(BColliderSizeX, BColliderSizeY, BColliderSizeZ));
    AddCollider(collision);
}

void JumpUp::Update()
{
    transform_.position_.x -= trPosiChangeX;

    if (transform_.position_.x <= LEdge) {
        this->KillMe();
    }
}

void JumpUp::Draw()
{
    Model::SetTransform(hJump_, transform_);
    Model::Draw(hJump_);
}

void JumpUp::Release()
{
}

//何かに当たった
void JumpUp::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "StageUp" || "StageLo")
    {
        this->KillMe();
    }
}