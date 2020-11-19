// URL: https://atcoder.jp/contests/abc135/submissions/6579692
// Date: Sat, 27 Jul 2019 22:20:57 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

int main()
{
  string s;
  cin >> s;
  i64 size = s.size();
  vector<vector<i64>> dp(size + 1, vector<i64>(13));
  bool plus = (size + 2) / 3 % 2;
  dp[0][0] = 1;
  i64 p[3] = {1, 10, 100};
  for (i64 i = 0; i < size; i++)
  {
    if (s[i] == '?')
    {
      for (i64 j = 0; j < 13; j++)
        for (i64 now = 0; now <= 9; now++)
        {
          i64 tmp = (j + ((plus ? 1 : -1) * now * p[(size - i - 1 + 3) % 3]) + 1300) % 13;
          dp[i + 1][tmp] += dp[i][j];
          dp[i + 1][tmp] %= MOD;
        }
    }
    else
    {
      i64 now = s[i] - '0';
      for (i64 j = 0; j < 13; j++)
      {
        i64 tmp = (j + ((plus ? 1 : -1) * now * p[(size - i - 1 + 3) % 3]) + 1300) % 13;
        dp[i + 1][tmp] += dp[i][j];
        dp[i + 1][tmp] %= MOD;
      }
    }
    if ((size - i - 1) % 3 == 0)
      plus = !plus;
  }
  cout << dp[size][5] % MOD << endl;
  return 0;
}
