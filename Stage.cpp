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
		//rd = rand() % MAX;
		rd = 0;

		switch(rd) {
		case TOGETHER:
			Instantiate<StageUp>(this);
			Instantiate<StageLo>(this);
			break;
		case UPPERFRONT:
			Instantiate<StageUp>(this);

			break;
		case LOWERFRONT:
			Instantiate<StageLo>(this);

			break;
		case UPPER:
			Instantiate<StageUp>(this);
			break;
		case LOWER:
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
