#pragma once
#include <DirectXMath.h>
#include <string>

// 2D 描画用のデータ構造体
struct Texture2DData {
    DirectX::XMFLOAT2 position; // 2D 画面上の位置（左上基準）
    DirectX::XMFLOAT2 size;     // 幅・高さ
    float rotation;             // 回転角度（ラジアン）
    std::string texturePath;    // テクスチャのパス
    DirectX::XMFLOAT4 color;    // 色（RGBA）

    float uvU, uvV; // UV座標
    float uvWidth, uvHeight;

    // **初期化**
    Texture2DData()
        : position(0.0f, 0.0f), size(100.0f, 100.0f), rotation(0.0f),
        texturePath(""), color(1.0f, 1.0f, 1.0f, 1.0f),
        uvU(0), uvV(0), uvWidth(1), uvHeight(1) {}
};
