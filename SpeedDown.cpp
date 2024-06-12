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
    transform_.position_.x = trPosiX;

    //モデルデータのロード
    hSpeed_ = Model::Load("Model/SpeedDown.fbx");
    assert(hSpeed_ >= 0);

    BoxCollider* collision = new BoxCollider
    (XMFLOAT3(BColliderPosiX, BColliderPosiY, BColliderPosiZ), 
        XMFLOAT3(BColliderSizeX, BColliderSizeY, BColliderSizeZ));
    AddCollider(collision);

    srand((unsigned int)time(nullptr));
}

void SpeedDown::Update()
{
    transform_.position_.x -= trPosiChangeX;
    trPosiY = GenerateRand();

    if (transform_.position_.x <= LEdge) {
        this->KillMe();
    }
}

int SpeedDown::GenerateRand()
{
    geneRand = (rand() % (max - min + 1) + min) / flo;
    return geneRand;
}

void SpeedDown::Draw()
{
    Model::SetTransform(hSpeed_, transform_);
    Model::Draw(hSpeed_);
}

void SpeedDown::Release()
{
}

//何かに当たった
void SpeedDown::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "StageUp" || "StageLo")
    {
        this->KillMe();
    }
}