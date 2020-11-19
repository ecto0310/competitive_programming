// URL: https://atcoder.jp/contests/abc146/submissions/8615862
// Date: Sun, 24 Nov 2019 21:27:57 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, x;
  cin >> a >> b >> x;
  i64 ans = 0;
  for (i64 i = 0; i < 9; i++)
  {
    i64 ok = pow(10, i) - 1, ng = pow(10, i + 1) + 1;
    while (1 < ng - ok)
    {
      i64 mid = (ok + ng) / 2;
      i64 c = mid * a;
      i64 t = mid;
      while (t)
      {
        c += b;
        t /= 10;
      }
      if (c <= x)
        ok = mid;
      else
        ng = mid;
    }
    if (ng != pow(10, i))
      ans = max(ans, ok);
  }
  cout << ans << endl;
  return 0;
}
