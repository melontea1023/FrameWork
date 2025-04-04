#include"Game.h"
#include"SceneManager.h"
#include"DXRenderer.h"
#include "TitleScene.h"

//sceneManager=currentScene内の処理

// コンストラクタ
Game::Game()
{

}

// デストラクタ
Game::~Game()
{
	SceneManager::GetInstance().Uninit();
}

// 初期化
void Game::Init()
{
    Renderer::Init();//Dx初期化
	SceneManager::GetInstance().Init(std::make_unique<TitleScene>());
}

// 更新
void Game::Update() {
    SceneManager::GetInstance().Update();
}

// 描画
void Game::Draw() {
    //std::cout << "Game::Draw()" << std::endl;  //  OK
    Renderer::Begin();
    SceneManager::GetInstance().Draw();
    Renderer::End();
}

// 終了処理
void Game::Uninit() {
    SceneManager::GetInstance().Uninit();
    Renderer::Uninit();
}

// シーンを切り替える
void Game::ChangeScene(SceneName sceneName) {
    SceneManager::GetInstance().ChangeScene(sceneName);
}