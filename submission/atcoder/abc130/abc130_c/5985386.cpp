// URL: https://atcoder.jp/contests/abc130/submissions/5985386
// Date: Sun, 16 Jun 2019 22:43:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 w, h, x, y;
  cin >> w >> h >> x >> y;
  cout << fixed << setprecision(10) << (double)w * h / 2 << " " << (x * 2 == w && y * 2 == h ? 1 : 0) << endl;
  return 0;
}
