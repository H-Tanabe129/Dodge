#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

TitleScene::TitleScene(GameObject* parent)
  : GameObject(parent, "TitleScene"), hPict_(-1), hStart_(-1)
{
}

void TitleScene::Initialize()
{
    //画像データのロード
    hPict_ = Image::Load("Dodge.png");
    assert(hPict_ >= 0);
    //画像データのロード
    hStart_ = Image::Load("Start.png");
    assert(hStart_ >= 0);

    Title.position_.y = 0;
    transform_.position_.y = -0.5;
}

void TitleScene::Update()
{
    //マウスの左ボタンを放した
    if(Input::IsMouseButtonUp(0))
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_PLAY);
    }
}

void TitleScene::Draw()
{
    Image::SetTransform(hPict_, Title);
    Image::Draw(hPict_);
    Image::SetTransform(hStart_, transform_);
    Image::Draw(hStart_);
}

void TitleScene::Release()
{
}
