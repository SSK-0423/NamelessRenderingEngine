#include "MultiRenderTargetHeader.hlsli"

float4 main(MultiRenderiFinalVertex input) : SV_TARGET
{
    // 左４分の1はレンダーターゲット1を描画
    if (input.uv.x >= 0.f && input.uv.x <= 0.25f)
    {
        return render1.Sample(smp, input.uv * 4.f);
    }
    // 右４分の1はレンダーターゲット2を描画
    if (input.uv.x >= 0.75f && input.uv.x <= 1.f)
    {
        float2 uv = input.uv - float2(0.75f, 0.f);
        return render2.Sample(smp, uv * 4);
    }

    // 中央は緑を描画
    return float4(0.f, 1.f, 0.f, 1.f);
}