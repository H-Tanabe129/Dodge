#include "Player.h"
#include "Ready.h"
#include "ValueManager.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"

Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1), hSound_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
    //�T�E���h�f�[�^�̃��[�h
    hSound_ = Audio::Load("A1_18278.WAV");
    assert(hSound_ >= 0);

    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Model/Player.fbx");
    assert(hModel_ >= 0);
	transform_.position_.z = posiZ;
	transform_.position_.y = posiY;

	SphereCollider* collision = 
		new SphereCollider(XMFLOAT3(SColliderX, SColliderY, SColliderZ), radius);
	AddCollider(collision);
}

void Player::Update()
{
	//Ready���Ă���start
	//Ready* pReady = (Ready*)FindObject("Ready");
	//if (pReady != nullptr && !pReady->Finished())
	//	return;

    //�X�y�[�X�L�[��������Ă�����W�����v
	float velocity = veloIni;
	if (Input::IsKey(DIK_SPACE))
    {
		velocity = veloIncre;
		Audio::Play(hSound_);
	}
	if (Input::IsKeyUp(DIK_SPACE))//velocity != veloIni
	{
		// �������d�͂ŏ��X�ɉ�����
		velocity -= veloDecre;

		//�L�����N�^�[�̏ꏊ�ɒl��n��
		transform_.position_.y += velocity;
    }

	if (transform_.position_.y >= edge || transform_.position_.y <= -edge)
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