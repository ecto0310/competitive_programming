// URL: https://atcoder.jp/contests/atc001/submissions/11442969
// Date: Thu, 02 Apr 2020 22:27:06 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 dh[] = {1, -1, 0, 0}, dw[] = {0, 0, 1, -1};

int main()
{
  i64 H, W;
  cin >> H >> W;
  vector<string> c(H);
  for (i64 i = 0; i < H; i++)
    cin >> c[i];
  queue<pair<i64, i64>> que;
  vector<vector<i64>> far(H, vector<i64>(W, 1e9));
  for (i64 i = 0; i < H; i++)
    for (i64 j = 0; j < W; j++)
      if (c[i][j] == 's')
      {
        que.push({i, j});
        far[i][j] = 0;
      }
  while (que.size())
  {
    pair<i64, i64> p = que.front();
    que.pop();
    for (i64 i = 0; i < 4; i++)
    {
      i64 ddh = p.first + dh[i], ddw = p.second + dw[i];
      if (0 <= ddh && ddh < H && 0 <= ddw && ddw < W)
      {
        if (c[ddh][ddw] == 'g')
        {
          cout << "Yes" << endl;
          return 0;
        }
        if (far[p.first][p.second] + 1 < far[ddh][ddw] && c[ddh][ddw] == '.')
        {
          far[ddh][ddw] = far[p.first][p.second] + 1;
          que.push({ddh, ddw});
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
