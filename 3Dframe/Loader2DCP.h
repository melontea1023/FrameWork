#pragma once
#include "Component.h"
#include "Texture.h"
#include <memory>
#include <string>

// �e�N�X�`�������[�h����N���X
class Loader2DCP : public Component {
private:
    std::string texturePath;
    std::unique_ptr<Texture> texture;

public:
    Loader2DCP();
    ~Loader2DCP();

    void LoadTexture(const std::string& filename);
    Texture* GetTexture() const;
    std::string GetTexturePath() const;
};
