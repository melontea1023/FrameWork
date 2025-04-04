#include "TitleObject.h"

// �R���X�g���N�^�i�����������j
TitleObject::TitleObject() {
    name = "TitleObject";
}

// ����������
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
    GameObject::Draw(); // �e�N���X�̕`������s
}