#pragma once
#include <DirectXMath.h>
#include <string>

// 2D �`��p�̃f�[�^�\����
struct Texture2DData {
    DirectX::XMFLOAT2 position; // 2D ��ʏ�̈ʒu�i�����j
    DirectX::XMFLOAT2 size;     // ���E����
    float rotation;             // ��]�p�x�i���W�A���j
    std::string texturePath;    // �e�N�X�`���̃p�X
    DirectX::XMFLOAT4 color;    // �F�iRGBA�j

    float uvU, uvV; // UV���W
    float uvWidth, uvHeight;

    // **������**
    Texture2DData()
        : position(0.0f, 0.0f), size(100.0f, 100.0f), rotation(0.0f),
        texturePath(""), color(1.0f, 1.0f, 1.0f, 1.0f),
        uvU(0), uvV(0), uvWidth(1), uvHeight(1) {}
};
