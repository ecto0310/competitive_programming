// URL: https://atcoder.jp/contests/dp/submissions/4489576
// Date: Thu, 07 Mar 2019 00:03:52 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

long long dp[101][100001];

int main()
{
  int N, W;
  cin >> N >> W;
  vector<int> w(N), v(N);
  for (int i = 0; i < N; i++)
    cin >> w[i] >> v[i];
  for (int i = 0; i < 101; i++)
    for (int j = 0; j < 100001; j++)
      dp[i][j] = 1e18;
  dp[0][0] = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < 100001; j++)
    {
      if (j - v[i] >= 0)
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - v[i]] + w[i]);
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
    }
  long long ans = 0;
  for (int i = 0; i < 100001; i++)
    if (dp[N][i] <= W)
      ans = i;
  cout << ans << endl;

  return 0;
}
