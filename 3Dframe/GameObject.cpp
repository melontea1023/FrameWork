#include "GameObject.h"	

// �R���X�g���N�^
GameObject::GameObject() {
    name = "gameObject";
    id = "gameObject0";
    objectType = ObjectType::GAMEOBJECT;//���̃N���X�̃I�u�W�F�N�g�^�C�v�͒萔�^�I�u�W�F�N�g�^�C�v�̃Q�[���I�u�W�F�N�g
}

// �f�X�g���N�^�i�������J��
GameObject::~GameObject() {
	//	�����������@���j�[�N�|�C���^�Ȃ̂� delete ���Ȃ��Ă��� ����������
	//for (auto comp : components) {
	//	delete comp;  // �����I�� delete ���Ȃ��ƃ��������[�N
	//}
	components.clear();
}

void GameObject::Update() {
    for (auto& comp : components) {
        comp->Update();  // �R���|�[�l���g�� Update() ���Ă�
    }
}

void GameObject::Draw() {
    std::cout << "[GameObject::Draw] components size = " << components.size() << std::endl;

    for (auto& comp : components) {
        comp->Draw();  // ���ׂẴR���|�[�l���g�� Draw() �����s
    }
}

// �I������
void GameObject::Uninit() {
    components.clear();
}