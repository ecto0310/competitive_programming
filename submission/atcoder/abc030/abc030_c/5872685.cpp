// URL: https://atcoder.jp/contests/abc030/submissions/5872685
// Date: Tue, 11 Jun 2019 01:08:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<i64> a(n), b(m);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  for (i64 i = 0; i < m; i++)
    cin >> b[i];
  i64 ans = 0, now = 0;
  while (true)
  {
    i64 i = lower_bound(a.begin(), a.end(), now) - a.begin();
    if (i == n)
      break;
    now = a[i] + x;
    i = lower_bound(b.begin(), b.end(), now) - b.begin();
    if (i == m)
      break;
    now = b[i] + y;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
