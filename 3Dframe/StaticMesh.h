#pragma once
// 3D用　
// 動かない、または動かす必要がない静的なメッシュを扱うクラスです。
// 静的オブジェクトのメッシュを管理します。
#include	<simplemath.h>
#include	<string>
#include	<vector>
#include	<memory>
#include	"Texture.h"
#include	"Mesh.h"
#include	"DXRenderer.h"

class StaticMesh : public Mesh {
public:
	void Load(std::string filename, std::string texturedirectory="");
	const std::vector<MATERIAL>& GetMaterials() {
		return m_materials;
	}
	const std::vector<SUBSET>& GetSubsets() {
		return m_subsets;
	}

	const std::vector<std::string>& GetTextureNames() {
		return m_texturenames;
	}

	std::vector<std::unique_ptr<Texture>> GetTextures() {
		return std::move(m_textures);
	}

private:

	std::vector<MATERIAL>m_materials;
	std::vector<std::string> m_texturenames;			// テクスチャ名
	std::vector<SUBSET> m_subsets;						// サブセット情報
	std::vector<std::unique_ptr<Texture>>	m_textures;	// テクスチャ群
};