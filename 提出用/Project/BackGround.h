#pragma once
#include "Engine/GameObject.h"
#include "Engine/Image.h"

class BackGround : public GameObject
{
private:
    int hPict_;    //画像番号
public:
 //コンストラクタ
 BackGround(GameObject* parent);

 ~BackGround();

 //初期化
 void Initialize() override;

 //更新
 void Update() override;

 //描画
 void Draw() override;

 //開放
 void Release() override;
};
