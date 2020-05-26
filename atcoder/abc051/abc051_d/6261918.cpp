// URL: https://atcoder.jp/contests/abc051/submissions/6261918
// Date: Sun, 07 Jul 2019 16:10:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

struct Edge
{
  i64 to, cost;
};

int main()
{
  i64 n, m;
  cin >> n >> m;
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
  set<pair<i64, i64>> ans;
  for (i64 i = 0; i < n; i++)
  {
    vector<i64> cost(n, 1e18), me[n];
    priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> que;
    cost[i] = 0;
    que.push({0, i});
    while (que.size())
    {
      pair<i64, i64> p = que.top();
      que.pop();
      for (Edge j : edge[p.second])
        if (cost[p.second] + j.cost < cost[j.to])
        {
          cost[j.to] = cost[p.second] + j.cost;
          que.push({cost[j.to], j.to});

          me[j.to].clear();
          me[j.to].push_back(p.second);
        }
        else if (cost[p.second] + j.cost == cost[j.to])
          me[j.to].push_back(p.second);
    }

    for (i64 i = 0; i < n; i++)
      for (i64 j : me[i])
        ans.insert({min(i, j), max(i, j)});
  }
  cout << m - ans.size() << endl;
  return 0;
}
