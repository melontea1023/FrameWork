#pragma once  // ヘッダーの多重インクルードを防ぐ

#include "ResourceManager.h"  // 汎用リソースマネージャを利用
#include "Model.h"            // モデルクラスを利用

/*
    ModelManager クラス
    - ResourceManager<Model> を継承し、モデル管理を担当
    - シングルトンパターンを使用し、一つのインスタンスを提供
*/
class ModelManager : public ResourceManager<Model> {
public:
    // シングルトンのインスタンスを取得
    static ModelManager& GetInstance() {
        static ModelManager instance;  // 静的インスタンス
        return instance;
    }
};
