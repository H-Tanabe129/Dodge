#include "GameOverScene.h"
#include "ValueManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"

GameOverScene::GameOverScene(GameObject* parent)
	: GameObject(parent, "GameOverScene"), hGameOver_(-1), pText(nullptr), hSound_(-1)
{
}

void GameOverScene::Initialize()
{
    //画像データのロード
    hGameOver_ = Image::Load("gameover.png");
    assert(hGameOver_ >= 0);
    hReturnTitle_ = Image::Load("returnTitle.png");
    assert(hReturnTitle_ >= 0);

    ToTitle.position_.y = toTitlePosY;

    //サウンドデータのロード
    hSound_ = Audio::Load("A2_07094.WAV");
    Audio::Play(hSound_);

    pText = new Text;
    pText->Initialize();
}

void GameOverScene::Update()
{
    //キーを放した→タイトル
    if (Input::IsKeyUp(DIK_T))
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_TITLE);
    }
}

void GameOverScene::Draw()
{
    Image::SetTransform(hGameOver_, transform_);
    Image::Draw(hGameOver_);
    Image::SetTransform(hReturnTitle_, ToTitle);
    Image::Draw(hReturnTitle_);

    //リザルト表示
    pText->Draw(SCORE_POS_X, SCORE_POS_Y, "Score:");
    pText->Draw(SCORE_POS_X + 100, SCORE_POS_Y, ValueManager::GetInstance().GetScore());
    pText->Draw(TIME_POS_X, TIME_POS_Y, "Time: ");
    pText->Draw(TIME_POS_X + 100, TIME_POS_Y, ValueManager::GetInstance().GetTime());
}

void GameOverScene::Release()
{
    pText->Release();
}
