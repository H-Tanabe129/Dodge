#pragma once
#include "Engine/GameObject.h"

class ScoreUp : public GameObject
{
private:
    int hScore_;    //スコアアップ
    static const int trPosiX = 35;      //モデルポジションX
    int trPosiY = 0;                    //モデルポジションY
    static const int trPosiZ = 0;       //モデルポジションZ
    static const int BColliderPosiX = 0.5f;     //コライダーポジションX
    static const int BColliderPosiY = 0.5f;        //コライダーポジションY
    static const int BColliderPosiZ = 0;        //コライダーポジションZ
    static const int BColliderSizeX = 1;    //コライダーサイズX
    static const int BColliderSizeY = 1;    //コライダーサイズY
    static const int BColliderSizeZ = 1;    //コライダーサイズZ

    int min = -800;     //Y座標乱数範囲の最小値*100
    int max = 800;      //Y座標乱数範囲の最大値*100
    int flo = 1000.0f;  //Y座標乱数÷1000する
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
    float GenerateRand();

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject *pTarget) override;
};

