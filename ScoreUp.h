#pragma once
#include "ItemBase.h"

class ScoreUp : public ItemBase
{
private:
    int hScore_;

public:
    ScoreUp(GameObject* parent);
    ~ScoreUp();

    // ‰Šú‰»
    void Initialize() override;

    // XV
    void Update() override;

    // Õ“Ëˆ—
    void OnCollision(GameObject* pTarget) override;
};
