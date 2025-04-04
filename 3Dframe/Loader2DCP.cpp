#include "Loader2DCP.h"
#include "Texture.h"
#include <iostream>

// �R���X�g���N�^
Loader2DCP::Loader2DCP() {}

// �f�X�g���N�^
Loader2DCP::~Loader2DCP() {}

// �e�N�X�`�������[�h
void Loader2DCP::LoadTexture(const std::string& filename) {
    texturePath = filename;
    texture = std::make_unique<Texture>();

    if (!texture->Load(filename)) {
        std::cerr << "Error: Failed to load texture: " << filename << std::endl;
        texture.reset(); // ���s���� nullptr �Ƀ��Z�b�g
    }
    else {
        std::cout << "Loader2DCP: Texture loaded successfully: " << filename << std::endl;
    }
}

// �e�N�X�`�����擾
Texture* Loader2DCP::GetTexture() const {
    return texture.get();
}

// �e�N�X�`���p�X���擾
std::string Loader2DCP::GetTexturePath() const {
    return texturePath;
}
