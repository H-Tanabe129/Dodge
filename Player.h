#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class Player : public GameObject
{
private:
    int hModel_;    //モデル番号
    int hSound_;    //サウンド番号
    Text* pText;
    const int END = 12;
    static const int posiZ = -1;
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

