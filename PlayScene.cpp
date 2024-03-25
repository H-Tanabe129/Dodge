#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Obstacle.h"
#include "BackGround.h"
#include "Engine/Camera.h"
#include "Engine/Audio.h"

//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene"), hSound_(-1)
{
}

//初期化
void PlayScene::Initialize()
{
	//サウンドデータのロード
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
