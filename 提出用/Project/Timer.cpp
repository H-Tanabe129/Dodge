#include "Timer.h"

static const int FPS = 60;
//�R���X�g���N�^
Timer::Timer(GameObject* parent)
	: GameObject(parent, "Timer"),
	frame(0), active(false), drawX(0), drawY(0), M(0)
{
	num = new Text;
	num->Initialize();
}

//�f�X�g���N�^
Timer::~Timer()
{
	delete num;
}

//������
void Timer::Initialize()
{
	frame = 0;
	active = false;
}

//�X�V
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

//�`��
void Timer::Draw()
{
	num->Draw(drawX, drawY, "Time:");
	int sec = frame / FPS;
	num->Draw(drawX + 80, drawY, sec);
	num->Draw(drawX, drawY + 30, M / 10);
}

//�J��
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