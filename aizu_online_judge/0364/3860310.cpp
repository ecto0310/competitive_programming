// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3860310
// Date: Wed, 11 Sep 2019 16:59:57 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 w, h, n;
  cin >> w >> h >> n;
  vector<i64> x(n), y(n);
  for (i64 i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  vector<i64> m(h);
  for (i64 i = 0; i < n; i++)
    m[y[i]] = max(m[y[i]], x[i]);
  i64 ans = 1e9, mob = 0;
  for (i64 i = h - 1; 0 <= i; i--)
  {
    ans = min(ans, i + mob);
    mob = max(mob, m[i]);
  }
  cout << ans << endl;
  return 0;
}
