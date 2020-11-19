// URL: https://atcoder.jp/contests/abc070/submissions/6215427
// Date: Tue, 02 Jul 2019 17:56:44 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

struct Edge
{
  i64 cost, to;
};

int main()
{
  i64 n;
  cin >> n;
  vector<Edge> edge[n];
  for (i64 i = 0; i < n - 1; i++)
  {
    i64 a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edge[a].push_back({c, b});
    edge[b].push_back({c, a});
  }
  i64 q, k;
  cin >> q >> k;
  k--;
  vector<i64> cost(n, 1e18);
  priority_queue<pair<i64, i64>> que;
  cost[k] = 0;
  que.push({0, k});
  while (que.size())
  {
    pair<i64, i64> p = que.top();
    que.pop();
    for (Edge i : edge[p.second])
      if (cost[p.second] + i.cost < cost[i.to])
      {
        cost[i.to] = cost[p.second] + i.cost;
        que.push({cost[i.to], i.to});
      }
  }
  for (i64 i = 0; i < q; i++)
  {
    i64 x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << cost[x] + cost[y] << endl;
  }
  return 0;
}
