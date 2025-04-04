#pragma once
#include<memory>
#include"Scene.h"
//�V�[���̃C���N���[�h

class SceneManager {
private:
	std::unique_ptr<Scene> currentScene;
	static SceneManager instance;  // �V���O���g���̃C���X�^���X
public:
	void Init(std::unique_ptr<Scene> firstScene); // �ŏ��̃V�[����ݒ�
	void Update();	// �X�V����
	void Draw();	// �`�揈��
	void Uninit();	// �I������
	void ChangeScene(SceneName nextSceneName);//
	void FinishScene();//�V�[����Uninit��delete�@���������

	static SceneManager& GetInstance();  // �V���O���g���̃C���X�^���X���擾

	inline Scene* GetCurrentScene() { return currentScene.get(); };
};