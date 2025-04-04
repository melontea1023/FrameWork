#pragma once
#include "BaseRender.h"
#include "MeshRenderer.h"

// 3D �̊�ՃN���X
class Base3D : public BaseRender {
protected:
    MeshRenderer meshRenderer; // ���b�V�������_���[

public:
    Base3D() {
        name = "Base3D";
        id = "Base3D00";
    }

    virtual void Draw() override = 0; // �������z�֐��i�e�h���N���X�Ŏ����j
};