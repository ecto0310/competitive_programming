// URL: https://codeforces.com/contest/1195/submission/57214848
// Date: Thu, 18 Jul 2019 00:07:42 +0900
// Language: GNU C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> h1(n), h2(n);
  for (i64 i = 0; i < n; i++)
    cin >> h1[i];
  for (i64 i = 0; i < n; i++)
    cin >> h2[i];
  vector<vector<i64>> dp(n + 1, vector<i64>(2, 0));
  for (i64 i = 0; i < n; i++)
  {
    dp[i + 1][0] = max(dp[i][0], dp[i][1] + h1[i]);
    dp[i + 1][1] = max(dp[i][1], dp[i][0] + h2[i]);
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
  return 0;
}
