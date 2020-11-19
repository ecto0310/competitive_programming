// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3855547
// Date: Mon, 09 Sep 2019 17:55:05 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

struct Edge
{
  i64 to, cost;
};

i64 n;
vector<vector<Edge>> edge;
vector<vector<i64>> d;
vector<bool> ok;

void dijkstra(int s)
{
  d[s][s] = 0;
  priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> que;
  que.push({0, s});
  while (que.size())
  {
    pair<i64, i64> p = que.top();
    que.pop();
    for (Edge i : edge[p.second])
      if (d[s][p.second] + i.cost < d[s][i.to])
      {
        d[s][i.to] = d[s][p.second] + i.cost;
        que.push({d[s][i.to], i.to});
      }
  }
  return;
}

void check(i64 s, i64 md)
{
  queue<i64> que;
  vector<bool> vis(n);
  for (i64 i = 0; i < n; i++)
    if (d[s][i] == md)
    {
      que.push(i);
      vis[i] = true;
    }
  while (que.size())
  {
    i64 p = que.front();
    que.pop();
    ok[p] = false;
    for (Edge i : edge[p])
      if (!vis[i.to] && d[s][i.to] == d[s][p] - i.cost)
      {
        vis[i.to] = true;
        que.push(i.to);
      }
  }
}

int main()
{
  i64 r;
  cin >> n >> r;
  edge.resize(n);
  for (i64 i = 0; i < r; i++)
  {
    i64 s, t, d;
    cin >> s >> t >> d;
    s--;
    t--;
    edge[s].push_back({t, d});
    edge[t].push_back({s, d});
  }
  d.resize(n, vector<i64>(n, 1e9));
  for (i64 i = 0; i < n; i++)
    dijkstra(i);
  i64 md = 0;
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      md = max(md, d[i][j]);
  ok.resize(n, true);
  for (i64 i = 0; i < n; i++)
    check(i, md);
  vector<i64> ans;
  for (i64 i = 0; i < n; i++)
    if (ok[i])
      ans.push_back(i + 1);
  cout << ans.size() << endl;
  for (i64 i : ans)
    cout << i << endl;
  return 0;
}
