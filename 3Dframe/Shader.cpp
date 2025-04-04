#include	"Shader.h"
#include	"dx11helper.h"
#include	"DXRenderer.h"
#include <iostream>

//=======================================
//Shader作成　　頂点シェーダーとピクセルシェーダー
//=======================================
void Shader::Create(std::string vs, std::string ps)
{
	// 頂点データの定義
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{//DXGI_FORMATは３D位置を表す
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,		0,	D3D11_APPEND_ALIGNED_ELEMENT,	D3D11_INPUT_PER_VERTEX_DATA, 0 },//頂点の位置
		{ "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT,		0,	D3D11_APPEND_ALIGNED_ELEMENT,	D3D11_INPUT_PER_VERTEX_DATA, 0 },//法線
		{ "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT,	0,	D3D11_APPEND_ALIGNED_ELEMENT,	D3D11_INPUT_PER_VERTEX_DATA, 0 },//色
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,			0,	D3D11_APPEND_ALIGNED_ELEMENT,   D3D11_INPUT_PER_VERTEX_DATA, 0 }//テクスチャ座標
	};

	unsigned int numElements = ARRAYSIZE(layout);

	ID3D11Device* device = Renderer::GetDevice();

	// 頂点シェーダーオブジェクトを生成、同時に頂点レイアウトも生成
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

	// ピクセルシェーダーを生成
	sts = CreatePixelShader(			// ピクセルシェーダーオブジェクトを生成
		device,							// デバイスオブジェクト
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
//GPUにデータを送る
//=======================================
void Shader::SetGPU()
{
	ID3D11DeviceContext* devicecontext = Renderer::GetDeviceContext();
	if (!devicecontext) {
		std::cerr << "Error: DeviceContext is nullptr in Shader::SetGPU()" << std::endl;
		return;
	}
	//std::cout << "Shader::SetGPU() - Applying shaders" << std::endl;
	devicecontext->VSSetShader(m_pVertexShader.Get(), nullptr, 0);		// 頂点シェーダーをセット
	devicecontext->PSSetShader(m_pPixelShader.Get(), nullptr, 0);		// ピクセルシェーダーをセット
	devicecontext->IASetInputLayout(m_pVertexLayout.Get());				// 頂点レイアウトセット
}

