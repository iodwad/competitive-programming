// by iodwad
#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

const int MAXN = 3e5;

i64 ans;
int n, tim;
int dfn[MAXN + 5], idfn[MAXN + 5], siz[MAXN + 5], dep[MAXN + 5], wson[MAXN + 5];
vector<int> e[MAXN + 5];

void pre_dfs(int x, int fa) {
  idfn[dfn[x] = ++tim] = x; siz[x] = 1; dep[x] = dep[fa] + 1; wson[x] = 0;
  for (int to : e[x]) {
    if (to == fa) continue;
    pre_dfs(to, x); siz[x] += siz[to];
    if (siz[to] > siz[wson[x]]) wson[x] = to;
  }
}

struct BIT {
  i64 sum[MAXN + 5];
  BIT() {}
  void modify(int pos, int v) {
    for (int i = pos; i <= n; i += i & (-i)) 
      sum[i] += v;
  }
  i64 query(int x) {
    i64 res = 0;
    for (int i = x; i; i -= i & (-i)) res += sum[i];
    return res;
  }
  i64 query(int l, int r) {
    if (l > r) return 0;
    return query(r) - query(l - 1); 
  }
} t1, t2;

void dfs(int x, int fa, bool flag) {
  int cnt = 0;
  for (int to : e[x]) {
    if (to == fa) continue;
    ans -= (i64)(2 * dep[x] + 1) * siz[to] * cnt;
    cnt += siz[to];
    if (to != wson[x]) dfs(to, x, false);
  }
  if (wson[x]) dfs(wson[x], x, true);
  for (int to : e[x]) {
    if (to == fa || to == wson[x]) continue;
    for (int i = dfn[to]; i <= dfn[to] + siz[to] - 1; ++i) {
      int v = idfn[i];
      ans += t2.query(1, dep[v]) * 2;
      ans += t1.query(dep[v] + 1, n) * (dep[v] * 2);
    }
    for (int i = dfn[to]; i <= dfn[to] + siz[to] - 1; ++i) {
      int v = idfn[i];
      t1.modify(dep[v], 1);
      t2.modify(dep[v], dep[v]);
    }
  }
  t1.modify(dep[x], 1);
  t2.modify(dep[x], dep[x]);
  if (flag == false) {
    for (int i = dfn[x]; i <= dfn[x] + siz[x] - 1; ++i) {
      int v = idfn[i];
      t1.modify(dep[v], -1);
      t2.modify(dep[v], -dep[v]);
    }
  }
}

void Solve() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].push_back(v); e[v].push_back(u);
  }
  pre_dfs(1, 0);
  dfs(1, 0, false);
  cout << ans << "\n";

  ans = tim = 0;
  for (int i = 1; i <= n; ++i) e[i].clear();
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
