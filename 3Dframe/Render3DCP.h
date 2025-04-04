#pragma once
#include "Base3D.h"
#include "Mesh.h"

// 3D �`��p�R���|�[�l���g
class Render3DCP : public Base3D {
protected:
    Mesh mesh; // 3D ���b�V��

public:
    Render3DCP() {
        name = "Render3DCP";
        id = "Render3DCP01";
    }

    void Draw() override {
        shader.SetGPU();
        std::shared_ptr<Texture>SetGPU();
        meshRenderer.BeforeDraw();
        meshRenderer.Draw();
    }
};
