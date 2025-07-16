// by iodwad
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;

int n, ans, a[MAXN + 5], pa[MAXN + 5];
int tim, idfn[MAXN + 5], dfn[MAXN + 5], siz[MAXN + 5], wson[MAXN + 5];
vector<int> e[MAXN + 5];

void pre_dfs(int x, int fa) {
  pa[x] = a[x] ^ pa[fa];
  siz[x] = 1; idfn[dfn[x] = ++tim] = x;
  for (int to : e[x]) {
    if (to == fa) continue;
    pre_dfs(to, x);
    siz[x] += siz[to];
    if (siz[to] > siz[wson[x]]) wson[x] = to;
  }
}

map<int, int> buc;

vector<int> sons;
void get_son(int x, int fa) {
  sons.push_back(x);
  for (int to : e[x]) {
    if (to == fa) continue;
    get_son(to, x);
  }
}

void dfs(int x, int fa, bool Flag) {
  for (int to : e[x]) {
    if (to == fa || to == wson[x]) continue;
    dfs(to, x, false);
  }
  if (wson[x]) dfs(wson[x], x, true);
  for (int to : e[x]) {
    if (to == fa || to == wson[x]) continue;
    sons.clear(); get_son(to, x);
    for (int v : sons) {
      if (pa[v] == -1) continue;
      if (buc[pa[v] ^ a[x]]) {
        ++ans;
        buc.clear();
        e[x].clear(); 
        a[x] = pa[x] = -1;
        return;
      }
    }
    for (int v : sons) {
      if (pa[v] == -1) continue;
      ++buc[pa[v]];
    }
  }
  if (buc[pa[x] ^ a[x]]) {
    ++ans;
    buc.clear();
    e[x].clear();
    a[x] = pa[x] = -1;
    return;
  }
  if (!Flag) buc.clear();
  else ++buc[pa[x]];
}

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].push_back(v); e[v].push_back(u);
  }
  pre_dfs(1, 0);
  dfs(1, 0, false);
  cout << ans << "\n";
  return 0;
}
