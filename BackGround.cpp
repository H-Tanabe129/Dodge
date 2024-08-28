#include "BackGround.h"
#include "Engine/Model.h"

//�R���X�g���N�^
BackGround::BackGround(GameObject * parent)
    :GameObject(parent, "BackGround"), 
    hBuilding1_(-1), hBuilding2_(-1), hBuilding3_(-1)
{
}

//�f�X�g���N�^
BackGround::~BackGround()
{
}

//������
void BackGround::Initialize()
{
    //���f���f�[�^�̃��[�h
    hBuilding1_ = Model::Load("Model/");
    assert(hBuilding1_ >= 0);
    hBuilding2_ = Model::Load("Model/");
    assert(hBuilding2_ >= 0);
    hBuilding3_ = Model::Load("Model/");
    assert(hBuilding3_ >= 0);


}

//�X�V
void BackGround::Update()
{
}

//�`��
void BackGround::Draw()
{
    Model::SetTransform(hBuilding1_, transform_);
    Model::Draw(hBuilding1_);
    Model::SetTransform(hBuilding2_, transform_);
    Model::Draw(hBuilding2_);
    Model::SetTransform(hBuilding3_, transform_);
    Model::Draw(hBuilding3_);
}

//�J��
void BackGround::Release()
{
}
