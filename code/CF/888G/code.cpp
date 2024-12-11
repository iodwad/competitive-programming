// by iodwad
#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

const int MAXN = 5e5;

int n, a[MAXN + 5];
i64 ans;

int tot;
int ch[MAXN * 31 + 5][2];

int query(int o, int v, int dep) {
  int res = 0;
  for (int i = dep; ~i; --i) {
    int cur = (v >> i) & 1;
    res <<= 1;
    if (ch[o][cur]) o = ch[o][cur];
    else {
      o = ch[o][cur ^ 1];
      res |= 1;
    }
  }
  return res;
}

int solve(int l, int r, int dep = 29) {
  if (l > r) return 0;
  int mid = l;
  while (mid <= r && ((a[mid] >> dep) & 1) == 0) ++mid;
  --mid;
  int o = ++tot;
  if (dep == -1) return o;
  int ls = solve(l, mid, dep - 1);
  int rs = solve(mid + 1, r, dep - 1);
  if (mid != l - 1 && mid != r) {
    int res = (1 << 30) + 1;
    for (int i = mid + 1; i <= r; ++i) 
      res = min(res, query(ls, a[i], dep - 1));
    res |= (1 << dep);
    ans += res;
  }
  ch[o][0] = ls; ch[o][1] = rs;
  return o;
}

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  solve(1, n, 29);
  cout << ans << "\n";
  return 0;
}
