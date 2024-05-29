#include "Item.h"
#include "SpeedDown.h"
#include "JumpUp.h"
#include "ScoreUp.h"
#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

Item::Item(GameObject* parent)
	:GameObject(parent, "Item"), frame(0), randomValue(getRandomValue(randMin, randMax))
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
    // ���Ԋu�Ń����_���l���o�͂���
    if (frame % (FPS * randomValue) == 0)
    {
        rd = getRandomValue(rdMin, rdMax);
        switch (rd) {
        case ScoreUp:
            Instantiate<ScoreUp>(this);
            break;
        case JumpUp:
            Instantiate<JumpUp>(this);
            break;
        case SpeedDown:
            Instantiate<SpeedDown>(this);
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

//�����ɓ�������
void Item::OnCollision(GameObject * pTarget)
{
    //���������Ƃ�
    if (pTarget->GetObjectName() == "Stage")
    {
        //this->KillMe();
    }
}

//�����_���Ȑ����𐶐�����֐�
int Item::getRandomValue(int min, int max) {
    std::uniform_int_distribution<> dis(min, max); // ��l���z
    return dis(gen);
}