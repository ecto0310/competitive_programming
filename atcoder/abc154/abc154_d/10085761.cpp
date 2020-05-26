// URL: https://atcoder.jp/contests/abc154/submissions/10085761
// Date: Fri, 14 Feb 2020 15:55:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<double> p(n + 1);
  for (i64 i = 0; i < n; i++)
  {
    i64 t;
    cin >> t;
    p[i + 1] = (double)(t + 1) / 2;
  }
  for (i64 i = 1; i <= n; i++)
    p[i] += p[i - 1];
  double ans = 0;
  for (i64 i = 0; i < n - k + 1; i++)
    ans = max(ans, p[i + k] - p[i]);
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
