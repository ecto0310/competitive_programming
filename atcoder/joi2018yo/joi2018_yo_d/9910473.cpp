// URL: https://atcoder.jp/contests/joi2018yo/submissions/9910473
// Date: Wed, 05 Feb 2020 17:09:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 n;
vector<i64> a, sum;
vector<vector<i64>> dp;
i64 m;

i64 calc(i64 x, i64 y)
{
  if (dp[x][y] != -1)
    return dp[x][y];
  if (x == n)
  {
    if (m <= sum[x] - sum[y] && !(x == n && y == 0))
      return dp[x][y] = sum[x] - sum[y];
    else
      return dp[x][y] = 1e9;
  }
  if (m <= sum[x] - sum[y])
    return dp[x][y] = min(max(sum[x] - sum[y], calc(x + 1, x)), calc(x + 1, y));
  return dp[x][y] = calc(x + 1, y);
}

int main()
{
  cin >> n;
  a.resize(n);
  sum.resize(n + 1);
  for (i64 i = 0; i < n; i++)
  {
    cin >> a[i];
    sum[i + 1] = sum[i] + a[i];
  }
  i64 ans = 1e9;
  for (i64 i = 0; i < n; i++)
    for (i64 j = i + 1; j <= n; j++)
    {
      if (i == 0 && j == n)
        continue;
      dp = vector<vector<i64>>(n + 1, vector<i64>(n + 1, -1));
      m = sum[j] - sum[i];
      ans = min(ans, calc(0, 0) - m);
    }
  cout << ans << endl;

  return 0;
}
