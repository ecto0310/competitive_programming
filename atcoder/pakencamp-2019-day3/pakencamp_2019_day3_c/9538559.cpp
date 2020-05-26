// URL: https://atcoder.jp/contests/pakencamp-2019-day3/submissions/9538559
// Date: Fri, 17 Jan 2020 00:18:43 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<vector<i64>> a(n, vector<i64>(m));
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < m; j++)
      cin >> a[i][j];
  i64 ans = 0;
  for (i64 i = 0; i < m; i++)
    for (i64 j = 0; j < m; j++)
    {
      i64 tmp = 0;
      for (i64 k = 0; k < n; k++)
        tmp += max(a[k][i], a[k][j]);
      ans = max(ans, tmp);
    }
  cout << ans << endl;
  return 0;
}
