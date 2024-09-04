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

    // randomValueが0でないことを確認し、0の場合再生成する
    if (randomValue == 0)
    {
        do {
            randomValue = getRandomValue(RANDOM_MIN, RANDOM_MAX);
        } while (randomValue == 0);
    }
    // 一定間隔でランダム値を出力する
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

//ランダムな整数を生成する関数
int Item::getRandomValue(int min, int max) {
    std::uniform_int_distribution<> dis(min, max); // 一様分布
    return dis(gen);
}

int Item::GenerateRand()
{
    geneRand = (rand() % (RANDOM_Y_MAX - RANDOM_Y_MIN + 1) + RANDOM_Y_MIN) / RANDOM_Y_SEPAR;
    return geneRand;
}
