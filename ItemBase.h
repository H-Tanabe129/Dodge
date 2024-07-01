#pragma once
#include "Engine/GameObject.h"
#include "Engine/BoxCollider.h"
#include "Engine/Model.h"
#include "Engine/Audio.h"

class ItemBase : public GameObject
{
protected:
    int hModel_;
    int hSound_;

    int trPosiX = 35;      //モデルポジションX
    int trPosiY = 0;       //モデルポジションY
    int trPosiZ = 0;       //モデルポジションZ

    const float BCollPosiX = 0.5;    //コライダーポジションX
    const float BCollPosiY = 0.5;    //コライダーポジションY
    const float BCollPosiZ = 0;      //コライダーポジションZ
    const float BCollSizeX = 1.1;    //コライダーサイズX
    const float BCollSizeY = 1.1;    //コライダーサイズY
    const float BCollSizeZ = 1.1;    //コライダーサイズZ

    float trPosiChangeX = 0.1;      //X座標変化量
    float trRoteChangeY = 0.5;      //Y軸回転変化量
    static const int LEdge = -10;   //世界左端

public:
    //コンストラクタ
    ItemBase(GameObject* parent);

    //デストラクタ
    virtual ~ItemBase();

    //初期化
    virtual void Initialize() override;

    //更新
    virtual void Update() override;

    //描画
    virtual void Draw() override;

    //開放
    virtual void Release() override;

    // 衝突処理
    virtual void OnCollision(GameObject* pTarget) override;

    virtual void SetPosition(int x, int y, int z);
};