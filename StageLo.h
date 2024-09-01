#pragma once
#include "Engine/GameObject.h"

class StageLo : public GameObject
{
private:
    int hModel_;    //モデル番号

    const float trPosiX = -5;       //モデルポジションX
    const float trPosiY = -10;      //モデルポジションY
    const float trPosiZ = 0;        //モデルポジションZ
    const float trSizeX = 1.0f;     //モデルサイズX
    const float trSizeY = 0.9f;     //モデルサイズY
    const float trSizeZ = 1.0f;     //モデルサイズZ
    const float boxCollPosX = 0;     //コライダーポジションX
    const float boxCollPosY = 4.1f;  //コライダーポジションY
    const float boxCollPosZ = 0;     //コライダーポジションZ
    const float boxCollSizeX = 1.75f; //コライダーサイズX
    const float boxCollSizeY = 8.3f;  //コライダーサイズY
    const float boxCollSizeZ = 1.7f;  //コライダーサイズZ

    static const int WORLD_EDGE = -10;   // 世界左端
    float trPosiChangeX = 0.1;      // X座標変化量

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