#pragma once
#include "Engine/GameObject.h"

class StageUp : public GameObject
{
private:
    int hStageUp_;    //モデル番号

    float trPosiX = -5.0f;              //モデルポジションX
    float trPosiY = 3.0f;               //モデルポジションY
    const float trPosiZ = 0.0f;         //モデルポジションZ
    const float trSizeX = 1.0f;         //モデルサイズX
    const float trSizeY = 0.9f;         //モデルサイズY
    const float trSizeZ = 1.0f;         //モデルサイズZ
    const float boxCollPosX = 0.0f;     //コライダーポジションX
    const float boxCollPosY = 4.1f;     //コライダーポジションY
    const float boxCollPosZ = 0.0f;     //コライダーポジションZ
    const float boxCollSizeX = 1.75f;   //コライダーサイズX
    const float boxCollSizeY = 8.3f;    //コライダーサイズY
    const float boxCollSizeZ = 1.7f;    //コライダーサイズZ

    static const int WORLD_EDGE = -10;  // 世界左端
    const float posChangeX = 0.1f;      // X座標変化量

public:
    //コンストラクタ
    StageUp(GameObject * parent);

    //デストラクタ
    ~StageUp();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};
