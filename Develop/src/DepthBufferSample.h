#pragma once

#include "Dx12ApplicationImpl.h"

#include "EngineUtility.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "RootSignature.h"
#include "Polygon.h"

#include "DepthStencilBuffer.h"
#include "DescriptorHeapDSV.h"

class DepthBufferSample : public Dx12ApplicationImpl
{
public:
	MYRESULT Init(Dx12GraphicsEngine& graphicsEngine, AppWindow& window) override;
	void Update(float deltaTime) override;
	void Draw(Dx12GraphicsEngine& graphicsEngine) override;
	void Final() override;

private:
	VertexBuffer _vertexBuffer;			        // ���_�o�b�t�@�[
	IndexBuffer _indexBuffer;			        // �C���f�b�N�X�o�b�t�@�[
	Shader _vertexShader;				        // ���_�V�F�[�_�[
	Shader _pixelShader;				        // �s�N�Z���V�F�[�_�[
	RootSignatureData _rootSignatureData;		// ���[�g�V�O�l�`��
	MyFrameWork::Polygon _nearPolygon;		    // ��O�|���S��
	MyFrameWork::Polygon _farPolygon;		    // ���|���S��
	CD3DX12_VIEWPORT _viewport;			        // �r���[�|�[�g
	CD3DX12_RECT _scissorRect;			        // �V�U�[��`

	MYRESULT CreateNearPolygon(Dx12GraphicsEngine& graphicsEngine);
	MYRESULT CreateFarPolygon(Dx12GraphicsEngine& graphicsEngine);
};