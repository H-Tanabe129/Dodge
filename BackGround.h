#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"

class BackGround : public GameObject
{
private:
    Transform picTrans_;
    Transform buildTrans1_;
    Transform buildTrans2_;
    Transform buildTrans3_;

    bool isPushed = false;
    static const int FPS = 60;
    int frame = 0;
    int rd = 0;     //乱数

    int hBack_;    //画像番号
    int hBuilding1_;    //モデル番号
    int hBuilding2_;    //モデル番号
    int hBuilding3_;    //モデル番号

    const float trPosiX = -16;      //モデルポジションX
    const float trMidPosiX = 23;    //中モデルポジションX
    const float trBackPosiX = 62;   //後モデルポジションX
    const float trPosiY = -8.0f;    //モデルポジションY
    const float trPosiZ = 8;        //モデルポジションZ
    const float loopPosiX = 59;   //ループ位置

    static const int picPosiX = 0;      //背景ポジションX
    static const int picPosiY = 0;      //背景ポジションY
    static const int picPosiZ = -3;     //背景ポジションZ
    const float picScaleX = 6.0f;       //背景サイズX
    const float picScaleY = 5.0f;       //背景サイズY
    const float picScaleZ = 1.0f;       //背景サイズZ
    static const int picAlpha = 128;    //背景透明度

    static const int LEdge = -58;   // 世界左端
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
