#pragma once
#include "GameObject.h"
#include "Loader2DCP.h"
#include "Render2DCP.h"
#include "Texture2DCP.h"

// �^�C�g����ʂ̃I�u�W�F�N�g
class TitleObject : public GameObject {
public:
    bool chek;
    TitleObject();

    bool Init() override;
    void Draw() override;
};
