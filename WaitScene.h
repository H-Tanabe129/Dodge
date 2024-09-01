#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Player.h"

class WaitScene : public GameObject
{
private:
    Text* pText;
    Player* pPlayer_; // Player クラスのポインタ
    Transform picTrans_;        //背景画像
    Transform pushTrans_;       //PushSpace
    Transform buildTrans1_;     //背景モデル1
    Transform buildTrans2_;     //背景モデル2

    int hReady_;   //画像番号(Ready)
    int hBack_;    //画像番号(背景)
    int hPush_;    //画像番号(Push)
    int hBuilding1_;    //モデル番号
    int hBuilding2_;    //モデル番号

    static const int FPS = 60;
    int frame = 0;
    static const int FLASH_INTERVAL = 5;    //点滅の間隔

    static const int CAMERA_POS_X = 15;	    //カメラポジションX
    static const int CAMERA_POS_Y = 3;	    //カメラポジションY
    static const int CAMERA_POS_Z = -25;	//カメラポジションZ
    static const int CAMERA_TARGET_X = 15;  //カメラターゲットX
    static const int CAMERA_TARGET_Y = 0;	//カメラターゲットY
    static const int CAMERA_TARGET_Z = 10;	//カメラターゲットZ

    const float trPosiX = -16.0f;       //モデルポジションX
    const float trBackPosiX = 23.0f;    //後モデルポジションX
    const float trPosiY = -8.0f;        //モデルポジションY
    const float trPosiZ = 8.0f;         //モデルポジションZ

    static const int PUSH_POSI_X = 0;   //画像ポジションX
    const float PUSH_POSI_Y = -0.5f;    //画像ポジションY
    static const int PUSH_POSI_Z = 0;   //画像ポジションZ
    int pushAlpha = 255;                //画像透明度
    bool isFlashing = false;

    static const int PIC_POS_X = 0;      //背景ポジションX
    static const int PIC_POS_Y = 0;      //背景ポジションY
    static const int PIC_POS_Z = 0;      //背景ポジションZ
    static const int PIC_SCALE_X = 6;    //背景サイズX
    static const int PIC_SCALE_Y = 5;    //背景サイズY
    static const int PIC_SCALE_Z = 1;    //背景サイズZ
    static const int PIC_ALPHA = 128;    //背景透明度

    static const int SCORE_POS_X = 30;   //時間表示X
    static const int SCORE_POS_Y = 30;   //時間表示Y
    static const int TIME_POS_X = 30;    //スコア表示X
    static const int TIME_POS_Y = 60;    //スコア表示Y

    const float veloIni = 0.0f; //重力初期値
    float veloIncre = 0.15f;    //重力増加量
    float veloDecre = 0.02f;    //重力減少量

public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    WaitScene(GameObject* parent);
    ~WaitScene();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};