#pragma once
class ValueManager
{
private:
	static const int FPS = 60;
	int frame = 0;
	int time_ = 0;
	int score_ = 0;
	ValueManager() : time_(0), score_(0) {}

public:
	static ValueManager& GetInstance();
	  void AddTime();
	  int GetTime() const;
	  void ResetTime();

	  void AddScore(int _amount);
	  int GetScore() const;
	  void ResetScore();
};

