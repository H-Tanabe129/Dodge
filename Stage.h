#pragma once
#include "Engine/GameObject.h"

class Stage : public GameObject
{
private:
    int hModelU_;    //���f���ԍ�
    int hModelL_;    //���f���ԍ�
    Transform StaUpper;
    Transform StaLower;
public:
    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};