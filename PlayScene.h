#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class PlayScene : public GameObject
{
private:
	static const int FPS = 60;
	int frame = 0;
	int hSound_;    //サウンド番号
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