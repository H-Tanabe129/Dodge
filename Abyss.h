#pragma once
#include "Engine/GameObject.h"

class Abyss : public GameObject
{
private:
    int hModel_;    //���f���ԍ�
public:
    //�R���X�g���N�^
    Abyss(GameObject* parent);

    //�f�X�g���N�^
    ~Abyss();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

