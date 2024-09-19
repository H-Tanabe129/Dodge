#pragma once
class ValueManager
{
private:
	static const int FPS = 60;				//�t���[�����[�g(1�b��)
	int frame_ = 0;							//�t���[���J�E���^
	int currentTime_ = 0;					//���݂̎���
	int currentScore_ = 0;					//���݂̃X�R�A
	int increIntervalScore_ = 0;			//�X�R�A�����̊Ԋu
	static const int SCORE_UP_VALUE = 100;	//�X�R�A�̑�����
	static const int FRAME_DIV= 18;			//�t���[�������l
	//�R���X�g���N�^�@���ԂƃX�R�A��������
	ValueManager() : currentTime_(0), currentScore_(0) {}

public:
	//�V���O���g���C���X�^���X���擾
	static ValueManager& GetInstance();
	//���Ԃ����Z
	void AddTime();
	//���݂̎��Ԃ��擾
	int GetTime() const;
	//���Ԃ����Z�b�g
	void ResetTime();

	//�w�肳�ꂽ�ʃX�R�A�����Z
	void AddScore(int _amount);
	//���݂̃X�R�A���擾
	int GetScore() const;
	//�A�C�e���擾���̃X�R�A���Z
	void ItemScore();
	//�X�R�A�����Z�b�g
	void ResetScore();
};

