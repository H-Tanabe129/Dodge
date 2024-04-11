#pragma once
#include "Engine/GameObject.h"

class TitleScene : public GameObject
{
private:
    int hPict_;    //画像番号
    int hStart_;    //画像番号
    Transform Title;

    static const int titlePicturePosiY = 0;
    float startPicturePosiY = -0.5;

public:
 //コンストラクタ
 //引数：parent  親オブジェクト（SceneManager）
 TitleScene(GameObject* parent);

 //初期化
 void Initialize() override;

 //更新
 void Update() override;

 //描画
 void Draw() override;

 //開放
 void Release() override;
};

