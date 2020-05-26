// URL: https://atcoder.jp/contests/abc148/submissions/9064157
// Date: Sun, 22 Dec 2019 21:07:48 +0900
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
  i64 ans = 0, now = 1;
  for (i64 i = 0; i < n; i++)
  {
    if (a[i] == now)
      now++;
    else
      ans++;
  }
  if (ans == n)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
