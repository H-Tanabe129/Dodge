#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"

class GameOverScene : public GameObject
{
private:
    int hPict_;     //画像番号
    int hSound_;    //サウンド
    Text* pText;

    static const int scoreX = 930;    //時間表示X
    static const int scoreY = 450;    //時間表示Y
    static const int timeX = 930;     //スコア表示X
    static const int timeY = 500;     //スコア表示Y
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    GameOverScene(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};