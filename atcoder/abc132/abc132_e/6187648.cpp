// URL: https://atcoder.jp/contests/abc132/submissions/6187648
// Date: Sat, 29 Jun 2019 23:58:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> edge[n * 3];
  for (i64 i = 0; i < m; i++)
  {
    i64 u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].push_back(n + v);
    edge[n + u].push_back(n * 2 + v);
    edge[n * 2 + u].push_back(v);
  }
  i64 s, t;
  cin >> s >> t;
  s--;
  t--;
  vector<i64> cost(n * 3, 1e18);
  queue<i64> que;
  cost[s] = 0;
  que.push(s);
  while (que.size())
  {
    i64 p = que.front();
    que.pop();
    for (i64 i : edge[p])
      if (cost[p] + 1 < cost[i])
      {
        cost[i] = cost[p] + 1;
        que.push(i);
      }
  }
  if (cost[t] == 1e18)
    cout << -1 << endl;
  else
    cout << cost[t] / 3 << endl;
  return 0;
}
