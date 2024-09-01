#pragma once
#include "Engine/GameObject.h"
#include <random>

//�A�C�e���̎��
enum {
    Score = 1,
    Jump,
    Speed,
    End
};

class Item : public GameObject
{
private:
    int frame = 0;                      // �t���[���J�E���^�[
    int randomValue;                    // �����_���Ԋu�l
    static const int FPS = 60;          // �t���[�����[�g

    int rd = 0;                         // ���݂̃����_���l
    static const int RANDOM_MIN = 10;   // �����_���b���Ԋu�̍ŏ��l
    static const int RANDOM_MAX = 15;   // �����_���b���Ԋu�̍ő�l

    float itemPosX = 35.0f;                 //���f���|�W�V����X
    float itemPosY = 0.0f;                  //���f���|�W�V����Y
    static const int ITEM_POS_Z = 0;        //���f���|�W�V����Z

    static const int RANDOM_Y_MIN = -700;       //Y���W�����͈͂̍ŏ��l*100
    static const int RANDOM_Y_MAX = 700;        //Y���W�����͈͂̍ő�l*100
    static const int RANDOM_Y_SEPAR = 100;      //Y���W������1000����
    int geneRand = 0;                           //Y���W����

    int getRandomValue(int min, int max);       //�����_���Ȑ����𐶐�����֐�
    std::random_device rd_dev;                  // �V�[�h������
    std::mt19937 gen;                           // �����Z���k�E�c�C�X�^������

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