#pragma once
#include "Engine/GameObject.h"

enum Model {
    BUILDING_1 = 0,
    BUILDING_2,
    BUILDING_3,
    MAX
};

class BackGround : public GameObject
{
private:
    int hBuilding1_;    //モデル番号
    int hBuilding2_;    //モデル番号
    int hBuilding3_;    //モデル番号

    const float trPosiX = 0;       //モデルポジションX
    const float trPosiY = -4.0f;     //モデルポジションY
    const float trPosiZ = 5;        //モデルポジションZ
    const float trSizeX = 1.0f;     //モデルサイズX
    const float trSizeY = 1.0f;     //モデルサイズY
    const float trSizeZ = 1.0f;     //モデルサイズZ

    static const int LEdge = -10;   // 世界左端
    float trPosiChangeX = 0.1;      // X座標変化量

public:
    //コンストラクタ
    BackGround(GameObject* parent);

    //デストラクタ
    ~BackGround();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};
