#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<DirectXMath.h>
#include<memory.h>


enum ObjectType{
	GAMEOBJECT = 0,	// 	�R���|�[�l���g�����L����I�u�W�F�N�g
	COMPONENT = 1	// 	�I�u�W�F�N�g�ɏ��L�����R���|�[�l���g
};

//�ŏ�ʂ̐e�N���X
class Object
{
protected:


	std::string name = "";
	std::string id = "";
	ObjectType objectType = ObjectType::GAMEOBJECT;

	bool isActive = false;// true�̏ꍇ�A���g��Update��Draw��ʂ��悤�ɂ���

public:
	//	�������������z�֐�������
	virtual bool Init() = 0;	// ������ ����������true��Ԃ��悤�ɂ���
	virtual void Update() = 0;	// �X�V����
	virtual void Draw() = 0;	// �`�揈��
	virtual void Uninit() = 0;	// �I������
};