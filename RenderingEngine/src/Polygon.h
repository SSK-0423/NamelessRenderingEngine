#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "GraphicsPipelineState.h"
#include "RootSignature.h"
#include "RenderingContext.h"
#include "Shader.h"

#include "EngineUtility.h"

/// <summary>
/// ポリゴン生成用データ
/// </summary>
struct PolygonData
{
	Shader _vertexShader;	                            // 頂点シェーダー
	Shader _pixelShader;	                            // ピクセルシェーダー
	VertexBuffer _vertexBuffer;	                        // 頂点バッファー
	IndexBuffer _indexBuffer;	                        // インデックスバッファー
	RootSignature _rootSignature;	                    // ルートシグネチャ
	std::vector<D3D12_INPUT_ELEMENT_DESC> _inputLayout;	// 頂点レイアウト
	unsigned int _renderTargetNum = 1;
};

/// <summary>
/// ポリゴンの頂点データ
/// </summary>
struct PolygonVertex {
	DirectX::XMFLOAT3 _vertex;
	DirectX::XMFLOAT2 _uv;
};

namespace MyFrameWork
{
	class Polygon
	{
	public:
		Polygon() = default;
		~Polygon() = default;

	private:
		VertexBuffer _vertexBuffer;
		IndexBuffer _indexBuffer;
		GraphicsPipelineState _graphicsPipelineState;

		/// <summary>
		/// ポリゴン表示用のパイプラインステート生成
		/// </summary>
		/// <returns></returns>
		MYRESULT CreateGraphicsPipelineState(ID3D12Device& device, const PolygonData& data);

	public:
		/// <summary>
		/// ポリゴン生成
		/// </summary>
		/// <param name="device">デバイス</param>
		/// <param name="data">ポリゴンデータ</param>
		/// <returns></returns>
		MYRESULT Create(ID3D12Device& device, const PolygonData& data);

		/// <summary>
		/// 描画
		/// </summary>
		/// <param name="renderContext">レンダリングコンテキスト</param>
		void Draw(RenderingContext& renderContext);
	};
}

/// メモ
/// 1.レンダリングコンテキスト
/// 2.GraphicsPipelineState
/// 3.頂点バッファー
/// 4.インデックスバッファー()