#include "SceneManager.h"
#include "TitleScene.h"
#include <iostream>



// �V���O���g���̃C���X�^���X���`
SceneManager SceneManager::instance;


SceneManager& SceneManager::GetInstance() {
    return instance;
}



void SceneManager::Init(std::unique_ptr<Scene> firstScene) {
    currentScene = std::move(firstScene);
    currentScene->Init();
}

void SceneManager::Update() {
    if (currentScene) {
        currentScene->Update();
    }
}


void SceneManager::Draw() {
    if (currentScene) {
        //std::cout << "SceneManager::Draw()" << std::endl;  //OK
        currentScene->Draw();
    }
}


void SceneManager::Uninit() {
    currentScene.reset();  // ���j�[�N�|�C���^�ň��S�ɍ폜
}

void SceneManager::ChangeScene(SceneName nextSceneName) {
    FinishScene();  // �����̃V�[�����폜

    switch (nextSceneName) {
    case SceneName::TITLE:
        currentScene = std::make_unique<TitleScene>();  // �^�C�g���V�[�����쐬
        break;
    //case SceneName::GAME:
    //    currentScene = std::make_unique<GameScene>();  // �Q�[���V�[�����쐬
    //    break;
    }

    if (currentScene) {
        currentScene->Init();  // �V�[���̏�����
    }
}

void SceneManager::FinishScene() {
    currentScene.reset();  // �V�[�����폜�i����������j
}
