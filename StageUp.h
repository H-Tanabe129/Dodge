#pragma once
#include "Engine/GameObject.h"

class StageUp : public GameObject
{
private:
    int hModel_;    //���f���ԍ�

    const float trPosiX = -5;       //���f���|�W�V����X
    const float trPosiY = 3.0f;     //���f���|�W�V����Y
    const float trPosiZ = 0;        //���f���|�W�V����Z
    const float trSizeX = 0.01f;    //���f���T�C�YX
    const float trSizeY = 0.017f;   //���f���T�C�YY
    const float trSizeZ = 0.01f;    //���f���T�C�YZ
    const float BCollPosiX = 0;     //�R���C�_�[�|�W�V����X
    const float BCollPosiY = 3.9f;  //�R���C�_�[�|�W�V����Y
    const float BCollPosiZ = 0;     //�R���C�_�[�|�W�V����Z
    const float BCollSizeX = 1.75f; //�R���C�_�[�T�C�YX
    const float BCollSizeY = 7.8f;  //�R���C�_�[�T�C�YY
    const float BCollSizeZ = 1.7f;  //�R���C�_�[�T�C�YZ

    static const int LEdge = -10;   // ���E���[
    float trPosiChangeX = 0.1;      // X���W�ω���

public:
    //�R���X�g���N�^
    StageUp(GameObject * parent);

    //�f�X�g���N�^
    ~StageUp();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
