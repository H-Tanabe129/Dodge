#include "BackGround.h"
#include "Engine/Model.h"

//コンストラクタ
BackGround::BackGround(GameObject * parent)
    :GameObject(parent, "BackGround"), 
    hBuilding1_(-1), hBuilding2_(-1), hBuilding3_(-1)
{
}

//デストラクタ
BackGround::~BackGround()
{
}

//初期化
void BackGround::Initialize()
{
    //モデルデータのロード
    hBuilding1_ = Model::Load("Model/");
    assert(hBuilding1_ >= 0);
    hBuilding2_ = Model::Load("Model/");
    assert(hBuilding2_ >= 0);
    hBuilding3_ = Model::Load("Model/");
    assert(hBuilding3_ >= 0);


}

//更新
void BackGround::Update()
{
}

//描画
void BackGround::Draw()
{
    Model::SetTransform(hBuilding1_, transform_);
    Model::Draw(hBuilding1_);
    Model::SetTransform(hBuilding2_, transform_);
    Model::Draw(hBuilding2_);
    Model::SetTransform(hBuilding3_, transform_);
    Model::Draw(hBuilding3_);
}

//開放
void BackGround::Release()
{
}
