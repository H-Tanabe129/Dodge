#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

//�e�X�g�V�[�����Ǘ�����N���X
class PlayScene : public GameObject
{
private:
	static const int FPS = 60;
	int frame = 0;

	Text* pText;
	int hBGM_;      // �T�E���h�ԍ�

	static const int CAMERA_POS_X = 15;		//�J�����|�W�V����X
	static const int CAMERA_POS_Y = 3;		//�J�����|�W�V����Y
	static const int CAMERA_POS_Z = -25;	//�J�����|�W�V����Z
	static const int CAMERA_TARGET_X = 15;	//�J�����^�[�Q�b�gX
	static const int CAMERA_TARGET_Y = 0;	//�J�����^�[�Q�b�gY
	static const int CAMERA_TARGET_Z = 10;	//�J�����^�[�Q�b�gZ

	static const int SCORE_POS_X = 30;		//���ԕ\��X
	static const int SCORE_POS_Y = 30;		//���ԕ\��Y
	static const int TIME_POS_X = 30;		//�X�R�A�\��X
	static const int TIME_POS_Y = 60;		//�X�R�A�\��Y
	static const int SCORE_INCREASE = 20;	//�X�R�A������

	static const int VSet = 1;         //BGM���ʒ���

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

	void KillAllChildren();
};