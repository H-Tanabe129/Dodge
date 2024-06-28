#include "Item.h"
#include "SpeedDown.h"
#include "JumpUp.h"
#include "ScoreUp.h"
#include "Stage.h"

void Item::SpawnItem()
{
}

Item::Item(GameObject* parent)
	:GameObject(parent, "Item"), 
    frame(0), randomValue(getRandomValue(randMin, randMax)), gen(rd_dev())
{
}

Item::~Item()
{
}

void Item::Initialize()
{
    srand((unsigned int)time(nullptr));
}

void Item::Update()
{
    frame += 1;

    // randomValue��0�łȂ����Ƃ��m�F���A0�̏ꍇ�Đ�������
    if (randomValue == 0)
    {
        do {
            randomValue = getRandomValue(randMin, randMax);
        } while (randomValue == 0);
    }
    // ���Ԋu�Ń����_���l���o�͂���
    if(frame % (FPS * randomValue) == 0)
    {
        trPosiY = GenerateRand();
        rd = getRandomValue(rdMin, rdMax);
        switch (rd) {
        case Score:
            Instantiate<ScoreUp>(this)/*->SetPosition(trPosiX, trPosiY, trPosiZ)*/;
            break;
        case Jump:
            Instantiate<JumpUp>(this)/*->SetPosition(trPosiX, trPosiY, trPosiZ)*/;
            break;
        case Speed:
            Instantiate<SpeedDown>(this)/*->SetPosition(trPosiX, trPosiY, trPosiZ)*/;
            break;
        }
    randomValue = getRandomValue(randMin, randMax);
    }
}

void Item::Draw()
{
}

void Item::Release()
{
}

//�����_���Ȑ����𐶐�����֐�
int Item::getRandomValue(int min, int max) {
    std::uniform_int_distribution<> dis(min, max); // ��l���z
    return dis(gen);
}

int Item::GenerateRand()
{
    geneRand = (rand() % (max - min + 1) + min) / flo;
    return geneRand;
}
