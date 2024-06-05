#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Item.h"
#include "ValueManager.h"
#include "Engine/Camera.h"
#include "Engine/Audio.h"
#include "Engine/Input.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene"), hSound_(-1), pText(nullptr)
{
}

//������
void PlayScene::Initialize()
{
	//�T�E���h�f�[�^�̃��[�h
	hSound_ = Audio::Load("A2_01003.WAV", true);
	assert(hSound_ >= 0);

	Camera::SetPosition(XMFLOAT3(CPosiX, CPosiY, CPosiZ));
	Camera::SetTarget(XMFLOAT3(CTarX, CTarY, CTarZ));

	// ���ׂĂ̎q�I�u�W�F�N�g���폜
	KillAllChildren();
	
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<Item>(this);

	pText = new Text;
	pText->Initialize();
	Audio::Play(hSound_);

	ValueManager::GetInstance().ResetScore();
	ValueManager::GetInstance().ResetTime();
}

//�X�V
void PlayScene::Update()
{
	ValueManager::GetInstance().AddScore(score);
	ValueManager::GetInstance().AddTime();
}

//�`��
void PlayScene::Draw()
{
	pText->Draw(scoreX, scoreY, "Score:");
	pText->Draw(scoreX+100, scoreY, ValueManager::GetInstance().GetScore());
	pText->Draw(timeX, timeY, "Time: ");
	pText->Draw(timeX+100, timeY, ValueManager::GetInstance().GetTime());
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