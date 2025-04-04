#pragma once  // ヘッダーの多重インクルードを防ぐ

#include "ResourceManager.h"  // 汎用リソースマネージャを利用
#include "Texture.h"          // テクスチャクラスを利用

/*
    TextureManager クラス
    - ResourceManager<Texture> を継承し、テクスチャ管理を担当
    - シングルトンパターンを使用し、一つのインスタンスを提供
*/
class TextureManager : public ResourceManager<Texture> {
public:
    // シングルトンのインスタンスを取得
    static TextureManager& GetInstance() {
        static TextureManager instance;  // 静的インスタンス
        return instance;
    }
};
