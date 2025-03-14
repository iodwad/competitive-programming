// by iodwad
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

int n, X[MAXN + 5], Y[MAXN + 5];
int ans, ansx, ansy;
vector<int> dot[MAXN + 5];

bool check(int lim) {
  static int lmin[MAXN + 5], lmax[MAXN + 5], rmin[MAXN + 5], rmax[MAXN + 5];
  static int buck[MAXN + 5];
  for (int i = 1, nmin = n + 1, nmax = 0, cnt1 = 0, cnt2 = 0; i <= n; ++i) {
    for (int p : dot[i - 1]) {
      ++buck[Y[p]];
      cnt1 += (Y[p] < nmin);
      cnt2 += (Y[p] >= nmax);
    }
    while (nmin > 1 && cnt1 - buck[nmin - 1] >= lim) cnt1 -= buck[--nmin];
    while (nmax <= n && cnt2 - buck[nmax] >= lim) cnt2 -= buck[nmax++];
    lmin[i] = nmin; lmax[i] = nmax;
  }
  memset(buck, 0, sizeof(buck));
  for (int i = n, nmin = n + 1, nmax = 0, cnt1 = 0, cnt2 = 0; i >= 1; --i) {
    for (int p : dot[i]) {
      ++buck[Y[p]];
      cnt1 += (Y[p] < nmin);
      cnt2 += (Y[p] >= nmax);
    }
    while (nmin > 1 && cnt1 - buck[nmin - 1] >= lim) cnt1 -= buck[--nmin];
    while (nmax <= n && cnt2 - buck[nmax] >= lim) cnt2 -= buck[nmax++];
    rmin[i] = nmin; rmax[i] = nmax;
  }
  memset(buck, 0, sizeof(buck));
  for (int i = 1; i <= n; ++i) {
    int l = max(lmin[i], rmin[i]), r = min(lmax[i], rmax[i]);
    if (l <= r) {
      ansx = i;
      ansy = l;
      return true;
    }
  }
  return false;
}

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> X[i] >> Y[i];
  static vector<int> xx, yy; xx.clear(); yy.clear();
  for (int i = 1; i <= n; ++i) xx.push_back(X[i]), yy.push_back(Y[i]);
  sort(xx.begin(), xx.end()); xx.erase(unique(xx.begin(), xx.end()), xx.end());
  sort(yy.begin(), yy.end()); yy.erase(unique(yy.begin(), yy.end()), yy.end());
  for (int i = 1; i <= n; ++i) X[i] = lower_bound(xx.begin(), xx.end(), X[i]) - xx.begin() + 1;
  for (int i = 1; i <= n; ++i) Y[i] = lower_bound(yy.begin(), yy.end(), Y[i]) - yy.begin() + 1;
  int l = 1, r = n / 4;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else r = mid - 1;
  }
  cout << ans << "\n" << xx[ansx - 1] << " " << yy[ansy - 1] << "\n";
  for (int i = 1; i <= n; ++i) dot[i].clear();
  ans = 0; ansx = 1; ansy = 1;
}

int main() {
  int cases; cin >> cases;
  while (cases--) {
    Solve();
  }
  return 0;
}
