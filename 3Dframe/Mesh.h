#pragma once
//　3D用 
// モデルのメッシュ（頂点データやインデックスデータ）を管理するクラス。
// 3D 空間での物体形状を定義します。
#include	<vector>
#include	"DXRenderer.h"

class Mesh {
protected:
	std::vector<VERTEX_3D>		m_vertices;		// 頂点座標群
	std::vector<unsigned int>	m_indices;		// インデックスデータ群
public:
	bool Load(const std::string& filename);


	// 頂点データ取得
	const std::vector<VERTEX_3D>& GetVertices() {
		return m_vertices;
	}

	// インデックスデータ取得
	const std::vector<unsigned int>& GetIndices() {
		return m_indices;
	}
};

