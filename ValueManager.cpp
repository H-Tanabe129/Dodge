#include "ValueManager.h"

ValueManager& ValueManager::GetInstance() {
	// TODO: return ステートメントをここに挿入します
	static ValueManager instance;
	return instance;
}

//時間
void ValueManager::AddTime() {
	frame_ += 1;
	time_ = frame_ / FPS;
}

int ValueManager::GetTime() const {
	return time_;
}

void ValueManager::ResetTime() {
	frame_ = 0;
	time_ = 0;
}

//スコア
void ValueManager::AddScore(int _amount) {
	int scoreInc_ = frame_ % 15;
	if(scoreInc_ == 0)
	score_ += _amount;
}

int ValueManager::GetScore() const {
	return score_;
}

void ValueManager::ItemScore() {
	score_ = score_ + 100;
}

void ValueManager::ResetScore() {
	score_ = 0;
}
