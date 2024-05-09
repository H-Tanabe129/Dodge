#include "ScoreUp.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

ScoreUp::ScoreUp(GameObject* parent)
    :GameObject(parent, "Item"), hScore_(-1)
{
}

ScoreUp::~ScoreUp()
{
}

void ScoreUp::Initialize()
{
    //モデルデータのロード
    hScore_ = Model::Load("Model/ScoreUp.fbx");
    assert(hScore_ >= 0);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
    AddCollider(collision);
}

void ScoreUp::Update()
{
}

void ScoreUp::Draw()
{
    Model::SetTransform(hScore_, transform_);
    Model::Draw(hScore_);
}

void ScoreUp::Release()
{
}
