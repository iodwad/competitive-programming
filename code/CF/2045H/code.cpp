// by iodwad
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3;

int n;
char str[MAXN + 5];
int lcs[MAXN + 5][MAXN + 5];
pair<int, int> dp[MAXN + 5][MAXN + 5];

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  scanf("%s", str + 1);
  n = strlen(str + 1);
  for (int i = n; i >= 1; --i)
    for (int j = n; j > i; --j)
      lcs[i][j] = str[i] == str[j] ? lcs[i + 1][j + 1] + 1 : 0;
  for (int i = 0; i <= n; ++i) 
    for (int j = 0; j <= n; ++j)
      dp[i][j].first = -1e9;
  for (int r = 1; r <= n; ++r) {
    for (int l = 1; l <= r; ++l) {
      if (dp[l][r - 1] > dp[l][r]) {
        dp[l][r] = dp[l][r - 1];
      }
      if (l == 1) dp[l][r].first = 1;
      int k = lcs[l][r + 1];
      if (k > r - l + 1 || (k == r - l + 1 && r + k < n) || str[l + k] < str[r + 1 + k]) {
        int nr = r + 1 + min(k, r - l + 1);
        if (dp[r + 1][nr] < pair(dp[l][r].first + 1, dp[l][r].second)) {
          dp[r + 1][nr] = dp[l][r];
          ++dp[r + 1][nr].first;
          dp[r + 1][nr].second = l;
        }
      }
    }
  }
  int ans = 0, ansl = 0;
  for (int l = 1; l <= n; ++l) {
    if (ans < dp[l][n].first) {
      ans = dp[l][n].first;
      ansl = l;
    }
  }
  static vector<pair<int, int>> p; p.clear();
  for (int l = ansl, r = n; l >= 1; ) {
    p.emplace_back(l, r);
    int nl = dp[l][r].second;
    r = l - 1; l = nl;
  }
  reverse(p.begin(), p.end());
  printf("%d\n", ans);
  for (auto &[l, r] : p) {
    for (int i = l; i <= r; ++i) 
      printf("%c", str[i]);
    printf("\n");
  }
  return 0;
}
