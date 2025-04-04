#include "ResourceManager.h"  // �w�b�_�[���C���N���[�h

/*
    ���\�[�X�����[�h����
    - ���łɃ��[�h�ς݂̏ꍇ�́A�����Ԃ�
    - �V�K���[�h���K�v�Ȃ�A�V�������\�[�X���쐬���Ēǉ�����
*/
template <typename T>
T& ResourceManager<T>::LoadResource(const std::string& name) {
    // ���ɓo�^����Ă���ꍇ�A���̃��\�[�X��Ԃ�
    if (resources.find(name) != resources.end()) {
        return resources[name];
    }

    // �V�������\�[�X���쐬
    T newResource;
    newResource.Load(name);  // ���\�[�X�̃��[�h����

    // unordered_map �ɒǉ��i�L�[: ���\�[�X���A�l: ���\�[�X�f�[�^�j
    resources[name] = newResource;

    // �ǉ��������\�[�X��Ԃ�
    return resources[name];
}

/*
    �����̃��\�[�X���擾����
    - �o�^�ς݂Ȃ�|�C���^��Ԃ�
    - ������Ȃ���� nullptr ��Ԃ�
*/
template <typename T>
T* ResourceManager<T>::GetResource(const std::string& name) {
    // ���\�[�X�����݂��邩����
    auto it = resources.find(name);

    // ���������ꍇ�̓��\�[�X�̃|�C���^��Ԃ�
    if (it != resources.end()) {
        return &it->second;
    }

    // ������Ȃ���� nullptr ��Ԃ�
    return nullptr;
}

/*
    �L���b�V�����N���A
    - ���ׂẴ��\�[�X���폜����
*/
template <typename T>
void ResourceManager<T>::ClearCache() {
    resources.clear();  // unordered_map ���N���A
}
