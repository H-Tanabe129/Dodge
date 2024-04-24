#include "Ready.h"
#include "Engine/Image.h"

namespace {
	float startX; //�ړ��J�nX���W
	float endX;   //�ړ��I��X���W
	float totalTime;  //�ړ�����
	float currentTime;  //���݂̎���

	int seq_line; // �����s���Ă���s
	float seq_time; // �V�[�P���X�����s���Ă��鎞��
	enum ACT { //��邱�Ƃ��R�}���h��
		A_SLIDEIN = 1,
		A_WAIT,
		A_SLIDEOUT,
		A_END
	};

	struct Sequence {
		float time; // ����
		int action; // ��邱��
		float param; // �K�v�Ȓl
	};

	Sequence tbl[] = {
		{0.0f, A_SLIDEIN, 5.0f}, //�܂��̓X���C�h�C�� 
		{3.0f, A_WAIT, 0.0f/*�Ӗ��Ȃ�*/}, // �P�b�҂��Ă���
		{4.0f, A_SLIDEOUT, -5.0f}, // �X���C�h�A�E�g
		{5.0f, A_END, 0.0f} // �����ŏ�����
	};
	ACT currentAction; // �����s���Ă���A�N�V����
	bool canMove; // �ړ��ł���
};

Ready::Ready(GameObject* parent)
	:GameObject(parent, "Ready"), hImage_(-1)
{
	seq_line = -1;
	seq_time = 0.0f;
	canMove = false;
}

Ready::~Ready()
{
}

void Ready::Initialize()
{
	hImage_ = Image::Load("Ready.png");
	startX = 5.0f;
	endX = 0;
	totalTime = 3.0f;
	currentTime = 0.0f;
}

float easeInCubic(float x) {
	return x * x * x;
}

void Ready::Update()
{
	seq_time += 1.0f / 60.0f; // ���Ԃ�i�߂�
	if (seq_time >= tbl[seq_line + 1].time) { // ���̍s�����s����
		seq_line++;
		switch (tbl[seq_line].action) {
		case A_END:
			KillMe();
			break;
		case A_SLIDEIN:
			startX = tbl[seq_line].param; // param����0�Ɍ������Ĉړ�
			endX = 0;
			totalTime = tbl[seq_line + 1].time - seq_time;
			currentTime = 0.0f;
			break;
		case A_WAIT:
			startX = transform_.position_.x;
			endX = transform_.position_.x;
			totalTime = tbl[seq_line + 1].time - seq_time;
			currentTime = 0.0f;
			break;
		case A_SLIDEOUT:
			canMove = true;
			startX = transform_.position_.x;
			endX = tbl[seq_line].param;
			totalTime = tbl[seq_line + 1].time - seq_time;
			currentTime = 0.0f;
			break;
		}
		// ���̍s�̎��s������
	}
	currentTime += 1.0f / 60.0f;  //1�t���[�����̎��Ԃ�i�܂���
	if (currentTime > totalTime)
		currentTime = totalTime;
	float t = currentTime / totalTime;//������0.0�`1.0�͈̔͂ɂ���
	float val = easeInCubic(t);	//�C�[�W���O�֐����Ă�(t) �Ԃ��Ă����l��0.0�`1.0
	//val�����Ƃ�transform_.position_��ݒ肷��
	transform_.position_.x = val * (endX - startX) + startX;
}

void Ready::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

bool Ready::Finished()
{
	return canMove;
}

//�C�[�W���O�@0.0�`1.0��⊮����Ȑ�
//�X�v���C���@�S�ȏ�̓_�����炩�ɒʂ�Ȑ