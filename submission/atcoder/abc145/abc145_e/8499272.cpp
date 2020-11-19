// URL: https://atcoder.jp/contests/abc145/submissions/8499272
// Date: Sun, 17 Nov 2019 15:08:15 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 dp[3005][6000];

int main()
{
  i64 n, t;
  cin >> n >> t;
  vector<pair<i64, i64>> d(n);
  for (i64 i = 0; i < n; i++)
    cin >> d[i].first >> d[i].second;
  sort(d.begin(), d.end());
  for (i64 i = 0; i < n; i++)
  {
    for (i64 j = 0; j < t; j++)
      dp[i + 1][j + d[i].first] = max(dp[i + 1][j + d[i].first], dp[i][j] + d[i].second);
    for (i64 j = 0; j < t + 3000; j++)
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
  }
  i64 ans = 0;
  for (i64 i = 0; i < t + 3000; i++)
    ans = max(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
