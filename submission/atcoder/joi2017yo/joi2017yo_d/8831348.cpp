// URL: https://atcoder.jp/contests/joi2017yo/submissions/8831348
// Date: Sun, 08 Dec 2019 10:37:31 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> a(n), cnt(m);
  vector<vector<i64>> sum(m, vector<i64>(n + 1));
  for (i64 i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
    sum[a[i]][i+1] = 1;
    cnt[a[i]]++;
  }
  for (i64 i = 0; i < m; i++)
    for (i64 j = 0; j < n; j++)
      sum[i][j + 1] += sum[i][j];
  vector<i64> dp(1 << m, 1e9);
  dp[0] = 0;
  for (i64 i = 0; i < (1 << m); i++)
  {
    i64 p = 0;
    for (i64 j = 0; j < m; j++)
      if (i & (1 << j))
        p += sum[j][n];
    for (i64 j = 0; j < m; j++)
      if (!(i & (1 << j)))
        dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + cnt[j] - sum[j][p + cnt[j]] + sum[j][p]);
  }
  cout << dp[(1 << m) - 1] << endl;
  return 0;
}
