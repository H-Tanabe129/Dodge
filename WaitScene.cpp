#include "WaitScene.h"
#include "Player.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"

WaitScene::WaitScene(GameObject* parent)
	: GameObject(parent, "WaitScene"), hPict_(-1), pText(nullptr), pPlayer_(nullptr)
{
}

WaitScene::~WaitScene()
{
    delete pText;
    delete pPlayer_;
}

void WaitScene::Initialize()
{
	Camera::SetPosition(XMFLOAT3(CPosiX, CPosiY, CPosiZ));  //test == 35, 3, 0    -25
	Camera::SetTarget(XMFLOAT3(CTarX, CTarY, CTarZ));

    //画像データのロード
    hPict_ = Image::Load("Ready.png");
    assert(hPict_ >= 0);

    // Player クラスのインスタンスを生成
    pPlayer_ = new Player(this);
    pPlayer_->Initialize();

	pText = new Text;
	pText->Initialize();
}

void WaitScene::Update()
{
	if (Input::IsKey(DIK_SPACE)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);

		if (pPlayer_) {
			pPlayer_->Jump();
		}
	}
}

void WaitScene::Draw()
{
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);

	pText->Draw(scoreX, scoreY, "Score:0");
	pText->Draw(timeX, timeY, "Time: 0");

    if (pPlayer_) {
        pPlayer_->Draw();
    }
}

void WaitScene::Release()
{
    if (pPlayer_) {
        pPlayer_->Release();
        delete pPlayer_;
        pPlayer_ = nullptr;
    }
}
