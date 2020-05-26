// URL: https://atcoder.jp/contests/abc146/submissions/8646885
// Date: Mon, 25 Nov 2019 17:25:24 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> edge[n];
  vector<pair<i64, i64>> p(n - 1);
  for (i64 i = 0; i < n - 1; i++)
  {
    i64 a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
    p[i] = {a, b};
  }
  map<pair<i64, i64>, i64> ans;
  queue<pair<i64, i64>> que;
  que.push({0, -1});
  while (que.size())
  {
    pair<i64, i64> p = que.front();
    que.pop();
    i64 cnt = 1;
    for (i64 i : edge[p.first])
      if (ans[{p.first, i}] == 0)
      {
        if (cnt == p.second)
          cnt++;
        ans[{p.first, i}] = cnt;
        ans[{i, p.first}] = cnt;
        cnt++;
        que.push({i, ans[{p.first, i}]});
      }
  }
  i64 m = 0;
  for (i64 i = 0; i < n - 1; i++)
    m = max(m, ans[p[i]]);
  cout << m << endl;
  for (i64 i = 0; i < n - 1; i++)
    cout << ans[p[i]] << endl;
  return 0;
}
