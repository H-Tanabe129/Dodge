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
	//Instantiate<StageUp>(this);
	//Instantiate<StageLo>(this);
	Instantiate<Abyss>(this);
	Instantiate<Ceiling>(this);

	srand((unsigned int)time(nullptr));
}

void Stage::Update()
{
	frame += 1;


	if (frame % (FPS * 3) == 0)
	{
		rd = rand() % MAX;

		switch(rd) {
		case TOGETHER:

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

		Instantiate<StageUp>(this);
		Instantiate<StageLo>(this);
	}
}

void Stage::Draw()
{
}

void Stage::Release()
{
}
