#include "Player.h"

Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Player.fbx");
    assert(hModel_ >= 0);
}

void Player::Update()
{
    //�X�y�[�X�L�[��������Ă�����W�����v
	static float velocity = 0.0f;
	if (Input::IsKey(DIK_SPACE))
    {
		velocity = 0.15f;
	}
	if (velocity != 0.0f)
	{
		// �������d�͂ŏ��X�ɉ�����
		velocity -= 0.02f;

		//�L�����N�^�[�̏ꏊ�ɒl��n��
		transform_.position_.y += velocity;
    }
}

void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Player::Release()
{
}
