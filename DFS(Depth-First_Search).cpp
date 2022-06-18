//ABC256 C-Filling 3x3 array の解説をもとに勉強をはじめました．リンクは次
//https://atcoder.jp/contests/abc256/editorial/4129
//


//疑似コード
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
  int i = ij / 3, j = ij % 3;
  if (i == 3) {
    ans++;
    return;
  }
  if (i == 2) {
    int x = w[j] - a[0][j] - a[1][j];
    if (x <= 0) return;
    a[i][j] = x, dfs(ij + 1);
  } else if (j == 2) {
    int x = h[i] - a[i][0] - a[i][1];
    if (x <= 0) return;
    a[i][j] = x, dfs(ij + 1);
  } else {
    for (int x = 1; x <= 30; x++) a[i][j] = x, dfs(ij + 1);
  }
}
int main() {
  for (int i = 0; i < 3; i++) cin >> h[i];
  for (int j = 0; j < 3; j++) cin >> w[j];
  if (h[0] + h[1] + h[2] != w[0] + w[1] + w[2]) {
    cout << 0 << "\n";
    return 0;
  }
  dfs(0);
  cout << ans << "\n";
}

//

