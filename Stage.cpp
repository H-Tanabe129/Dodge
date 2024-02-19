#include "Stage.h"
#include <time.h>
#include "StageUp.h"
#include "StageLo.h"
#include "Player.h"


Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1)
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	Instantiate<StageUp>(this);
	Instantiate<StageLo>(this);

	srand((unsigned int)time(nullptr));
}

void Stage::Update()
{
	frame += 1;


	if (frame % (FPS * 3) == 0)
	{
		rd = rand() % MAX;
		//rd = 2;

		switch(rd) {
		case TOGETHER:		//一緒
			Instantiate<StageUp>(this);
			Instantiate<StageLo>(this);
			break;
		case UPPERFRONT:	//上が手前下が奥
			Instantiate<StageUp>(this);
			Instantiate<StageLo>(this) -> SetPosition(41, -6.0f, 0);

			break;
		case LOWERFRONT:	//下が手前上が奥
			Instantiate<StageLo>(this);
			Instantiate<StageUp>(this) -> SetPosition(41, 7.0f, 0);

			break;
		case UPPER:			//上だけ
			Instantiate<StageUp>(this);
			break;
		case LOWER:			//下だけ
			Instantiate<StageLo>(this);
			break;
		}
	}
}

void Stage::Draw()
{
}

void Stage::Release()
{
}
