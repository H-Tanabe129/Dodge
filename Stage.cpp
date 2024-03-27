#include "Stage.h"
#include "StageUp.h"
#include "StageLo.h"
#include "Player.h"
#include <time.h>


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

	//�X�e�[�W�������_���ŕ\������
	if (frame % (FPS * 2) == 0)
	{
		rd = rand() % MAX;
		//rd = 5;

		//�X�e�[�W�p�^�[��
		switch(rd) {
		case TOGETHER:		//�ꏏ
			Instantiate<StageUp>(this);
			Instantiate<StageLo>(this);
			break;
		//case UPPERFRONT:	//�オ��O������
		//	Instantiate<StageUp>(this) -> SetPosition(33.5f, 7.5f, 0);
		//	Instantiate<StageLo>(this) -> SetPosition(38.5f, -6.5f, 0);
		//	break;
		//case LOWERFRONT:	//������O�オ��
		//	Instantiate<StageUp>(this) -> SetPosition(38.5f, 7.5f, 0);
		//	Instantiate<StageLo>(this) -> SetPosition(33.5f, -6.5f, 0);
		//	break;
		case UPPER:			//�ゾ��
			Instantiate<StageUp>(this);
			break;
		case LOWER:			//������
			Instantiate<StageLo>(this);
			break;
		//case UPPERLONG:		//�㒷��
		//	Instantiate<StageUp>(this)->SetScale(1, 2.5f, 1);
		//	GetScale();
		//	break;
		//case LOWERLONG:		//������
		//	Instantiate<StageLo>(this)->SetScale(1, 2.5f, 1);
		//	break;
		}
	}
}

void Stage::Draw()
{
}

void Stage::Release()
{
}
