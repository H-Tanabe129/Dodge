#pragma once
#include "Engine/GameObject.h"
#include "StageUp.h"
#include "StageLO.h"

class SpeedDown : public GameObject
{
private:
    int hSpeed_;    //スピードダウン　　オレンジ
    StageUp* pStageUp_;
    StageLo* pStageLo_;

    int trPosiX = 35;      //モデルポジションX
    int trPosiY = 0;       //モデルポジションY
    int trPosiZ = 0;       //モデルポジションZ
    const float BCollPosiX = 0.5;     //コライダーポジションX
    const float BCollPosiY = 0.5;     //コライダーポジションY
    const float BCollPosiZ = 0;       //コライダーポジションZ
    const float BCollSizeX = 1.1;    //コライダーサイズX
    const float BCollSizeY = 1.1;    //コライダーサイズY
    const float BCollSizeZ = 1.1;    //コライダーサイズZ

    float trPosiChangeX = 0.1;      //X座標変化量
    float trRoteChangeY = 0.5;      //Y軸回転変化量
    static const int LEdge = -10;   //左端

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

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject* pTarget) override;
};

