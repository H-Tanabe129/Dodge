#include "WaitScene.h"
#include "Player.h"
#include "BackGround.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"

WaitScene::WaitScene(GameObject* parent)
	: GameObject(parent, "WaitScene"), 
    hPict_(-1), hBack_(-1), hPush_(-1), hBuilding1_(-1), hBuilding2_(-1), pText(nullptr), pPlayer_(nullptr)
{
}

WaitScene::~WaitScene()
{
    delete pText;
    delete pPlayer_;
}

void WaitScene::Initialize()
{
    //�J����
	Camera::SetPosition(XMFLOAT3(CPosiX, CPosiY, CPosiZ));  //test == 35, 3, 0    -25
	Camera::SetTarget(XMFLOAT3(CTarX, CTarY, CTarZ));

    //���f���f�[�^�̃��[�h
    hBuilding1_ = Model::Load("Model/Back.fbx");
    assert(hBuilding1_ >= 0);
    hBuilding2_ = Model::Load("Model/Back.fbx");
    assert(hBuilding2_ >= 0);

    // �����ʒu
    buildTrans1_.position_ = XMFLOAT3(trPosiX, trPosiY, trPosiZ);
    buildTrans2_.position_ = XMFLOAT3(trBackPosiX, trPosiY, trPosiZ);

    //�摜�f�[�^�̃��[�h
    hBack_ = Image::Load("shiro.png");
    assert(hBack_ >= 0);
    hPict_ = Image::Load("Ready.png");
    assert(hPict_ >= 0);
    hPush_ = Image::Load("PSTART.png");
    assert(hPush_ >= 0);

    //�摜
    pushTrans_.position_ = XMFLOAT3(pushPosiX, pushPosiY, pushPosiZ);

    //�w�i
    picTrans_.position_ = XMFLOAT3(picPosiX, picPosiY, picPosiZ);
    picTrans_.scale_ = XMFLOAT3(picScaleX, picScaleY, picScaleZ);
    Image::SetAlpha(hBack_, picAlpha);

    // Player �N���X�̃C���X�^���X�𐶐�
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

    if (frame % (flash * FPS) == 0)
    {
        isFlashing = !isFlashing;
    }

    if (isFlashing)
    {
        pushAlpha = 0;
        Image::SetAlpha(hPush_, picAlpha);
    }
    else 
    {
        pushAlpha = 255;
        Image::SetAlpha(hPush_, picAlpha);
    }
}

void WaitScene::Draw()
{
    // ���f��
    Model::SetTransform(hBuilding1_, buildTrans1_);
    Model::Draw(hBuilding1_);
    Model::SetTransform(hBuilding2_, buildTrans2_);
    Model::Draw(hBuilding2_);

    // �摜
    Image::SetTransform(hBack_, picTrans_);
    Image::Draw(hBack_);
    Image::SetTransform(hPict_, transform_);
    Image::Draw(hPict_);
    Image::SetTransform(hPush_, pushTrans_);
    Image::Draw(hPush_);

    // ����
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
