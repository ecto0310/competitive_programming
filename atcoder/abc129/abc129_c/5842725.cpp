// URL: https://atcoder.jp/contests/abc129/submissions/5842725
// Date: Sun, 09 Jun 2019 21:16:15 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> dp(n + 1, 0);
  for (i64 i = 0; i < m; i++)
  {
    i64 a;
    cin >> a;
    dp[a] = -1;
  }
  dp[0] = 1;
  for (i64 i = 0; i < n; i++)
    if (dp[i] != -1)
      for (i64 j = 1; j <= 2; j++)
      {
        if (n < i + j)
          break;
        if (dp[i + j] == -1)
          continue;
        (dp[i + j] += dp[i]) %= MOD;
      }
  cout << dp[n] % MOD << endl;
  return 0;
}
