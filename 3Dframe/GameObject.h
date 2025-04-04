#pragma once
#include "Object.h"
#include <utility>

class GameObject : public Object
{
private:
	//���j�[�N�|�C���^�̃��X�g
	std::vector<std::unique_ptr<Object>> components;
public:
	// �R���X�g���N�^
	GameObject();

	// �f�X�g���N�^�i�������J��
	~GameObject();

    bool Init() override {return true;}
	void Update() override;
	void Draw() override;
	void Uninit() override;

	// �R���|�[�l���g��ǉ�
	// �R���|�[�l���g�̃R���X�g���N�^�ɓn�����C�ӂ̈������󂯎�邽��
	template<typename T, typename... Args>
	T* AddComponent(Args&&... args) {
		// T�^�̃R���|�[�l���g�𓮓I�ɐ���
		std::unique_ptr<T> component = std::make_unique<T>(std::forward<Args>(args)...);
		// ���݂̃I�u�W�F�N�g�ithis�j�����L�҂Ƃ��Đݒ�
		component->SetOwner(this); 
		// ���������R���|�[�l���g�� components�@�����X�g�ɒǉ�

		T* rawPointer = component.get();  // unique_ptr ���� T* ���擾
		components.push_back(std::move(component));  // move �ŏ��L�����ڂ�
	
		// ���������R���|�[�l���g�ւ̃|�C���^��Ԃ�
		return rawPointer;
	}

	// �R���|�[�l���g���擾
	//�@T�@�͎擾�������R���|�[�l���g�̌^��\��
	template<typename T>
	T* GetComponent() {
		//�@�Q�[���I�u�W�F�N�g�������Ă��郊�X�g�̃��[�v
		for (auto& comp : components) {
			//�@comp �� Object* �^�̃|�C���^�ł���AT* �^�ɃL���X�g�i�ϊ��j����܂��B
			//�@�����Acomp �����ۂ� T �^�̃I�u�W�F�N�g�ł���΁Adynamic_cast �͂��̃|�C���^��Ԃ�
			if (auto target = dynamic_cast<T*>(comp)) {
				// �R���|�[�l���g�̃R���X�g���N�^�ɓn�����C�ӂ̈������󂯎�邽
				return target;
			}
		}
		return nullptr; // ������Ȃ������ꍇ
	}

};