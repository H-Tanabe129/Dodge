#include "Player.h"
#include "Ready.h"
#include "ValueManager.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Audio.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"

Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1), hSound_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
    //サウンドデータのロード
    hSound_ = Audio::Load("A1_18278.WAV");
    assert(hSound_ >= 0);

    //モデルデータのロード
    hModel_ = Model::Load("Model/Player.fbx");
    assert(hModel_ >= 0);
	transform_.position_.z = posiZ;
	transform_.position_.y = posiY;

	SphereCollider* collision = 
		new SphereCollider(XMFLOAT3(SColliderX, SColliderY, SColliderZ), radius);
	AddCollider(collision);
}

void Player::Update()
{
	//Readyしてからstart
	/*Ready* pReady = (Ready*)FindObject("Ready");
	if (pReady != nullptr && !pReady->Finished())
		return;*/

	if (transform_.position_.y >= edge || transform_.position_.y <= -edge)
	{
		this->KillMe();

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}

}

void Player::Jump()
{

    //スペースキーが押されていたらジャンプ
	float velocity = veloIni;
	if (Input::IsKey(DIK_SPACE))
    {
		velocity = veloIncre;
		Audio::Play(hSound_);
	}
	if (Input::IsKeyUp(DIK_SPACE))//velocity != veloIni
	{
		// ここが重力で徐々に下げる
		velocity -= veloDecre;

		//キャラクターの場所に値を渡す
		transform_.position_.y += velocity;
    }
}

void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void Player::Release()
{
}

//何かに当たった
void Player::OnCollision(GameObject * pTarget)
{
	if (pTarget->GetObjectName() == "StageUp" || "StageLo")
    {
		this->KillMe();
		pTarget->KillMe();

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
    }
}