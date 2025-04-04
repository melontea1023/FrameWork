#include "Scene.h"

void Scene::Update() {
    for (auto obj : objects) {
        obj->Update();  // �e�I�u�W�F�N�g�� Update() ���Ă�
    }
}

// ���X�g���̃I�u�W�F�N�g��`��
void Scene::Draw() {
    for (auto obj : objects) {
        std::cout << "Scene::Draw() objects.size: " << objects.size() << std::endl;
        obj->Draw();
    }
}

// �V�[���I�����Ƀ��X�g���̃I�u�W�F�N�g���폜
void Scene::Uninit() {
    for (auto obj : objects) {
        delete obj; // ���������
    }
    objects.clear();
}

//  �Q�[���I�u�W�F�N�g�����X�g�ɒǉ�����
void Scene::AddObject(GameObject* obj)
{
	objects.push_back(obj);
}
