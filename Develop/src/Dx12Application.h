#pragma once

#include <Windows.h>
#include <memory>

#include "EngineUtility.h"

class Dx12GraphicsEngine;
class AppWindow;
class Dx12ApplicationImpl;

/// <summary>
/// レンダリング開発中のテスト用クラス
/// </summary>
class Dx12Application
{
public:
	Dx12Application(Dx12ApplicationImpl& applicationImpl);
	~Dx12Application();

	/// <summary>
	/// アプリケーションの初期化
	/// </summary>
	/// <returns>成功：MYRESULT::SUCCESS 失敗：MYRESULT::FAILED</returns>
	MYRESULT Init();

	/// <summary>
	/// メインループ
	/// </summary>
	void Run();

	/// <summary>
	/// 終了処理
	/// </summary>
	void End();

private:
	Dx12GraphicsEngine& _graphicsEngine;			    // 描画の基礎部分を担当するエンジン
	std::shared_ptr<AppWindow> _window = nullptr;		// アプリケーションのウィンドウ
	Dx12ApplicationImpl& _applicationImpl;				// アプリケーションの本体
};