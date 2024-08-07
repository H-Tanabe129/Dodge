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
    hStart_ = Image::Load("PStart.png");
    assert(hStart_ >= 0);

    Title.position_.y = titlePicturePosiY;
    transform_.position_.y = startPicturePosiY;
}

void TitleScene::Update()
{
    //キーを放した
    if(Input::IsKeyUp(DIK_SPACE))
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        pSceneManager->ChangeScene(SCENE_ID_WAIT);
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
