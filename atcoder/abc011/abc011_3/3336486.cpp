// URL: https://atcoder.jp/contests/abc011/submissions/3336486
// Date: Fri, 05 Oct 2018 22:26:34 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, ng[3];
  cin >> n >> ng[0] >> ng[1] >> ng[2];
  vector<int> dp(305, 200);
  dp[0] = 0;
  for (int i = 0; i < 3; i++)
    dp[ng[i]] = -1;
  for (int i = 0; i < n; i++)
    for (int j = 1; j < 4; j++)
      if (dp[i + j] != -1 && dp[i] != -1)
        dp[i + j] = min(dp[i + j], dp[i] + 1);
  if (0<=dp[n]&&dp[n] <= 100)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
