// URL: https://atcoder.jp/contests/s8pc-6/submissions/4979446
// Date: Sun, 14 Apr 2019 23:29:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 h, w;
  cin >> h >> w;
  vector<vector<i64>> a(h, vector<i64>(w));
  for (i64 i = 0; i < h; i++)
    for (i64 j = 0; j < w; j++)
      cin >> a[i][j];
  vector<string> ans(h);
  for (i64 i = 0; i < h; i++)
  {
    if (i % 2 == 0)
      ans[i] = string(w, '#');
    else
    {
      ans[i] = string(w, '.');
      i64 m = 0, p = 0;
      for (i64 j = 0; j < w; j++)
        if (m < a[i][j])
        {
          m = a[i][j];
          p = j;
        }
      ans[i][p] = '#';
    }
  }
  for (i64 i = 0; i < h; i++)
    cout << ans[i] << endl;

  return 0;
}
