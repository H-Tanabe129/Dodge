#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//テストシーンを管理するクラス
class PlayScene : public GameObject
{
private:
	static const int FPS = 60;
	int frame = 0;
	int hSound_;    //サウンド番号
	Text* pText;

	static const int CPosiX = 15;	//カメラポジションX  //test == 35, 3, 0    -25
	static const int CPosiY = 3;	//カメラポジションY
	static const int CPosiZ = -25;	//カメラポジションZ
	static const int CTarX = 15;	//カメラターゲットX
	static const int CTarY = 0;		//カメラターゲットY
	static const int CTarZ = 10;	//カメラターゲットZ

	static const int scoreX = 30;    //時間表示X
	static const int scoreY = 30;    //時間表示Y
	static const int timeX = 30;     //スコア表示X
	static const int timeY = 60;     //スコア表示Y
	int score = 20;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};