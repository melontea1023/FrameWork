#include "Texture2DCP.h"
#include "DXRenderer.h"
#include "Application.h"
#include <DirectXMath.h>
#include <iostream>

// コンストラクタ
Texture2DCP::Texture2DCP()
    : position(0.0f, 0.0f), size(100.0f, 100.0f), rotation(0.0f) {}

// デストラクタ
Texture2DCP::~Texture2DCP() {}

// 初期化処理
bool Texture2DCP::Init() {
    std::cout << "Texture2DCP::Init() called" << std::endl;

    std::vector<VERTEX_3D> vertices(4);
    vertices[0].position = { -0.5f,  0.5f, 0 };
    vertices[1].position = { 0.5f,  0.5f, 0 };
    vertices[2].position = { -0.5f, -0.5f, 0 };
    vertices[3].position = { 0.5f, -0.5f, 0 };

    vertices[0].uv = { 0, 0 };
    vertices[1].uv = { 1, 0 };
    vertices[2].uv = { 0, 1 };
    vertices[3].uv = { 1, 1 };

    m_VertexBuffer.Create(vertices);

    std::vector<unsigned int> indices = { 0, 1, 2, 3 };
    m_IndexBuffer.Create(indices);

    m_Shader.Create("shader/unlitTextureVS.hlsl", "shader/unlitTexturePS.hlsl");

    m_Material = std::make_unique<Material>();
    MATERIAL mtrl = {};
    mtrl.Diffuse = { 1, 1, 1, 1 };
    mtrl.Shiness = 1;
    mtrl.TextureEnable = true;

    if (!m_Material->Create(mtrl)) {
        std::cerr << "Material作成に失敗" << std::endl;
        return false;
    }
    std::cout << "[Init] 頂点バッファ/インデックスバッファ/シェーダー初期化完了" << std::endl;

    return true;
}

// 更新処理
void Texture2DCP::Update() {
    // 特に処理なし
}

// 描画処理
void Texture2DCP::Draw() {
    std::cout << "[Texture2DCP::Draw] path = " << texturePath << std::endl;
    if (texturePath.empty()) return;

    float screenWidth = static_cast<float>(Application::GetWidth());
    float screenHeight = static_cast<float>(Application::GetHeight());

    DirectX::SimpleMath::Matrix scale = DirectX::SimpleMath::Matrix::CreateScale(
        size.x / screenWidth * 2.0f,
        size.y / screenHeight * 2.0f,
        1.0f
    );

    DirectX::SimpleMath::Matrix rot = DirectX::SimpleMath::Matrix::CreateRotationZ(rotation);

    DirectX::SimpleMath::Matrix trans = DirectX::SimpleMath::Matrix::CreateTranslation(
        (position.x / screenWidth) * 2.0f - 1.0f,
        (position.y / screenHeight) * -2.0f + 1.0f,
        0.0f
    );

    DirectX::SimpleMath::Matrix world = scale * rot * trans;
    Renderer::SetWorldMatrix(&world);

    Renderer::SetUV(m_NumU, m_NumV, 1.0f / m_SplitX, 1.0f / m_SplitY);

    Renderer::SetCamera(1);

    ID3D11DeviceContext* ctx = Renderer::GetDeviceContext();
    ctx->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

    m_Shader.SetGPU();
    m_VertexBuffer.SetGPU();
    m_IndexBuffer.SetGPU();
    m_Texture.SetGPU();
    m_Material->SetGPU();

    ctx->DrawIndexed(4, 0, 0);
}


// 終了処理
void Texture2DCP::Uninit() {
    // 解放処理があればここに記述
}

void Texture2DCP::SetTexture(const char* imgname) {
    bool ok = m_Texture.Load(imgname);
    std::cout << "[SetTexture] path: " << imgname << " Load: " << (ok ? "OK" : "FAIL") << std::endl;
    if (ok) {
        texturePath = imgname;
    }
}

void Texture2DCP::SetUV(const float& nu, const float& nv, const float& sx, const float& sy) {
    m_NumU = nu;
    m_NumV = nv;
    m_SplitX = sx;
    m_SplitY = sy;
}

void Texture2DCP::SetPosition(float x, float y) {
    position = DirectX::SimpleMath::Vector2(x, y);
}

void Texture2DCP::SetSize(float width, float height) {
    size = DirectX::SimpleMath::Vector2(width, height);
}

void Texture2DCP::SetRotation(float angle) {
    rotation = angle * 3.14159265f / 180.0f;
}