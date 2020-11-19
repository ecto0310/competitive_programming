// URL: https://atcoder.jp/contests/abc125/submissions/5140350
// Date: Sat, 27 Apr 2019 21:03:12 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> v(n), c(n);
  for (i64 i = 0; i < n; i++)
    cin >> v[i];
  for (i64 i = 0; i < n; i++)
    cin >> c[i];
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    if (c[i] < v[i])
      ans += v[i] - c[i];
  cout << ans << endl;
  return 0;
}
