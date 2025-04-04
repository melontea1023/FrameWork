#pragma once
#include "GameObject.h"
#include "Loader2DCP.h"
#include "Render2DCP.h"
#include "Texture2DCP.h"

// タイトル画面のオブジェクト
class TitleObject : public GameObject {
public:
    bool chek;
    TitleObject();

    bool Init() override;
    void Draw() override;
};
