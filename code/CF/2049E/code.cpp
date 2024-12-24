// by iodwad
#include <bits/stdc++.h>

using namespace std;

int n, O3;

int query(int l, int r) {
  if (l > r) swap(l, r);
  cout << "? " << l << " " << r << "\n";
  cout.flush();
  int res; cin >> res;
  return res;
}

void solve_1(int L, int R) { // k <= len / 2
  bool flag = false;
  auto id = [&](int x) { 
    return !flag ? x : R + L - x;
  };
  if (O3) flag = true;
  if (!O3 && !query(L, (L + R) / 2)) return cout << "! " << n / 2 << "\n", void();
  int l = L, r = (L + R) >> 1, res = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (query(id(L), id(mid)) == 1) {
      r = mid - 1;
      res = mid;
    } else l = mid + 1;
  }
  cout << "! " << abs(id(res) - id(L)) + 1 << "\n";
}

void solve_2(int L, int R) { // k > len / 2
  bool flag = false;
  auto id = [&](int x) { 
    return !flag ? x : R + L - x;
  };
  if (O3) flag = true;
  int l = (L + R) / 2 + 1, r = R, res = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (query(id(L), id(mid)) == 0) {
      r = mid - 1;
      res = mid;
    } else l = mid + 1;
  }
  cout << "! " << abs(id(res) - id(L)) + 1 << "\n";
}

int main() {
  int cases; cin >> cases;
  while (cases--) {
    cin >> n;
    int o1 = query(1, n / 4), o2 = query(n / 4 + 1, n / 2), o3 = query(n / 2 + 1, n);
    O3 = o3;
    if (o1 == 1 && o2 == 1) {
      if (!o3) solve_1(1, n);
      else solve_2(1, n);
    } else if (o1 == 0 && o2 == 0) {
      if (!o3) solve_1(1, n);
      else solve_2(1, n);
    } else {
      if (o3) 
        solve_1(1, n);
      else 
        solve_2(1, n);
    }
  }
  return 0;
}
