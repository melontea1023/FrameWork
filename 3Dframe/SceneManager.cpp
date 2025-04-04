#include "SceneManager.h"
#include "TitleScene.h"
#include <iostream>



// シングルトンのインスタンスを定義
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
    currentScene.reset();  // ユニークポインタで安全に削除
}

void SceneManager::ChangeScene(SceneName nextSceneName) {
    FinishScene();  // 既存のシーンを削除

    switch (nextSceneName) {
    case SceneName::TITLE:
        currentScene = std::make_unique<TitleScene>();  // タイトルシーンを作成
        break;
    //case SceneName::GAME:
    //    currentScene = std::make_unique<GameScene>();  // ゲームシーンを作成
    //    break;
    }

    if (currentScene) {
        currentScene->Init();  // シーンの初期化
    }
}

void SceneManager::FinishScene() {
    currentScene.reset();  // シーンを削除（メモリ解放）
}
