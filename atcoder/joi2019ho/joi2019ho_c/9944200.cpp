// URL: https://atcoder.jp/contests/joi2019ho/submissions/9944200
// Date: Sat, 08 Feb 2020 01:13:43 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MAXN = 400;

i64 dp[MAXN + 1][MAXN + 1][MAXN + 1][3];
i64 pre[3][MAXN], pos[3][MAXN];

int main()
{
  i64 n;
  string s;
  cin >> n >> s;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    if (s[i] == 'R')
      a[i] = 0;
    else if (s[i] == 'G')
      a[i] = 1;
    else
      a[i] = 2;
  i64 cnt[3] = {0, 0, 0};
  for (i64 i = 0; i < n; i++)
  {
    pos[a[i]][cnt[a[i]]] = i;
    cnt[a[i]]++;
    for (i64 j = 0; j < 3; j++)
      pre[j][i] = cnt[j];
  }
  for (i64 i = 0; i <= cnt[0]; i++)
    for (i64 j = 0; j <= cnt[1]; j++)
      for (i64 k = 0; k <= cnt[2]; k++)
        for (i64 l = 0; l < 3; l++)
          dp[i][j][k][l] = 1e9;
  dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][0][2] = 0;
  for (i64 i = 0; i <= cnt[0]; i++)
    for (i64 j = 0; j <= cnt[1]; j++)
      for (i64 k = 0; k <= cnt[2]; k++)
        for (i64 l = 0; l < 3; l++)
        {
          if (l != 0 && i < cnt[0])
          {
            i64 p = pos[0][i];
            dp[i + 1][j][k][0] = min(dp[i + 1][j][k][0], dp[i][j][k][l] + max(0LL, pre[1][p] - j) + max(0LL, pre[2][p] - k));
          }
          if (l != 1 && j < cnt[1])
          {
            i64 p = pos[1][j];
            dp[i][j + 1][k][1] = min(dp[i][j + 1][k][1], dp[i][j][k][l] + max(0LL, pre[0][p] - i) + max(0LL, pre[2][p] - k));
          }
          if (l != 2 && k < cnt[2])
          {
            i64 p = pos[2][k];
            dp[i][j][k + 1][2] = min(dp[i][j][k + 1][2], dp[i][j][k][l] + max(0LL, pre[0][p] - i) + max(0LL, pre[1][p] - j));
          }
        }
  i64 ans = min({dp[cnt[0]][cnt[1]][cnt[2]][0], dp[cnt[0]][cnt[1]][cnt[2]][1], dp[cnt[0]][cnt[1]][cnt[2]][2]});
  if (ans == 1e9)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
