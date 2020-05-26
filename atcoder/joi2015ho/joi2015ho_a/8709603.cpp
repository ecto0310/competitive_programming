// URL: https://atcoder.jp/contests/joi2015ho/submissions/8709603
// Date: Sat, 30 Nov 2019 20:40:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> p(m);
  for (i64 i = 0; i < m; i++)
    cin >> p[i];
  vector<i64> a(n), b(n), c(n);
  for (i64 i = 0; i < n - 1; i++)
    cin >> a[i] >> b[i] >> c[i];
  vector<i64> sum(n);
  for (i64 i = 0; i < m - 1; i++)
  {
    sum[min(p[i], p[i + 1]) - 1]++;
    sum[max(p[i], p[i + 1]) - 1]--;
  }
  for (i64 i = 0; i < n - 1; i++)
    sum[i + 1] += sum[i];
  i64 ans = 0;
  for (i64 i = 0; i < n - 1; i++)
    ans += min(a[i] * sum[i], b[i] * sum[i] + c[i]);
  cout << ans << endl;
  return 0;
}
