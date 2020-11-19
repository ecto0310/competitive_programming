// URL: https://atcoder.jp/contests/abc129/submissions/5848507
// Date: Sun, 09 Jun 2019 21:45:10 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (i64 i = 0; i < h; i++)
    cin >> s[i];
  vector<vector<i64>> cnth(h, vector<i64>(w)), cntw(h, vector<i64>(w));
  for (i64 i = 0; i < h; i++)
  {
    i64 start = 0, cnt = 0;
    for (i64 j = 0; j < w; j++)
      if (s[i][j] == '.')
        cnt++;
      else
      {
        for (i64 k = start; k < j; k++)
          cnth[i][k] = cnt;
        start = j + 1;
        cnt = 0;
      }
    for (i64 k = start; k < w; k++)
      cnth[i][k] = cnt;
  }
  for (i64 i = 0; i < w; i++)
  {
    i64 start = 0, cnt = 0;
    for (i64 j = 0; j < h; j++)
      if (s[j][i] == '.')
        cnt++;
      else
      {
        for (i64 k = start; k < j; k++)
          cntw[k][i] = cnt;
        start = j + 1;
        cnt = 0;
      }
    for (i64 k = start; k < h; k++)
      cntw[k][i] = cnt;
  }
  i64 ans = 0;
  for (i64 i = 0; i < h; i++)
    for (i64 j = 0; j < w; j++)
      if (s[i][j] == '.')
        ans = max(ans, cnth[i][j] + cntw[i][j]);
  cout << ans - 1 << endl;
  return 0;
}
