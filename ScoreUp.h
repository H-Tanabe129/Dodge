#pragma once
#include "Engine/GameObject.h"

class ScoreUp : public GameObject
{
private:
    int hScore_;    //�X�R�A�A�b�v

    int trPosiX = 35;      //���f���|�W�V����X
    int trPosiY = 0;       //���f���|�W�V����Y
    int trPosiZ = 0;       //���f���|�W�V����Z
    const float BColliderPosiX = 0.5;     //�R���C�_�[�|�W�V����X
    const float BColliderPosiY = 0.5;     //�R���C�_�[�|�W�V����Y
    const float BColliderPosiZ = 0;         //�R���C�_�[�|�W�V����Z
    const float BColliderSizeX = 1;    //�R���C�_�[�T�C�YX
    const float BColliderSizeY = 1;    //�R���C�_�[�T�C�YY
    const float BColliderSizeZ = 1;    //�R���C�_�[�T�C�YZ

    int min = -800;     //Y���W�����͈͂̍ŏ��l*100
    int max = 800;      //Y���W�����͈͂̍ő�l*100
    int flo = 100;     //Y���W������1000����
    int geneRand = 0;   //Y���W����
    float trPosiChangeX = 0.1;      //X���W�ω���
    static const int LEdge = -10;   //���[

public:
    //�R���X�g���N�^
    ScoreUp(GameObject* parent);

    //�f�X�g���N�^
    ~ScoreUp();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //Y���W��������
    int GenerateRand();

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject *pTarget) override;
};

