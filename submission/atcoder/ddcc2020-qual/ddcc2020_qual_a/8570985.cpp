// URL: https://atcoder.jp/contests/ddcc2020-qual/submissions/8570985
// Date: Sat, 23 Nov 2019 21:01:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 x, y;
  cin >> x >> y;
  i64 ans = 0;
  if (x == 3)
    ans += 100000;
  else if (x == 2)
    ans += 200000;
  else if (x == 1)
    ans += 300000;
  if (y == 3)
    ans += 100000;
  else if (y == 2)
    ans += 200000;
  else if (y == 1)
    ans += 300000;
  if (x == 1 && y == 1)
    ans += 400000;
  cout << ans << endl;
  return 0;
}
