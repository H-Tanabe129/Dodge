#pragma once
#include "Engine/GameObject.h"

class ScoreUp : public GameObject
{
private:
    int hScore_;    //�X�R�A�A�b�v  ���F
    int hSound_;    //�l����

    int scoreUpPosX = 35;                       //���f���|�W�V����X
    int scoreUpPosY = 0;                        //���f���|�W�V����Y
    static const int SCORE_UP_POS_Z = 0;        //���f���|�W�V����Z
    const float sphCollPosX = 0.0f;    //�R���C�_�[�|�W�V����X
    const float sphCollPosY = 0.5f;    //�R���C�_�[�|�W�V����Y
    const float sphCollPosZ = 0.0f;    //�R���C�_�[�|�W�V����Z
    const float sphCollSizeX = 0.7f;   //�R���C�_�[�T�C�Y

    const float posChangeX = 0.1f;       //X���W�ω���
    const float trRoteChangeY = 0.5f;       //Y����]�ω���
    static const int WORLD_EDGE = -10;      //���E���[

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

