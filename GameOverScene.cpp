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
    ////キーを放した→リトライ
    //if (Input::IsKeyUp(DIK_R))
    //{
    //    SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
    //    pSceneManager->ChangeScene(SCENE_ID_PLAY);
    //    Instantiate<PlayScene>(this);
    //}
}

void GameOverScene::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);


    pText->Draw(scoreX, scoreY, "Score:");
    pText->Draw(scoreX + 100, scoreY, ValueManager::GetInstance().GetScore());
    pText->Draw(timeX, timeY, "Time: ");
    pText->Draw(timeX + 100, timeY, ValueManager::GetInstance().GetTime());
}

void GameOverScene::Release()
{
    pText->Release();
}
