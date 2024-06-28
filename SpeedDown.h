#pragma once
#include "ItemBase.h"
#include "Stage.h"

class SpeedDown : public ItemBase
{
private:
    int hSpeed_;        //スピードダウン　オレンジ
    Stage* pStage_;

public:
    SpeedDown(GameObject* parent);
    ~SpeedDown();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    //解放
    void Release() override;

    // 衝突処理
    void OnCollision(GameObject* pTarget) override;
};
