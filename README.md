# algorithm-and-datastructure
The algorithm and data structure that I learned.

I'm learning Algorithm and Data Structure in AOJ(AIZU ONLINE JUDGE).
https://onlinejudge.u-aizu.ac.jp/courses/list

C++ syntax learning here
https://atcoder.jp/contests/APG4b/tasks

おすすめサイト
- サイト	                日本語	    特徴	              おすすめ用途
- AtCoder APG4b	        ◎	    解説＋演習＋自動採点	    最初にやる
- LearnCpp.com	        ×	    C++をかなり体系的に解説	    APG4bの次
- cppreference 日本語版   ◎	    C++仕様・STLのリファレンス	分からない機能を調べる
- learn-cpp.org	        ×	    ブラウザ上で実行できる	    軽い演習

# Design programs
https://www.learncpp.com/cpp-tutorial/how-to-design-your-first-programs/



# compile C++ source code
- compile: g++ sample.cpp -o sample
- execute: ./sample

# Makefileを使う
ファイル数が増えると毎回入力するのが面倒なので、

CXX=g++
CXXFLAGS=-std=c++20 -Wall -Wextra -O2

program: main.cpp calc.cpp
	$(CXX) $(CXXFLAGS) main.cpp calc.cpp -o program

実行

make
./program

# よく使うコンパイルオプション
- C++17
	- g++ -std=c++17 hello.cpp -o hello
- C++20
	- g++ -std=c++20 hello.cpp -o hello

最近は C++20 を使うことが多いです。

- 警告を表示
- g++ -Wall -Wextra hello.cpp -o hello

研究・開発ではほぼ必須です。

- デバッグ情報付き
- g++ -g hello.cpp -o hello

gdbでデバッグ可能になります。

- 最適化
- g++ -O2 hello.cpp -o hello

高速化されます。

- 実務でよく使う形
- g++ -std=c++20 -Wall -Wextra -O2 main.cpp -o main


# C++ の演算子について
- C++の**文法としての「演算子（operator）」**について
- C++では、演算子は「値に対して計算・比較・代入などの操作を行う記号」です。かなり種類が多いので、まず全体像を整理すると理解しやすいです。
## 1. 算術演算子
- 数値計算で使います。

```cpp
int a = 10;
int b = 3;

a + b;   // 13  加算
a - b;   // 7   減算
a * b;   // 30  乗算
a / b;   // 3   除算
a % b;   // 1   剰余
```

特に注意したいのが整数同士の `/` です。
```cpp
int x = 10 / 3;
// x = 3
```

小数が欲しい場合は、
```cpp
double x = 10.0 / 3.0;
// 約3.333
```
とします。

## 2. 代入演算子
変数に値を入れます。
```cpp
int x;

x = 10;
```

`=` は数学の「等しい」ではなく、**右側の値を左側に代入する**という意味です。

複合代入演算子もあります。

```cpp
x += 5;   // x = x + 5;
x -= 5;   // x = x - 5;
x *= 5;   // x = x * 5;
x /= 5;   // x = x / 5;
x %= 5;   // x = x % 5;
```

例えば、

```cpp
int x = 10;

x += 3;

std::cout << x;
```
なら、

```text
13
```
になります。

## 3. 比較演算子
2つの値を比較し、結果として `bool` 型の `true` または `false` を返します。

| 演算子  | 意味    | 例        |
| ---- | ----- | -------- |
| `==` | 等しい   | `a == b` |
| `!=` | 等しくない | `a != b` |
| `>`  | より大きい | `a > b`  |
| `<`  | より小さい | `a < b`  |
| `>=` | 以上    | `a >= b` |
| `<=` | 以下    | `a <= b` |

例えば、

```cpp
int age = 20;

if (age >= 18) {
    std::cout << "成人です";
}
```

となります。

初心者のうちは特に

```cpp
=
```
と
```cpp
==
```
の違いが重要です。

```cpp
x = 10;     // 代入

x == 10;    // 比較
```

です。

## 4. 論理演算子
複数の条件を組み合わせます。
```cpp
&&    // AND
||    // OR
!     // NOT
```

例えば、

```cpp
int age = 25;
bool license = true;

if (age >= 18 && license) {
    std::cout << "条件を満たしています";
}
```

`&&` は「両方ともtrueならtrue」です。

