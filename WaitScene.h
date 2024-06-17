#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Player.h"

class WaitScene : public GameObject
{
private:
    int hSound_;    //�摜�ԍ�
    Text* pText;
    Player* pPlayer_; // Player �N���X�̃|�C���^

    static const int CPosiX = 15;	//�J�����|�W�V����X
    static const int CPosiY = 3;	//�J�����|�W�V����Y
    static const int CPosiZ = -25;	//�J�����|�W�V����Z
    static const int CTarX = 15;	//�J�����^�[�Q�b�gX
    static const int CTarY = 0;		//�J�����^�[�Q�b�gY
    static const int CTarZ = 10;	//�J�����^�[�Q�b�gZ
    static const int scoreX = 30;    //���ԕ\��X
    static const int scoreY = 30;    //���ԕ\��Y
    static const int timeX = 30;     //�X�R�A�\��X
    static const int timeY = 60;     //�X�R�A�\��Y
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