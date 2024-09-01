#include "GameOverScene.h"
#include "ValueManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"
//#include "PlayScene.h"

GameOverScene::GameOverScene(GameObject* parent)
	: GameObject(parent, "GameOverScene"), hPict_(-1), pText(nullptr), hSound_(-1)
{
}

void GameOverScene::Initialize()
{
    //サウンドデータのロード
    hSound_ = Audio::Load("A2_07094.WAV");


    //画像データのロード
    hPict_ = Image::Load("gameover.png");
    assert(hPict_ >= 0);

    pText = new Text;
    pText->Initialize();
    Audio::Play(hSound_);
}

void GameOverScene::Update()
{
    //キーを放した→タイトル
    if (Input::IsKeyUp(DIK_SPACE))
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_TITLE);
    }
}

void GameOverScene::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);


    pText->Draw(SCORE_POS_X, SCORE_POS_Y, "Score:");
    pText->Draw(SCORE_POS_X + 100, SCORE_POS_Y, ValueManager::GetInstance().GetScore());
    pText->Draw(TIME_POS_X, TIME_POS_Y, "Time: ");
    pText->Draw(TIME_POS_X + 100, TIME_POS_Y, ValueManager::GetInstance().GetTime());
}

void GameOverScene::Release()
{
    pText->Release();
}
