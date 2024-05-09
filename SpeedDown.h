#pragma once
#include "Engine/GameObject.h"

class SpeedDown : public GameObject
{
private:
    int hSpeed_;    //スピードダウン

public:
    //コンストラクタ
    SpeedDown(GameObject* parent);

    //デストラクタ
    ~SpeedDown();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

