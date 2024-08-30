#include "BackGround.h"
#include "Engine/Image.h"

//コンストラクタ
BackGround::BackGround(GameObject * parent)
    :GameObject(parent, "BackGround"), 
    hBack_(-1), hBuilding1_(-1), hBuilding2_(-1), hBuilding3_(-1)
{
}

//デストラクタ
BackGround::~BackGround()
{
}

//初期化
void BackGround::Initialize()
{
    //画像データのロード
    hBack_ = Image::Load("shiro.png");
    assert(hBack_ >= 0);

    //モデルデータのロード
    hBuilding1_ = Model::Load("Model/Back.fbx");
    assert(hBuilding1_ >= 0);
    hBuilding2_ = Model::Load("Model/Back.fbx");
    assert(hBuilding2_ >= 0);
    hBuilding3_ = Model::Load("Model/Back.fbx");
    assert(hBuilding3_ >= 0);

    // 初期位置
    buildTrans1_.position_ = XMFLOAT3(trPosiX, trPosiY, trPosiZ);
    buildTrans2_.position_ = XMFLOAT3(trMidPosiX, trPosiY, trPosiZ);
    buildTrans3_.position_ = XMFLOAT3(trBackPosiX, trPosiY, trPosiZ);

    // 背景
    picTrans_.position_ = XMFLOAT3(picPosiX, picPosiY, picPosiZ);
    picTrans_.scale_ = XMFLOAT3(picScaleX, picScaleY, picScaleZ);
    Image::SetAlpha(hBack_, picAlpha);
}

//更新
void BackGround::Update()
{
    buildTrans1_.position_.x -= trPosiChangeX;
    buildTrans2_.position_.x -= trPosiChangeX;
    buildTrans3_.position_.x -= trPosiChangeX;

    if (buildTrans1_.position_.x <= LEdge) {
        buildTrans1_.position_.x = loopPosiX;
    }
    if (buildTrans2_.position_.x <= LEdge) {
        buildTrans2_.position_.x = loopPosiX;
    }
    if (buildTrans3_.position_.x <= LEdge) {
        buildTrans3_.position_.x = loopPosiX;
    }
}

//描画
void BackGround::Draw()
{
    // モデル
    Model::SetTransform(hBuilding1_, buildTrans1_);
    Model::Draw(hBuilding1_);
    Model::SetTransform(hBuilding2_, buildTrans2_);
    Model::Draw(hBuilding2_);
    Model::SetTransform(hBuilding3_, buildTrans3_);
    Model::Draw(hBuilding3_);

    // 背景
    Image::SetTransform(hBack_, picTrans_);
    Image::Draw(hBack_);
}

//開放
void BackGround::Release()
{
}
