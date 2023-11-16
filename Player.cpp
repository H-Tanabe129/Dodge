#include "Player.h"

Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Player.fbx");
    assert(hModel_ >= 0);
}

void Player::Update()
{
    //スペースキーが押されていたらジャンプ
	static float velocity = 0.0f;
	if (Input::IsKey(DIK_SPACE))
    {
		velocity = 0.15f;
	}
	if (velocity != 0.0f)
	{
		// ここが重力で徐々に下げる
		velocity -= 0.02f;

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
