#include "ResourceManager.h"  // ヘッダーをインクルード

/*
    リソースをロードする
    - すでにロード済みの場合は、それを返す
    - 新規ロードが必要なら、新しくリソースを作成して追加する
*/
template <typename T>
T& ResourceManager<T>::LoadResource(const std::string& name) {
    // 既に登録されている場合、そのリソースを返す
    if (resources.find(name) != resources.end()) {
        return resources[name];
    }

    // 新しいリソースを作成
    T newResource;
    newResource.Load(name);  // リソースのロード処理

    // unordered_map に追加（キー: リソース名、値: リソースデータ）
    resources[name] = newResource;

    // 追加したリソースを返す
    return resources[name];
}

/*
    既存のリソースを取得する
    - 登録済みならポインタを返す
    - 見つからなければ nullptr を返す
*/
template <typename T>
T* ResourceManager<T>::GetResource(const std::string& name) {
    // リソースが存在するか検索
    auto it = resources.find(name);

    // 見つかった場合はリソースのポインタを返す
    if (it != resources.end()) {
        return &it->second;
    }

    // 見つからなければ nullptr を返す
    return nullptr;
}

/*
    キャッシュをクリア
    - すべてのリソースを削除する
*/
template <typename T>
void ResourceManager<T>::ClearCache() {
    resources.clear();  // unordered_map をクリア
}
