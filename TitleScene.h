#pragma once
#include "Engine/GameObject.h"

class TitleScene : public GameObject
{
private:
    Transform titleTransform;
    Transform startTransform;
    int hTitle_;    //画像番号(タイトル)
    int hStart_;    //画像番号(スタート)

    static const int TITLE_POS_Y = 0;   //Title画像ポジションY
    const float startPosY = -0.5f;      //START画像ポジションY

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

