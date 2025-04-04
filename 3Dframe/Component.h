#pragma once
#include"Object.h"
#include <memory>

//  コンポーネントの親クラス
class Component : public Object {
protected:
    Object* owner = nullptr;//そのコンポーネントを所有するオブジェクト

public:
    Component(){
        name = "component";
        id = "component0";
        objectType = ObjectType::COMPONENT;
    }

    // 所有者の設定
    //　セッターなので inline 処理
    inline void SetOwner(Object* newOwner)
    {
        owner = newOwner;
    }

    // 所有者を取得
    //　ゲッターなので inline 処理
    inline Object* GetOwner()
    {
        return owner;
    }

    bool Init() override { return true; }// trueを返さないと処理が回らないから
    void Update() override {}
    void Draw() override {}
    void Uninit() override {}
};