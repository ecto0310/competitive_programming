// URL: https://atcoder.jp/contests/abc031/submissions/9372566
// Date: Fri, 10 Jan 2020 01:12:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 ans = -1e9;
  for (i64 i = 0; i < n; i++)
  {
    i64 am = -1e9, bm = -1e9;
    for (i64 j = 0; j < n; j++)
      if (i != j)
      {
        i64 ta = 0, tb = 0;
        for (i64 k = min(i, j); k <= max(i, j); k++)
          if ((k - min(i, j)) % 2 == 0)
            ta += a[k];
          else
            tb += a[k];
        if (bm < tb)
        {
          am = ta;
          bm = tb;
        }
      }
    ans = max(ans, am);
  }
  cout << ans << endl;
  return 0;
}
