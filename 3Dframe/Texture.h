#pragma once
// 3D&2D
// 3D �I�u�W�F�N�g�ɓK�p����e�N�X�`�����Ǘ�����N���X�B
// �e�N�X�`���� GPU �Ƀ��[�h������A�V�F�[�_�[�Ŏg�p�ł���悤�ɏ������܂��B

#include	<d3d11.h>
#include	<string>
#include	<wrl/client.h> // ComPtr�̒�`���܂ރw�b�_�t�@�C��
#include	<filesystem>

using Microsoft::WRL::ComPtr;

//-----------------------------------------------------------------------------
//Texture�N���X
//-----------------------------------------------------------------------------
class Texture
{
	std::string m_texname{}; // �t�@�C����
	ComPtr<ID3D11ShaderResourceView> m_srv{}; // �V�F�[�_�[���\�[�X�r���[

	int m_width; // ��
	int m_height; // ����
	int m_bpp; // BPP
public:
	bool Load(const std::string& filename);
	bool LoadFromFemory(const unsigned char* data,int len);

	void SetGPU();
};