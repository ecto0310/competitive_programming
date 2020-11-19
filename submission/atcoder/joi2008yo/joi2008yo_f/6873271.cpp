// URL: https://atcoder.jp/contests/joi2008yo/submissions/6873271
// Date: Tue, 13 Aug 2019 00:54:39 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const i64 INF = 1e9 + 7;

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<pair<i64, i64>> edge[n];
  for (i64 i = 0; i < k; i++)
  {
    i64 t;
    cin >> t;
    if (t == 0)
    {
      i64 a, b;
      cin >> a >> b;
      a--;
      b--;
      vector<i64> cost(n, INF);
      priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> que;
      cost[a] = 0;
      que.push({0, a});
      while (que.size())
      {
        pair<i64, i64> p = que.top();
        que.pop();
        for (pair<i64, i64> j : edge[p.second])
          if (cost[p.second] + j.second < cost[j.first])
          {
            cost[j.first] = cost[p.second] + j.second;
            que.push({cost[j.first], j.first});
          }
      }
      if (cost[b] == INF)
        cout << -1 << endl;
      else
        cout << cost[b] << endl;
    }
    else
    {
      i64 c, d, e;
      cin >> c >> d >> e;
      c--;
      d--;
      edge[c].push_back({d, e});
      edge[d].push_back({c, e});
    }
  }
  return 0;
}
