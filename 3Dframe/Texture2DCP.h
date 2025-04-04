#pragma once
#include "Component.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Material.h"
#include <memory>
#include <vector>

// 2D �e�N�X�`���`��p�̃R���|�[�l���g
class Texture2DCP : public Component {
private:
    Shader m_Shader;
    Texture m_Texture;
    VertexBuffer<VERTEX_3D> m_VertexBuffer;
    IndexBuffer m_IndexBuffer;
    std::unique_ptr<Material> m_Material;

    DirectX::XMFLOAT2 position; // �ʒu
    DirectX::XMFLOAT2 size;     // �T�C�Y
    float rotation;             // ��]�i���W�A���j
    std::string texturePath;    // �e�N�X�`���̃p�X

    // UV���W�̏��
    float m_NumU = 1;
    float m_NumV = 1;
    float m_SplitX = 1;
    float m_SplitY = 1;
public:
    Texture2DCP();
    ~Texture2DCP();

    bool Init() override; // **�������ibool �^�j**
    void Update() override;
    void Draw() override;
    void Uninit() override;

    void SetTexture(const char* imgname);
    void SetPosition(float x, float y);
    void SetSize(float width, float height);
    void SetRotation(float angle);

    // UV���W���w��
    void SetUV(const float& nu, const float& nv, const float& sx, const float& sy);
};
