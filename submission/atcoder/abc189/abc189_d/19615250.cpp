// URL: https://atcoder.jp/contests/abc189/submissions/19615250
// Date: Sat, 23 Jan 2021 21:29:43 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<string> S(N);
  for (i64 i = 0; i < N; i++)
    cin >> S[i];
  vector<vector<i64>> dp(N + 1, vector<i64>(2));
  dp[0][0] = 1;
  dp[0][1] = 1;
  for (i64 i = 0; i < N; i++)
  {
    if (S[i] == "AND")
    {
      dp[i + 1][0] += dp[i][0] * 2 + dp[i][1];
      dp[i + 1][1] += dp[i][1];
    }
    else
    {
      dp[i + 1][0] += dp[i][0];
      dp[i + 1][1] += dp[i][1] * 2 + dp[i][0];
    }
  }
  cout << dp[N][1] << endl;
  return 0;
}
