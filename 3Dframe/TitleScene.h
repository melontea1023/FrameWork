#pragma once
#include "Scene.h"
#include "TitleObject.h"

// �^�C�g���V�[��
class TitleScene : public Scene {
public:
    TitleScene();//  �R���X�g���N�^
    void Init() override;
    void Update() override;
    void Draw() override;
};