#pragma once
#include "Engine/GameObject.h"

class JumpUp : public GameObject
{
private:
    int hJump_;     //�W�����v�̓A�b�v

    int trPosiX = 35;      //���f���|�W�V����X
    int trPosiY = 0;       //���f���|�W�V����Y
    int trPosiZ = 0;       //���f���|�W�V����Z
    int BColliderPosiX = 0.75f;     //�R���C�_�[�|�W�V����X
    int BColliderPosiY = 0.75f;     //�R���C�_�[�|�W�V����Y
    int BColliderPosiZ = 0;         //�R���C�_�[�|�W�V����Z
    static const int BColliderSizeX = 1;    //�R���C�_�[�T�C�YX
    static const int BColliderSizeY = 1;    //�R���C�_�[�T�C�YY
    static const int BColliderSizeZ = 1;    //�R���C�_�[�T�C�YZ

    int min = -800;     //Y���W�����͈͂̍ŏ��l*100
    int max = 800;      //Y���W�����͈͂̍ő�l*100
    int flo = 1000.0f;  //Y���W������1000����
    int geneRand = 0;   //Y���W����
    float trPosiChangeX = 0.1;      //X���W�ω���
    static const int LEdge = -10;   //���[

public:
    //�R���X�g���N�^
    JumpUp(GameObject* parent);

    //�f�X�g���N�^
    ~JumpUp();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //Y���W��������
    float GenerateRand();

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

