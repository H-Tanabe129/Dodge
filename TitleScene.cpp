#include "TitleScene.h"
#include "Engine/Image.h"

TitleScene::TitleScene(GameObject* parent)
  : GameObject(parent, "TitleScene"), hPict_(-1)
{
}

void TitleScene::Initialize()
{
    //�摜�f�[�^�̃��[�h
    //hPict_ = Image::Load("�t�@�C����");
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
