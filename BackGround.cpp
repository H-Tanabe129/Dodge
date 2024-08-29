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
    frame += 1;

    //ランダムで表示する
    if (frame % (FPS * 2) == 0)
    {
        rd = rand() % MAX;
    }

}

//描画
void BackGround::Draw()
{
    switch (rd) {
    case BUILDING_1:
        Model::SetTransform(hBuilding1_, transform_);
        Model::Draw(hBuilding1_);
        break;
    case BUILDING_2:
        Model::SetTransform(hBuilding2_, transform_);
        Model::Draw(hBuilding2_);
        break;
    case BUILDING_3:
        Model::SetTransform(hBuilding3_, transform_);
        Model::Draw(hBuilding3_);
        break;
    default:
        break;
    }
}

//開放
void BackGround::Release()
{
}
