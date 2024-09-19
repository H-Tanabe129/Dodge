#include "Item.h"
#include "ScoreUp.h"
#include "Stage.h"

Item::Item(GameObject* parent)
	:GameObject(parent, "Item"), 
    frame(0), randomValue(0)
{
}

Item::~Item()
{
}

void Item::Initialize()
{
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    getRandomValue(RANDOM_MIN, RANDOM_MAX);
}

void Item::Update()
{
    frame += 1;

    // randomValue��0�łȂ����Ƃ��m�F���A0�̏ꍇ�Đ�������
    if (randomValue == 0)
    {
        do {
            randomValue = getRandomValue(RANDOM_MIN, RANDOM_MAX);
        } while (randomValue == 0);
    }
    // ���Ԋu�Ń����_���l���o�͂���
    if(frame % (FPS * randomValue) == 0)
    {
        itemPosY = GenerateRand();
        Instantiate<ScoreUp>(this)->SetPosition(itemPosX, itemPosY, ITEM_POS_Z);
        randomValue = getRandomValue(RANDOM_MIN, RANDOM_MAX);
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
    geneRand = (rand() % (RANDOM_Y_MAX - RANDOM_Y_MIN + 1) + RANDOM_Y_MIN) / RANDOM_Y_SEPAR;
    return geneRand;
}
