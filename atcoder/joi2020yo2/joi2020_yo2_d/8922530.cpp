// URL: https://atcoder.jp/contests/joi2020yo2/submissions/8922530
// Date: Thu, 12 Dec 2019 18:17:10 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mov[10][10] = {{1, 2, 3, 4, 3, 4, 5, 4, 5, 6},
                   {2, 1, 2, 3, 2, 3, 4, 3, 4, 5},
                   {3, 2, 1, 2, 3, 2, 3, 4, 3, 4},
                   {4, 3, 2, 1, 4, 3, 2, 5, 4, 3},
                   {3, 2, 3, 4, 1, 2, 3, 2, 3, 4},
                   {4, 3, 2, 3, 2, 1, 2, 3, 2, 3},
                   {5, 4, 3, 2, 3, 2, 1, 4, 3, 2},
                   {4, 3, 4, 5, 2, 3, 4, 1, 2, 3},
                   {5, 4, 3, 4, 3, 2, 3, 2, 1, 2},
                   {6, 5, 4, 3, 4, 3, 2, 3, 2, 1}};

int main()
{
  i64 m, r;
  cin >> m >> r;
  vector<vector<i64>> dp(m, vector<i64>(10, 1e18));
  dp[0][0] = 0;
  while (true)
  {
    bool ok = true;
    for (i64 i = 0; i < m; i++)
      for (i64 j = 0; j < 10; j++)
        for (i64 k = 0; k < 10; k++)
          if (dp[i][k] + mov[k][j] < dp[(i * 10 + j) % m][j])
          {
            dp[(i * 10 + j) % m][j] = dp[i][k] + mov[k][j];
            ok = false;
          }
    if (ok)
      break;
  }
  i64 ans = 1e18;
  for (i64 i = 0; i < 10; i++)
    ans = min(ans, dp[r][i]);
  cout << ans << endl;
  return 0;
}
