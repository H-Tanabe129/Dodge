#pragma once
#include "Engine/GameObject.h"
class StageLo : public GameObject
{
private:
    int hModel_;    //���f���ԍ�
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