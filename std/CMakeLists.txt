cmake_minimum_required(VERSION 3.2)
project(std)

include(CTest)
enable_testing()

## コンセプトライブラリ

## コルーチンライブラリ

## ユーティリティライブラリ
### <bitset>	std::bitset クラステンプレート
add_subdirectory(bitset)

### <tuple> (C++11以上)	std::tuple クラステンプレート
add_subdirectory(tuple)

### <ctime>	C スタイルの日付と時間のユーティリティ
add_subdirectory(ctime)

### <chrono> (C++11以上)	C++ の時間ユーティリティ
add_subdirectory(chrono)

### <typeinfo>	実行時型情報ユーティリティ
add_subdirectory(typeinfo)

## 動的メモリ管理

## 数値の限界

## エラー処理

## 文字列ライブラリ

## コンテナライブラリ
### <array> (C++11以上)	std::array コンテナ
add_subdirectory(array)

### <vector>	std::vector コンテナ
add_subdirectory(vector)

### <list>	std::list コンテナ
add_subdirectory(list)

### <forward_list> (C++11以上)	std::forward_list コンテナ
add_subdirectory(forward_list)

### <deque>	std::deque コンテナ
add_subdirectory(deque)

### <queue>	std::queue および std::priority_queue コンテナアダプタ
add_subdirectory(queue)

### <stack>	std::stack コンテナアダプタ
add_subdirectory(stack)

### <map>	std::map および std::multimap 連想コンテナ
add_subdirectory(map)

### <set>	std::set および std::multiset 連想コンテナ
add_subdirectory(set)

### <unordered_map> (C++11以上)	std::unordered_map および std::unordered_multimap 非順序連想コンテナ
add_subdirectory(unordered_map)

## イテレータライブラリ

## 範囲ライブラリ

## アルゴリズムライブラリ

## 数値演算ライブラリ

## 入出力ライブラリ

## ローカライゼーションライブラリ

## 正規表現ライブラリ

## アトミック操作ライブラリ

## スレッドサポートライブラリ
### <thread> (C++11以上)	std::thread クラスとサポート関数
add_subdirectory(thread)

### <mutex> (C++11以上)	相互排他プリミティブ
add_subdirectory(mutex)

### <future> (C++11以上)	非同期計算のためのプリミティブ
add_subdirectory(future)
