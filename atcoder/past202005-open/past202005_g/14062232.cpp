// URL: https://atcoder.jp/contests/past202005-open/submissions/14062232
// Date: Sat, 06 Jun 2020 18:06:25 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const i64 dx[6] = {1, 0, -1, 1, -1, 0}, dy[6] = {1, 1, 1, 0, 0, -1};
const i64 BASE = 205;

int main()
{
  i64 N, X, Y;
  cin >> N >> X >> Y;
  vector<string> m(BASE * 2, string(BASE * 2, '.'));
  for (i64 i = 0; i < N; i++)
  {
    i64 x, y;
    cin >> x >> y;
    m[x + BASE][y + BASE] = '#';
  }
  vector<vector<i64>> ans(BASE * 2, vector<i64>(BASE * 2, 1e9));
  queue<pair<i64, i64>> que;
  ans[BASE][BASE] = 0;
  que.push({BASE, BASE});
  while (que.size())
  {
    pair<i64, i64> p = que.front();
    que.pop();
    for (i64 i = 0; i < 6; i++)
    {
      i64 ddx = p.first + dx[i], ddy = p.second + dy[i];
      if (ddx < 0 || BASE * 2 <= ddx || ddy < 0 || BASE * 2 <= ddy)
        continue;
      if (m[ddx][ddy] == '.' && ans[p.first][p.second] + 1 < ans[ddx][ddy])
      {
        ans[ddx][ddy] = ans[p.first][p.second] + 1;
        que.push({ddx, ddy});
      }
    }
  }
  if (ans[BASE + X][BASE + Y] == 1e9)
    cout << -1 << endl;
  else
    cout << ans[BASE + X][BASE + Y] << endl;
  return 0;
}
