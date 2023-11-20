#include "Engine/Camera.h"
#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Camera::SetPosition(XMFLOAT3(15, 3, -25));
	Camera::SetTarget(XMFLOAT3(15, 0, 10));
	
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
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
