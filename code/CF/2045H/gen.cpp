// by iodwad
#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(0));
int randint(int l, int r) { return l + rnd() % (r - l); }

int main() {
  freopen("code.in", "w", stdout);
  int n = 5000;
  for (int i = 1; i <= n; ++i)
    // putchar(randint(0, 25) + 'A');
    putchar(i % 2 + 'A');
  return 0;
}

