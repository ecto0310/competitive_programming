// URL: https://atcoder.jp/contests/abc151/submissions/9443271
// Date: Sun, 12 Jan 2020 21:02:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k, m;
  cin >> n >> k >> m;
  vector<i64> a(n);
  for (i64 i = 0; i < n - 1; i++)
    cin >> a[i];
  i64 ans = n * m;
  for (i64 i = 0; i < n - 1; i++)
    ans -= a[i];
  if (k < ans)
    cout << -1 << endl;
  else
    cout << max(0LL, ans) << endl;
  return 0;
}
