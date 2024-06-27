#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class GameOverScene : public GameObject
{
private:
    int hPict_;     //�摜�ԍ�
    int hSound_;    //�T�E���h
    Text* pText;

    static const int scoreX = 930;    //���ԕ\��X
    static const int scoreY = 450;    //���ԕ\��Y
    static const int timeX = 930;     //�X�R�A�\��X
    static const int timeY = 500;     //�X�R�A�\��Y
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    GameOverScene(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};