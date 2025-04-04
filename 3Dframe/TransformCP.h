#pragma once
#include"Component.h"
#include <SimpleMath.h>

//	オブジェクトの位置大きさ
class TransformCP : public Component
{
protected:
	DirectX::XMFLOAT3 Position;//	位置
	DirectX::XMFLOAT3 Rotation;//	回転
	DirectX::XMFLOAT3 Scale;//		大きさ
	DirectX::XMFLOAT4 WorldMatrix;//

public:
	TransformCP() :Position({ 0, 0, 0 }), Rotation({ 0, 0, 0 }), Scale({ 1, 1, 1 }) {};//最低限の初期化処理をコンストラクタでする
	~TransformCP();

	void SetPosition(DirectX::XMFLOAT3 pos) { Position = pos; };
	void SetRotation(DirectX::XMFLOAT3 rot) { Rotation = rot; };
	void SetScale(DirectX::XMFLOAT3 scl) { Scale = scl; };

	DirectX::SimpleMath::Vector3 GetPosition() const;
	DirectX::SimpleMath::Vector3 GetRotation() const;
	DirectX::SimpleMath::Vector3 GetScale();

	void CreateWorldMatrix();
};