// URL: https://atcoder.jp/contests/tdpc/submissions/3336552
// Date: Fri, 05 Oct 2018 22:41:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, p[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i];
  bool dp[101][10001] = {};
  dp[0][0] = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 10001; j++)
      if (dp[i][j])
      {
        dp[i + 1][j] = true;
        dp[i + 1][j + p[i]] = true;
      }
  int ans = 0;
  for (int i = 0; i < 10001; i++)
    if (dp[n][i])
      ans++;
  cout << ans << endl;

  return 0;
}
