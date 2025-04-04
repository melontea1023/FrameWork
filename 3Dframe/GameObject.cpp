#include "GameObject.h"	

// コンストラクタ
GameObject::GameObject() {
    name = "gameObject";
    id = "gameObject0";
    objectType = ObjectType::GAMEOBJECT;//このクラスのオブジェクトタイプは定数型オブジェクトタイプのゲームオブジェクト
}

// デストラクタ（メモリ開放
GameObject::~GameObject() {
	//	↓↓↓↓↓　ユニークポインタなので delete しなくていい ↓↓↓↓↓
	//for (auto comp : components) {
	//	delete comp;  // 明示的に delete しないとメモリリーク
	//}
	components.clear();
}

void GameObject::Update() {
    for (auto& comp : components) {
        comp->Update();  // コンポーネントの Update() を呼ぶ
    }
}

void GameObject::Draw() {
    std::cout << "[GameObject::Draw] components size = " << components.size() << std::endl;

    for (auto& comp : components) {
        comp->Draw();  // すべてのコンポーネントの Draw() を実行
    }
}

// 終了処理
void GameObject::Uninit() {
    components.clear();
}