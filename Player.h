#pragma once
#include "Engine/GameObject.h"

class Player : public GameObject
{
private:
    int hModel_;    //モデル番号
    int hSound_;    //サウンド番号

    static const int SColliderX = 1.0f;    //コライダーX軸
    static const int SColliderY = 1.0f;    //コライダーY軸
    static const int SColliderZ = 1.0f;    //コライダーZ軸
    static const int radius = 1.02f;       //コライダー半径
    float veloIni = 0.0f;       //重力初期値
    float veloIncre = 0.15f;    //重力増加量
    float veloDecre = 0.05f;    //重力減少量

    const float initialVelocity = 0.0f; // 最初の速度（静止状態）
    const float jumpVelocity = 10.0f;   // ジャンプ初期速度
    const float gravity = 0.5f;         // 重力加速度
    const float hoverHeight = 10.0f;    // 初期位置の高さ
    const float groundLevel = -FLT_MAX; // 地面の高さ（今回は無限に低く設定）
    int posiY = 0.0f;


    static const int edge = 12;     //画面端
    static const int posiZ = -1;    //プレイヤー表示Z
    static const int scoreX = 30;    //時間表示X
    static const int scoreY = 30;    //時間表示Y
    static const int timeX = 30;     //スコア表示X
    static const int timeY = 60;     //スコア表示Y

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

    void ApplyGravity();

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject *pTarget) override;
};

