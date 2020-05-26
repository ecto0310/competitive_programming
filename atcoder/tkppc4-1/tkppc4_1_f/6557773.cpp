// URL: https://atcoder.jp/contests/tkppc4-1/submissions/6557773
// Date: Sat, 27 Jul 2019 17:55:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<vector<i64>> a(n, vector<i64>(m)), b(n, vector<i64>(m));
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      cin >> a[i][j];
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      cin >> b[i][j];
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    i64 mi = 1e9;
    for (i64 j = 0; j < m; j++)
      mi = min(mi, (ans + a[i][j] - 1) / a[i][j] * a[i][j] + b[i][j]);
    ans = mi;
  }
  cout << ans << endl;
  return 0;
}
