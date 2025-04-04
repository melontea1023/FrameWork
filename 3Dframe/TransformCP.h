#pragma once
#include"Component.h"
#include <SimpleMath.h>

//	�I�u�W�F�N�g�̈ʒu�傫��
class TransformCP : public Component
{
protected:
	DirectX::XMFLOAT3 Position;//	�ʒu
	DirectX::XMFLOAT3 Rotation;//	��]
	DirectX::XMFLOAT3 Scale;//		�傫��
	DirectX::XMFLOAT4 WorldMatrix;//

public:
	TransformCP() :Position({ 0, 0, 0 }), Rotation({ 0, 0, 0 }), Scale({ 1, 1, 1 }) {};//�Œ���̏������������R���X�g���N�^�ł���
	~TransformCP();

	void SetPosition(DirectX::XMFLOAT3 pos) { Position = pos; };
	void SetRotation(DirectX::XMFLOAT3 rot) { Rotation = rot; };
	void SetScale(DirectX::XMFLOAT3 scl) { Scale = scl; };

	DirectX::SimpleMath::Vector3 GetPosition() const;
	DirectX::SimpleMath::Vector3 GetRotation() const;
	DirectX::SimpleMath::Vector3 GetScale();

	void CreateWorldMatrix();
};