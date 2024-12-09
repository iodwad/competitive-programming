// by iodwad
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;

int n, a[MAXN + 5];
int atot;
map<int, int> id;
set<int> idx[MAXN + 5];

struct Trie {
  int sum[MAXN * 30 + 5], ch[MAXN * 30 + 5][2];
  int tot;
  Trie() : tot(1) {}
  void insert(int x, int v) {
    int o = 1;
    for (int i = 30; ~i; --i) {
      int cur = (x >> i) & 1;
      if (!ch[o][cur]) ch[o][cur] = ++tot;
      o = ch[o][cur];
      sum[o] += v;
    }
  }
  pair<int, int> query(int x) {
    int o = 1, res = 0, num = 0;
    for (int i = 30; ~i; --i) {
      int cur = (x >> i) & 1;
      if (!sum[ch[o][cur]]) {
        cur ^= 1;
        res |= (1 << i);
      }
      o = ch[o][cur];
      num = num | (cur << i);
      if (!o) return make_pair((int)1e9, -1);
    }
    return make_pair(res, num);
  }
} t;

struct Fset {
  int f[MAXN + 5];
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
  bool chk(int x, int y) { return find(x) == find(y); }
  void merge(int x, int y) { f[find(x)] = find(y); }
} fset;

void Boruvka() {
  long long ans = 0;
  static vector<int> p[MAXN + 5];
  for (int i = 1; i <= n; ++i) {
    t.insert(a[i], 1);
    fset.f[i] = i;
  }
  for (int etot = 0; etot < n - 1; ) {
    for (int i = 1; i <= n; ++i) p[i].clear();
    for (int i = 1; i <= n; ++i) p[fset.find(i)].push_back(i);
    for (int i = 1; i <= n; ++i) {
      if (p[i].empty()) continue;
      for (int &x : p[i]) {
        t.insert(a[x], -1);
        idx[id[a[x]]].erase(x);
      }
      pair<int, int> res((int)1e9, 0);
      int to;
      for (int &x : p[i]) 
        res = min(res, t.query(a[x]));
      if (res.first != -1) to = *idx[id[res.second]].begin();
      if (!fset.chk(p[i][0], to)) {
        ans += res.first;
        fset.merge(p[i][0], to);
        ++etot;
      }
      for (int &x : p[i]) {
        t.insert(a[x], 1);
        idx[id[a[x]]].insert(x);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    if (!id[a[i]]) id[a[i]] = ++atot;
    idx[id[a[i]]].insert(i);
  }
  Boruvka();
  return 0;
}
