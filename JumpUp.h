#pragma once
#include "Engine/GameObject.h"

class JumpUp : public GameObject
{
private:
    int hJump_;     //�W�����v�̓A�b�v

public:
    //�R���X�g���N�^
    JumpUp(GameObject* parent);

    //�f�X�g���N�^
    ~JumpUp();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

