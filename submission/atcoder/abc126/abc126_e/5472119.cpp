// URL: https://atcoder.jp/contests/abc126/submissions/5472119
// Date: Sun, 19 May 2019 22:06:28 +0900
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
    i64 x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  i64 ans = 0;
  vector<i64> t(n, -1);
  for (i64 i = 0; i < n; i++)
    if (t[i] == -1)
    {
      t[i] = ans;
      queue<i64> que;
      que.push(i);
      while (que.size())
      {
        i64 p = que.front();
        que.pop();
        for (i64 j : edge[p])
          if (t[j] == -1)
          {
            t[j] = ans;
            que.push(j);
          }
      }
      ans++;
    }
  cout << ans << endl;
  return 0;
}
