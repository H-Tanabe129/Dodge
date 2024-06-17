#pragma once
class ValueManager
{
private:
	static const int FPS = 60;
	int frame_ = 0;
	int time_ = 0;
	int score_ = 0;
	int scoreUp_ = 100;
	int scoreInc_ = 0;
	int frameDiv_= 18;
	ValueManager() : time_(0), score_(0) {}

public:
	static ValueManager& GetInstance();
	  void AddTime();
	  int GetTime() const;
	  void ResetTime();

	  void AddScore(int _amount);
	  int GetScore() const;
	  void ItemScore();
	  void ResetScore();
};

