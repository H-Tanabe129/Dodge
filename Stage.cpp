#include "Stage.h"

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
	Instantiate<StageLo>(this);
	Instantiate<Abyss>(this);
	Instantiate<Ceiling>(this);
}

void Stage::Update()
{
	frame += 1;

	if (frame % (FPS * 3) == 0)
	{
		Instantiate<StageUp>(this);
	}
	if (frame % (FPS * 3) == 0)
	{
		Instantiate<StageLo>(this);
	}
}

void Stage::Draw()
{
}

void Stage::Release()
{
}
