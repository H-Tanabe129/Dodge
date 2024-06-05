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
    transform_.position_ = XMFLOAT3(trPosiX, trPosiY, trPosiZ);

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
    transform_.position_.x -= trPosiChangeX;
    trPosiY = GenerateRand();

    if (transform_.position_.x <= LEdge) {
        this->KillMe();
    }
}

float JumpUp::GenerateRand()
{
    geneRand = (rand() % (max - min + 1) + min) / flo;
    return geneRand;
}

void JumpUp::Draw()
{
    Model::SetTransform(hJump_, transform_);
    Model::Draw(hJump_);
}

void JumpUp::Release()
{
}