```cpp
true  && true   // true
true  && false  // false
```

一方 `||` はどちらか一方が `true` なら `true` です。

```cpp
true  || false  // true
false || false  // false
```

`!` は反転です。

```cpp
!true   // false
!false  // true
```

## 5. インクリメント・デクリメント
C++で非常によく登場します。

```cpp
x++;
++x;

x--;
--x;
```

例えば、

```cpp
int x = 10;

x++;

std::cout << x;
```

なら `11` です。

ただし、

```cpp
x++;
```
と
```cpp
++x;
```

は式の中では意味が違います。

```cpp
int x = 10;

int a = x++;
```

では、

```text
a = 10
x = 11
```

になります。

一方、

```cpp
int x = 10;

int a = ++x;
```
なら、
```text
a = 11
x = 11
```

です。

つまり、
```text
x++    値を使ってから +1
++x    +1してから値を使う
```
という違いです。

## 6. ビット演算子
整数を2進数として操作します。
```cpp
&     // AND
|     // OR
^     // XOR
~     // NOT
<<    // 左シフト
>>    // 右シフト
```

例えば、

```cpp
int a = 5;  // 0101
int b = 3;  // 0011

int c = a & b;
```

ビットごとにANDを取るので、

```text
0101
0011
----
0001
```

となり、

```cpp
c == 1
```

です。

ここで、

```cpp
&&
```

と

```cpp
&
```

は全く違う演算子なので注意してください。

```cpp
a && b    // 論理AND

a & b     // ビットAND
```

## 7. 条件演算子 `?:`
三項演算子とも呼ばれます。
```cpp
条件 ? trueの場合 : falseの場合
```

例えば、

```cpp
int age = 20;

std::string result = age >= 18 ? "成人" : "未成年";
```

これは概念的には、

```cpp
std::string result;

if (age >= 18) {
    result = "成人";
} else {
    result = "未成年";
}
```

と似ています。

## 8. C++特有の重要な演算子
C++を勉強すると、さらに次のような演算子が重要になります。

```cpp
&x        // アドレス取得
*p        // ポインタの参照先
obj.x     // メンバアクセス
ptr->x    // ポインタ経由のメンバアクセス

::        // スコープ解決
[]        // 添字
()        // 関数呼び出し

new       // 動的メモリ確保
delete    // 解放

sizeof    // サイズ取得
```

例えば、

```cpp
int x = 100;

int* p = &x;

std::cout << *p;
```

では、

```text
x
 ↓
100

&x
 ↓
xのメモリアドレス

p = &x
 ↓
pはxのアドレスを持つ

*p
 ↓
そのアドレスに存在する値
 ↓
100
```

という関係になります。

C++では、この**`&` と `*` の理解がポインタ・参照・配列・クラス・メモリ管理につながる**ため、演算子の中でも特に重要です。

また、演算子には**優先順位**があります。例えば、

```cpp
int x = 2 + 3 * 4;
```

は、

```cpp
2 + (3 * 4)
```

なので `14` です。一方、

```cpp
int x = (2 + 3) * 4;
```

なら `20` です。

C++を基礎から学ぶ場合は、次に **「演算子の優先順位」→「`&` と `*`」→「ポインタと参照」→「`.` と `->`」** の順番で理解すると、C++らしい文法がかなり見えてきます。

# algorithm and data structure をC++で学習
C++で Algorithm and Data Structure（アルゴリズムとデータ構造）を学ぶのは非常に良い選択です。特に研究者や機械学習・バイオインフォマティクス分野のプログラマにとって、

* 計算量を理解できる
* 大規模データを効率的に扱える
* 論文中のアルゴリズムを実装できる
* AI・データサイエンスの基礎体力が付く

というメリットがあります。

## まず何を学ぶべきか

おすすめの順番は以下です。

### 1. C++基礎

