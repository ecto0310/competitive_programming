// URL: https://atcoder.jp/contests/abc148/submissions/9098781
// Date: Mon, 23 Dec 2019 15:46:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, u, v;
  cin >> n >> u >> v;
  u--;
  v--;
  vector<i64> edge[n];
  for (i64 i = 0; i < n - 1; i++)
  {
    i64 a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  queue<i64> que;
  vector<i64> ufar(n, 1e9), vfar(n, 1e9);
  ufar[u] = 0;
  que.push(u);
  while (que.size())
  {
    i64 p = que.front();
    que.pop();
    for (i64 i : edge[p])
      if (ufar[p] + 1 < ufar[i])
      {
        ufar[i] = ufar[p] + 1;
        que.push(i);
      }
    if (ufar[p] == 0)
      ufar[p] = 1e9;
  }
  vfar[v] = 0;
  que.push(v);
  while (que.size())
  {
    i64 p = que.front();
    que.pop();
    for (i64 i : edge[p])
      if (vfar[p] + 1 < vfar[i])
      {
        vfar[i] = vfar[p] + 1;
        que.push(i);
      }
  }
  i64 ans = vfar[u] / 2;
  for (i64 i = 0; i < n; i++)
  {
    if (ufar[i] < vfar[i])
      ans = max(ans, vfar[i] - 1);
  }
  cout << ans << endl;
  return 0;
}
