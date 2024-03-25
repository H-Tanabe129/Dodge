#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Obstacle.h"
#include "BackGround.h"
#include "Engine/Camera.h"
#include "Engine/Audio.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene"), hSound_(-1)
{
}

//������
void PlayScene::Initialize()
{
	//�T�E���h�f�[�^�̃��[�h
	hSound_ = Audio::Load("A2_01003.WAV");
	assert(hSound_ >= 0);

	Camera::SetPosition(XMFLOAT3(15, 3, -25));  //test == 35, 3, 0    -25
	Camera::SetTarget(XMFLOAT3(15, 0, 10));
	
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	//Instantiate<Obstacle>(this);

	//Instantiate<BackGround>(this);
	Audio::Play(hSound_);
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
