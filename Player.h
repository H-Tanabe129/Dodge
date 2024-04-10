#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Player : public GameObject
{
private:
    int hModel_;    //モデル番号
    int hSound_;    //サウンド番号
    Text* pText;

    static const int SphereColliderX = 1.0f;    //コライダーX軸
    static const int SphereColliderY = 1.0f;    //コライダーY軸
    static const int SphereColliderZ = 1.0f;    //コライダーZ軸
    static const int radius = 1.02f;            //コライダー半径
    float veloIni = 0.0f;       //重力初期値
    float veloIncre = 0.15f;    //重力増加量
    float veloDecre = 0.02f;    //重力減少量
    static const int edge = 12;     //画面端
    static const int posiZ = -1;    //プレイヤー表示Z
    static const int textX = 30;    //文字表示X
    static const int textY = 30;    //文字表示Y
    int score;

public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject *pTarget) override;
};

