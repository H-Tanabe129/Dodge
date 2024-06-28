#pragma once
#include "ItemBase.h"

class ScoreUp : public ItemBase
{
private:
    int hScore_;        //スコアアップ　青

public:
    ScoreUp(GameObject* parent);
    ~ScoreUp();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    // 衝突処理
    void OnCollision(GameObject* pTarget) override;
};
