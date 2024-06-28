#include "SpeedDown.h"
#include "ValueManager.h"

SpeedDown::SpeedDown(GameObject* parent)
    : ItemBase(parent), GameObject(parent, "SpeedDown"), hSpeed_(-1)
{
}

SpeedDown::~SpeedDown()
{
    delete pStage_;
}

void SpeedDown::Initialize()
{
    // モデルデータのロード
    hModel_ = Model::Load("Model/SpeedDown.fbx");
    assert(hModel_ >= 0);

    //インスタンスを作成
    pStage_ = new Stage(this);
}

void SpeedDown::Update()
{
}

void SpeedDown::Release()
{
    if (pStage_) {
        pStage_->Release();
        delete pStage_;
        pStage_ = nullptr;
    }
}

void SpeedDown::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Player") {
        if (pStage_) {
            //pStage_->;
        }
    }
}
