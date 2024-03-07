#include "Obstacle.h"
#include "Engine/Model.h"

Obstacle::Obstacle(GameObject* parent)
	:GameObject(parent, "Obstacle"), hModel_(-1)
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Model/Obstacle.fbx");
    assert(hModel_ >= 0);
    transform_.position_.x = 5;  //kari
}

void Obstacle::Update()
{
}

void Obstacle::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Obstacle::Release()
{
}
