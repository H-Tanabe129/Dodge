#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Player.h"

class WaitScene : public GameObject
{
private:
    Text* pText;
    Player* pPlayer_; // Player �N���X�̃|�C���^
    Transform picTrans_;
    Transform pushTrans_;
    Transform buildTrans1_;
    Transform buildTrans2_;

    int hPict_;    //�摜�ԍ�
    int hBack_;    //�摜�ԍ�
    int hPush_;    //�摜�ԍ�
    int hBuilding1_;    //���f���ԍ�
    int hBuilding2_;    //���f���ԍ�

    static const int FPS = 60;
    static const int flash = 5;
    int frame = 0;

    static const int CPosiX = 15;	//�J�����|�W�V����X
    static const int CPosiY = 3;	//�J�����|�W�V����Y
    static const int CPosiZ = -25;	//�J�����|�W�V����Z
    static const int CTarX = 15;	//�J�����^�[�Q�b�gX
    static const int CTarY = 0;		//�J�����^�[�Q�b�gY
    static const int CTarZ = 10;	//�J�����^�[�Q�b�gZ

    const float trPosiX = -16;      //���f���|�W�V����X
    const float trBackPosiX = 23;   //�ヂ�f���|�W�V����X
    const float trPosiY = -8.0f;    //���f���|�W�V����Y
    const float trPosiZ = 8;        //���f���|�W�V����Z

    static const int pushPosiX = 0;     //�摜�|�W�V����X
    const float pushPosiY = -0.5f;      //�摜�|�W�V����Y
    static const int pushPosiZ = 0;     //�摜�|�W�V����Z
    int pushAlpha = 255;   //�摜�����x
    bool isFlashing = false;

    static const int picPosiX = 0;      //�w�i�|�W�V����X
    static const int picPosiY = 0;      //�w�i�|�W�V����Y
    static const int picPosiZ = 0;      //�w�i�|�W�V����Z
    const float picScaleX = 6.0f;       //�w�i�T�C�YX
    const float picScaleY = 5.0f;       //�w�i�T�C�YY
    const float picScaleZ = 1.0f;       //�w�i�T�C�YZ
    static const int picAlpha = 128;    //�w�i�����x

    static const int scoreX = 30;   //���ԕ\��X
    static const int scoreY = 30;   //���ԕ\��Y
    static const int timeX = 30;    //�X�R�A�\��X
    static const int timeY = 60;    //�X�R�A�\��Y

    float veloIni = 0.0f;       //�d�͏����l
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