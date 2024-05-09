#pragma once
#include "Engine/GameObject.h"

class SpeedDown : public GameObject
{
private:
    int hSpeed_;    //�X�s�[�h�_�E��

    static const int trPosiX = 35;      //���f���|�W�V����X
    static const int trPosiY = -6.5f;   //���f���|�W�V����Y
    static const int trPosiZ = 0;       //���f���|�W�V����Z
    static const int BColliderPosiX = 0.1f;     //�R���C�_�[�|�W�V����X
    static const int BColliderPosiY = 0;        //�R���C�_�[�|�W�V����Y
    static const int BColliderPosiZ = 0;        //�R���C�_�[�|�W�V����Z
    static const int BColliderSizeX = 1;    //�R���C�_�[�T�C�YX
    static const int BColliderSizeY = 8;    //�R���C�_�[�T�C�YY
    static const int BColliderSizeZ = 1;    //�R���C�_�[�T�C�YZ

public:
    //�R���X�g���N�^
    SpeedDown(GameObject* parent);

    //�f�X�g���N�^
    ~SpeedDown();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
