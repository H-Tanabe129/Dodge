#include "Item.h"
#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

Item::Item(GameObject* parent)
	:GameObject(parent, "Item"), hSpeed_(-1), hJump_(-1), hScore_(-1)
{
}

Item::~Item()
{
}

void Item::Initialize()
{
    //モデルデータのロード
    hSpeed_ = Model::Load("Model/SpeedDown.fbx");
    assert(hSpeed_ >= 0);
    hJump_ = Model::Load("Model/JumpUp.fbx");
    assert(hJump_ >= 0);
    hScore_ = Model::Load("Model/ScoreUp.fbx");
    assert(hScore_ >= 0);

    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
    AddCollider(collision);

    srand((unsigned int)time(nullptr));
}

void Item::Update()
{
   /* frame += 1;
    if (frame % (FPS * 5) == 0)
    {
        rd = rand() % 100;
        switch (rd) {
        case 1:

        }
    }*/
}

void Item::Draw()
{
    Model::SetTransform(hSpeed_, transform_);
    Model::Draw(hSpeed_);
    Model::SetTransform(hJump_, transform_);
    Model::Draw(hJump_);
    Model::SetTransform(hScore_, transform_);
    Model::Draw(hScore_);
}

void Item::Release()
{
}

//何かに当たった
void Item::OnCollision(GameObject * pTarget)
{
    //当たったとき
    if (pTarget->GetObjectName() == "Stage")
    {
        //this->KillMe();
    }
}