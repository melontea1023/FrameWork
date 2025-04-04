#include	"Shader.h"
#include	"dx11helper.h"
#include	"DXRenderer.h"
#include <iostream>

//=======================================
//Shader�쐬�@�@���_�V�F�[�_�[�ƃs�N�Z���V�F�[�_�[
//=======================================
void Shader::Create(std::string vs, std::string ps)
{
	// ���_�f�[�^�̒�`
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{//DXGI_FORMAT�͂RD�ʒu��\��
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,		0,	D3D11_APPEND_ALIGNED_ELEMENT,	D3D11_INPUT_PER_VERTEX_DATA, 0 },//���_�̈ʒu
		{ "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT,		0,	D3D11_APPEND_ALIGNED_ELEMENT,	D3D11_INPUT_PER_VERTEX_DATA, 0 },//�@��
		{ "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT,	0,	D3D11_APPEND_ALIGNED_ELEMENT,	D3D11_INPUT_PER_VERTEX_DATA, 0 },//�F
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,			0,	D3D11_APPEND_ALIGNED_ELEMENT,   D3D11_INPUT_PER_VERTEX_DATA, 0 }//�e�N�X�`�����W
	};

	unsigned int numElements = ARRAYSIZE(layout);

	ID3D11Device* device = Renderer::GetDevice();

	// ���_�V�F�[�_�[�I�u�W�F�N�g�𐶐��A�����ɒ��_���C�A�E�g������
	bool sts = CreateVertexShader(device,
			vs.c_str(),
			"vs_main",
			"vs_5_0",
			layout,
			numElements,
			&m_pVertexShader,
			&m_pVertexLayout);
	if (!sts) {
		MessageBoxA(nullptr, "CreateVertexShader error", "error", MB_OK);
		return;
	}

	// �s�N�Z���V�F�[�_�[�𐶐�
	sts = CreatePixelShader(			// �s�N�Z���V�F�[�_�[�I�u�W�F�N�g�𐶐�
		device,							// �f�o�C�X�I�u�W�F�N�g
		ps.c_str(),
		"ps_main",
		"ps_5_0",
		&m_pPixelShader);
	if (!sts) {
		MessageBoxA(nullptr, "CreatePixelShader error", "error", MB_OK);
		return;
	}

	return;
}

//=======================================
//GPU�Ƀf�[�^�𑗂�
//=======================================
void Shader::SetGPU()
{
	ID3D11DeviceContext* devicecontext = Renderer::GetDeviceContext();
	if (!devicecontext) {
		std::cerr << "Error: DeviceContext is nullptr in Shader::SetGPU()" << std::endl;
		return;
	}
	//std::cout << "Shader::SetGPU() - Applying shaders" << std::endl;
	devicecontext->VSSetShader(m_pVertexShader.Get(), nullptr, 0);		// ���_�V�F�[�_�[���Z�b�g
	devicecontext->PSSetShader(m_pPixelShader.Get(), nullptr, 0);		// �s�N�Z���V�F�[�_�[���Z�b�g
	devicecontext->IASetInputLayout(m_pVertexLayout.Get());				// ���_���C�A�E�g�Z�b�g
}

