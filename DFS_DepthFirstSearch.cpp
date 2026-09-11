//DFS についてABC256 C-Filling 3x3 array の解説をもとに勉強をはじめました．リンクは次
//https://atcoder.jp/contests/abc256/editorial/4129
//


//DFSの疑似コード
int h[3], w[3], a[3][3];
long long ans = 0;
void dfs(int ij) {
  int i = ij / 3, j = ij % 3;
  if (i == 3) { 
    if( /* 盤面が条件を満たす */ ) ans++;
    return;
  }
  for (int x = 1; x <= 30; x++) {
    a[i][j] = x;
    dfs(ij + 1);
  }
}

//for-loop を用いた実装例
#include <algorithm>
#include <iostream>
using namespace std;
int H[3], W[3], ans = 0;
int main() {
  for (int i = 0; i < 3; i++) cin >> H[i];
  for (int j = 0; j < 3; j++) cin >> W[j];
  for (int a = 1; a <= 30; a++) {
    for (int b = 1; b <= 30; b++) {
      for (int d = 1; d <= 30; d++) {
        for (int e = 1; e <= 30; e++) {
          int c = H[0] - a - b;
          int f = H[1] - d - e;
          int g = W[0] - a - d;
          int h = W[1] - b - e;
          int i = W[2] - c - f;
          if (min({c, f, g, h, i}) > 0 and g + h + i == H[2]) ans++;
          //条件h0, h1とw0, w1, w2 は,c, fとg, h, iを求めるために使って，
          //条件を満たしている数を決めたことになるので，条件h2 だけ考えればいいということ．
          
        }
      }
    }
  }
  cout << ans << "\n";
}

//DFS を用いた実装例
#include <iostream>
using namespace std;
int h[3], w[3], a[3][3];

long long ans = 0;

void dfs(int ij) {
  //ij は９まで動くということ．9になったら，i == 3で終了する．
  
  int i = ij / 3, j = ij % 3;
  // iは行h，jは列wにうまく対応している．
  
  if (i == 3) {//配列aの範囲外に突入
    ans++;
    return;
    //i == 3 まで進むことができたら，配列aの要素をすべてチェックし終えて，
    //h1, h2, h3とw1, w2, w3 の条件すべてを満たすことを確認された数の組になっているので，ans++;して84行目の再帰関数を終了している．
  }
  
  if (i == 2) {//３行目に突入
    int x = w[j] - a[0][j] - a[1][j];
    if (x <= 0) return;
    //条件を満たさない数の組になったら，84行目の再帰関数を終了している．
    //条件を満たさない組でそれ以上確認せずに終了することがDFSの肝
    
    
    a[i][j] = x, dfs(ij + 1);
    //条件を満たす数の組が見つかれば配列a に格納して，数を+1して次の要素を検討する再帰関数へ進んでいる．
    //g, h, iを決定している．
    
    
  } else if (j == 2) {//３列目に突入
    int x = h[i] - a[i][0] - a[i][1];
    if (x <= 0) return;
    //上記同様
    //c, fを決定している．
    //iは i ==2 で先に決定される．
    
    a[i][j] = x, dfs(ij + 1);
    //上記同様
    
  } else {
    for (int x = 1; x <= 30; x++) a[i][j] = x, dfs(ij + 1);
    //９つの要素a ~ i は30までの値を取るのでa[i][j] に代入して，再帰関数へ進んでいる．
    // 
    
  }
  
}

int main() {
  for (int i = 0; i < 3; i++) cin >> h[i];
  for (int j = 0; j < 3; j++) cin >> w[j];
  if (h[0] + h[1] + h[2] != w[0] + w[1] + w[2]) {
    //最初に和を考えて，簡単なチェックをしておく．
    //なるべくしなくて良い計算を省こうというわけだ．
    
    cout << 0 << "\n";
    return 0;
  }
  
  dfs(0);
  //0 から再帰関数で1 ずつ数を増やしてあり得るパターンをチェックしている．
  
  cout << ans << "\n";
}

//

