#pragma once
#include "Engine/GameObject.h"

class ScoreUp : public GameObject
{
private:
    int hScore_;    //�X�R�A�A�b�v  ���F
    int hSound_;

    int trPosiX = 35;      //���f���|�W�V����X
    int trPosiY = 0;       //���f���|�W�V����Y
    int trPosiZ = 0;       //���f���|�W�V����Z
    const float SCollPosiX = 0.0f;    //�R���C�_�[�|�W�V����X
    const float SCollPosiY = 0.5f;    //�R���C�_�[�|�W�V����Y
    const float SCollPosiZ = 0.0f;    //�R���C�_�[�|�W�V����Z
    const float SCollSizeX = 0.7f;    //�R���C�_�[�T�C�Y

    float trPosiChangeX = 0.1;      //X���W�ω���
    float trRoteChangeY = 0.5;      //Y����]�ω���
    static const int LEdge = -10;   //���E���[

public:
    //�R���X�g���N�^
    ScoreUp(GameObject* parent);

    //�f�X�g���N�^
    ~ScoreUp();

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

