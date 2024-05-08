#include "PlayScene.h"
#include "Player.h"
#include "Stage.h"
#include "Item.h"
#include "ValueManager.h"
#include "Engine/Camera.h"
#include "Engine/Audio.h"
#include "Engine/Input.h"

//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene"), hSound_(-1), pText(nullptr)
{
}

//初期化
void PlayScene::Initialize()
{
	//サウンドデータのロード
	hSound_ = Audio::Load("A2_01003.WAV", true);
	assert(hSound_ >= 0);

	Camera::SetPosition(XMFLOAT3(CPosiX, CPosiY, CPosiZ));  //test == 35, 3, 0    -25
	Camera::SetTarget(XMFLOAT3(CTarX, CTarY, CTarZ));
	
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
	//Instantiate<Item>(this);

	pText = new Text;
	pText->Initialize();
	Audio::Play(hSound_);
}

//更新
void PlayScene::Update()
{
	ValueManager::GetInstance().AddScore(score);
	ValueManager::GetInstance().AddTime();
}

//描画
void PlayScene::Draw()
{
	pText->Draw(scoreX, scoreY, ValueManager::GetInstance().GetScore());
	pText->Draw(timeX, timeY, ValueManager::GetInstance().GetTime());
}

//開放
void PlayScene::Release()
{
	pText->Release();
}
