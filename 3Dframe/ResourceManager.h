#pragma once  // �w�b�_�[�̑��d�C���N���[�h��h��

#include <unordered_map>  // �A�z�z����g�����߂ɕK�v
#include <string>         // ��������������߂ɕK�v
#include <iostream>       // �f�o�b�O�o�͂ȂǂɎg�p

/*
    �ėp���\�[�X�}�l�[�W��
    - �e�N�X�`���⃂�f���ȂǁA�قȂ郊�\�[�X�^�ɑΉ��\
    - unordered_map ���g�p���A�����Ƀ��\�[�X�������ł���悤�ɂ���
*/
template <typename T>
class ResourceManager {
private:
    std::unordered_map<std::string, T> resources;  // ���\�[�X���ƃf�[�^��R�Â���

public:
    T& LoadResource(const std::string& name);  // ���\�[�X�����[�h����
    T* GetResource(const std::string& name);   // �����̃��\�[�X���擾����
    void ClearCache();                         // ���ׂẴ��\�[�X���폜����
};
