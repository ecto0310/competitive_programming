// URL: https://atcoder.jp/contests/rcl-contest-2020-qual/submissions/10107521
// Date: Sat, 15 Feb 2020 21:24:55 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Ans
{
  bool move = false;
  i64 r, c;
  char d;
};

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<vector<i64>> a(n, vector<i64>(n));
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
    {
      cin >> a[i][j];
      a[i][j]++;
    }
  vector<vector<i64>> bord(n, vector<i64>(n, -1));
  bord[0][0] = 1;
  bord[0][n - 1] = 2;
  bord[n - 1][0] = 3;
  bord[n - 1][n - 1] = 4;
  vector<Ans> ans(m);
  for (i64 i = 0; i < m; i++)
  {
    i64 now = i % 4 + 1;
    i64 cnt = -1e9;
    Ans best;
    for (i64 j = 0; j < n; j++)
      for (i64 k = 0; k < n; k++)
      {
        if (bord[j][k] != now)
          continue;
        i64 tmp = 0;
        for (i64 l = max(0LL, j - 5); l <= j; l++)
          if (a[l][k] == now)
            tmp++;
          else if (a[l][k] < 0)
            tmp--;
        if (cnt < tmp)
        {
          best = {true, j, k, 'U'};
          cnt = tmp;
        }
        tmp = 0;
        for (i64 l = j; l < min(n, j + 6); l++)
          if (a[l][k] == now)
            tmp++;
          else if (a[l][k] < 0)
            tmp--;
        if (cnt < tmp)
        {
          best = {true, j, k, 'D'};
          cnt = tmp;
        }
        tmp = 0;
        for (i64 l = max(0LL, k - 5); l <= k; l++)
          if (a[j][l] == now)
            tmp++;
          else if (a[j][l] < 0)
            tmp--;
        if (cnt < tmp)
        {
          best = {true, j, k, 'L'};
          cnt = tmp;
        }
        tmp = 0;
        for (i64 l = k; l < min(n, k + 6); l++)
          if (a[j][l] == now)
            tmp++;
          else if (a[j][l] < 0)
            tmp--;
        if (cnt < tmp)
        {
          best = {true, j, k, 'R'};
          cnt = tmp;
        }
      }
    if (best.move && 0 < cnt)
    {
      if (best.d == 'U')
        for (i64 l = max(0LL, best.r - 5); l <= best.r; l++)
        {
          if (a[l][best.c] == now)
            a[l][best.c] = -1 * abs(a[l][best.c]);
          else
            a[l][best.c] = abs(a[l][best.c]);
          bord[l][best.c] = now;
        }
      if (best.d == 'D')
        for (i64 l = best.r; l < min(n, best.r + 6); l++)
        {
          if (a[l][best.c] == now)
            a[l][best.c] = -1 * abs(a[l][best.c]);
          else
            a[l][best.c] = abs(a[l][best.c]);
          bord[l][best.c] = now;
        }
      if (best.d == 'L')
        for (i64 l = max(0LL, best.c - 5); l <= best.c; l++)
        {
          if (a[best.r][l] == now)
            a[best.r][l] = -1 * abs(a[best.r][l]);
          else
            a[best.r][l] = abs(a[best.r][l]);
          bord[best.r][l] = now;
        }
      if (best.d == 'R')
        for (i64 l = best.c; l < min(n, best.c + 6); l++)
        {
          if (a[best.r][l] == now)
            a[best.r][l] = -1 * abs(a[best.r][l]);
          else
            a[best.r][l] = abs(a[best.r][l]);
          bord[best.r][l] = now;
        }
      ans[i] = best;
    }
  }
  for (i64 i = 0; i < m; i++)
    if (!ans[i].move)
      cout << -1 << endl;
    else
      cout << ans[i].r << " " << ans[i].c << " " << ans[i].d << "\n";
  return 0;
}
