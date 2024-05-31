#pragma once
#include "Engine/GameObject.h"

class JumpUp : public GameObject
{
private:
    int hJump_;     //ジャンプ力アップ
    static const int BColliderPosiX = 0.1f;     //コライダーポジションX
    static const int BColliderPosiY = 0;        //コライダーポジションY
    static const int BColliderPosiZ = 0;        //コライダーポジションZ
    static const int BColliderSizeX = 1;    //コライダーサイズX
    static const int BColliderSizeY = 1;    //コライダーサイズY
    static const int BColliderSizeZ = 1;    //コライダーサイズZ

public:
    //コンストラクタ
    JumpUp(GameObject* parent);

    //デストラクタ
    ~JumpUp();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

