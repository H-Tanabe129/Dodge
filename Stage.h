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
    int InitPosiUpY = 3;        //�㏉��Stage��Y���W
    int InitPosiLoY = -10;      //������Stage��Y���W
    int InitPosiZ = 0;          //����Stage��Z���W
    int SetPosiX = 35;          //�ǉ�Stage��X���W
    int SetPosiUpY = -1;        //��ǉ�Stage��Y�������W
    int SetPosiLoY = -6;        //���ǉ�Stage��Y�������W
    int SetPosiZ = 0;           //�ǉ�Stage��Z���W

    int SetSizeX = 0.01f;       //�ǉ�Stage��X�T�C�Y
    int SetSizeY = 0.005f;       //�ǉ�Stage��Y�T�C�Y
    int SetSizeZ = 0.01f;       //�ǉ�Stage��Z�T�C�Y

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