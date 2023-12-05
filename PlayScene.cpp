#include "Engine/Camera.h"
#include "PlayScene.h"
#include "Player.h"
#include "StageUp.h"
#include "StageLo.h"

//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Camera::SetPosition(XMFLOAT3(15, 3, -25));  //35, 3, 0
	Camera::SetTarget(XMFLOAT3(15, 0, 10));
	
	Instantiate<Player>(this);

	Instantiate<StageUp>(this);
	//Instantiate<StageLo>(this);
}

//更新
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

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
