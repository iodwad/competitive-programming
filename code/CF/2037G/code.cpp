// by iodwad
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int MAXN = 2e5;
const int MAXV = 1e6;
const int MOD = 998244353;

int add(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
int sub(int x, int y) { return x < y ? x - y + MOD : x - y; }
int mul(int x, int y) { return (i64)x * y % MOD; }

namespace Number {
  int pn, pr[MAXV + 5], mu[MAXV + 5];
  bool np[MAXV + 5];
  vector<int> fac[MAXV + 5];
  void Sieve(int n) {
    mu[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (!np[i]) {
        pr[++pn] = i;
        mu[i] = MOD - 1;
      }
      for (int j = 1; j <= pn && i * pr[j] <= n; ++j) {
        np[i * pr[j]] = true;
        mu[i * pr[j]] = sub(0, mu[i]);
        if (i % pr[j] == 0) {
           mu[i * pr[j]] = 0;
           break;
        }
      }
    }
    for (int i = 1; i <= n; ++i) 
      for (int j = i; j <= n; j += i)
        fac[j].push_back(i);
  }
}

using namespace Number;

int n, a[MAXN + 5], f[MAXN + 5], g[MAXV + 5];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  f[1] = 1;
  for (int i = 1, sum = 0; i <= n; ++i) {
    for (int d : fac[a[i]]) 
      f[i] = add(f[i], mul(mu[d], g[d]));
    if (i > 1) f[i] = sub(sum, f[i]);
    for (int d : fac[a[i]])
      g[d] = add(g[d], f[i]);
    sum = add(sum, f[i]);
  }
  cout << f[n] << "\n";
}

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  Sieve(MAXV);
  solve();
  return 0;
}
