#pragma once
#include "Engine/GameObject.h"

class StageLo : public GameObject
{
private:
    int hStageLo_;    //���f���ԍ�

    const float loPosX = -5.0f;         //���f���|�W�V����X
    const float loPosY = -10.0f;        //���f���|�W�V����Y
    const float loPosZ = 0.0f;          //���f���|�W�V����Z
    const float loSizeX = 1.0f;         //���f���T�C�YX
    const float loSizeY = 0.9f;         //���f���T�C�YY
    const float loSizeZ = 1.0f;         //���f���T�C�YZ

    const float boxCollPosX = 0.0f;     //�R���C�_�[�|�W�V����X
    const float boxCollPosY = 4.1f;     //�R���C�_�[�|�W�V����Y
    const float boxCollPosZ = 0.0f;     //�R���C�_�[�|�W�V����Z
    const float boxCollSizeX = 1.75f;   //�R���C�_�[�T�C�YX
    const float boxCollSizeY = 8.3f;    //�R���C�_�[�T�C�YY
    const float boxCollSizeZ = 1.7f;    //�R���C�_�[�T�C�YZ

    static const int WORLD_EDGE = -10;  // ���E���[
    float posChangeX = 0.1f;          // X���W�ω���

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