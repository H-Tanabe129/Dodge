#include "PlayScene.h"
#include "Stage.h"
#include "Item.h"
#include "ValueManager.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene"), pText(nullptr), pPlayer_(nullptr), hSound_(-1)
{
}

PlayScene::~PlayScene()
{
	delete pText;
	delete pPlayer_;
}

//������
void PlayScene::Initialize()
{

	Camera::SetPosition(XMFLOAT3(CPosiX, CPosiY, CPosiZ));
	Camera::SetTarget(XMFLOAT3(CTarX, CTarY, CTarZ));

	// ���ׂĂ̎q�I�u�W�F�N�g���폜
	KillAllChildren();
	
	//Instantiate<Player>(this);
	Instantiate<Stage>(this);
	Instantiate<Item>(this);

	// Player �N���X�̃C���X�^���X�𐶐�
	pPlayer_ = new Player(this);
	pPlayer_->Initialize();

	pText = new Text;
	pText->Initialize();

	ValueManager::GetInstance().ResetScore();
	ValueManager::GetInstance().ResetTime();
}

//�X�V
void PlayScene::Update()
{
	if (pPlayer_) {
		pPlayer_->Update();
	}

	ValueManager::GetInstance().AddScore(score);
	ValueManager::GetInstance().AddTime();
}

//�`��
void PlayScene::Draw()
{
	pText->Draw(scoreX, scoreY, "Score:");
	pText->Draw(scoreX+100, scoreY, ValueManager::GetInstance().GetScore());
	pText->Draw(timeX, timeY, "Time: ");
	pText->Draw(timeX+100, timeY, ValueManager::GetInstance().GetTime());

	if (pPlayer_) {
		pPlayer_->Draw();
	}
}

//�J��
void PlayScene::Release()
{
	if (pText) {
		pText->Release(); // ���\�[�X�����
		delete pText;     // �����������
		pText = nullptr;  // �|�C���^�𖳌���
	}

	if (pPlayer_) {
		pPlayer_->Release();
		delete pPlayer_;
		pPlayer_ = nullptr;
	}
}

// �q�I�u�W�F�N�g��S�č폜
void PlayScene::KillAllChildren()
{
	for (auto& child : *GetChildList())  // �|�C���^���f���t�@�����X���ă��X�g���擾
	{
		child->KillMe();
	}
	GetChildList()->clear();  // �|�C���^���f���t�@�����X���ă��X�g���N���A
}