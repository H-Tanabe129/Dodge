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
    //モデルデータのロード
    hJump_ = Model::Load("Model/JumpUp.fbx");
    assert(hJump_ >= 0);

    BoxCollider* collision = new BoxCollider
    (XMFLOAT3(BColliderPosiX, BColliderPosiY, BColliderPosiZ), 
        XMFLOAT3(BColliderSizeX, BColliderSizeY, BColliderSizeZ));
    AddCollider(collision);

    srand((unsigned int)time(nullptr));
}

void JumpUp::Update()
{
}

void JumpUp::Draw()
{
    Model::SetTransform(hJump_, transform_);
    Model::Draw(hJump_);
}

void JumpUp::Release()
{
}