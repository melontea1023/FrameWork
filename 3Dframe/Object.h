#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<DirectXMath.h>
#include<memory.h>


enum ObjectType{
	GAMEOBJECT = 0,	// 	コンポーネントを所有するオブジェクト
	COMPONENT = 1	// 	オブジェクトに所有されるコンポーネント
};

//最上位の親クラス
class Object
{
protected:


	std::string name = "";
	std::string id = "";
	ObjectType objectType = ObjectType::GAMEOBJECT;

	bool isActive = false;// trueの場合、自身のUpdateやDrawを通すようにする

public:
	//	↓↓↓純粋仮想関数↓↓↓
	virtual bool Init() = 0;	// 初期化 成功したらtrueを返すようにする
	virtual void Update() = 0;	// 更新処理
	virtual void Draw() = 0;	// 描画処理
	virtual void Uninit() = 0;	// 終了処理
};