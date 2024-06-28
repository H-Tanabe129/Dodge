#pragma once
#include "ItemBase.h"

class JumpUp : public ItemBase, public GameObject
{
private:
    int hJump_;         //�W�����v�A�b�v�@��

public:
    JumpUp(GameObject* parent);
    ~JumpUp();

    // ������
    void Initialize() override;

    // �X�V
    void Update() override;

    // �Փˏ���
    void OnCollision(GameObject* pTarget) override;
};
