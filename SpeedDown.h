#pragma once
#include "Engine/GameObject.h"

class SpeedDown : public GameObject
{
private:
    int hSpeed_;    //スピードダウン

    static const int trPosiX = 35;      //モデルポジションX
    static const int trPosiY = -6.5f;   //モデルポジションY
    static const int trPosiZ = 0;       //モデルポジションZ
    static const int BColliderPosiX = 0.1f;     //コライダーポジションX
    static const int BColliderPosiY = 0;        //コライダーポジションY
    static const int BColliderPosiZ = 0;        //コライダーポジションZ
    static const int BColliderSizeX = 1;    //コライダーサイズX
    static const int BColliderSizeY = 8;    //コライダーサイズY
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
};

