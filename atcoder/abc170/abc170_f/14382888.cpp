// URL: https://atcoder.jp/contests/abc170/submissions/14382888
// Date: Mon, 15 Jun 2020 15:42:21 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 H, W, K;
  cin >> H >> W >> K;
  i64 x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--;
  y1--;
  x2--;
  y2--;
  vector<string> c(H);
  for (i64 i = 0; i < H; i++)
    cin >> c[i];
  vector<vector<i64>> far(H, vector<i64>(W, 1e9));
  priority_queue<pair<i64, pair<i64, i64>>> que;
  far[x1][y1] = 0;
  que.push({0, {x1, y1}});
  while (que.size())
  {
    pair<i64, pair<i64, i64>> p = que.top();
    i64 f = -p.first, x = p.second.first, y = p.second.second;
    que.pop();
    if (far[x][y] < f)
      continue;
    for (i64 i = 1; i <= K; i++)
      if (x - i < 0 || c[x - i][y] == '@' || far[x - i][y] <= far[x][y])
        break;
      else if (f + 1 < far[x - i][y])
      {
        far[x - i][y] = f + 1;
        que.push({-far[x - i][y], {x - i, y}});
      }
    for (i64 i = 1; i <= K; i++)
      if (H <= x + i || c[x + i][y] == '@' || far[x + i][y] <= far[x][y])
        break;
      else if (f + 1 < far[x + i][y])
      {
        far[x + i][y] = f + 1;
        que.push({-far[x + i][y], {x + i, y}});
      }

    for (i64 i = 1; i <= K; i++)
      if (y - i < 0 || c[x][y - i] == '@' || far[x][y - i] <= far[x][y])
        break;
      else if (f + 1 < far[x][y - i])
      {
        far[x][y - i] = f + 1;
        que.push({-far[x][y - i], {x, y - i}});
      }
    for (i64 i = 1; i <= K; i++)
      if (W <= y + i || c[x][y + i] == '@' || far[x][y + i] <= far[x][y])
        break;
      else if (f + 1 < far[x][y + i])
      {
        far[x][y + i] = f + 1;
        que.push({-far[x][y + i], {x, y + i}});
      }
  }
  if (far[x2][y2] == 1e9)
    cout << -1 << endl;
  else
    cout << far[x2][y2] << endl;
  return 0;
}
