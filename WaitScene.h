#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "Player.h"

class WaitScene : public GameObject
{
private:
    int hSound_;    //画像番号
    Text* pText;
    Player* pPlayer_; // Player クラスのポインタ

    static const int CPosiX = 15;	//カメラポジションX
    static const int CPosiY = 3;	//カメラポジションY
    static const int CPosiZ = -25;	//カメラポジションZ
    static const int CTarX = 15;	//カメラターゲットX
    static const int CTarY = 0;		//カメラターゲットY
    static const int CTarZ = 10;	//カメラターゲットZ
    static const int scoreX = 30;    //時間表示X
    static const int scoreY = 30;    //時間表示Y
    static const int timeX = 30;     //スコア表示X
    static const int timeY = 60;     //スコア表示Y
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