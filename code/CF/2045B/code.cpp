// by iodwad
#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

int a[1000];
i64 n, d, s, ans;

i64 get_ans(i64 x) {
  if (x == 1) return 1;
  return min(d / s / (x - 1), n / s / x) * x;
}

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  cin >> n >> d >> s;
  i64 v1 = d / s, v2 = n / s; 
  ans = 1;
  for (i64 l = 1, r = 0; l <= v1; l = r + 1) {
    r = min(v1 / (v1 / l), v2 / (v2 / l));
    if (l < r) 
      ans = max(ans, v1 / l * (r - 1));
    ans = max(ans, get_ans(r + 1));
  }
  ans = ans * s;
  cout << ans << "\n";
  return 0;
}
