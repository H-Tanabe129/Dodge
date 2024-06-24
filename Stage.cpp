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

	//�X�e�[�W�������_���ŕ\������
	if (frame % (FPS * 2) == 0)
	{
		rd = rand() % MAX;

		//�X�e�[�W�p�^�[��
		switch(rd) {
		case TOGETHER:		//�ꏏ
			Instantiate<StageUp>(this)->SetPosition(InitPosiX, InitPosiUpY, InitPosiZ);
			Instantiate<StageLo>(this)->SetPosition(InitPosiX, InitPosiLoY, InitPosiZ);
			break;
		case UPPER:			//�ゾ��
			Instantiate<StageUp>(this)->SetPosition(InitPosiX, InitPosiUpY, InitPosiZ);
			break;
		case LOWER:			//������
			Instantiate<StageLo>(this)->SetPosition(InitPosiX, InitPosiLoY, InitPosiZ);
			break;
		case UPPERLONG:		//�㒷��
			Instantiate<StageUp>(this)->SetPosition(InitPosiX, InitPosiUpY, InitPosiZ);
			Instantiate<StageUp>(this)->SetPosition(SetPosiX, SetPosiUpY, SetPosiZ);
			GetScale();
			break;
		case LOWERLONG:		//������
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
