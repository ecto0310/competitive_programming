// URL: https://atcoder.jp/contests/abc025/submissions/9530700
// Date: Thu, 16 Jan 2020 13:19:34 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 grid[3][3];
i64 b[2][3], c[3][2];
i64 sum;

i64 calc()
{
  i64 ret = 0;
  for (i64 i = 0; i < 2; i++)
    for (i64 j = 0; j < 3; j++)
      if (grid[i][j] == grid[i + 1][j])
        ret += b[i][j];
  for (i64 i = 0; i < 3; i++)
    for (i64 j = 0; j < 2; j++)
      if (grid[i][j] == grid[i][j + 1])
        ret += c[i][j];
  return ret - (sum - ret);
}

i64 dfs(i64 t)
{
  if (t == 9)
    return calc();

  i64 ret = (t % 2 == 0 ? -1e9 : 1e9);
  for (i64 i = 0; i < 3; i++)
    for (i64 j = 0; j < 3; j++)
      if (grid[i][j] == -1)
      {
        grid[i][j] = t % 2;
        if (t % 2 == 0)
          ret = max(ret, dfs(t + 1));
        else
          ret = min(ret, dfs(t + 1));
        grid[i][j] = -1;
      }
  return ret;
}

int main()
{
  for (i64 i = 0; i < 3; i++)
    for (i64 j = 0; j < 3; j++)
      grid[i][j] = -1;

  for (i64 i = 0; i < 2; i++)
    for (i64 j = 0; j < 3; j++)
    {
      cin >> b[i][j];
      sum += b[i][j];
    }
  for (i64 i = 0; i < 3; i++)
    for (i64 j = 0; j < 2; j++)
    {
      cin >> c[i][j];
      sum += c[i][j];
    }
  i64 ans = (dfs(0) + sum) / 2;
  cout << ans << endl
       << sum - ans << endl;
  return 0;
}
