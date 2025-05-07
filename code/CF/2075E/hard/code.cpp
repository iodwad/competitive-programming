// by iodwad
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400;
const int MAXM = (MAXN) * (MAXN - 1) / 2;

int n, m, Q;
int U[MAXM + 5], V[MAXM + 5], W[MAXM + 5];
int dis[MAXN + 5][MAXN + 5][MAXN + 5], bel[MAXM + 5];

struct Fset {
  int f[MAXN + 5];
  Fset() {}
  void init() { iota(f, f + n + 1, 0); }
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
  bool merge(int x, int y) {
    if (find(x) == find(y)) return false;
    return f[find(x)] = find(y), true;
  }
} fset;

void Solve() {
  cin >> n >> m >> Q;
  for (int i = 1; i <= m; ++i) cin >> U[i] >> V[i] >> W[i];
  static int id[MAXM + 5]; iota(id, id + m + 1, 0);
  fset.init();
  sort(id + 1, id + m + 1, [&](int x, int y) { return W[x] < W[y]; });
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) dis[0][i][j] = 1e9;
    dis[0][i][i] = 0;
  }
  for (int i = 1; i <= m; ++i) dis[0][U[i]][V[i]] = dis[0][V[i]][U[i]] = 1;
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) 
        dis[0][i][j] = min(dis[0][i][j], dis[0][i][k] + dis[0][k][j]);
  int tot = 0; // total of useful edges
  for (int k = 1; k <= m; ++k) {
    int now = id[k];
    if (!fset.merge(U[now], V[now])) {
      bel[k] = bel[k - 1];
      continue;
    }
    bel[k] = ++tot;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dis[tot][i][j] = min(dis[tot - 1][i][U[now]] + dis[tot - 1][V[now]][j], dis[tot - 1][i][V[now]] + dis[tot - 1][U[now]][j]);
        dis[tot][i][j] = min(dis[tot][i][j], dis[tot - 1][i][j]);
      }
    }
  }
  while (Q--) {
    int a, b, K;
    cin >> a >> b >> K;
    int l = 1, r = m, ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (dis[bel[mid]][a][b] < K) {
        r = mid - 1;
        ans = mid;
      } else l = mid + 1;
    }
    cout << W[id[ans]] << " ";
  }
  cout << "\n";
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
