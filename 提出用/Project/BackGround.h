#pragma once
#include "Engine/GameObject.h"
#include "Engine/Image.h"

class BackGround : public GameObject
{
private:
    int hPict_;    //�摜�ԍ�
public:
 //�R���X�g���N�^
 BackGround(GameObject* parent);

 ~BackGround();

 //������
 void Initialize() override;

 //�X�V
 void Update() override;

 //�`��
 void Draw() override;

 //�J��
 void Release() override;
};
