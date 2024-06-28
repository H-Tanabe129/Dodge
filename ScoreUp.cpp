#include "ScoreUp.h"
#include "ValueManager.h"

ScoreUp::ScoreUp(GameObject* parent)
    : ItemBase(parent), hScore_(-1)
{
}

ScoreUp::~ScoreUp()
{
}

void ScoreUp::Initialize()
{
    // モデルデータのロード
    hModel_ = Model::Load("Model/ScoreUp.fbx");
    assert(hModel_ >= 0);
}

void ScoreUp::Update()
{
}

void ScoreUp::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Player") {
        ValueManager::GetInstance().ItemScore();
    }
}
