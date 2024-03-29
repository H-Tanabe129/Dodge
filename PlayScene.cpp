#include "Engine/Camera.h"
#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Obstacle.h"
#include "BackGround.h"

//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Camera::SetPosition(XMFLOAT3(15, 3, -25));  //test == 35, 3, 0    -25
	Camera::SetTarget(XMFLOAT3(15, 0, 10));
	
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<Obstacle>(this);
	//Instantiate<BackGround>(this);
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
