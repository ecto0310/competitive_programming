// URL: https://atcoder.jp/contests/s8pc-6/submissions/4973037
// Date: Sun, 14 Apr 2019 20:07:14 +0900
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
  for (i64 i = 0; i < h; i++)
  {
    for (i64 j = 0; j < w; j++)
      if (i % 2 == 0)
        cout << "#";
      else if (j == 0)
        cout << "#";
      else
        cout << ".";
    cout << "\n";
  }

  return 0;
}
