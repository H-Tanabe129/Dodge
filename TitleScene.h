#pragma once
#include "Engine/GameObject.h"

class TitleScene : public GameObject
{
private:
    Transform titleTransform;
    Transform startTransform;
    int hTitle_;    //�摜�ԍ�(�^�C�g��)
    int hStart_;    //�摜�ԍ�(�X�^�[�g)

    static const int TITLE_POS_Y = 0;   //Title�摜�|�W�V����Y
    const float startPosY = -0.5f;      //START�摜�|�W�V����Y

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

