#pragma once
class ValueManager
{
private:
	static const int FPS = 60;				//フレームレート(1秒間)
	int frame_ = 0;							//フレームカウンタ
	int currentTime_ = 0;					//現在の時間
	int currentScore_ = 0;					//現在のスコア
	int increIntervalScore_ = 0;			//スコア増加の間隔
	static const int SCORE_UP_VALUE = 100;	//スコアの増加量
	static const int FRAME_DIV= 18;			//フレーム分割値
	//コンストラクタ　時間とスコアを初期化
	ValueManager() : currentTime_(0), currentScore_(0) {}

public:
	//シングルトンインスタンスを取得
	static ValueManager& GetInstance();
	//時間を加算
	void AddTime();
	//現在の時間を取得
	int GetTime() const;
	//時間をリセット
	void ResetTime();

	//指定された量スコアを加算
	void AddScore(int _amount);
	//現在のスコアを取得
	int GetScore() const;
	//アイテム取得時のスコア加算
	void ItemScore();
	//スコアをリセット
	void ResetScore();
};

