#pragma once
#include "Engine/GameObject.h"

class StageLo : public GameObject
{
private:
    int hModel_;    //���f���ԍ�

    const float trPosiX = -5;      //���f���|�W�V����X
    const float trPosiY = -6.5f;   //���f���|�W�V����Y
    const float trPosiZ = 0;       //���f���|�W�V����Z
    const float trSizeX = 0.01f;    //���f���T�C�YX
    const float trSizeY = 0.02f;    //���f���T�C�YY
    const float trSizeZ = 0.01f;    //���f���T�C�YZ
    const float BCollPosiX = 0.1f;     //�R���C�_�[�|�W�V����X
    const float BCollPosiY = -2;        //�R���C�_�[�|�W�V����Y
    const float BCollPosiZ = 0;        //�R���C�_�[�|�W�V����Z
    const float BCollSizeX = 1.5;   //�R���C�_�[�T�C�YX
    const float BCollSizeY = 8;     //�R���C�_�[�T�C�YY
    const float BCollSizeZ = 1.5;   //�R���C�_�[�T�C�YZ

    static const int LEdge = -10;   // ���E���[
    float trPosiChangeX = 0.1;      // X���W�ω���

public:
    //�R���X�g���N�^
    StageLo(GameObject * parent);

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