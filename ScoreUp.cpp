#include "ScoreUp.h"
#include "ValueManager.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

ScoreUp::ScoreUp(GameObject* parent)
    :GameObject(parent, "ScoreUp"), hScore_(-1)
{
}

ScoreUp::~ScoreUp()
{
}

void ScoreUp::Initialize()
{
    transform_.position_ = XMFLOAT3(trPosiX, trPosiY, trPosiZ);

    //モデルデータのロード
    hScore_ = Model::Load("Model/ScoreUp.fbx");
    assert(hScore_ >= 0);

    BoxCollider* collision = new BoxCollider
        (XMFLOAT3(BColliderPosiX, BColliderPosiY, BColliderPosiZ),
            XMFLOAT3(BColliderSizeX, BColliderSizeY, BColliderSizeZ));
    AddCollider(collision);

    srand((unsigned int)time(nullptr));
}

void ScoreUp::Update()
{
    transform_.position_.x -= trPosiChangeX;
    trPosiY = GenerateRand();

    if (transform_.position_.x <= LEdge) {
        this->KillMe();
    }
}

float ScoreUp::GenerateRand()
{
    geneRand = (rand() % (max - min + 1) + min) / flo;
    return geneRand;
}

void ScoreUp::Draw()
{
    Model::SetTransform(hScore_, transform_);
    Model::Draw(hScore_);
}

void ScoreUp::Release()
{
}

void ScoreUp::OnCollision(GameObject* pTarget) {
    if (pTarget->GetObjectName() == "Player") {
        ValueManager::GetInstance().ItemScore();
    }
}
