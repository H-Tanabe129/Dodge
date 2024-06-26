#include "StageUp.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

StageUp::StageUp(GameObject* parent)
    :GameObject(parent, "StageUp"), hModel_(-1)
{
}

StageUp::~StageUp()
{
}

void StageUp::Initialize()
{
    transform_.position_ = XMFLOAT3(trPosiX, trPosiY, trPosiZ);

    //モデルデータのロード
    hModel_ = Model::Load("Model/Stage.fbx");
    assert(hModel_ >= 0);

    BoxCollider* collision =
        new BoxCollider(XMFLOAT3(BCollPosiX, BCollPosiY, BCollPosiZ),
            XMFLOAT3(BCollSizeX, BCollSizeY, BCollSizeZ));
    AddCollider(collision);
}

void StageUp::Update()
{
    if (transform_.position_.x <= LEdge) {
        this->KillMe();
    }
}

void StageUp::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void StageUp::Release()
{
}