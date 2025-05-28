// by iodwad
#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int A, B, K, ans;

int dp[500];
int DP(int x) {
  static vector<int> fac; fac.clear();
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      fac.push_back(i);
      if (x / i != i) fac.push_back(x / i);
    }
  }
  sort(fac.begin(), fac.end());
  int n = fac.size();
  for (int i = 1; i < n; ++i) {
    dp[i] = 1e9;
    for (int j = 0; j < i; ++j) {
      if (fac[i] / fac[j] > K || fac[i] % fac[j] != 0) continue;
      dp[i] = min(dp[i], dp[j] + 1);
    }
  }
  return dp[n - 1];
}

void Solve() {
  cin >> A >> B >> K;
  int g = gcd(A, B); A /= g; B /= g;
  ans = DP(A) + DP(B);
  cout << (ans >= 1e9 ? -1 : ans) << "\n";
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
