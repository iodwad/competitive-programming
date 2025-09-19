// by iodwad
#include <bits/stdc++.h>

using namespace std;

void Solve() {
  long long a, b; cin >> a >> b;
  long long c = a * a - b * b;
  if (c < 0) c = -c;
  long long ans = c;
  if (c == 3) return puts("1"), void();
  if (c == 5) return puts("2"), void();
  if (c == 7) return puts("3"), void();
  if (c == 8) return puts("4"), void();
  if (c % 2 == 0) {
    long long d = c / 2 - 1;
    ans -= (d + 1) / 2;
  } else {
    long long d = c - 1;
    if ((d / 2) % 2 == 0) {
      d = d - 2;
    }
    ans -= (d / 2 + 1) / 2;
  }
  ans = ans - 2;
  printf("%lld\n", ans);
}

int main() {
  // freopen("E.in", "r", stdin);
  // freopen("E.out", "w", stdout);
  /*
  int tot = 0;
  for (int i = 1; i <= 100; ++i) 
    for (int j = i + 1; j <= 100; ++j)
      a[++tot] = j * j - i * i;
  sort(a + 1, a + tot + 1);
  tot = unique(a + 1, a + tot + 1) - a - 1;
  for (int i = 1; i <= tot; ++i) 
    printf("%d ", a[i]);
    */
  int cases; cin >> cases;
  while (cases--) {
    Solve();
  }
  return 0;
}
