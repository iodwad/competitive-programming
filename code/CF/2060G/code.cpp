// by iodwad
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;

int n, a[MAXN + 5], b[MAXN + 5];

struct BIT {
  int maxv[MAXN * 2 + 5];
  void modify(int x, int v) {
    for (int i = x; i <= 2 * n; i += i & (-i)) 
      maxv[i] = max(maxv[i], v);
  }
  int query(int x) {
    int res = -1e9;
    for (int i = x; i; i -= i & (-i))
      res = max(res, maxv[i]);
    return res;
  }
  void clear() {
    for (int i = 1; i <= 2 * n; ++i) maxv[i] = -1e9;
  }
} t[2];

struct Pair {
  int x, y, op;
  Pair(int _x = 0, int _y = 0, int _op = 0) : x(_x), y(_y), op(_op) {}
  friend bool operator< (const Pair &lhs, const Pair &rhs) {
    return lhs.x < rhs.x; 
  }
} p[MAXN * 2 + 5];

int dp[MAXN * 2 + 5][2];

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  for (int i = 1; i <= n; ++i) {
    p[i] = Pair(a[i], b[i], 0);
    p[i + n] = Pair(b[i], a[i], 1);
  }
  sort(p + 1, p + 2 * n + 1);
  t[0].clear(); t[1].clear();
  for (int i = 1; i <= 2 * n; ++i) {
    int op = p[i].op, y = p[i].y;
    dp[i][0] = dp[i][1] = -1e9; dp[i][op] = 1;
    for (int j = 0; j <= 1; ++j) 
      dp[i][j] = max(dp[i][j], t[j ^ op].query(y - 1) + 1);
    for (int j = 0; j <= 1; ++j) 
      t[j].modify(y, dp[i][j]);
  }
  for (int i = 1; i <= 2 * n; ++i) 
    if (dp[i][0] == n)
      return puts("YES"), void();
  puts("NO");
}

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  int cases; cin >> cases;
  while (cases--) {
    Solve();
  }
  return 0;
}
