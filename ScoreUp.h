#pragma once
#include "ItemBase.h"

class ScoreUp : public ItemBase
{
private:
    int hScore_;        //�X�R�A�A�b�v�@��

public:
    ScoreUp(GameObject* parent);
    ~ScoreUp();

    // ������
    void Initialize() override;

    // �X�V
    void Update() override;

    // �Փˏ���
    void OnCollision(GameObject* pTarget) override;
};
