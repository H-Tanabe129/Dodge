#pragma once
#include "Engine/GameObject.h"

class Stage : public GameObject
{
private:
    int hModelU_;    //モデル番号
    int hModelL_;    //モデル番号
    Transform StaUpper;
    Transform StaLower;
public:
    //コンストラクタ
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};