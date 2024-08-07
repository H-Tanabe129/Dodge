#include "Item.h"
#include "ScoreUp.h"
#include "Stage.h"

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

    // randomValueが0でないことを確認し、0の場合再生成する
    if (randomValue == 0)
    {
        do {
            randomValue = getRandomValue(randMin, randMax);
        } while (randomValue == 0);
    }
    // 一定間隔でランダム値を出力する
    if(frame % (FPS * randomValue) == 0)
    {
        trPosiY = GenerateRand();
        Instantiate<ScoreUp>(this)->SetPosition(trPosiX, trPosiY, trPosiZ);
        randomValue = getRandomValue(randMin, randMax);
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
    geneRand = (rand() % (max - min + 1) + min) / flo;
    return geneRand;
}
