#pragma once
#include "Engine/GameObject.h"

class StageUp : public GameObject
{
private:
    int hModel_;    //モデル番号
    int width;
    int height;
    int depth;
public:
    //コンストラクタ
    StageUp(GameObject* parent);

    //デストラクタ
    ~StageUp();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    DirectX::XMFLOAT3 GetScale() const override { return GameObject::GetScale(); }
};