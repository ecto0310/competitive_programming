// URL: https://atcoder.jp/contests/abc137/submissions/7365989
// Date: Fri, 06 Sep 2019 22:42:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<pair<i64, i64>> b(n);
  for (i64 i = 0; i < n; i++)
    cin >> b[i].first >> b[i].second;
  sort(b.begin(), b.end());
  i64 ans = 0, t = 0;
  priority_queue<i64> que;
  for (i64 i = 0; i <= m; i++)
  {
    while (t < n && b[t].first <= i)
    {
      que.push(b[t].second);
      t++;
    }
    if (que.size() != 0)
    {
      ans += que.top();
      que.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
