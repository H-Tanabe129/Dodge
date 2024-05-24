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
    static const int FPS = 60;
    int frame = 0;
    int randMin = 10;
    int randMax = 15;

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

    int getRandomValue(int min, int max);
};