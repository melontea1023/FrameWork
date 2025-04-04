#include "Render2DCP.h"
#include "DXRenderer.h"
#include <iostream>

// コンストラクタ
Render2DCP::Render2DCP() : texture(nullptr) {}

// デストラクタ
Render2DCP::~Render2DCP() {}

// Loader2DCP から受け取ったテクスチャをセット
void Render2DCP::SetTexture(Texture* tex) {
    if (!tex) {
        std::cerr << "Error: Render2DCP::SetTexture() received nullptr!" << std::endl;
        return;
    }

    std::cout << "Render2DCP::SetTexture() called" << std::endl;
    texture = tex;
}

//// `Loader2DCP` を使用しない場合のため、直接テクスチャパスをセット
//void Render2DCP::SetTexturePath(const std::string& path) {
//    texture = new Texture();  // 直接ロード
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

    texture->SetGPU();  // GPUにセット

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