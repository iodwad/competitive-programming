// by iodwad
#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

const int MOD = 998244353;
const int MAXN = 1e6;

int add(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
int sub(int x, int y) { return x < y ? x - y + MOD : x - y; }
void Add(int &x, int y) { x = add(x, y); }
void Sub(int &x, int y) { x = sub(x, y); }
int mul(int x, int y) { return (i64)x * y % MOD; }

int n;
int f[MAXN + 5], ans[MAXN + 5];

void DP() {
  ans[2] = 1;
  for (int i = 3, sum = 0, s = 0; i <= MAXN; ++i) {
    Add(sum, mul(f[i], i));
    Add(s, f[i]);
    Add(f[i + 1], sum);
    Add(f[i + 1], (i64)(i + 1) * (i - 2) / 2 % MOD);
    Add(ans[i], s);
    Add(ans[i], 1);
    Add(ans[i], i - 2);
  }
}

void solve() {
  cin >> n;
  cout << ans[n] << "\n";
}

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  DP();
  int cases; cin >> cases;
  while (cases--) {
    solve();
  }
  return 0;
}
