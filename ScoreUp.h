#pragma once
#include "Engine/GameObject.h"

class ScoreUp : public GameObject
{
private:
    int hScore_;    //スコアアップ

    static const int trPosiX = 35;      //モデルポジションX
    static const int trPosiY = -6.5f;   //モデルポジションY
    static const int trPosiZ = 0;       //モデルポジションZ
    static const int BColliderPosiX = 0.1f;     //コライダーポジションX
    static const int BColliderPosiY = 0;        //コライダーポジションY
    static const int BColliderPosiZ = 0;        //コライダーポジションZ
    static const int BColliderSizeX = 1;    //コライダーサイズX
    static const int BColliderSizeY = 1;    //コライダーサイズY
    static const int BColliderSizeZ = 1;    //コライダーサイズZ
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
};

