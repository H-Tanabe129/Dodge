#pragma once
#include "Engine/GameObject.h"

class JumpUp : public GameObject
{
private:
    int hJump_;     //�W�����v�̓A�b�v�@�@��

    int trPosiX = 35;      //���f���|�W�V����X
    int trPosiY = 0;       //���f���|�W�V����Y
    int trPosiZ = 0;       //���f���|�W�V����Z
    const float BCollPosiX = 0.5;    //�R���C�_�[�|�W�V����X
    const float BCollPosiY = 0.5;    //�R���C�_�[�|�W�V����Y
    const float BCollPosiZ = 0;      //�R���C�_�[�|�W�V����Z
    const float BCollSizeX = 1.1;    //�R���C�_�[�T�C�YX
    const float BCollSizeY = 1.1;    //�R���C�_�[�T�C�YY
    const float BCollSizeZ = 1.1;    //�R���C�_�[�T�C�YZ

    float trPosiChangeX = 0.1;      //X���W�ω���
    float trRoteChangeY = 0.5;      //Y����]�ω���
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

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject* pTarget) override;
};

