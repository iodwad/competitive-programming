// by iodwad
#include <bits/stdc++.h>

using namespace std;

void Solve() {
  int l, r, k; cin >> l >> r;
  for (int i = 30; ~i; --i) {
    if ((l ^ r) & (1 << i)) {
      k = i;
      break;
    }
  }
  int a, b, c;
  int tmp = (l >> k + 1) << k + 1;
  a = (1 << k) - 1 + tmp; b = a + 1; c = l;
  if (a == c) c = r;
  printf("%d %d %d\n", a, b, c);
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
