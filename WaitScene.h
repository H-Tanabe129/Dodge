#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Player.h"

class WaitScene : public GameObject
{
private:
    Text* pText;
    Player* pPlayer_; // Player �N���X�̃|�C���^
    Transform picTrans_;        //�w�i�摜
    Transform pushTrans_;       //PushSpace
    Transform buildTrans1_;     //�w�i���f��1
    Transform buildTrans2_;     //�w�i���f��2

    int hReady_;   //�摜�ԍ�(Ready)
    int hBack_;    //�摜�ԍ�(�w�i)
    int hPush_;    //�摜�ԍ�(Push)
    int hBuilding1_;    //���f���ԍ�
    int hBuilding2_;    //���f���ԍ�

    static const int FPS = 60;
    int frame = 0;
    static const int FLASH_INTERVAL = 5;    //�_�ł̊Ԋu

    static const int CAMERA_POS_X = 15;	    //�J�����|�W�V����X
    static const int CAMERA_POS_Y = 3;	    //�J�����|�W�V����Y
    static const int CAMERA_POS_Z = -25;	//�J�����|�W�V����Z
    static const int CAMERA_TARGET_X = 15;  //�J�����^�[�Q�b�gX
    static const int CAMERA_TARGET_Y = 0;	//�J�����^�[�Q�b�gY
    static const int CAMERA_TARGET_Z = 10;	//�J�����^�[�Q�b�gZ

    const float trPosiX = -16.0f;       //���f���|�W�V����X
    const float trBackPosiX = 23.0f;    //�ヂ�f���|�W�V����X
    const float trPosiY = -8.0f;        //���f���|�W�V����Y
    const float trPosiZ = 8.0f;         //���f���|�W�V����Z

    static const int PUSH_POSI_X = 0;   //�摜�|�W�V����X
    const float PUSH_POSI_Y = -0.5f;    //�摜�|�W�V����Y
    static const int PUSH_POSI_Z = 0;   //�摜�|�W�V����Z
    int pushAlpha = 255;                //�摜�����x
    bool isFlashing = false;

    static const int PIC_POS_X = 0;      //�w�i�|�W�V����X
    static const int PIC_POS_Y = 0;      //�w�i�|�W�V����Y
    static const int PIC_POS_Z = 0;      //�w�i�|�W�V����Z
    static const int PIC_SCALE_X = 6;    //�w�i�T�C�YX
    static const int PIC_SCALE_Y = 5;    //�w�i�T�C�YY
    static const int PIC_SCALE_Z = 1;    //�w�i�T�C�YZ
    static const int PIC_ALPHA = 128;    //�w�i�����x

    static const int SCORE_POS_X = 30;   //���ԕ\��X
    static const int SCORE_POS_Y = 30;   //���ԕ\��Y
    static const int TIME_POS_X = 30;    //�X�R�A�\��X
    static const int TIME_POS_Y = 60;    //�X�R�A�\��Y

    const float veloIni = 0.0f; //�d�͏����l
    float veloIncre = 0.15f;    //�d�͑�����
    float veloDecre = 0.02f;    //�d�͌�����

public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    WaitScene(GameObject* parent);
    ~WaitScene();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};