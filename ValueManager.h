#pragma once
class ValueManager
{
private:
	int time_;
	int score_;
	
	ValueManager() : time_(0), score_(0) {}

public:
	static ValueManager& GetInstance();
	  void AddTime(int _amount);
	  int GetTime() const;
	  void ResetTime();

	  void AddScore(int _amount);
	  int GetScore() const;
	  void ResetScore();
};

