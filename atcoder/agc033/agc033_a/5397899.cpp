// URL: https://atcoder.jp/contests/agc033/submissions/5397899
// Date: Tue, 14 May 2019 18:22:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

i64 dh[4] = {1, -1, 0, 0}, dw[4] = {0, 0, 1, -1};

int main()
{
  i64 h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (i64 i = 0; i < h; i++)
    cin >> a[i];
  queue<pair<pair<i64, i64>, i64>> que;
  for (i64 i = 0; i < h; i++)
    for (i64 j = 0; j < w; j++)
      if (a[i][j] == '#')
        que.push({{i, j}, 0});
  i64 ans = 0;
  while (que.size())
  {
    pair<pair<i64, i64>, i64> p = que.front();
    que.pop();
    ans = max(ans, p.second);
    for (i64 i = 0; i < 4; i++)
    {
      i64 hh = p.first.first + dh[i], ww = p.first.second + dw[i];
      if (0 <= hh && hh < h && 0 <= ww && ww < w && a[hh][ww] == '.')
      {
        a[hh][ww] = '#';
        que.push({{hh, ww}, p.second + 1});
      }
    }
  }
  cout << ans << endl;
  return 0;
}
