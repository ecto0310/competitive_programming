// URL: https://atcoder.jp/contests/joi2020ho/submissions/10031225
// Date: Mon, 10 Feb 2020 23:49:51 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 INF = 1e9;

i64 dp[202][202][202][2];

int main()
{
  i64 n, l;
  cin >> n >> l;
  vector<i64> x(n + 2), t(n + 2);
  for (i64 i = 0; i < n; i++)
    cin >> x[i + 1];
  for (i64 i = 0; i < n; i++)
    cin >> t[i + 1];
  x[n + 1] = l;
  for (i64 i = 0; i <= n; i++)
    for (i64 j = 0; j <= n; j++)
      for (i64 k = 0; k <= n; k++)
        dp[i][j][k][0] = dp[i][j][k][1] = INF;
  dp[0][0][0][0] = dp[0][0][0][1] = 0;
  for (i64 i = 0; i <= n; i++)
    for (i64 j = 0; j <= n; j++)
      for (i64 k = 0; k < n; k++)
      {
        if (i + 1 + j <= n)
        {
          i64 m = dp[i][j][k][0] + x[i + 1] - x[i];
          if (m <= t[i + 1])
            dp[i + 1][j][k + 1][0] = min(dp[i + 1][j][k + 1][0], m);
          else
            dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], m);
        }
        if (i + j + 1 <= n)
        {
          i64 m = dp[i][j][k][0] + x[i] + l - x[n - (j + 1) + 1];
          if (m <= t[n - (j + 1) + 1])
            dp[i][j + 1][k + 1][1] = min(dp[i][j + 1][k + 1][1], m);
          else
            dp[i][j + 1][k][1] = min(dp[i][j + 1][k][1], m);
        }
        if (i + 1 + j <= n)
        {
          i64 m = dp[i][j][k][1] + x[i + 1] + l - x[n - j + 1];
          if (m <= t[i + 1])
            dp[i + 1][j][k + 1][0] = min(dp[i + 1][j][k + 1][0], m);
          else
            dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], m);
        }
        if (i + j + 1 <= n)
        {
          i64 m = dp[i][j][k][1] + x[n - j + 1] - x[n - (j + 1) + 1];
          if (m <= t[n - (j + 1) + 1])
            dp[i][j + 1][k + 1][1] = min(dp[i][j + 1][k + 1][1], m);
          else
            dp[i][j + 1][k][1] = min(dp[i][j + 1][k][1], m);
        }
      }
  i64 ans = 0;
  for (i64 i = 0; i <= n; i++)
    for (i64 j = 0; j <= n; j++)
      for (i64 k = 0; k <= n; k++)
        if (dp[i][j][k][0] < INF || dp[i][j][k][1] < INF)
          ans = max(ans, k);
  cout << ans << endl;
  return 0;
}
