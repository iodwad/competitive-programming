// by iodwad
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

int n, m, K, h[MAXN + 5], X[MAXN + 5];

bool check(int mid) {
  static vector<int> p; p.clear();
  static int l[MAXN + 5], r[MAXN + 5];
  static int sum[MAXN * 2 + 5];
  for (int i = 1; i <= 2 * n; ++i) sum[i] = 0;
  for (int i = 1; i <= n; ++i) {
    int len = m - (int)ceil((double)h[i] / mid);
    p.push_back(l[i] = X[i] - len);
    p.push_back(r[i] = X[i] + len);
  }
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  for (int i = 1; i <= n; ++i) {
    l[i] = lower_bound(p.begin(), p.end(), l[i]) - p.begin() + 1;
    r[i] = lower_bound(p.begin(), p.end(), r[i]) - p.begin() + 1;
    if (l[i] > r[i]) continue;
    ++sum[l[i]]; --sum[r[i] + 1];
  }
  int siz = p.size();
  for (int i = 1; i <= siz; ++i) sum[i] += sum[i - 1];
  for (int i = 1; i <= siz; ++i) if (sum[i] >= K) return true;
  return false;
}

void solve() {
  cin >> n >> m >> K;
  for (int i = 1; i <= n; ++i) cin >> h[i];
  for (int i = 1; i <= n; ++i) cin >> X[i];
  int l = 1, r = 1e9, res = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      res = mid;
      r = mid - 1;
    } else l = mid + 1;
  }
  cout << res << "\n";
}

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  int cases; cin >> cases;
  while (cases--) {
    solve();
  }
  return 0;
}
