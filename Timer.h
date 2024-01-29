#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Timer : public GameObject
{
	int frame;  //�c�莞�Ԃ𐔂���ϐ�
	Text* num;
	bool active;  //true�̎��ɃJ�E���g�_�E������
	int drawX, drawY;
	float M;  //�����̃J�E���g
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Timer(GameObject* parent);
	~Timer();

	//������
	void Initialize() override;
	//�X�V
	void Update() override;
	//�`��
	void Draw() override;
	//�J��
	void Release() override;

	/// <summary>
	/// �������Ԃ�ݒ肷��
	/// </summary>
	/// <param name="seconds">��������</param>
	void SetLimit(float seconds);

	/// <summary>
	/// �^�C�}�[���J�n
	/// </summary>
	void Start();

	/// <summary>
	/// �^�C�}�[���~
	/// </summary>
	void Stop();

	/// <summary>
	/// �^�C�}�[���I��������
	/// </summary>
	/// <returns>�I��������true</returns>
	bool IsFinished();

	/// <summary>
	/// ��ʂ̕\���ʒu���w�肷��
	/// </summary>
	/// <param name="x">X���W</param>
	/// <param name="y">Y���W</param>
	void DrawPosition(int x, int y) { drawX = x, drawY = y; }
};