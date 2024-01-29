#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Timer : public GameObject
{
	int frame;  //残り時間を数える変数
	Text* num;
	bool active;  //trueの時にカウントダウンする
	int drawX, drawY;
	float M;  //距離のカウント
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Timer(GameObject* parent);
	~Timer();

	//初期化
	void Initialize() override;
	//更新
	void Update() override;
	//描画
	void Draw() override;
	//開放
	void Release() override;

	/// <summary>
	/// 制限時間を設定する
	/// </summary>
	/// <param name="seconds">制限時間</param>
	void SetLimit(float seconds);

	/// <summary>
	/// タイマーを開始
	/// </summary>
	void Start();

	/// <summary>
	/// タイマーを停止
	/// </summary>
	void Stop();

	/// <summary>
	/// タイマーが終了したか
	/// </summary>
	/// <returns>終了したらtrue</returns>
	bool IsFinished();

	/// <summary>
	/// 画面の表示位置を指定する
	/// </summary>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	void DrawPosition(int x, int y) { drawX = x, drawY = y; }
};