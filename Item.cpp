#include "Item.h"
#include "SpeedDown.h"
#include "JumpUp.h"
#include "ScoreUp.h"
#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"
#include <random>

Item::Item(GameObject* parent)
	:GameObject(parent, "Item")
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
    // 一定間隔でランダム値を出力する
    int randomValue = getRandomValue(randMin, randMax);
    if (frame % (FPS * randomValue) == 0)
    {
        switch (rd) {
        case ScoreUp:
        }
    }
}

void Item::Draw()
{
}

void Item::Release()
{
}

//何かに当たった
void Item::OnCollision(GameObject * pTarget)
{
    //当たったとき
    if (pTarget->GetObjectName() == "Stage")
    {
        //this->KillMe();
    }
}

//ランダムな整数を生成する関数
int Item::getRandomValue(int min, int max) {
    std::random_device rd;   // シード生成器
    std::mt19937 gen(rd());  // メルセンヌ・ツイスタ生成器
    std::uniform_int_distribution<> dis(min, max); // 一様分布
    return dis(gen);
}