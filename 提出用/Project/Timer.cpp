#include "Timer.h"

static const int FPS = 60;
//コンストラクタ
Timer::Timer(GameObject* parent)
	: GameObject(parent, "Timer"),
	frame(0), active(false), drawX(0), drawY(0), M(0)
{
	num = new Text;
	num->Initialize();
}

//デストラクタ
Timer::~Timer()
{
	delete num;
}

//初期化
void Timer::Initialize()
{
	frame = 0;
	active = false;
}

//更新
void Timer::Update()
{
	if (active)
	{
		if (frame > 0)
		{
			frame--;
		}
	}
	M++;
}

//描画
void Timer::Draw()
{
	num->Draw(drawX, drawY, "Time:");
	int sec = frame / FPS;
	num->Draw(drawX + 80, drawY, sec);
	num->Draw(drawX, drawY + 30, M / 10);
}

//開放
void Timer::Release()
{
}

void Timer::SetLimit(float seconds)
{
	frame = (int)(seconds * FPS);
}

void Timer::Start()
{
	active = true;
}

void Timer::Stop()
{
	active = false;
}

bool Timer::IsFinished()
{
	return(frame == 0);
}