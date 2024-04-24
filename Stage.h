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
    int rd = 0;     //乱数
    int SetPosiX = 35.0;        //追加StageのX座標
    int SetPosiUpY = 3.5f;      //上追加StageのY初期座標
    int SetPosiLoY = -2.5f;     //下追加StageのY初期座標
    int SetPosiZ = 0;           //追加StageのZ座標

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