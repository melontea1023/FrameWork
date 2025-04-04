#include "Scene.h"

void Scene::Update() {
    for (auto obj : objects) {
        obj->Update();  // 各オブジェクトの Update() を呼ぶ
    }
}

// リスト内のオブジェクトを描画
void Scene::Draw() {
    for (auto obj : objects) {
        std::cout << "Scene::Draw() objects.size: " << objects.size() << std::endl;
        obj->Draw();
    }
}

// シーン終了時にリスト内のオブジェクトを削除
void Scene::Uninit() {
    for (auto obj : objects) {
        delete obj; // メモリ解放
    }
    objects.clear();
}

//  ゲームオブジェクトをリストに追加する
void Scene::AddObject(GameObject* obj)
{
	objects.push_back(obj);
}
