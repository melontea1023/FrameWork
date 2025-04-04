#pragma once
#include"Object.h"
#include <memory>

//  �R���|�[�l���g�̐e�N���X
class Component : public Object {
protected:
    Object* owner = nullptr;//���̃R���|�[�l���g�����L����I�u�W�F�N�g

public:
    Component(){
        name = "component";
        id = "component0";
        objectType = ObjectType::COMPONENT;
    }

    // ���L�҂̐ݒ�
    //�@�Z�b�^�[�Ȃ̂� inline ����
    inline void SetOwner(Object* newOwner)
    {
        owner = newOwner;
    }

    // ���L�҂��擾
    //�@�Q�b�^�[�Ȃ̂� inline ����
    inline Object* GetOwner()
    {
        return owner;
    }

    bool Init() override { return true; }// true��Ԃ��Ȃ��Ə��������Ȃ�����
    void Update() override {}
    void Draw() override {}
    void Uninit() override {}
};