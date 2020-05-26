// URL: https://atcoder.jp/contests/joi2010yo/submissions/7426787
// Date: Mon, 09 Sep 2019 00:45:05 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const i64 MOD = 100000;

i64 dp[101][101][2][2];

int main()
{
  i64 w, h;
  cin >> w >> h;
  dp[1][1][0][0] = 1;
  dp[1][1][1][1] = 1;
  for (i64 i = 1; i <= h; i++)
    for (i64 j = 1; j <= w; j++)
      if (!(w == 1 && h == 1))
      {
        (dp[i][j][0][0] += dp[i - 1][j][0][0] + dp[i - 1][j][0][1]) %= MOD;
        (dp[i][j][0][1] += dp[i][j - 1][1][1]) %= MOD;
        (dp[i][j][1][0] += dp[i - 1][j][0][0]) %= MOD;
        (dp[i][j][1][1] += dp[i][j - 1][1][1] + dp[i][j - 1][1][0]) %= MOD;
      }
  cout << (dp[h][w][0][0] + dp[h][w][1][1]) % MOD << endl;
  return 0;
}
