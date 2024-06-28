#pragma once
#include "Engine/GameObject.h"
#include "ItemBase.h"
#include "ScoreUp.h"
#include "JumpUp.h"
#include "SpeedDown.h"
#include <vector>
#include <random>

enum {
    Score = 1,
    Jump,
    Speed,
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

    int trPosiX = 35;                   //���f���|�W�V����X
    float trPosiY = 0;                  //���f���|�W�V����Y
    static const int trPosiZ = 0;       //���f���|�W�V����Z
    float trPosiChangeX = 0.1;      //X���W�ω���

    int min = -700;     //Y���W�����͈͂̍ŏ��l*100
    int max = 700;      //Y���W�����͈͂̍ő�l*100
    int flo = 100;     //Y���W������1000����
    int geneRand = 0;   //Y���W����

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

    int GenerateRand();
};