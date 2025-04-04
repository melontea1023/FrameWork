#pragma once
#include <memory>
#include"Component.h"
#include"shader.h"
#include"Texture.h"

//  描画の基底クラス（2D / 3D 共通）
class BaseRender : public Component {
protected:
    Shader m_Shader;               // シェーダー
    std::shared_ptr<Texture> texture; // テクスチャを shared_ptrで管理

public:
    BaseRender() { name = "BaseRender"; }

    // シェーダーの設定
    void SetShaderPath(const std::string& vsPath, const std::string& psPath) {
        m_Shader.Create(vsPath, psPath);
    }

    // テクスチャのセット
    void SetTexture(const std::string& filename) {
        if (!texture) {
            texture = std::make_shared<Texture>();
            texture->Load(filename);
        }
    }

    // テクスチャ取得
    std::shared_ptr<Texture> GetTexture() {
        return texture;
    }

    // 描画 (各派生クラスでオーバーライド)
    virtual void Draw() override = 0;
};