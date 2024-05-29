#pragma once
#include "Engine/GameObject.h"
#include <random>

enum {
    ScoreUp = 1,
    JumpUp,
    SpeedDown,
    End
};

class Item : public GameObject
{
private:
    int rd = 0;              // ���݂̃����_���l
    int frame = 0;           // �t���[���J�E���^�[
    int randomValue;         // �����_���Ԋu�l
    const int FPS = 60;      // �t���[�����[�g
    const int randMin = 10;  // �����_���b���Ԋu�̍ŏ��l
    const int randMax = 15;  // �����_���b���Ԋu�̍ő�l
    const int rdMin = 1;     // �����_���A�C�e���^�C�v�̍ŏ��l
    const int rdMax = 3;     // �����_���A�C�e���^�C�v�̍ő�l

    int getRandomValue(int min, int max);

    std::random_device rd_dev; // �V�[�h������
    std::mt19937 gen;          // �����Z���k�E�c�C�X�^������

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