#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Player : public GameObject
{
private:
    int hModel_;    //���f���ԍ�
    int hSound_;    //�T�E���h�ԍ�
    Text* pText;
    const int END = 12;
    static const int posiZ = -1;
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

