#pragma once
#include "Engine/GameObject.h"

class ScoreUp : public GameObject
{
private:
    int hScore_;    //スコアアップ  水色
    int hSound_;

    int trPosiX = 35;      //モデルポジションX
    int trPosiY = 0;       //モデルポジションY
    int trPosiZ = 0;       //モデルポジションZ
    const float SCollPosiX = 0.0f;    //コライダーポジションX
    const float SCollPosiY = 0.5f;    //コライダーポジションY
    const float SCollPosiZ = 0.0f;    //コライダーポジションZ
    const float SCollSizeX = 0.7f;    //コライダーサイズ

    float trPosiChangeX = 0.1;      //X座標変化量
    float trRoteChangeY = 0.5;      //Y軸回転変化量
    static const int LEdge = -10;   //世界左端

public:
    //コンストラクタ
    ScoreUp(GameObject* parent);

    //デストラクタ
    ~ScoreUp();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject *pTarget) override;
};

