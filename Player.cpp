#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"

Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1), pText(nullptr)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Model/Player.fbx");
    assert(hModel_ >= 0);
	transform_.position_.z = -1;

	pText = new Text;
	pText->Initialize();

	SphereCollider* collision = new SphereCollider(XMFLOAT3(1.0f, 1.0f, 1.0f), 1.02f);
	AddCollider(collision);
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

	if (transform_.position_.y == 5)
	{
		this->KillMe();
	}
}

void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
	pText->Draw(30, 30, transform_.position_.y);
}

void Player::Release()
{
	pText->Release();
}

//�����ɓ�������
void Player::OnCollision(GameObject * pTarget)
{
	if (pTarget->GetObjectName() == "StageUp" || "StageLo" || "Abyss")
    {
		this->KillMe();
		pTarget->KillMe();
    }
}