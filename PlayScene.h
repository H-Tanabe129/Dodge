#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class PlayScene : public GameObject
{
private:
	static const int FPS = 60;
	int frame = 0;
	int hSound_;    //サウンド番号

	static const int CPosiX = 15;	//カメラポジションX
	static const int CPosiY = 3;	//カメラポジションY
	static const int CPosiZ = -25;	//カメラポジションZ
	static const int CTarX = 15;	//カメラターゲットX
	static const int CTarY = 0;		//カメラターゲットY
	static const int CTarZ = 10;	//カメラターゲットZ


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