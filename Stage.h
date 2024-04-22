#pragma once
#include "Engine/GameObject.h"
#include "Engine/Transform.h"

enum Wall {
    TOGETHER = 0,
    //UPPERFRONT,
    //LOWERFRONT,
    UPPER,
    LOWER,
    UPPERLONG,
    LOWERLONG,
    MAX
};

class Stage : public GameObject
{
private:
    int hModel_;    //モデル番号

    static const int FPS = 60;
    int frame = 0;
    int rd = 0;
    int SetPosiX = 35.0;
    int SetPosiUpY = 3.5f;
    int SetPosiLoY = -2.5f;
    int SetPosiZ = 0;

public:
    //コンストラクタ
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};