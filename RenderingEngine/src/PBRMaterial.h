#pragma once
#include <string>
#include <unordered_map>

#include "IMaterial.h"
#include "Texture.h"

/// <summary>
/// PBR対応マテリアルクラス
/// </summary>
class PBRMaterial : public IMaterial {
public:
	PBRMaterial();
	~PBRMaterial();

private:
	std::wstring _textureFolderPath = L"";

	enum class TEXTURETYPE
	{
		BASE_COLOR = 0,
		METALLIC,
		ROUGHNESS,
		NORMAL,
		OCCULUSION,	// アンビエントオクルージョン
		TYPE_NUM
	};

	std::unordered_map<TEXTURETYPE, std::wstring> _pbrTexturePaths;
	std::unordered_map<TEXTURETYPE, Texture*> _pbrTextures;

	Texture _dummyTexture;	// テクスチャが指定されていない場合のダミー用テクスチャ

	/// <summary>
	/// テクスチャが指定されていない場合の
	/// ダミーとなる真っ白なテクスチャ生成
	/// </summary>
	/// <returns></returns>
	MYRESULT CreateDammyTexture(Dx12GraphicsEngine& graphicsEngine);

	MYRESULT LoadPBRTextures(Dx12GraphicsEngine& graphicsEngine);

public:
	/// <summary>
	/// マテリアルを利用可能な状態にする
	/// </summary>
	/// <returns></returns>
	MYRESULT Commit();

	void ApplyMaterial(FBXMesh& mesh) override;

	/// <summary>
	/// 読み込みたいテクスチャが置いてあるフォルダへのパス
	/// </summary>
	/// <param name="folderPath"></param>
	void SetTextureFolderPath(std::wstring folderPath);

	/// <summary>
	/// 読み込みたいテクスチャのファイル名(拡張子付き)セット
	/// </summary>
	/// <param name="type">テクスチャの種類(ベースカラー・メタリック・ラフネスなど)</param>
	/// <param name="path"></param>
	void SetTextureName(TEXTURETYPE type, std::wstring path);
};