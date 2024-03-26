#pragma once
#include "Engine/GameObject.h"
#include "Engine/Transform.h"

enum Wall {
    TOGETHER = 0,
    //UPPERFRONT,
    //LOWERFRONT,
    UPPER,
    LOWER,
    //UPPERLONG,
    //LOWERLONG,
    MAX
};

class Stage : public GameObject
{
private:
    int hModel_;    //モデル番号

    static const int FPS = 60;
    int frame = 0;
    int rd = 0;

    //Transform Upper;
    //Transform Lower;

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