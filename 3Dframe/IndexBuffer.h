#pragma once
// 　3D用
//  インデックスバッファは、描画時に使用する頂点の順序を定義します。
// 3D モデルの頂点データがどのように接続されるかを示します。
#include	<vector>
#include	<wrl/client.h>
#include	"dx11helper.h"
#include	"DXRenderer.h"


using Microsoft::WRL::ComPtr;

//-----------------------------------------------------------------------------
//IndexBufferクラス
//-----------------------------------------------------------------------------
class IndexBuffer {

	ComPtr<ID3D11Buffer> m_IndexBuffer;

public:
	void Create(const std::vector<unsigned int>& indices) {

		// デバイス取得
		ID3D11Device* device = nullptr;

		device = Renderer::GetDevice();

		assert(device);

		// インデックスバッファ作成
		bool sts = CreateIndexBuffer(
			device,										// デバイス
			(unsigned int)(indices.size()),				// インデックス数
			(void*)indices.data(),						// インデックスデータ先頭アドレス
			&m_IndexBuffer);							// インデックスバッファ

		assert(sts == true);
	}

	void SetGPU() {
		// デバイスコンテキスト取得
		ID3D11DeviceContext* devicecontext = nullptr;
		devicecontext = Renderer::GetDeviceContext();

		// インデックスバッファをセット
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