まずは以下が書けるようになることです。

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = {1,2,3,4,5};

    for(int x : a){
        cout << x << endl;
    }

    return 0;
}
```

学ぶ内容

* 変数
* if
* for
* while
* 関数
* class
* ポインタ
* 参照
* STL

特に STL は重要です。

---

### 2. 計算量

アルゴリズム学習で最重要です。

#### O(1)

```cpp
a[5]
```

#### O(N)

```cpp
for(int i=0;i<N;i++)
```

#### O(N²)

```cpp
for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
```

#### O(logN)

```cpp
binary_search(...)
```

例

| N     | O(N²) |
| ----- | ----- |
| 1000  | 100万回 |
| 10000 | 1億回   |

性能差が非常に大きくなります。

---

## データ構造

### 配列 (Array)

```cpp
vector<int> v;
```

アクセス

```cpp
v[i]
```

計算量

```text
アクセス O(1)
挿入     O(N)
削除     O(N)
```

---

### Linked List

```cpp
list<int> lst;
```

特徴

```text
挿入 O(1)
削除 O(1)
探索 O(N)
```

---

### Stack

後入れ先出し(LIFO)

```cpp
stack<int> st;

st.push(10);
st.pop();
st.top();
```

用途

* DFS
* 関数呼び出し

---

### Queue

先入れ先出し(FIFO)

```cpp
queue<int> q;
```

用途

* BFS
* ジョブスケジューリング

---

### Priority Queue

```cpp
priority_queue<int> pq;
```

最大値を高速取得

```text
push O(logN)
pop  O(logN)
top  O(1)
```

用途

* ダイクストラ法
* A*探索

---

### Hash Table

```cpp
unordered_map<string,int> mp;
```

例

```cpp
mp["cat"] = 3;
```

計算量

```text
平均 O(1)
```

用途

* UniProt ID検索
* 遺伝子名検索

---

### Tree

#### Binary Search Tree

```text
      10
     /  \
    5   20
```

探索

```text
O(logN)
```

---

## アルゴリズム

### Binary Search

```cpp
int l=0,r=n-1;

