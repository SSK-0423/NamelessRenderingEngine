#pragma once

#include <d3d12.h>
#include <wrl.h>

#pragma comment(lib,"d3d12.lib")

#include "EngineUtility.h"

/// <summary>
/// グラフィックスパイプラインステートクラス
/// </summary>
class GraphicsPipelineState {
public:
	GraphicsPipelineState() = default;
	~GraphicsPipelineState() = default;

private:
	Microsoft::WRL::ComPtr<ID3D12PipelineState> _pipelineState = nullptr;	// パイプラインステート

	/// <summary>
	/// パイプラインステート生成
	/// </summary>
	/// <param name="device">デバイス</param>
	/// <param name="piplineStateDesc">グラフィックスパイプラインステート構造体</param>
	/// <returns></returns>
	HRESULT CreateGraphicsPipelineState(
		ID3D12Device& device, const D3D12_GRAPHICS_PIPELINE_STATE_DESC& piplineStateDesc);

public:
	/// <summary>
	/// パイプラインステート生成
	/// </summary>
	/// <param name="device">デバイス</param>
	/// <param name="piplineStateDesc">グラフィックスパイプラインステート構造体</param>
	/// <returns></returns>
	MYRESULT Create(ID3D12Device& device, const D3D12_GRAPHICS_PIPELINE_STATE_DESC& piplineStateDesc);
};