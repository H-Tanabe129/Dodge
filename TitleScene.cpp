#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

TitleScene::TitleScene(GameObject* parent)
  : GameObject(parent, "TitleScene"), hTitle_(-1), hStart_(-1)
{
}

void TitleScene::Initialize()
{
    //画像データのロード
    hTitle_ = Image::Load("Dodge.png");
    assert(hTitle_ >= 0);
    //画像データのロード
    hStart_ = Image::Load("PStart.png");
    assert(hStart_ >= 0);

    titleTransform.position_.y = TITLE_POS_Y;
    startTransform.position_.y = startPosY;
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
    Image::SetTransform(hTitle_, titleTransform);
    Image::Draw(hTitle_);
    Image::SetTransform(hStart_, startTransform);
    Image::Draw(hStart_);
}

void TitleScene::Release()
{
}
