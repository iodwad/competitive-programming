// by iodwad
#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

const int MAXN = 1e5;

int L, R, n;

int id(int x) { return x - L + 1; }

int fset[MAXN + 5];
int find(int x) { return fset[x] == x ? x : fset[x] = find(fset[x]); }
void merge(int x, int y){ fset[find(x)] = find(y); }

struct Edge {
  int u, v;
  i64 w;
  Edge(int _u = 0, int _v = 0, i64 _w = 0) : u(_u), v(_v), w(_w) {}
  friend bool operator< (const Edge &lhs, const Edge &rhs) { return lhs.w < rhs.w; }
};

vector<Edge> e;

i64 Kruskal() {
  i64 res = 0;
  sort(e.begin(), e.end());
  for (int i = 1; i <= n; ++i) fset[i] = i;
  for (auto &[u, v, w] : e) {
    if (find(u) == find(v)) continue;
    merge(u, v);
    res += w;
  }
  return res;
}

int main() {
  // ios::sync_with_stdio(false); cin.tie(0);
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  cin >> L >> R; n = R - L + 1;
  for (int d = 1; d <= 1000000; ++d) {
    int l = (L / d + (L % d != 0)) * d;
    for (int i = l + d; i <= R; i += d) {
      e.emplace_back(id(l), id(i), (i64)l * i / d);
    }
  }
  cout << Kruskal() << "\n";
  return 0;
}
