// URL: https://atcoder.jp/contests/agc039/submissions/7886838
// Date: Sun, 06 Oct 2019 19:51:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> edge[n];
  for (i64 i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    for (i64 j = 0; j < n; j++)
      if (s[j] == '1')
        edge[i].push_back(j);
  }
  bool ok = true;
  queue<i64> que;
  vector<i64> c(n, -1);
  que.push(0);
  c[0] = 0;
  while (que.size())
  {
    i64 p = que.front();
    que.pop();
    for (i64 i : edge[p])
    {
      if (c[i] == -1)
      {
        c[i] = c[p] ^ 1;
        que.push(i);
      }
      else if (c[p] != (c[i] ^ 1))
        ok = false;
    }
  }
  if (!ok)
  {
    cout << -1 << endl;
    return 0;
  }
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    while (!que.empty())
      que.pop();
    vector<i64> far(n, 1e9);
    que.push(i);
    far[i] = 0;
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
    i64 m = 0;
    for (i64 i = 0; i < n; i++)
      m = max(m, far[i]);
    ans = max(ans, m);
  }
  cout << ans + 1 << endl;
  return 0;
}
