#pragma once
#include "Engine/GameObject.h"

class TitleScene : public GameObject
{
private:
    int hPict_;    //�摜�ԍ�
    int hStart_;    //�摜�ԍ�
    Transform Title;
public:
 //�R���X�g���N�^
 //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
 TitleScene(GameObject* parent);

 //������
 void Initialize() override;

 //�X�V
 void Update() override;

 //�`��
 void Draw() override;

 //�J��
 void Release() override;
};

