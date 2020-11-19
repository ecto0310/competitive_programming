// URL: https://atcoder.jp/contests/s8pc-6/submissions/4973461
// Date: Sun, 14 Apr 2019 20:18:52 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n), b(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    ans += abs(b[i] - a[i]);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (i64 i = 0; i < n; i++)
    ans += abs(a[i] - a[(n - 1) / 2]) + abs(b[i] - b[(n - 1) / 2]);
  cout << ans << endl;
  return 0;
}
