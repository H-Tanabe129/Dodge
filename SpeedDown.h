#pragma once
#include "Engine/GameObject.h"

class SpeedDown : public GameObject
{
private:
    int hSpeed_;    //スピードダウン
    int min = -800;     //Y座標乱数範囲の最小値*100
    int max = 800;      //Y座標乱数範囲の最大値*100
    int flo = 1000.0f;  //Y座標乱数÷1000する
    int geneRand = 0;   //Y座標乱数

    static const int trPosiX = 35;      //モデルポジションX
    float trPosiY = 0;                  //モデルポジションY
    static const int trPosiZ = 0;       //モデルポジションZ
    static const int BColliderPosiX = 0.1f;     //コライダーポジションX
    static const int BColliderPosiY = 0;        //コライダーポジションY
    static const int BColliderPosiZ = 0;        //コライダーポジションZ
    static const int BColliderSizeX = 1;    //コライダーサイズX
    static const int BColliderSizeY = 1;    //コライダーサイズY
    static const int BColliderSizeZ = 1;    //コライダーサイズZ

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

    //Y座標乱数生成
    float GenerateRand();
};

