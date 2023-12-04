#pragma once
#include <vector>
#include "Engine/GameObject.h"
#include "Engine/BoxCollider.h"

class Stage : public GameObject
{
private:
    int hModel_;    //モデル番号
    Transform StaUpper;
    Transform StaLower;

    // コライダーを格納するstd::vector
    std::vector<Collider*> colliders_;
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

    // コライダーへのアクセスを提供するメソッド
    Collider* GetCollider(size_t index) const;
};