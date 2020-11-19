// URL: https://atcoder.jp/contests/abc140/submissions/7383313
// Date: Sat, 07 Sep 2019 21:04:14 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n), b(n), c(n - 1);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  for (i64 i = 0; i < n; i++)
    cin >> b[i];
  for (i64 i = 0; i < n - 1; i++)
    cin >> c[i];
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    ans += b[a[i] - 1];
    if (i + 1 != n && a[i] + 1 == a[i + 1])
      ans += c[a[i] - 1];
  }
  cout << ans << endl;
  return 0;
}
