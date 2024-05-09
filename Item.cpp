#include "Item.h"
#include "SpeedDown.h"
#include "JumpUp.h"
#include "ScoreUp.h"
#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

Item::Item(GameObject* parent)
	:GameObject(parent, "Item")
{
}

Item::~Item()
{
}

void Item::Initialize()
{
    srand((unsigned int)time(nullptr));
}

void Item::Update()
{
   /* frame += 1;
    if (frame % (FPS * 5) == 0)
    {
        rd = rand() % 100;
        switch (rd) {
        case 1:

        }
    }*/
}

void Item::Draw()
{
}

void Item::Release()
{
}

//‰½‚©‚É“–‚½‚Á‚½
void Item::OnCollision(GameObject * pTarget)
{
    //“–‚½‚Á‚½‚Æ‚«
    if (pTarget->GetObjectName() == "Stage")
    {
        //this->KillMe();
    }
}