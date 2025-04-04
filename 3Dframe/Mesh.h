#pragma once
//�@3D�p 
// ���f���̃��b�V���i���_�f�[�^��C���f�b�N�X�f�[�^�j���Ǘ�����N���X�B
// 3D ��Ԃł̕��̌`����`���܂��B
#include	<vector>
#include	"DXRenderer.h"

class Mesh {
protected:
	std::vector<VERTEX_3D>		m_vertices;		// ���_���W�Q
	std::vector<unsigned int>	m_indices;		// �C���f�b�N�X�f�[�^�Q
public:
	bool Load(const std::string& filename);


	// ���_�f�[�^�擾
	const std::vector<VERTEX_3D>& GetVertices() {
		return m_vertices;
	}

	// �C���f�b�N�X�f�[�^�擾
	const std::vector<unsigned int>& GetIndices() {
		return m_indices;
	}
};

