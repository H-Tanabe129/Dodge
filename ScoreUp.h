#pragma once
#include "Engine/GameObject.h"

class ScoreUp : public GameObject
{
private:
    int hScore_;    //スコアアップ  水色
    int hSound_;    //獲得音

    int scoreUpPosX = 35;                       //モデルポジションX
    int scoreUpPosY = 0;                        //モデルポジションY
    static const int SCORE_UP_POS_Z = 0;        //モデルポジションZ
    const float sphCollPosX = 0.0f;    //コライダーポジションX
    const float sphCollPosY = 0.5f;    //コライダーポジションY
    const float sphCollPosZ = 0.0f;    //コライダーポジションZ
    const float sphCollSizeX = 0.7f;   //コライダーサイズ

    const float posChangeX = 0.1f;       //X座標変化量
    const float trRoteChangeY = 0.5f;       //Y軸回転変化量
    static const int WORLD_EDGE = -10;      //世界左端

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

