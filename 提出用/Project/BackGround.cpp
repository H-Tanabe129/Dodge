#include "BackGround.h"

BackGround::BackGround(GameObject* parent)
  : GameObject(parent, "BackGround")//, hPict_(-1)
{
}

BackGround::~BackGround()
{
}

void BackGround::Initialize()
{
    //�摜�f�[�^�̃��[�h
    //hPict_ = Image::Load("�t�@�C����");
    //assert(hPict_ >= 0);
}

void BackGround::Update()
{
}

void BackGround::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
}

void BackGround::Release()
{
}
