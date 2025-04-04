#include "TitleScene.h"
#include "SceneManager.h"
#include <iostream>

TitleScene::TitleScene() {}

void TitleScene::Init() {
    std::cout << "TitleScene::Init() called" << std::endl;

    // タイトルオブジェクトを作成
    TitleObject* titleObj = new TitleObject();
    if (titleObj) {
        std::cout << "TitleObject created" << std::endl;
        titleObj->Init();
        AddObject(titleObj);
    }
    else {
        std::cerr << "Error: Failed to create TitleObject" << std::endl;
    }
}

void TitleScene::Update() {

    Scene::Update();
    // キーボー入力 (Enter)
    if (Input::GetKeyTrigger(VK_RETURN)) {
        std::cout << "キーボード:Enter" << std::endl;
        SceneManager::GetInstance().ChangeScene(SceneName::GAME);
    }

    // XInput
    if (Input::GetXInputButtonTrigger(XINPUT_START)) {
        std::cout << "XInput:Start" << std::endl;
        SceneManager::GetInstance().ChangeScene(SceneName::GAME);
    }

    // DirectInput
    if (Input::GetDInputButtonTrigger(DINPUT_BUTTON_START)) {
        std::cout << "DirectInput:Start" << std::endl;
        SceneManager::GetInstance().ChangeScene(SceneName::GAME);
    }
}


void TitleScene::Draw() {
    std::cout << "[TitleScene::Draw]" << std::endl;
    Scene::Draw();
}


