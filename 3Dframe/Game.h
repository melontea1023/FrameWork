#pragma once
#include<iostream>
#include"SceneManager.h"


class Game
{
public:
	Game(); // �R���X�g���N�^
	~Game(); // �f�X�g���N�^

	void Init(); // ������
	void Update(); // �X�V
	void Draw(); // �`��
	void Uninit(); // �I������

	void ChangeScene(SceneName sceneName); // �V�[����ύX

};
