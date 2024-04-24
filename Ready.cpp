#include "Ready.h"
#include "Engine/Image.h"

namespace {
	float startX; //移動開始X座標
	float endX;   //移動終了X座標
	float totalTime;  //移動時間
	float currentTime;  //現在の時間

	int seq_line; // 今実行している行
	float seq_time; // シーケンスを実行している時間
	enum ACT { //やることをコマンド化
		A_SLIDEIN = 1,
		A_WAIT,
		A_SLIDEOUT,
		A_END
	};

	struct Sequence {
		float time; // 時間
		int action; // やること
		float param; // 必要な値
	};

	Sequence tbl[] = {
		{0.0f, A_SLIDEIN, 5.0f}, //まずはスライドイン 
		{3.0f, A_WAIT, 0.0f/*意味なし*/}, // １秒待ってから
		{4.0f, A_SLIDEOUT, -5.0f}, // スライドアウト
		{5.0f, A_END, 0.0f} // ここで消える
	};
	ACT currentAction; // 今実行しているアクション
	bool canMove; // 移動できる
};

Ready::Ready(GameObject* parent)
	:GameObject(parent, "Ready"), hImage_(-1)
{
	seq_line = -1;
	seq_time = 0.0f;
	canMove = false;
}

Ready::~Ready()
{
}

void Ready::Initialize()
{
	hImage_ = Image::Load("Ready.png");
	startX = 5.0f;
	endX = 0;
	totalTime = 3.0f;
	currentTime = 0.0f;
}

float easeInCubic(float x) {
	return x * x * x;
}

void Ready::Update()
{
	seq_time += 1.0f / 60.0f; // 時間を進める
	if (seq_time >= tbl[seq_line + 1].time) { // 次の行を実行する
		seq_line++;
		switch (tbl[seq_line].action) {
		case A_END:
			KillMe();
			break;
		case A_SLIDEIN:
			startX = tbl[seq_line].param; // paramから0に向かって移動
			endX = 0;
			totalTime = tbl[seq_line + 1].time - seq_time;
			currentTime = 0.0f;
			break;
		case A_WAIT:
			startX = transform_.position_.x;
			endX = transform_.position_.x;
			totalTime = tbl[seq_line + 1].time - seq_time;
			currentTime = 0.0f;
			break;
		case A_SLIDEOUT:
			canMove = true;
			startX = transform_.position_.x;
			endX = tbl[seq_line].param;
			totalTime = tbl[seq_line + 1].time - seq_time;
			currentTime = 0.0f;
			break;
		}
		// その行の実行をする
	}
	currentTime += 1.0f / 60.0f;  //1フレーム分の時間を進ませる
	if (currentTime > totalTime)
		currentTime = totalTime;
	float t = currentTime / totalTime;//ここを0.0～1.0の範囲にする
	float val = easeInCubic(t);	//イージング関数を呼ぶ(t) 返ってきた値は0.0～1.0
	//valをもとにtransform_.position_を設定する
	transform_.position_.x = val * (endX - startX) + startX;
}

void Ready::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

bool Ready::Finished()
{
	return canMove;
}

//イージング　0.0～1.0を補完する曲線
//スプライン　４つ以上の点を滑らかに通る曲線