#include "Stage.h"
#include "StageUp.h"
#include "StageLo.h"
#include "StageLoMore.h"
#include "Player.h"
#include "Item.h"
#include <time.h>


Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage")
{
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	Instantiate<StageUp>(this);
	Instantiate<StageLo>(this);
	Instantiate<StageLoMore>(this);

	srand((unsigned int)time(nullptr));
}

void Stage::Update()
{
	frame += 1;

	//ステージをランダムで表示する
	if (frame % (FPS * 2) == 0)
	{
		rd = rand() % MAX;

		//ステージパターン
		switch(rd) {
		case TOGETHER:		//一緒
			Instantiate<StageUp>(this)->SetPosition(InitPosiX, InitPosiUpY, InitPosiZ);
			Instantiate<StageLo>(this)->SetPosition(InitPosiX, InitPosiLoY, InitPosiZ);
			break;
		case UPPER:			//上だけ
			Instantiate<StageUp>(this)->SetPosition(InitPosiX, InitPosiUpY, InitPosiZ);
			break;
		case LOWER:			//下だけ
			Instantiate<StageLo>(this)->SetPosition(InitPosiX, InitPosiLoY, InitPosiZ);
			break;
		case UPPERLONG:		//上長め
			Instantiate<StageUp>(this)->SetPosition(SetPosiX, SetPosiUpY, SetPosiZ);
			Instantiate<StageUp>(this)->SetPosition(InitPosiX, InitPosiUpY, InitPosiZ);
			break;
		case LOWERLONG:		//下長め
			Instantiate<StageLoMore>(this)->SetPosition(InitPosiX, InitPosiLoY, InitPosiZ);
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