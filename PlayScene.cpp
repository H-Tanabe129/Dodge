#include "PlayScene.h"
#include "Stage.h"
#include "Item.h"
#include "ValueManager.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"

//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene"), pText(nullptr), pPlayer_(nullptr), hSound_(-1)
{
}

PlayScene::~PlayScene()
{
	delete pText;
	delete pPlayer_;
}

//初期化
void PlayScene::Initialize()
{

	Camera::SetPosition(XMFLOAT3(CPosiX, CPosiY, CPosiZ));
	Camera::SetTarget(XMFLOAT3(CTarX, CTarY, CTarZ));

	// すべての子オブジェクトを削除
	KillAllChildren();
	
	//Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<Item>(this);

	// Player クラスのインスタンスを生成
	pPlayer_ = new Player(this);
	pPlayer_->Initialize();

	pText = new Text;
	pText->Initialize();

	ValueManager::GetInstance().ResetScore();
	ValueManager::GetInstance().ResetTime();
}

//更新
void PlayScene::Update()
{
	if (pPlayer_) {
		pPlayer_->Update();
	}

	ValueManager::GetInstance().AddScore(score);
	ValueManager::GetInstance().AddTime();
}

//描画
void PlayScene::Draw()
{
	pText->Draw(scoreX, scoreY, "Score:");
	pText->Draw(scoreX+100, scoreY, ValueManager::GetInstance().GetScore());
	pText->Draw(timeX, timeY, "Time: ");
	pText->Draw(timeX+100, timeY, ValueManager::GetInstance().GetTime());

	if (pPlayer_) {
		pPlayer_->Draw();
	}
}

//開放
void PlayScene::Release()
{
	if (pText) {
		pText->Release(); // リソースを解放
		delete pText;     // メモリを解放
		pText = nullptr;  // ポインタを無効化
	}

	if (pPlayer_) {
		pPlayer_->Release();
		delete pPlayer_;
		pPlayer_ = nullptr;
	}
}

// 子オブジェクトを全て削除
void PlayScene::KillAllChildren()
{
	for (auto& child : *GetChildList())  // ポインタをデリファレンスしてリストを取得
	{
		child->KillMe();
	}
	GetChildList()->clear();  // ポインタをデリファレンスしてリストをクリア
}