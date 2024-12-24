// by iodwad
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

int n, m, X, Q;
int a[MAXN + 5][MAXN + 5];
long long s1[MAXN + 5][MAXN + 5], s2[MAXN + 5][MAXN + 5];
int pw[10];

void init() {
  for (int i = 1; i <= 9; ++i) {
    pw[i] = 1;
    for (int j = 1; j <= X; ++j) pw[i] = pw[i] * i;
  }
}

int power(int x) {
  return pw[abs(x)] * (x < 0 ? -1 : 1);
}

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  cin >> n >> m >> X;
  for (int i = 1; i <= n; ++i) {
    static string str;
    cin >> str;
    for (int j = 1; j <= m; ++j) a[i][j] = str[j - 1] - '0';
  }
  init();
  bool flag = false;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      // if (a[i][j] != a[i + 1][j + 1] && a[i][j + 1] != a[i + 1][j]) {
      if (power(a[i][j] - a[i + 1][j]) + power(a[i + 1][j] - a[i + 1][j + 1]) != power(a[i][j] - a[i][j + 1]) + power(a[i][j + 1] - a[i + 1][j + 1]) || power(a[i + 1][j] - a[i][j]) + power(a[i][j] - a[i][j + 1]) != power(a[i + 1][j] - a[i + 1][j + 1]) + power(a[i + 1][j + 1] - a[i][j + 1])) {
        flag = true;
        break;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      s1[i][j] = s1[i][j - 1] + power(a[i][j] - a[i][j - 1]);
      s2[i][j] = s2[i - 1][j] + power(a[i][j] - a[i - 1][j]);
    }
  }
  cin >> Q;
  while (Q--) {
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    if (X == 1) {
      printf("%d\n", a[sx][sy] - a[ex][ey]);
    } else if (flag) {
      puts("INVALID");
    } else {
      long long ans = 0;
      int dx = sx > ex ? 1 : -1, dy = sy > ey ? 1 : -1;
      /*
      for (int i = sx; i != ex; i += dx) 
        ans += power(a[i][sy] - a[i + dx][sy]);
      for (int i = sy; i != ey; i += dy)
        ans += power(a[ex][i] - a[ex][i + dy]);
       */
      ans += (s1[sx][max(sy, ey)] - s1[sx][min(sy, ey)]) * dy;
      ans += (s2[max(sx, ex)][ey] - s2[min(sx, ex)][ey]) * dx;
      printf("%lld\n", ans);
    }
  }
  return 0;
}
