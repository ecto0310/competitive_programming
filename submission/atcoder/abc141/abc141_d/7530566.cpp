// URL: https://atcoder.jp/contests/abc141/submissions/7530566
// Date: Sun, 15 Sep 2019 21:31:08 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  priority_queue<i64> que;
  for (i64 i = 0; i < n; i++)
  {
    i64 a;
    cin >> a;
    que.push(a);
  }
  for (i64 i = 0; i < m; i++)
  {
    i64 p = que.top();
    que.pop();
    p /= 2;
    que.push(p);
  }
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    ans += que.top();
    que.pop();
  }
  cout << ans << endl;
  return 0;
}
