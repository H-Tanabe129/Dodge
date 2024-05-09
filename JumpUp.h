#pragma once
#include "Engine/GameObject.h"

class JumpUp : public GameObject
{
private:
    int hJump_;     //ジャンプ力アップ

public:
    //コンストラクタ
    JumpUp(GameObject* parent);

    //デストラクタ
    ~JumpUp();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

