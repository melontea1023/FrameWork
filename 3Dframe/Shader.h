#pragma once
//  3D&2D
// シェーダー（頂点シェーダー、ピクセルシェーダーなど）を管理するクラスです。
// GPU 上での計算を指示し、描画処理に関連する様々な操作を行います。
#include	<wrl/client.h>
#include	<string>
#include	<d3d11.h>

using Microsoft::WRL::ComPtr;

//-----------------------------------------------------------------------------
//Shaderクラス
//-----------------------------------------------------------------------------
class Shader{
public:
	void Create(std::string vs, std::string ps);
	void SetGPU();
private:
	ComPtr<ID3D11VertexShader> m_pVertexShader;		// 頂点シェーダー
	ComPtr<ID3D11PixelShader>  m_pPixelShader;		// ピクセルシェーダー
	ComPtr<ID3D11InputLayout>  m_pVertexLayout;		// 頂点レイアウト
};

