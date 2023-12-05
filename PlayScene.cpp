#include "Engine/Camera.h"
#include "PlayScene.h"
#include "Player.h"
#include "StageUp.h"
#include "StageLo.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Camera::SetPosition(XMFLOAT3(15, 3, -25));  //35, 3, 0
	Camera::SetTarget(XMFLOAT3(15, 0, 10));
	
	Instantiate<Player>(this);

	Instantiate<StageUp>(this);
	//Instantiate<StageLo>(this);
}

//�X�V
void PlayScene::Update()
{
	frame += 1;

	if (frame % 150 == 0)
	{
		Instantiate<StageUp>(this);
	}
	if (frame % 150 == 0)
	{
		Instantiate<StageLo>(this);
	}
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}
