#pragma once  // ヘッダーの多重インクルードを防ぐ

#include <unordered_map>  // 連想配列を使うために必要
#include <string>         // 文字列を扱うために必要
#include <iostream>       // デバッグ出力などに使用

/*
    汎用リソースマネージャ
    - テクスチャやモデルなど、異なるリソース型に対応可能
    - unordered_map を使用し、高速にリソースを検索できるようにする
*/
template <typename T>
class ResourceManager {
private:
    std::unordered_map<std::string, T> resources;  // リソース名とデータを紐づける

public:
    T& LoadResource(const std::string& name);  // リソースをロードする
    T* GetResource(const std::string& name);   // 既存のリソースを取得する
    void ClearCache();                         // すべてのリソースを削除する
};
