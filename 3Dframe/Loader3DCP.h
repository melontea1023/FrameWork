#pragma once
#include "Base3D.h"
#include "Mesh.h"
#include "Texture.h"
#include "MeshRenderer.h"

// 3D モデルローダー
class Loader3DCP : public Component {
protected:
    Mesh mesh; // 3D メッシュ
    MeshRenderer meshRenderer;
public:
    Loader3DCP() { name = "Loader3DCP"; }

    void LoadModel(const std::string& filename) {
        mesh.Load(filename);
        meshRenderer.Init(mesh);
    }
};
