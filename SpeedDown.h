#pragma once
#include "ItemBase.h"
#include "Stage.h"

class SpeedDown : public ItemBase
{
private:
    int hSpeed_;        //�X�s�[�h�_�E���@�I�����W
    Stage* pStage_;

public:
    SpeedDown(GameObject* parent);
    ~SpeedDown();

    // ������
    void Initialize() override;

    // �X�V
    void Update() override;

    //���
    void Release() override;

    // �Փˏ���
    void OnCollision(GameObject* pTarget) override;
};
