// by iodwad
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int MAXK = 1e5;
const int MOD = 998244353;;

int add(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
int sub(int x, int y) { return x < y ? x - y + MOD : x - y; }
int fpow(int x, int y) {
  int res = 1;
  for (int i = x; y; i = (i64)i * i % MOD, y >>= 1)
    if (y & 1) res = (i64)res * i % MOD;
  return res;
}
int Inv(int x) { return fpow(x, MOD - 2); }

int n, K;
vector<int> fac[MAXK + 5];

void pre_work() {
  for (int i = 2; i <= MAXK; ++i) 
    for (int j = i; j <= MAXK; j += i) 
      fac[j].push_back(i);
}

int dp[20][MAXK + 5];
void Solve() {
  cin >> K >> n;
  dp[0][1] = 1;
  for (int i = 1; i <= min(19, n); ++i) {
    for (int j = 2; j <= K; ++j) {
      dp[i][j] = 0;
      for (int k : fac[j]) {
        if (k > K) break;
        dp[i][j] = add(dp[i][j], dp[i - 1][j / k]);
      }
    }
  }
  for (int i = 1; i <= K; ++i) {
    int C = n + 1, ans = 0;
    for (int j = 0; j <= min(n, 19); ++j) {
      ans = add(ans, (i64)dp[j][i] * C % MOD);
      C = (i64)C * (n - j) % MOD * Inv(j + 2) % MOD;
    }
    if (i == 1) --ans;
    cout << ans << " ";
  }
  cout << "\n";
}

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  int cases; cin >> cases;
  pre_work();
  while (cases--) {
    Solve();
  }
  return 0;
}
