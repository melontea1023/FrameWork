#pragma once  // �w�b�_�[�̑��d�C���N���[�h��h��

#include "ResourceManager.h"  // �ėp���\�[�X�}�l�[�W���𗘗p
#include "Model.h"            // ���f���N���X�𗘗p

/*
    ModelManager �N���X
    - ResourceManager<Model> ���p�����A���f���Ǘ���S��
    - �V���O���g���p�^�[�����g�p���A��̃C���X�^���X���
*/
class ModelManager : public ResourceManager<Model> {
public:
    // �V���O���g���̃C���X�^���X���擾
    static ModelManager& GetInstance() {
        static ModelManager instance;  // �ÓI�C���X�^���X
        return instance;
    }
};
