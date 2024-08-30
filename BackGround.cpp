#include "BackGround.h"
#include "Engine/Image.h"

//�R���X�g���N�^
BackGround::BackGround(GameObject * parent)
    :GameObject(parent, "BackGround"), 
    hBack_(-1), hBuilding1_(-1), hBuilding2_(-1), hBuilding3_(-1)
{
}

//�f�X�g���N�^
BackGround::~BackGround()
{
}

//������
void BackGround::Initialize()
{
    //�摜�f�[�^�̃��[�h
    hBack_ = Image::Load("shiro.png");
    assert(hBack_ >= 0);

    //���f���f�[�^�̃��[�h
    hBuilding1_ = Model::Load("Model/Back.fbx");
    assert(hBuilding1_ >= 0);
    hBuilding2_ = Model::Load("Model/Back.fbx");
    assert(hBuilding2_ >= 0);
    hBuilding3_ = Model::Load("Model/Back.fbx");
    assert(hBuilding3_ >= 0);

    // �����ʒu
    buildTrans1_.position_ = XMFLOAT3(trPosiX, trPosiY, trPosiZ);
    buildTrans2_.position_ = XMFLOAT3(trMidPosiX, trPosiY, trPosiZ);
    buildTrans3_.position_ = XMFLOAT3(trBackPosiX, trPosiY, trPosiZ);

    // �w�i
    picTrans_.position_ = XMFLOAT3(picPosiX, picPosiY, picPosiZ);
    picTrans_.scale_ = XMFLOAT3(picScaleX, picScaleY, picScaleZ);
    Image::SetAlpha(hBack_, picAlpha);
}

//�X�V
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

//�`��
void BackGround::Draw()
{
    // ���f��
    Model::SetTransform(hBuilding1_, buildTrans1_);
    Model::Draw(hBuilding1_);
    Model::SetTransform(hBuilding2_, buildTrans2_);
    Model::Draw(hBuilding2_);
    Model::SetTransform(hBuilding3_, buildTrans3_);
    Model::Draw(hBuilding3_);

    // �w�i
    Image::SetTransform(hBack_, picTrans_);
    Image::Draw(hBack_);
}

//�J��
void BackGround::Release()
{
}
