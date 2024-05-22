#pragma once
#include "Engine/GameObject.h"

class Player : public GameObject
{
private:
    int hModel_;    //���f���ԍ�
    int hSound_;    //�T�E���h�ԍ�

    static const int SColliderX = 1.0f;    //�R���C�_�[X��
    static const int SColliderY = 1.0f;    //�R���C�_�[Y��
    static const int SColliderZ = 1.0f;    //�R���C�_�[Z��
    static const int radius = 1.02f;       //�R���C�_�[���a
    float veloIni = 0.0f;       //�d�͏����l
    float veloIncre = 0.15f;    //�d�͑�����
    float veloDecre = 0.05f;    //�d�͌�����

    const float initialVelocity = 0.0f; // �ŏ��̑��x�i�Î~��ԁj
    const float jumpVelocity = 10.0f;   // �W�����v�������x
    const float gravity = 0.5f;         // �d�͉����x
    const float hoverHeight = 10.0f;    // �����ʒu�̍���
    const float groundLevel = -FLT_MAX; // �n�ʂ̍����i����͖����ɒႭ�ݒ�j
    int posiY = 0.0f;


    static const int edge = 12;     //��ʒ[
    static const int posiZ = -1;    //�v���C���[�\��Z
    static const int scoreX = 30;    //���ԕ\��X
    static const int scoreY = 30;    //���ԕ\��Y
    static const int timeX = 30;     //�X�R�A�\��X
    static const int timeY = 60;     //�X�R�A�\��Y

public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    void Jump();

    void ApplyGravity();

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject *pTarget) override;
};

