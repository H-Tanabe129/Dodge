#pragma once
#include "Engine/GameObject.h"

class StageUp : public GameObject
{
private:
    int hModel_;    //���f���ԍ�
public:
    //�R���X�g���N�^
    StageUp(GameObject* parent);

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

    void GetTransform(Transform& transform);
};