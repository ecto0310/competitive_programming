// URL: https://atcoder.jp/contests/abc054/submissions/6607904
// Date: Mon, 29 Jul 2019 22:35:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const i64 INF = 1e18;

int main()
{
  i64 n, ma, mb;
  cin >> n >> ma >> mb;
  vector<i64> a(n), b(n), c(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i] >> b[i] >> c[i];
  vector<vector<vector<i64>>> dp(n + 1, vector<vector<i64>>(n * 10 + 1, vector<i64>(n * 10 + 1, INF)));
  dp[0][0][0] = 0;
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j <= n * 10; j++)
      for (i64 k = 0; k <= n * 10; k++)
        if (dp[i][j][k] != INF)
        {
          dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
          dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
        }
  i64 ans = INF;
  for (i64 i = 1; i <= n * 10; i++)
    for (i64 j = 1; j <= n * 10; j++)
      if (i * mb == j * ma)
        ans = min(ans, dp[n][i][j]);
  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}
