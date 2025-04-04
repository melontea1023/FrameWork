#pragma once
#include "Scene.h"
#include "TitleObject.h"

// タイトルシーン
class TitleScene : public Scene {
public:
    TitleScene();//  コンストラクタ
    void Init() override;
    void Update() override;
    void Draw() override;
};