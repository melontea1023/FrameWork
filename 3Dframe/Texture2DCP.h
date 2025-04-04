#pragma once
#include "Component.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Material.h"
#include <memory>
#include <vector>

// 2D テクスチャ描画用のコンポーネント
class Texture2DCP : public Component {
private:
    Shader m_Shader;
    Texture m_Texture;
    VertexBuffer<VERTEX_3D> m_VertexBuffer;
    IndexBuffer m_IndexBuffer;
    std::unique_ptr<Material> m_Material;

    DirectX::XMFLOAT2 position; // 位置
    DirectX::XMFLOAT2 size;     // サイズ
    float rotation;             // 回転（ラジアン）
    std::string texturePath;    // テクスチャのパス

    // UV座標の情報
    float m_NumU = 1;
    float m_NumV = 1;
    float m_SplitX = 1;
    float m_SplitY = 1;
public:
    Texture2DCP();
    ~Texture2DCP();

    bool Init() override; // **初期化（bool 型）**
    void Update() override;
    void Draw() override;
    void Uninit() override;

    void SetTexture(const char* imgname);
    void SetPosition(float x, float y);
    void SetSize(float width, float height);
    void SetRotation(float angle);

    // UV座標を指定
    void SetUV(const float& nu, const float& nv, const float& sx, const float& sy);
};
