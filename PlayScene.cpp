#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Item.h"
#include "BackGround.h"
#include "ValueManager.h"
#include "Engine/Audio.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene"), pText(nullptr), hBGM_(-1)
{
}

//������
void PlayScene::Initialize()
{
	//�T�E���h�f�[�^�̃��[�h
	hBGM_ = Audio::Load("A2_01003.WAV", true);
	assert(hBGM_ >= 0);
	Audio::Play(hBGM_);
	Audio::SetVolume(hBGM_, VSet);

	//�J����
	Camera::SetPosition(XMFLOAT3(CAMERA_POS_X, CAMERA_POS_Y, CAMERA_POS_Z));
	Camera::SetTarget(XMFLOAT3(CAMERA_TARGET_X, CAMERA_TARGET_Y, CAMERA_TARGET_Z));

	// ���ׂĂ̎q�I�u�W�F�N�g���폜
	KillAllChildren();
	
	Instantiate<BackGround>(this);
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<Item>(this);

	pText = new Text;
	pText->Initialize();

	ValueManager::GetInstance().ResetScore();
	ValueManager::GetInstance().ResetTime();
}

//�X�V
void PlayScene::Update()
{
	ValueManager::GetInstance().AddScore(SCORE_INCREASE);
	ValueManager::GetInstance().AddTime();
}

//�`��
void PlayScene::Draw()
{
	pText->Draw(SCORE_POS_X, SCORE_POS_Y, "Score:");
	pText->Draw(SCORE_POS_X+100, SCORE_POS_Y, ValueManager::GetInstance().GetScore());
	pText->Draw(TIME_POS_X, TIME_POS_Y, "Time: ");
	pText->Draw(TIME_POS_X+100, TIME_POS_Y, ValueManager::GetInstance().GetTime());
}

//�J��
void PlayScene::Release()
{
	pText->Release();
}

// �q�I�u�W�F�N�g��S�č폜
void PlayScene::KillAllChildren()
{
	for (auto& child : *GetChildList())  // �|�C���^���f���t�@�����X���ă��X�g���擾
	{
		child->KillMe();
	}
	GetChildList()->clear();  // �|�C���^���f���t�@�����X���ă��X�g���N���A
}