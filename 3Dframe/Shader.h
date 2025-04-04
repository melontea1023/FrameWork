#pragma once
//  3D&2D
// �V�F�[�_�[�i���_�V�F�[�_�[�A�s�N�Z���V�F�[�_�[�Ȃǁj���Ǘ�����N���X�ł��B
// GPU ��ł̌v�Z���w�����A�`�揈���Ɋ֘A����l�X�ȑ�����s���܂��B
#include	<wrl/client.h>
#include	<string>
#include	<d3d11.h>

using Microsoft::WRL::ComPtr;

//-----------------------------------------------------------------------------
//Shader�N���X
//-----------------------------------------------------------------------------
class Shader{
public:
	void Create(std::string vs, std::string ps);
	void SetGPU();
private:
	ComPtr<ID3D11VertexShader> m_pVertexShader;		// ���_�V�F�[�_�[
	ComPtr<ID3D11PixelShader>  m_pPixelShader;		// �s�N�Z���V�F�[�_�[
	ComPtr<ID3D11InputLayout>  m_pVertexLayout;		// ���_���C�A�E�g
};

