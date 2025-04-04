#pragma once
#include "Object.h"
#include <utility>

class GameObject : public Object
{
private:
	//ユニークポインタのリスト
	std::vector<std::unique_ptr<Object>> components;
public:
	// コンストラクタ
	GameObject();

	// デストラクタ（メモリ開放
	~GameObject();

    bool Init() override {return true;}
	void Update() override;
	void Draw() override;
	void Uninit() override;

	// コンポーネントを追加
	// コンポーネントのコンストラクタに渡される任意の引数を受け取るため
	template<typename T, typename... Args>
	T* AddComponent(Args&&... args) {
		// T型のコンポーネントを動的に生成
		std::unique_ptr<T> component = std::make_unique<T>(std::forward<Args>(args)...);
		// 現在のオブジェクト（this）を所有者として設定
		component->SetOwner(this); 
		// 生成したコンポーネントを components　をリストに追加

		T* rawPointer = component.get();  // unique_ptr から T* を取得
		components.push_back(std::move(component));  // move で所有権を移す
	
		// 生成したコンポーネントへのポインタを返す
		return rawPointer;
	}

	// コンポーネントを取得
	//　T　は取得したいコンポーネントの型を表す
	template<typename T>
	T* GetComponent() {
		//　ゲームオブジェクトが持っているリストのループ
		for (auto& comp : components) {
			//　comp は Object* 型のポインタであり、T* 型にキャスト（変換）されます。
			//　もし、comp が実際に T 型のオブジェクトであれば、dynamic_cast はそのポインタを返す
			if (auto target = dynamic_cast<T*>(comp)) {
				// コンポーネントのコンストラクタに渡される任意の引数を受け取るた
				return target;
			}
		}
		return nullptr; // 見つからなかった場合
	}

};