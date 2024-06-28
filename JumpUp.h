#pragma once
#include "ItemBase.h"

class JumpUp : public ItemBase, public GameObject
{
private:
    int hJump_;         //ジャンプアップ　緑

public:
    JumpUp(GameObject* parent);
    ~JumpUp();

    // 初期化
    void Initialize() override;

    // 更新
    void Update() override;

    // 衝突処理
    void OnCollision(GameObject* pTarget) override;
};