while(l<=r){
    int mid=(l+r)/2;

    if(a[mid]==target)
        return mid;
    else if(a[mid]<target)
        l=mid+1;
    else
        r=mid-1;
}
```

計算量

```text
O(logN)
```

---

### DFS

```cpp
void dfs(int v){
    visited[v]=true;

    for(auto nv:g[v]){
        if(!visited[nv])
            dfs(nv);
    }
}
```

用途

* 系統樹
* タンパク質相同性ネットワーク

---

### BFS

```cpp
queue<int> q;
```

用途

* 最短経路
* ネットワーク解析

---

### Sorting

```cpp
sort(v.begin(),v.end());
```

内部は Introsort

```text
O(NlogN)
```

---

### Dijkstra

最短経路問題

```cpp
priority_queue
```

を利用

計算量

```text
O(E logV)
```

---

## 研究で特に役立つ部分

今崎さんのように

* バイオインフォマティクス
* タンパク質解析
* 機械学習

を行う場合は、

1. STL
2. Hash Table
3. Graph
4. DFS/BFS
5. Dynamic Programming
6. Heap(Priority Queue)

が特に重要です。

実際、

* PSI-BLAST
* HMMER
* AlphaFold
* MMseqs2

などの高速化されたバイオインフォマティクスソフトウェアはほぼC/C++で書かれています。

## おすすめ教材

まずは次の順で進めると効率的です。

1. 『問題解決力を鍛える！アルゴリズムとデータ構造』
2. 『アルゴリズム図鑑』
3. 『Competitive Programming 4』
4. 『Introduction to Algorithms (CLRS)』
5. 『Algorithm Design (Kleinberg & Tardos)』

特に研究用途なら、競技プログラミング向けの小手先テクニックよりも、

* 計算量解析
* グラフ理論
* 動的計画法
* 文字列アルゴリズム
* 確率的アルゴリズム

を重点的に学ぶのがおすすめです。バイオインフォマティクスとの関連まで含めると、次に学ぶべきは「文字列アルゴリズム（KMP、Suffix Array、BWT）」です。BLASTやゲノム検索の基礎につながります。

# C++ の学ぶ内容
変数
if
for
while
関数
class
ポインタ
参照
STL
について学ぶのに良い学習サイト

今回挙げた範囲なら、**日本語で始めるなら AtCoder APG4b がかなり適しています**。C++文法を学んだ後、そのままアルゴリズム・データ構造の問題演習へ移れるのも利点です。

## おすすめサイト

| サイト                                                                                  | 日本語 | 特徴               | おすすめ用途      |
| ------------------------------------------------------------------------------------ | --- | ---------------- | ----------- |
| [AtCoder APG4b](https://atcoder.jp/contests/APG4b?utm_source=chatgpt.com)            | ◎   | 解説＋演習＋自動採点       | **最初にやる**   |
| [LearnCpp.com](https://www.learncpp.com/?utm_source=chatgpt.com)                     | ×   | C++をかなり体系的に解説    | APG4bの次     |
| [cppreference 日本語版](https://ja.cppreference.com/cpp/language?utm_source=chatgpt.com) | ◎   | C++仕様・STLのリファレンス | 分からない機能を調べる |
| [learn-cpp.org](https://www.learn-cpp.org/?utm_source=chatgpt.com)                   | ×   | ブラウザ上で実行できる      | 軽い演習        |

特に **AtCoder APG4b → LearnCpp → cppreference** の3つを使い分けるのがおすすめです。

## 1. まず AtCoder APG4b

[AtCoder Programming Guide for beginners (APG4b)](https://atcoder.jp/contests/APG4b?utm_source=chatgpt.com)

今回学びたい内容と非常によく一致しています。実際にカリキュラムには、

* `1.04` 変数と型
* `1.06` if文
* `1.10` while文
* `1.11` for文
* `1.14` STLの関数
* `1.15` 関数
* `2.04` 参照
* `3.03` STLのコンテナ
* `4.05` ポインタ

が含まれています。さらに各項目に練習問題があり、自分でコードを書いて自動採点できます。([AtCoder][1])

たとえば `for` なら、

```cpp
for (int i = 0; i < N; i++) {
    // 処理
}
```

について、単に文法だけでなく「どういう順序で実行されるか」まで説明されています。([AtCoder][2])

**Algorithm & Data Structure を最終目的にするなら、まずここから始めるのが自然です。**

## 2. C++そのものを深く理解するなら LearnCpp

[LearnCpp.com](https://www.learncpp.com/?utm_source=chatgpt.com)

英語ですが、C++をきちんと理解するには非常に使いやすい教材です。

たとえば「変数」についても、

```cpp
int x = 5;
```

を単に「変数の宣言」と覚えるだけではなく、

**object / variable / identifier / initialization / memory**

というC++内部の考え方まで説明します。([Learn C++][3])

特に、

**ポインタ → 参照 → class → object → constructor → inheritance → template**

あたりを理解するときはこちらの方が向いています。

## 3. cppreference は「教科書」ではなく「辞書」

[cppreference 日本語版](https://ja.cppreference.com/cpp/language?utm_source=chatgpt.com)

これは最初から順番に読む必要はありません。

たとえば、

```cpp
std::vector<int>
std::sort()
std::unordered_map
std::priority_queue
```

について「この関数どう使うんだっけ？」となったときに調べます。

C++11、C++17、C++20、C++23などの言語仕様や標準ライブラリについて詳しく確認できます。([C++ Reference][4])

---

### 私ならこの順番で進めます

```text
AtCoder APG4b

1. 変数・型
      ↓
2. if
      ↓
3. while
      ↓
4. for
      ↓
5. 配列 / vector
      ↓
6. STL
      ↓
7. 関数
      ↓
8. 参照
      ↓
9. 再帰
      ↓
10. 計算量 O(N), O(log N), O(N²)
      ↓
11. STLコンテナ
      ↓
12. class / struct
      ↓
13. pointer
      ↓
Algorithm & Data Structure
      ↓
sort / binary search
      ↓
stack / queue
      ↓
set / map / unordered_map
      ↓
tree / graph
      ↓
DFS / BFS
      ↓
