#pragma once
#include "Engine/GameObject.h"

class StageLo : public GameObject
{
private:
    int hModel_;    //���f���ԍ�

    static const int trPosiX = -5;      //���f���|�W�V����X
    static const int trPosiY = -6.5f;   //���f���|�W�V����Y
    static const int trPosiZ = 0;       //���f���|�W�V����Z
    static const int BColliderPosiX = 0.1f;     //�R���C�_�[�|�W�V����X
    static const int BColliderPosiY = 0;        //�R���C�_�[�|�W�V����Y
    static const int BColliderPosiZ = 0;        //�R���C�_�[�|�W�V����Z
    static const int BColliderSizeX = 1;    //�R���C�_�[�T�C�YX
    static const int BColliderSizeY = 8;    //�R���C�_�[�T�C�YY
    static const int BColliderSizeZ = 1;    //�R���C�_�[�T�C�YZ
    
    static const int LEdge = -10;
    float trPosiChangeX = 0.1;      //X���W�ω���

public:
    //�R���X�g���N�^
    StageLo(GameObject* parent);

    //�f�X�g���N�^
    ~StageLo();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};