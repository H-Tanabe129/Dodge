#pragma once
#include "Engine/GameObject.h"

enum Wall {
    TOGETHER = 0,
    UPPER,
    LOWER,
    UPPERLONG,
    LOWERLONG,
    MAX
};

class Stage : public GameObject
{
private:
    static const int FPS = 60;
    int frame = 0;
    int rd = 0;     //����
    int InitPosiX = 35;         //����Stage��X���W
    int InitPosiUpY = 7;        //�㏉��Stage��Y���W
    int InitPosiLoY = -6;       //������Stage��Y���W
    int InitPosiZ = 0;          //����Stage�̂y���W
    int SetPosiX = 35;          //�ǉ�Stage��X���W
    int SetPosiUpY = 3.5f;      //��ǉ�Stage��Y�������W
    int SetPosiLoY = -2.5f;     //���ǉ�Stage��Y�������W
    int SetPosiZ = 0;           //�ǉ�Stage��Z���W

    float trPosiChangeX = 0.1;      //X���W�ω���
    const float trChangeX = 0.05f;  //�A�C�e���擾�� X �ω�

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