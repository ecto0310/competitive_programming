// URL: https://atcoder.jp/contests/joi2010yo/submissions/6865441
// Date: Mon, 12 Aug 2019 17:35:25 +0900
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
  vector<i64> far(n, 1e9);
  queue<i64> que;
  far[0] = 0;
  que.push(0);
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
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    if (far[i] < 3)
      ans++;
  cout << ans - 1 << endl;
  return 0;
}
