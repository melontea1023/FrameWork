#pragma once
#include <memory>
#include"Component.h"
#include"shader.h"
#include"Texture.h"

//  �`��̊��N���X�i2D / 3D ���ʁj
class BaseRender : public Component {
protected:
    Shader m_Shader;               // �V�F�[�_�[
    std::shared_ptr<Texture> texture; // �e�N�X�`���� shared_ptr�ŊǗ�

public:
    BaseRender() { name = "BaseRender"; }

    // �V�F�[�_�[�̐ݒ�
    void SetShaderPath(const std::string& vsPath, const std::string& psPath) {
        m_Shader.Create(vsPath, psPath);
    }

    // �e�N�X�`���̃Z�b�g
    void SetTexture(const std::string& filename) {
        if (!texture) {
            texture = std::make_shared<Texture>();
            texture->Load(filename);
        }
    }

    // �e�N�X�`���擾
    std::shared_ptr<Texture> GetTexture() {
        return texture;
    }

    // �`�� (�e�h���N���X�ŃI�[�o�[���C�h)
    virtual void Draw() override = 0;
};