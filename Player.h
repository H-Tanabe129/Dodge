#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Player : public GameObject
{
private:
    int hModel_;    //���f���ԍ�
    int hSound_;    //�T�E���h�ԍ�
    Text* pText;

    static const int SphereColliderX = 1.0f;    //�R���C�_�[X��
    static const int SphereColliderY = 1.0f;    //�R���C�_�[Y��
    static const int SphereColliderZ = 1.0f;    //�R���C�_�[Z��
    static const int radius = 1.02f;            //�R���C�_�[���a
    float veloIni = 0.0f;       //�d�͏����l
    float veloIncre = 0.15f;    //�d�͑�����
    float veloDecre = 0.02f;    //�d�͌�����
    static const int edge = 12;     //��ʒ[
    static const int posiZ = -1;    //�v���C���[�\��Z
    static const int textX = 30;    //�����\��X
    static const int textY = 30;    //�����\��Y
    int score;

public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

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

