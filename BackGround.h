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

    static const int PIC_POS_X = 0;      //背景ポジションX
    static const int PIC_POS_Y = 0;      //背景ポジションY
    static const int PIC_POS_Z = -3;     //背景ポジションZ
    const float PIC_SCALE_X = 6.0f;       //背景サイズX
    const float PIC_SCALE_Y = 5.0f;       //背景サイズY
    const float PIC_SCALE_Z = 1.0f;       //背景サイズZ
    static const int PIC_ALPHA = 128;    //背景透明度

    static const int WORLD_EDGE = -58;   // 世界左端
    float posChangeX = 0.1f;      // X座標変化量

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
