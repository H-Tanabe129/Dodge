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
		case TOGETHER:		//ˆê
			Instantiate<StageUp>(this);
			Instantiate<StageLo>(this);
			break;
		case UPPERFRONT:	//ã‚ªè‘O‰º‚ª‰œ
			Instantiate<StageUp>(this);
			Instantiate<StageLo>(this) -> SetPosition(41, -6.0f, 0);

			break;
		case LOWERFRONT:	//‰º‚ªè‘Oã‚ª‰œ
			Instantiate<StageLo>(this);
			Instantiate<StageUp>(this) -> SetPosition(41, 7.0f, 0);

			break;
		case UPPER:			//ã‚¾‚¯
			Instantiate<StageUp>(this);
			break;
		case LOWER:			//‰º‚¾‚¯
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
