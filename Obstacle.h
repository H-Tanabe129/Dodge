#pragma once
#include "Engine/GameObject.h"

class Obstacle : public GameObject
{
public:
    //�R���X�g���N�^
    Obstacle(GameObject* parent);

    //�f�X�g���N�^
    ~Obstacle();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};