// URL: https://atcoder.jp/contests/abc151/submissions/9457052
// Date: Sun, 12 Jan 2020 21:25:23 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main()
{
  i64 h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (i64 i = 0; i < h; i++)
    cin >> s[i];
  i64 ans = 0;
  for (i64 i = 0; i < h; i++)
    for (i64 j = 0; j < w; j++)
      if (s[i][j] == '.')
      {
        vector<vector<i64>> far(h, vector<i64>(w, 1e9));
        queue<pair<i64, i64>> que;
        far[i][j] = 0;
        que.push({i, j});
        while (que.size())
        {
          pair<i64, i64> p = que.front();
          que.pop();
          for (i64 k = 0; k < 4; k++)
          {
            i64 x = p.first + dx[k], y = p.second + dy[k];
            if (0 <= x && x < h && 0 <= y && y < w && far[p.first][p.second] + 1 < far[x][y] && s[x][y] == '.')
            {
              far[x][y] = far[p.first][p.second] + 1;
              que.push({x, y});
            }
          }
        }
        i64 t = 0;
        for (i64 k = 0; k < h; k++)
          for (i64 l = 0; l < w; l++)
            if (s[k][l] == '.')
              t = max(t, far[k][l]);
        ans = max(ans, t);
      }
  cout << ans << endl;
  return 0;
}
