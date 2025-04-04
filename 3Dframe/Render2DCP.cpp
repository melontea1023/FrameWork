#include "Render2DCP.h"
#include "DXRenderer.h"
#include <iostream>

// �R���X�g���N�^
Render2DCP::Render2DCP() : texture(nullptr) {}

// �f�X�g���N�^
Render2DCP::~Render2DCP() {}

// Loader2DCP ����󂯎�����e�N�X�`�����Z�b�g
void Render2DCP::SetTexture(Texture* tex) {
    if (!tex) {
        std::cerr << "Error: Render2DCP::SetTexture() received nullptr!" << std::endl;
        return;
    }

    std::cout << "Render2DCP::SetTexture() called" << std::endl;
    texture = tex;
}

//// `Loader2DCP` ���g�p���Ȃ��ꍇ�̂��߁A���ڃe�N�X�`���p�X���Z�b�g
//void Render2DCP::SetTexturePath(const std::string& path) {
//    texture = new Texture();  // ���ڃ��[�h
//    if (!texture->Load(path)) {
//        std::cerr << "Error: Failed to load texture: " << path << std::endl;
//        delete texture;
//        texture = nullptr;
//    }
//}

void Render2DCP::Draw() {
    //if (chek == false) {
    //    std::cout << "Render2DCP::Draw() called" << std::endl;
    //    chek = true;
    //}

    if (!texture) {
        std::cerr << "Error: No texture set in Render2DCP" << std::endl;
        return;
    }

    texture->SetGPU();  // GPU�ɃZ�b�g

    ID3D11DeviceContext* context = Renderer::GetDeviceContext();
    if (!context) {
        std::cerr << "Error: DeviceContext is nullptr" << std::endl;
        return;
    }
    if (chek == false) {
        std::cout << "Render2DCP::Draw() - Applying shader" << std::endl;
        chek = true;
    }
    m_Shader.SetGPU();
    context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
    context->DrawIndexed(4, 0, 0);
}