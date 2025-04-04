#include "TitleObject.h"

// コンストラクタ（初期化処理）
TitleObject::TitleObject() {
    name = "TitleObject";
}

// 初期化処理
bool TitleObject::Init() {
    std::cout << "TitleObject::Init() called" << std::endl;

    auto textureComp = AddComponent<Texture2DCP>();

    if (!textureComp->Init()) {
        std::cerr << "Error: TitleObject::Init() - Failed to initialize Texture2DCP" << std::endl;
        return false;
    }

    textureComp->SetTexture("assets/title2.png");
    textureComp->SetPosition(200.0f, 150.0f);
    textureComp->SetSize(100.0f, 100.0f);
    textureComp->SetRotation(0.0f);

    return true;
}

void TitleObject::Draw() {
    GameObject::Draw(); // 親クラスの描画を実行
}