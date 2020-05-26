// URL: https://atcoder.jp/contests/abc063/submissions/3816222
// Date: Tue, 18 Dec 2018 00:05:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<vector<bool>> dp(n + 1, vector<bool>(10001));
  dp[0][0] = true;
  for (int i = 0; i < n; i++)
  {
    int s;
    cin >> s;
    for (int j = 0; j <= 10000; j++)
      if (dp[i][j])
      {
        dp[i + 1][j] = true;
        dp[i + 1][j + s] = true;
      }
  }
  int ans = 0;
  for (int i = 0; i <= 10000; i++)
    if (dp[n][i] && i % 10 != 0)
      ans = i;
  cout << ans << endl;

  return 0;
}
