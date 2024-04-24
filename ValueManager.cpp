#include "ValueManager.h"

ValueManager& ValueManager::GetInstance() {
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	static ValueManager instance;
	return instance;
}

//����
void ValueManager::AddTime() {
	frame += 1;
	time_ = frame / FPS;
}

int ValueManager::GetTime() const {
	return time_;
}

void ValueManager::ResetTime() {
	time_ = 0;
}

//�X�R�A
void ValueManager::AddScore(int _amount) {
	if(frame%FPS == 0)
	score_ += _amount;
}

int ValueManager::GetScore() const {
	return score_;
}

void ValueManager::ResetScore() {
	score_ = 0;
}
