#pragma once
#include<memory>
#include"Scene.h"
//シーンのインクルード

class SceneManager {
private:
	std::unique_ptr<Scene> currentScene;
	static SceneManager instance;  // シングルトンのインスタンス
public:
	void Init(std::unique_ptr<Scene> firstScene); // 最初のシーンを設定
	void Update();	// 更新処理
	void Draw();	// 描画処理
	void Uninit();	// 終了処理
	void ChangeScene(SceneName nextSceneName);//
	void FinishScene();//シーンのUninitとdelete　メモリ解放

	static SceneManager& GetInstance();  // シングルトンのインスタンスを取得

	inline Scene* GetCurrentScene() { return currentScene.get(); };
};