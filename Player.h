#pragma once
#include "Engine/GameObject.h"
#include "Engine/Input.h"

class Player : public GameObject
{
private:
    int hModel_;    //���f���ԍ�
    //Transform Player_;

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
};

