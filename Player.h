#pragma once
#include "Engine/GameObject.h"

class Player : public GameObject
{
private:
    int hModel_;    // モデル番号
    int hSound_;    // サウンド番号
    int hBGM_;      // サウンド番号

    const float SColliderX = 1.0f;    // コライダーX軸
    const float SColliderY = 1.0f;    // コライダーY軸
    const float SColliderZ = 1.0f;    // コライダーZ軸
    const float radius = 1.02f;       // コライダー半径
    float veloIni = 0.0f;             // 重力初期値
    float veloIncre = 0.15f;          // 重力増加量
    float veloDecre = 0.02f;          // 重力減少量

    static const int edge = 12;       // 画面端
    float posiY = 0.0f;               // プレイヤー表示Y
    static const int posiZ = -1;      // プレイヤー表示Z
    static const int scoreX = 30;     // 時間表示X
    static const int scoreY = 30;     // 時間表示Y
    static const int timeX = 30;      // スコア表示X
    static const int timeY = 60;      // スコア表示Y

public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    void Jump();

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject *pTarget) override;
};

