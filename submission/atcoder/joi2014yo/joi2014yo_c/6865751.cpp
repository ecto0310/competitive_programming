// URL: https://atcoder.jp/contests/joi2014yo/submissions/6865751
// Date: Mon, 12 Aug 2019 17:48:15 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 w, h, n;
  cin >> w >> h >> n;
  vector<i64> x(n), y(n);
  for (i64 i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  i64 ans = 0;
  for (i64 i = 1; i < n; i++)
  {
    i64 dx = x[i] - x[i - 1], dy = y[i] - y[i - 1];
    if (0 < dx * dy)
      ans += max(abs(dx), abs(dy));
    else
      ans += abs(dx) + abs(dy);
  }
  cout << ans << endl;
  return 0;
}
