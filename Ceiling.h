#pragma once
#include "Engine/GameObject.h"

class Ceiling : public GameObject
{
private:
    int hModel_;    //���f���ԍ�
public:
    //�R���X�g���N�^
    Ceiling(GameObject* parent);

    //�f�X�g���N�^
    ~Ceiling();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

