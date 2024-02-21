#pragma once
#include "Engine/GameObject.h"

class StageUp : public GameObject
{
private:
    int hModel_;    //���f���ԍ�
    int width;
    int height;
    int depth;
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

    DirectX::XMFLOAT3 GetScale() const override { return GameObject::GetScale(); }
};