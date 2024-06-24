#pragma once
#include "Engine/GameObject.h"

class Player : public GameObject
{
private:
    int hModel_;    // ���f���ԍ�
    int hSound_;    // �T�E���h�ԍ�
    int hBGM_;      // �T�E���h�ԍ�

    const float SColliderX = 1.0f;    // �R���C�_�[X��
    const float SColliderY = 1.0f;    // �R���C�_�[Y��
    const float SColliderZ = 1.0f;    // �R���C�_�[Z��
    const float radius = 1.02f;       // �R���C�_�[���a
    float veloIni = 0.0f;             // �d�͏����l
    float veloIncre = 0.15f;          // �d�͑�����
    float veloDecre = 0.02f;          // �d�͌�����

    static const int edge = 12;       // ��ʒ[
    float posiY = 0.0f;               // �v���C���[�\��Y
    static const int posiZ = -1;      // �v���C���[�\��Z
    static const int scoreX = 30;     // ���ԕ\��X
    static const int scoreY = 30;     // ���ԕ\��Y
    static const int timeX = 30;      // �X�R�A�\��X
    static const int timeY = 60;      // �X�R�A�\��Y

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

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject *pTarget) override;
};

