// URL: https://atcoder.jp/contests/cf17-final/submissions/6238950
// Date: Fri, 05 Jul 2019 01:30:31 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> d(n);
  for (i64 i = 0; i < n; i++)
    cin >> d[i];
  sort(d.begin(), d.end());
  vector<i64> t(n);
  for (i64 i = 0; i < n; i++)
    t[i] = abs(24 * (i % 2) - d[i]);
  i64 ans = d[0];
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < i; j++)
      ans = min({ans, abs(t[i] - t[j]), 24 - abs(t[i] - t[j])});
  cout << ans << endl;
  return 0;
}
