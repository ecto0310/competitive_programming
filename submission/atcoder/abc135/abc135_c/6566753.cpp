// URL: https://atcoder.jp/contests/abc135/submissions/6566753
// Date: Sat, 27 Jul 2019 21:11:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n + 1), b(n);
  for (i64 i = 0; i < n + 1; i++)
    cin >> a[i];
  for (i64 i = 0; i < n; i++)
    cin >> b[i];
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    ans += min(a[i], b[i]);
    b[i] -= min(a[i], b[i]);
    ans += min(a[i + 1], b[i]);
    a[i + 1] -= min(a[i + 1], b[i]);
  }
  cout << ans << endl;
  return 0;
}
