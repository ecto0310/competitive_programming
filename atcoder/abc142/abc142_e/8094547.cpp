// URL: https://atcoder.jp/contests/abc142/submissions/8094547
// Date: Wed, 23 Oct 2019 16:34:43 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<pair<i64, i64>> k(m);
  for (i64 i = 0; i < m; i++)
  {
    i64 b;
    cin >> k[i].first >> b;
    for (i64 j = 0; j < b; j++)
    {
      i64 d;
      cin >> d;
      k[i].second |= (1LL << (d - 1));
    }
  }
  vector<vector<i64>> dp(m + 1, vector<i64>(1LL << n, 1e9));
  dp[0][0] = 0;
  for (i64 i = 0; i < m; i++)
    for (i64 j = 0; j < (1LL << n); j++)
    {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j | k[i].second] = min(dp[i + 1][j | k[i].second], dp[i][j] + k[i].first);
    }
  if (dp[m][(1LL << n) - 1] == 1e9)
    cout << -1 << endl;
  else
    cout << dp[m][(1LL << n) - 1] << endl;
  return 0;
}
