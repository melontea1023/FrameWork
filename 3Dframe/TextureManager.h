#pragma once  // �w�b�_�[�̑��d�C���N���[�h��h��

#include "ResourceManager.h"  // �ėp���\�[�X�}�l�[�W���𗘗p
#include "Texture.h"          // �e�N�X�`���N���X�𗘗p

/*
    TextureManager �N���X
    - ResourceManager<Texture> ���p�����A�e�N�X�`���Ǘ���S��
    - �V���O���g���p�^�[�����g�p���A��̃C���X�^���X���
*/
class TextureManager : public ResourceManager<Texture> {
public:
    // �V���O���g���̃C���X�^���X���擾
    static TextureManager& GetInstance() {
        static TextureManager instance;  // �ÓI�C���X�^���X
        return instance;
    }
};
