// URL: https://atcoder.jp/contests/abc126/submissions/5462387
// Date: Sun, 19 May 2019 21:29:46 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  double ans = 0;
  for (i64 i = 1; i <= n; i++)
  {
    double tmp = 1;
    i64 t = i;
    while (t < k)
    {
      tmp *= 0.5;
      t *= 2;
    }
    ans += tmp / n;
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