dynamic programming
```

APG4bは「参照」の直後に「再帰関数」「計算量」が来る構成なので、**C++文法 → アルゴリズム学習**への橋渡しとしてもかなり相性がいいです。([AtCoder][1])

特に今後C++でアルゴリズムとデータ構造を本格的に学ぶのであれば、**APG4bを一緒に1.01から進めて、各章ごとに私から追加問題を2〜3問出す**という進め方もできます。これなら最終的に AtCoder のアルゴリズム問題へ自然につなげられます。

[1]: https://atcoder.jp/contests/APG4b?utm_source=chatgpt.com "C++入門 AtCoder Programming Guide for beginners (APG4b) - AtCoder"
[2]: https://atcoder.jp/contests/apg4b/tasks/APG4b_l?utm_source=chatgpt.com "L - 1.11.for文・break・continue"
[3]: https://www.learncpp.com/cpp-tutorial/introduction-to-objects-and-variables/?utm_source=chatgpt.com "1.3 — Introduction to objects and variables – Learn C++"
[4]: https://en.cppreference.com/?utm_source=chatgpt.com "cppreference.com"


# プログラム実装においてはソフトウェア開発における設計についても学ぶ必要がある
はい。C++の文法とアルゴリズムだけでなく、**「プログラムをどう分割し、どう依存させ、どう変更しやすくするか」というソフトウェア設計**を並行して学ぶのは重要です。

特におすすめなのが次の3サイトです。

1. **Refactoring.Guru 日本語版**
   [Refactoring.Guru — C++ デザインパターン](https://refactoring.guru/ja/design-patterns/cpp?utm_source=chatgpt.com)
   最初に使うならこれです。図が多く、C++コード例もあります。Factory、Strategy、Observer、Adapter、Facade、StateなどのGoFデザインパターンを、単なるコードではなく「何の問題を解決する設計なのか」から説明しています。([Refactoring Guru][1])

2. **C++ Core Guidelines**
   C++を使って「安全で保守しやすい設計」を考える段階で非常に重要です。特に、クラス、インターフェース、リソース管理、RAII、所有権、ポインタ、エラー処理などを学ぶ際に役立ちます。

3. **Google C++ Style Guide**
   [Google C++ Style Guide](https://google.github.io/styleguide/cppguide?utm_source=chatgpt.com)
   大規模なC++コードを「他人が読める・保守できる形」にする考え方を学べます。`.h` と `.cpp` の使い分け、クラス、関数、命名、所有権など、単なるインデント規則以上の内容を扱っています。([Google GitHub][2])
   日本語訳もあります。[Google C++ Style Guide 日本語訳](https://ttsuki.github.io/styleguide/cppguide.ja.html?utm_source=chatgpt.com)

ただし、いきなりデザインパターンを22種類暗記する必要はありません。むしろ次の順番がおすすめです。

```text
C++文法
  ↓
関数
  ↓
.h と .cpp によるファイル分割
  ↓
struct / class
  ↓
カプセル化
  ↓
public / private
  ↓
コンストラクタ
  ↓
参照・ポインタ
  ↓
継承・仮想関数
  ↓
interface（抽象クラス）
  ↓
「責務」を考えたクラス分割
  ↓
SOLID原則
  ↓
依存関係
  ↓
デザインパターン
  ↓
リファクタリング
  ↓
アーキテクチャ
```

例えば、以前質問されていた

```text
project/
├── main.cpp
├── calc.cpp
└── calc.h
```

という構成は、まさに**設計学習の入口**です。

単に

```cpp
int add(int a, int b) {
    return a + b;
}
```

と書けるだけでなく、

```text
main.cpp
   │
   │ 利用する
   ↓
calc.h
   │
   │ 宣言
   ↓
calc.cpp
   │
   └─ 実装
```

というように、「**どのファイルが何を担当するのか**」「外部に何を公開するのか」を考え始めます。

さらに規模が大きくなると、

```text
main.cpp
   │
   ├── DataLoader
   │
   ├── Preprocessor
   │
   ├── Model
   │
   └── Evaluator
```

のように責務を分割します。ここから **Single Responsibility Principle（単一責任原則）**などのSOLID原則につながります。

そして、

```text
悪い設計
main.cpp
 ├─ ファイル読み込み
 ├─ データ処理
 ├─ アルゴリズム
 ├─ 結果保存
 └─ エラー処理
```

を

```text
main.cpp
   │
   ├── DataLoader
   ├── Processor
   ├── Algorithm
   └── ResultWriter
