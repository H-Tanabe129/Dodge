#pragma once
#include "Engine/GameObject.h"

class Item : public GameObject
{
private:
    int hSpeed_;    //�X�s�[�h�_�E��
    int hJump_;     //�W�����v�̓A�b�v
    int hScore_;    //�X�R�A�A�b�v
public:
    //�R���X�g���N�^
    Item(GameObject* parent);

    //�f�X�g���N�^
    ~Item();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject *pTarget) override;
};