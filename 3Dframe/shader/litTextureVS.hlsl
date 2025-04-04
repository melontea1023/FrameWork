#include "common.hlsl"

PS_IN vs_main(in VS_IN input)
{
    PS_IN output;

	//positoin=============================
	// ワールド、ビュー、プロジェクション行列を掛け合わせて座標変換を行う
	matrix wvp;
	wvp = mul(World, View);
	wvp = mul(wvp, Projection);
    output.pos = mul(input.pos, wvp);

	//color=============================
	//法線ベクトルの変換と正規化
	//入力された法線をワールド空間に変換し正規化する
    float4 normal = float4(input.nrm.xyz,0.0);
    float4 worldNormal = mul(normal, World);
    worldNormal = normalize(worldNormal);
	
	//光源方向と法線ベクトルの内積を計算して拡散光を求める
    float d = -dot(Light.Direction.xyz, worldNormal.xyz);
	
    d = saturate(d);
	
	
    output.col.xyz = input.col.xyz *d * Light.Diffuse.xyz; // 拡散光の影響を乗算
    output.col.xyz += input.col.xyz * Light.Ambient.xyz; // アンビエント光を加算
    output.col.xyz += Material.Emission.xyz;
	output.col.a = input.col.a*Material.Diffuse.a; // アルファ値はそのまま使用
	
	//texture=============================
	// テクスチャ座標はそのまま使用
    output.tex = input.tex;
	
    return output;
}

