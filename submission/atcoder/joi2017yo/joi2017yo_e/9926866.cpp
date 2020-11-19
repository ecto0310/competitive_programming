// URL: https://atcoder.jp/contests/joi2017yo/submissions/9926866
// Date: Thu, 06 Feb 2020 20:41:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 dh[] = {-1, 1, 0, 0}, dw[] = {0, 0, -1, 1};

int main()
{
  i64 h, w;
  cin >> h >> w;
  vector<vector<i64>> grid(h, vector<i64>(w));
  vector<pair<i64, pair<i64, i64>>> s(h * w);
  for (i64 i = 0; i < h; i++)
    for (i64 j = 0; j < w; j++)
    {
      cin >> grid[i][j];
      s[i * w + j] = {grid[i][j], {i, j}};
    }
  sort(s.begin(), s.end());
  i64 ans = 0;
  vector<vector<i64>> one(h, vector<i64>(w, -1));
  for (i64 i = 0; i < h * w; i++)
  {
    i64 tmp = -1;
    for (i64 j = 0; j < 4; j++)
    {
      i64 ddh = s[i].second.first + dh[j], ddw = s[i].second.second + dw[j];
      if (0 <= ddh && ddh < h && 0 <= ddw && ddw < w && grid[ddh][ddw] < grid[s[i].second.first][s[i].second.second])
      {
        if (tmp == -1)
          tmp = one[ddh][ddw];
        else if (tmp != one[ddh][ddw])
          tmp = -2;
      }
    }
    if (tmp == -1)
      one[s[i].second.first][s[i].second.second] = i;
    else
      one[s[i].second.first][s[i].second.second] = tmp;
    if (tmp == -2)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
