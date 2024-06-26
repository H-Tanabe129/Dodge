#include "SpeedDown.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

SpeedDown::SpeedDown(GameObject* parent)
    :GameObject(parent, "SpeedDown"), hSpeed_(-1)
{
}

SpeedDown::~SpeedDown()
{
    delete pStage_;
}

void SpeedDown::Initialize()
{
    transform_.position_.x = trPosiX;

    //モデルデータのロード
    hSpeed_ = Model::Load("Model/SpeedDown.fbx");
    assert(hSpeed_ >= 0);

    BoxCollider* collision = new BoxCollider
    (XMFLOAT3(BCollPosiX, BCollPosiY, BCollPosiZ), 
        XMFLOAT3(BCollSizeX, BCollSizeY, BCollSizeZ));
    AddCollider(collision);

    //インスタンスを作成
    pStage_ = new Stage(this);
}

void SpeedDown::Update()
{
    transform_.position_.x -= trPosiChangeX;
    transform_.rotate_.y += trRoteChangeY;

    if (transform_.position_.x <= LEdge) {
        this->KillMe();
    }
}

void SpeedDown::Draw()
{
    Model::SetTransform(hSpeed_, transform_);
    Model::Draw(hSpeed_);
}

void SpeedDown::Release()
{
    if (pStage_) {
        pStage_->Release();
        delete pStage_;
        pStage_ = nullptr;
    }
}

//何かに当たった
void SpeedDown::OnCollision(GameObject* pTarget) {
    if (pTarget->GetObjectName() == "Player") {
        if (pStage_) {
            pStage_->;
        }
    }
        this->KillMe();
    }
}

    if (pTarget->GetObjectName() == "StageUp") {
        this->KillMe();
    }
    if (pTarget->GetObjectName() == "StageLo") {
        this->KillMe();
    }
}