#pragma once
// �@3D�p
//  �C���f�b�N�X�o�b�t�@�́A�`�掞�Ɏg�p���钸�_�̏������`���܂��B
// 3D ���f���̒��_�f�[�^���ǂ̂悤�ɐڑ�����邩�������܂��B
#include	<vector>
#include	<wrl/client.h>
#include	"dx11helper.h"
#include	"DXRenderer.h"


using Microsoft::WRL::ComPtr;

//-----------------------------------------------------------------------------
//IndexBuffer�N���X
//-----------------------------------------------------------------------------
class IndexBuffer {

	ComPtr<ID3D11Buffer> m_IndexBuffer;

public:
	void Create(const std::vector<unsigned int>& indices) {

		// �f�o�C�X�擾
		ID3D11Device* device = nullptr;

		device = Renderer::GetDevice();

		assert(device);

		// �C���f�b�N�X�o�b�t�@�쐬
		bool sts = CreateIndexBuffer(
			device,										// �f�o�C�X
			(unsigned int)(indices.size()),				// �C���f�b�N�X��
			(void*)indices.data(),						// �C���f�b�N�X�f�[�^�擪�A�h���X
			&m_IndexBuffer);							// �C���f�b�N�X�o�b�t�@

		assert(sts == true);
	}

	void SetGPU() {
		// �f�o�C�X�R���e�L�X�g�擾
		ID3D11DeviceContext* devicecontext = nullptr;
		devicecontext = Renderer::GetDeviceContext();

		// �C���f�b�N�X�o�b�t�@���Z�b�g
		devicecontext->IASetIndexBuffer(m_IndexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);

	}

	void Modify(const std::vector<unsigned int>& indices) {
		if (!m_IndexBuffer) {
			std::cerr << "Error: IndexBuffer::Modify() - Buffer is nullptr!" << std::endl;
			return;
		}

		ID3D11DeviceContext* context = Renderer::GetDeviceContext();
		if (!context) return;

		D3D11_MAPPED_SUBRESOURCE mappedResource;
		HRESULT hr = context->Map(m_IndexBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
		if (FAILED(hr)) {
			std::cerr << "Error: Failed to map index buffer!" << std::endl;
			return;
		}

		memcpy(mappedResource.pData, indices.data(), indices.size() * sizeof(unsigned int));
		context->Unmap(m_IndexBuffer.Get(), 0);

		std::cout << "IndexBuffer::Modify() - Index buffer updated" << std::endl;
	}
};
