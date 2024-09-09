#pragma once
#include "Engine/GameObject.h"

class StageLoMore : public GameObject
{
private:
    int hStageLoMore_;    //���f���ԍ�

    float trPosiX = -7.0f;              //���f���|�W�V����X
    float trPosiY = 3.0f;               //���f���|�W�V����Y
    const float trPosiZ = 0.0f;         //���f���|�W�V����Z
    const float trSizeX = 1.0f;         //���f���T�C�YX
    const float trSizeY = 0.9f;         //���f���T�C�YY
    const float trSizeZ = 1.0f;         //���f���T�C�YZ
    const float boxCollPosX = 0.0f;     //�R���C�_�[�|�W�V����X
    const float boxCollPosY = 5.7f;     //�R���C�_�[�|�W�V����Y
    const float boxCollPosZ = 0.0f;     //�R���C�_�[�|�W�V����Z
    const float boxCollSizeX = 1.75f;   //�R���C�_�[�T�C�YX
    const float boxCollSizeY = 10.4f;    //�R���C�_�[�T�C�YY
    const float boxCollSizeZ = 1.7f;    //�R���C�_�[�T�C�YZ

    static const int WORLD_EDGE = -10;  // ���E���[
    const float posChangeX = 0.1f;      // X���W�ω���

public:
    //�R���X�g���N�^
    StageLoMore(GameObject* parent);

    //�f�X�g���N�^
    ~StageLoMore();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
