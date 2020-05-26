// URL: https://atcoder.jp/contests/tenka1-2018-beginner/submissions/9119346
// Date: Tue, 24 Dec 2019 22:54:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  vector<i64> d(n - 1);
  for (i64 i = 0; i < n - 1; ++i)
    d[i] = a[i + 1] - a[i];
  if (n % 2 == 0)
  {
    i64 ans = 0;
    for (i64 i = 0; i < n - 1; i++)
      ans += d[i] * 2 * min(i + 1, n - i - 1);
    cout << ans - d[n / 2 - 1];
  }
  else
  {
    i64 ans = 0;
    for (i64 i = 0; i < n - 1; ++i)
      ans += d[i] * 2 * min(i + 1, n - i - 1);
    cout << ans - min(d[n / 2 - 1], d[n / 2]) << endl;
  }
  return 0;
}
