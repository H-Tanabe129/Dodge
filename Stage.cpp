#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1)
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
    StaUpper.position_ = XMFLOAT3(20, 6.8f, 0);
    StaLower.position_ = XMFLOAT3(20, -5.7f, 0);

    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Model/Stage.fbx");
    assert(hModel_ >= 0);

    BoxCollider* collisionU = new BoxCollider(StaUpper.position_, XMFLOAT3(1, 8, 1));
    AddCollider(collisionU);
    BoxCollider* collisionL = new BoxCollider(StaLower.position_, XMFLOAT3(1, 8, 1));
    AddCollider(collisionL);
}

void Stage::Update()
{
    StaUpper.position_.x -= 0.1f;
    StaLower.position_.x -= 0.1f;

    // �R���C�_�[�̈ʒu���X�V
    GetCollider(0)->SetPosition(StaUpper.position_);
    GetCollider(1)->SetPosition(StaLower.position_);
}

void Stage::Draw()
{
    Model::SetTransform(hModel_, StaUpper);
    Model::Draw(hModel_);
    Model::SetTransform(hModel_, StaLower);
    Model::Draw(hModel_);
}

void Stage::Release()
{
}

Collider* Stage::GetCollider(size_t index) const
{
    if (index < colliders_.size()) {
        return colliders_[index];
    } else {
        // �C���f�b�N�X���͈͊O�̏ꍇ��nullptr��Ԃ����A�G���[�������s��
        return nullptr;
    }
}