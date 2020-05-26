// URL: https://atcoder.jp/contests/abc126/submissions/5470531
// Date: Sun, 19 May 2019 21:58:58 +0900
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
  i64 n;
  cin >> n;
  vector<Edge> edge[n];
  for (i64 i = 0; i < n - 1; i++)
  {
    i64 v1, v2, w;
    cin >> v1 >> v2 >> w;
    v1--;
    v2--;
    edge[v1].push_back({v2, w});
    edge[v2].push_back({v1, w});
  }
  vector<i64> ans(n, -1);
  queue<pair<i64, i64>> que;
  que.push({0, 0});
  ans[0] = 0;
  while (que.size())
  {
    pair<i64, i64> p = que.front();
    que.pop();
    for (Edge j : edge[p.first])
      if (ans[j.to] == -1)
      {
        if ((p.second + j.cost) % 2 == 0)
        {
          ans[j.to] = 0;
          que.push({j.to, p.second + j.cost});
        }
        else
        {
          ans[j.to] = 1;
          que.push({j.to, p.second + j.cost});
        }
      }
  }
  for (i64 i = 0; i < n; i++)
    cout << ans[i] << endl;
  return 0;
}
