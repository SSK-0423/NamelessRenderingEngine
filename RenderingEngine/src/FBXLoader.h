#pragma once
#include <fbxsdk.h>
#include <map>
#include <vector>
#include <DirectXMath.h>

/// <summary>
/// FBX���b�V���̒��_�f�[�^
/// </summary>
struct FBXMeshVertex {
	DirectX::XMFLOAT3 position;
	DirectX::XMFLOAT3 normal;
	DirectX::XMFLOAT2 uv;
};

/// <summary>
/// FBX���b�V���̃}�e���A���f�[�^
/// FBXMesh�N���X���}�e���A���E�e�N�X�`���`����s��
/// </summary>
struct FBXMaterial {

	float ambient[4];
	float diffuse[4];
	float specular[4];
	float shiness;
	
	std::wstring textureName;

	FBXMaterial()
	{
		for (int i = 0; i < _countof(ambient); i++)
		{
			ambient[i] = 1.0f;
			diffuse[i] = 1.0f;
			specular[i] = 1.0f;
		}
		shiness = 1.f;
		ambient[3] = 0.f;
		diffuse[3] = 0.f;
		specular[3] = 0.f;
		textureName = L"";
	}

	void SetAmbient(float r, float g, float b, float factor)
	{
		ambient[0] = r;
		ambient[1] = g;
		ambient[2] = b;
		ambient[3] = factor;
	}

	void SetDiffuse(float r, float g, float b, float factor)
	{
		diffuse[0] = r;
		diffuse[1] = g;
		diffuse[2] = b;
		diffuse[3] = factor;
	}

	void SetSpecular(float r, float g, float b, float factor)
	{
		specular[0] = r;
		specular[1] = g;
		specular[2] = b;
		specular[3] = factor;
	}
};

/// <summary>
/// FBX���b�V�������i�[����\����
/// FBXMesh�N���X�����̏������ɒ��_�o�b�t�@�[������}�e���A�����̃Z�b�g���s��
/// </summary>
struct FBXMeshData {
	std::vector<FBXMeshVertex> vertices;	// ���_
	std::vector<unsigned int> indices;		// ���_�C���f�b�N�X
	FBXMaterial material;					// �}�e���A��
};

class FBXLoader {
public:
	FBXLoader();
	~FBXLoader();

	FbxManager* fbxManager;
	FbxImporter* fbxImporter;
	FbxScene* fbxScene;

public:
	bool Load(const char* meshPath, std::vector<FBXMeshData>& meshDataList);

private:
	std::map<std::string, FBXMaterial> _materials;

	/// <summary>
	/// FBX_SDK������
	/// </summary>
	/// <returns></returns>
	bool Init();

	FBXMeshData CreateMesh(FbxMesh* mesh);

	void LoadVertices(FBXMeshData& meshData, FbxMesh* mesh);

	void LoadIndices(FBXMeshData& meshData, FbxMesh* mesh);

	void LoadNormals(FBXMeshData& meshData, FbxMesh* mesh);

	void LoadMaterial(FbxSurfaceMaterial* material);

	void SetMaterial(FBXMeshData& meshData, FbxMesh* mesh);

	void LoadUV(FBXMeshData& meshData, FbxMesh* mesh);

	std::wstring GetTextureFileName(FbxFileTexture* texture);
};