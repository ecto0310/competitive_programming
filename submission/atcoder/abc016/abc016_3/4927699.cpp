// URL: https://atcoder.jp/contests/abc016/submissions/4927699
// Date: Fri, 12 Apr 2019 20:50:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> edge[n];
  for (i64 i = 0; i < m; i++)
  {
    i64 a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  for (i64 i = 0; i < n; i++)
  {
    vector<i64> cost(n, 1e9);
    priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> pque;
    pque.push({0, i});
    cost[i] = 0;
    while (pque.size())
    {
      pair<i64, i64> p = pque.top();
      pque.pop();
      for (i64 j : edge[p.second])
        if (cost[p.second] + 1 < cost[j])
        {
          cost[j] = cost[p.second] + 1;
          pque.push({cost[j], j});
        }
    }
    i64 ans = 0;
    for (i64 i = 0; i < n; i++)
      if (cost[i] == 2)
        ans++;
    cout << ans << endl;
  }
  return 0;
}
