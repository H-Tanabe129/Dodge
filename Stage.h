#pragma once
#include "Engine/GameObject.h"

enum Obstacle {
    TOGETHER = 0,
    UPPERFRONT,
    LOWERFRONT,
    UPPER,
    LOWER,
    MAX
};

class Stage : public GameObject
{
private:
    int hModel_;    //���f���ԍ�

    static const int FPS = 60;
    int frame = 0;
    int rd = 0;
public:
    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};