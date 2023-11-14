#include "Engine/Camera.h"
#include "PlayScene.h"
#include "Player.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Camera::SetPosition(XMFLOAT3(0, 3, -8));
	Camera::SetTarget(XMFLOAT3(0, 2, 0));
	
	Instantiate<Player>(this);
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
