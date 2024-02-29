#include "TitleScene.h"
#include "Engine/Image.h"

TitleScene::TitleScene(GameObject* parent)
  : GameObject(parent, "TitleScene"), hPict_(-1)
{
}

void TitleScene::Initialize()
{
    //画像データのロード
    //hPict_ = Image::Load("ファイル名");
    assert(hPict_ >= 0);
}

void TitleScene::Update()
{
}

void TitleScene::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

void TitleScene::Release()
{
}
