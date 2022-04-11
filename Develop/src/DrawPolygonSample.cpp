#include "DrawPolygonSample.h"
#include "Dx12GraphicsEngine.h"
#include "AppWindow.h"

MYRESULT DrawPolygonSample::Init(Dx12GraphicsEngine& graphicsEngine, AppWindow& window)
{
	// �O�p�`�|���S���̒��_�f�[�^�p��
	std::vector<PolygonVertex> triangleVertex;
	triangleVertex.push_back({ { -0.5f,-0.7f	,0.f }	,{0.f,1.f} });
	triangleVertex.push_back({ { 0.f  ,0.7f		,0.f }	,{0.5f,0.f} });
	triangleVertex.push_back({ { 0.5f ,-0.7f	,0.f}	,{1.f,1.f} });

	// ���_�o�b�t�@�[����
	MYRESULT result = _vertexBuffer.Create(
		graphicsEngine.Device(), (void*)&triangleVertex[0],
		SizeofVector<PolygonVertex>(triangleVertex), sizeof(PolygonVertex));

	// �O�p�`�|���S���̃C���f�b�N�X�f�[�^�p��
	std::vector<UINT> index;
	index.push_back(0); index.push_back(1); index.push_back(2);

	// �C���f�b�N�X�o�b�t�@�[����
	result = _indexBuffer.Create(graphicsEngine.Device(), index);

	// ���[�g�V�O�l�`������
	RootSignatureData data;
	result = _rootSignature.Create(graphicsEngine.Device(), data);

	// �V�F�[�_�[
	result = _vertexShader.Create(L"src/PolygonSampleVertex.hlsl", "PolygonSampleVS", "vs_5_0");
	result = _pixelShader.Create(L"src/PolygonSamplePixel.hlsl", "PolygonSamplePS", "ps_5_0");

	// �|���S������
	PolygonData polygonData;
	polygonData.vertexBuffer = _vertexBuffer;
	polygonData.indexBuffer = _indexBuffer;
	polygonData.vertexShader = _vertexShader;
	polygonData.pixelShader = _pixelShader;
	polygonData.rootSignature = _rootSignature;
	polygonData.inputLayout.push_back
	(
		{
			"POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,
			D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0
		}
	);
	polygonData.inputLayout.push_back
	(
		{
			"TEXCOORD",0,DXGI_FORMAT_R32G32_FLOAT,0,
			D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0
		}
	);

	result = _triangle.Create(graphicsEngine.Device(), polygonData);

	// �r���[�|�[�g�Z�b�g
	_viewport.TopLeftX = 0.f;
	_viewport.TopLeftY = 0.f;
	_viewport.Width = static_cast<FLOAT>(window.GetWindowSize().cx);
	_viewport.Height = static_cast<FLOAT>(window.GetWindowSize().cy);

	// �V�U�[��`�Z�b�g
	_scissorRect.left = 0;
	_scissorRect.top = 0;
	_scissorRect.right = window.GetWindowSize().cx;
	_scissorRect.bottom = window.GetWindowSize().cy;

	return result;
}

void DrawPolygonSample::Update()
{
}

void DrawPolygonSample::Draw(Dx12GraphicsEngine& graphicsEngine)
{
	// �����_�����O�R���e�L�X�g�擾
	RenderingContext& renderContext = graphicsEngine.GetRenderingContext();

	renderContext.SetGraphicsRootSignature(_rootSignature);
	renderContext.SetViewport(_viewport);
	renderContext.SetScissorRect(_scissorRect);

	// �|���S���`��
	_triangle.Draw(renderContext);
}

void DrawPolygonSample::Final()
{
}