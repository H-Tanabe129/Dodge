#include "ValueManager.h"

ValueManager& ValueManager::GetInstance() {
	// TODO: return ステートメントをここに挿入します
	static ValueManager instance;
	return instance;
}

//時間
void ValueManager::AddTime(int _amount) {
	time_ += _amount;
}

int ValueManager::GetTime() const {
	return time_;
}

void ValueManager::ResetTime() {
	time_ = 0;
}

//スコア
void ValueManager::AddScore(int _amount) {
	score_ += _amount;
}

int ValueManager::GetScore() const {
	return score_;
}

void ValueManager::ResetScore() {
	score_ = 0;
}
