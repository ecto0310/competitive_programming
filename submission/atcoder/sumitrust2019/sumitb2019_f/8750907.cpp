// URL: https://atcoder.jp/contests/sumitrust2019/submissions/8750907
// Date: Sun, 01 Dec 2019 23:15:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  i64 p = (a1 - b1) * t1, q = (a2 - b2) * t2;
  if (0 < p)
  {
    p *= -1;
    q *= -1;
  }
  if (p + q < 0)
    cout << 0 << endl;
  else if (p + q == 0)
    cout << "infinity" << endl;
  else if (-p % (p + q) == 0)
    cout << -p / (p + q) * 2 << endl;
  else
    cout << -p / (p + q) * 2 + 1 << endl;
  return 0;
}
