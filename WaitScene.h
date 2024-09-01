#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Player.h"

class WaitScene : public GameObject
{
private:
    Text* pText;
    Player* pPlayer_; // Player クラスのポインタ
    Transform picTrans_;
    Transform pushTrans_;
    Transform buildTrans1_;
    Transform buildTrans2_;

    int hPict_;    //画像番号
    int hBack_;    //画像番号
    int hPush_;    //画像番号
    int hBuilding1_;    //モデル番号
    int hBuilding2_;    //モデル番号

    static const int FPS = 60;
    static const int flash = 5;
    int frame = 0;

    static const int CPosiX = 15;	//カメラポジションX
    static const int CPosiY = 3;	//カメラポジションY
    static const int CPosiZ = -25;	//カメラポジションZ
    static const int CTarX = 15;	//カメラターゲットX
    static const int CTarY = 0;		//カメラターゲットY
    static const int CTarZ = 10;	//カメラターゲットZ

    const float trPosiX = -16;      //モデルポジションX
    const float trBackPosiX = 23;   //後モデルポジションX
    const float trPosiY = -8.0f;    //モデルポジションY
    const float trPosiZ = 8;        //モデルポジションZ

    static const int pushPosiX = 0;     //画像ポジションX
    const float pushPosiY = -0.5f;      //画像ポジションY
    static const int pushPosiZ = 0;     //画像ポジションZ
    int pushAlpha = 255;   //画像透明度
    bool isFlashing = false;

    static const int picPosiX = 0;      //背景ポジションX
    static const int picPosiY = 0;      //背景ポジションY
    static const int picPosiZ = 0;      //背景ポジションZ
    const float picScaleX = 6.0f;       //背景サイズX
    const float picScaleY = 5.0f;       //背景サイズY
    const float picScaleZ = 1.0f;       //背景サイズZ
    static const int picAlpha = 128;    //背景透明度

    static const int scoreX = 30;   //時間表示X
    static const int scoreY = 30;   //時間表示Y
    static const int timeX = 30;    //スコア表示X
    static const int timeY = 60;    //スコア表示Y

    float veloIni = 0.0f;       //重力初期値
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