#pragma once
#include "Engine/GameObject.h"

enum {
    ScoreUp = 1,
    JumpUp,
    SpeedDown,
    End
};

class Item : public GameObject
{
private:
    int rd = 0;
    int frame = 0;
    int randomValue;
    const int FPS = 60;
    const int randMin = 10;
    const int randMax = 15;

    int getRandomValue(int min, int max);

public:
    //�R���X�g���N�^
    Item(GameObject* parent);

    //�f�X�g���N�^
    ~Item();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject *pTarget) override;
};