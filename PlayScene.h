#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//テストシーンを管理するクラス
class PlayScene : public GameObject
{
private:
	static const int FPS = 60;
	int frame = 0;

	Text* pText;
	int hBGM_;      // サウンド番号

	static const int CAMERA_POS_X = 15;		//カメラポジションX
	static const int CAMERA_POS_Y = 3;		//カメラポジションY
	static const int CAMERA_POS_Z = -25;	//カメラポジションZ
	static const int CAMERA_TARGET_X = 15;	//カメラターゲットX
	static const int CAMERA_TARGET_Y = 0;	//カメラターゲットY
	static const int CAMERA_TARGET_Z = 10;	//カメラターゲットZ

	static const int SCORE_POS_X = 30;		//時間表示X
	static const int SCORE_POS_Y = 30;		//時間表示Y
	static const int TIME_POS_X = 30;		//スコア表示X
	static const int TIME_POS_Y = 60;		//スコア表示Y
	static const int SCORE_INCREASE = 20;	//スコア増加量

	static const int VSet = 1;         //BGM音量調節

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

	void KillAllChildren();
};