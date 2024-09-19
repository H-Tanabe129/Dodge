#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"

class BackGround : public GameObject
{
private:
    Transform picTrans_;
    Transform buildTrans1_;
    Transform buildTrans2_;
    Transform buildTrans3_;

    bool isPushed = false;
    static const int FPS = 60;
    int frame = 0;
    int rd = 0;     //����

    int hBack_;    //�摜�ԍ�
    int hBuilding1_;    //���f���ԍ�
    int hBuilding2_;    //���f���ԍ�
    int hBuilding3_;    //���f���ԍ�

    const float trPosiX = -16;      //���f���|�W�V����X
    const float trMidPosiX = 23;    //�����f���|�W�V����X
    const float trBackPosiX = 62;   //�ヂ�f���|�W�V����X
    const float trPosiY = -8.0f;    //���f���|�W�V����Y
    const float trPosiZ = 8;        //���f���|�W�V����Z
    const float loopPosiX = 59;   //���[�v�ʒu

    static const int PIC_POS_X = 0;      //�w�i�|�W�V����X
    static const int PIC_POS_Y = 0;      //�w�i�|�W�V����Y
    static const int PIC_POS_Z = -3;     //�w�i�|�W�V����Z
    const float PIC_SCALE_X = 6.0f;       //�w�i�T�C�YX
    const float PIC_SCALE_Y = 5.0f;       //�w�i�T�C�YY
    const float PIC_SCALE_Z = 1.0f;       //�w�i�T�C�YZ
    static const int PIC_ALPHA = 128;    //�w�i�����x

    static const int WORLD_EDGE = -58;   // ���E���[
    float posChangeX = 0.1f;      // X���W�ω���

public:
    //�R���X�g���N�^
    BackGround(GameObject* parent);

    //�f�X�g���N�^
    ~BackGround();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};