```

のように整理できるようになることが、アルゴリズム問題とは別の「ソフトウェア設計能力」です。

そのため、今後のC++学習は大きく**3本立て**にするとよいと思います。

| 系統                         | 学ぶもの                                        | 教材                                     |
| -------------------------- | ------------------------------------------- | -------------------------------------- |
| C++                        | 変数、関数、class、pointer、STL                     | AtCoder APG4b / LearnCpp               |
| Algorithm & Data Structure | sort、探索、stack、queue、tree、graph、DP           | AOJ / AtCoder                          |
| Software Design            | クラス設計、SOLID、依存関係、Design Pattern、Refactoring | Refactoring.Guru / C++ Core Guidelines |

特に **Refactoring.Guru → C++ Core Guidelines → Google C++ Style Guide** の順で進めると、C++の文法から実際のソフトウェア開発へかなり自然につながります。

Refactoring.GuruにはC++でGoFデザインパターンを実装したコード集も公開されています。([GitHub][3])

今の段階なら、**C++文法 → アルゴリズム・データ構造 → ソフトウェア設計を並行して半年程度で体系的に学ぶロードマップ**を作って、それに沿ってAOJなどの問題を解いていく形がかなり適しています。

[1]: https://refactoring.guru/?utm_source=chatgpt.com "Refactoring and Design Patterns"
[2]: https://google.github.io/styleguide/cppguide?utm_source=chatgpt.com "Google C++ Style Guide"
[3]: https://github.com/RefactoringGuru/design-patterns-cpp?utm_source=chatgpt.com "GitHub - RefactoringGuru/design-patterns-cpp: Design Pattern Examples in C++ · GitHub"

https://github.com/RefactoringGuru/design-patterns-cpp?utm_source=chatgpt.com


# meaning of header file .h file 
project/ 
├── main.cpp 
├── calc.cpp 
└── calc.h  
こちらの例のように calc.hは何に使うのか

はい。`calc.h` は **「calc.cpp にどんな関数やクラスが用意されているのかを、他の `.cpp` ファイルに知らせるためのファイル」**です。

C++では、この役割を持つファイルを**ヘッダファイル（header file）**と呼びます。

たとえば次の構成を考えます。

```text
project/
├── main.cpp
├── calc.cpp
└── calc.h
```

ここで「2つの整数を足す `add()` 関数」を作ってみます。

## `calc.h` — 関数の宣言

```cpp
#ifndef CALC_H
#define CALC_H

int add(int a, int b);

#endif
```

ここでは、

```cpp
int add(int a, int b);
```

と書くことで、

> `int` を2つ受け取って `int` を返す `add()` という関数があります

とコンパイラに知らせています。

まだ「どうやって足し算するか」は書いていません。

## `calc.cpp` — 関数の実装

```cpp
#include "calc.h"

int add(int a, int b) {
    return a + b;
}
```

こちらに実際の処理を書きます。

```cpp
return a + b;
```

が `add()` の具体的な実装です。

## `main.cpp` — 関数を利用

```cpp
#include <iostream>
#include "calc.h"

int main() {
    int x = 10;
    int y = 20;

    int result = add(x, y);

    std::cout << result << std::endl;

    return 0;
}
```

`main.cpp` は

```cpp
#include "calc.h"
```

することで、

```cpp
add(x, y)
```

という関数を使えることを知ります。

Ubuntuなら3つのファイルを用意して、

```bash
g++ main.cpp calc.cpp -o program
```

とコンパイルします。

そして、

```bash
./program
```

とすると、

```text
30
```

と表示されます。

つまり、関係を簡単に表すと、

```text
                  calc.h
             「addがあります」
                ↙       ↘
               /         \
          main.cpp      calc.cpp
        addを使う       addを実装する
             \           /
              \         /
               コンパイル
                   ↓
                program
```

という構造です。

特に重要なのは、**`.h` と `.cpp` の役割の違い**です。

| ファイル       | 主な役割            | 例                    |
| ---------- | --------------- | -------------------- |
| `main.cpp` | プログラムの入口        | `main()`             |
| `calc.h`   | 関数・クラスなどの**宣言** | `int add(int, int);` |
| `calc.cpp` | 関数などの**実装・定義**  | `return a + b;`      |

小さなプログラムなら、全部 `main.cpp` に書いても問題ありません。

```cpp
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    std::cout << add(10, 20) << std::endl;
}
```

しかしプログラムが大きくなると、`main.cpp` が何千行にもなってしまいます。そのため、

```text
main.cpp
calc.cpp
calc.h
database.cpp
database.h
network.cpp
network.h
```

のように**機能ごとに分割する**わけです。

C++を学ぶうえでは、ここから「宣言と定義の違い」→「`#include` が実際に何をしているのか」→「コンパイルとリンク」という順番で理解すると、`.h` の存在理由がかなり明確になります。


