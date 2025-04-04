#include "TransformCP.h"

TransformCP::~TransformCP()
{
}


DirectX::SimpleMath::Vector3 TransformCP::GetPosition() const
{
    return DirectX::SimpleMath::Vector3();
}

DirectX::SimpleMath::Vector3 TransformCP::GetRotation() const
{
    return DirectX::SimpleMath::Vector3();
}

DirectX::SimpleMath::Vector3 TransformCP::GetScale()
{
	return DirectX::SimpleMath::Vector3();
}

void TransformCP::CreateWorldMatrix()
{
}
