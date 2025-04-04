#include "Loader2DCP.h"
#include "Texture.h"
#include <iostream>

// コンストラクタ
Loader2DCP::Loader2DCP() {}

// デストラクタ
Loader2DCP::~Loader2DCP() {}

// テクスチャをロード
void Loader2DCP::LoadTexture(const std::string& filename) {
    texturePath = filename;
    texture = std::make_unique<Texture>();

    if (!texture->Load(filename)) {
        std::cerr << "Error: Failed to load texture: " << filename << std::endl;
        texture.reset(); // 失敗時は nullptr にリセット
    }
    else {
        std::cout << "Loader2DCP: Texture loaded successfully: " << filename << std::endl;
    }
}

// テクスチャを取得
Texture* Loader2DCP::GetTexture() const {
    return texture.get();
}

// テクスチャパスを取得
std::string Loader2DCP::GetTexturePath() const {
    return texturePath;
}
