#pragma once
#include "Engine/GameObject.h"

class ScoreUp : public GameObject
{
private:
    int hScore_;    //スコアアップ

    int trPosiX = 35;      //モデルポジションX
    int trPosiY = 0;       //モデルポジションY
    int trPosiZ = 0;       //モデルポジションZ
    const float BColliderPosiX = 0.5;     //コライダーポジションX
    const float BColliderPosiY = 0.5;     //コライダーポジションY
    const float BColliderPosiZ = 0;         //コライダーポジションZ
    const float BColliderSizeX = 1;    //コライダーサイズX
    const float BColliderSizeY = 1;    //コライダーサイズY
    const float BColliderSizeZ = 1;    //コライダーサイズZ

    int min = -800;     //Y座標乱数範囲の最小値*100
    int max = 800;      //Y座標乱数範囲の最大値*100
    int flo = 100;     //Y座標乱数÷1000する
    int geneRand = 0;   //Y座標乱数
    float trPosiChangeX = 0.1;      //X座標変化量
    static const int LEdge = -10;   //左端

public:
    //コンストラクタ
    ScoreUp(GameObject* parent);

    //デストラクタ
    ~ScoreUp();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //Y座標乱数生成
    int GenerateRand();

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject *pTarget) override;
};

