// URL: https://atcoder.jp/contests/ddcc2020-qual/submissions/8579257
// Date: Sat, 23 Nov 2019 21:37:39 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  for (i64 i = 0; i < h; i++)
    cin >> s[i];
  vector<vector<i64>> ans(h, vector<i64>(w, -1));
  i64 cnt = 0;
  i64 b = -1;
  for (i64 i = 0; i < h; i++)
    for (i64 j = 0; j < w; j++)
      if (b == -1 && s[i][j] == '#')
        b = i;
  for (i64 i = 0; i < w; i++)
  {
    if (s[b][i] == '#')
      cnt++;
    ans[b][i] = (cnt == 0 ? cnt + 1 : cnt);
  }
  for (i64 i = b + 1; i < h; i++)
  {
    bool ok = true;
    for (i64 j = 0; j < w; j++)
      if (s[i][j] == '#')
        ok = false;
    if (ok)
    {
      for (i64 j = 0; j < w; j++)
        ans[i][j] = ans[i - 1][j];
    }
    else
    {
      i64 t = 0;
      for (i64 j = 0; j < w; j++)
      {
        if (s[i][j] == '#')
          t++;
        ans[i][j] = (t == 0 ? cnt + 1 : cnt + t);
      }
      cnt += t;
    }
  }
  for (i64 i = 0; i < b; i++)
    for (i64 j = 0; j < w; j++)
      cout << ans[b][j] << (j + 1 == w ? "\n" : " ");
  for (i64 i = b; i < h; i++)
    for (i64 j = 0; j < w; j++)
      cout << ans[i][j] << (j + 1 == w ? "\n" : " ");
  return 0;
}
