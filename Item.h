#pragma once
#include "Engine/GameObject.h"
#include <random>

//アイテムの種類
enum {
    Score = 1,
    Jump,
    Speed,
    End
};

class Item : public GameObject
{
private:
    int frame = 0;                      // フレームカウンター
    int randomValue;                    // ランダム間隔値
    static const int FPS = 60;          // フレームレート

    int rd = 0;                         // 現在のランダム値
    static const int RANDOM_MIN = 10;   // ランダム秒数間隔の最小値
    static const int RANDOM_MAX = 15;   // ランダム秒数間隔の最大値

    float itemPosX = 35.0f;                 //モデルポジションX
    float itemPosY = 0.0f;                  //モデルポジションY
    static const int ITEM_POS_Z = 0;        //モデルポジションZ

    static const int RANDOM_Y_MIN = -700;       //Y座標乱数範囲の最小値*100
    static const int RANDOM_Y_MAX = 700;        //Y座標乱数範囲の最大値*100
    static const int RANDOM_Y_SEPAR = 100;      //Y座標乱数÷1000する
    int geneRand = 0;                           //Y座標乱数

    int getRandomValue(int min, int max);       //ランダムな整数を生成する関数
    std::random_device rd_dev;                  // シード生成器
    std::mt19937 gen;                           // メルセンヌ・ツイスタ生成器

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

    int GenerateRand();
};