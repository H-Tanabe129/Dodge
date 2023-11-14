#include "Engine/Camera.h"
#include "PlayScene.h"
#include "Player.h"

//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Camera::SetPosition(XMFLOAT3(0, 3, -8));
	Camera::SetTarget(XMFLOAT3(0, 2, 0));
	
	Instantiate<Player>(this);
}

//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
