#pragma once
#include "Engine/GameObject.h"

class JumpUp : public GameObject
{
private:
    int hJump_;     //ジャンプ力アップ

    int trPosiX = 35;      //モデルポジションX
    int trPosiY = 0;       //モデルポジションY
    int trPosiZ = 0;       //モデルポジションZ
    int BColliderPosiX = 0.75f;     //コライダーポジションX
    int BColliderPosiY = 0.75f;     //コライダーポジションY
    int BColliderPosiZ = 0;         //コライダーポジションZ
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
    JumpUp(GameObject* parent);

    //デストラクタ
    ~JumpUp();

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
};

