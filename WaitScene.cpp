#include "WaitScene.h"
#include "Player.h"
#include "BackGround.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"

WaitScene::WaitScene(GameObject* parent)
	: GameObject(parent, "WaitScene"), 
    hReady_(-1), hBack_(-1), hPush_(-1), hBuilding1_(-1), hBuilding2_(-1), pText(nullptr), pPlayer_(nullptr)
{
}

WaitScene::~WaitScene()
{
    delete pText;
    delete pPlayer_;
}

void WaitScene::Initialize()
{
    //カメラ
	Camera::SetPosition(XMFLOAT3(CAMERA_POS_X, CAMERA_POS_Y, CAMERA_POS_Z));  //test == 35, 3, 0    -25
	Camera::SetTarget(XMFLOAT3(CAMERA_TARGET_X, CAMERA_TARGET_Y, CAMERA_TARGET_Z));

    //モデルデータのロード
    hBuilding1_ = Model::Load("Model/Back.fbx");
    assert(hBuilding1_ >= 0);
    hBuilding2_ = Model::Load("Model/Back.fbx");
    assert(hBuilding2_ >= 0);

    // 初期位置
    buildTrans1_.position_ = XMFLOAT3(trPosiX, trPosiY, trPosiZ);
    buildTrans2_.position_ = XMFLOAT3(trBackPosiX, trPosiY, trPosiZ);

    //画像データのロード
    hBack_ = Image::Load("shiro.png");
    assert(hBack_ >= 0);
    hReady_ = Image::Load("Ready.png");
    assert(hReady_ >= 0);
    hPush_ = Image::Load("PSTART.png");
    assert(hPush_ >= 0);

    //画像
    pushTrans_.position_ = XMFLOAT3(PUSH_POSI_X, PUSH_POSI_Y, PUSH_POSI_Z);

    //背景
    picTrans_.position_ = XMFLOAT3(PIC_POS_X, PIC_POS_Y, PIC_POS_Z);
    picTrans_.scale_ = XMFLOAT3(PIC_SCALE_X, PIC_SCALE_Y, PIC_SCALE_Z);
    Image::SetAlpha(hBack_, PIC_ALPHA);

    // Player クラスのインスタンスを生成
    pPlayer_ = new Player(this);
    pPlayer_->Initialize();

	pText = new Text;
	pText->Initialize();
}

void WaitScene::Update()
{
    frame++;

	if (Input::IsKey(DIK_SPACE)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);

		if (pPlayer_) {
			pPlayer_->Jump();
		}
	}

    // アルファ値を増減させる
    if (isIncreasingAlpha) {
        pushAlpha += alphaSpeed;
        if (pushAlpha >= 255) {
            pushAlpha = 255;
            isIncreasingAlpha = false; // アルファ値が最大になったら減少に切り替え
        }
    }
    else {
        pushAlpha -= alphaSpeed;
        if (pushAlpha <= 0) {
            pushAlpha = 0;
            isIncreasingAlpha = true; // アルファ値が最小になったら増加に切り替え
        }
    }
    Image::SetAlpha(hPush_, pushAlpha);

}

void WaitScene::Draw()
{
    // モデル
    Model::SetTransform(hBuilding1_, buildTrans1_);
    Model::Draw(hBuilding1_);
    Model::SetTransform(hBuilding2_, buildTrans2_);
    Model::Draw(hBuilding2_);

    // 画像
    Image::SetTransform(hBack_, picTrans_);
    Image::Draw(hBack_);
    Image::SetTransform(hReady_, transform_);
    Image::Draw(hReady_);
    Image::SetTransform(hPush_, pushTrans_);
    Image::Draw(hPush_);

    // 文字
	pText->Draw(SCORE_POS_X, SCORE_POS_Y, "Score:0");
	pText->Draw(TIME_POS_X, TIME_POS_Y, "Time: 0");

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
