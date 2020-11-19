// URL: https://atcoder.jp/contests/joi2019ho/submissions/9893469
// Date: Tue, 04 Feb 2020 11:17:19 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<pair<i64, i64>> f(n);
  for (i64 i = 0; i < n; i++)
    cin >> f[i].second >> f[i].first;
  vector<i64> c(m);
  for (i64 i = 0; i < m; i++)
    cin >> c[i];
  sort(f.begin(), f.end(), greater<pair<i64, i64>>());
  sort(c.begin(), c.end(), greater<i64>());
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    if (ans < m && f[i].second <= c[ans])
      ans++;
  cout << ans << endl;
  return 0;
}
