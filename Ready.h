#pragma once

#include "Engine/GameObject.h"

class Ready : public GameObject
{
private:
	int hImage_;
public:
	Ready(GameObject* parent);
	~Ready();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	bool Finished();
};

