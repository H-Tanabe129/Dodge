#pragma once
#include "Engine/GameObject.h"

enum Wall {
    TOGETHER = 0,
    UPPER,
    LOWER,
    UPPERLONG,
    LOWERLONG,
    MAX
};

class Stage : public GameObject
{
private:
    static const int FPS = 60;
    int frame = 0;
    int rd = 0;     //乱数

    int InitPosiX = 35;         //初期StageのX座標
    int InitPosiUpY = 3;        //上初期StageのY座標
    int InitPosiLoY = -10;      //下初期StageのY座標
    int InitPosiZ = 0;          //初期StageのZ座標
    int SetPosiX = 35;          //追加StageのX座標
    int SetPosiUpY = -1;        //上追加StageのY初期座標
    int SetPosiLoY = -6;        //下追加StageのY初期座標
    int SetPosiZ = 0;           //追加StageのZ座標

    int SetSizeX = 0.01f;       //追加StageのXサイズ
    int SetSizeY = 0.005f;       //追加StageのYサイズ
    int SetSizeZ = 0.01f;       //追加StageのZサイズ

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