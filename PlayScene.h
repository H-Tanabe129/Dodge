#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//�e�X�g�V�[�����Ǘ�����N���X
class PlayScene : public GameObject
{
private:
	static const int FPS = 60;
	int frame = 0;
	int hSound_;    //�T�E���h�ԍ�
	Text* pText;

	static const int CPosiX = 15;	//�J�����|�W�V����X  //test == 35, 3, 0    -25
	static const int CPosiY = 3;	//�J�����|�W�V����Y
	static const int CPosiZ = -25;	//�J�����|�W�V����Z
	static const int CTarX = 15;	//�J�����^�[�Q�b�gX
	static const int CTarY = 0;		//�J�����^�[�Q�b�gY
	static const int CTarZ = 10;	//�J�����^�[�Q�b�gZ

	static const int scoreX = 30;    //���ԕ\��X
	static const int scoreY = 30;    //���ԕ\��Y
	static const int timeX = 30;     //�X�R�A�\��X
	static const int timeY = 60;     //�X�R�A�\��Y
	int score = 20;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};