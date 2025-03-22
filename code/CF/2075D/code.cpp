// #pragma GCC optimize(2)
// by iodwad
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 X, Y;
i64 dp[61][120][120];

void pre_work() {
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 1; i <= 60; ++i) {
    for (int j = 0; j < 60; ++j) {
      for (int k = 0; k < 60; ++k) {
        dp[i][j][k] = dp[i - 1][j][k];
        if (j >= i) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - i][k] + (1ll << i));
        if (k >= i) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - i] + (1ll << i));
      }
    }
  }
}

void Solve() {
  cin >> X >> Y;
  i64 ans = 1e18;
  for (int i = 0; i < 60; ++i) {
    for (int j = 0; j < 60; ++j) {
      if (dp[60][i][j] >= ans) continue;
      if ((X >> i) == (Y >> j)) 
        ans = dp[60][i][j];
    }
  }
  cout << ans << "\n";
}

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  pre_work();
  int cases; cin >> cases;
  while (cases--) {
    Solve();
  }
  return 0;
}
