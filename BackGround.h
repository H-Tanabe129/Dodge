#pragma once
#include "Engine/GameObject.h"

enum Model {
    BUILDING_1 = 0,
    BUILDING_2,
    BUILDING_3,
    MAX
};

class BackGround : public GameObject
{
private:
    int hBuilding1_;    //���f���ԍ�
    int hBuilding2_;    //���f���ԍ�
    int hBuilding3_;    //���f���ԍ�

    const float trPosiX = 0;       //���f���|�W�V����X
    const float trPosiY = -4.0f;     //���f���|�W�V����Y
    const float trPosiZ = 5;        //���f���|�W�V����Z
    const float trSizeX = 1.0f;     //���f���T�C�YX
    const float trSizeY = 1.0f;     //���f���T�C�YY
    const float trSizeZ = 1.0f;     //���f���T�C�YZ

    static const int LEdge = -10;   // ���E���[
    float trPosiChangeX = 0.1;      // X���W�ω���

public:
    //�R���X�g���N�^
    BackGround(GameObject* parent);

    //�f�X�g���N�^
    ~BackGround();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
