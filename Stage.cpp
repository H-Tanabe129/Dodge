#include "Stage.h"
#include <time.h>
#include "StageUp.h"
#include "StageLo.h"
#include "Abyss.h"
#include "Ceiling.h"
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
	StageUp* newStageUp = Instantiate<StageUp>(this);
	newStageUp->GetTransform(Upper);
	Instantiate<StageLo>(this);
	Instantiate<Abyss>(this);
	Instantiate<Ceiling>(this);

	srand((unsigned int)time(nullptr));
}

void Stage::Update()
{
	frame += 1;


	if (frame % (FPS * 3) == 0)
	{
		rd = 0;

		switch(rd) {
		case TOGETHER:
			Upper.position_.x = 30;
			Lower.position_.x = 30;
			break;
		case UPPERFRONT:

			break;
		case LOWERFRONT:

			break;
		case UPPER:

			break;
		case LOWER:

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
