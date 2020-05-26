// URL: https://atcoder.jp/contests/abc138/submissions/7325049
// Date: Tue, 03 Sep 2019 20:23:45 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, q;
  cin >> n >> q;
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
  vector<i64> ans(n);
  for (i64 i = 0; i < q; i++)
  {
    i64 p, x;
    cin >> p >> x;
    p--;
    ans[p] += x;
  }
  vector<bool> tmp(n);
  queue<i64> que;
  que.push(0);
  tmp[0] = true;
  while (que.size())
  {
    i64 p = que.front();
    que.pop();
    for (i64 i : edge[p])
      if (!tmp[i])
      {
        ans[i] += ans[p];
        que.push(i);
        tmp[i]=true;
      }
  }
  for (i64 i = 0; i < n; i++)
    cout << ans[i] << (i + 1 == n ? "\n" : " ");
  return 0;
}
