#pragma once
#include "Engine/GameObject.h"
#include "Engine/Input.h"

class Player : public GameObject
{
private:
    int hModel_;    //モデル番号
    //Transform Player_;

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
};

