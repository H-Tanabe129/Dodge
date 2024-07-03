#include "StageLo.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

StageLo::StageLo(GameObject* parent)
    :GameObject(parent, "StageLo"), hModel_(-1)
{
}

StageLo::~StageLo()
{
}

void StageLo::Initialize()
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

void StageLo::Update()
{
    transform_.position_.x -= trPosiChangeX;
    if (transform_.position_.x <= LEdge) {
        this->KillMe();
    }
}

void StageLo::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void StageLo::Release()
{
}

void StageLo::SpeedChange()
{
    transform_.position_.x -= spChangeX;
}
