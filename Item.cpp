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
    // ���Ԋu�Ń����_���l���o�͂���
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
    std::random_device rd;   // �V�[�h������
    std::mt19937 gen(rd());  // �����Z���k�E�c�C�X�^������
    std::uniform_int_distribution<> dis(min, max); // ��l���z
    return dis(gen);
}