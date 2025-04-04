#include"Game.h"
#include"SceneManager.h"
#include"DXRenderer.h"
#include "TitleScene.h"

//sceneManager=currentScene���̏���

// �R���X�g���N�^
Game::Game()
{

}

// �f�X�g���N�^
Game::~Game()
{
	SceneManager::GetInstance().Uninit();
}

// ������
void Game::Init()
{
    Renderer::Init();//Dx������
	SceneManager::GetInstance().Init(std::make_unique<TitleScene>());
}

// �X�V
void Game::Update() {
    SceneManager::GetInstance().Update();
}

// �`��
void Game::Draw() {
    //std::cout << "Game::Draw()" << std::endl;  //  OK
    Renderer::Begin();
    SceneManager::GetInstance().Draw();
    Renderer::End();
}

// �I������
void Game::Uninit() {
    SceneManager::GetInstance().Uninit();
    Renderer::Uninit();
}

// �V�[����؂�ւ���
void Game::ChangeScene(SceneName sceneName) {
    SceneManager::GetInstance().ChangeScene(sceneName);
}