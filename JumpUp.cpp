#include "JumpUp.h"
#include "ValueManager.h"

JumpUp::JumpUp(GameObject* parent)
    : ItemBase(parent), GameObject(parent, "JumpUp"), hJump_(-1)
{
}

JumpUp::~JumpUp()
{
}

void JumpUp::Initialize()
{
    // モデルデータのロード
    hModel_ = Model::Load("Model/JumpUp.fbx");
    assert(hModel_ >= 0);
}

void JumpUp::Update()
{
}

void JumpUp::OnCollision(GameObject* pTarget)
{
    if (pTarget->GetObjectName() == "Player") {
    }
}
