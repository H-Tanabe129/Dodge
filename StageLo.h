#pragma once
#include "Engine/GameObject.h"

class StageLo : public GameObject
{
private:
    int hStageLo_;    //モデル番号

    const float loPosX = -5.0f;         //モデルポジションX
    const float loPosY = -10.0f;        //モデルポジションY
    const float loPosZ = 0.0f;          //モデルポジションZ
    const float loSizeX = 1.0f;         //モデルサイズX
    const float loSizeY = 0.9f;         //モデルサイズY
    const float loSizeZ = 1.0f;         //モデルサイズZ

    const float boxCollPosX = 0.0f;     //コライダーポジションX
    const float boxCollPosY = 4.1f;     //コライダーポジションY
    const float boxCollPosZ = 0.0f;     //コライダーポジションZ
    const float boxCollSizeX = 1.75f;   //コライダーサイズX
    const float boxCollSizeY = 8.3f;    //コライダーサイズY
    const float boxCollSizeZ = 1.7f;    //コライダーサイズZ

    static const int WORLD_EDGE = -10;  // 世界左端
    float posChangeX = 0.1f;          // X座標変化量

public:
    //コンストラクタ
    StageLo(GameObject * parent);

    //デストラクタ
    ~StageLo();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};