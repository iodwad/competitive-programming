// by iodwad
#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

const int MAXN = 3e5;

i64 ans;
int n, m;
int a[MAXN + 5], lst[MAXN + 5];

struct BIT {
  int sum[MAXN + 5];
  void modify(int x, int v) {
    for (int i = x; i <= n; i += i & (-i)) sum[i] += v;
  }
  int query(int x) {
    int res = 0;
    for (int i = x; i; i -= i & (-i)) res += sum[i];
    return res;
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
} t;

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    if (!lst[a[i]]) ans += m - 1;
    else if (lst[a[i]]) {
      ans += t.query(lst[a[i]] + 1, i);
      t.modify(lst[a[i]], -1);
    }
    lst[a[i]] = i;
    t.modify(i, 1);
  }
  cout << ans << "\n";
  return 0;
}
