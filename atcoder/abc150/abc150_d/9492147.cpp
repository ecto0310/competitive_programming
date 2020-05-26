// URL: https://atcoder.jp/contests/abc150/submissions/9492147
// Date: Mon, 13 Jan 2020 15:21:51 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i] /= 2;
  }
  bool ok = true;
  i64 s = 1;
  for (i64 i = 0; i < n; i++)
    s = s / __gcd(s, a[i]) * a[i];
  i64 t = 1, ans = 0;
  while (s * t <= m)
  {
    ans++;
    t += 2;
  }
  for (i64 i = 0; i < n; i++)
    if ((s / a[i]) % 2 == 0)
      ok = false;
  if (ok)
    cout << ans << endl;
  else
    cout << 0 << endl;
  return 0;
}
