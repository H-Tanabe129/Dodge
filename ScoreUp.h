#pragma once
#include "Engine/GameObject.h"

class ScoreUp : public GameObject
{
private:
    int hScore_;    //�X�R�A�A�b�v

    static const int BColliderPosiX = 0.1f;     //�R���C�_�[�|�W�V����X
    static const int BColliderPosiY = 0;        //�R���C�_�[�|�W�V����Y
    static const int BColliderPosiZ = 0;        //�R���C�_�[�|�W�V����Z
    static const int BColliderSizeX = 1;    //�R���C�_�[�T�C�YX
    static const int BColliderSizeY = 1;    //�R���C�_�[�T�C�YY
    static const int BColliderSizeZ = 1;    //�R���C�_�[�T�C�YZ
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

