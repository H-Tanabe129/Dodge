#pragma once
#include "Engine/GameObject.h"

class StageLo : public GameObject
{
private:
    int hModel_;    //���f���ԍ�

    static const int trPosiX = -5;      //���f���|�W�V����X
    static const int trPosiY = -6.5f;   //���f���|�W�V����Y
    static const int trPosiZ = 0;       //���f���|�W�V����Z
    static const int BCollPosiX = 0.1f;     //�R���C�_�[�|�W�V����X
    static const int BCollPosiY = 0;        //�R���C�_�[�|�W�V����Y
    static const int BCollPosiZ = 0;        //�R���C�_�[�|�W�V����Z
    static const int BCollSizeX = 1;    //�R���C�_�[�T�C�YX
    static const int BCollSizeY = 8;    //�R���C�_�[�T�C�YY
    static const int BCollSizeZ = 1;    //�R���C�_�[�T�C�YZ
    
    static const int LEdge = -10;

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