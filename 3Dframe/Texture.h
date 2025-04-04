#pragma once
// 3D&2D
// 3D オブジェクトに適用するテクスチャを管理するクラス。
// テクスチャを GPU にロードしたり、シェーダーで使用できるように準備します。

#include	<d3d11.h>
#include	<string>
#include	<wrl/client.h> // ComPtrの定義を含むヘッダファイル
#include	<filesystem>

using Microsoft::WRL::ComPtr;

//-----------------------------------------------------------------------------
//Textureクラス
//-----------------------------------------------------------------------------
class Texture
{
	std::string m_texname{}; // ファイル名
	ComPtr<ID3D11ShaderResourceView> m_srv{}; // シェーダーリソースビュー

	int m_width; // 幅
	int m_height; // 高さ
	int m_bpp; // BPP
public:
	bool Load(const std::string& filename);
	bool LoadFromFemory(const unsigned char* data,int len);

	void SetGPU();
};