#pragma once
#include <vector>
#include "Engine/GameObject.h"
#include "Engine/BoxCollider.h"

class Stage : public GameObject
{
private:
    int hModel_;    //���f���ԍ�
    Transform StaUpper;
    Transform StaLower;

    // �R���C�_�[���i�[����std::vector
    std::vector<Collider*> colliders_;
public:
    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    // �R���C�_�[�ւ̃A�N�Z�X��񋟂��郁�\�b�h
    Collider* GetCollider(size_t index) const;
};