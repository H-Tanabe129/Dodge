#pragma once
#include "Engine/GameObject.h"
#include "Engine/Input.h"
#include "Engine/Text.h"

class Player : public GameObject
{
private:
    int hModel_;    //モデル番号
    Text* pText;

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

