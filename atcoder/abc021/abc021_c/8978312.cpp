// URL: https://atcoder.jp/contests/abc021/submissions/8978312
// Date: Mon, 16 Dec 2019 17:25:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

int main()
{
  i64 n, a, b, m;
  cin >> n >> a >> b >> m;
  a--;
  b--;
  vector<i64> edge[n];
  for (i64 i = 0; i < m; i++)
  {
    i64 x, y;
    cin >> x >> y;
    x--;
    y--;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  vector<i64> far(n, 1e9);
  queue<i64> que;
  far[a] = 0;
  que.push(a);
  while (que.size())
  {
    i64 p = que.front();
    que.pop();
    for (i64 i : edge[p])
      if (far[p] + 1 < far[i])
      {
        far[i] = far[p] + 1;
        que.push(i);
      }
  }
  vector<i64> ans(n, 0);
  vector<bool> vis(n, false);
  ans[b] = 1;
  vis[b] = true;
  que.push(b);
  while (que.size())
  {
    i64 p = que.front();
    que.pop();
    for (i64 i : edge[p])
      if (far[i] < far[p])
      {
        (ans[i] += ans[p]) %= MOD;
        if (!vis[i])
          que.push(i);
        vis[i] = true;
      }
  }
  cout << ans[a] << endl;
  return 0;
}
