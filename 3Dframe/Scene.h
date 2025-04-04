#pragma once
#include <string>
#include "Input.h"
#include "GameObject.h"

enum class SceneName {
	TITLE,
	GAME,
	RESULT
};

class Scene {
protected:
	//  GemeObjectを継承したObjectを各シーンで使うためのリスト
	std::vector<GameObject*>objects;
public:
	virtual void Init()=0 ;	// 初期化 成功したらtrueを返すようにする
	virtual void Update() ;	// 更新処理
	virtual void Draw() ;	// 描画処理
	virtual void Uninit() ;	// 終了処理

	//  Objectのリストに追加する
	void AddObject(GameObject* obj);
 };