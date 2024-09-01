#include "ScoreUp.h"
#include "ValueManager.h"
#include "Engine/Model.h"
#include "Engine/Audio.h"
#include "Engine/BoxCollider.h"
#include "Engine/SphereCollider.h"

ScoreUp::ScoreUp(GameObject* parent)
    :GameObject(parent, "ScoreUp"), hScore_(-1), hSound_(-1)
{
}

ScoreUp::~ScoreUp()
{
}

void ScoreUp::Initialize()
{
    transform_.position_.x = scoreUpPosX;

    //サウンドデータのロード
    hSound_ = Audio::Load("A1_18287.WAV");
    assert(hSound_ >= 0);

    //モデルデータのロード
    hScore_ = Model::Load("Model/ScoreUp.fbx");
    assert(hScore_ >= 0);

    SphereCollider* collision = 
        new SphereCollider(XMFLOAT3(sphCollPosX, sphCollPosY, sphCollPosZ), sphCollSizeX);
    AddCollider(collision);
}

void ScoreUp::Update()
{
    transform_.position_.x -= trPosiChangeX;
    transform_.rotate_.y += trRoteChangeY;

    if (transform_.position_.x <= WORLD_EDGE) {
        this->KillMe();
    }
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
    //プレイヤーに当たったら
    if (pTarget->GetObjectName() == "Player") {
        ValueManager::GetInstance().ItemScore();
        this->KillMe();
        Audio::Play(hSound_);
    }
    //上の壁に当たったら
    if (pTarget->GetObjectName() == "StageUp") {
        this->KillMe();
    }
    //下の壁に当たったら
    if (pTarget->GetObjectName() == "StageLo") {
        this->KillMe();
    }
}
