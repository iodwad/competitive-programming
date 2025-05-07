// by iodwad
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int MAXN = 1e5;

int n, a[MAXN + 5];
long long ans;

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  ans = (i64)n * (n + 1) / 2;
  for (int v = 1; v <= 10; ++v) {
    static int buck[MAXN * 2 + 5], sum[MAXN + 5];
    int p = 0; 
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + (a[i] <= v ? 1 : -1);
      if (a[i] == v) {
        while (p < i) ++buck[sum[p++] + n];
      }
      ans -= buck[sum[i] + n];
      cnt += buck[sum[i] + n];
    }
    for (int i = 0; i < p; ++i) --buck[sum[i] + n];
  }
  cout << ans << "\n";
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
