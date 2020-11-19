// URL: https://atcoder.jp/contests/m-solutions2019/submissions/5768887
// Date: Sun, 02 Jun 2019 23:55:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{

  i64 n;
  cin >> n;
  vector<i64> edge[n], c(n);
  for (i64 i = 0; i < n - 1; i++)
  {
    i64 a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  for (i64 i = 0; i < n; i++)
    cin >> c[i];
  sort(c.begin(), c.end(), greater<i64>());
  i64 sum = 0, now = 1;
  vector<i64> ans(n, -1);
  queue<i64> que;
  que.push(0);
  ans[0] = c[0];
  while (que.size())
  {
    i64 p = que.front();
    que.pop();
    for (i64 i : edge[p])
      if (ans[i] == -1)
      {
        ans[i] = c[now];
        sum += c[now];
        now++;
        que.push(i);
      }
  }
  cout << sum << endl;
  for (i64 i = 0; i < n; i++)
    cout << ans[i] << (i + 1 == n ? "\n" : " ");
  return 0;
}
