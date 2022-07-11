#pragma once
#include <string>
#include <DirectXMath.h>

#include "IMaterial.h"
#include "ConstantBuffer.h"
#include "Texture.h"

/// <summary>
/// フォンの反射モデル用マテリアルクラス
/// </summary>
class PhongMaterial : public IMaterial {
public:
	PhongMaterial();
	~PhongMaterial();
	PhongMaterial(const PhongMaterial& inst);

private:
	static const size_t _dummyTextureWidth = 16;
	static const size_t _dummyTextureHeight = 16;

	
	std::wstring _textureName;
	std::wstring _textureFolderPath;

	struct PhongMaterialBuff
	{
		DirectX::XMFLOAT4 ambient;
		DirectX::XMFLOAT4 diffuse;
		DirectX::XMFLOAT4 specular;
		float shininess;
	};
	PhongMaterialBuff _material;

	ConstantBuffer _materialCBuffer;
	MYRESULT CreateMaterialConstantBuffer(ID3D12Device& device);

	Texture _texture;
	MYRESULT CreateTexture(Dx12GraphicsEngine& graphicsEngine);

public:
	/// <summary>
	/// マテリアルを利用可能な状態にする
	/// </summary>
	/// <returns></returns>
	MYRESULT Commit();

	void ApplyMaterial(FBXMesh& mesh) override;

	inline void SetAmbient(float r, float g, float b, float factor)
	{
		DirectX::XMStoreFloat4(&_material.ambient, DirectX::XMVectorSet(r, g, b, factor));
	}

	inline void SetDiffuse(float r, float g, float b, float factor)
	{
		DirectX::XMStoreFloat4(&_material.diffuse, DirectX::XMVectorSet(r, g, b, factor));
	}

	inline void SetSpecular(float r, float g, float b, float factor)
	{
		DirectX::XMStoreFloat4(&_material.specular, DirectX::XMVectorSet(r, g, b, factor));
	}

	inline void SetShininess(float s)
	{
		_material.shininess = s;
	}

	inline void SetTextureName(std::wstring name)
	{
		_textureName = name;
	}

	inline void SetTextureFolderPath(std::wstring path)
	{
		_textureFolderPath = path;
	}
};