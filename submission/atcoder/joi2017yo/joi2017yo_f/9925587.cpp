// URL: https://atcoder.jp/contests/joi2017yo/submissions/9925587
// Date: Thu, 06 Feb 2020 18:49:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Edge
{
  i64 to, cost;
};

int main()
{
  i64 n, m, x;
  cin >> n >> m >> x;
  vector<i64> t(n);
  for (i64 i = 0; i < n; i++)
    cin >> t[i];
  vector<Edge> edge[n];
  for (i64 i = 0; i < m; i++)
  {
    i64 a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edge[a].push_back({b, c});
    edge[b].push_back({a, c});
  }
  vector<vector<vector<i64>>> far(n, vector<vector<i64>>(3, vector<i64>(x + 1, 1e18)));
  vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(3, vector<bool>(x + 1, false)));
  priority_queue<pair<pair<i64, i64>, pair<i64, i64>>,vector<pair<pair<i64, i64>, pair<i64, i64>>>,greater<pair<pair<i64, i64>, pair<i64, i64>>>> que;
  far[0][0][0] = 0;
  que.push({{0, 0}, {0, 0}});
  while (que.size())
  {
    pair<pair<i64, i64>, pair<i64, i64>> p = que.top();
    que.pop();
    if (vis[p.first.second][p.second.first][p.second.second])
      continue;
    vis[p.first.second][p.second.first][p.second.second] = true;
    for (Edge i : edge[p.first.second])
    {
      if (t[i.to] == 0)
      {
        if (p.second.first == 2 && p.second.second + i.cost < x)
          continue;
        if (far[p.first.second][p.second.first][p.second.second] + i.cost < far[i.to][0][0])
        {
          far[i.to][0][0] = far[p.first.second][p.second.first][p.second.second] + i.cost;
          que.push({{far[i.to][0][0], i.to}, {0, 0}});
        }
      }
      else if (t[i.to] == 1)
      {

        if (far[p.first.second][p.second.first][p.second.second] + i.cost < far[i.to][p.second.first][min(x, p.second.second + i.cost)])
        {
          far[i.to][p.second.first][min(x, p.second.second + i.cost)] = far[p.first.second][p.second.first][p.second.second] + i.cost;
          que.push({{far[i.to][p.second.first][min(x, p.second.second + i.cost)], i.to}, {p.second.first, min(x, p.second.second + i.cost)}});
        }
      }
      else
      {
        if (p.second.first == 0 && p.second.second + i.cost < x)
          continue;
        if (far[p.first.second][p.second.first][p.second.second] + i.cost < far[i.to][2][0])
        {
          far[i.to][2][0] = far[p.first.second][p.second.first][p.second.second] + i.cost;
          que.push({{far[i.to][2][0], i.to}, {2, 0}});
        }
      }
    }
  }
  i64 ans = 1e18;
  for (i64 i = 0; i < 3; i++)
    for (i64 j = 0; j < x + 1; j++)
      ans = min(ans, far[n - 1][i][j]);
  cout << ans << endl;
  return 0;
}
