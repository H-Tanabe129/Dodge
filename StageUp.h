#pragma once
#include "Engine/GameObject.h"

class StageUp : public GameObject
{
private:
    int hModel_;    //モデル番号

    static const int trPosiX = -5;      //モデルポジションX
    static const int trPosiY = 7.5f;    //モデルポジションY
    static const int trPosiZ = 0;       //モデルポジションZ
    static const int BCollPosiX = -0.1f;    //コライダーポジションX
    static const int BCollPosiY = 0;        //コライダーポジションY
    static const int BCollPosiZ = 0;        //コライダーポジションZ
    static const int BCollSizeX = 1;    //コライダーサイズX
    static const int BCollSizeY = 8;    //コライダーサイズY
    static const int BCollSizeZ = 1;    //コライダーサイズZ

    static const int LEdge = -10;   // 世界左端
    float trPosiChangeX = 0.1;      // X座標変化量

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