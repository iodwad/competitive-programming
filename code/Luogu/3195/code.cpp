// by iodwad
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e4;

int n, L;
int c[MAXN + 5], s[MAXN + 5];
int f[MAXN + 5];

struct Dot {
  int x, y;
  Dot(int o) { x = s[o]; y = f[o] + s[o] * s[o] + 2 * s[o] * L; }
};

double Slope(int x, int y) {
  Dot xx = Dot(x), yy = Dot(y);
  return (double)(yy.y - xx.y) / (yy.x - xx.x);
}

int q[MAXN + 5], hd, tl;

signed main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  cin >> n >> L; L = L + 1;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    s[i] = s[i - 1] + c[i];
  }
  for (int i = 1; i <= n; ++i) s[i] = s[i] + i;
  hd = 1; tl = 0; q[++tl] = 0;
  for (int i = 1; i <= n; ++i) {
    while (hd < tl && Slope(q[hd], q[hd + 1]) < 2.0 * s[i]) ++hd;
    int j = q[hd];
    f[i] = f[j] + (s[i] - s[j] - L) * (s[i] - s[j] - L);
    while (hd < tl && Slope(q[tl - 1], q[tl]) >= Slope(q[tl], i)) --tl;
    q[++tl] = i;
  }
  cout << f[n] << "\n";
  return 0;
}
