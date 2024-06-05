#include "Stage.h"
#include "StageUp.h"
#include "StageLo.h"
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
		//case UPPERFRONT:	//上が手前下が奥
		//	Instantiate<StageUp>(this) -> SetPosition(33.5f, 7.5f, 0);
		//	Instantiate<StageLo>(this) -> SetPosition(38.5f, -6.5f, 0);
		//	break;
		//case LOWERFRONT:	//下が手前上が奥
		//	Instantiate<StageUp>(this) -> SetPosition(38.5f, 7.5f, 0);
		//	Instantiate<StageLo>(this) -> SetPosition(33.5f, -6.5f, 0);
		//	break;
		case UPPER:			//上だけ
			Instantiate<StageUp>(this)->SetPosition(InitPosiX, InitPosiUpY, InitPosiZ);
			break;
		case LOWER:			//下だけ
			Instantiate<StageLo>(this)->SetPosition(InitPosiX, InitPosiLoY, InitPosiZ);
			break;
		case UPPERLONG:		//上長め
			Instantiate<StageUp>(this)->SetPosition(InitPosiX, InitPosiUpY, InitPosiZ);
			Instantiate<StageUp>(this)->SetPosition(SetPosiX, SetPosiUpY, SetPosiZ);
			GetScale();
			break;
		case LOWERLONG:		//下長め
			Instantiate<StageLo>(this)->SetPosition(InitPosiX, InitPosiLoY, InitPosiZ);
			Instantiate<StageLo>(this)->SetPosition(SetPosiX, SetPosiLoY, SetPosiZ);
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
