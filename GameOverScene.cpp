#include "GameOverScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
//#include "PlayScene.h"

GameOverScene::GameOverScene(GameObject* parent)
	: GameObject(parent, "TitleScene"), hPict_(-1)
{
}

void GameOverScene::Initialize()
{
    //�摜�f�[�^�̃��[�h
    hPict_ = Image::Load("gameover.png");
    assert(hPict_ >= 0);
}

void GameOverScene::Update()
{
    //�L�[����������^�C�g��
    if (Input::IsKeyUp(DIK_SPACE))
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_TITLE);
    }
    ////�L�[������������g���C
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
}

void GameOverScene::Release()
{
}
