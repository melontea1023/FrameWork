#pragma once
#include "Component.h"
#include "Shader.h"
#include "Texture.h"

// 2D•`‰æ‚ğs‚¤ƒNƒ‰ƒX
class Render2DCP : public Component {
private:
    Shader m_Shader;
    Texture* texture;
    bool chek=false;
public:
    Render2DCP();
    ~Render2DCP();

    void SetTexture(Texture* tex);
    //void SetTexturePath(const std::string& path);
    void Draw() override;
};
