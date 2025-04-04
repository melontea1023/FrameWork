#pragma once
#include<iostream>
#include"SceneManager.h"


class Game
{
public:
	Game(); // コンストラクタ
	~Game(); // デストラクタ

	void Init(); // 初期化
	void Update(); // 更新
	void Draw(); // 描画
	void Uninit(); // 終了処理

	void ChangeScene(SceneName sceneName); // シーンを変更

};
