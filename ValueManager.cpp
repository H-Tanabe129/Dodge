#include "ValueManager.h"

ValueManager& ValueManager::GetInstance() {
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	static ValueManager instance_;
	return instance_;
}

//����
void ValueManager::AddTime() {
	frame_ += 1;
	currentTime_ = frame_ / FPS;
}

int ValueManager::GetTime() const {
	return currentTime_;
}

void ValueManager::ResetTime() {
	frame_ = 0;
	currentTime_ = 0;
}

//�X�R�A
void ValueManager::AddScore(int _amount) {
	int increIntervalScore_ = frame_ % FRAME_DIV;
	if(increIntervalScore_ == 0)
	currentScore_ += _amount;
}

int ValueManager::GetScore() const {
	return currentScore_;
}

void ValueManager::ItemScore() {
	currentScore_ = currentScore_ + SCORE_UP_VALUE;
}

void ValueManager::ResetScore() {
	currentScore_ = 0;
}
