#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"

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
    hModel_ = Model::Load("Model/Player.fbx");
    assert(hModel_ >= 0);
	transform_.position_.z = -1;

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

	if (transform_.position_.y >= 14 || transform_.position_.y <= -14)
	{
		this->KillMe();

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
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

//�����ɓ�������
void Player::OnCollision(GameObject * pTarget)
{
	if (pTarget->GetObjectName() == "StageUp" || "StageLo")
    {
		this->KillMe();
		pTarget->KillMe();

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
    }
}