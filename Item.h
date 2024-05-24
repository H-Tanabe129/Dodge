#pragma once
#include "Engine/GameObject.h"

enum {
    ScoreUp = 1,
    JumpUp,
    SpeedDown,
    End
};

class Item : public GameObject
{
private:
    int rd = 0;
    int frame = 0;
    int randomValue;
    const int FPS = 60;
    const int randMin = 10;
    const int randMax = 15;

    int getRandomValue(int min, int max);

public:
    //コンストラクタ
    Item(GameObject* parent);

    //デストラクタ
    ~Item();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject *pTarget) override;
};