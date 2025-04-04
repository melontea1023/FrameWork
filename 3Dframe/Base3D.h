#pragma once
#include "BaseRender.h"
#include "MeshRenderer.h"

// 3D の基盤クラス
class Base3D : public BaseRender {
protected:
    MeshRenderer meshRenderer; // メッシュレンダラー

public:
    Base3D() {
        name = "Base3D";
        id = "Base3D00";
    }

    virtual void Draw() override = 0; // 純粋仮想関数（各派生クラスで実装）
};