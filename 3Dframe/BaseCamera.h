#pragma once
#include "Component.h"
#include "DXRenderer.h"
#include "TransformCP.h"

class BaseCamera : public Component {
protected:
    DirectX::SimpleMath::Matrix ViewMatrix;//  �r���[�s��i�J�����̎��_�j
    DirectX::SimpleMath::Matrix ProjectionMatrix;//  �ˉe�s��i�J�����̓��e�ݒ�j

    //  ����p
    float FOV;

    //  �`��͈�
    float NearClip;
    float FarClip;

public:
    //  �R���X�g���N�^
    BaseCamera() { name = "BaseCamera"; }
    //  �f�X�g���N�^
    virtual ~BaseCamera() = default;

    virtual void Update() override = 0;  // �h���N���X�ŃJ�����̓���������

    //  �ˉe�s��̐ݒ�
    void SetProjection(float fov, float nearClip, float farClip, float aspectRatio);
    //  �r���[�s��̐ݒ�
    void SetView(const DirectX::SimpleMath::Vector3& eye, 
                 const DirectX::SimpleMath::Vector3& target, 
                 const DirectX::SimpleMath::Vector3& up);

    //  �ˉe�s��̎擾
    inline DirectX::SimpleMath::Matrix GetProjectionMatrix() const { return ProjectionMatrix; }
    //  �r���[�s��̎擾
    inline DirectX::SimpleMath::Matrix GetViewMatrix() const { return ViewMatrix; }

};
