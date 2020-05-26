// URL: https://atcoder.jp/contests/soundhound2018-summer-qual/submissions/4129568
// Date: Thu, 31 Jan 2019 00:24:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

struct Edge
{
  long long to, cost;
};

void dijkstra(vector<Edge> edge[], int n, int s, vector<long long> &far)
{
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  far[s] = 0;
  pq.push({0, s});
  while (pq.size())
  {
    pair<long long, int> p = pq.top();
    pq.pop();
    cerr << " " << p.second << " " << p.first << endl;
    for (Edge t : edge[p.second])
      if (far[p.second] + t.cost < far[t.to])
      {
        far[t.to] = far[p.second] + t.cost;
        pq.push({far[t.to], t.to});
      }
  }
}

int main()
{
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<Edge> edgeY[n], edgeS[n];
  for (int i = 0; i < m; i++)
  {
    long long u, v, a, b;
    cin >> u >> v >> a >> b;
    u--;
    v--;
    edgeY[u].push_back({v, a});
    edgeY[v].push_back({u, a});
    edgeS[u].push_back({v, b});
    edgeS[v].push_back({u, b});
  }
  vector<long long> costY(n, 1e18), costS(n, 1e18);
  dijkstra(edgeY, n, s - 1, costY);
  dijkstra(edgeS, n, t - 1, costS);
  vector<pair<long long, int>> cost(n);
  for (int i = 0; i < n; i++)
    cost[i] = {costY[i] + costS[i], i + 1};
  sort(cost.begin(), cost.end());
  int index = 0;
  for (int i = 0; i < n; i++)
  {
    while (cost[index].second <= i)
      index++;
    cout << (long long)1e15 - cost[index].first << endl;
  }

  return 0;
}
