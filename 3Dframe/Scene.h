#pragma once
#include <string>
#include "Input.h"
#include "GameObject.h"

enum class SceneName {
	TITLE,
	GAME,
	RESULT
};

class Scene {
protected:
	//  GemeObject���p������Object���e�V�[���Ŏg�����߂̃��X�g
	std::vector<GameObject*>objects;
public:
	virtual void Init()=0 ;	// ������ ����������true��Ԃ��悤�ɂ���
	virtual void Update() ;	// �X�V����
	virtual void Draw() ;	// �`�揈��
	virtual void Uninit() ;	// �I������

	//  Object�̃��X�g�ɒǉ�����
	void AddObject(GameObject* obj);
 };