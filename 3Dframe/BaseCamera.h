#pragma once
#include "Component.h"
#include "DXRenderer.h"
#include "TransformCP.h"

class BaseCamera : public Component {
protected:
    DirectX::SimpleMath::Matrix ViewMatrix;//  ビュー行列（カメラの視点）
    DirectX::SimpleMath::Matrix ProjectionMatrix;//  射影行列（カメラの投影設定）

    //  視野角
    float FOV;

    //  描画範囲
    float NearClip;
    float FarClip;

public:
    //  コンストラクタ
    BaseCamera() { name = "BaseCamera"; }
    //  デストラクタ
    virtual ~BaseCamera() = default;

    virtual void Update() override = 0;  // 派生クラスでカメラの動きを実装

    //  射影行列の設定
    void SetProjection(float fov, float nearClip, float farClip, float aspectRatio);
    //  ビュー行列の設定
    void SetView(const DirectX::SimpleMath::Vector3& eye, 
                 const DirectX::SimpleMath::Vector3& target, 
                 const DirectX::SimpleMath::Vector3& up);

    //  射影行列の取得
    inline DirectX::SimpleMath::Matrix GetProjectionMatrix() const { return ProjectionMatrix; }
    //  ビュー行列の取得
    inline DirectX::SimpleMath::Matrix GetViewMatrix() const { return ViewMatrix; }

};
