// URL: https://atcoder.jp/contests/joi2015ho/submissions/9909723
// Date: Wed, 05 Feb 2020 16:23:20 +0900
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
  i64 n, m, c;
  cin >> n >> m >> c;
  vector<Edge> edge[n];
  i64 dcost = 0;
  for (i64 i = 0; i < m; i++)
  {
    i64 a, b, d;
    cin >> a >> b >> d;
    a--;
    b--;
    edge[a].push_back({b, d});
    edge[b].push_back({a, d});
    dcost += d;
  }
  vector<pair<i64, i64>> far(n);
  for (i64 i = 0; i < n; i++)
    far[i] = {1e18, i};
  priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> que;
  far[0] = {0, 0};
  que.push({0, 0});
  while (que.size())
  {
    pair<i64, i64> p = que.top();
    que.pop();
    for (Edge i : edge[p.second])
      if (p.first + i.cost < far[i.to].first)
      {
        far[i.to].first = p.first + i.cost;
        que.push({far[i.to].first, i.to});
      }
  }
  sort(far.begin(), far.end());
  i64 ans = 1e18;
  vector<bool> co(n, false);
  for (i64 i = 0; i < n; i++)
  {
    i64 tmp = c * far[i].first;
    for (Edge j : edge[far[i].second])
      if (co[j.to])
        dcost -= j.cost;
    co[far[i].second] = true;
    tmp += dcost;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
