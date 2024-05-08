#include "WaitScene.h"
#include "Player.h"
#include "Engine/Camera.h"
#include "Engine/Audio.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

WaitScene::WaitScene(GameObject* parent)
	: GameObject(parent, "WaitScene"), hSound_(-1), pText(nullptr)
{
}

void WaitScene::Initialize()
{
	//サウンドデータのロード
	hSound_ = Audio::Load("A2_01003.WAV", true);
	assert(hSound_ >= 0);

	Camera::SetPosition(XMFLOAT3(CPosiX, CPosiY, CPosiZ));  //test == 35, 3, 0    -25
	Camera::SetTarget(XMFLOAT3(CTarX, CTarY, CTarZ));

	Instantiate<Player>(this);

	pText = new Text;
	pText->Initialize();
	Audio::Play(hSound_);
}

void WaitScene::Update()
{
	if (Input::IsKeyUp(DIK_SPACE)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void WaitScene::Draw()
{
	pText->Draw(scoreX, scoreY, "0");
	pText->Draw(timeX, timeY, "0");
}

void WaitScene::Release()
{
}
