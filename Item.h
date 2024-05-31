#pragma once
#include "Engine/GameObject.h"
#include <random>

enum {
    Score = 1,
    Jump,
    Speed,
    End
};

class Item : public GameObject
{
private:
    int rd = 0;              // 現在のランダム値
    int frame = 0;           // フレームカウンター
    int randomValue;         // ランダム間隔値
    const int FPS = 60;      // フレームレート
    const int randMin = 10;  // ランダム秒数間隔の最小値
    const int randMax = 15;  // ランダム秒数間隔の最大値
    const int rdMin = 1;     // ランダムアイテムタイプの最小値

    int min = -800;     //Y座標乱数範囲の最小値*100
    int max = 800;      //Y座標乱数範囲の最大値*100
    int flo = 1000.0f;  //Y座標乱数÷1000する
    int geneRand = 0;   //Y座標乱数

    int trPosiX = 35;      //モデルポジションX
    float trPosiY = 0;                  //モデルポジションY
    static const int trPosiZ = 0;       //モデルポジションZ

    const int rdMax = 3;     // ランダムアイテムタイプの最大値

    int getRandomValue(int min, int max);

    std::random_device rd_dev; // シード生成器
    std::mt19937 gen;          // メルセンヌ・ツイスタ生成器

public:
    //コンストラクタ
    Item(GameObject* parent);

    //デストラクタ
    ~Item();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //Y座標乱数生成
    float GenerateRand();

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject *pTarget) override;
};