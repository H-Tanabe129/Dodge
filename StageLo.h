#pragma once
#include <vector>
#include "Engine/GameObject.h"
#include "Engine/BoxCollider.h"
class StageLo : public GameObject
{
private:
    int hModel_;    //モデル番号
public:
    //コンストラクタ
    StageLo(GameObject* parent);

    //デストラクタ
    ~StageLo();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};